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
		SDL_Log("Surface did not load: ", SDL_GetError());
	}

	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
	
	if (pTexture == 0)
	{
		SDL_Log("Texture did not load: ", SDL_GetError());
	}
	
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

void Diagram::drawFrame(int numOfFrames, int x, int y, SDL_Renderer * pRenderer)
{
	SDL_Rect * srcRect = new SDL_Rect();
	SDL_Rect * destRect = new SDL_Rect();
	SDL_QueryTexture(pTexture, NULL, NULL, &(srcRect->w), &(srcRect->h));
	srcRect->x = 350 * currentFrame;
	srcRect->y = 0;
	destRect->y = y;
	destRect->x = x;
	destRect->w = srcRect->w = srcRect->w / numOfFrames;
	destRect->h = srcRect->h;
	SDL_RenderCopy(pRenderer, pTexture, srcRect, destRect);
}

