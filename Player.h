#ifndef _H_PLAYER_
#define _H_PLAYER_

#include "GameStateFunctions.h"

class Player : public GameStateFunctions
{
private:
	void Begin();
	void Loop();
	void End();
public:
	Player();
	~Player();
};

#endif