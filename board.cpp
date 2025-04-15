#include "board.h"

using namespace std;

Board::Board(SDL_Point basePos, SDL_Renderer* ren, bool turn) 
    : boardRenderer(ren), playerOrBot(turn), isHidden(false) {
        boardCover = {
            basePos.x, basePos.y,
            basePos.x + BOARD_COL * CELL_SIZE + (BOARD_COL - 1) * BORDER_SIZE,
            basePos.y + BOARD_ROW * CELL_SIZE + (BOARD_ROW - 1) * BORDER_SIZE
        };

        for (int i = 0; i < BOARD_ROW; ++i) {
            vector<Cell> row;

            for (int j = 0; j < BOARD_COL; ++j) {
                SDL_Point curCellPos = {
                    basePos.x + j * CELL_SIZE + j * BORDER_SIZE,
                    basePos.y + i * CELL_SIZE + i * BORDER_SIZE
                };

                row.push_back(Cell(curCellPos, ren));
            }
        }

        stateMatrix = vector<vector<State>>(
            BOARD_ROW, vector<State>(BOARD_COL, CELL_ALIVE)
        );
    }

Board::~Board() {}

Board::updateBoard() {

}

Board::renderBoard() {
    for (auto &row : grid) {
        for (auto &cell : row) {
            SDL_Color FillColor = backgroundColor;

            if (isHidden == true) {
                switch (cell.getCellState()) {
                    case CELL_DEAD:
                        FillColor = deadCellColor;
                        break;

                    case CELL_ALIVE:
                        FillColor = (playerOrBot) ? playerSignatureColor : botSignatureColor;
                        break;
                }
            } else {
                if (playerOrBot and cell.getCellState == CELL_OCCUPIED)
                    FillColor = playerDomainColor;
            }
            
            cell.setCellFillColor(FillColor);
            cell.renderCell();
        }
    }

    SDL_Color borderColor = {};

    if (isHidden)
        borderColor = backgroundColor;
    else
        borderColor = (playerOrBot) ? playerSignatureColor : botSignatureColor;

    SDL_SetRenderDrawColor(boardRenderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);

    for (int i = 0; i < BOARD_ROW - 1; ++i) {
        SDL_Rect horizontalBorder = {
            boardCover.x,
            boardCover.y + (i + 1) * CELL_SIZE + i * BORDER_SIZE,
            BOARD_COL * CELL_SIZE + (BOARD_COL - 1) * BORDER_SIZE,
            BORDER_SIZE
        };

        SDL_RenderFillRect(boardRenderer, &horizontalBorder);
    }

    for (int j = 0; j < BOARD_COL - 1; ++j) {
        SDL_Rect verticalBorder = {
            boardBaseCoord.x + (j + 1) * CELL_SIZE + j * BORDER_SIZE,
            boardBaseCoord.y,
            BORDER_SIZE,
            BOARD_ROW * CELL_SIZE + (BOARD_ROW - 1) * BORDER_SIZE
        };

        SDL_RenderFillRect(boardRenderer, &verticalBorder);
    }
}

bool Board::checkMouseInBoard(int mouseX, int mouseY) {
    return (boardCover.x <= mouseX and mouseX <= boardCover.x + boardCover.w and
            boardCover.y <= mouseY and mouseY <= boardCover.y + boardCover.h);
}