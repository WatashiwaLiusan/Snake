cmake_minimum_required(VERSION 3.29)
project(Snake)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_EXAMPLES OFF)

add_subdirectory(lib/raylib)

add_executable(Snake/main.cpp)

target_link_libraries(Snake raylib)