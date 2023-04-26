#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char const *argv[])
{
    int height = 4;
    int width = 4;
    int grid[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grid[i][j] = 15;
        }
        
    }
    

    for(int y = 0; y < height; y++)
    {
        int run_start = 0;
        for (int x = 0; x < width; x++)
        {
            if (y > 0 && (x+1 == width || rand() % 2 == 0)) {
                // carve north
                //printf("%d,%d : carve north\n", y, x);
                int cell = run_start + rand() % (x-run_start+1);
                grid[y][cell] -= 1;
                grid[y-1][cell] -= 4;
                run_start = x+1;

            } else if (x+1 < width){    
                // carve east
                //printf("%d,%d : carve east\n", y, x);
                grid[y][x] -= 2;
                grid[y][x+1] -= 8;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%02d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
