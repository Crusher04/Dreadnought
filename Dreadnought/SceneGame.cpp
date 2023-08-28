#include "SceneGame.h"

SceneGame::SceneGame(GameManager* game_)
{
	// Providing a seed value
	std::srand((unsigned)time(NULL));

	game = game_;

	OnCreate();
}


SceneGame::~SceneGame()
{
	OnDestroy();
}

bool SceneGame::OnCreate()
{
	player = std::make_shared<Battleship>();
	player->AddComponent<EngineComponent>();

	player->ListComponents();
	return true;
}

void SceneGame::OnDestroy()
{

}

void SceneGame::Update()
{
}

void SceneGame::GetUserInput()
{
}

void SceneGame::Attack(Battleship friendly, ActorType actor)
{
}

int SceneGame::RandomNumber(DiceType dice, int lastNum)
{
	return 0;
}

void SceneGame::InitializePlayer()
{
}

void SceneGame::RunIntro()
{
	cFormat.ClearScreen();
	std::string intro1, intro2, intro3;
	intro1 = "Commander, you are the last vessel from the fleet. You are in enemy waters and must do what you can to survive.\n";
	intro2 = "Your goal is to find the hidden friendly naval base, we cannot transmit coordinates as this may be an unsecured line.\n";
	intro3 = "\nDo what you can to survive, good luck and gods speed Commander! \n";

	for (int i = 0; i < intro1.length(); i++)
	{
		std::cout << intro1[i];
		Sleep(50);
	}
	Sleep(550);
	for (int i = 0; i < intro2.length(); i++)
	{
		std::cout << intro2[i];
		Sleep(50);
	}
	Sleep(550);
	for (int i = 0; i < intro3.length(); i++)
	{
		std::cout << intro3[i];
		Sleep(50);
	}

	cFormat.Pause();
	cFormat.ClearScreen();

}

