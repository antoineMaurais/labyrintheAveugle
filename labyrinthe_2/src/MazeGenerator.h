#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <vector>
#include <cstdlib>

class MazeGenerator
{
public:
    MazeGenerator(int width, int height);
    std::vector<std::vector<int>> generate();

private:
    int width, height;
};

#endif // MAZE_GENERATOR_H
