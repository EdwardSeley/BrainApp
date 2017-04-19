#include <SDL\SDL.h>
#include <BrainApp\Button.h>

Button::Button(int leftBound, int rightBound, int bottomBound, int topBound)
{
	left = leftBound;
	right = rightBound;
	bottom = bottomBound;
	top = topBound;
}

void Button::drawFrame(int numOfFrames, int x, int y, SDL_Renderer * pRenderer)
{
	SDL_Rect * srcRect = new SDL_Rect();
	SDL_Rect * destRect = new SDL_Rect();
	SDL_QueryTexture(this->getTexture(), NULL, NULL, &(srcRect->w), &(srcRect->h));
	srcRect->x = srcRect->w / numOfFrames * (currentFrame - 1);
	srcRect->y = 0;
	destRect->y = y;
	destRect->x = x;
	destRect->w = srcRect->w = srcRect->w / numOfFrames;
	destRect->h = srcRect->h;
	SDL_RenderCopy(pRenderer, this->getTexture(), srcRect, destRect);
}

int Button::getCurrentFrame()
{
	return currentFrame;
}

void Button::setCurrentFrame(int frameNumber)
{
	currentFrame = frameNumber;
}

void Button::keepPressed()
{
	currentFrame = 3;
	keepButtonPressed = true;
}

