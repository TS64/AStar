#pragma once
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>

class Node
{
public:
	Node(short x, short y);
	~Node();
	short xPos;
	short yPos;
	float g;	// START TO NODE
	float h;	// NODE TO GOAL
	float f;	// F = G + H

	bool closed;
	bool open;
	void setParent(Node* p);
	Node* getParent();
	float calculateFunc(short xStart, short yStart, short xFinish, short yFinish);
	float calculateG(short xStart, short yStart);
	float calculateH(short xFinish, short yFinish);
private:
	Node* parent;
	Node* child;
};