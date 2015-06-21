#ifndef ISCENE
#define ISCENE

class GameStateFunctions
{
public:
	GameStateFunctions() {};
	virtual ~GameStateFunctions() {};
	virtual void Begin() = 0;
	virtual void Loop() = 0;
	virtual void End() = 0;
};

#endif 