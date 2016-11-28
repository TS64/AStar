#include "stdafx.h"
#include "World.h"

World::World()
{
	outerWall = { 0, 0, 1000, 1000 };
}

void World::Initialize(int w, int h, SDL_Window* window, SDL_Renderer* render)
{
	m_window = window;
	m_renderer = render;
	worldWidth = w;
	worldHeight = h;
	for (int x = 0; x < 1000; x++)
	{
		for (int y = 0; y < 1000; y++)
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

	//SDL_RenderPresent(m_renderer);
}

void World::setPlayerPosition(int x, int y)
{
	worldArray[x][y] = 1;
}