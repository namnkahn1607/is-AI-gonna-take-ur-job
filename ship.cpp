#include "ship.h"

using namespace std;

Ship::Ship(const char* imgPath, SDL_Renderer* ren, SDL_Point trayPos, int len)
    : shipTrayPos(trayPos), shipWidth(len), shipRenderer(ren),
    onBoard(false), horizontal(true), isDragging(false),
    startRow(-1), startCol(-1), offsetX(0), offsetY(0) {
        shipTexture = textureManager::loadFromFile(imgPath, ren);

        shipCover = {
            trayPos.x, trayPos.y,
            len * CELL_SIZE + (len - 1) * BORDER_SIZE, CELL_SIZE
        };
    }

Ship::~Ship() {
    SDL_DestroyTexture(shipTexture);
    shipTexture = nullptr;
}

bool Ship::checkMouseWithin(int mouseX, int mouseY) {
    return (shipCover.x <= mouseX and mouseX <= shipCover.x + shipCover.w and
            shipCover.y <= mouseY and mouseY <= shipCover.y + shipCover.h);
}

void Ship::shipHandleEvents(SDL_Event e) {
    switch (e.type) {

    }
}

void Ship::updateShip() {

}

void Ship::renderShip() {
    SDL_RenderCopy(shipRenderer, shipTexture, nullptr, &shipCover);
}

