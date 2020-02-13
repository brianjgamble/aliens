#ifndef CONTROLS_SHIP_H
#define CONTROLS_SHIP_H

class Ship {
  public:
    struct Position {
        int x;
        int y;
    };

    Ship(int initialX, int initialY) : pos {Position {initialX, initialY}} {};

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

  private:
    Position pos;
    const int INCREMENT = 5;
};

#endif
