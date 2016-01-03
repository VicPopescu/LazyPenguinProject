#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include "PauseState.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";


bool PlayState::onEnter()
{
    //loading player sprite
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha2.png", "penguin_player", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

    //loading enemy sprite
    if(!TheTextureManager::Instance()->load("Resources/baby_penguin_alpha3.png", "enemy_player", TheGame::Instance()->getRenderer()))
    {
        return false;
    }


    //creating objects from sprites
    GameObject* player = new Player(new LoaderParams(200, 200, 64, 64, "penguin_player"));
    GameObject* enemy  = new Enemy(new LoaderParams(500, 100, 64, 64, "enemy_player"));

    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);


    std::cout << "Entering PlayState \n";
    return true;
}




bool PlayState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();
    TheTextureManager::Instance()->clearFromTextureMap("penguin_player");

    std::cout << "Exiting PlayState \n";
    return true;
}





void PlayState::update()
{
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheGame::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }

    //handling collision
    if(checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
    {
        TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
    }



}






void PlayState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}





//collision handling
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    //Calculate the sides of rect B
    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    //If any of the sides from A are outside of B
    if( bottomA <= topB ){return false;}
    if( topA >= bottomB ){return false; }
    if( rightA <= leftB ){return false; }
    if( leftA >= rightB ){return false;}

    return true;
}

