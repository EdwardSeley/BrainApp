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
	while (SDL_GetTicks() < 3000)
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
	int clicked = -1;
	while (display->stayOnPage())
	{
		if (clicked != -1)
			display->samePage = false;
		display->render(63, 184, 175, 255);
		brain->draw(230, 20, pRenderer);
		credit->draw(110, 730, pRenderer);
		startButton->drawFrame(3, 60, 430, pRenderer);
		display->update();
		clicked = this->manageEvents(buttonVector);
	}

}

int PageManager::historyPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	historyOfNeuroscience->load("HistoryText.png", pRenderer);
	display->samePage = true;
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	historyButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		display->render(63, 184, 175, 255);
		historyOfNeuroscience->draw(-15, 100, pRenderer);
		this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
		display->update();
	}

	historyButton->release();
	return pageSwitch;

}


int PageManager::philosophyPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	philosophyButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		display->render(63, 184, 175, 255);
		this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
		display->update();
	}

	philosophyButton->release();
	return pageSwitch;

}

int PageManager::sciencePage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	scienceButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		display->render(63, 184, 175, 255);
		this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
		display->update();
	}

	scienceButton->release();
	return pageSwitch;

}

int PageManager::computationsPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	computationsButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		display->render(63, 184, 175, 255);
		this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
		display->update();
	}

	computationsButton->release();
	return pageSwitch;

}

int PageManager::resourcesPage()
{
	SDL_Renderer * pRenderer = display->getRenderer();
	display->samePage = true;
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	resourcesButton->keepPressed();
	int pageIndex = -1; //Where to go on the navigational menu (-1 is default)
	int pageSwitch = -1;

	while (pageSwitch == -1)
	{
		pageSwitch = pageIndex; // Delays the render loop so one last iteration
		display->render(63, 184, 175, 255);
		this->renderMenu(pRenderer);
		pageIndex = this->manageEvents(menuVector);
		display->update();
	}

	resourcesButton->release();
	return pageSwitch;

}

vector <Button *> PageManager::loadMenu(SDL_Renderer * pRenderer)
{
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
	return menuVector;
}

void PageManager::renderMenu(SDL_Renderer * pRenderer)
{
	historyButton->drawFrame(3, -2, 0, pRenderer);
	philosophyButton->drawFrame(3, 188, -1, pRenderer);
	scienceButton->drawFrame(3, 377, 0, pRenderer);
	computationsButton->drawFrame(3, 567, -1, pRenderer);
	resourcesButton->drawFrame(3, 848, 0, pRenderer);
}

int PageManager::manageEvents(vector <Button *> buttonVector)
{
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);
	cout << "x: " << x << " y: " << y << endl;
		
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
					cout << "2nd Frame" << endl;
				}

				else if (!buttonVector.at(z)->keepButtonPressed)
				{
					buttonVector.at(z)->setCurrentFrame(1);
					cout << "1st Frame" << endl;
				}
			}

	return -1;

}





