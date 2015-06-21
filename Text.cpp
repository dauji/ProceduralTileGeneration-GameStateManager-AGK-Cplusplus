#include <iostream>
#include "Text.h"
#include "template.h"

Text::Text(int ID, std::string text, int size, int red, int green, int blue, int alpha, int X, int Y, int font)
{
	ID_ = ID;
	text_ = text;
	size_ = size;
	red_ = red;
	green_ = green;
	blue_ = blue;
	alpha_ = alpha;
	x_ = X;
	y_ = Y;
	font_ = font;

	Text::AddText(ID_, text_, size_, red_, green_, blue_, alpha_, x_, y_, font_);
}

Text::~Text() 
{
}

void Text::AddText(int ID, std::string text, int size, int red, int green, int blue, int alpha, int X, int Y, int font)
{
	const char * text__ = text.c_str();
	agk::CreateText(ID, text__);
	agk::SetTextSize(ID, size);
	agk::SetTextColor(ID, red, green, blue);
	agk::SetTextPosition(ID, X, Y);
	agk::SetTextFontImage(ID, font);
}

void Text::Destory()	
{
	agk::DeleteText(ID_);
}