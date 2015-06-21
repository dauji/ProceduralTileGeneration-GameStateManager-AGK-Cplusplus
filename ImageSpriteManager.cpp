#include <iostream>
#include "ImageSpriteManager.h"
#include "template.h"

ImageSpriteManager::ImageSpriteManager(std::string type, int ID, std::string path, int X_pos, int Y_pos, int X_size, int Y_size)
{
	type_ = type;
	ID_ = ID;
	path_ = path;
	x_pos_ = X_pos;
	y_pos_ = Y_pos;
	x_size_ = X_size;
	y_size_ = Y_size;

	switch (ImageSpriteManager::TypeConversion(type_))
	{
	case ImageSpriteManager::OBJTYPE::image: ImageSpriteManager::CreateImage(ID_, path_);  break;
	case ImageSpriteManager::OBJTYPE::sprite: ImageSpriteManager::CreateSprite(ID_, path_, x_pos_, y_pos_, x_size_, y_size_); break;
	}
}

ImageSpriteManager::~ImageSpriteManager()
{

}

// -- Create/Import Standalone Images (e.g. Tiles Textures, etc.)
void ImageSpriteManager::CreateImage(int ID, std::string path)
{
	const char * path__ = path.c_str();
	agk::LoadImage(ID, path__);
}

// -- Create Sprites (e.g. Background, etc.)
void ImageSpriteManager::CreateSprite(int ID, std::string path, int X_pos, int Y_pos, int X_size, int Y_size)
{
	const char * path__ = path.c_str();
	agk::CreateSprite(ID, agk::LoadImage(path__));
	agk::SetSpritePosition(ID, X_pos, Y_pos);
	agk::SetSpriteSize(ID, X_size, Y_size);
}

ImageSpriteManager::OBJTYPE ImageSpriteManager::TypeConversion(std::string type)
{
	if (type == "Image") return image;
	if (type == "Sprite") return sprite;
}