#pragma once

#include "constant.h"

class Cell {
private:
    SDL_Rect cellCover;
    State cellState;
    SDL_Color cellFillColor;
    SDL_Renderer* cellRenderer;

public:
    Cell(SDL_Point basePos, SDL_Renderer* ren);
    
    ~Cell();

    void renderCell();

    void setCellFillColor(SDL_Color color);

    State getCellState() const;

    SDL_Point getCellMidpoint() const;
};