#include "Node.h"

Node::Node(int x, int y)
{
	xPosition = x;
	yPosition = y;
	cost = 0;
}

int Node::calculateFunc(int xStart, int yStart, int xFinish, int yFinish)
{
	int cost = abs(sqrt(((xFinish - xStart) * (xFinish - xStart)) + ((yFinish - yStart) * (yFinish - yStart))));
	return cost;
}

int Node::getFunc()
{
	return func;
}

void Node::setCost(int f)
{
	func = f;
}

void Node::setParent(Node* p)
{
	parent = p;
}

Node* Node::getParent()
{
	return parent;
}

void Node::setChild(Node* c)
{
	child = c;
}

Node* Node::getChild()
{
	return child;
}

int Node::getX()
{
	return xPosition;
}

int Node::getY()
{
	return yPosition;
}