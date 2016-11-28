#pragma once
#include "stdafx.h"
#include "SDL_render.h"

class World
{
public:
	World();
	void Initialize(int width, int height, SDL_Window* w, SDL_Renderer* r);
	void Update();
	void HandleEvents();
	void Render();
	char worldArray[1000][1000];
	void setPlayerPosition(int x, int y);
private:
	int worldWidth;
	int worldHeight;

	SDL_Rect outerWall;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
