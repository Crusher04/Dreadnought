#include "GameManager.h"



GameManager::GameManager():currentScene{nullptr}, gameActive{nullptr}
{	
	//Console Title
	SetConsoleTitleA("Dreadnought: Rogue-like Surival Game");
	std::cout << "\n\t PLEASE MAXIMIZE WINDOW FOR FULL EXPERIENCE! THANKS :) \n";
	Sleep(5000);
	cFormat.ClearScreen();
	IO.PrintFromFile("credits.txt");
	Sleep(5000);
	cFormat.ClearScreen();

	//Set Game as active
	if (gameActive == nullptr)
	{
		gameActive = DBG_NEW bool;
		*gameActive = true;
	}


	/********************************   Default first scene   ***********************/
						BuildScene(SCENENUMBER::SCENE_MAINMENU);
	/********************************************************************************/
}

GameManager::~GameManager()
{
	*gameActive = false;
	
	if (currentScene) {
		currentScene->OnDestroy();
		delete currentScene;
		
	}

	if (gameActive)
	{
		delete gameActive;
	}

}

void GameManager::Run()
{
	currentScene->Update();
}

void GameManager::Update()
{
	

}


bool GameManager::BuildScene(SCENENUMBER scene_)
{
	if (currentScene != nullptr)
	{
		currentScene->OnDestroy();
		delete currentScene;
		currentScene = nullptr;
	}
	
	switch (scene_)
	{
	case SCENENUMBER::SCENE_MAINMENU:
		currentScene = DBG_NEW SceneMenu(this);
		break;
	case SCENENUMBER::SCENE_GAME:
		currentScene = DBG_NEW SceneGame(this);
		break;
	case SCENENUMBER::SCENE_HOWTOPLAY:
		currentScene = DBG_NEW SceneHowToPlay(this);
	default:
		std::cout << "ERROR: Scene cannot be found\n";
		return false;
		break;
	}

	return true;
}
