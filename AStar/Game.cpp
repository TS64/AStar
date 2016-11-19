#include "stdafx.h"
#include "Game.h"

Game::Game()
{

}

bool Game::Initialize(const char* title, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, 100, 100, 800, 600, flags);

		if (m_window != 0)
		{
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);
			if (m_renderer != 0)
			{
				SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	m_running = true;
	return true;
}

void Game::Update()
{

}

bool Game::IsRunning()
{
	return m_running;
}