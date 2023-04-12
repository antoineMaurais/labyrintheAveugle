#include "Maze.h"
#include <iostream>

Maze::Maze(const std::vector<std::vector<int>> &grid)
    : grid(grid)
{
}

Maze::~Maze()
{
}

bool Maze::isWall(int x, int y, int preX, int preY) const
{
    
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
    {
        return true;
    }

    int cellValue = grid[y][x];
    //printf("(%d, %d) = %d (north:%d,south:%d,west:%d,east:%d)\n", x, y, cellValue, cellValue & 1, cellValue & 4, cellValue & 8, cellValue & 2);

    //printf("actu (%d,%d) = %d\n", x, y, cellValue);
    /*printf("prev (%d,%d)\n", preX, preY);*/
    int lr = x - preX; // Left or right
    int tb = y - preY; // Top or bottom

    //printf("lr: %d, tb: %d\n", lr, tb);

    if(lr == 0){
        if(tb == 1){
            // Going down
            //printf("Going down : %d\n", cellValue & 1);
            if((cellValue & 1) > 0){
                //printf("wall down\n");
                return true;
            }
        } else if(tb == -1) {
            // Going up
            //printf("Going up: %d\n", cellValue & 4);
            if((cellValue & 4) > 0){
                //printf("wall up\n");
                return true;
            }
        }
    } else {
        if(lr == 1){
            // Going right
            //printf("Going right : %d\n", cellValue & 8);
            if((cellValue & 8) > 0){
                //printf("wall right\n");
                return true;
            }
        } else if(lr == -1){
            // Going left
            //printf("Going left : %d\n", cellValue & 2);
            if((cellValue & 2) > 0){
                //printf("wall left\n");
                return true;
            }
        }   
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
            //printf("%02d ", cellValue);

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
