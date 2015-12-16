#include "Game.h"
#include <SDL_image.h>
#include <iostream>


Game::Game(){}
Game::~Game(){}


//define our static instance:
Game* Game::s_pInstance = 0;



/* ****************INIT BEGIN**************** */
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


    //Initialize controllers
    TheInputHandler::Instance()->initialiseJoysticks();


    /* ====================================== */

    // Load file source
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha2.png", "animate", m_pRenderer)){

        return false;
    }

     if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha3.png", "animate2", m_pRenderer)){

        return false;
    }

    /* Pushing objects to the m_gameObjects array */
    //players
    m_gameObjects.push_back(new Player(new LoaderParams(10, 100, 64, 64, "animate")));

    //enemies
    m_gameObjects.push_back(new Enemy(new LoaderParams(530, 300, 64, 64, "animate2")));



    /* ====================================== */

    return true;

}
/* ****************INIT END**************** */


/* ****************RENDER BEGIN**************** */
void Game::render(){

    // clear the renderer to the draw color
    SDL_RenderClear(m_pRenderer);

    //////////////////////////////////
    // loop through our objects and draw them
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)

    {
    m_gameObjects[i]->draw();
    }
    //////////////////////////////////

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}
/* ****************RENDER END**************** */


/* ****************UPDATE BEGIN**************** */
void Game::update(){

        // loop through and update our objects

        for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)

        {
        m_gameObjects[i]->update();
        }

}
/* ****************UPDATE END**************** */


/* ****************HANDLE EVENTS BEGIN**************** */
void Game::handleEvents()
{
    TheInputHandler::Instance()->update();

}
/* ****************HANDLE EVENTS END**************** */


/* ****************CLEAN BEGIN**************** */
void Game::clean(){

    std::cout << "cleaning game\n";
    //Clean controllers array
    TheInputHandler::Instance()->clean();
    //Destroy SDL objects
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    //Quit SDL
    SDL_Quit();
}
/* ****************CLEAN END**************** */
