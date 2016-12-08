#include "AStarSearch.h"


AStarSearch::AStarSearch()
{

}

std::list<Node*> AStarSearch::Search(int xStart, int yStart, int xFinish, int yFinish)
{
	Node *start = new Node(xStart, yStart);
	start->f = 0;
	Node *finish = new Node(xFinish, yFinish);
	Node *previous = NULL;
	Node *current = NULL;
	Node *child = NULL;

	std::list<Node*> openNodeList;
	std::list<Node*> closedNodeList;
	std::list<Node*>::iterator itr;

	openNodeList.push_back(start);

	while (!openNodeList.empty())
	{
		Node* q = getLowestF(openNodeList, xStart, yStart, xFinish, yFinish);
		openNodeList.remove(q);
		for each (Node* s in getNeighbours(q))
		{
			if (s == finish)
			{

			}
			s->g = q->g + distanceBetweenNodes(s, q);
			s->h = s->calculateH(xFinish, yFinish);
			s->f = s->g + s->h;

			for each (Node* n in openNodeList)
			{
				if (n->xPos == s->xPos && n->yPos == s->yPos && s->f > n->f)
				{
					//skip
				}
				else
				{
					openNodeList.push_back(n);
				}
			}
			for each (Node* n in closedNodeList)
			{
				if (n->xPos == s->xPos && n->yPos == s->yPos && s->f > n->f)
				{
					//skip
				}
				else
				{
					openNodeList.push_back(n);
				}
			}

		}
		closedNodeList.push_back(q);
	}


	

	return openNodeList;
}

std::vector<Node*> AStarSearch::getNeighbours(Node* n)
{
	if (n->xPos != 0)
	{
		Node* leftNeighbour = new Node(n->xPos - 1, n->yPos);
		neighbours.push_back(leftNeighbour);
	}
	if (n->xPos != worldSize)
	{
		Node* rightNeighbour = new Node(n->xPos + 1, n->yPos);
		neighbours.push_back(rightNeighbour);
	}
	if (n->yPos != 0)
	{
		Node* aboveNeighbour = new Node(n->xPos, n->yPos - 1);
		neighbours.push_back(aboveNeighbour);
	}
	if (n->yPos != worldSize)
	{
		Node* belowNeighbour = new Node(n->xPos, n->yPos + 1);
		neighbours.push_back(belowNeighbour);
	}
	return neighbours;
}

Node* getLowestF(std::list<Node*> nodes, int xStart, int yStart, int xFinish, int yFinish)
{
	int lowestF = INFINITY;
	Node* q;
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
