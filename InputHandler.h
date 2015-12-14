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

        //this will be called in each frame in the main game loop to update the event state
        void update();
        //loop through SDL_Joystick* array and call SDL_JoystickClose on each iteration
        void clean();


private:

        InputHandler();
        ~InputHandler();

        //define singleton
        static InputHandler* s_pInstance;

        //pointer to initialized controllers
        std::vector<SDL_Joystick*> m_joysticks;
        //controller status variable
        bool m_bJoysticksInitialised;



};

typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
