#pragma once

#include "constant.h"
#include "cell.h"
#include "board.h"

using namespace std;

class Board;

class Ship {
private:
    const SDL_Point shipTrayPos;
    SDL_Texture* shipTexture;
    SDL_Rect shipCover;
    SDL_Renderer* shipRenderer;
    int shipWidth;
    bool onBoard, horizontal, isDragging;
    int startRow, startCol;
    int offsetX, offsetY;
    Board shipBoard;

public:
    Ship(const char* imgPath, SDL_Renderer* ren, SDL_Point trayPos, int len);

    ~Ship();

    bool checkMouseWithin(int mouseX, int mouseY);

    void shipHandleEvents(SDL_Event e);

    void updateShip();

    void renderShip();
};