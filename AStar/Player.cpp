#include "stdafx.h"
#include "Player.h"

Player::Player()
{

}

void Player::Initialize(int x, int y, SDL_Window* window, SDL_Renderer* renderer, SDL_Surface* surface, World* w)
{
	world = w;
	m_xPosition = x;
	m_yPosition = y;
	m_window = window;
	m_renderer = renderer;
	m_surface = surface;
	m_outerRectangle = { x - 4, y - 4, 9, 9 };
	m_innerRectangle = { x - 1 ,y - 1, 3, 3 };
}

void Player::Update()
{
	m_outerRectangle = { m_xPosition - 4, m_yPosition - 4, 9, 9 };
	m_innerRectangle = { m_xPosition - 1, m_yPosition - 1, 3, 3 };
	world->setPlayerPosition(m_xPosition, m_yPosition);
}

void Player::HandleEvents(SDL_Keycode e)
{
	switch (e)
	{
	case SDLK_RIGHT:
		printf("right");
		if (m_xPosition != 999)
		{
			m_xPosition += 1;
		}
		break;
	case SDLK_LEFT:
		printf("left");
		if (m_xPosition != 1)
		{
			m_xPosition -= 1;
		}
		break;
	case SDLK_DOWN:
		printf("down");
		if (m_yPosition != 999)
		{
			m_yPosition += 1;
		}
		break;
	case SDLK_UP:
		printf("up");
		if (m_yPosition != 1)
		{
			m_yPosition -= 1;
		}
		break;
	default:
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	}
}

void Player::Render()
{
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(m_renderer, &m_outerRectangle);
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(m_renderer, &m_innerRectangle);
	//Draw_Circle(m_surface, 50, 50, 10, 0x50);
	//SDL_RenderPresent(m_renderer);
}