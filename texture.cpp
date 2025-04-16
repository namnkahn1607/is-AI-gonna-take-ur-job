#include "texture.h"

using namespace std;

SDL_Texture* textureManager::loadFromFile(const char* imgPath, SDL_Renderer* ren) {
    SDL_Surface* loadedSur = IMG_Load(imgPath);
    
    if (loadedSur == nullptr) {
        SDL_LogError(
            SDL_LOG_CATEGORY_VIDEO, "cannot load img onto sur: %s\n", IMG_GetError()
        );

        return nullptr;
    }

    SDL_Texture* txtr = SDL_CreateTextureFromSurface(ren, loadedSur);
    SDL_FreeSurface(loadedSur);

    return txtr;
}