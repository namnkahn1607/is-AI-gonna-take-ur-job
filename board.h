#pragma once

#include "cell.h"
#include "ship.h"

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
    vector<Ship*> shipList;

    vector<pair<int, int>> occupiedCells;

    Board(SDL_Point basePos, SDL_Renderer* ren, bool turn);

    ~Board();

    bool checkMouseInBoard(int mouseX, int mouseY);

    bool checkValidPlacement(Ship* placingShip);
    
    void renderBoard();

    void updateBoard();

    int getBasePosX() const;

    int getBasePosY() const;

    int getBoardWidth() const;
    
    int getBoardHeight() const;
};