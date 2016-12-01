#pragma once
#include <list>
#include <vector>

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
	int getX();
	int getY();
	int getFunc();
	int func;
private:

};