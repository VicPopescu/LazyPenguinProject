#include "MenuState.h"
#include "Game.h"
#include "MenuButtons.h"
#include "PlayState.h"




//need to clean up those includes





const std::string MenuState::s_menuID = "MENU";




bool MenuState::onEnter()
{
    if(!TheTextureManager::Instance()->load("Resources/play-button.png", "playbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("Resources/exit-button.png", "exitbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* button1 = new MenuButtons(new LoaderParams(150, 100, 350, 90, "playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButtons(new LoaderParams(150, 300, 350, 90, "exitbutton"), s_exitFromMenu);


    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);

    std::cout << "Entering MenuState\n";
    return true;

}




bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();

    TheTextureManager::Instance()->clearFromTextureMap("playbutton");
    TheTextureManager::Instance()->clearFromTextureMap("exitbutton");


    std::cout << "Exiting MenuState \n";
    return true;
}




void MenuState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

}




void MenuState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}




void MenuState::s_menuToPlay()
{
    std::cout << "Play button clicked\n";
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());

}



void MenuState::s_exitFromMenu()
{
    std::cout << "Exit button clicked\n";
    TheGame::Instance()->quit();
}
