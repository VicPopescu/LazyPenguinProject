#include "Game.h"
#include "Windows.h"



// creating the Game object
Game* g_game = 0;



/* MAIN FUNCTION */
int main(int argc, char* argv[]){

    std::cout << "game init attempt...\n";

    if(TheGame::Instance()->init("Main window", 100, 100, 640, 480, false)){

        std::cout << "game init success!\n";

        while(TheGame::Instance()->running()){

            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            SDL_Delay(20);
        }
    }else{

        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }


    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    return 0;
}
