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
	int clicked = -1;
	while (display->stayOnPage())
	{
		if (clicked != -1)
			display->samePage = false;
		clicked = this->renderDisplay(imageVector, menuVector);
	}

}

int PageManager::historyPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	historyButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		pageIndex = this->renderDisplay(imageVector, menuVector);
	}

	historyButton->release();
	return pageSwitch;

}


int PageManager::philosophyPage()
{
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	philosophyButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;
	vector <Image *> emptyVec;
	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		//pageIndex = this->renderDisplay(menuVector);
	}

	philosophyButton->release();
	return pageSwitch;

}

int PageManager::sciencePage()
{
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	scienceButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		//pageIndex = this->renderDisplay(menuVector);
	}

	scienceButton->release();
	return pageSwitch;

}

int PageManager::computationsPage()
{
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	computationsButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		//pageIndex = this->renderDisplay(menuVector);
	}

	computationsButton->release();
	return pageSwitch;

}

int PageManager::resourcesPage()
{
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	resourcesButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		//pageIndex = this->renderDisplay(menuVector);
	}

	resourcesButton->release();
	return pageSwitch;

}

int PageManager::renderDisplay(vector <Image *> imageVector, vector <Button *> menuVector)
{
	display->render(63, 184, 175, 255);
	int pageIndex = -1;
	
	if (!menuVector.empty())
	{
		
		if (menuVector.size() == 1)
			menuVector.at(0)->drawFrame();
		else
			this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
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
				((Button *) imageVector.at(x))->drawFrame();
			else 
				imageVector.at(x)->draw();
		}
	}
	cout << "pageIndex: " << pageIndex << endl;
	display->update();
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





