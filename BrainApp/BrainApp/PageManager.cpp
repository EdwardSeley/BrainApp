#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\Diagram.h>
#include <SDL\SDL_mouse.h>

void PageManager::introSequence(SDL_Window * pWindow)
{
	SDL_Renderer * pRenderer = display->init(pWindow);
	introSequenceImage->load("IntroSequence.png", pRenderer);

	while (SDL_GetTicks() < 8000)
	{
		display->render(63, 184, 175, 255);
		introSequenceImage->draw(20, 0, pRenderer);
		display->update();
		this->manageEvents(NULL, NULL, NULL, NULL, NULL, NULL);
	}
	
}

void PageManager::startingPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	brain->load("Brain Intro.png", pRenderer);
	startButton->load("StartButton.png", pRenderer);
	credit->load("Edward.png", pRenderer);
	bool clicked = false;

	while (display->stayOnPage())
	{
		if (clicked)
			display->samePage = false;
		display->render(63, 184, 175, 255);
		brain->draw(230, 20, pRenderer);
		credit->draw(110, 730, pRenderer);
		startButton->drawFrame(3, 60, 430, pRenderer);
		display->update();
		clicked = this->manageEvents(startButton, clicked, 67, 330, 479, 579);
	}

}

void PageManager::historyPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	historyOfNeuroscience->load("HistoryText.png", pRenderer);

	while (display->stayOnPage())
	{
		display->render(63, 184, 175, 255);
		historyOfNeuroscience->draw(0, 120, pRenderer);
		display->update();
		this->manageEvents(NULL, NULL, NULL, NULL, NULL, NULL);
	}

}

bool PageManager::manageEvents(Diagram * button, bool clicked, int left, int right, int bottom, int top)
{

	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);
	cout << "x: " << x << " y: " << y << endl;

	if (button != NULL)
	{

		int x = 0;
		int y = 0;

		if (button->currentFrame == 3)
			SDL_Delay(300);

		SDL_GetMouseState(&x, &y);

		if (x > left && x < right && y > bottom && y < top)
		{
			button->currentFrame = 2;
		}

		else
			button->currentFrame = 1;

	}
		
	SDL_Event * event = new SDL_Event();

	if (SDL_PollEvent(event))
	{
		switch ((*event).type)
		{
		case SDL_QUIT:
			cout << "Ending Program." << endl;
			SDL_Quit();
			exit(EXIT_FAILURE);
		case SDL_MOUSEBUTTONDOWN:
			if (event->button.x > left && event->button.x < right && event->button.y > bottom && event->button.y < top && button != NULL)
			{
				button->currentFrame = 3;
				clicked = true;
			}
		default:
			break;
		}
	}

	return clicked;

}





