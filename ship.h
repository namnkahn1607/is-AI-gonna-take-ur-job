#pragma once

#include "constant.h"

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
    Board* ownerBoard;

public:
    Ship(const char* imgPath, SDL_Renderer* ren, SDL_Point trayPos, int len, Board* playBoard);

    ~Ship();

    bool checkMouseInShip(int mouseX, int mouseY);

    void calculateShipRowCol();

    void sendToTray();
    
    void updateShip(SDL_Event e);

    void renderShip();

    int getShipWidth() const;

    int getStartRow() const;

    int getStartCol() const;

    bool checkHorizontal() const;
};