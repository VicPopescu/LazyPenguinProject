#ifndef MENUSTATE_H
#define MENUSTATE_H


#include "GameState.h"



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
};

#endif // MENUSTATE_H
