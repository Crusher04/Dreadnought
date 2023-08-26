#include "SceneMenu.h"
#include <windows.h> 
#include <sstream>
#include <string>
#include <algorithm>

SceneMenu::SceneMenu(GameManager* game_)
{
	game = game_;

	//Title
	Title();
	//Sleep(1000);
	

	/*std::string s{"Welcome Commander"};
	
	for (int i = 0; i < s.length(); i++)
	{
		std::cout << s[i];
		Sleep(100);
	}*/
	
	
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
	std::getline(std::cin, userInput);
	
	//Set input string to lower case.
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
	userInput.erase(std::remove_if(userInput.begin(), userInput.end(), [](unsigned char x) { return std::isspace(x); }), userInput.end());

	if (userInput.compare("howtoplay") == 0)
	{
		cFormat.ClearScreen();
		std::string howtoplay;
		std::ifstream myFile("howtoplay.txt");
		while (std::getline(myFile, howtoplay))
		{
			std::cout << howtoplay << "\n";
		}
		myFile.close();
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
	std::string asciiBanner;

	std::ifstream myFile("asciiBanner.txt");

	cFormat.SetColour(7);
	
	while (std::getline(myFile, asciiBanner))
	{
		std::cout << asciiBanner << "\n";
	}

	myFile.close();
	cFormat.SetColour(15);
	std::cout << std::flush;

}