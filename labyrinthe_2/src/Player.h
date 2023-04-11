#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"
#include <SDL.h>

class Player
{
public:
    Player(int x, int y);
    ~Player();

    int x, y;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void checkWalls(const Maze &maze);
    void draw(SDL_Renderer *renderer) const;

private:
    int prevX, prevY;
};

#endif // PLAYER_H
