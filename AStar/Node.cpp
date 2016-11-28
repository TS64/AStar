#include "stdafx.h"
#include "Node.h"

Node::Node(int x, int y)
{
	position.first = x;
	position.second = y;
}

void Node::setPosition(int x, int y)
{
	position.first = x;
	position.second = y;
}

pair<int, int> Node::getPosition()
{
	return position;
}

pair<int, int> Node::getParent()
{
	return parent;
}

void Node::setParent(pair<int, int> p)
{
	parent = p;
}

bool Node::hasParent()
{
	return (parent.first != NULL && parent.second != NULL);
}