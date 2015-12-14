#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "Vector2D.h"



class SDLGameObject : public GameObject
{
public:
        SDLGameObject(const LoaderParams* pParams);
        virtual void draw();
        virtual void update();
        virtual void clean();

protected:
        //initial frame position on window
        Vector2D m_position;
        //moving velocity from initial position
        Vector2D m_velocity;
        //adding acceleration
        Vector2D m_acceleration;

        //sprite frame properties
        int m_width;
        int m_height;
        int m_currentRow;
        int m_currentFrame;
        std::string m_textureID;
};

#endif // SDLGAMEOBJECT_H
