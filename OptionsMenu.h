#ifndef _H_OPTIONSMENU_
#define _H_OPTIONSMENU_

#include <iostream>
#include <memory>
#include "GameStateFunctions.h"
#include "Text.h"
#include "Button.h"
#include "ImageSpriteManager.h"

class OptionsMenu : public GameStateFunctions
{
private:
	std::unique_ptr<Text> headerText;
	std::unique_ptr<Button> exitButton;
	std::unique_ptr<ImageSpriteManager> imgSpriteManager;
	void Begin();
	void Loop();
	void End();
	void Initialization();
	void Background();
	void OptionsMenuLoop();
	void GUI();
	void Destroy();
public:
	OptionsMenu();
	~OptionsMenu();
};

#endif