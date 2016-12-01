#include "World.h"

World::World()
{
	outerWall = { 0, 0, 1000, 1000 };
}

void World::Initialize(int size, SDL_Window* window, SDL_Renderer* render)
{
	m_window = window;
	m_renderer = render;
	worldSize = size;
	for (int x = 0; x < worldSize; x++)
	{
		for (int y = 0; y < worldSize; y++)
		{
			worldArray[x][y] = 0;
		}
	}
}

void World::Update()
{
	
}

void World::HandleEvents()
{

}

void World::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(m_renderer, &outerWall);
}

void World::setPlayerPosition(int x, int y)
{
	playerPosition.first = x;
	playerPosition.second = y;
	worldArray[x][y] = 1;
}

char World::getGridContents(int x, int y)
{
	return worldArray[x][y];
}

int World::getWorldSize()
{
	return worldSize;
}

std::pair<int, int> World::getPlayerPosition()
{
	return playerPosition;
}
