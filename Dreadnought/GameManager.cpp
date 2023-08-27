#include "GameManager.h"



GameManager::GameManager():currentScene{nullptr}, gameActive{nullptr}
{	
	//Console Title
	SetConsoleTitleA("Dreadnought: Rogue-like Surival Game");

	//Set Game as active
	if (gameActive == nullptr)
	{
		gameActive = new bool;
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
		currentScene = nullptr;
		delete currentScene;
		
	}

	if (gameActive)
	{
		gameActive = nullptr;
		delete gameActive;
	}

}

void GameManager::Run()
{
	currentScene->Update(gameActive);
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
		currentScene = new SceneMenu(this);
		break;
	case SCENENUMBER::SCENE_GAME:
		currentScene = new SceneGame(this);
		break;
	default:
		std::cout << "ERROR: Scene cannot be found\n";
		return false;
		break;
	}

	return true;
}
