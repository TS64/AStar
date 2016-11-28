#include "stdafx.h"
#include "Worker.h"

Worker::Worker()
{

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