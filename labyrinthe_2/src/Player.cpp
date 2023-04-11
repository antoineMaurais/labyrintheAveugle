#include "Player.h"

Player::Player(int x, int y) : x(x), y(y), prevX(x), prevY(y) {}

Player::~Player() {}

void Player::moveUp()
{
    prevY = y;
    y -= 1;
}

void Player::moveDown()
{
    prevY = y;
    y += 1;
}

void Player::moveLeft()
{
    prevX = x;
    x -= 1;
}

void Player::moveRight()
{
    prevX = x;
    x += 1;
}

void Player::checkWalls(const Maze &maze)
{
    if (maze.isWall(x, y))
    {
        x = prevX;
        y = prevY;
    }
}

void Player::draw(SDL_Renderer *renderer) const
{
    SDL_Rect playerRect;
    playerRect.x = x * 32; // Assuming a tile size of 32
    playerRect.y = y * 32; // Assuming a tile size of 32
    playerRect.w = 32;     // Assuming a tile size of 32
    playerRect.h = 32;     // Assuming a tile size of 32

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &playerRect);
}
