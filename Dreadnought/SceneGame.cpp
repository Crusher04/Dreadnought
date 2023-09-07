#include "SceneGame.h"
#include "Enums.h"
SceneGame::SceneGame(GameManager* game_)
{
	// Providing a seed value
	std::srand((unsigned)time(NULL));

	game = game_;

	IO.ReadFileToUMap(*keywordsMap, "TextFiles/keywords.csv");
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
	//RESET SCREEN
	cFormat.ClearScreen();

	//Select starter ship once
	while(!starterShpSelected)
		SelectStarterShip();

	//Always pull updates to battleship from components
	player->UpdateFromComponents();

	GetUserInput();
	KeywordSelection();
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
		player->AddComponent<MissileLauncherComponent>(Armament::MissileLauncher_4);


		player->UpdateFromComponents(); //Final update check.


		//DEBUG ONLY. SET TO FALSE FOR PRODUCTION RELEASE.
		if (false)
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

void SceneGame::GetUserInput()
{
	//USER INPUT
	std::cout << "\nCOMMAND -> ";
	IO.GetUserInput(*userInput);
}

void SceneGame::KeywordSelection()
{
	//Variable
	Keywords key = Keywords::KEYWORD_NULL;
	auto  missile = player->GetComponent<MissileComponent>();
	auto launcher = player->GetComponent<MissileLauncherComponent>();
	int missileVectorPosition = 0;

	//Find the keyword
	for (auto i : *keywordsMap)
	{
		if (*userInput == i.first)
		{
			key = i.second;
			break;
		}
	}

	//Filter through keyword actions
	switch (key)
	{
	case Keywords::Quit:
		std::cout << "\n EXIT CONFIRMED. THANKS FOR PLAYING! \n";
		attackFlag = false;
		game->SetGameActive(false);
		return;
		break;
	case Keywords::Menu:
		break;
	case Keywords::Back:
		attackFlag = false;
		return;
		break;
	case Keywords::Attack:
		attackFlag = true;
		PlayerAttack();
		return;
		break;
	case Keywords::Missile_Launcher:
		if (!attackFlag)
			break;
		if (player->GetComponent<MissileComponent>())
		{
			player->ListMissileComponents();
		}
		break;
	case Keywords::Missile:
		break;
	case Keywords::Naval_Battery:
		if (!attackFlag)
			break;
		
		std::cout << "\n";
		if (player->GetComponent<NavalBatteriesComponent>()->GetBatteryType() == Armament::NavalBattery250mm)
		{
			attackFlag = false;
			std::cout << "Naval Battery 250mm Selected! Rolling Damage: \n";
			dRoller.RollDice(player->GetComponent<NavalBatteriesComponent>()->GetDamageDice());
		}
		else if (player->GetComponent<NavalBatteriesComponent>()->GetBatteryType() == Armament::NavalBattery400mm)
		{
			std::cout << "Naval Battery 400mm Selected! Rolling Damage: \n";
			attackFlag = false;
			dRoller.RollDice(player->GetComponent<NavalBatteriesComponent>()->GetDamageDice());
		}
		break;
	case Keywords::Silo_Status:
		if (player->GetComponent<MissileLauncherComponent>() != nullptr)
		{

			player->GetComponent<MissileLauncherComponent>()->GetSiloStatus();

		}
		else
			std::cout << "\n\t YOU DO NOT HAVE A MISSILE LAUNCHER ARMAMENT. \n";

		break;
	LOADMISSILE:
	case Keywords::Load_Missile:
		if (missile != nullptr && launcher != nullptr)
		{
			if (missile->CheckIfLoaded() == false)
			{
				player->GetComponent<MissileLauncherComponent>()->LoadMissile(*missile);
				break;
			}
			else if (player->GetComponent<MissileLauncherComponent>()->GetVacantSiloAmount() > 0)
			{
				missileVectorPosition = player->GetComponentPosition<MissileComponent>();
				player->PushComponentToEnd(missileVectorPosition);
				missile = player->GetComponent<MissileComponent>();
				goto LOADMISSILE;

			}
			else
			{
				std::cout << "\n\t SILOS ARE ALL LOADED.\n";
			}
		}
		break;
	default:
		cFormat.SetColour(12);
		std::cout << "\nCommand Not Recognized\n";
		cFormat.SetColour(7);
		return;
		break;
	}

	cFormat.Pause();
}


void SceneGame::PlayerAttack()
{
	std::unique_ptr<std::string> question = std::make_unique <std::string>();
	std::string delimiter = ",";
	size_t pos = 0;
	std::string token;

	*question = "\nWhat armament would you like to attack with?\n";
	
	player->GetArmamentComponents(*question);
	while ((pos = question->find(delimiter)) != std::string::npos) {
		
		token = question->substr(0, pos);
		TypeWrite(token, 5);
		question->erase(0, pos + delimiter.length());
		std::cout << std::endl;
	}
	
	while (attackFlag)
	{
		GetUserInput();
		KeywordSelection();
	}
}

void SceneGame::TypeWrite(std::string s, int speed)
{
	for (int i = 0; i < s.length(); i++)
	{
		std::cout << s[i];
		Sleep(speed);
	}

}
