#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>




class Game
{
private:
    SDL_Window * window;
    
    bool running;
    int cont = 0;
    int tempox = 0;
    int tempoy = 1;
    int nvidas = 3;
    int nCaldas = 0;
    int score1 = 0;
    int score2 = 0;
    int vel = 60;

    float memoSnakex[200];
    float memoSnakey[200];

    float backgx = 0;
    float backgy = 32;
    float backw = 800;
    float backh = 608;


    float snakeX = 2 * 32;
    float snakeY = 2 * 32;
    float snakeW = 32;
    float snakeH = 32;

    float caldaX[200];
    float caldaY[200];
    float caldaW = 32;
    float caldaH = 32;
    

    float macaX = 0;
    float macaY = 1 * 32;
    float macaW = 32;
    float macaH = 32;

    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    
    
    
    
public:
    Game();
    ~Game();
    void init(const char* title, int width, int heigth, bool fullscreen);
    void handleEvents();
    void update();
    void draw();
    void clean();
    bool isRunning() { return running; }
    SDL_Renderer * renderer;
};

//----------------------------








#endif //Game_h