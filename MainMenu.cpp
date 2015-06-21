#include <string>
#include <iostream>
#include <vector>
#include "MainMenu.h"
#include "template.h"
#include "GameStateStack.h"
#include "Button.h"
#include "Text.h"
#include "AGK_Delete.h"
#include "ImageSpriteManager.h"

MainMenu::MainMenu()
{
	MainMenu::Begin();
}

MainMenu::~MainMenu()
{
	MainMenu::Destroy();
}

void MainMenu::Begin()
{
	MainMenu::Initialization();
	MainMenu::Background();
	MainMenu::GUI();
}

void MainMenu::Loop()
{
	MainMenu::MainMenuLoop();
}

void MainMenu::End()
{
}

void MainMenu::Initialization()
{
}

void MainMenu::Background()
{
	imgSpriteManager = std::make_unique<ImageSpriteManager>("Sprite", 1, "media\\background.jpg", 0, 0, 1024, 768);
}

void MainMenu::MainMenuLoop()
{
	if (optionsButton->IsButtonExist(1))
	{

		if (optionsButton->IsButtonPressed(1)){}
		if (optionsButton->IsButtonReleased(1))
		{
			MainMenu::Destroy();
			state.PushGameState("OptionsMenu");
		}
	}

	if (startGameButton->IsButtonExist(2))
	{
		if (startGameButton->IsButtonPressed(2)){}
		if (startGameButton->IsButtonReleased(2))
		{
			MainMenu::Destroy();
			state.PushGameState("GameLevel");
		}
	}
}

void MainMenu::GUI()
{
	headerText = std::make_unique<Text>(1, "MainMenu", 100, 255, 0, 0, 100, 250, 50, agk::LoadImage("media\\output.png"));
	optionsButton = std::make_unique<Button>(agk::LoadImage("media\\optionsButtonA.png"), agk::LoadImage("media\\optionsButtonB.png"), 1, 512, 400, 100, 75);
	startGameButton = std::make_unique<Button>(agk::LoadImage("media\\startButtonA.png"), agk::LoadImage("media\\startButtonB.png"), 2, 512, 300, 100, 75);
}

void MainMenu::Destroy()
{
	std::unique_ptr<AGK_Delete> agk_del;

	agk_del = std::make_unique<AGK_Delete>(1, "SPRITE");
	agk_del = std::make_unique<AGK_Delete>(1, "TEXT");
	agk_del = std::make_unique<AGK_Delete>(1, 2, 3, 4, "BUTTON");
}
