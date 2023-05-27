#!/bin/bash

validate_exit() {
    if [ $? != 0 ]; then
        exit 1
    fi
}

ROOT_DIR=$(pwd)

TARGET=main
EXECUTABLE=main

CONFIGURE=false
COMPILE_CMD="make"
WIN=false

while getopts "t:c" option; do
    case $option in
        c)
            CONFIGURE=true
            ;;
        t)
            TARGET=$OPTARG
            EXECUTABLE=$OPTARG
            ;;
    esac
done


if [ "$OSTYPE" = "msys" ]; then
    WIN=true
    
    COMPILE_CMD="MSBuild.exe -target:Build /property:Configuration=Debug"
    ROOT_DIR="c:/Users/darko/Development/<DIR_NAME>"

    TARGET=${TARGET}.vcxproj
    EXECUTABLE=${EXECUTABLE}.exe
fi

# configure
if [ $CONFIGURE == true ]; then
    cd $ROOT_DIR/build/
    cmake ..
    validate_exit
    
    if  [ $WIN == true ]; then
        cd $ROOT_DIR/ninja/
        cmake -G"Ninja" ..
        mv compile_commands.json ..
        validate_exit
    fi

    exit 0
fi


# build
cd $ROOT_DIR/build/
echo "COMPILE_CMD: $COMPILE_CMD ${TARGET}"
$COMPILE_CMD ${TARGET}
validate_exit

# run
cd $ROOT_DIR/bin/
echo "EXECUTABLE: $EXECUTABLE"
./${EXECUTABLE}
