#include "game.h"

using namespace std;

Game* newGame = nullptr;

int main(int argc, char* argv[]) {
    Uint32 frameStart;
    int frameTime;
    
    newGame = new Game();

    newGame->init(
        "is AI gonna take ur job?!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, NOT_FULLSCREEN
    );

    while (newGame->running()) {
        frameStart = SDL_GetTicks();
        
        newGame->handleEvents();
        
        newGame->update();
        
        newGame->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime)
            SDL_Delay(FRAME_DELAY - frameTime);
    }

    newGame->close();

    delete newGame;

    newGame = nullptr;

    return PROGRAM_SUCCESS;
}