#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "SDLGameObject.h"


class Background : public SDLGameObject{

public:

        Background(const LoaderParams* pParams);
        virtual void draw();
        virtual void update();
        virtual void clean();

private:



};

#endif // BACKGROUND_H
