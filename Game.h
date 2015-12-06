#ifndef GAME_H
#define GAME_H

#include "SDL.h"


class Game
{
    public:

        Game();
        ~Game();
        //initialize SDL
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        //render
        void render();
        //update
        void update();
        ////allow us to close the application the regular way
        void handleEvents();
        //clean the memory and close everything
        void clean();
        // a function to access the private running variable
        bool running() { return m_bRunning;};

    private:

        //pointer to an SDL_Window function, which will be set using the SDL_CreateWindow function
        SDL_Window* m_pWindow;
        //pointer to an SDL_Renderer object; set using the SDL_CreateRenderer function
        SDL_Renderer* m_pRenderer;
        //this variable will decide if the game is running or not
        bool m_bRunning;
};

#endif /* defined(Game) */
