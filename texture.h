#pragma once

#include "constant.h"

using namespace std;

class textureManager {
public:
    static SDL_Texture* loadFromFile(const char* imgPath, SDL_Renderer* ren);

    static SDL_Texture* loadText(TTF_Font* font, std::string text, SDL_Renderer* ren);
};
