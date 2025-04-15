#pragma once

#include "cell.h"

using namespace std;

class Cell;

class Ship;

class Board {
private:
    vector<vector<Cell>> grid;
    vector<vector<State>> stateMatrix;
    SDL_Rect boardCover;
    bool isHidden, playerOrBot;
    SDL_Renderer* boardRenderer;

public:
    Board(SDL_Point basePos, SDL_Renderer* ren, bool turn);

    ~Board();

    void renderBoard();

    void updateBoard();

    bool checkMouseInBoard(int mouseX, int mouseY);
};