#ifndef _H_MAINMENU_
#define _H_MAINMENU_

#include <vector>
#include <iostream>
#include <memory>
#include "GameStateFunctions.h"
#include "Text.h"
#include "Button.h"
#include "ImageSpriteManager.h"

class MainMenu : public GameStateFunctions
{
private:
	std::unique_ptr<Text> headerText;
	std::unique_ptr<Button> optionsButton;
	std::unique_ptr<Button> startGameButton;
	std::unique_ptr<ImageSpriteManager> imgSpriteManager;
	void Begin();
	void Loop();
	void End();
	void Initialization();
	void Background();
	void MainMenuLoop();
	void GUI();
	void Destroy();
public:
	MainMenu();
	~MainMenu();
};

#endif