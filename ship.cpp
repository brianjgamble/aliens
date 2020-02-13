#include "ship.h"

void Ship::moveUp() {
    pos.y -= INCREMENT;
}

void Ship::moveDown() {
    pos.y += INCREMENT;
}

void Ship::moveLeft() {
    pos.x -= INCREMENT;
}

void Ship::moveRight() {
    pos.x += INCREMENT;
}

int Ship::getX() const {
    return pos.x;
}

int Ship::getY() const {
    return pos.y;
}
