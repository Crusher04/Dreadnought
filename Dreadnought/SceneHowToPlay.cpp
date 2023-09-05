#include "SceneHowToPlay.h"

SceneHowToPlay::SceneHowToPlay(GameManager* game_)
{
	game = game_;
}

SceneHowToPlay::~SceneHowToPlay()
{
}

bool SceneHowToPlay::OnCreate()
{
	return false;
}

void SceneHowToPlay::OnDestroy()
{
}

void SceneHowToPlay::Update()
{
	GetUserInput();
}

void SceneHowToPlay::GetUserInput()
{
	std::string input;
	cFormat.ClearScreen();
	IO.PrintFromFile("TextFiles/howtoplay.txt");
	std::cout << "\n SELECTION -> ";
	IO.GetUserInput(input);

	if (input.compare("menu") == 0 || input.compare("back") == 0)
	{
		cFormat.ClearScreen();
		game->BuildScene(SCENENUMBER::SCENE_MAINMENU);

	}
	else if (input.compare("quit") == 0 || input.compare("exit") == 0)
	{
		std::cout << "\n Thanks for Playing! Goodbye! \n";
		game->SetGameActive(false);
	}
	else if (input.compare("armaments") == 0)
	{
		cFormat.ClearScreen();
		IO.PrintFromFile("TextFiles/armaments.txt");
		cFormat.Pause();

	}
	else if (input.compare("subsystems") == 0 || input.compare("subsystem") == 0)
	{
		cFormat.ClearScreen();
		IO.PrintFromFile("TextFiles/subsystems.txt");
		cFormat.Pause();
	}
	else if (input.compare("combat") == 0)
	{

	}
	else if (input.compare("movement") == 0)
	{

	}
	else if (input.compare("shiptypes") == 0)
	{

	}
	else if (input.compare("shops") == 0)
	{

	}
	else if (input.compare("listofkeywords") == 0)
	{
			cFormat.ClearScreen();
			IO.PrintFromFile("TextFiles/listofkeywords.txt");
			cFormat.Pause();

	}
	else 
	{
		cFormat.SetColour(12);
		std::cout << "\n\tKeyword Not Recognized\n";
		cFormat.SetColour(7);
		cFormat.Pause();
		cFormat.ClearScreen();
	}

	
}
