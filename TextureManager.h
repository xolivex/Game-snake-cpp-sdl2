#ifndef TextureManager_h
#define TextureManager_h
#include "Game.h"

class TextureManager
{
public:
    SDL_Texture * LoadTexture(const char * texture);
    void drawTexture(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);
private:
    
};


#endif //TextureManager_h