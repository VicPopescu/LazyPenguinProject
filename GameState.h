#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <string>

/*
*   Handling game states.
*   This abstract base class is used to implement a blueprint
*   that will be inherited and followed by our derived classes.
*
*/




class GameState
{

public:
        virtual void onEnter() = 0;
        virtual void onExit() = 0;

        virtual void update() = 0;
        virtual void render() = 0;

        //each state will need to define this function and return its own static const ID
        //the ID is used to ensure that states don't get repeated
        virtual std::string getStateID() const = 0;
};




















#endif // GAMESTATE_H_INCLUDED
