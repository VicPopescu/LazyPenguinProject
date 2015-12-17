#ifndef GAME_H
#define GAME_H
//////////////////
#include "SDL.h"
#include <vector>
/////////////////


#include "TextureManager.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "FSM.h"
#include "MenuState.h"
#include "PlayState.h"




class Game
{

public:

        // create the public instance function
        static Game* Instance(){

        if(s_pInstance == 0){

            s_pInstance = new Game();
            return s_pInstance;
        }

        return s_pInstance;
        }


        //will return our SDL_Renderer object:
        SDL_Renderer* getRenderer() const { return m_pRenderer; }



        //initialize SDL
        bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        //render
        void render();
        //update the sprite sheet frame position, by moving the location of the source rectangle
        //and copy it to the renderer
        void update();
        //update InputHandler, for now
        void handleEvents();
        //clean the memory and close everything
        void clean();
        // a function to access the private running variable
        bool running() { return m_bRunning;};
        void quit() { m_bRunning = false; }





private:
        Game();
        ~Game();

        //pointer to an SDL_Window function, which will be set using the SDL_CreateWindow function
        SDL_Window* m_pWindow;
        //pointer to an SDL_Renderer object; set using the SDL_CreateRenderer function
        SDL_Renderer* m_pRenderer;


        //this variable will decide if the game is running or not
        bool m_bRunning;


        std::vector<GameObject*> m_gameObjects;

        //Game State Machine (FSM)
        FSM* m_pGameStateMachine;

        //singleton
        static Game* s_pInstance;

};

// create the typedef
typedef Game TheGame;

#endif
