#include "Player.h"

Player::Player()
{

}

void Player::Initialize(int x, int y, int spd, SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, World* w)
{
	world = w;
	position.first = x;
	position.second = y;
	worldSize = world->getWorldSize();
	speed = 1000 / spd;
	m_window = window;
	m_renderer = renderer;
	m_surface = surface;
	rect = { x, y, 1000 / x, 1000 / y };
}

void Player::Update()
{
	world->setPlayerPosition(position.first / (1000 / worldSize), position.second / (1000 / worldSize));
	rect = { position.first, position.second, 1000 / worldSize, 1000 / worldSize };
}

void Player::HandleEvents(SDL_Keycode e)
{
	switch (e)
	{
	case SDLK_RIGHT:
		printf("right");
		if (world->getPlayerPosition().first != worldSize - 1)
		{
			position.first += speed;
		}
		break;
	case SDLK_LEFT:
		printf("left");
		if (world->getPlayerPosition().first != 0)
		{
			position.first -= speed;
		}
		break;
	case SDLK_DOWN:
		printf("down");
		if (world->getPlayerPosition().second != worldSize - 1)
		{
			position.second += speed;
		}
		break;
	case SDLK_UP:
		printf("up");
		if (world->getPlayerPosition().second != 0)
		{
			position.second -= speed;
		}
		break;
	default:
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	}
}

void Player::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(m_renderer, &rect);
}

std::pair<int, int> Player::getPosition()
{
	return position;
}