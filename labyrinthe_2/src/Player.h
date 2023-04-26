#ifndef PLAYER_H
#define PLAYER_H

#include "Maze.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <AL/al.h>

class Player
{
public:
    Player(int x, int y);
    ~Player();

    int x, y;

    bool isOn(int x, int y);
    void rotateLeft();
    void rotateRight();
    void moveForward();
    void checksound();

    void checkWalls(const Maze &maze);
    void draw(SDL_Renderer *renderer) const;

private:
    int prevX, prevY;
    char orientation;

    /** buffers pour la gestion du son */
    ALuint buffer, source;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // PLAYER_H
