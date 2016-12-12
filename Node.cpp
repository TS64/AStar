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
	float dx = abs(xPos - xStart);
	float dy = abs(yPos - yStart);
	float g = dx + dy;
	std::cout << "x1: " << xPos << "|y1: " << yPos << "|x2: " << xStart << "|y2: " << yStart << "|Distance between nodesG: " << g << std::endl;
	return g;
}

float Node::calculateH(int xFinish, int yFinish)
{
	float dx = abs(xPos - xFinish);
	float dy = abs(yPos - yFinish);
	float h = dx + dy;
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