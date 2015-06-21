#ifndef _H_BUTTON_
#define _H_BUTTON_

class Button
{
private:
	int imgUp_;
	int imgDown_;
	int ID_;
	int x_;
	int y_;
	int size_;
	int alpha_;
	void Destory();
	void AddButton(int imageUp, int imageDown, int ID, int X, int Y, int size, int alpha);
public:
	bool IsButtonPressed(int ID);
	bool IsButtonReleased(int ID);
	bool IsButtonExist(int ID);
	Button(int imageUp, int imageDown, int ID, int X, int Y, int size, int alpha);
	~Button();
};

#endif