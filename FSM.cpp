#include "FSM.h"
#include <iostream>



void FSM::clean()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();

        delete m_gameStates.back();

        m_gameStates.clear();
    }
}

void FSM::update()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->update();
	}
}

void FSM::render()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}

void FSM::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void FSM::popState()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();
        m_gameStates.pop_back();
    }

    m_gameStates.back()->resume();
}

void FSM::changeState(GameState *pState)
{
    if(!m_gameStates.empty())
    {

        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {

            return; // do nothing
        }

		m_gameStates.back()->onExit();
		m_gameStates.pop_back();

    }

	// initialize it
    pState->onEnter();


    // push back our new state
    m_gameStates.push_back(pState);

}
