#ifndef _H_GAMELEVEL_
#define _H_GAMELEVEL_

#include "GameStateFunctions.h"
#include <memory>
#include <iostream>
#include "TilesManager.h"

class GameLevel : public GameStateFunctions
{
private:
	std::unique_ptr<TilesManager> tile_;
	void Begin();
	void Loop();
	void End();
	void GameLevelLoop();
	void Destory();
public:
	GameLevel();
	~GameLevel();
};

#endif