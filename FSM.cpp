#include "FSM.h"


void FSM::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();

}


void FSM::popState()
{
    //check if there are any states available to remove
    if(!m_gameStates.empty())
    {
        //if there are, call onExit of the current state and remove it
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

}


void FSM::changeState(GameState *pState)
{


}
