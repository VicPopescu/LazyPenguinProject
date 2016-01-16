#include "Enemy.h"
#include "Game.h"






Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams){}



void Enemy::draw(){

    //SDLGameObject::draw(); // we can use SDLGameObject drawing function


    //override SDLGameObject drawing function
    //we want enemy player to turn his back to us when running up
    if(m_velocity.getY() < 0)
    {
        TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame + 3, TheGame::Instance()->getRenderer());
    }
    else
    {
        TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
    }

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

    //set up the starting frame, how many frames, and the animation speed
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));


    if(m_position.getX() == 0 && m_position.getY() == 0)
    {
        m_velocity.setX(2);
        m_velocity.setY(0);
    }

    if(m_position.getX() == 570)
    {
        m_velocity.setX(0);
        m_velocity.setY(2);
    }
    if(m_position.getY() == 410)
    {
        m_velocity.setX(-2);
        m_velocity.setY(0);
    }
    if(m_position.getX() == 0 && m_position.getY() == 410)
    {
        m_velocity.setX(0);
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

