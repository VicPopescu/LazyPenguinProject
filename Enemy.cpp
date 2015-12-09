#include "Enemy.h"






Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams){}


void Enemy::draw(){

    SDLGameObject::draw(); // we now use SDLGameObject
}



void Enemy::update(){

    //this will increment x on the window vector!!!
    m_x -= 1;

    m_currentFrame = int((3 +(SDL_GetTicks() / 100) % 3));
}



void Enemy::clean(){}

