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
	void Initialize(int x, int y, int speed, SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, World* world);
	void Update();
	void HandleEvents(SDL_Keycode e);
	void Render();
	std::pair<int, int> getPosition();
	bool positionLock;

private:
	std::pair<int, int> position;
	int worldSize;
	int speed;
	int m_speed;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	SDL_Rect rect;


	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;

	World* world;
};
