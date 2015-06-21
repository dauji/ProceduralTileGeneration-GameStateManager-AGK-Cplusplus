#include <iostream>
#include <cstddef>
#include "template.h"
#include "TilesManager.h"
#include "AGK_Delete.h"
#include "RandomSeedManager.h"
#include "ImageSpriteManager.h"

TilesManager::TilesManager(int count, int size, int Y_increment, int X_increment, int Y_MAX, int Y_MAX_incrementor, int _Y_MAX_incrementor)
{
	count_ = count;
	size_ = size;
	Y_increment_ = Y_increment;
	X_increment_ = X_increment;
	Y_MAX_ = Y_MAX;
	Y_MAX_incrementor_ = Y_MAX_incrementor;
	_Y_MAX_incrementor_ = _Y_MAX_incrementor;

	TilesManager::Initialize();
	TilesManager::GenerateGrid(count_, size_, Y_increment_, X_increment_, Y_MAX_, Y_MAX_incrementor_, _Y_MAX_incrementor_);
	TilesManager::GenerateTiles(count_);
	TilesManager::ChangeTextures();
}

TilesManager::~TilesManager()
{
	TilesManager::Destory(count_);
}

void TilesManager::GenerateGrid(int count, int size, int Y_increment, int X_increment, int Y_MAX, int Y_MAX_incrementor, int _Y_MAX_incrementor)
{
	// Generate Grid
	for (int i = 0; i <= count; i++)
	{
		Y_GRID.insert(Y_GRID.begin() + i, (size + Y_increment));
		Y_increment = Y_increment + size;

		if (i == Y_MAX || i == Y_MAX + Y_MAX_incrementor)
		{
			Y_MAX_incrementor = Y_MAX_incrementor + Y_MAX;
			Y_increment = size;
		}
	}

	for (int j = 0; j <= count; j++)
	{
		X_GRID.insert(X_GRID.begin() + j, (size + X_increment));

		if (j == Y_MAX || j == Y_MAX + _Y_MAX_incrementor)
		{
			_Y_MAX_incrementor = _Y_MAX_incrementor + Y_MAX;
			X_increment = X_increment + size;
		}
	}
}

void TilesManager::Initialize()
{
	for (int i = 1; i <= 20; i++)
	{
		imgSpriteManager = std::make_unique<ImageSpriteManager>("Image", i, std::string("media\\Gametile_") + std::to_string(i) + std::string(".png"), NULL, NULL, NULL, NULL);
	}
}

void TilesManager::GenerateTiles(int count)
{
	for (int i = 1; i <= count; i++)
	{
		agk::CreateSprite(i, agk::LoadImage("media\\Gametile_1.png"));
		agk::SetSpriteSize(i, 100, 100);
		agk::SetSpritePosition(i, X_GRID[i], Y_GRID[i]);
	}
}

void TilesManager::ChangeTextures()
{
	tilesRND =  seed->RandomSeed(tilesRND);
	for (int i = 1; i <= count_; i++)
	{
		agk::SetSpriteImage(tilesRND[i], i);
	}
}

void TilesManager::Destory(int count) 
{
	std::unique_ptr<AGK_Delete> agk_del;
	for (int i = 1; i <= count; i++)
	{
		agk_del = std::make_unique<AGK_Delete>(i, "SPRITE");
	}
}