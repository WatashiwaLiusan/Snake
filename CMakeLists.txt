cmake_minimum_required(VERSION 3.29)
project(Snake)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_EXAMPLES OFF)

add_executable(main src/main.cpp
        src/object/SnakeBody.h
        src/object/Snake.h
        src/object/SnakeBody.cpp
        src/object/Snake.cpp
        src/controller/GameController.h
        src/controller/GameController.cpp
        src/object/Apple.cpp
        src/layer/Layer.h
        src/layer/Layer.cpp)

include_directories(include)

find_library(RAYLIB raylib lib)

target_link_libraries(main LINK_PUBLIC ${RAYLIB} winmm)