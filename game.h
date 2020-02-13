#ifndef CONTROLS_GAME_H
#define CONTROLS_GAME_H

#include "ship.h"
#include <SDL.h>

class Game {
  public:
    Game() : ship {Ship {288, 208}}, isRunning {true} {};

    // Initialize the game
    bool initialize();

    // Runs the game loop until the game is over
    void runLoop();

    // Shutdown the game
    void shutDown();

  private:
    // Helper functions for the game loop
    void processInput();
    void generateOutput();

    // Window created by SDL
    SDL_Window* window {};
    SDL_Renderer* renderer {};
    SDL_Texture* texture {};

    // Game should continue to run
    bool isRunning;

    Ship ship;
};

#endif
