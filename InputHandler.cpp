#include "InputHandler.h"
#include "Game.h"

//constructor
//push our three mouse button states(default to false) into the array
InputHandler::InputHandler()
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}



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
                //create a pair of Vector2D*
                m_joystickValues.push_back(std::make_pair(new Vector2D(0,0),new Vector2D(0,0))); // add our pair

                std::vector<bool> tempButtons;

                for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
                {
                    tempButtons.push_back(false);
                }

                m_buttonStates.push_back(tempButtons);
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
            TheGame::Instance()->quit();
        }

        /* ----------------------------------- */

        //listen for controller sticks events (not working correctly)
        if(event.type == SDL_JOYAXISMOTION)
        {
            //find out which controller the event came from
            int whichOne = event.jaxis.which;

            /* left stick move left or right */
            //check the axis the event came from
            if(event.jaxis.axis == 0)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setX(-1);
                }
                else
                {
                    m_joystickValues[whichOne].first->setX(0);
                }
            }

            /* left stick move up or down */
            //check the axis the event came from
            if(event.jaxis.axis == 1)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].first->setY(-1);
                }
                else
                {
                    m_joystickValues[whichOne].first->setY(0);
                }
            }

            /* right stick move left or right */
            //check the axis the event came from
            if(event.jaxis.axis == 3)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                   m_joystickValues[whichOne].second->setX(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setX(-1);
                }
                else
                {
                    m_joystickValues[whichOne].second->setX(0);
                }
            }

            /* right stick move up or down */
            //check the axis the event came from
            if(event.jaxis.axis == 4)
            {
                if (event.jaxis.value > m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(1);
                }
                else if(event.jaxis.value < -m_joystickDeadZone)
                {
                    m_joystickValues[whichOne].second->setY(-1);
                }
                else
                {
                    m_joystickValues[whichOne].second->setY(0);
                }
            }
        }

        /* ----------------------------------- */


        //listen for button events(not working)
        if(event.type == SDL_JOYBUTTONDOWN)
        {
            int whichOne = event.jaxis.which;

            m_buttonStates[whichOne][event.jbutton.button] = true;
        }

        if(event.type == SDL_JOYBUTTONUP)
        {
            int whichOne = event.jaxis.which;

            m_buttonStates[whichOne][event.jbutton.button] = false;
        }

        /* ----------------------------------- */


        //Mouse events
        //Button down
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonStates[LEFT] = true;
            }

            if(event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonStates[MIDDLE] = true;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonStates[RIGHT] = true;
            }
        }


        //Button up
        if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonStates[LEFT] = false;
            }

            if(event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonStates[MIDDLE] = false;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonStates[RIGHT] = false;
            }
        }

        /* ----------------------------------- */





    }
}
/* ****************UPDATE END**************** */



int InputHandler::xvalue(int joy, int stick)
{
    if(m_joystickValues.size() > 0)
    {
        if(stick == 1)
        {
            return m_joystickValues[joy].first->getX();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getX();
        }
    }

    return 0;
}


int InputHandler::yvalue(int joy, int stick)
{
    if(m_joystickValues.size() > 0)
    {
        if(stick == 1)
        {
            return m_joystickValues[joy].first->getY();
        }
        else if(stick == 2)
        {
            return m_joystickValues[joy].second->getY();
        }
    }

    return 0;
}



InputHandler::~InputHandler(){}

