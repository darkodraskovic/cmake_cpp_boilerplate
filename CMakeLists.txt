cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(main Source/Main.cpp)

target_include_directories(main PRIVATE
  Source/
  lib/
  lib/SFML/include
  lib/libtcod/include
  )

target_link_directories(main PRIVATE
  lib/SFML/lib
  lib/libtcod
  )
target_link_libraries(main
  sfml-main.lib sfml-system.lib sfml-window.lib sfml-graphics.lib
  libtcod.lib
  )
