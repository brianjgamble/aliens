#include "game.h"

int main() {
    Game game;
    bool success = game.initialize();
    if (success) {
        game.runLoop();
    }
    game.shutDown();
    return 0;
}
