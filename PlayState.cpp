#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Game.h"


const std::string PlayState::s_playID = "PLAY";


bool PlayState::onEnter()
{

    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha2.png", "penguin_player", TheGame::Instance()->getRenderer()))
    {
        return false;
    }


    GameObject* player = new Player(new LoaderParams(300, 200, 64, 64, "penguin_player"));

    m_gameObjects.push_back(player);


    std::cout << "Entering PlayState \n";
    return true;
}

bool PlayState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("penguin_player");

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
