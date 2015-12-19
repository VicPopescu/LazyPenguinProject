#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H

#include "SDLGameObject.h"
#include "MenuState.h"


class MenuButtons: public SDLGameObject
{
public:

        MenuButtons(const LoaderParams* pParams, void (*callback)());

        virtual void draw();
        virtual void update();
        virtual void clean();


private:

        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };

        void (*m_callback)();
        bool m_bReleased;
};

#endif // MENUBUTTONS_H
