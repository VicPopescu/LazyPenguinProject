#ifndef MENUSTATE_H
#define MENUSTATE_H


#include <vector>


#include "GameState.h"
#include "GameObject.h"




class MenuState : public GameState
{
public:

        virtual bool onEnter();
        virtual bool onExit();

        virtual void update();
        virtual void render();

        virtual std::string getStateID() const {return s_menuID;}



private:

        static const std::string s_menuID;

        //store menu items:
        std::vector<GameObject*> m_gameObjects;

        // call back functions for menu items
        static void s_menuToPlay();
        static void s_exitFromMenu();


};

#endif // MENUSTATE_H
