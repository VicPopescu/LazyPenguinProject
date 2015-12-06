#include<SDL.h> //access SDL functions


//global variables
SDL_Window* g_pWindow = 0; // pointer to an SDL_Window function, which will be set using the SDL_CreateWindow function
SDL_Renderer* g_pRenderer = 0; //pointer to an SDL_Renderer object



int main(int argc, char* args[]){

    // try to initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){

    // if succeeded create our window
    g_pWindow = SDL_CreateWindow("Setting up SDL",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 480,
    SDL_WINDOW_SHOWN);

    // if the window creation succeeded create our renderer
    if(g_pWindow != 0){

    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }

    }else{

    return 1; // sdl could not initialize
    }


    // if everything succeeded, lets draw the window
    // set to black // This function expects Red, Green, Blue and
    // Alpha as color values
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    // clear the window to black
    SDL_RenderClear(g_pRenderer);
    // show the window
    SDL_RenderPresent(g_pRenderer);
    // wait 3 sec
    SDL_Delay(3000);
    // clean up SDL
    SDL_Quit();
    return 0;
}
