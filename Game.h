#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "Player.h"
#include "World.h"
#include "Coordinator.h"
#include <iostream>


class Game
{
public:
	Game(char size);
	bool Initialize(const char* title, int flags);
	bool IsRunning();
	void Update();
	void HandleEvents();
	void Render();

private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Surface* screenSurface;
	SDL_Renderer* m_renderer;
	SDL_Rect rectangle;
	Player player;
	World world;
	Coordinator* coordinator;
	short worldSize;

	short SCREEN_WIDTH = 990;
	short SCREEN_HEIGHT = 990;
	short workersPerCoord = 5;
};
