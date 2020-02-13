cmake_minimum_required(VERSION 3.15)
project(controls)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(controls main.cpp game.cpp ship.cpp)

target_link_libraries(controls ${SDL2_LIBRARIES})