#pragma once
#include <list>
#include <vector>
#include <queue>
#include <math.h>

class Node
{
public:
	Node(int x, int y);
	int xPosition;
	int yPosition;

	bool closed;
	bool open;
	void setParent(Node* p);
	Node* getParent();
	void setChild(Node* p);
	Node* getChild();
	int getX();
	int getY();
	int calculateCost(int xStart, int yStart, int xFinish, int yFinish);
	int getCost();
	void setCost(int c);
	int cost;
private:
	Node* parent;
	Node* child;
};