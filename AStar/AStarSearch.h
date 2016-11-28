#pragma once
#include "Node.h"
#include <vector>

using namespace std;

class AStarSearch
{
public:
	AStarSearch();
	vector<Node*> Search(int xStart, int yStart, int xFinish, int yFinish);
private:

};

