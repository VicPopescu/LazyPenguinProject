#include "InputHandler.h"
#include "Game.h"

InputHandler::InputHandler(){}
InputHandler::~InputHandler(){}



InputHandler* InputHandler::s_pInstance = 0;


/* ****************INIT BEGIN**************** */
void InputHandler::initialiseJoysticks()
{
    //check if the controller subsystem has been initialized
    if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    {
        //if it has not been initialized, we initialized it with SDL_InitSubSystem
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    //check if there are any controllers available
    if(SDL_NumJoysticks() > 0)
    {
        //loop through the number of controllers
        for(int i = 0; i < SDL_NumJoysticks(); i++)
        {
            //open controllers
            SDL_Joystick* joy = SDL_JoystickOpen(i);

            //"SDL_JoystickOpened" can't be used since SDL 2.0
            //so I used a workaround: just check if it's a valid pointer
            //because SDL_Joystick call returns a NULL pointer if it fails
            if(joy)
            {
                //push available controllers into our array for closing later
                m_joysticks.push_back(joy);
            }
            else
            {
                std::cout << SDL_GetError();
            }
        }

        //enable listening for controllers
        SDL_JoystickEventState(SDL_ENABLE);
        //set initialized member variable to true if everything is ok
        m_bJoysticksInitialised = true;

        std::cout << "Initialized " << m_joysticks.size() << " controller(s)" ;
    }
    else
    {
        //set initialized member variable to false, if something goes wrong
        m_bJoysticksInitialised = false;
    }
}
/* ****************INIT END**************** */


/* ****************CLEAN BEGIN**************** */
void InputHandler::clean()
{
    if(m_bJoysticksInitialised)
    {
        for(unsigned int i = 0; i < SDL_NumJoysticks(); i++)
        {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}
/* ****************CLEAN END**************** */


/* ****************UPDATE BEGIN**************** */
void InputHandler::update()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {

            TheGame::Instance()->clean();
        }
    }
}
/* ****************UPDATE END**************** */
