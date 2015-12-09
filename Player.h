#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"


class Player: public GameObject{ //inherit GameObject;

public:
        Player();
        ~Player();


        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* pRenderer);
        void update();
        void clean();




    protected:
    private:
};

#endif // PLAYER_H
