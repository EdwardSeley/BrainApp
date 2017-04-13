#include <SDL\SDL.h>
#include <iostream>
#include <BrainApp\PageManager.h>
#undef main

using namespace std; 

void main()
{
	PageManager * pages = new PageManager();
	pages->startingPage();
	SDL_Delay(20000);

}