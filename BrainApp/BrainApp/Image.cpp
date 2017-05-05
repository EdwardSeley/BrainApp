#include <BrainApp\Image.h>
#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

void Image::load(char * fileLocation, SDL_Renderer * pRen, int x, int y, int numOfFrames)
{

	coordinates = make_pair(x, y);
	SDL_Surface * pSurface = IMG_Load(fileLocation);
	pRenderer = pRen;
	frames = numOfFrames;

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

void Image::draw()
{
	SDL_Rect * srcRect = new SDL_Rect();
	SDL_Rect * destRect = new SDL_Rect();
	SDL_QueryTexture(pTexture, NULL, NULL, &(srcRect->w), &(srcRect->h));
	srcRect->x = srcRect->y = 0;
	destRect->x = get<0>(coordinates);
	destRect->y = get<1>(coordinates);
	destRect->w = srcRect->w;
	destRect->h = srcRect->h;
	SDL_RenderCopy(pRenderer, pTexture, srcRect, destRect);
}

SDL_Texture * Image::getTexture()
{
	return pTexture;
}


