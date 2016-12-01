#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "World.h"
#include <math.h>
#include <iostream>

class Worker
{
public:
	Worker();
	short xPosition;
	short yPosition;
	short getXPosition();
	short getYPosition();
	void setTarget(short x, short y);
private:
	short targetXPosition;
	short targetYPosition;
	void calculateDistance(short xTarget, short yTarget);
	void calculateHeuristic();
};