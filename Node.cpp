#include "Node.h"

Node::Node(int x, int y)
{
	xPosition = x;
	yPosition = y;
	func = 0;
}

int Node::getFunc()
{
	return func;
}