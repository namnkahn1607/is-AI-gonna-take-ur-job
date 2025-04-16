#pragma once

#include "constant.h"
#include "cell.h"

class Cell;

class Ship;

class Board {
private:
    std::vector<std::vector<Cell>> grid;
    std::vector<std::vector<State>> stateMatrix;
    SDL_Rect boardCover;
    bool isHidden, playerOrBot;
    SDL_Renderer* boardRenderer;

public:
    std::vector<Ship*> shipList;

    std::vector<std::pair<int, int>> occupiedCells;

    Board(SDL_Point basePos, SDL_Renderer* ren, bool turn);

    ~Board();

    bool checkMouseInBoard(int mouseX, int mouseY);

    bool checkValidPlacement(Ship* placingShip);

    void snapShip(Ship* snappingShip);

    void removeShip(Ship* removingShip);
    
    void renderBoard();

    int getBasePosX() const;

    int getBasePosY() const;

    int getBoardWidth() const;
    
    int getBoardHeight() const;
};