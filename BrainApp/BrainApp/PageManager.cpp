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
	
	this->renderDisplay(imageVector, 3000);
	
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
	
	this->renderDisplay(imageVector, 0, menuVector);


}

int PageManager::historyPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	historyButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, 0, menuVector);

	historyButton->release(); //button is no longer pressed
	return pageIndex;

}


int PageManager::philosophyPage()
{
	philosophyOfMind->load("PhilosophyOfMind.png", pRenderer, -15, 100);
	dualismButton->load("Buttons/Dualism.png", pRenderer, 20, 294, 2);
	monismButton->load("Buttons/Monism.png", pRenderer, 378, 297, 2);
	materialismButton->load("Buttons/Materialism.png", pRenderer, 240, 414, 2);
	idealismButton->load("Buttons/Idealism.png", pRenderer, 528, 415, 2);
	behaviorismButton->load("Buttons/Behaviorism.png", pRenderer, 20, 549, 2);
	identityTheoryButton->load("Buttons/IdentityTheory.png", pRenderer, 237, 550, 2);
	functionalismButton->load("Buttons/Functionalism.png", pRenderer, 481, 549, 2);
	mindBodyButton->load("Buttons/MindBodyProblem.png", pRenderer, 139, 656, 2);
	consciousnessButton->load("Buttons/Consciousness.png", pRenderer, 215, 739, 2);
	explanationImages.push_back("DualismText.png");
	explanationImages.push_back("MonismText.png");
	explanationImages.push_back("MaterialismText.png");
	explanationImages.push_back("IdealismText.png");
	explanationImages.push_back("BehaviorismText.png");
	explanationImages.push_back("IdentityTheoryText.png");
	explanationImages.push_back("FunctionalismText.png");
	explanationImages.push_back("MindBodyProblemText.png");
	explanationImages.push_back("ConsciousnessText.png");

	vector <Image *> imageVector;
	imageVector.push_back(philosophyOfMind);
	vector <Button *> buttonVector = this->loadMenu(pRenderer);
	buttonVector.push_back(dualismButton);
	buttonVector.push_back(monismButton);
	buttonVector.push_back(materialismButton);
	buttonVector.push_back(idealismButton);
	buttonVector.push_back(behaviorismButton);
	buttonVector.push_back(identityTheoryButton);
	buttonVector.push_back(functionalismButton);
	buttonVector.push_back(mindBodyButton);
	buttonVector.push_back(consciousnessButton);
	philosophyButton->keepPressed();
	int pageIndex = this->renderDisplay(imageVector, 0, buttonVector);
	philosophyButton->release(); //button is no longer pressed
	explanationImages.clear();
	return pageIndex;
}

