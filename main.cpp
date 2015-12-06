#include<SDL.h> //access SDL functions


//global variables
SDL_Window* g_pWindow = 0; // pointer to an SDL_Window function, which will be set using the SDL_CreateWindow function
SDL_Renderer* g_pRenderer = 0; //pointer to an SDL_Renderer object



int main(int argc, char* args[]){

    // try to initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){

    // if succeeded create pointer to our window
    g_pWindow = SDL_CreateWindow("Setting up SDL",   //window title
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //center position relative to the screen
    640, 480, //width, hight
    SDL_WINDOW_SHOWN); //flag

    // if the window creation succeeded create our renderer
    if(g_pWindow != 0){

    //set the pointer to out renderer, passing the window we want to use as a parameter
    //the second parameter passed is the index of the rendering driver to initialize: -1 means first capable driver
    //the final parameter is SDL_RendererFlag
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }

    }else{

    return 1; // SDL could not initialize
    }


    // if everything initialized correctly, then we can create our window
    // this function expects Red, Green, Blue and alpha as color values
    // setting it to blue
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 0);
    // clear the window to blue
    SDL_RenderClear(g_pRenderer);
    // show the window
    SDL_RenderPresent(g_pRenderer);
    // wait 3 sec
    SDL_Delay(3000);
    // clean up SDL
    SDL_Quit();
    return 0;
}
