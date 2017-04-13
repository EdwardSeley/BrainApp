#include <SDL\SDL.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\PageManager.h>
#include <iostream>

using namespace std;

bool DisplayApp::init(char * title)
{
	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;
	SDL_DisplayMode * pDisplayMode = new SDL_DisplayMode();

	if ( SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log(" SDL_VIDEO could not be initilized: %s", SDL_GetError());
		return false;
	}


	if (SDL_GetCurrentDisplayMode(0, pDisplayMode) != 0)
	{
		SDL_Log("SDL_GetDisplayMode failed: %s", SDL_GetError());
		return false;
	}

	pWindow = SDL_CreateWindow(title, pDisplayMode->w / 2 - 250, pDisplayMode->h / 2 - 250, 500, 500, SDL_WINDOW_SHOWN); //prnts window in the middle

	if (pWindow == 0)
	{
		SDL_Log("Window creation failed: %s", SDL_GetError());
		return false;
	}

	pRenderer = SDL_CreateRenderer(pWindow, -1, NULL);

	return true;
}