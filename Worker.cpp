#include "Worker.h"

Worker::Worker(short x, short y, short size, std::vector<std::pair<short, short>> w)
{
	xPosition = x;
	yPosition = y;
	aStar = AStarSearch(targetXPosition, targetYPosition, size);
	walls = w;
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

void Worker::findPath(short xTarget, short yTarget)
{
	foundPath = aStar.Search(xPosition, yPosition, xTarget, yTarget, walls);
	printf("Path found");
	while (!foundPath.empty())
	{
		short x = foundPath.back()->xPos;
		short y = foundPath.back()->yPos;
		foundPath.pop_back();
		std::pair<short, short> nextTile;
		nextTile.first = x;
		nextTile.second = y;
		myPath.push_back(nextTile);
	}
}

std::vector<std::pair<short, short>> Worker::getPath()
{
	return myPath;
}