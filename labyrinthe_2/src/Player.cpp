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
        // printf("Wall detected => retour(%d,%d)\n", prevX, prevY);
        x = prevX;
        y = prevY;
    }
}

void filledTriangle(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int x3, int y3)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1);

    int minX = std::min(std::min(x1, x2), x3);
    int maxX = std::max(std::max(x1, x2), x3);
    int minY = std::min(std::min(y1, y2), y3);
    int maxY = std::max(std::max(y1, y2), y3);

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            int a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
            int b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
            int c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

            if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
            {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void Player::draw(SDL_Renderer *renderer) const
{
    int frontX = x * 40 + 20;
    int frontY = y * 40 + 5;
    int backLeftX = x * 40 + 5;
    int backLeftY = y * 40 + 35;
    int backRightX = x * 40 + 35;
    int backRightY = y * 40 + 35;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    filledTriangle(renderer, frontX, frontY, backLeftX, backLeftY, backRightX, backRightY);
}
