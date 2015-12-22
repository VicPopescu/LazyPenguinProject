#include "PauseState.h"
#include "Game.h"
#include "MenuButtons.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
    TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}


bool PauseState::onEnter()
{
    if(!TheTextureManager::Instance()->load("Resources/resume.png", "resumebutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("Resources/main-menu.png", "mainbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* button1 = new MenuButtons(new LoaderParams(200, 100, 350, 90, "mainbutton"), s_pauseToMain);
    GameObject* button2 = new MenuButtons(new LoaderParams(200, 300, 350, 90, "resumebutton"), s_resumePlay);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Pause State ON\n";
    return true;
}


bool PauseState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
    TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

    // reset mouse button states to false
    TheInputHandler::Instance()->reset();

    std::cout << "Pause State OFF\n";
    return true;
}






