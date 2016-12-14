#include "AStarSearch.h"

AStarSearch::AStarSearch()
{

}

AStarSearch::AStarSearch(short xGoal, short yGoal, short size)
{
	goal = new Node(xGoal, yGoal);
	worldSize = size;
}

std::vector<Node*> AStarSearch::getNeighbours(Node* n)
{
	std::vector<Node*> neighbours;
	neighbours.clear();
	if (n->xPos != 0)
	{
		if (!checkForWalls(n->xPos - 1, n->yPos))
		{
			Node* leftNeighbour = new Node(n->xPos - 1, n->yPos);
			leftNeighbour->g = n->g + 1;
			leftNeighbour->setParent(n);
			neighbours.push_back(leftNeighbour);
		}
	}
	if (n->xPos != worldSize)
	{
		if (!checkForWalls(n->xPos + 1, n->yPos))
		{
			Node* rightNeighbour = new Node(n->xPos + 1, n->yPos);
			rightNeighbour->g = n->g + 1;
			rightNeighbour->setParent(n);
			neighbours.push_back(rightNeighbour);
		}
	}
	if (n->yPos != 0)
	{
		if (!checkForWalls(n->xPos, n->yPos - 1))
		{
			Node* aboveNeighbour = new Node(n->xPos, n->yPos - 1);
			aboveNeighbour->g = n->g + 1;
			aboveNeighbour->setParent(n);
			neighbours.push_back(aboveNeighbour);
		}
	}
	if (n->yPos != worldSize)
	{
		if (!checkForWalls(n->xPos, n->yPos + 1))
		{
			Node* belowNeighbour = new Node(n->xPos, n->yPos + 1);
			belowNeighbour->g = n->g + 1;
			belowNeighbour->setParent(n);
			neighbours.push_back(belowNeighbour);
		}
	}
	return neighbours;
}

Node* getLowestF(std::vector<Node*> nodes, short xStart, short yStart, short xFinish, short yFinish)
{
	short lowestF = 30000;
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
	float dx = abs(n->xPos - q->xPos);
	float dy = abs(n->yPos - q->yPos);
	float h = dx + dy;
	n->h = h;
	
	return h;
}

std::vector<Node*> AStarSearch::Search(short xStart, short yStart, short xFinish, short yFinish, std::vector<std::pair<short, short>> w)
{
	walls = w;
	Node* start = new Node(xStart, yStart);
	start->f = 0;
	Node* finish = new Node(xFinish, yFinish);
	std::vector<Node*> openList;
	std::vector<Node*> closedList;

	openList.push_back(start);

	while (!openList.empty())
	{
		Node* current = getLowestF(openList, xStart, yStart, xFinish, yFinish);
		//std::cout << current->xPos << " - " << current->yPos << std::endl;
		if (current->xPos == finish->xPos && current->yPos == finish->yPos)
		{
			return createPath(current);
		}
		openList = removeNode(openList, current);
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
	std::vector<Node*> fail;
	return fail;
}

Node* AStarSearch::findInList(std::vector<Node*> list, Node* find)
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

bool AStarSearch::checkForWalls(short x, short y)
{
	for (short i = 0; i < walls.size(); i++)
	{
		if (x == walls.at(i).first && y == walls.at(i).second)
		{
			return true;
		}
	}
	return false;
}

std::vector<Node*> AStarSearch::createPath(Node* n)
{
	std::vector<Node*> path;
	path.push_back(n);
	while (n->getParent() != nullptr)
	{
		n = n->getParent();
		path.push_back(n);
	}
	return path;
}

std::vector<Node*> AStarSearch::removeNode(std::vector<Node*> list, Node* n)
{
	for (short i = 0; i < list.size(); i++)
	{
		if (list.at(i)->xPos == n->xPos && list.at(i)->yPos == n->yPos)
		{
			list.erase(list.begin() + i);
			return list;
		}
	}
}