cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (WIN32)
  message("Configure for WIN32")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin")

  set(warning_compiler_options /W3 /wd"4267" /wd"4305" /wd"4244" /wd"4996")
  # /Od disables optimization to speed compilation.
  add_compile_options(${warning_compiler_options} /MD /Od /JMC)
elseif(UNIX)
  message("Configure for LINUX")  
  SET(CMAKE_C_FLAGS "-g -Wall -std=gnu11 -O0")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
endif()


# LEN lib

file(GLOB LEN_C "Source/Len/Math/*.cpp")
add_library(len STATIC ${LEN_C})

add_executable(main Source/Main.cpp)


# MAIN

target_include_directories(main PRIVATE
  Source/
  Source/Len/Math
  )

target_link_libraries(main
  len
  )

# TEST

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
  Source/Tests/gtest_main.cpp
  )
target_include_directories(tests PUBLIC
  Source/Tests
  Source/Len/Math
  )
target_link_libraries(tests PUBLIC gtest gtest_main len)

include(GoogleTest)
gtest_discover_tests(tests)
