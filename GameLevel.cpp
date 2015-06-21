#include <iostream>
#include "GameLevel.h"
#include "template.h"
#include "GameStateStack.h"
#include "TilesManager.h"

GameLevel::GameLevel()
{
	GameLevel::Begin();
}

GameLevel::~GameLevel() 
{
	GameLevel::Destory();
}

void GameLevel::Begin()
{
	tile_ = std::make_unique<TilesManager>(14, 100, 0, 0, 2, 0, 0);
}

void GameLevel::Loop()
{

}

void GameLevel::End()
{

}
void GameLevel::Destory()
{

}
