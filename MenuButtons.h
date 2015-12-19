#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H

#include "SDLGameObject.h"


class MenuButtons: public SDLGameObject
{
public:

        MenuButtons(const LoaderParams* pParams);

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
};

#endif // MENUBUTTONS_H
