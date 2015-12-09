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


       // Load file source
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha2.png", "animate", m_pRenderer)){

        return false;
    }


    //////////////////////////////////////
    m_go.load(100, 100, 64, 64,  "animate");
    m_player.load(300, 300, 64, 64, "animate");
    //////////////////////////////////////



    return true;

}










/* RENDER */
void Game::render(){

    // clear the renderer to the draw color
    SDL_RenderClear(m_pRenderer);

    //////////////////////////////////
    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);
    //////////////////////////////////

    /* ///////////////////////////////////////////////////////////////////////////////

    // draw specific frames   //(id, x, y, height, width, row, current frame, renderer)

    //Picture 1
    TheTextureManager::Instance()->drawFrame("animate", 130,250, 64, 64, 5, m_currentFrame1, m_pRenderer);
    //Picture 3
    TheTextureManager::Instance()->drawFrame("animate", 260,250, 64, 64, 2, m_currentFrame3, m_pRenderer);
    //Picture 4
    TheTextureManager::Instance()->drawFrame("animate", 325,250, 64, 64, 3, m_currentFrame4, m_pRenderer);
    //Picture 5
    TheTextureManager::Instance()->drawFrame("animate", 390,250, 64, 64, 4, m_currentFrame5, m_pRenderer);
    //Picture 6
    TheTextureManager::Instance()->drawFrame("animate", 455,250, 64, 64, 1, m_currentFrame6, m_pRenderer);

    // Draw
    // Draw non-animated picture //(id, x, y, height, width, renderer)
    //Picture 2
    TheTextureManager::Instance()->draw("animate", 195,250, 64, 64, m_pRenderer);


    */
    /* /////////////////////////////////////////////////////////////////////////////// */

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}


/* UPDATE */
void Game::update(){
    //every 200 (or whatever I put there) milliseconds shift the x value of our source rectangle by
    //64 pixels (the width of a frame), multiplied by the current frame we want,
    //giving us the correct position
    //SDL_GetTicks return the amount of milliseconds since SDL was initialized
    //then we divide it by the amount of time(ms) we want between frames
    //then use modulo operator to keep it in range of the amount of frames we have in our animation
                //m_currentFrame = int(((SDL_GetTicks() / 200) % 2));

        m_go.update();
        m_player.update();


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

