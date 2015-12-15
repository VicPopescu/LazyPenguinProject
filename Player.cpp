#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}




void Player::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
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
    if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
        m_velocity.setX(-1);
    }
    //right button move object right
    if(TheInputHandler::Instance()->getMouseButtonState(RIGHT))
    {
        m_velocity.setX(1);
    }

    /* ----------------------------------- */


}



void Player::update(){

    //override currentRow
    m_currentRow = 1;

    //set up velocity
    m_velocity.setX(0);
    m_velocity.setY(0);



    handleInput(); // add our function

    //start: frame 1, continue 3 more frames:
    m_currentFrame = int(((SDL_GetTicks() / 100) % 3));

    //update
    SDLGameObject::update();
}



void Player::clean(){}






