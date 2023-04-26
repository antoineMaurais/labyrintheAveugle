#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

class Maze
{
public:
    Maze(const std::vector<std::vector<int>> &grid);
    ~Maze();

    void playSound(int x, int y, char orientation) const;
    bool isWall(int x, int y, int preX, int preY) const;
    void draw(SDL_Renderer *renderer, int screenWidth, int screenHeight, int arrive_x, int arrive_y) const;

private:
    ALuint buffer, buffer2, source[5], source2;
    std::vector<std::vector<int>> grid;
};

#endif
