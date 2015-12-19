#include "PlayState.h"



const std::string PlayState::s_playID = "PLAY";


bool PlayState::onEnter()
{
    std::cout << "Entering PlayState \n";
    return true;
}

bool PlayState::onExit()
{
    std::cout << "Exiting PlayState \n";
    return true;
}

void PlayState::update()
{
    //nothing here yet
}

void PlayState::render()
{
    //nothing here yet
}
