#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "AStarSearch.h"
#include <math.h>
#include <iostream>

class Worker
{
public:
	Worker(short x, short y, short size, std::vector<std::pair<short, short>> walls);
	short xPosition;
	short yPosition;
	short getXPosition();
	short getYPosition();
	void setTarget(short x, short y);
	void findPath(short xTarget, short yTarget);
	std::vector<std::pair<short, short>> getPath();
	void Update();
	short targetXPosition;
	short targetYPosition;
private:
	AStarSearch aStar;
	std::vector<Node*> foundPath;
	std::vector<std::pair<short, short>> myPath;
	std::vector<std::pair<short, short>> walls;
};