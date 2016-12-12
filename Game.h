#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "SDL_thread.h"
#include "Player.h"
#include "World.h"
#include "Coordinator.h"
#include <iostream>


class Game
{
public:
	Game();
	bool Initialize(const char* title, int flags);
	bool IsRunning();
	void Update();
	void HandleEvents();
	void Render();

	SDL_Thread *thread;
private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Surface* screenSurface;
	SDL_Renderer* m_renderer;
	SDL_Rect rectangle;
	Player player;
	World world;
	Coordinator coordinator;
	int worldSize;

	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 1000;

	static int threadFunction(void* data);
	bool quit = false;
};
