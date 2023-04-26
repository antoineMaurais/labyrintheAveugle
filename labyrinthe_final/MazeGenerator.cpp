#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(int width, int height) : width(width), height(height) {}

std::vector<std::vector<int>> MazeGenerator::generate()
{
    std::vector<std::vector<int>> grid(height, std::vector<int>(width, 15));
    srand (time(NULL));

    for (int y = 0; y < height; y++)
    {
        int run_start = 0;
        for (int x = 0; x < width; x++)
        {
            if (y > 0 && (x + 1 == width || rand() % 2 == 0))
            {
                int cell = run_start + rand() % (x - run_start + 1);
                grid[y][cell] -= 1;
                grid[y - 1][cell] -= 4;
                run_start = x + 1;
            }
            else if (x + 1 < width)
            {
                grid[y][x] -= 2;
                grid[y][x + 1] -= 8;
            }
        }
    }

    return grid;
}
