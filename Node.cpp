#include "Node.h"

Node::Node(int x, int y)
{
	xPos = x;
	yPos = y;
	f = 0;
}

float Node::calculateFunc(int xStart, int yStart, int xFinish, int yFinish)
{
	f = calculateG(xStart, yStart) + calculateH(xFinish, yFinish);
	return calculateG(xStart, yStart) + calculateH(xFinish, yFinish);
}

float Node::calculateG(int xStart, int yStart)
{
	g = abs(sqrt(((xPos - xStart) * (xPos - xStart)) + ((yPos - yStart) * (yPos - yStart))));
	return g;
}

float Node::calculateH(int xFinish, int yFinish)
{
	h = abs(sqrt(((xPos - xFinish) * (xPos - xFinish)) + ((yPos - yFinish) * (yPos - yFinish))));
	return h;
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