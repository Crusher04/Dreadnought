#include "SceneGame.h"
#include "Enums.h"

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
		

	return true;
}

void SceneGame::OnDestroy()
{

}

void SceneGame::Update()
{
	//Select starter ship once
	while(!starterShpSelected)
		SelectStarterShip();

	//Always pull updates to battleship from components
	player->UpdateFromComponents();


	cFormat.Pause();
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
		//Set Ship Type
		player->SetShipType(Ships::Dreadnought);

		//Components
		player->AddComponent<EngineComponent>(EngineType::EV20);
		player->AddComponent<RadarComponent>(Subsystems::STANDARD_RADAR);
		player->AddComponent<CommandCenterComponent>();
		player->GetComponent<CommandCenterComponent>()->OnCreate(50, 0, 250, 0);
		player->AddComponent<MissileStorageComponent>(Subsystems::MISSILE_STORAGE_15);
		player->UpdateFromComponents();	//IF you dont update battleship capacities the missiles wont be added!!
		
		for (int i = 0; i < 10; i++)
			player->AddComponent<MissileComponent>(Armament::AntiShipMissile);

		player->AddComponent<NavalBatteriesComponent>(Armament::NavalBattery250mm, 2);

		player->UpdateFromComponents(); //Final update check.


		//DEBUG ONLY. SET TO FALSE FOR PRODUCTION RELEASE.
		if (true)
		{
			std::cout << "\n DEBUG CHECKS: \n"
				<< "Engine Type: " << player->GetComponent<EngineComponent>()->GetMovement() << "\n"
				<< "Radar Distance: " << player->GetComponent<RadarComponent>()->GetRadarDistance() << "\n"
				<< "Health Amount: " << player->GetComponent<CommandCenterComponent>()->GetHealth() << "\n"
				<< "Armour amount: " << player->GetComponent<CommandCenterComponent>()->GetArmour() << "\n"
				<< "Money Amount: " << player->GetComponent<CommandCenterComponent>()->GetMoney() << "\n"
				<< "ADS Defense: " << player->GetComponent<CommandCenterComponent>()->GetADSDefence() << "\n";

			player->PrintCapacities();
			player->ListComponents();

		}
		
		//STARTER SHIP SELECTED
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
	
	
}
