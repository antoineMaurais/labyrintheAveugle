#include "Maze.h"
#include <iostream>

Maze::Maze(const std::vector<std::vector<int>> &grid)
    : grid(grid)
{
    // ouverture du flux audio à placer dans le buffer
    std::string soundpathname = "data/white_noise.wav";
    std::string soundpathname2 = "data/running_short.wav";
    buffer = alutCreateBufferFromFile(soundpathname.c_str());
    buffer2 = alutCreateBufferFromFile(soundpathname2.c_str());
    if (buffer == AL_NONE) {
        std::cerr << "unable to open file " << soundpathname << std::endl;
        alGetError();
        throw std::runtime_error("file not found or not readable");
    }
    if (buffer2 == AL_NONE) {
        std::cerr << "unable to open file " << soundpathname2 << std::endl;
        alGetError();
        throw std::runtime_error("file not found or not readable");
    }

    // lien buffer -> source
    alGenSources(5, source);
    alSourcei(source[0], AL_BUFFER, buffer);
    alSourcei(source[1], AL_BUFFER, buffer);
    alSourcei(source[2], AL_BUFFER, buffer);
    alSourcei(source[3], AL_BUFFER, buffer);

    alSource3f(source[0], AL_POSITION, 0, 0, -1); // son devant
    alSource3f(source[1], AL_POSITION, -1, 0, 0); //gauche
    alSource3f(source[2], AL_POSITION, 1, 0, 0); //droite
    alSource3f(source[3], AL_POSITION, 0, 0, 1); //derriere

    alGenSources(1, &source2);
    alSourcei(source2, AL_BUFFER, buffer2);
    alSource3f(source2, AL_POSITION, 0, 0, 0); // son sur le joueur

    //alSourcePlay(source[1]);
    //alSourcePlay(source[2]);
}

Maze::~Maze()
{
}

void Maze::playSound(int x, int y, char orientation) const
{
    int up = 0; //son devant
    int left = 1; //son gauche
    int right = 2; //son droite
    int down = 3; //son derriere
    switch(orientation) {
        case 'w':
            left = 0; //son devant
            down = 1; //son gauche
            up = 2; //son droite
            right = 3; //son derriere
            break;
        case 's':
            down = 0; //son devant
            right = 1; //son gauche
            left = 2; //son droite
            up = 3; //son derriere
            break;
        case 'e':
            right = 0; //son devant
            up = 1; //son gauche
            down = 2; //son droite
            left = 3; //son derriere
            break;
    }

    int cellValue = grid[y][x];   
    if (cellValue & 1)
    { // North wall
        alSourcePlay(source[up]);
        switch (up)
        {
        case 0:
            printf("sound north : devant\n");
            break;
        case 1:
            printf("sound north : gauche\n");
            break;
        case 2:
            printf("sound north : droite\n");
            break;
        case 3:
            printf("sound north : derriere\n");
            break;
        default:
            printf("sound north : error\n");
            break;
        }
    }
    if (cellValue & 2)
    { // East wall
        alSourcePlay(source[right]);
        switch (right)
        {
        case 0:
            printf("sound east : devant\n");
            break;
        case 1:
            printf("sound east : gauche\n");
            break;
        case 2:
            printf("sound east : droite\n");
            break;
        case 3:
            printf("sound east : derriere\n");
            break;
        default:
            printf("sound east : error\n");
            break;
        }
    }
    if (cellValue & 4)
    { // South wall
        alSourcePlay(source[down]);
        switch (down)
        {
        case 0:
            printf("sound south : devant\n");
            break;
        case 1:
            printf("sound south : gauche\n");
            break;
        case 2:
            printf("sound south : droite\n");
            break;
        case 3:
            printf("sound south : derriere\n");
            break;
        default:
            printf("sound south : error\n");
            break;
        }
    }
    if (cellValue & 8)
    { // West wall
        alSourcePlay(source[left]);
        switch (left)
        {
        case 0:
            printf("sound west : devant\n");
            break;
        case 1:
            printf("sound west : gauche\n");
            break;
        case 2:
            printf("sound west : droite\n");
            break;
        case 3:
            printf("sound west : derriere\n");
            break;
        default:
            printf("sound west : error\n");
            break;
        }
    }
    printf("----------------------------\n");
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

    alSourcePlay(source2);
    printf("avance\n");
    return false;
}

void Maze::draw(SDL_Renderer *renderer, int screenWidth, int screenHeight, int arrive_x, int arrive_y) const
{
    int cellWidth = screenWidth / grid[0].size();
    int cellHeight = screenHeight / grid.size();

    SDL_Rect rect = { arrive_x*cellWidth, arrive_y*cellHeight, cellWidth, cellHeight };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Spécification de la couleur rouge pour le remplissage
    SDL_RenderFillRect(renderer, &rect); // Remplissage du rectangle

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

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
