#ifndef _H_RANDOMSEED_
#define _H_RANDOMSEED_

#include <iostream>
#include <vector>

class RandomSeedManager
{
private:
	
public:
	std::vector<int> RandomSeed(std::vector<int> values);
	RandomSeedManager();
	~RandomSeedManager();
};

#endif