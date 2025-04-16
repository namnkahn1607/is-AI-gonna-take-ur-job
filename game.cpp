#include "game.h"

using namespace std;

Board* playerBoard = nullptr;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* consoleTitle, int xPos, int yPos, 
                int width, int height, bool fullscreen) {
    int fullscreenFlag = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;
        
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        printf("%s\n", "SDL subsys inited!"); 

        win = SDL_CreateWindow(consoleTitle, xPos, yPos, width, height, fullscreenFlag);

        if (win != nullptr)
            printf("%s\n", "window created!");
        
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        if (ren != nullptr)
            printf("%s\n", "renderer created!");

        SDL_SetRenderDrawColor(
            ren, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a
        );

        isRunning = true;
    } else
        isRunning = false;

    playerBoard = new Board({0, 0}, ren, PLAYER);
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
            break;
        }
    }
}

void Game::update() {
    /* stuff to update */
}

void Game::render() {
    SDL_SetRenderDrawColor(
        ren, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a
    );
    
    SDL_RenderClear(ren);

    /* stuff to render */
    playerBoard->renderBoard();

    SDL_RenderPresent(ren);
}

void Game::close() {
    SDL_DestroyWindow(win);
    win = nullptr;
    SDL_DestroyRenderer(ren);
    ren = nullptr;

    SDL_Quit();

    printf("%s\n", "closed game!");
}

bool Game::running() {
    return isRunning;
}