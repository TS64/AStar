#pragma once
#include "SDL.h"
#include "SDL_render.h"
#include "World.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

class Player
{
public:
	Player();
	void Initialize(short x, short y, short speed, SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, World world);
	void Update();
	void HandleEvents(SDL_Keycode e);
	void Render();
	std::pair<short, short> getPosition();
	bool positionLock;
	std::pair<short, short> position;

private:
	
	short worldSize;
	short speed;
	short m_speed;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_Rect rect;


	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;

	World world;
	bool checkForWalls(short x, short y);
};
