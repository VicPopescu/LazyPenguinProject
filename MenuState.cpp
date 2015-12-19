#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButtons.h"
#include <iostream>
#include "PlayState.h"
#include "InputHandler.h"
#include "LoaderParams.h"





const std::string MenuState::s_menuID = "MENU";




bool MenuState::onEnter()
{
    if(!TheTextureManager::Instance()->load("Resources/a-play.png", "playbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("Resources/a-exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    GameObject* button1 = new MenuButtons(new LoaderParams(100, 100, 400, 100, "playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButtons(new LoaderParams(100, 300, 400, 100, "exitbutton"), s_exitFromMenu);


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
}



void MenuState::s_exitFromMenu()
{
    std::cout << "Exit button clicked\n";
}
