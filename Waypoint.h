#pragma once
#include "SDL.h"

class Waypoint
{
public:
	Waypoint();	
	short getXWaypoint();
	short getYWaypoint();
private:
	short xPosition;
	short yPosition;
	void readWaypoints();
	void calculateHeuristic();
};
