#include "World.h"

World::World()
{
	outerWall = { 0, 0, 1000, 1000 };
}

void World::Initialize(short size, short windowX, short windowY, SDL_Window* window, SDL_Renderer* render)
{
	m_window = window;
	m_renderer = render;
	worldSize = size; // 30, 100, or 1000
	worldArray.resize(size);
	for (short x = 0; x < worldSize; x++)
	{
		worldArray[x].resize(size);
		for (short y = 0; y < worldSize; y++)
		{
			worldArray[x][y] = 0;
		}
	}
	if (worldSize == 30)
	{
		noOfWalls = 3;
		wallsTouchingSides = 1;
		sizeOfWalls = 15;
	}
	if (worldSize == 100)
	{
		noOfWalls = 6;
		wallsTouchingSides = 2;
		sizeOfWalls = 50;
	}
	if (worldSize == 1000)
	{
		noOfWalls = 18;
		wallsTouchingSides = 4;
		sizeOfWalls = 500;
	}
	createWalls(noOfWalls, wallsTouchingSides, sizeOfWalls);
}

void World::Update()
{
	
}

void World::HandleEvents()
{

}

void World::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(m_renderer, &outerWall);
	SDL_Rect rect;
	for (short i = 0; i < worldWalls.size(); i++)
	{
		SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0xFF);
		rect = { worldWalls.at(i).first * (1000 / worldSize), worldWalls.at(i).second * (1000 / worldSize), 1000 / worldSize, 1000 / worldSize };
		SDL_RenderFillRect(m_renderer, &rect);
	}
}

void World::setPlayerPosition(short x, short y)
{
	playerPosition.first = x;
	playerPosition.second = y;
	worldArray.at(x).at(y) = 1;
}

char World::getGridContents(short x, short y)
{
	return worldArray.at(x).at(y);
}

short World::getWorldSize()
{
	return worldSize;
}

std::pair<short, short> World::getPlayerPosition()
{
	return playerPosition;
}

void World::createWalls(char walls, char sides, short size)
{
	std::pair<short, short> wall; // 15, 50, 500 size // 3(1), 6(2), 18(4) walls
	std::vector<short> touchingWalls;
	short distanceBetweenWalls = worldSize / (walls + 1);
	short randPos;
	short sizeRange = size - 1;
	srand(time(0));
	touchingWalls = getUniqueRandom(walls);
	for (char i = 0; i < walls; i++)
	{
		randPos = rand() % (sizeRange - 1) + 1;
		for (short s = 0; s < size; s++)
		{
			wall.first = distanceBetweenWalls * (i + 1);
			wall.second = s + randPos;
			worldArray[wall.first][wall.second] = 1;
			worldWalls.push_back(wall);
		}
	}
	/*for (int i = 0; i < 12; i++)
	{
		worldArray[10][i] = 1;
		wall.first = 10;
		wall.second = i;
		worldWalls.push_back(wall);
	}
	for (int i = 14; i < 28; i++)
	{
		worldArray[10][i] = 1;
		wall.first = 10;
		wall.second = i;
		worldWalls.push_back(wall);
	}*/
}

std::vector<std::pair<short, short>> World::getWalls()
{
	return worldWalls;
}

std::vector<short> World::getUniqueRandom(short n)
{
	srand(time(0));
	std::vector<short> randoms;
	short r;
	if (n == 3)
	{
		r = rand() % 3;
		randoms.push_back(r);
	}
	else if (n == 6)
	{
		bool unique;
		for (char i = 0; i < 2; i++)
		{
			r = rand() % 6;
			if (std::find(randoms.begin(), randoms.end(), r) != randoms.end())
			{
				i--;
			}
			else
			{
				randoms.push_back(r);
			}
		}
	}
	else if (n == 18)
	{
		bool unique;
		for (char i = 0; i < 4; i++)
		{
			r = rand() % 18;
			if (std::find(randoms.begin(), randoms.end(), r) != randoms.end())
			{
				i--;
			}
			else
			{
				randoms.push_back(r);
			}
		}
	}
	return randoms;
}
