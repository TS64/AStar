#include "Coordinator.h"

Coordinator::Coordinator()
{

}

Coordinator::Coordinator(SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, short width, short height, short workers, World world)
{
	std::cout << workers << std::endl;
	myWorld = world;
	for (short i = 0; i < workers; i++)
	{
		//Worker w = Worker(width - 1, (height / 2) - 10 - i, width, world);
		//std::cout << i << std::endl;
		Worker w = Worker(10, 10, width, world.getWalls());
		myWorkers.push_back(w);
	}
	m_window = w;
	m_renderer = r;
	m_surface = s;

	worldWidth = width;
	worldHeight = height;
	
}

void Coordinator::SetTarget(short xTarget, short yTarget)
{
	for (short i = 0; i < myWorkers.size(); i++)
	{
		myWorkers.at(i).setTarget(xTarget, yTarget);
	}
}

void Coordinator::RunCoorinator()
{
	for (short i = 0; i < myWorkers.size(); i++)
	{
		myWorkers.at(i).findPath(5, 5);
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
			rect = { myWorkers.at(j).getPath().at(i).first * worldWidth, myWorkers.at(j).getPath().at(i).second * worldHeight, worldWidth, worldHeight };
			SDL_RenderFillRect(m_renderer, &rect);
		}
		
	}
}
