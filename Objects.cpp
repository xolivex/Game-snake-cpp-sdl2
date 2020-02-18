#include "Objects.h"
#include "TextureManager.h"


Objects::Objects()
{}
Objects::~Objects()
{}
void Objects::objInit(const char * texturesheet)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
}
void Objects::objUpdate(float x, float y, float w, float h)
{

    dest.x = x;
    dest.y = y;
    dest.h = h;
    dest.w = w; 
}

void Objects::objDraw()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &dest);
}




