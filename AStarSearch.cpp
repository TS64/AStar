#include "AStarSearch.h"


AStarSearch::AStarSearch()
{

}

std::priority_queue<Node*> AStarSearch::Search(int xStart, int yStart, int xFinish, int yFinish)
{
	Node *start = new Node(xStart, yStart);
	Node *finish = new Node(xFinish, yFinish);
	Node *previous = NULL;
	Node *current = NULL;
	Node *child = NULL;

	std::list<Node*> openNodeList;
	std::list<Node*> closedNodeList;
	std::list<Node*>::iterator itr;

	//std::list<Node*> path;

	std::priority_queue<Node*> queue;
	queue.push(start);

	int currentCost = 0;
	int newCost = 0;

	start->setCost(0);

	openNodeList.push_back(start);
	start->open = true;

	while (!queue.empty())
	{
		current = queue.top();

		if (current == finish)
		{
			break;
		}

		for each (Node* next in getNeighbours(current))
		{
			newCost += currentCost + current->calculateFunc(current->getX(), current->getY(), next->getX(), next->getY());

		}
	}

	return queue;
}

std::vector<Node*> AStarSearch::getNeighbours(Node* n)
{
	if (n->getX() != 0)
	{
		Node* leftNeighbour = new Node(n->getX() - 1, n->getY());
		neighbours.push_back(leftNeighbour);
	}
	if (n->getX() != worldSize)
	{
		Node* rightNeighbour = new Node(n->getX() + 1, n->getY());
		neighbours.push_back(rightNeighbour);
	}
	if (n->getY() != 0)
	{
		Node* aboveNeighbour = new Node(n->getX(), n->getY() - 1);
		neighbours.push_back(aboveNeighbour);
	}
	if (n->getY() != worldSize)
	{
		Node* belowNeighbour = new Node(n->getX(), n->getY() + 1);
		neighbours.push_back(belowNeighbour);
	}
	return neighbours;
}
