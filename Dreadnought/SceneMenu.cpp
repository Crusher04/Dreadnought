#include "SceneMenu.h"
#include <windows.h> 

SceneMenu::SceneMenu()
{
	
	//Title
	Title();
	Sleep(1000);
	std::cout << "IM AWAKE\n";

	std::string s{"Welcome Commander"};
	
	for (int i = 0; i < s.length(); i++)
	{
		std::cout << s[i];
		Sleep(100);
	}
	
	
}

bool SceneMenu::OnCreate()
{


	return true;
}

void SceneMenu::OnDestroy()
{

}

void SceneMenu::Update(bool* gameActive_)
{

}

void SceneMenu::GetUserInput()
{

}

void SceneMenu::Title()
{

	cFormat.SetColour(7);
	std::cout << "Welcome To Battleship Combat Simulator!\n"
		<< "---------------------------------------\n"
		<< "To quit the game, type Quit or Exit at anytime, progress does not save!\n"
		<< "Type Help for all keywords.\n"
		<< "Goal of the game is to destroy your opponent! You'll have a choice of ships, each with a specific armament.\n"
		<< "The board is 20x20 and you move one square at a time. \nEach weapon will have a specific dice as damage and you roll to hit with every attack.\n"
		<< "Every turn you have 1 action, 1 bonus action and your movement speed. Good luck!\n"
		<< "---------------------------------------\n\n";
	cFormat.SetColour(15);
}