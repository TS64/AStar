#include "AStarSearch.h"


AStarSearch::AStarSearch(int xGoal, int yGoal)
{
	goal = new Node(xGoal, yGoal);
}

std::list<Node*> AStarSearch::getNeighbours(Node* n)
{
	std::list<Node*> neighbours;
	if (n->xPos != 0)
	{
		Node* leftNeighbour = new Node(n->xPos - 1, n->yPos);
		leftNeighbour->g = n->g + 1;
		leftNeighbour->setParent(n);
		neighbours.push_back(leftNeighbour);
	}
	if (n->xPos != worldSize)
	{
		Node* rightNeighbour = new Node(n->xPos + 1, n->yPos);
		rightNeighbour->g = n->g + 1;
		rightNeighbour->setParent(n);
		neighbours.push_back(rightNeighbour);
	}
	if (n->yPos != 0)
	{
		Node* aboveNeighbour = new Node(n->xPos, n->yPos - 1);
		aboveNeighbour->g = n->g + 1;
		aboveNeighbour->setParent(n);
		neighbours.push_back(aboveNeighbour);
	}
	if (n->yPos != worldSize)
	{
		Node* belowNeighbour = new Node(n->xPos, n->yPos + 1);
		belowNeighbour->g = n->g + 1;
		belowNeighbour->setParent(n);
		neighbours.push_back(belowNeighbour);
	}
	return neighbours;
}

Node* getLowestF(std::list<Node*> nodes, int xStart, int yStart, int xFinish, int yFinish)
{
	int lowestF = 100000;
	Node* q = nullptr;
	for each (Node* n in nodes)
	{
		if (n->calculateFunc(xStart, yStart, xFinish, yFinish) < lowestF)
		{
			lowestF = n->f;
			q = n;
		}
	}
	return q;
}

float distanceBetweenNodes(Node* n, Node* q)
{
	return abs(sqrt(((n->xPos - q->yPos) * (n->xPos - q->yPos)) + ((n->yPos - q->yPos) * (n->yPos - q->yPos))));
}

std::list<Node*> AStarSearch::Search(int xStart, int yStart, int xFinish, int yFinish)
{
	Node* start = new Node(xStart, yStart);
	start->f = 0;
	Node* finish = new Node(xFinish, yFinish);
	std::list<Node*> openList;
	std::list<Node*> closedList;

	openList.push_back(start);

	while (!openList.empty())
	{
		Node* current = getLowestF(openList, xStart, yStart, xFinish, yFinish);
		std::cout << current->xPos << " - " << current->yPos << std::endl;
		if (current == finish)
		{
			return createPath(current);
		}
		openList.pop_back();
		closedList.push_back(current);
		for each (Node* neighbour in getNeighbours(current))
		{
			//if (/*neighbour not in closedList*/)
			if (findInList(closedList, neighbour) == nullptr)
			{
				neighbour->f = neighbour->calculateG(xStart, yStart) + distanceBetweenNodes(neighbour, finish);
				//if (/*neighbour is not in openList*/)
				if (findInList(openList, neighbour) == nullptr)
				{
					openList.push_back(neighbour);
				}
				else
				{
					Node* openNeighbour = findInList(openList, neighbour);
					if (neighbour->g < openNeighbour->g)
					{
						openNeighbour->g = neighbour->g;
						openNeighbour->setParent(neighbour->getParent());
					}
				}
			}
		}
	}
	std::list<Node*> fail;
	return fail;
}

Node* AStarSearch::findInList(std::list<Node*> list, Node* find)
{
	for each (Node* var in list)
	{
		if (var->xPos == find->xPos && var->yPos == find->yPos)
		{
			return var;
		}
	}
	return nullptr;
}

std::list<Node*> AStarSearch::createPath(Node* n)
{
	std::list<Node*> path;
	path.push_back(n);
	while (n->getParent() != nullptr)
	{
		n = n->getParent();
		path.push_back(n);
	}
	return path;
}