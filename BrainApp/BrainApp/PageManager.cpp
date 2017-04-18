#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\Image.h>
#include <SDL\SDL_mouse.h>
#include <vector>

void PageManager::introSequence(SDL_Window * pWindow)
{
	SDL_Renderer * pRenderer = display->init(pWindow);
	introSequenceImage->load("IntroSequence.png", pRenderer);
	vector <Button *> emptyVec;
	while (SDL_GetTicks() < 5000)
	{
		display->render(63, 184, 175, 255);
		introSequenceImage->draw(20, 0, pRenderer);
		display->update();
		this->manageEvents(emptyVec);
	}
	
}

void PageManager::startingPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	brain->load("Brain Intro.png", pRenderer);
	startButton->load("StartButton.png", pRenderer);
	credit->load("Edward.png", pRenderer);
	vector <Button *> buttonVector;
	buttonVector.push_back(startButton);
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
		clicked = this->manageEvents(buttonVector);
	}

}

void PageManager::historyPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	historyOfNeuroscience->load("HistoryText.png", pRenderer);
	historyButton->load("Buttons/HistoryButton.png", pRenderer);
	philosophyButton->load("Buttons/PhilosophyButton.png", pRenderer);
	scienceButton->load("Buttons/ScienceButton.png", pRenderer);
	computationsButton->load("Buttons/ComputationsButton.png", pRenderer);
	resourcesButton->load("Buttons/ResourcesButton.png", pRenderer);
	vector <Button *> menuVector;
	menuVector.push_back(historyButton);
	menuVector.push_back(philosophyButton);
	menuVector.push_back(scienceButton);
	menuVector.push_back(computationsButton);
	menuVector.push_back(resourcesButton);

	while (display->stayOnPage())
	{
		display->render(63, 184, 175, 255);
		historyOfNeuroscience->draw(0, 100, pRenderer);
		historyButton->drawFrame(3, 0, 0, pRenderer);
		philosophyButton->drawFrame(3, 190, 0, pRenderer);
		scienceButton->drawFrame(3, 379, 0, pRenderer);
		computationsButton->drawFrame(3, 569, 0, pRenderer);
		resourcesButton->drawFrame(3, 840, 0, pRenderer);
		display->update();
		this->manageEvents(menuVector);
	}

}

bool PageManager::manageEvents(vector <Button *> buttonVector)
{

	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);
	//cout << "x: " << x << " y: " << y << endl;

	if (!buttonVector.empty())
	{

		int x = 0;
		int y = 0;

		for (int z = 0; z < buttonVector.size(); z++)
		{
			if (buttonVector.at(z)->getCurrentFrame() == 3)
				SDL_Delay(300);
		}


		SDL_GetMouseState(&x, &y);

		for (int z = 0; z < buttonVector.size(); z++)
		{
			if (x > buttonVector.at(z)->left && x < buttonVector.at(z)->right && y < buttonVector.at(z)->bottom && y > buttonVector.at(z)->top)
			{
				buttonVector.at(z)->setCurrentFrame(2);
			}

			else
				buttonVector.at(z)->setCurrentFrame(1);
		}

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
			if (!buttonVector.empty())
				for (int z = 0; z < buttonVector.size(); z++)
					if (event->button.x > buttonVector.at(z)->left && event->button.x < buttonVector.at(z)->right && event->button.y < buttonVector.at(z)->bottom && event->button.y > buttonVector.at(z)->top)
					{
						buttonVector.at(z)->setCurrentFrame(3);
						buttonVector.at(z)->clicked = true;
					}
		default:
			break;
		}
	}

	if (!buttonVector.empty())
		return buttonVector.at(0)->clicked;
	else
		return false;

}





