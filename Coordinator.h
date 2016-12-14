#pragma once
#include "Worker.h"
#include "World.h"
#include <vector>
#include <list>

class Coordinator
{
public:
	Coordinator();
	Coordinator(SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, short width, short height, short workers, World world);
	void SetTarget(short xTarget, short yTarget);
	void RunCoorinator();
	void Render();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;

	short worldWidth;
	short worldHeight;
	std::vector<Worker> myWorkers;
	World myWorld;
};