#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

class Node
{
public:
	Node(int x, int y);
	pair<int, int> position;
	pair<int, int> parent;

	bool opened;
	bool closed;

	void setPosition(int x, int y);
	pair<int, int> getPosition();
	pair<int, int> getParent();
	void setParent(pair<int, int> p);
	bool hasParent();
private:
	


};