#include <SDL\SDL.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\PageManager.h>
#include <iostream>

using namespace std;

SDL_Renderer * DisplayApp::init(SDL_Window * pWindow)
{
	
	pRenderer = SDL_CreateRenderer(pWindow, -1, NULL);


	if (pRenderer == 0)
	{
		SDL_Log("Renderer creation failed: %s", SDL_GetError());
	}

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

bool DisplayApp::stayOnPage()
{
	return samePage;
}

SDL_Renderer * DisplayApp::getRenderer()
{
	return pRenderer;
}




