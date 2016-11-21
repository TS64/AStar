#pragma once
#include "stdafx.h"
#include "SDL.h"
#include "SDL_render.h"
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
private:
	bool m_running;
	SDL_Window* m_window;
	SDL_Surface* screenSurface;
	SDL_Renderer* m_renderer;
	SDL_Rect rectangle;

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
};