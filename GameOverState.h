#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <vector>


#include "GameState.h"


class GameObject;

class GameOverState : public GameState
{
public:

        virtual bool onEnter();
        virtual bool onExit();

        virtual void update();
        virtual void render();

        virtual std::string getStateID() const {return s_gameOverID;}

private:

        static void s_gameOverToMain();
        static void s_restartPlay();

        static const std::string s_gameOverID;

        std::vector<GameObject*> m_gameObjects;

};

#endif // GAMEOVERSTATE_H
