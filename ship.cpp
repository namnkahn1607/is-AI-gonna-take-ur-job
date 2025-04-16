#include "ship.h"

using namespace std;

Ship::Ship(const char* imgPath, SDL_Renderer* ren, SDL_Point trayPos, int len, Board* playBoard)
    : shipTrayPos(trayPos), shipWidth(len), shipRenderer(ren),
    onBoard(false), horizontal(true), isDragging(false),
    startRow(-1), startCol(-1), offsetX(0), offsetY(0) {
        shipTexture = textureManager::loadFromFile(imgPath, ren);

        shipCover = {
            trayPos.x, trayPos.y,
            len * CELL_SIZE + (len - 1) * BORDER_SIZE, CELL_SIZE
        };

        ownerBoard = playBoard;

        playBoard->shipList.emplace_back(this);
    }

Ship::~Ship() {
    SDL_DestroyTexture(shipTexture);
    shipTexture = nullptr;
}

bool Ship::checkMouseInShip(int mouseX, int mouseY) {
    return (shipCover.x <= mouseX and mouseX <= shipCover.x + shipCover.w and
            shipCover.y <= mouseY and mouseY <= shipCover.y + shipCover.h);
}

void Ship::calculateShipRowCol() {
    int dx = shipCover.x - ownerBoard->getBasePosX;
    int dy = shipCover.y - ownerBoard->getBasePosY;

    int cellSpacing = CELL_SIZE + BORDER_SIZE;

    startCol = (int)round((double)dx / cellSpacing);
    startRow = (int)round((double)dy / cellSpacing);

    if (horizontal) {
        if (startCol < 0)
            startCol = 0;
        if (startCol + shipWidthInCells > BOARD_COL)
            startCol = BOARD_COL - shipWidthInCells;
        if (startRow < 0)
            startRow = 0;
        if (startRow >= BOARD_ROW)
            startRow = BOARD_ROW - 1;
    } else {
        if (startRow < 0)
            startRow = 0;
        if (startRow + shipWidthInCells > BOARD_ROW)
            startRow = BOARD_ROW - shipWidthInCells;
        if (startCol < 0)
            startCol = 0;
        if (startCol >= BOARD_COL)
            startCol = BOARD_COL - 1;
    }
}

void Ship::sendToTray() {
    shipCover.x = shipTrayPos.x;
    shipCover.y = shipTrayPos.y;
    startRow = startCol = -1;
}

void Ship::updateShip(SDL_Event e) {
    switch (e.type) {
        case SDL_MOUSEBUTTONDOWN: {
            if (e.button.button == SDL_BUTTON_LEFT) {
                if (checkMouseWithin(e.button.x, e.button.y)) {
                    isDragging = true;
                    offsetX = mouseX - shipCover.x;
                    offsetY = mouseY - shipCover.y;
                }
            } else if (e.button.button == SDL_BUTTON_RIGHT)
                horizontal = !horizontal;

            break;
        }

        case SDL_MOUSEMOTION: {
            if (isDragging) {
                int mouseX = e.motion.x, mouseY = e.motion.y;

                if (0 <= mouseX and mouseX <= WINDOW_WIDTH and
                    0 <= mouseY and mouseY <= WINDOW_HEIGHT) {
                        shipCover.x = e.motion.x - offsetX;
                        shipCover.y = e.motion.y - offsetY;
                    }
            }

            break;
        }

        case SDL_MOUSEBUTTONUP: {
            if (e.button.button == SDL_BUTTON_LEFT) {
                isDragging = false;

                // if (ownerBoard->checkMouseInBoard(e.button.x, e.button.y))
                //     autoAlignShip();
                // else
                //     sendToTray();
            }

            break;
        }

        case SDL_KEYDOWN: {
            if (e.key.keysym.sym == SDLK_SPACE)
                horizontal = !horizontal;

            break; 
        }

        default:
            break;
    }
}

void Ship::renderShip() {
    SDL_RenderCopy(shipRenderer, shipTexture, nullptr, &shipCover);
}

int Ship::getShipWidth() const {
    return shipWidth;
}

int Ship::getStartRow() const {
    return startRow;
}

int Ship::getStartCol() const {
    return startCol;
}

bool Ship::checkHorizontal() const {
    return horizontal;
}