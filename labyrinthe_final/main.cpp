#include <iostream>
#include <SDL2/SDL.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <unistd.h>
#include "Maze.h"
#include "Player.h"
#include "MazeGenerator.h"

int main(int argc, char *argv[])
{
    // Génération et chargement du labyrinthe
    int width = 5;
    int height = 4;
    const int screenWidth = width*40;
    const int screenHeight = height*40;

    // Initialisation de SDL2 et SDL2_mixer
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Erreur lors de l'initialisation de SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre et du renderer
    SDL_Window *window = SDL_CreateWindow("Labyrinthe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Erreur lors de la création de la fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Erreur lors de la création du renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    alutInit(0, NULL);
    alGetError();

    // position de la caméra qui écoute
    alListener3f(AL_POSITION, 0, 0, 0);
    alListener3f(AL_VELOCITY, 0, 0, 0);

    // ouverture du flux audio à placer dans le buffer
    std::string soundpathname = "data/victory.wav";
    ALuint bufferVic = alutCreateBufferFromFile(soundpathname.c_str());
    if (bufferVic == AL_NONE) {
        std::cerr << "unable to open file " << soundpathname << std::endl;
        alGetError();
        throw std::runtime_error("file not found or not readable");
    }

    ALuint victoire;
    alGenSources(1, &victoire);
    alSourcei(victoire, AL_BUFFER, bufferVic); // son victoir
    alSource3f(victoire, AL_POSITION, 0, 0, 0); // son sur le joueur

    MazeGenerator generator(width, height);
    std::vector<std::vector<int>> grid = generator.generate();
    Maze maze(grid);

    // Création du joueur
    Player player(0, 0);

    srand(time(NULL));

    int arrive_x = rand() % width;
    int arrive_y = rand() % height;

    while(arrive_x == 0 && arrive_y == 0){
        arrive_x = rand() % width;
        arrive_y = rand() % height;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
    SDL_RenderClear(renderer);
    maze.draw(renderer, screenWidth, screenHeight, arrive_x, arrive_y);
    player.draw(renderer);
    SDL_RenderPresent(renderer);

    // Boucle principale du jeu
    bool running = true;
    while (!player.isOn(arrive_x, arrive_y))
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
                case SDLK_q:
                    player.rotateLeft();
                    player.checkWalls(maze);
                    break;
                case SDLK_d:
                    player.rotateRight();
                    player.checkWalls(maze);
                    break;
                case SDLK_z:
                    player.moveForward();
                    player.checkWalls(maze);
                    break;
                case SDLK_UP:
                    player.moveForward();
                    player.checkWalls(maze);
                    break;
                case SDLK_LEFT:
                    player.rotateLeft();
                    break;
                case SDLK_RIGHT:
                    player.rotateRight();
                    break;
                case SDLK_a:
                    player.playSoundAround(maze);
                    break;
                }

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fond noir
                SDL_RenderClear(renderer);
                maze.draw(renderer, screenWidth, screenHeight, arrive_x, arrive_y);
                player.draw(renderer);
                SDL_RenderPresent(renderer);
            }
        }

        // Mise à jour du joueur et du labyrinthe
        // (ajoutez ici les mises à jour nécessaires pour les autres objets du jeu)

        // Rendu du labyrinthe et du joueur
        
    }

    alSourcePlay(victoire);
    sleep(8);

    // Nettoyage et fermeture de SDL2 et SDL2_mixer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    alutExit();

    printf("C'est gagné !\n");

    return 0;
}
