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

	pWindow = SDL_CreateWindow(title, 50, 50, 900, 800, SDL_WINDOW_SHOWN); //prints window in the middle

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

bool DisplayApp::stayOnPage()
{
	return samePage;
}

void DisplayApp::clean()
{
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
}

void DisplayApp::manageEvents()
{
	SDL_Event * event = new SDL_Event();

	if (SDL_PollEvent(event))
	{
		switch ((*event).type)
		{
		case SDL_QUIT:
			this->clean();
			cout << "Ending Program." << endl;
			SDL_Quit();
			exit(EXIT_FAILURE);
		case SDL_MOUSEBUTTONDOWN:
				if (event->button.x > 67 && event->button.x < 330 && event->button.y > 479 && event->button.y < 579)
				{
					cout << " x coordinate: " << event->button.x << " y coordinate: " << event->button.x << endl;
					samePage = false;
				}
		default:
			break;
		}
	}
}

