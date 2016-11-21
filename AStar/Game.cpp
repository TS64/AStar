#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 50;
	rectangle.h = 50;
}

bool Game::Initialize(const char* title, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, 100, 100, 800, 600, flags);
		std::cout << "SDL Init success" << std::endl;
		if (m_window != 0)
		{
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);
			std::cout << "Window creation success" << std::endl;
			if (m_renderer != 0)
			{
				SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 200);
				std::cout << "Renderer creation success" << std::endl;
			}
			else
			{
				std::cout << "Renderer init fail" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Window Init success" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL Init success" << std::endl;
		return false;
	}
	m_running = true;
	std::cout << "Game() Init success" << std::endl;
	return true;
}

void Game::Update()
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 1000;
	int y2 = 1000;
	SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
	SDL_RenderFillRect(m_renderer, &rectangle);
}

bool Game::IsRunning()
{
	return m_running;
}