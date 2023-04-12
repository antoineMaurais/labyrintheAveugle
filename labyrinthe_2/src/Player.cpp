#include "Player.h"

Player::Player(int x, int y) : x(x), y(y), prevX(x), prevY(y), orientation('n') {}

Player::~Player() {}

void Player::moveUp()
{
    prevX = x;
    prevY = y;
    y -= 1;
}

void Player::moveDown()
{
    prevX = x;
    prevY = y;
    y += 1;
}

void Player::moveLeft()
{
    prevY = y;
    prevX = x;
    x -= 1;
}

void Player::moveRight()
{
    prevY = y;
    prevX = x;
    x += 1;
}

void Player::checkWalls(const Maze &maze)
{
    if (maze.isWall(x, y, prevX, prevY))
    {
        //printf("Wall detected => retour(%d,%d)\n", prevX, prevY);
        x = prevX;
        y = prevY;
    }
}

void Player::draw(SDL_Renderer *renderer) const
{
    SDL_Rect playerRect;
    /*int frontX = x * 40 + 20;
    int frontY = y * 40 + 5;
    int backLeftX = x * 40 + 5;
    int backLeftY = y * 40 + 35; 
    int backRightX = x * 40 + 35;
    int backRightY = y * 40 + 35;

    const std::vector<SDL_Vertex> verts =
    {
        { SDL_FPoint{ frontX, frontY }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ backLeftX, backLeftY }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, },
        { SDL_FPoint{ backRightX, backRightY }, SDL_Color{ 255, 0, 0, 255 }, SDL_FPoint{ 0 }, },
    };*/

    playerRect.x = x * 40 + 5;
    playerRect.y = y * 40 + 5;
    playerRect.w = 30;
    playerRect.h = 30;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &playerRect);
    //SDL_RenderGeometry( renderer, nullptr, verts.data(), verts.size(), nullptr, 0 );
}
