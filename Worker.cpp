#include "Worker.h"

Worker::Worker(short x, short y, short size, std::vector<std::pair<short, short>> w)
{
	xPosition = x;
	yPosition = y;
	aStar = AStarSearch(targetXPosition, targetYPosition, size);
	walls = w;
	foundTarget = false;
}

void Worker::setTarget(short x, short y)
{
	targetXPosition = x;
	targetYPosition = y;
	myPath.clear();
	foundPath.clear();
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
	//std::cout << "x: " << xTarget << " y: " << yTarget << std::endl;
	myPath = aStar.Search(xPosition, yPosition, xTarget, yTarget, walls);
	printf("Path-found ");
	foundTarget = true;
	/*while (!foundPath.empty())
	{
		short x = foundPath.back()->xPos;
		short y = foundPath.back()->yPos;
		foundPath.pop_back();
		std::pair<short, short> nextTile;
		nextTile.first = x;
		nextTile.second = y;
		myPath.push_back(nextTile);
	}*/
}

std::vector<std::pair<short, short>> Worker::getPath()
{
	return myPath;
}

void Worker::Update()
{
	if (myPath.size() > 0)
	{
		xPosition = myPath.at(0).first;
		yPosition = myPath.at(0).second;
		myPath.erase(myPath.begin(), myPath.begin() + 1);
	}
}
