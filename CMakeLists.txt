cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main Source/Main.cpp)
target_include_directories(main PUBLIC src)
