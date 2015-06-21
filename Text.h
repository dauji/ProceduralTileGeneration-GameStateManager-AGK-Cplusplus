#ifndef _H_TEXTS_
#define _H_TEXTS_

#include <iostream>
#include <string>

class Text
{
private:
	int ID_;
	std::string text_;
	int size_;
	int red_;
	int green_;
	int blue_;
	int alpha_;
	int x_;
	int y_;
	int font_;
	void Destory();
	void AddText(int ID, std::string text, int size, int red, int green, int blue, int alpha, int X, int Y, int font);
public:
	Text(int ID, std::string text, int size, int red, int green, int blue, int alpha, int X, int Y, int font);
	~Text();
};

#endif


