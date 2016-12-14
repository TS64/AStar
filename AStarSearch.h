#pragma once
#include "Node.h"
#include <iostream>

class AStarSearch
{
public:
	AStarSearch();
	AStarSearch(short x, short y, short size);
	std::vector<Node*> Search(short xStart, short yStart, short xFinish, short yFinish, std::vector<std::pair<short, short>> walls);
	std::vector<Node*> getNeighbours(Node* n);
private:
	std::vector<Node*> neighbours;
	short worldSize = 30;
	Node* goal;
	std::vector<Node*> createPath(Node* n);
	std::vector<Node*> removeNode(std::vector<Node*> list, Node* n);
	Node* findInList(std::vector<Node*> list, Node* find);
	std::vector<std::pair<short, short>> walls;
	bool checkForWalls(short x, short y);
};

