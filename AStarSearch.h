#pragma once
#include "Node.h"
#include <iostream>

class AStarSearch
{
public:
	AStarSearch(int x, int y);
	std::vector<Node*> Search(int xStart, int yStart, int xFinish, int yFinish);
	std::vector<Node*> getNeighbours(Node* n);
private:
	std::vector<Node*> neighbours;
	int worldSize = 49;
	Node* goal;
	std::vector<Node*> createPath(Node* n);
	std::vector<Node*> removeNode(std::vector<Node*> list, Node* n);
	Node* findInList(std::vector<Node*> list, Node* find);
};

