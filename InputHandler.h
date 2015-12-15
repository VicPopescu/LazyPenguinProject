#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"
#include <vector>
#include <iostream>


#include "Vector2D.h"


/*
*   Singleton InputHandler
*
*   Handle all device input, no matter its origin (mouse, keyboard or controller)
*/




/*  MOUSE BUTTONS VALUES  */
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};



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


        /* CONTROLLER */
        //joy = ID of the controller we want to use
        //stick = 1 for left stick, 2 for the right stick
        int xvalue(int joy, int stick);
        int yvalue(int joy, int stick);

        //controller button state
        bool getButtonState(int joy, int buttonNumber)
        {
            return m_buttonStates[joy][buttonNumber];
        }


        /* MOUSE */
        //mouse button state
        bool getMouseButtonState(int buttonNumber)
        {
            return m_mouseButtonStates[buttonNumber];
        }


private:

        InputHandler();
        ~InputHandler();

        //define singleton
        static InputHandler* s_pInstance;

        /* CONTROLLER */
        std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
        std::vector<SDL_Joystick*> m_joysticks;
        //array of boolean values to handle button events
        std::vector<std::vector<bool>> m_buttonStates;
        //controller status variable
        bool m_bJoysticksInitialised;

        //account for the sensitivity of a controller
        const int m_joystickDeadZone = 10000;


        /* MOUSE */
        std::vector<bool> m_mouseButtonStates;



};

typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
