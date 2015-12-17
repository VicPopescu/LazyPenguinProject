#ifndef MENUSTATE_H
#define MENUSTATE_H


#include "GameState.h"



class MenuState : public GameState
{
public:

        virtual void onEnter();
        virtual void onExit();

        virtual void update();
        virtual void render();

        virtual std::string getStateID() const {return s_menuID;}



private:

        static const std::string s_menuID;
};

#endif // MENUSTATE_H
