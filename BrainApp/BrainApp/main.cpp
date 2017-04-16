#include <SDL\SDL.h>
#include <iostream>
#include <BrainApp\PageManager.h>
#undef main

using namespace std; 

void main()
{
	PageManager * pages = new PageManager();
	if (!pages->startingPage())
		pages->secondPage();

}