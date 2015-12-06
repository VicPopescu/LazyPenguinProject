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
        //update the sprite sheet frame position, by moving the location of the source rectangle
        //and copy it to the renderer
        void update();
        //allow us to close the application the regular way
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

        //SDL Texture pointers:
        SDL_Texture* m_pTexture; //new SDL Texture variable
        //the area we want to copy from a texture onto the window
        SDL_Rect m_sourceRectangle;
        //the window area where the sourceRectangle will be draw
        SDL_Rect m_destinationRectangle;

        //this variable will decide if the game is running or not
        bool m_bRunning;
};

#endif /* defined(Game) */
