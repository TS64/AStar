#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "World.h"
#include "AStarSearch.h"
#include <math.h>
#include <iostream>

class Worker
{
public:
	Worker(short x, short y);
	short xPosition;
	short yPosition;
	short getXPosition();
	short getYPosition();
	void setTarget(short x, short y);
	void findPath(int xTarget, int yTarget);
	short targetXPosition;
	short targetYPosition;
private:
	
	AStarSearch* aStar;
	std::list<Node*> foundPath;
	std::list<std::pair<int, int>> myPath;
};