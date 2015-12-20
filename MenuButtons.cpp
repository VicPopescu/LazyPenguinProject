#include "MenuButtons.h"

MenuButtons::MenuButtons(const LoaderParams* pParams, void (*callback)()) : SDLGameObject(pParams), m_callback(callback)
{
    m_currentFrame = MOUSE_OUT; //start with first frame
}


void MenuButtons::draw()
{
    SDLGameObject::draw(); //use the base class drawing function
}




void MenuButtons::update()
{
    Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

    if(pMousePos->getX() < (m_position.getX() + m_width)
       && pMousePos->getX() > m_position.getX()
       && pMousePos->getY() < (m_position.getY() + m_height)
       && pMousePos->getY() > m_position.getY())
    {

        if(TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
        {
            m_currentFrame = MOUSE_OVER;

            m_callback(); //call our callback function

            m_bReleased = false;
        }
        else if(!TheInputHandler::Instance()->getMouseButtonState(LEFT))
                {
                    m_bReleased = true;
                    m_currentFrame = CLICKED;
                }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
    }
}



void MenuButtons::clean()
{
    SDLGameObject::clean();
}






