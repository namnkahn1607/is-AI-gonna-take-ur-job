#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "texture.h"

const int FRAME_DELAY = 1000 / 144;

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

const SDL_Color playerDomainColor = {194, 232, 255, 255};
const SDL_Color playerSignatureColor = {10, 173, 255, 255};
const SDL_Color botDomainColor = {249, 176, 202, 255};
const SDL_Color botSignatureColor = {249, 38, 114, 255};
const SDL_Color backgroundColor = {234, 238, 244, 255};
const SDL_Color deadCellColor = {0, 0, 0, 255};

const bool PLAYER = true;
const bool BOT = false;

const int CELL_SIZE = 27;

typedef enum CellState {
    CELL_DEAD,
    CELL_BROKEN,
    CELL_ALIVE,
    CELL_OCCUPIED
} State;

const int BORDER_SIZE = 3;

const int BOARD_ROW = 10;
const int BOARD_COL = 10;

typedef enum EXIT_CODE {
    PROGRAM_SUCCESS
} EXIT_CODE;