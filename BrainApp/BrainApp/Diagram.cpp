#include <BrainApp\Diagram.h>
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

void Diagram::load(char * fileLocation, SDL_Renderer * pRenderer)
{
	SDL_Surface * pSurface = IMG_Load(fileLocation);
	if (pSurface == 0)
	{
		SDL_Log("Image did not load: ", SDL_GetError());
	}
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
	SDL_FreeSurface(pSurface);
}

void Diagram::draw(int x, int y, SDL_Renderer * pRenderer)
{
	SDL_Rect * srcRect = new SDL_Rect();
	SDL_Rect * destRect = new SDL_Rect();
	SDL_QueryTexture(pTexture, NULL, NULL, &(srcRect->w), &(srcRect->h));
	srcRect->x = srcRect->y = 0;
	destRect->x = x;
	destRect->y = y;
	destRect->w = srcRect->w;
	destRect->h = srcRect->h;
	SDL_RenderCopy(pRenderer, pTexture, srcRect, destRect);
}