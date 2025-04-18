#include "cell.h"

Cell::Cell(SDL_Point basePos, SDL_Renderer* ren) : cellState(CELL_ALIVE), cellRenderer(ren) {
    cellCover = {
        basePos.x, basePos.y,
        CELL_SIZE, CELL_SIZE
    };
}

Cell::~Cell() {}

void Cell::setCellFillColor(SDL_Color color) {
    cellFillColor = color;
}

void Cell::renderCell() {
    SDL_SetRenderDrawColor(
        cellRenderer, cellFillColor.r, cellFillColor.g, cellFillColor.b, cellFillColor.a
    );

    SDL_RenderFillRect(cellRenderer, &cellCover);
}

State Cell::getCellState() const {
    return cellState;
}

SDL_Point Cell::getCellMidpoint() const {
    return {cellCover.x + cellCover.w / 2, cellCover.y + cellCover.h / 2};
}