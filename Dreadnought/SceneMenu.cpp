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
}

void SceneMenu::Update()
{
	GetUserInput();
}

void SceneMenu::GetUserInput()
{
	
	std::cout << "SELECTION -> ";
	IO.GetUserInput(userInput);
	if (userInput.compare("cursor") == 0)
	{
		IO.PrintCursorPos();
	}
	else if (userInput.compare("howtoplay") == 0)
	{
		cFormat.ClearScreen();
		IO.PrintFromFile("howtoplay.txt");
		game->BuildScene(SCENENUMBER::SCENE_HOWTOPLAY);
		Title();
	}
	else if (userInput.compare("play") == 0)
	{
		game->BuildScene(SCENENUMBER::SCENE_GAME);
	}
	else if (userInput.compare("quit") == 0 || userInput.compare("exit") == 0)
		game->SetGameActive(false);
	else
	{
		cFormat.SetColour(12);
		std::cout << "\n\tKeyword Not Recognized\n";
		cFormat.SetColour(7);
		cFormat.Pause();
		cFormat.ClearScreen();
		Title();
	}
	std::cout << std::flush;
}

void SceneMenu::Title()
{
	cFormat.SetColour(7);	
	
	IO.PrintFromFile("asciiBanner.txt");

	cFormat.SetColour(15);
	std::cout << std::flush;

}