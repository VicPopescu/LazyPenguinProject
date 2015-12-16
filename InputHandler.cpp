#include "InputHandler.h"
#include "Game.h"

//singleton
InputHandler* InputHandler::s_pInstance = 0;




/* ****************CONSTRUCTOR BEGIN**************** */
//push our three mouse button states(default to false) into the array
InputHandler::InputHandler() : m_keystate(0), m_bJoysticksInitialised(false), m_mousePosition(new Vector2D(0,0))
{
    //mouse button states
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}
/* ****************CONSTRUCTOR END**************** */





/* ****************DESTRUCTOR BEGIN**************** */
InputHandler::~InputHandler()
{
    //delete everything here
    //need to implement soon
}
/* ****************DESTRUCTOR END**************** */






/* ****************UPDATE BEGIN**************** */
void InputHandler::update()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            //EXIT GAME EVENT
            case SDL_QUIT:
                TheGame::Instance()->quit();
                break;

            //CONTROLLER EVENTS
            case SDL_JOYAXISMOTION:
                onJoystickAxisMove(event);
                break;

            case SDL_JOYBUTTONDOWN:
                onJoystickButtonDown(event);
                break;

            case SDL_JOYBUTTONUP:
                onJoystickButtonUp(event);
                break;

            //MOUSE EVENTS
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;

            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            //KEYBOARD EVENTS
            case SDL_KEYDOWN:
                onKeyDown();
                break;

            case SDL_KEYUP:
                onKeyUp();
                break;

            //DEFAULT
            default:
                break;
        }
    }


}
/* ****************UPDATE END**************** */





/* ****************CONTROLLER BEGIN**************** */

/* INITIALISE BEGIN*/
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
                //array to hold buttons values
                std::vector<bool> tempButtons;
                //fill array with false values
                for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
                {
                    tempButtons.push_back(false);
                }
                //push button array into button state array
                m_buttonStates.push_back(tempButtons);
            }
            else
            {
                //in case of an error
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
/* END*/

/*  CLEAN BEGIN */
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
/* END */


/* BUTTON STATE START */
bool InputHandler::getButtonState(int joy, int buttonNumber)
{
    return m_buttonStates[joy][buttonNumber];
}
/* END */


/* EVENTS */

//sticks
void InputHandler::onJoystickAxisMove(SDL_Event &event)
{
     int whichOne = event.jaxis.which;

     //left stick move left or right
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

     //left stick move up or down
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

    //right stick move up or down
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

    //right stick move left or right
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
}

//buttons
//press
void InputHandler::onJoystickButtonDown(SDL_Event &event)
{
    int whichOne = event.jaxis.which;

    m_buttonStates[whichOne][event.jbutton.button] = true;
}
//release
void InputHandler::onJoystickButtonUp(SDL_Event &event)
{
    int whichOne = event.jaxis.which;

    m_buttonStates[whichOne][event.jbutton.button] = false;
}


/* ****************CONSTROLLER END**************** */






/* ****************MOUSE BEGIN**************** */
//Buttons
bool InputHandler::getMouseButtonState(int buttonNumber) const
        {
            return m_mouseButtonStates[buttonNumber];
        }

//Motion(not working)
Vector2D* InputHandler::getMousePosition() const
{
    return m_mousePosition;
}

void InputHandler::onMouseMove(SDL_Event &event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

//Reset
void InputHandler::reset()
{
    m_mouseButtonStates[LEFT] = false;
    m_mouseButtonStates[RIGHT] = false;
    m_mouseButtonStates[MIDDLE] = false;
}
//EVENTS
void InputHandler::onMouseButtonDown(SDL_Event &event)
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

void InputHandler::onMouseButtonUp(SDL_Event &event)
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

/* ****************MOUSE END**************** */








/* ****************KEYBOARD START**************** */
//Is key down
bool InputHandler::isKeyDown(SDL_Scancode key) const
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}
//On key press
void InputHandler::onKeyDown()
{
    m_keystate = SDL_GetKeyboardState(0);
}
//On key release
void InputHandler::onKeyUp()
{
    m_keystate = SDL_GetKeyboardState(0);
}

/* ****************KEYBOARD END**************** */










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






