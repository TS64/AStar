#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = 500;
	rectangle.h = 500;
	m_window = NULL;
	m_renderer = NULL;
	screenSurface = NULL;
}

bool Game::Initialize(const char* title, int flags)
{
	/*if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, 100, 100, 800, 600, SDL_WINDOW_SHOWN);
		std::cout << "SDL Init success" << std::endl;
		if (m_window != 0)
		{
			screenSurface = SDL_GetWindowSurface(m_window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(m_window);
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
			std::cout << "Window Init fail" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL Init fail" << std::endl;
		return false;
	}
	m_running = true;
	std::cout << "Game() Init success" << std::endl;
	return true;*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL failed. Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		// Make window
		m_window = SDL_CreateWindow("AStar", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			printf("Window failed. Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			// Make renderer
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
			if (m_renderer == NULL)
			{
				printf("Render failed. Error: %s\n", SDL_GetError());
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}		
	}
	m_running = true;
	printf("Game::Init() success");
	return true;
}

void Game::Update()
{
	
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_running = false;
				break;
			default:
				SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
			}
		}
	}
}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_renderer);

	SDL_Rect fillRect = { 0, 0, 500, 500 };
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(m_renderer, &fillRect);

	SDL_RenderPresent(m_renderer);
}

bool Game::IsRunning()
{
	return m_running;
}