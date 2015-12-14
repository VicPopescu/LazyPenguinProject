#include "Enemy.h"






Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams){}


void Enemy::draw(){

    SDLGameObject::draw(); // we now use SDLGameObject
}



void Enemy::update(){

    //set up the starting frame and how many frames
    m_currentFrame = int((3 +(SDL_GetTicks() / 100) % 3));


    //this will increment x on the window vector!!!
    m_position.setX(m_position.getX() -1);
    //increment y on window
    m_position.setY(m_position.getY() );


}



void Enemy::clean(){}

