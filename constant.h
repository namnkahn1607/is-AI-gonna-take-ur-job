#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef enum State {
    CELL_DEAD,
    CELL_BROKEN,
    CELL_ALIVE,
    CELL_OCCUPIED
} State;

const int FRAME_DELAY = 1000 / 144;

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

const bool FULLSCREEN = true;
const bool NOT_FULLSCREEN = false;

constexpr const char* fontPath = "assets/font/Consolas.ttf";
const int inGameFontSize = 14;

const SDL_Color playerDomainColor = {194, 232, 255, 255};
const SDL_Color playerSignatureColor = {10, 173, 255, 255};
const SDL_Color botDomainColor = {249, 176, 202, 255};
const SDL_Color botSignatureColor = {249, 38, 114, 255};
const SDL_Color backgroundColor = {234, 238, 244, 255};
const SDL_Color deadCellColor = {0, 0, 0, 255};

const bool PLAYER = true;
const bool BOT = false;

const int CELL_SIZE = 27;

const int BORDER_SIZE = 3;
const int BOARD_ROW = 10;
const int BOARD_COL = 10;

const int CARRIER_WIDTH = 5;
const int CARRIER_IDX = 0;
constexpr const char* blueCarrierPath = "assets/img/Bcarrier.png";
constexpr const char* redCarrierPath = "assets/img/Rcarrier.png";

const int BATTLESHIP_WIDTH = 4;
const int BATTLESHIP_IDX = 1;
constexpr const char* blueBattleshipPath = "assets/img/Bbattleship.png";
constexpr const char* redBattleshipPath = "assets/img/Rbattleship.png";

const int CRUISER_WIDTH = 3;
const int CRUISER_IDX = 2;
constexpr const char* blueCruiserPath = "assets/img/Bcruiser.png";
constexpr const char* redCruisePath = "assets/img/Rcruiser.png";

const int SUBMARINE_WIDTH = 3;
const int SUBMARINE_IDX = 3;
constexpr const char* blueSubmarinePath = "assets/img/Bsubmarine.png";
constexpr const char* redSubmarinePath = "assets/img/Rsubmarine.png";

const int DESTROYER_WIDTH = 2;
const int DESTROYER_IDX = 4;
constexpr const char* blueDestroyerPath = "assets/img/Bdestroyer.png";
constexpr const char* redDestroyerPath = "assets/img/Rdestroyer.png";

typedef enum EXIT_CODE {
    PROGRAM_SUCCESS
} EXIT_CODE;