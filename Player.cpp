#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}


void Player::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
}



void Player::update(){


    //set up the starting frame and how many frames
    //start: frame 1, continue 3 more frames:
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));

    //start: from frame 2, continue 2 more frames
//    m_currentFrame = int((1 + (SDL_GetTicks() / 100) % 2));

    //override currentRow
    m_currentRow = 1;

    //set up velocity
    //add 1 to our m_position x value each time  the update function is called
    m_velocity.setX(1);
    SDLGameObject::update();
}



void Player::clean(){}






