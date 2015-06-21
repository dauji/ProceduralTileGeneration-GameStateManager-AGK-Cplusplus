#include "OptionsMenu.h"
#include "template.h"
#include "GameStateStack.h"
#include "Button.h"
#include "Text.h"
#include "AGK_Delete.h"

OptionsMenu::OptionsMenu()
{
	OptionsMenu::Begin();
}

OptionsMenu::~OptionsMenu()
{
	OptionsMenu::Destroy();
}

void OptionsMenu::Begin()
{
	OptionsMenu::Initialization();
	OptionsMenu::Background();
	OptionsMenu::GUI();
}

void OptionsMenu::Loop()
{
	OptionsMenu::OptionsMenuLoop();
}

void OptionsMenu::End(){}

void OptionsMenu::Initialization()
{
}

void OptionsMenu::Background()
{
	imgSpriteManager = std::make_unique<ImageSpriteManager>("Sprite", 1, "media\\background_optionsmenu.png", 0, 0, 1024, 768);
}

void OptionsMenu::OptionsMenuLoop()
{
	if (exitButton->IsButtonExist(1))
	{
		if (exitButton->IsButtonPressed(1))	{}
		if (exitButton->IsButtonReleased(1))
		{
			OptionsMenu::Destroy();
			state.PopGameState();
		}
	}
}

void OptionsMenu::GUI()
{
	headerText = std::make_unique<Text>(1, "OptionsMenu", 100, 255, 0, 0, 100, 250, 50, agk::LoadImage("media\\output.png"));
	exitButton = std::make_unique<Button>(agk::LoadImage("media\\exitButtonA.png"), agk::LoadImage("media\\exitButtonB.png"), 1, 512, 300, 100, 75);
}

void OptionsMenu::Destroy()
{
	std::unique_ptr<AGK_Delete> agk_del;
	agk_del = std::make_unique<AGK_Delete>(1, "SPRITE");
	agk_del = std::make_unique<AGK_Delete>(1, "TEXT");
	agk_del = std::make_unique<AGK_Delete>(1, "BUTTON");
}

