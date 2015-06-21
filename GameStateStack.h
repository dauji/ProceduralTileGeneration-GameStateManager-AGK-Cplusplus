#ifndef _H_GAMESTATE_
#define _H_GAMESTATE_

#include <iostream>
#include <memory>

class node
{
public:
	std::string gameState;
	std::unique_ptr<node> nextGameState;

	~node()
	{
	//	std::cout << " Element Deleting: " << gameState << "\n";
	}
};

class GameStateStack
{
private:
	std::unique_ptr<node> topState;
	int gameStatesCount;
	void Destory();

public:
	void PushGameState(std::string element);
	void PopGameState();
	std::string CurrentGameState();
	int GetStateCount();
	GameStateStack();
};

extern GameStateStack state;

#endif