#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H


#include "SDLGameObject.h"



class AnimatedGraphic : public SDLGameObject
{
public:

        AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
        virtual void draw();
        virtual void update();
        virtual void clean();

private:

        int m_animSpeed;
};

#endif // ANIMATEDGRAPHIC_H
