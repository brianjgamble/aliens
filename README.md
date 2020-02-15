# Aliens

This is a basic SDL2 project so I could learn how to move a bitmap around 
the screen.

The original art for the alien ship is found on OpenGameArt.Org: [Simple Alien Ship](https://opengameart.org/content/alien-ship)

## Building

1. Download the latest SDL2 library and build it locally.

2. Clone this project and run the following commands in the root of the project:

```shell script
mkdir -p build
cd build
cmake -D SDL_CMAKE_PATH==~/local/lib/cmake/SDL2 ..
cmake --build .
cp ../alien-blue.bmp .
```

The `SDL_CMAKE_PATH` is the path to the directory that contains the file 
`sdl2-config.cmake`.  It is created when you build the SDL2 library.

## Running

In the build directory, run the program `aliens`.  You can use WASD and the 
arrow keys to move the ship around the screen.  Pressing `Esc` or closing the 
window will exit the program.