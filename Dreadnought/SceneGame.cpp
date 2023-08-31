#include "SceneGame.h"

SceneGame::SceneGame(GameManager* game_)
{
	// Providing a seed value
	std::srand((unsigned)time(NULL));

	game = game_;

	LoadAssets();
	OnCreate();
}


SceneGame::~SceneGame()
{
	OnDestroy();
}

bool SceneGame::OnCreate()
{
	player = std::make_shared<Battleship>(ActorType::PLAYER);
	
	//Base Components
	player->AddComponent<EngineComponent>(EngineType::E_NULL);
	player->AddComponent<InventoryComponent>();
	player->AddComponent<CommandCenterComponent>();

	return true;
}

void SceneGame::OnDestroy()
{

}

void SceneGame::Update()
{
	while(!starterShpSelected)
		SelectStarterShip();

	
	game->SetGameActive(false);
}


int SceneGame::RandomNumber(DiceType dice, int lastNum)
{
	return 0;
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

}

void SceneGame::SelectStarterShip()
{
	cFormat.ClearScreen();
	IO.PrintFromFile("TextFiles/shipDesc.txt");
	std::cout << "\nSELECTION -> ";
	IO.GetUserInput(*userInput);
	if (userInput->compare("dreadnought") == 0)
	{

		NavalBattery250->Initialize(Armament::NavalBattery250mm, 2);

		
		starterShpSelected = true;


	}
	else if (userInput->compare("idris") == 0)
	{
		player->GetComponent<EngineComponent>()->ChangeEngineType(EngineType::EV20);

		starterShpSelected = true;

	}
	else if (userInput->compare("sunkenlady") == 0)
	{
		player->GetComponent<EngineComponent>()->ChangeEngineType(EngineType::EV15);

		starterShpSelected = true;

	}
	else if (userInput->compare("supernova") == 0)
	{
		player->GetComponent<EngineComponent>()->ChangeEngineType(EngineType::EV10);

		starterShpSelected = true;

	}
	else
	{
		std::cout << "ERROR: ship not available, please select another ship.\n";
	}

}

void SceneGame::LoadAssets()
{
	NavalBattery250 = std::make_shared<JAMISAsset>("Naval Battery 250mm", InventoryType::ARMAMENT);
	NavalBattery400 = std::make_shared<JAMISAsset>("Naval Battery 400mm", InventoryType::ARMAMENT);
	ASM = std::make_shared<JAMISAsset>("Anti-Ship Missile", InventoryType::MISSILES);
	AST = std::make_shared<JAMISAsset>("Anti-Ship Torpedo", InventoryType::MISSILES);
	ADS = std::make_shared<JAMISAsset>("Active Defense System", InventoryType::ARMAMENT);
	
}
