#include "GameManager.h"
#include <SDL3_ttf/SDL_ttf.h>

GameManager::GameManager():currentScene{nullptr}, gameActive{nullptr}
{	
	windowPtr = nullptr;
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;
	windowPtr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (windowPtr == nullptr) {
		//OnDestroy();
		//return false;
	}
	if (windowPtr->OnCreate() == false) {
		//OnDestroy();
		//return false;
	}


	//Console Title
	//SetConsoleTitleA("Dreadnought: Rogue-like Surival Game");
	//std::cout << "\n\t PLEASE MAXIMIZE WINDOW FOR FULL EXPERIENCE! THANKS :) \n";
	//Sleep(4000);
	//cFormat.ClearScreen();
	//IO.PrintFromFile("TextFiles/credits.txt");
	//Sleep(3500);
	//cFormat.ClearScreen();

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

	windowPtr->OnDestroy();
	delete windowPtr;
}

void GameManager::Run()
{
	// --- SDL_ttf Initialization ---
	if (TTF_Init() != 0) {
		std::cerr << "TTF_Init Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}
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
