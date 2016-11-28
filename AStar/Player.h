#pragma once
#include "stdafx.h"
#include "SDL.h"
#include "SDL_render.h"
#include "World.h"
#include <iostream>

class Player
{
public:
	Player();
	void Initialize(int x, int y, SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, World* world);
	void Update();
	void HandleEvents(SDL_Keycode e);
	void Render();
private:
	int m_xPosition;
	int m_yPosition;
	int m_speed;
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	SDL_Rect m_outerRectangle;
	SDL_Rect m_innerRectangle;
	

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;

	World* world;
};