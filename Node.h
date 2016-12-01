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
	int calculateFunc(int xStart, int yStart, int xFinish, int yFinish);
	int getFunc();
	void setCost(int c);
	void setG(int xStart, int yStart, int xFinish, int yFinish);
	int getG();
	void setH(int xStart);
	int cost;
private:
	Node* parent;
	Node* child;

	int func;
	int g;
	int h;
};