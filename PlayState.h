#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"




class GameObject;


class PlayState : public GameState
{
public:

        virtual bool onEnter();
        virtual bool onExit();

        virtual void update();
        virtual void render();

        virtual std::string getStateID() const {return s_playID;}

        //check for collisions
        bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);


private:

        static const std::string s_playID;
        std::vector<GameObject*> m_gameObjects;
};

#endif // PLAYSTATE_H
