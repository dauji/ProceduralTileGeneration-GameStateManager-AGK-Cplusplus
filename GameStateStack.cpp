#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include "GameStateStack.h"
#include "template.h"

GameStateStack state;

GameStateStack::GameStateStack()
{
	gameStatesCount = 0;
}

void GameStateStack::PushGameState(std::string gameStateName)
{
	std::unique_ptr<node> newTopState(new node);
	newTopState->gameState = gameStateName;

	newTopState->nextGameState = std::move(topState);
	topState = std::move(newTopState);

	gameStatesCount++;
}

void GameStateStack::PopGameState()
{
	if (!topState)
		std::cout << "Error: no gamestates available to pop";
	else
	{
		topState = std::move(topState->nextGameState);
		gameStatesCount--;
	}
}

std::string GameStateStack::CurrentGameState()
{
	if (topState)
		return topState->gameState;
	return "error: nothing on stack"; 
}

int GameStateStack::GetStateCount()
{
	return gameStatesCount;
}

void GameStateStack::Destory()
{
	topState.reset();
}