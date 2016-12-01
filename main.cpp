#include <iostream>
#include <thread>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv){

	Game* game = new Game();

	game->Initialize("AStar game", SDL_WINDOW_SHOWN);

	while (game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}
	return 0;
}

