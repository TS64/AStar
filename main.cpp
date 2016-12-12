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
	float currentFrameTime;
	float lastFrameTime;
	float frameTime;
	float fps;
	while (game->IsRunning())
	{
		lastFrameTime = SDL_GetTicks();
		game->HandleEvents();
		game->Update();
		game->Render();
		currentFrameTime = SDL_GetTicks();
		frameTime = currentFrameTime - lastFrameTime;
		if (frameTime != 0)
		{
			fps = 1000.0f / frameTime;
		}		
		//cout << "FPS: " << fps << endl;
	}
	return 0;
}


