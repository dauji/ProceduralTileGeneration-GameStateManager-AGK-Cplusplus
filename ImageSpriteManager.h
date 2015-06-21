#ifndef _H_IMAGESPRITEMANAGER_
#define _H_IMAGESPRITEMANAGER_

#include <iostream>
#include <string>

class ImageSpriteManager
{
private:
	std::string type_;
	int ID_;
	std::string path_;
	int x_pos_;
	int y_pos_;
	int x_size_;
	int y_size_;
	void CreateImage(int ID, std::string path);
	void CreateSprite(int ID, std::string path, int X_pos, int Y_pos, int X_size, int Y_size);
	enum OBJTYPE {image, sprite};
	OBJTYPE TypeConversion(std::string type);
public:
	ImageSpriteManager(std::string type, int ID, std::string path, int X_pos, int Y_pos, int X_size, int Y_size);
	~ImageSpriteManager();
};

#endif