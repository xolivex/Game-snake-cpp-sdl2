#include "Game.h"
const int width = 800;
const int heigth = 640;


Game * game;

int main(int argc,char* argv[])
{
    game = new Game();
    game->init("snake",width,heigth,false);
    while (game->isRunning())
    {
        SDL_Delay(16);
        game->handleEvents();
        game->update();
        game->draw();
        
    }
    game->clean();
    delete game;
    return 0;
}