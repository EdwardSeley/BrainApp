#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>

void PageManager::startingPage()
{
	DisplayApp * display = new DisplayApp();

	display->init("Welcome to the Brain App");
}