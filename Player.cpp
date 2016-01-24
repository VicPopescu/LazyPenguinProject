#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}




void Player::draw()
{
    //override SDLGameObject draw function so we can flip the image corresponding to X incrementation
    //if the player is moving
    if(m_velocity.getX() != 0 || m_velocity.getY() != 0)
    {

        //if the player is moving to the left, flip the image
        if(m_velocity.getX() < 0 && m_velocity.getY() == 0)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow + 1, m_currentFrame, TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
        }
        //if the player is moving to the right, use the normal "right facing" sprite row
        else if(m_velocity.getX() > 0 && m_velocity.getY() == 0)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow + 1, m_currentFrame, TheGame::Instance()->getRenderer());
        }

        //if the player is moving up
        if(m_velocity.getY() < 0)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame + 3, TheGame::Instance()->getRenderer());
        }
        else if(m_velocity.getY() > 0)
        {
            TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
       }


    }
    //if the player is not moving, use the first sprite row images, so he will face us now
    else
    {
        TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
    }
}




void Player::update(){

    //set up velocity
    m_velocity.setX(0);
    m_velocity.setY(0);




    //override currentRow
    //m_currentRow = 1;

    handleInput(); // add our function

    //start: frame 1, continue 3 more frames:
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));

    //update
    SDLGameObject::update();
}








void Player::handleInput()
{
    /* ----------------------------------- */

    /* CONTROLLER (need fix)*/
    if(TheInputHandler::Instance()->joysticksInitialised())
    {
        /* CONTROLLER STICK*/
        if(TheInputHandler::Instance()->xvalue(0, 1) > 0 || TheInputHandler::Instance()->xvalue(0, 1) < 0)
        {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,1));
        }
        if(TheInputHandler::Instance()->yvalue(0, 1) > 0 || TheInputHandler::Instance()->yvalue(0, 1) < 0)
        {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,1));
        }
        if(TheInputHandler::Instance()->xvalue(0, 2) > 0 || TheInputHandler::Instance()->xvalue(0, 2) < 0)
        {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,2));
        }
        if(TheInputHandler::Instance()->yvalue(0, 2) > 0 || TheInputHandler::Instance()->yvalue(0, 2) < 0)
        {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,2));
        }

        /* CONTROLLER BUTTONS */
        //testing button input, not working either tho...
        if(TheInputHandler::Instance()->getButtonState(0, 1))
        {
            m_velocity.setX(1);

        }
    }

    /* ----------------------------------- */

    /* MOUSE BUTTON EVENTS */
    //left button move object left
/*    if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
        m_velocity.setX(-1);
    }
    //right button move object right
    if(TheInputHandler::Instance()->getMouseButtonState(RIGHT))
    {
        m_velocity.setX(1);
    }
*/
    /* ----------------------------------- */


    /* KEYBOARD */

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(2);
    }

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-2);
    }

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-2);
    }

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(2);
    }


}




void Player::clean(){}






