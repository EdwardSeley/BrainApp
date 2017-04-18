#include <SDL\SDL.h>
#include <iostream>
#include <BrainApp\PageManager.h>
#undef main

using namespace std; 

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * pWindow = SDL_CreateWindow("The Brain App: An Interactive Study Guide", 50, 50, 1100, 880, SDL_WINDOW_SHOWN); //prints window in the middle

	if (pWindow == 0)
	{
		SDL_Log("Window creation failed: %s", SDL_GetError());
		return -1;
	}

	PageManager * pages = new PageManager();
	pages->introSequence(pWindow);
	pages->startingPage();
	pages->historyPage();
}