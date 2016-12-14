#pragma once
#include "Node.h"
#include <iostream>

class AStarSearch
{
public:
	AStarSearch();
	AStarSearch(short x, short y, short size);
	std::vector<std::pair<short, short>> Search(short xStart, short yStart, short xFinish, short yFinish, std::vector<std::pair<short, short>> walls);
	std::vector<Node*> getNeighbours(Node* n);
private:
	std::vector<Node*> openList;
	std::vector<Node*> closedList;
	std::vector<Node*> neighbours;
	short worldSize = 30;
	std::vector<std::pair<short, short>> createPath(Node* n);
	std::vector<Node*> removeNode(std::vector<Node*> list, Node* n);
	Node* findInList(std::vector<Node*> list, Node* find);
	std::vector<std::pair<short, short>> walls;
	bool checkForWalls(short x, short y);
	void cleanUp();

	void clearVector(std::vector<Node*> & v);
};

