#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>

void PageManager::startingPage()
{
	display->init("The Brain App: An Interactive Study Guide");

	while (display->keepRunning())
	{
		display->render();
		//display->update();
		display->manageEvents();
	}

}