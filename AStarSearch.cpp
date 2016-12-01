#include "AStarSearch.h"



AStarSearch::AStarSearch()
{

}

std::list<Node*> AStarSearch::Search(int xStart, int yStart, int xFinish, int yFinish)
{
	Node *start = new Node(xStart, yStart);
	Node *finish = new Node(xFinish, yFinish);
	Node *current = NULL;
	Node *child = NULL;

	std::list<Node*> openNodeList;
	std::list<Node*> closedNodeList;
	std::list<Node*>::iterator itr;

	std::list<Node*> path;

	int n = 0;

	openNodeList.push_back(start);
	start->open = true;

	while (current != finish)
	{
		for (itr = openNodeList.begin(); itr != openNodeList.end(); ++itr)
		{
			if (itr == openNodeList.begin() || (*itr)->getFunc() <= current->getFunc())
			{
				current = (*itr);
			}
		}

		if (current == finish)
		{
			break;
		}

		openNodeList.remove(current);
		current->open = false;

		closedNodeList.push_back(current);
		current->closed = true;

	}

	return path;
}
