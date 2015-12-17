#include "FSM.h"


/* pushState */
void FSM::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();

}

/* popState */
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

/* changeState */
void FSM::changeState(GameState *pState)
{
    //check if there are already any states in the array
    if(!m_gameStates.empty())
    {
        //if there are, check whether their state ID is the same as the current one
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            //if it is:
            return; //don't do anything
        }
        //if the state ID doesn't match
        if(m_gameStates.back()->onExit())
        {
            //remove current state
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    //then push back our new state
    m_gameStates.push_back(pState);
    //initialize it
    m_gameStates.back()->onEnter();

}
