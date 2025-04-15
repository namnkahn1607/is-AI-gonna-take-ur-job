#pragma once

#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class textureManager {
public:
    static SDL_Texture* loadFromFile(const char* imgPath, SDL_Renderer* ren);
};
