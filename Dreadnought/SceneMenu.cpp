#include "SceneMenu.h"


SceneMenu::SceneMenu(GameManager* game_)
{
	//Assign Game Manager
	game = game_;

	//Title
	Title();		
}

SceneMenu::~SceneMenu()
{
	OnDestroy();
}

bool SceneMenu::OnCreate()
{


	return true;
}

void SceneMenu::OnDestroy()
{
	if (game->IsGameActive() == false && game != nullptr)
	{
		game = nullptr;
		delete game;
	}
}

void SceneMenu::Update(bool* gameActive_)
{
	GetUserInput(gameActive_);
}

void SceneMenu::GetUserInput(bool* gameActive_)
{
	std::cout << "SELECTION -> ";
	IO.GetUserInput(userInput);

	if (userInput.compare("howtoplay") == 0)
	{
		cFormat.ClearScreen();
		IO.PrintFromFile("howtoplay.txt");
		cFormat.PauseAfterAction();
		cFormat.ClearScreen();
		Title();
	}
	else if (userInput.compare("play") == 0)
	{
		game->BuildScene(SCENENUMBER::SCENE_GAME);
	}
	else if (userInput.compare("quit") == 0 || userInput.compare("exit") == 0)
		*gameActive_ = false;

	std::cout << std::flush;
}

void SceneMenu::Title()
{
	cFormat.SetColour(7);	
	
	IO.PrintFromFile("asciiBanner.txt");

	cFormat.SetColour(15);
	std::cout << std::flush;

}