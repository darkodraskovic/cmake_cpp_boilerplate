# Minimal cmake boilerplate

Install [clangd](https://clangd.llvm.org/installation.html).

## Linux

### Configure and build
`mkdir` `build` folder. `cd` into `build` folder and run

```
cmake ..
make
```

### Run
To run program

```
cd bin
./main
```

### Generate compile_commands.json
`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json.
```

## Windows

We use bash environment with native CMake and Ninja. We build and compile with MSBuild and MSVC toolchain.

### Configure
```
cd build/ && cmake ..
```

### Build
```
cd build && MSBuild.exe -target:Build /property:Configuration=Release .\boilerplate.sln
```

### Run
```
cd bin && main.exe
```

### Generate compile_commands.json
```
cd ninja && cmake -G"Ninja" .. && mv compile_commands.json ..
```
