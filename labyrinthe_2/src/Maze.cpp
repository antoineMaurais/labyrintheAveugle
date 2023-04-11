#include "Maze.h"
#include <iostream>

Maze::Maze(const std::vector<std::vector<int>> &grid)
    : grid(grid)
{
}

Maze::~Maze()
{
}

bool Maze::isWall(float x, float y) const
{
    int cellX = static_cast<int>(x);
    int cellY = static_cast<int>(y);

    if (cellX < 0 || cellX >= grid[0].size() || cellY < 0 || cellY >= grid.size())
    {
        return true;
    }

    int cellValue = grid[cellY][cellX];

    if (cellValue & 1 && y - cellY < 0.5) // North wall
    {
        return true;
    }
    if (cellValue & 2 && x - cellX > 0.5) // East wall
    {
        return true;
    }
    if (cellValue & 4 && y - cellY > 0.5) // South wall
    {
        return true;
    }
    if (cellValue & 8 && x - cellX < 0.5) // West wall
    {
        return true;
    }

    return false;
}

void Maze::draw(SDL_Renderer *renderer, int screenWidth, int screenHeight) const
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    int cellWidth = screenWidth / grid[0].size();
    int cellHeight = screenHeight / grid.size();

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            int cellValue = grid[i][j];

            if (cellValue & 1)
            { // North wall
                SDL_RenderDrawLine(renderer, j * cellWidth, i * cellHeight, (j + 1) * cellWidth, i * cellHeight);
            }
            if (cellValue & 2)
            { // East wall
                SDL_RenderDrawLine(renderer, (j + 1) * cellWidth, i * cellHeight, (j + 1) * cellWidth, (i + 1) * cellHeight);
            }
            if (cellValue & 4)
            { // South wall
                SDL_RenderDrawLine(renderer, j * cellWidth, (i + 1) * cellHeight, (j + 1) * cellWidth, (i + 1) * cellHeight);
            }
            if (cellValue & 8)
            { // West wall
                SDL_RenderDrawLine(renderer, j * cellWidth, i * cellHeight, j * cellWidth, (i + 1) * cellHeight);
            }
        }
    }
}
