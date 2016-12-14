#include "Node.h"

Node::Node(short x, short y)
{
	xPos = x;
	yPos = y;
	f = 0;
}

Node::~Node()
{
	//printf("deleted node\n");
}

float Node::calculateFunc(short xStart, short yStart, short xFinish, short yFinish)
{
	f = calculateG(xStart, yStart) + calculateH(xFinish, yFinish);
	return calculateG(xStart, yStart) + calculateH(xFinish, yFinish);
}

float Node::calculateG(short xStart, short yStart)
{
	float dx = abs(xPos - xStart);
	float dy = abs(yPos - yStart);
	float g = dx + dy;
	//std::cout << "x1: " << xPos << "|y1: " << yPos << "|x2: " << xStart << "|y2: " << yStart << "|Distance between nodesG: " << g << std::endl;
	return g;
}

float Node::calculateH(short xFinish, short yFinish)
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