#pragma once
#include "SDL_render.h"
#include <vector>
#include <ctime>

class World
{
public:
	World();
	void Initialize(short worldSize, short windowX, short windowY, SDL_Window* w, SDL_Renderer* r);
	void Update();
	void HandleEvents();
	void Render();
	std::vector<std::vector<short>> worldArray;
	void setPlayerPosition(short x, short y);
	char getGridContents(short x, short y);
	short getWorldSize();
	std::pair<short, short> getPlayerPosition();
	std::vector < std::pair<short, short>> wallPosition;
	std::vector<std::pair<short, short>> getWalls();
private:
	short worldSize;
	std::pair<short, short> playerPosition;
	std::vector<std::pair<short, short>> worldWalls;
	SDL_Rect outerWall;
	std::vector<SDL_Rect> wallRectangles;

	SDL_Rect playerRect;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	void createWalls(char walls, char sides, short size);
	std::vector<short> World::getUniqueRandom(short n);
	char wallsTouchingSides;
	char noOfWalls;
	char sizeOfWalls;
};
