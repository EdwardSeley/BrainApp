#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\Diagram.h>

bool PageManager::startingPage()
{
	SDL_Renderer * pRenderer = display->init("The Brain App: An Interactive Study Guide");

	brain->load("Brain Intro.png", pRenderer);
	startButton->load("Start Button.png", pRenderer);
	credit->load("Edward.png", pRenderer);

	while (display->stayOnPage())
	{
		display->render(63, 184, 175, 255);
		brain->draw(70, 20, pRenderer);
		credit->draw(70, 700, pRenderer);
		startButton->drawFrame(11, 20, 430, pRenderer);
		startButton->currentFrame = int((SDL_GetTicks() / 250) % 11);
		display->update();
		display->manageEvents();
	}

	return false;
}

bool PageManager::secondPage()
{
	SDL_Renderer * pRenderer = display->init("The Brain App: An Interactive Study Guide");
	brain->load("Brain.BMP", pRenderer);

	while (true)
	{
		display->render(2, 204, 181, 255);
		brain->draw(70, 20, pRenderer);
		display->update();
		display->manageEvents();
	}

	return false;
}



