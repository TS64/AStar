#pragma once
#include "Worker.h"
#include <vector>
#include <list>

class Coordinator
{
public:
	Coordinator();
	std::vector<Worker> myWorkers;
	void SetTarget(int xTarget, int yTarget);
	int RunCoorinator();
private:

};