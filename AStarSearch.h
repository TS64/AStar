#pragma once
#include "Node.h"

class AStarSearch
{
public:
	AStarSearch();
	std::list<Node*> Search(int xStart, int yStart, int xFinish, int yFinish);
	std::vector<Node*> getNeighbours(Node* n);
private:
	std::vector<Node*> neighbours;
	int worldSize = 49;
};

