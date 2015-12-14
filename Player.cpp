#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}


void Player::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
}



void Player::update(){

    //override currentRow
    m_currentRow = 1;

    //start: frame 1, continue 3 more frames:
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));

    //set up velocity
    //add 1 to our m_position x value each time  the update function is called
    m_velocity.setX(1);

    //update
    SDLGameObject::update();
}



void Player::clean(){}






