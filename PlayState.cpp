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
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}
