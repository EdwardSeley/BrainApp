#include <SDL\SDL.h>
#include <BrainApp\PageManager.h>
#include <BrainApp\DisplayApp.h>
#include <BrainApp\Image.h>
#include <SDL\SDL_mouse.h>
#include <vector>

SDL_Renderer * pRenderer;

void PageManager::introSequence(SDL_Window * pWindow)
{
	pRenderer = display->init(pWindow);
	introSequenceImage->load("IntroSequence.png", pRenderer, 20, 0);
	
	vector <Image *> imageVector;
	imageVector.push_back(introSequenceImage);
	
	while (SDL_GetTicks() < 3000)
	{
		this->renderDisplay(imageVector);
	}
	
}

void PageManager::startingPage()
{
	brain->load("Brain Intro.png", pRenderer, 230, 20);
	startButton->load("StartButton.png", pRenderer, 80, 430, 3);
	credit->load("Edward.png", pRenderer, 110, 750);
	
	vector <Image *> imageVector;
	imageVector.push_back(brain);
	imageVector.push_back(credit);
	
	vector <Button *> menuVector;
	menuVector.push_back(startButton);
	bool samePage = true;
	
	this->renderDisplay(imageVector, menuVector);


}

int PageManager::historyPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	historyButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, menuVector);

	historyButton->release(); //button is no longer pressed
	return pageIndex;

}


int PageManager::philosophyPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	philosophyButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, menuVector);

	philosophyButton->release(); //button is no longer pressed
	return pageIndex;
}

int PageManager::sciencePage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	scienceButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, menuVector);

	scienceButton->release(); //button is no longer pressed
	return pageIndex;
}

int PageManager::computationsPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	computationsButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, menuVector);

	computationsButton->release(); //button is no longer pressed
	return pageIndex;
}

int PageManager::resourcesPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	resourcesButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, menuVector);

	resourcesButton->release(); //button is no longer pressed
	return pageIndex;
}

int PageManager::renderDisplay(vector <Image *> imageVector, vector <Button *> menuVector)
{
	
	int pageIndex = -1; //default index for pages

	while (pageIndex != -1) //page change has not been requested
	{
		display->render(63, 184, 175, 255);

		if (!menuVector.empty())
		{

			pageIndex = this->manageEvents(menuVector);

			if (menuVector.size() == 1)
				menuVector.at(0)->drawFrame();
			else
				this->renderMenu(pRenderer);

		}

		else
		{
			this->manageEvents();
		}

		if (!imageVector.empty())
		{
			for (int x = 0; x < imageVector.size(); x++)
			{
				if (imageVector.at(x)->frames > 1)
					((Button *)imageVector.at(x))->drawFrame();
				else
					imageVector.at(x)->draw();
			}
		}

		display->update();

	}

	return pageIndex;

}

vector <Button *> PageManager::loadMenu(SDL_Renderer * pRenderer)
{
	historyButton->load("Buttons/HistoryButton.png", pRenderer, -2, 0, 3);
	philosophyButton->load("Buttons/PhilosophyButton.png", pRenderer, 188, -1, 3);
	scienceButton->load("Buttons/ScienceButton.png", pRenderer, 377, 0, 3);
	computationsButton->load("Buttons/ComputationsButton.png", pRenderer, 567, -1, 3);
	resourcesButton->load("Buttons/ResourcesButton.png", pRenderer, 848, 0, 3);
	vector <Button *> menuVector;
	menuVector.push_back(historyButton);
	menuVector.push_back(philosophyButton);
	menuVector.push_back(scienceButton);
	menuVector.push_back(computationsButton);
	menuVector.push_back(resourcesButton);
	return menuVector;
}

void PageManager::renderMenu(SDL_Renderer * pRenderer)
{
	historyButton->drawFrame();
	philosophyButton->drawFrame();
	scienceButton->drawFrame();
	computationsButton->drawFrame();
	resourcesButton->drawFrame();
}

int PageManager::manageEvents(vector <Button *> buttonVector)
{
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);
		
	SDL_Event * event = new SDL_Event();

	if (SDL_PollEvent(event) && event->type == SDL_QUIT)
	{
			cout << "Ending Program." << endl;
			SDL_Quit();
			exit(EXIT_FAILURE);
	}
			
	if (!buttonVector.empty())
		for (int z = 0; z < buttonVector.size(); z++)
			{
				if (event->type == SDL_MOUSEBUTTONDOWN && event->button.x > buttonVector.at(z)->left && event->button.x < buttonVector.at(z)->right
					&& event->button.y < buttonVector.at(z)->bottom && event->button.y > buttonVector.at(z)->top)
				{
					buttonVector.at(z)->setCurrentFrame(3);
					buttonVector.at(z)->clicked = true;
					return z;
				}

				else if (x > buttonVector.at(z)->left && x < buttonVector.at(z)->right && y < buttonVector.at(z)->bottom
						&& y > buttonVector.at(z)->top)
				{
					buttonVector.at(z)->setCurrentFrame(2);
				}

				else if (!buttonVector.at(z)->keepButtonPressed)
				{
					buttonVector.at(z)->setCurrentFrame(1);
				}
			}

	return -1;

}





