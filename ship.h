#ifndef CONTROLS_SHIP_H
#define CONTROLS_SHIP_H

class Ship {
  public:
    struct Position {
        int x;
        int y;
    };

    Ship(int initialX, int initialY, int largestX, int largestY)
        : pos {Position {initialX, initialY}}, upperX {largestX - SIZE},
          upperY {largestY - SIZE} {};

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    [[nodiscard]] int getSize() const;

  private:
    const int INCREMENT = 5;
    const int SIZE      = 37;

    Position pos;
    int upperX;
    int upperY;
};

#endif
