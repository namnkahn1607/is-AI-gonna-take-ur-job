#pragma once

#include "game.h"

using namespace std;

class textureManager {
public:
    static SDL_Texture* loadFromFile(const char* imgPath, SDL_Renderer* ren);
};
