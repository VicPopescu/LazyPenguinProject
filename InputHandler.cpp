#include "InputHandler.h"

InputHandler::InputHandler(){}
InputHandler::~InputHandler(){}


void InputHandler::initialiseJoysticks()
{
    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    if(SDL_NumJoysticks() > 0)
    {
        for(int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_Joystick* joy = SDL_JoystickOpen(i);

            //"SDL_JoystickOpened" can't be used since SDL 2.0
            //so I used a workaround: just check if it's a valid pointer
            //because SDL_Joystick call returns a NULL pointer if it fails
            if(joy)
            {
                m_joysticks.push_back(joy);
            }
            else
            {
                std::cout << SDL_GetError();
            }
        }

        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;

        std::cout << "Initialized" << m_joysticks.size() << " controller(s)" ;
    }
    else
    {
        m_bJoysticksInitialised = false;
    }
}
