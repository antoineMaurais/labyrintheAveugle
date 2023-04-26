#include "Player.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>
#include <iostream>

Player::Player(int x, int y) : x(x), y(y), prevX(x), prevY(y), orientation('e') {}

Player::~Player() {}

bool Player::isOn(int onX, int onY)
{
    return onX == x && onY == y;
}

void Player::checksound()
{
    std::string soundpathname = "sounds/Duck-quacking-sound.wav";
    buffer = alutCreateBufferFromFile(soundpathname.c_str());
    if (buffer == AL_NONE)
    {
        std::cerr << "unable to open file " << soundpathname << std::endl;
        alGetError();
        // throw std::runtime_error("file not found or not readable");
    }
    // lien buffer -> source
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);

    // propriétés de la source à l'origine
    alSource3f(source, AL_POSITION, 0, 0, 0); // on positionne la source à (0,0,0) par défaut
    alSource3f(source, AL_VELOCITY, 0, 0, 0);
    alSourcei(source, AL_LOOPING, AL_TRUE);
    alSourcePlay(source);
}

void Player::rotateLeft()
{
    switch (orientation)
    {
    case 'n':
        orientation = 'w';
        break;
    case 'w':
        orientation = 's';
        break;
    case 's':
        orientation = 'e';
        break;
    case 'e':
        orientation = 'n';
        break;
    default:
        break;
    }
}

void Player::rotateRight()
{
    switch (orientation)
    {
    case 'n':
        orientation = 'e';
        break;
    case 'e':
        orientation = 's';
        break;
    case 's':
        orientation = 'w';
        break;
    case 'w':
        orientation = 'n';
        break;
    default:
        break;
    }
}

void Player::moveForward()
{
    switch (orientation)
    {
    case 'n':
        moveUp();
        break;
    case 'e':
        moveRight();
        break;
    case 's':
        moveDown();
        break;
    case 'w':
        moveLeft();
        break;
    default:
        break;
    }
}

void Player::moveUp()
{
    prevX = x;
    prevY = y;
    y -= 1;
}

void Player::moveDown()
{
    prevX = x;
    prevY = y;
    y += 1;
}

void Player::moveLeft()
{
    prevY = y;
    prevX = x;
    x -= 1;
}

void Player::moveRight()
{
    prevY = y;
    prevX = x;
    x += 1;
}

void Player::checkWalls(const Maze &maze)
{
    if (maze.isWall(x, y, prevX, prevY))
    {
        // printf("Wall detected => retour(%d,%d)\n", prevX, prevY);
        x = prevX;
        y = prevY;
    }
}

void filledTriangle(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int x3, int y3)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(renderer, x3, y3, x1, y1);

    int minX = std::min(std::min(x1, x2), x3);
    int maxX = std::max(std::max(x1, x2), x3);
    int minY = std::min(std::min(y1, y2), y3);
    int maxY = std::max(std::max(y1, y2), y3);

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            int a = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
            int b = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
            int c = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

            if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
            {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void Player::draw(SDL_Renderer *renderer) const
{
    int frontX = 0;
    int frontY = 0;
    int backLeftX = 0;
    int backLeftY = 0;
    int backRightX = 0;
    int backRightY = 0;

    switch (orientation)
    {
    case 'n':
        frontX = x * 40 + 20;
        frontY = y * 40 + 5;
        backLeftX = x * 40 + 5;
        backLeftY = y * 40 + 35;
        backRightX = x * 40 + 35;
        backRightY = y * 40 + 35;
        break;
    case 's':
        frontX = x * 40 + 20;
        frontY = y * 40 + 35;
        backLeftX = x * 40 + 5;
        backLeftY = y * 40 + 5;
        backRightX = x * 40 + 35;
        backRightY = y * 40 + 5;
        break;
    case 'w':
        frontX = x * 40 + 5;
        frontY = y * 40 + 20;
        backLeftX = x * 40 + 35;
        backLeftY = y * 40 + 35;
        backRightX = x * 40 + 35;
        backRightY = y * 40 + 5;
        break;
    case 'e':
        frontX = x * 40 + 35;
        frontY = y * 40 + 20;
        backLeftX = x * 40 + 5;
        backLeftY = y * 40 + 5;
        backRightX = x * 40 + 5;
        backRightY = y * 40 + 35;
        break;
    default:
        break;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    filledTriangle(renderer, frontX, frontY, backLeftX, backLeftY, backRightX, backRightY);
}
