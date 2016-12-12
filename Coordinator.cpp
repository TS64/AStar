#include "Coordinator.h"

Coordinator::Coordinator()
{
	for (char i = 0; i < 5; i++)
	{
		Worker w = Worker(i + 10, i + 10);
		myWorkers.push_back(w);
	}
}

void Coordinator::SetTarget(int xTarget, int yTarget)
{
	for each (Worker w in myWorkers)
	{
		w.setTarget(xTarget, yTarget);
	}
}

int Coordinator::RunCoorinator()
{
	for each (Worker w in myWorkers)
	{
		w.findPath(7, 7);
	}
	return 1;
}
