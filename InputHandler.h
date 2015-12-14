#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"
#include <string>
#include <vector>
#include <iostream>

/*
*   Singleton InputHandler
*
*   Handle all device input, no matter its origin (mouse, keyboard or controller)
*/


class InputHandler
{
public:

        static InputHandler* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new InputHandler();
            }

            return s_pInstance;
        }
        //initialize controllers
        void initialiseJoysticks();
        //return controller status (initialized or not)
        bool joysticksInitialised(){return m_bJoysticksInitialised;}

        //poll for events and update InputHandler
        void update();
        //loop through SDL_Joystick* array and call SDL_JoystickClose on each iteration
        void clean();


private:

        InputHandler();
        ~InputHandler();

        //pointer to initialized controllers
        std::vector<SDL_Joystick*> m_joysticks;
        //controller status variable
        bool m_bJoysticksInitialised;


        static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
