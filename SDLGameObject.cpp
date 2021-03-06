#include "SDLGameObject.h"
#include "Game.h"



SDLGameObject::SDLGameObject(const LoaderParams* pParams) :
GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_acceleration(0,0)

{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureID();

    m_currentRow = 1;
    m_currentFrame = 1;
}



void SDLGameObject::draw(){

    TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}



void SDLGameObject::update(){

    //adding velocity to initial position
    m_position += m_velocity;
    //adding acceleration
    //m_velocity += m_acceleration;

}

void SDLGameObject::clean(){}





//for collision handling in PlayState


