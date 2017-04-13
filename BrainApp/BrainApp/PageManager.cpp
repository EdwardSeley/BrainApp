#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\Diagram.h>

void PageManager::startingPage()
{
	SDL_Renderer * pRenderer = display->init("The Brain App: An Interactive Study Guide");

	while (display->keepRunning())
	{
		display->render(57, 133, 118, 155);
		brain->load("BrainSurface.png", pRenderer);
		brain->draw(50, 50, pRenderer);
		display->update();
		display->manageEvents();
	}

}