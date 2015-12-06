#include "Game.h"
#include "Windows.h"

// creating the Game object
Game* g_game = 0;



/* MAIN FUNCTION */
int main(int argc, char* argv[]){

    //create a new instance of the game
    g_game = new Game();
    g_game->init("Lazy Penguin", 100, 100, 640, 480, true);

    while(g_game->running()){

    g_game->handleEvents();
    //g_game->update();
    g_game->render();
    }

    g_game->clean();
    return 0;

}

