#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";


bool PlayState::onEnter()
{
    //loading player sprite
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha2.png", "penguin_player", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    //loading enemy sprite
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha3.png", "enemy_player", TheGame::Instance()->getRenderer()))
    {
        return false;
    }


    //creating objects from sprites
    GameObject* player = new Player(new LoaderParams(200, 200, 64, 64, "penguin_player"));
    GameObject* enemy  = new Enemy(new LoaderParams(500, 100, 64, 64, "enemy_player"));

    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);


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
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

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
