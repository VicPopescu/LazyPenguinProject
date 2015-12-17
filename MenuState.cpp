

#include "MenuState.h"




const std::string MenuState::s_menuID = "MENU";

bool MenuState::onEnter()
{
    std::cout << "Entering MenuState \n";
    return true;
}

bool MenuState::onExit()
{
    std::cout << "Exiting MenuState \n";
    return true;
}

void MenuState::update()
{
    //nothing yet
}

void MenuState::render()
{
    //nothing here either, yet
}
