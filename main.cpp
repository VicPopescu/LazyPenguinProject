#include "Game.h"
#include "Windows.h"



// creating the Game object
Game* g_game = 0;

//FPS constants
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS; //how much we delay between loops to get 60 fps



/* MAIN FUNCTION */
int main(int argc, char* argv[]){

    //fps calculation variables
    Uint32 frameStart, frameTime;

    std::cout << "game init attempt...\n";

    if(TheGame::Instance()->init("Main window", 100, 100, 640, 480, false)){

        std::cout << "game init success!\n";

        while(TheGame::Instance()->running()){

            //get the time and store it in frameStart
            frameStart = SDL_GetTicks();

            //run game loop
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();

            //store how long it took to run, by subtracting the time our frame started from current time
            frameTime = SDL_GetTicks() - frameStart;

            //if it's less then the time we want a frame to take, we call SDL_Delay to make our loop wait
            if(frameTime < DELAY_TIME){
                //subtracting how long the loop already took to complete and delay the rest of the time
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }else{

        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }


    std::cout << "game closing...\n";
    TheGame::Instance()->clean();
    return 0;
}
