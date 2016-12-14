#include "Coordinator.h"

Coordinator::Coordinator()
{

}

Coordinator::Coordinator(SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, short width, short height, short workers, World world, Player player, short coordID)
{
	myWorld = world;
	//for (short i = 0; i < workers; i++)
	//{
	//	//Worker w = Worker(width - 1, (height / 2) - 10 - i, width, world);
	//	//std::cout << i << std::endl;
	//	Worker w = Worker(width - 5, 10 + (i * 2), width, world.getWalls());
	//	w.setTarget(1, 1);
	//	myWorkers.push_back(w);
	//}
	spawnWorkers(coordID, width, world);
	m_window = w;
	m_renderer = r;
	m_surface = s;

	worldWidth = 1000 / width;
	worldHeight = 1000 / height;
	thePlayer = player;

	lastPlayerPosition.first = 1;
	lastPlayerPosition.second = 1;
	
	workerUpdateDelay = 30;
	currentDelay = 0;
}

void Coordinator::SetTarget(Player player)
{
	//std::cout << "x" << player.position.first / worldWidth << "y" << player.position.second / worldWidth << std::endl;
	if (lastPlayerPosition.first != player.position.first / worldWidth)
	{
		lastPlayerPosition.first = player.position.first / worldWidth;
		for (short i = 0; i < myWorkers.size(); i++)
		{
			myWorkers.at(i).foundTarget = false;
			myWorkers.at(i).setTarget(lastPlayerPosition.first, lastPlayerPosition.second);
		}
	}
	if (lastPlayerPosition.second != player.position.second / worldHeight)
	{
		lastPlayerPosition.second = player.position.second / worldHeight;
		for (short i = 0; i < myWorkers.size(); i++)
		{
			myWorkers.at(i).foundTarget = false;
			myWorkers.at(i).setTarget(lastPlayerPosition.first, lastPlayerPosition.second);
		}
	}
	
}

void Coordinator::RunCoorinator()
{
	for (short i = 0; i < myWorkers.size(); i++)
	{
		if (!myWorkers.at(i).foundTarget)
		{
			myWorkers.at(i).findPath(lastPlayerPosition.first, lastPlayerPosition.second);
		}
		
	}
}

void Coordinator::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_Rect rect;
	for (short j = 0; j < myWorkers.size(); j++)
	{
		for (short i = 0; i < myWorkers.at(j).getPath().size(); i++)
		{
			SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0xFF, 0xFF);
			rect = { myWorkers.at(j).getPath().at(0).first * worldWidth, myWorkers.at(j).getPath().at(0).second * worldHeight, worldWidth, worldHeight };
			SDL_RenderFillRect(m_renderer, &rect);
		}
		
	}
}

void Coordinator::Update()
{
	currentDelay++;
	if (currentDelay > 10)
	{
		currentDelay = 0;
		for (short i = 0; i < myWorkers.size(); i++)
		{
			if (myWorkers.at(i).foundTarget)
			{
				myWorkers.at(i).Update();
			}
		}
	}
	
}

void Coordinator::spawnWorkers(short id, short size, World world)
{
	if (size == 30)
	{
		for (short i = 0; i < 5; i++)
		{
			Worker w = Worker(size - 5, 10 + (i * 2), size, world.getWalls());
			w.setTarget(1, 1);
			myWorkers.push_back(w);
		}
	}
	if (size == 100)
	{
		for (short i = 0; i < 10; i++)
		{
			Worker w = Worker(size - 1 - (id * 2), 10 + (i * 2), size, world.getWalls());
			w.setTarget(1, 1);
			myWorkers.push_back(w);
		}
	}
	if (size == 1000)
	{
		if (id != 6)
		{
			for (short i = 0; i < 10; i++)
			{
				Worker w = Worker(size - 1 - (id * 2), 10 + (i * 2), size, world.getWalls());
				w.setTarget(1, 1);
				myWorkers.push_back(w);
			}
		}
		else
		{
			for (short i = 0; i < 10; i++)
			{
				Worker w = Worker(size - 1 - (6 * 2), 10 + (i * 2), size, world.getWalls());
				w.setTarget(1, 1);
				myWorkers.push_back(w);
			}
		}
	}
	
}
