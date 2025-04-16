#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cmath>
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

const int CARRIER_WIDTH = 5;
const int CARRIER_IDX = 0;
constexpr char* blueCarrierPath = "assets/img/Bcarrier.png";
constexpr char* redCarrierPath = "assets/img/Rcarrier.png";

const int BATTLESHIP_WIDTH = 4;
const int BATTLESHIP_IDX = 1;
constexpr char* blueBattleshipPath = "assets/img/Bbattleship.png";
constexpr char* redBattleshipPath = "assets/img/Rbattleship.png";

const int CRUISER_WIDTH = 3;
const int CRUISER_IDX = 2;
constexpr char* blueCruiserPath = "assets/img/Bcruiser.png";
constexpr char* redCruisePath = "assets/img/Rcruiser.png";

const int SUBMARINE_WIDTH = 3;
const int SUBMARINE_IDX = 3;
constexpr char* blueSubmarinePath = "assets/img/Bsubmarine.png";
constexpr char* redSubmarinePath = "assets/img/Rsubmarine.png";

const int DESTROYER_WIDTH = 2;
const int DESTROYER_IDX = 4;
constexpr char* blueDestroyerPath = "assets/img/Bdestroyer.png";
constexpr char* redDestroyerPath = "assets/img/Rdestroyer.png";

typedef enum EXIT_CODE {
    PROGRAM_SUCCESS
} EXIT_CODE;