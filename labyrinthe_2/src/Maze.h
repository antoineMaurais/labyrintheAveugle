#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <SDL2/SDL.h>

class Maze
{
public:
    Maze(const std::vector<std::vector<int>> &grid);
    ~Maze();

    bool isWall(int x, int y, int prevX, int prevY) const;
    void draw(SDL_Renderer *renderer, int screenWidth, int screenHeight) const;

private:
    std::vector<std::vector<int>> grid;
};

#endif
