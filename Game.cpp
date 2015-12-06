#include "Game.h"
#include <SDL_image.h>
#include <iostream>

Game::Game(){}
Game::~Game(){}

/* INIT */
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

    //handling fullscreen mode
    int flags = 0;

    if(fullscreen){

        flags = SDL_WINDOW_FULLSCREEN;
    }



    //attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);


        if(m_pWindow != 0){ // window init success

            std::cout << "window creation success\n";
            //set the pointer to our renderer
            //parameters: 1: window we want to render
            //            2: index of the rendering driver to initialize (-1: first capable driver)
            //            3: SDL_RendererFlag (0: default, no flag)
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0){ // renderer init success

                std::cout << "renderer creation success\n";
                //render a blue image on the screen
                SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);

            }else{ // renderer init fail

                std::cout << "renderer init fail\n";
                return false;
                }
        }else{ // window init fail

            std::cout << "window init fail\n";
            return false;
            }
    }else{ // SDL init fail

        std::cout << "SDL init fail\n";
        return false;
        }

    std::cout << "init success\n";
    m_bRunning = true; // everything initialized successfully, start the main loop


    /* /////////////////////////////////////////////////////////////////////////////// */

    SDL_Surface* pTempSurface = IMG_Load("Resources/animate-alpha.png");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    //position
    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;
    m_sourceRectangle.x = 0;
    m_sourceRectangle.y = 0;

    //rectangle size
    m_destinationRectangle.w = 128;
    m_destinationRectangle.h = 82;
    m_sourceRectangle.w = 128;
    m_sourceRectangle.h = 82;

    /* /////////////////////////////////////////////////////////////////////////////// */

    return true;

}



/* RENDER */
void Game::render(){

    // clear the renderer to the draw color
    SDL_RenderClear(m_pRenderer);

    /* /////////////////////////////////////////////////////////////////////////////// */
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

    /* /////////////////////////////////////////////////////////////////////////////// */

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}


/* UPDATE */
void Game::update(){
    //every 100 milliseconds shift the x value of our source rectangle by
    //128 pixels (the width of a frame), multiplied by the current frame we want,
    //giving us the correct position

    //SDL_GetTicks return the amount of milliseconds since SDL was initialized
    //then we divide it by the amount of time(ms) we want between frames
    //then use modulo operator to keep it in range of the amount of frames we have in our animation
    m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));

}


/* HANDLE EVENTS */
void Game::handleEvents(){

    SDL_Event event;

    if(SDL_PollEvent(&event)){

        switch (event.type){

            case SDL_QUIT: m_bRunning = false;
            break;
            default: break;
        }
    }
}



/* CLEAN */
void Game::clean(){

    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

