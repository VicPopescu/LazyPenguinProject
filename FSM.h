#ifndef FSM_H
#define FSM_H

#include <vector>

#include "GameState.h"



/*
*   Game State Machine - Handle game states
*   This class will handle:
*       -Removing one state and adding another -> Change states without leaving option to return
*       -Adding one state without removing the previous one -> Pause menus etc.
*       -Removing one state without adding another ->Remove pause states or other state that had been pushed on top of another one
*/


class FSM
{
public:

        //add a state without removing the previous one
        void pushState(GameState* pState);
        //remove previous state before adding another
        void changeState(GameState* pState);
        //remove whichever state is currently being used, without adding another one
        void popState();

        //check if there are any states, and if so, these functions update and render the current state
        void update();
        void render();
        void clean();

        std::vector<GameState*>& getGameStates() { return m_gameStates; }

private:

        //vector to store these states
        std::vector<GameState*> m_gameStates;

};

#endif // FSM_H
