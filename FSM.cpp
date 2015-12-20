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
        std::cout << "I am 1 \n";
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            std::cout << "I am 2 \n";
            return; // do nothing
        }
        std::cout << "I am 3 \n";
		m_gameStates.back()->onExit();
		m_gameStates.pop_back();
		std::cout << "I am 4 \n";
    }

	// initialize it
	std::cout << "I am 5 \n";
    pState->onEnter();
    std::cout << "I am 6 \n";

    // push back our new state
    m_gameStates.push_back(pState);
    std::cout << "I am 7 \n";
}
