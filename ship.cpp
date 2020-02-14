#include "ship.h"

void Ship::moveUp() {
    pos.y -= INCREMENT;
    if (pos.y < 0)
        pos.y = 0;
}

void Ship::moveDown() {
    pos.y += INCREMENT;
    if (pos.y > upperY)
        pos.y = upperY;
}

void Ship::moveLeft() {
    pos.x -= INCREMENT;
    if (pos.x < 0)
        pos.x = 0;
}

void Ship::moveRight() {
    pos.x += INCREMENT;
    if (pos.x > upperX)
        pos.x = upperX;
}

int Ship::getX() const {
    return pos.x;
}

int Ship::getY() const {
    return pos.y;
}
int Ship::getSize() const {
    return SIZE;
}
