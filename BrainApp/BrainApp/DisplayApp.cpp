#include <SDL\SDL.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\PageManager.h>
#include <iostream>

using namespace std;

SDL_Renderer * DisplayApp::init(char * title)
{
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

	pWindow = SDL_CreateWindow(title, pDisplayMode->w / 2 - 250, pDisplayMode->h / 2 - 250, 500, 500, SDL_WINDOW_SHOWN); //prints window in the middle

	if (pWindow == 0)
	{
		SDL_Log("Window creation failed: %s", SDL_GetError());
		return false;
	}
	
	pRenderer = SDL_CreateRenderer(pWindow, -1, NULL);
	
	return pRenderer;
}

void DisplayApp::render(int red, int blue, int green, int alpha)
{
	SDL_SetRenderDrawColor(pRenderer, red, blue, green, alpha);
	SDL_RenderClear(pRenderer);
}

void DisplayApp::update()
{
	SDL_RenderPresent(pRenderer);
}

bool DisplayApp::keepRunning()
{
	return runProgram;
}

void DisplayApp::manageEvents()
{
	SDL_Event * event = new SDL_Event();

	if (SDL_PollEvent(event))
	{
		switch ((*event).type)
		{
		case SDL_QUIT:
				runProgram = false;
				cout << "Ending Program." << endl;
		default:
			break;
		}
	}
}