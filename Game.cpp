#include "Game.h"

Game::Game()
{
	m_window = NULL;
	m_renderer = NULL;
	screenSurface = NULL;
	player = Player();
	world = World();
	worldSize = 50;
}

bool Game::Initialize(const char* title, int flags)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL failed. Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		// Make window
		m_window = SDL_CreateWindow("AStar", 10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
	screenSurface = SDL_GetWindowSurface(m_window);
	printf("Game::Init() success");
	world.Initialize(worldSize, m_window, m_renderer);
	player.Initialize(1000 / worldSize, 1000 / worldSize, worldSize, m_window, m_renderer, screenSurface, &world);
	return true;
}

void Game::Update()
{
	player.Update();
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			player.HandleEvents(event.key.keysym.sym);
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

	world.Render();
	player.Render();

	SDL_RenderPresent(m_renderer);
}

bool Game::IsRunning()
{
	return m_running;
}
