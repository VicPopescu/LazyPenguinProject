#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"


class Player: public GameObject{ //inherit GameObject;

public:
        Player();
        ~Player();

        void draw(){

            GameObject::draw();
            std::cout << "draw player";
        }

        void update(){

            std::cout << "update player";
            m_x = 10;
            m_y = 20;
        }

        void clean(){

            GameObject::clean();
            std::cout << "clean player";
        }



    protected:
    private:
};

#endif // PLAYER_H
