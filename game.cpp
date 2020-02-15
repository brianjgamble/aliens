#include "game.h"

bool Game::initialize() {
    auto sdlResult = SDL_Init(SDL_INIT_VIDEO);

    if (sdlResult != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Test Controls", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    SDL_Surface* image = SDL_LoadBMP("alien-blue.bmp");

    if (!image) {
        SDL_Log("Failed to load alien bitmap: %s", SDL_GetError());
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_FreeSurface(image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    return true;
}

void Game::runLoop() {
    while (isRunning) {
        processInput();
        generateOutput();
    }
}

void Game::shutDown() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::processInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_a:
                        ship.moveLeft();
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        ship.moveRight();
                        break;
                    case SDLK_UP:
                    case SDLK_w:
                        ship.moveUp();
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        ship.moveDown();
                        break;
                }
                break;

            case SDL_QUIT:
                isRunning = false;
                break;
        }
    }

    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(nullptr);

    // If escape is pressed, also end loop
    if (state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
}

void Game::generateOutput() {
    SDL_Rect rect = {ship.getX(), ship.getY(), ship.getSize(), ship.getSize()};

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_RenderPresent(renderer);
}
