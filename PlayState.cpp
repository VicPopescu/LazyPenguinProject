#include "PlayState.h"



const std::string PlayState::s_playID = "PLAY";


bool onEnter()
{
    std::cout << "Entering PlayState \n";
    return true;
}

bool onExit()
{
    std::cout << "Exiting PlayState \n";
    return true;
}

void update()
{
    //nothing here yet
}

void render()
{
    //nothing here yet
}
