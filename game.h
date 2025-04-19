#pragma once

#include "constant.h"

class Game {
private:
    bool isRunning;
    SDL_Window* win;
    SDL_Renderer* ren;

public:
    Game();
    
    ~Game();

    void init(const char* consoleTitle, int xPos, int yPos, 
              int width, int height, bool fullscreen);
    
    void handleEvents();

    void update();

    void render();

    void close();

    bool running();
};
