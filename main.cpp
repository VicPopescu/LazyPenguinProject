#include<SDL.h> //access SDL functions



/* GLOBAL VARIABLES */
SDL_Window* g_pWindow = 0; // pointer to an SDL_Window function, which will be set using the SDL_CreateWindow function
SDL_Renderer* g_pRenderer = 0; //pointer to an SDL_Renderer object

bool g_bRunning = false; // this will create a loop


/* SDL INITIALIZATION */
bool init(const char* title, int xpos, int ypos, int height, int width, int flags){

    // initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){

    // if succeeded create our window
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    // if the window creation succeeded create our renderer

        if(g_pWindow != 0){

        g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }else{

    return false; // SDL could not initialize
    }

return true;
}

/* RENDERING FUNCTION */
void render(){

    // set to blue
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 0);
    // clear the window to blue
    SDL_RenderClear(g_pRenderer);
    // show the window
    SDL_RenderPresent(g_pRenderer);
}

/* MAIN FUNCTION */
int main(int argc, char* args[]){

    if(init("Lazy Penguin",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
    480, SDL_WINDOW_SHOWN)){

        g_bRunning = true;
    }else{

    return 1; //something's wrong
    }

    while(g_bRunning){

    render();
    }
    // clean up SDL
    SDL_Quit();
    return 0;
}

