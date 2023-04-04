#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char const *argv[])
{
    if(argc == 3) {

        

        FILE* fichier = fopen("lab.txt", "w");
        int height = atoi(argv[1]);
        int width = atoi(argv[2]);

        printf("Génération d'un labyrinthe de %d par %d ...\n", height, width);

        /*
        int grid[height][width];

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                grid[i][j] = 0;
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
                    grid[y][cell] += 1; //north
                    grid[y-1][cell] += 2; //south
                    run_start = x+1;

                } else if (x+1 < width){    
                    // carve east
                    //printf("%d,%d : carve east\n", y, x);
                    grid[y][x] += 4; //east
                    grid[y][x+1] += 8; //west
                }
            }
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                fprintf(fichier, "%2d ", grid[i][j]);
            }
            fprintf(fichier, "\n");       
        }
        fclose(fichier);
        printf("Le contenu du labyrinthe a été ecrit dans le fichier lab.txt");*/
    } else {
        printf("Erreur : vous n'avez pas selectionné la taille du labyrinthe !");
    }
    
    
    return 0;
}
