#include <string>
#include "template.h"
#include "MainMenu.h"
#include "GameStateStack.h"
#include "OptionsMenu.h"
#include "GameStateFunctions.h"
#include "GameLevel.h"
#include "RandomSeedManager.h"

using namespace AGK;

app App;
GameStateFunctions * currentState;
RandomSeedManager seed;

void app::Begin(void)
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);

	agk::SetVirtualResolution(1024, 768);
	agk::SetClearColor(151, 170, 204); 
	agk::SetSyncRate(60, 0);
	agk::SetScissor(0, 0, 0, 0);

	if (state.GetStateCount() == 0){ state.PushGameState("MainMenu"); }
}

void app::Loop(void)
{
	agk::Print(agk::ScreenFPS());
	agk::Sync();

	std::string CURRENT_STATE = state.CurrentGameState();

	switch (app::TypeConversion(CURRENT_STATE))
	{
	case app::CURRENTSTATE::mainmenu: 
		
		if (!mainMenuToLoopOnce)
		{
			currentState = new MainMenu();
			mainMenuToLoopOnce = true;
		}

		currentState->Loop();
		optionsMenuToLoopOnce = false;
		gameLevelToLoopOnce = false;
		
		break;
	case app::CURRENTSTATE::optionsmenu: 
		
		if (!optionsMenuToLoopOnce)
		{
			currentState = new OptionsMenu();
			optionsMenuToLoopOnce = true;
			mainMenuToLoopOnce = false;
		}
		currentState->Loop();
		
		break;
	case app::CURRENTSTATE::gamelevel: 
		
		if (!gameLevelToLoopOnce)
		{
			currentState = new GameLevel();	
			gameLevelToLoopOnce = true;
			mainMenuToLoopOnce = false;
		}		
		currentState->Loop();
		
		break;
	}
}

void app::End(void)
{
	currentState->End();
	delete currentState;
}

app::CURRENTSTATE app::TypeConversion(std::string state)
{
	if (state == "MainMenu") return mainmenu;
	if (state == "OptionsMenu") return optionsmenu;
	if (state == "GameLevel") return gamelevel;
}
