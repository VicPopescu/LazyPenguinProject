#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButtons.h"
#include "AnimatedGraphic.h"




//define static variable
const std::string GameOverState::s_gameOverID = "GAMEOVER";




//define static functions
void GameOverState::s_gameOverToMain()
{

    TheGame::Instance()->getStateMachine()->changeState(new MenuState());

}

void GameOverState::s_restartPlay()
{

    TheGame::Instance()->getStateMachine()->changeState(new PlayState());

}






bool GameOverState::onEnter()
{
    if(!TheTextureManager::Instance()->load("Resources/game-over.png", "gameovertext", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("Resources/main-menu.png", "mainbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("Resources/restart-button.png", "restartbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    //                                                             (           pParams,             animSpeed)
    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(230, 100, 190, 30, "gameovertext"), 4);
    GameObject* button1 = new MenuButtons(new LoaderParams(150, 200, 350, 90, "mainbutton"), s_gameOverToMain);
    GameObject* button2 = new MenuButtons(new LoaderParams(150, 300, 350, 90, "restartbutton"), s_restartPlay);

    m_gameObjects.push_back(gameOverText);
    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Enter GameOverState\n";
    return true;

}


bool GameOverState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();
    std::cout << "Exiting GameOverState \n";
    return true;
}


void GameOverState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}


void GameOverState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}
