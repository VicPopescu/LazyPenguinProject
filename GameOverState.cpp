#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

//define static variable
const std::string GameOverState::s_gameOverID = "GAMEOVER";

//define static function
void GameOverState::s_gameOverToMain()
{

    TheGame::Instance()->getStateMachine()->changeState(new MenuState());

}

//define static function
void GameOverState::s_restartPlay()
{

    TheGame::Instance()->getStateMachine()->changeState(new PlayState());

}

