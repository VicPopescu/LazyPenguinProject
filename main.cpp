#include "Game.h"
#include "Windows.h"

// creating the Game object
Game* g_game = 0;



/* MAIN FUNCTION */
int main(int argc, char* argv[]){

    //create a new instance of the game
    g_game = new Game();
    //calling the init() function from game class
    g_game->init("Lazy Penguin", 100, 100, 640, 480, false);

    //while running() is returning "true"
    while(g_game->running()){
    //call these functions
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    //////
    SDL_Delay(10); // add the delay
    }
    //when running() return "false"
    g_game->clean();
    return 0;

}

