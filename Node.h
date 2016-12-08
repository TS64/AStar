#pragma once
#include <list>
#include <vector>
#include <queue>
#include <math.h>

class Node
{
public:
	Node(int x, int y);
	int xPos;
	int yPos;
	float g;	// START TO NODE
	float h;	// NODE TO GOAL
	float f;	// F = G + H

	bool closed;
	bool open;
	void setParent(Node* p);
	Node* getParent();
	void setChild(Node* p);
	Node* getChild();
	float calculateFunc(int xStart, int yStart, int xFinish, int yFinish);
	float calculateG(int xStart, int yStart);
	float calculateH(int xFinish, int yFinish);
	
private:
	Node* parent;
	Node* child;
};