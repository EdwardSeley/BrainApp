#include <SDL\SDL.h>
#include <BrainApp\Button.h>

Button::Button(int leftBound, int rightBound, int bottomBound, int topBound)
{
	left = leftBound;
	right = rightBound;
	bottom = bottomBound;
	top = topBound;
	void(PageManager::*response)(int) = nullptr;
}

void Button::drawFrame()
{
	SDL_Rect * srcRect = new SDL_Rect();
	SDL_Rect * destRect = new SDL_Rect();
	SDL_QueryTexture(this->getTexture(), NULL, NULL, &(srcRect->w), &(srcRect->h));
	srcRect->x = (srcRect->w / frames) * (currentFrame - 1);
	srcRect->y = 0;
	destRect->x = get<0>(coordinates);
	destRect->y = get<1>(coordinates);
	destRect->w = srcRect->w = srcRect->w / frames;
	destRect->h = srcRect->h;
	SDL_RenderCopy(pRenderer, this->getTexture(), srcRect, destRect);

	//cout << "dest-x: " << destRect->x << ", texture: " << this->getTexture() << endl;
}

int Button::getCurrentFrame()
{
	return currentFrame;
}

void Button::release()
{
	keepButtonPressed = false;
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

