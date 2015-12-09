#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}


void Player::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
}



void Player::update(){

    //this will increment x on the window, not on the sprite!!!
    //need to corect this in the SDLGameObjectCLass
    m_x += 2;//need to correct this! same for enemy class
    //this works, take the correct number of frames out of the sprite row
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));
}
void Player::clean(){}






