#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <vector>

#include "GameObject.h"
#include "GameState.h"




class GameObject;


class PauseState : public GameState
{
public:

        virtual bool onEnter();
        virtual bool onExit();


        virtual void render();
        virtual void update();

        virtual std::string getStateID() const { return s_pauseID; }


private:

        static void s_pauseToMain();
        static void s_resumePlay();

        static const std::string s_pauseID;

        std::vector<GameObject*> m_gameObjects;

};

#endif // PAUSESTATE_H
