#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "RandomSeedManager.h"

RandomSeedManager::RandomSeedManager()
{
}

RandomSeedManager::~RandomSeedManager()
{

}

std::vector<int> RandomSeedManager::RandomSeed(std::vector<int> values)
{
	srand(time(0));
	for (int i = 0; i <= 20; i++)
	{
		values.insert(values.begin() + i, (1 + (rand() % 20)));
	}
	return values;
}