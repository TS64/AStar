#include <iostream>
#include <thread>
#include <string>

#include <SDL.h>
//#include "Debug\SDL2-2.0.5\include\SDL.h"
#include <SDL_image.h>

#include "Game.h"

using namespace std;

int main(int argc, char** argv){
	string input = "";
	char gameSize = 1;
	Game* game;
	cout << "Enter size of level. 1 = 30*30; 2 = 100*100; 3 = 1000*1000:\n";
	getline(cin, input);
	if (input == "3")
	{
		game = new Game(3);
		cout << "You entered: " << "3 = 1000*1000" << endl << endl;
	}
	else if (input == "2")
	{
		game = new Game(2);
		cout << "You entered: " << "2 = 100*100" << endl << endl;
	}
	else if (input == "1")
	{
		game = new Game(1);
		cout << "You entered: " << "1 = 30*30" << endl << endl;
	}
	else
	{
		game = new Game(1);
		cout << "You entered: " << input << ". Invalid, defaulting to 1 = 30*30" << endl << endl;
	}

	game->Initialize("AStar game", SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
	
	Uint32 currentFrameTime;
	Uint32 lastFrameTime;
	Uint32 frameTime;
	Uint32 fps;
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
			fps = 1000 / frameTime;
		}		
		//cout << "FPS: " << fps << endl;
	}
	//delete game;
	return 0;
}


