#ifndef _H_TILES_
#define _H_TILES_

#include <vector>
#include <memory>
#include <iostream>
#include "RandomSeedManager.h"
#include "ImageSpriteManager.h"

class TilesManager
{
private:
	std::vector<int> X_GRID;
	std::vector<int> Y_GRID;
	std::vector<int> tilesRND;
	std::unique_ptr<RandomSeedManager> seed;
	std::unique_ptr<ImageSpriteManager> imgSpriteManager;
	int count_;
	int size_;
	int Y_increment_;
	int X_increment_;
	int Y_MAX_;
	int Y_MAX_incrementor_;
	int _Y_MAX_incrementor_;
	void GenerateGrid(int count, int size, int Y_increment, int X_increment, int Y_MAX, int Y_MAX_incrementor, int _Y_MAX_incrementor);
	void GenerateTiles(int count);
	void ChangeTextures();
	void Initialize();
	void Destory(int count);
public:
	TilesManager(int count, int size, int Y_increment, int X_increment, int Y_MAX, int Y_MAX_incrementor, int _Y_MAX_incrementor);
	~TilesManager();
};

#endif