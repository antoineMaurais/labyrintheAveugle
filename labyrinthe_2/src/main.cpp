#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Maze.h"
#include "Player.h"
#include "MazeGenerator.h"

int main(int argc, char *argv[])
{
    // Initialisation de SDL2 et SDL2_mixer
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cerr << "Erreur lors de l'initialisation de SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "Erreur lors de l'initialisation de SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Création de la fenêtre et du renderer
    SDL_Window *window = SDL_CreateWindow("Labyrinthe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Erreur lors de la création de la fenêtre: " << SDL_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Erreur lors de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    // Génération et chargement du labyrinthe
    int width = 20;
    int height = 15;
    const int screenWidth = 800;
    const int screenHeight = 600;

    MazeGenerator generator(width, height);
    std::vector<std::vector<int>> grid = generator.generate();
    Maze maze(grid);

    // Création du joueur
    Player player(1, 1);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
    SDL_RenderClear(renderer);
    maze.draw(renderer, screenWidth, screenHeight);
    player.draw(renderer);
    SDL_RenderPresent(renderer);

    // Boucle principale du jeu
    bool running = true;
    while (running)
    {
        // Gestion des événements et des entrées utilisateur
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    player.moveUp();
                    break;
                case SDLK_DOWN:
                    player.moveDown();
                    break;
                case SDLK_LEFT:
                    player.moveLeft();
                    break;
                case SDLK_RIGHT:
                    player.moveRight();
                    break;
                }
                player.checkWalls(maze);

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
                SDL_RenderClear(renderer);
                maze.draw(renderer, screenWidth, screenHeight);
                player.draw(renderer);
                SDL_RenderPresent(renderer);
            }
        }

        // Mise à jour du joueur et du labyrinthe
        // (ajoutez ici les mises à jour nécessaires pour les autres objets du jeu)

        // Rendu du labyrinthe et du joueur
        
    }

    // Nettoyage et fermeture de SDL2 et SDL2_mixer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
