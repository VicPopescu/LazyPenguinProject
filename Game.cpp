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

        std::cout << "+SDL initialized!\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);


        if(m_pWindow != 0){ // window init success

            std::cout << "+Create Window!\n";
            //set the pointer to our renderer
            //parameters: 1: window we want to render
            //            2: index of the rendering driver to initialize (-1: first capable driver)
            //            3: SDL_RendererFlag (0: default, no flag)
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0){ // renderer init success

                std::cout << "+Create Renderer!\n";
                //render a blue image on the screen
                SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);

            }else{ // renderer init fail

                std::cout << "-Renderer initialization failed!\n";
                return false;
                }
        }else{ // window init fail

            std::cout << "-Windows initialization failed!\n";
            return false;
            }
    }else{ // SDL init fail

        std::cout << "SDL initialization failed!\n";
        return false;
        }

    std::cout << "+EVERYTHING was initialized with success!\n";
    std::cout << "................................\n";


    //Initialize controllers
    TheInputHandler::Instance()->initialiseJoysticks();

    // Create Game State Machine and add first state
    m_pGameStateMachine = new FSM();
    m_pGameStateMachine->changeState(new MenuState());




    m_bRunning = true; // everything initialized successfully, start the main loop
    return true;

}
/* ****************INIT END**************** */





/* ****************RENDER BEGIN**************** */
void Game::render(){

    // clear the renderer to the draw color
    SDL_RenderClear(m_pRenderer);

    // FSM render() function
    m_pGameStateMachine->render();

    // draw to the screen
    SDL_RenderPresent(m_pRenderer);
}
/* ****************RENDER END**************** */





/* ****************UPDATE BEGIN**************** */
void Game::update(){

        //FSM update() function
        m_pGameStateMachine->update();

}
/* ****************UPDATE END**************** */


/* ****************HANDLE EVENTS BEGIN**************** */
void Game::handleEvents()
{
    //update inputs function
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
