#pragma once
#include "SDL_render.h"
#include <vector>

class World
{
public:
	World();
	void Initialize(int size, SDL_Window* w, SDL_Renderer* r);
	void Update();
	void HandleEvents();
	void Render();
	char worldArray[50][50];
	void setPlayerPosition(int x, int y);
	char getGridContents(int x, int y);
	int getWorldSize();
	std::pair<int, int> getPlayerPosition();
private:
	int worldSize;
	std::pair<int, int> playerPosition;
	SDL_Rect outerWall;

	SDL_Rect playerRect;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
