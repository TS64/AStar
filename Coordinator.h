#pragma once
#include "Worker.h"
#include "World.h"
#include "Player.h"
#include <vector>
#include <list>

class Coordinator
{
public:
	Coordinator();
	Coordinator(SDL_Window* w, SDL_Renderer* r, SDL_Surface* s, short width, short height, short workers, World world, Player player, short coordID);
	void SetTarget(Player player);
	void RunCoorinator();
	void Render();
	void Update();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;
	std::pair<int, int> lastPlayerPosition;
	short worldWidth;
	short worldHeight;
	std::vector<Worker> myWorkers;
	World myWorld;
	Player thePlayer;
	short workerUpdateDelay;
	short currentDelay;
	void spawnWorkers(short id, short size, World world);
};