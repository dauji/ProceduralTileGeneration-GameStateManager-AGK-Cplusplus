#include <iostream>
#include "Button.h"
#include "template.h"

Button::Button(int imageUp, int imageDown, int ID, int X, int Y, int size, int alpha)
{
	imgUp_ = imageUp;
	imgDown_ = imageDown;
	ID_ = ID;
	x_ = X;
	y_ = Y;
	size_ = size;
	alpha_ = alpha;

	Button::AddButton(imgUp_, imgDown_, ID_, x_, y_, size_, alpha_);
}

Button::~Button() 
{
}

void Button::AddButton(int imageUp, int imageDown, int ID, int X, int Y, int size, int alpha)
{
	agk::AddVirtualButton(ID, X, Y, size);
	agk::SetVirtualButtonAlpha(ID, alpha);
	agk::SetVirtualButtonImageUp(ID, imageUp);
	agk::SetVirtualButtonImageDown(ID, imageDown);
}

bool Button::IsButtonPressed(int ID)
{
	if (agk::GetVirtualButtonPressed(ID)){ return true; }
	else	{ return false; }
}

bool Button::IsButtonReleased(int ID)
{
	if (agk::GetVirtualButtonReleased(ID)){ return true; }
	else	{ return false; }
}

bool Button::IsButtonExist(int ID)
{
	if (agk::GetVirtualButtonExists(ID)) { return true; }
	else { return false; }
}

void Button::Destory()	
{
	agk::DeleteVirtualButton(ID_);
}