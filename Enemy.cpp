#include "Enemy.h"






Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
    m_velocity.setY(2);
    m_velocity.setX(0.001);
}


void Enemy::draw(){

    SDLGameObject::draw(); // we use SDLGameObject drawing function
}


void Enemy::handleInput()
{

/*
    //following mouse motion
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position) / 100;
*/


}





void Enemy::update(){

    //set up the starting frame and how many frames
    m_currentFrame = int((3 +(SDL_GetTicks() / 100) % 3));


    if(m_position.getY() < 0)
    {
        m_velocity.setY(2);
    }
    else if(m_position.getY() > 400)
    {
        m_velocity.setY(-2);
    }







/*    //set up velocity
    m_velocity.setX(0);
    m_velocity.setY(0);
*/


/*    //this will increment x on the window vector!!!
    m_position.setX(m_position.getX() -1);
    //increment y on window
    m_position.setY(m_position.getY() );  */

    //using acceleration instead of velocity
//    m_acceleration.setX(-0.1);




    handleInput(); // handling inputs

    //update
    SDLGameObject::update();


}



void Enemy::clean(){}

