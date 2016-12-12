#pragma once
#include "Node.h"
#include <iostream>

class AStarSearch
{
public:
	AStarSearch(int x, int y);
	std::list<Node*> Search(int xStart, int yStart, int xFinish, int yFinish);
	std::list<Node*> getNeighbours(Node* n);
private:
	std::list<Node*> neighbours;
	int worldSize = 49;
	Node* goal;
	std::list<Node*> AStarSearch::createPath(Node* n);
	Node* AStarSearch::findInList(std::list<Node*> list, Node* find);
};

