#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL.h"

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

        //poll for events and update InputHandler
        void update();
        //clear any devices we have initialized
        void clean();


private:

        InputHandler();
        ~InputHandler();

        static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;

#endif // INPUTHANDLER_H