int PageManager::sciencePage()
{
	neuroscience->load("Neuroscience.png", pRenderer, -15, 100);
	downButton->load("DownButton.png", pRenderer, 520, 800, 2);
	pumpButton->load(" ", pRenderer, 10, 300, 4);
	explanationImages.push_back("Neuroscience.png");
	explanationImages.push_back("NeuronAnatomy.png");
	explanationImages.push_back("PotentialDifference.png");
	explanationImages.push_back("LeakChannels.png");
	explanationImages.push_back("Depolarization.png");
	explanationImages.push_back("ActionPotential.png");
	explanationImages.push_back("SynapticTerminal.png");
	explanationImages.push_back("VariationInFunction.png");
	vector <Image *> imageVector;
	imageVector.push_back(neuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	menuVector.push_back(downButton);
	menuVector.push_back(pumpButton);
	neuroscienceButton->keepPressed();
	neuroscienceImageCount = 0;

	int pageIndex = this->renderDisplay(imageVector, 0, menuVector);

	neuroscienceButton->release(); //button is no longer pressed
	return pageIndex;
}

int PageManager::computationsPage()
{
	historyOfNeuroscience->load("HistoryText.png", pRenderer, -15, 100);
	vector <Image *> imageVector;
	imageVector.push_back(historyOfNeuroscience);
	vector <Button *> menuVector = this->loadMenu(pRenderer);
	computationsButton->keepPressed();

	int pageIndex = this->renderDisplay(imageVector, 0, menuVector);

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

	int pageIndex = this->renderDisplay(imageVector, 0, menuVector);

	resourcesButton->release(); //button is no longer pressed
	return pageIndex;
}

void PageManager::displayExplanation(int index)
{
	char * fileLocation = "";

	if (philosophyButton->keepButtonPressed)
	{
		fileLocation = explanationImages.at(index);
		explanation->load(fileLocation, pRenderer, 725, 290);
		explanation->draw();
	}
	
	if (neuroscienceButton->keepButtonPressed)
	{
		neuroscienceImageCount++;
		if (neuroscienceImageCount < 8)
		{
			fileLocation = explanationImages.at(neuroscienceImageCount);
			neuroscience->load(fileLocation, pRenderer, -15, 100);

			if (neuroscienceImageCount == 2) {
				pumpButton->load("pumpButton.png", pRenderer, 10, 300, 4);
			}

			if (neuroscienceImageCount == 3) {
				pumpButton->load(" ", pRenderer, 10, 300, 4);
			}
		}
	}
}

int PageManager::renderDisplay(vector <Image *> imageVector, int secondsLooping, vector <Button *> menuVector)
{
	
	int pageIndex = -1; //default index for pages
	int start = SDL_GetTicks();


	while (pageIndex == -1 && (SDL_GetTicks() - start < secondsLooping || secondsLooping == 0) ) //page change has not been requested 
																				//or time hasn't elapsed past 'secondsLooping' argument 
	{
		display->render(63, 184, 175, 255);

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

		if (!menuVector.empty())
		{
			pageIndex = this->manageEvents(menuVector);

			for (int x = 0; x < menuVector.size(); x++)
			{
				menuVector.at(x)->drawFrame();
			}

		}

		else
		{
			this->manageEvents();
		}

		if (pageIndex > 100)
		{
			this->displayExplanation(pageIndex - 105);
			pageIndex = -1;
		}

		display->update();

	}

	return pageIndex;

}

vector <Button *> PageManager::loadMenu(SDL_Renderer * pRenderer)
{
	historyButton->load("Buttons/HistoryButton.png", pRenderer, -2, 0, 3);
	philosophyButton->load("Buttons/PhilosophyButton.png", pRenderer, 188, -1, 3);
	neuroscienceButton->load("Buttons/ScienceButton.png", pRenderer, 377, 0, 3);
	computationsButton->load("Buttons/ComputationsButton.png", pRenderer, 567, -1, 3);
	resourcesButton->load("Buttons/ResourcesButton.png", pRenderer, 848, 0, 3);
	
	vector <Button *> menuVector;
	menuVector.push_back(historyButton);
	menuVector.push_back(philosophyButton);
	menuVector.push_back(neuroscienceButton);
	menuVector.push_back(computationsButton);
	menuVector.push_back(resourcesButton);
	return menuVector;
}

int PageManager::manageEvents(vector <Button *> buttonVector)
{
	int x = 0;
	int y = 0;

	SDL_GetMouseState(&x, &y);
	//cout << "x: " << x << " y: " << y << endl;

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
				if (buttonVector.at(z)->frames == 3)
				{
					buttonVector.at(z)->setCurrentFrame(3);
					buttonVector.at(z)->clicked = true;
					return z;
				}

				else if (neuroscienceButton->keepButtonPressed && z == 5)
				{
					return z + 100;
				}

				else if (neuroscienceButton->keepButtonPressed && z == 6)
				{
					pumpButtonCount++;
					if (pumpButtonCount > 4)
						pumpButtonCount = 1;
					buttonVector.at(z)->setCurrentFrame(pumpButtonCount);
				}
			}

				else if (x > buttonVector.at(z)->left && x < buttonVector.at(z)->right && y < buttonVector.at(z)->bottom
						&& y > buttonVector.at(z)->top)
				{
					if (!neuroscienceButton->keepButtonPressed || z != 6)
						buttonVector.at(z)->setCurrentFrame(2);
					if (z > 4 && philosophyButton->keepButtonPressed)
						return z + 100;
				}

				else if (!buttonVector.at(z)->keepButtonPressed)
				{
					if (!(neuroscienceButton->keepButtonPressed && z == 6))
					buttonVector.at(z)->setCurrentFrame(1);
				}

			}

	return -1;

}





