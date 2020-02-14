cmake_minimum_required(VERSION 3.15)
project(aliens)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${SDL_CMAKE_PATH})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(aliens main.cpp game.cpp ship.cpp)

target_link_libraries(aliens ${SDL2_LIBRARIES})