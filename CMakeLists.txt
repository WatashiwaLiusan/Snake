cmake_minimum_required(VERSION 3.29)
project(Snake)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_EXAMPLES OFF)

add_executable(main src/main.cpp)

include_directories(include)

find_library(RAYLIB raylib lib)

target_link_libraries(main LINK_PUBLIC ${RAYLIB} winmm)