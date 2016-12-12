#include "Worker.h"

Worker::Worker(short x, short y)
{
	xPosition = x;
	yPosition = y;
	aStar = new AStarSearch(targetXPosition, targetYPosition);
}

void Worker::setTarget(short x, short y)
{
	targetXPosition = x;
	targetYPosition = y;
}

short Worker::getXPosition()
{
	return xPosition;
}

short Worker::getYPosition()
{
	return yPosition;
}

void Worker::findPath(int xTarget, int yTarget)
{
	foundPath = aStar->Search(xPosition, yPosition, xTarget, yTarget);
	while (!foundPath.empty())
	{
		int x = foundPath.back()->xPos;
		int y = foundPath.back()->yPos;
		foundPath.pop_back();
		std::pair<int, int> nextTile;
		nextTile.first = x;
		nextTile.second = y;
		myPath.push_back(nextTile);
	}
	int x = 1;
}