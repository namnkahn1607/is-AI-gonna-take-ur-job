#include "button.h"
#include "texture.h"

Button::Button(SDL_Point buttonPos, SDL_Renderer* ren, int buttonWidth, int buttonHeight) : buttonRenderer(ren) {
    buttonCover = {
        buttonPos.x, buttonPos.y,
        buttonWidth, buttonHeight
    };

    idleTexture = ;
    hoverTexture = ; // create texture from text;
}

Button::~Button() {
    SDL_DestroyTexture(idleTexture);
    idleTexture = nullptr;

    SDL_DestroyTexture(hoverTexture);
    hoverTexture = nullptr;
}

Button::handleEvents(SDL_Event e) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Point mousePos = {mouseX, mouseY};

    isHover = SDL_PointInRect(&mousePos, &buttonCover);
}

Button::render() {
    if (isHover == true)
        SDL_RenderCopy(buttonRenderer, hoverTexture, nullptr, &buttonCover);
    else
        SDL_RenderCopy(buttonRenderer, idleTexture, nullptr, &buttonCover);
}