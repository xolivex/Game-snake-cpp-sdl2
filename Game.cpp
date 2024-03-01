
#include "Game.h"
#include "Objects.h"

Objects * cobra;
Objects * maca;
Objects * calda;
Objects * background;


Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int width, int heigth, bool fullscreen)
{
    int flags = 0;

    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,heigth,flags);
        if(window)
        {
            std::cout<<"window created..."<<std::endl;
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            std::cout<<"created renderer..."<<std::endl;
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
        
        cobra = new Objects();
        maca = new Objects();
        calda = new Objects();
        background = new Objects();
        
        cobra->objInit("assets/cobra.png");
        maca->objInit("assets/maca.png");
        calda->objInit("assets/calda.png");
        background->objInit("assets/background.png");

        right = true;
        running = true;
    }else
    {
        running = false;
    }
    
}

void Game::handleEvents()
{
    SDL_Event events;
    SDL_PollEvent(&events);
    switch(events.type)
    {
    case SDL_KEYDOWN:
        switch (events.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;
        case SDLK_UP:
            up = true;
            down = false;
            left = false;
            right = false;
            break;
        case SDLK_DOWN:
            up = false;
            down = true;
            left = false;
            right = false;
            break;
        case SDLK_LEFT:
            up = false;
            down = false;
            left = true;
            right = false;
            break;
        case SDLK_RIGHT:
            up = false;
            down = false;
            left = false;
            right = true;
            break;
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    
    

    //conta 1 segundo antes de atualizar a movimentacao
    cont++;
    if(cont == vel)
    {

        
       //carrega a posição inicial da cabeça e passa pra uma variavel memorizadora
       //para atualizar a proxima posição da cabeça
       memoSnakex[0] = snakeX;
       memoSnakey[0] = snakeY;
        //atualiza todas as outras variaveis da calda com a posição anterior somando +1
        //para não apagar a posição 0 do vetor memosnake x e y
       for(int i = 0;i < nCaldas; i++)
       {
           memoSnakex[i+1] = caldaX[i];
           memoSnakey[i+1] = caldaY[i];
       }  
        //move a cabeça da cobra
        if(up)
        {
            snakeY -= snakeH;
        }
        if(down)
        {
            snakeY += snakeH;
        }
        if(left)
        {
            snakeX -= snakeW;
        }
        if(right)
        {
            snakeX += snakeW;
        }
        
        cont = 0;
        
        caldaX[0] = memoSnakex[0];
        caldaY[0] = memoSnakey[0];
        
        for(int i = 0;i < nCaldas; i++)
        {
            caldaX[i+1] = memoSnakex[i+1];
            caldaY[i+1] = memoSnakey[i+1];
        }   

   
    }
    //----
    
    //quando come a maca
    if(snakeX == macaX && snakeY == macaY)
    {
        if(vel > 6)
            vel -= 2;
        macaX = tempox * 32;
        macaY = tempoy * 32;
        nCaldas += 1;
        score1 += 1;
        if(score1 > 9)
        {
            score1 = 0;
            score2 +=1;
        }

        for(int i = 0;i < nCaldas; i++)
        {
            if(macaX == caldaX[i] && macaY == caldaY[i])
            {
                macaX += 32;
                std::cout << "bateu" <<std::endl;
                
            }
        }
        
    }
    
    //ccaso a maca nasca fora da tela
    if(macaX >= 800 or macaY >= 640)
    {
        macaX = 0;
        macaY = 32;
    }

    //gera cordenadas aleatorias
    tempox += 1;
    tempoy += 1;
    if(tempox >= 25)
    {
        tempox = 0;
    }
    if(tempoy >= 20)
    {
        tempoy = 1;
    }
    
    //quando bate nas bordas
    if(snakeX+snakeW > 800)
        snakeX = 0;
    if(snakeX < 0)
        snakeX = 800 - 32;
    if(snakeY+snakeH > 640)
        snakeY = 32;
    if(snakeY < 32)
        snakeY = 640 - 32;
    //quando bate na calda
    for(int i = 0;i < nCaldas; i++)
    {
        if(snakeX == caldaX[i] && snakeY == caldaY[i])
        {
            snakeX = 12 * 32;
            snakeY = 10 * 32;
            vel = 60;
            nCaldas = 0;
            up = false;
            down = false;
            left = false;
            right = false;
        }
    }

    background->objUpdate(backgx,backgy,backw,backh);
    cobra->objUpdate(snakeX,snakeY,snakeW,snakeH);
    maca->objUpdate(macaX,macaY,macaW,macaH);
     
}

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderClear(renderer);
    background->objDraw();

    for(int i = 0;i < nCaldas;i++)
    {
        calda->objUpdate(caldaX[i],caldaY[i],caldaW,caldaH);
        calda->objDraw(renderer);
    }

    cobra->objDraw(renderer);
    maca->objDraw(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}