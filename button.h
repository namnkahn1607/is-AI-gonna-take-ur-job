#pragma once

#include "constant.h"

class Button {
private:
    SDL_Texture* idleTexture;
    SDL_Texture* hoverTexture;
    SDL_Rect buttonCover;
    SDL_Renderer* buttonRenderer;
    bool isHover;

public:
    Button(SDL_Point buttonPos, SDL_Renderer* ren, int buttonWidth, int buttonHeight);

    ~Button();

    void handleEvents(SDL_Event e);

    void render();
};