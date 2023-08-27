#include "SceneGame.h"

SceneGame::SceneGame(GameManager* game_)
{
	// Providing a seed value
	std::srand((unsigned)time(NULL));

	game = game_;

	if (!playerOne.Initialize(ActorType::PLAYER))
	{
		InitializePlayer();
	}

}

void SceneGame::GetUserInput()
{
	/*
	* Basic user input to accept only keywords. No filtration system, wont find keywords in a mess of a sentence like ' asjflasjj quit '
	*/
	

	cFormat.SetColour(14);
	std::cout << "\nCOMMAND-> ";
	std::cin >> userInput;
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
	cFormat.SetColour(15);

	//Check for help
	if (userInput.compare("help") == 0)
	{
		cFormat.SetColour(6);
		std::cout << "\t-------------\n"
			<< "\tKeywords\n"
			<< "\t-------------\n";
		cFormat.SetColour(15);
		std::cout << "*Quit/Exit:\t to Exit the game.\n"
			<< "*Board:\t\t to display the board.\n"
			<< "*Move:\t\t to move ship in a direction\n"
			<< "*Back:\t\t to cancel *Move* command\n"
			<< "*Attack:\t\t Shows attack options\n"
			<< "*End:\t\t Ends the turn\n";


		helpFlag = true;
	}
	else if (userInput.compare("board") == 0)
	{
		//theBoard.Display();
		helpFlag = false;
	}
	//Check for terminating characters
	else if (userInput.compare("quit") == 0 || userInput.compare("exit") == 0)
	{
		cFormat.SetColour(10);
		std::cout << "\n **Thanks For Playing! Goodbye!**\n";
		game->SetGameActive(false);
		cFormat.SetColour(15);

	}
	else if (userInput.compare("move") == 0)
	{
		cFormat.SetColour(15);
		moveFlag = true;

		while (moveFlag)
		{
			std::cout << std::endl;
			if (playerOne.GetMovement() != 0)
				std::cout << "Where would you like to move? (LEFT, RIGHT, UP, DOWN)";

			cFormat.SetColour(14);
			std::cout << "\n\nMOVE COMMAND-> ";
			std::cin >> userInput;
			std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
			cFormat.SetColour(15);

			if (moveFlag && userInput.compare("left") == 0 || userInput.compare("right") == 0 || userInput.compare("up") == 0 || userInput.compare("down") == 0 || userInput.compare("back") == 0)
			{

				if (moveFlag && userInput.compare("left") == 0)
					moveFlag = playerOne.Move(MovementDirection::LEFT, ActorType::PLAYER);
				else if (moveFlag && userInput.compare("right") == 0)
					moveFlag = playerOne.Move(MovementDirection::RIGHT, ActorType::PLAYER);
				else if (moveFlag && userInput.compare("up") == 0)
					moveFlag = playerOne.Move(MovementDirection::UP, ActorType::PLAYER);
				else if (moveFlag && userInput.compare("down") == 0)
					moveFlag = playerOne.Move(MovementDirection::DOWN, ActorType::PLAYER);
				else if (moveFlag && userInput.compare("back") == 0)
					moveFlag = false;

				if (helpFlag)
					helpFlag = false;

			}
			else if (userInput.compare("move") == 0)
			{
				cFormat.SetColour(64);
				std::cout << "\t\t**ERROR: MOVE Command Already Initialized!**";
				cFormat.SetColour(15);
				std::cout << "\n";
			}
			else
			{
				cFormat.SetColour(64);
				std::cout << "\t\t**ERROR: Unrecognized keyword!**";
				cFormat.SetColour(15);
				std::cout << "\n";
			}
		}
	}
	else if (userInput.compare("attack") == 0)
	{
		helpFlag = true;
		//Check Attack Range
		int xRange = playerOne.GetPositionX() - playerAI.GetPositionX();
		if (xRange < 0)
			xRange *= -1;
		int yRange = playerOne.GetPositionY() - playerAI.GetPositionY();
		if (yRange < 0)
			yRange *= -1;
		if (xRange <= 4 && yRange <= 4 && playerOne.GetAction())
		{
			playerOne.TakeAction();
			Attack(playerOne, ActorType::AI);
		}
		else if (!playerOne.GetAction())
		{
			std::cout << "\n No Actions left!\n ";
		}
		else
		{
			std::cout << "\n No Enemy Ships in Range\n ";
		}


	}
	else if (userInput.compare("end") == 0)
	{
		endTurn = playerOne.EndOfTurn();
	}
	else
	{
		cFormat.SetColour(64);
		std::cout << "\t\t**ERROR: Unrecognized keyword!**";
		helpFlag = true;
		cFormat.SetColour(15);
		std::cout << "\n";
	}







}


SceneGame::~SceneGame()
{
	OnDestroy();
}

bool SceneGame::OnCreate()
{
	return true;
}

void SceneGame::OnDestroy()
{
	if (game->IsGameActive() == false && game != nullptr)
	{
		game = nullptr;
		delete game;
	}
	else if (game != nullptr)
		game = nullptr;
}


void SceneGame::Update()
{
	std::cout << std::endl;

	if (playerOne.GetHealth() <= 0)
	{
		cFormat.SetColour(12);
		std::cout << "\n\n\t ** YOU LOSE. GAME OVER! ** \n";
		game->SetGameActive(false);
		cFormat.PauseAfterAction();
		return;
	}

	if (playerAI.GetHealth() <= 0)
	{
		cFormat.SetColour(10);
		std::cout << "\n\n\t ** YOU WIN. CONGRATULATIONS! ** \n";
		game->SetGameActive(false);
		cFormat.PauseAfterAction();
		return;
	}

	if (!helpFlag && !moveFlag)
	{
		cFormat.ClearScreen();
		theBoard.Display(playerOne.GetPositionX(), playerOne.GetPositionY(), playerAI.GetPositionX(), playerAI.GetPositionY());

		playerOne.RenderUI(playerAI.GetPositionX(), playerAI.GetPositionY(), playerAI.GetHealth(), playerAI.GetShipName());
	}

	if (!endTurn)
		GetUserInput();

	if (playerOne.GetHealth() <= 0)
	{
		cFormat.SetColour(12);
		std::cout << "\n\n\t ** YOU LOSE. GAME OVER! ** \n";
		game->SetGameActive(false);
		cFormat.PauseAfterAction();
		return;
	}

	if (playerAI.GetHealth() <= 0)
	{
		cFormat.SetColour(10);
		std::cout << "\n\n\t ** YOU WIN. CONGRATULATIONS! ** \n";
		game->SetGameActive(false);
		cFormat.PauseAfterAction();
		return;
	}

	if (endTurn)
	{
		//AI
		//Check Attack Range
		int xRange = playerOne.GetPositionX() - playerAI.GetPositionX();
		if (xRange < 0)
			xRange *= -1;
		int yRange = playerOne.GetPositionY() - playerAI.GetPositionY();
		if (yRange < 0)
			yRange *= -1;
		if (xRange <= 4 && yRange <= 4)
		{
			Attack(playerAI, ActorType::PLAYER);
			playerAI.EndOfTurn();
			endTurn = false;
			return;
		}

		aiOldPosFlag = true;
		// Providing a seed value
		while (playerAI.GetMovement() > 0 && aiOldPosFlag)
		{

			int oldPOS[2] = { playerAI.GetPositionX(), playerAI.GetPositionY() };
			int psuedoNum = rand() % 2;

			while (psuedoNum < 1 || psuedoNum > 2)
				psuedoNum = rand() % 2;

			if (playerAI.GetPositionY() == 19)
			{
				if (playerAI.GetPositionX() == 0)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::UP, ActorType::AI);
						break;
					case 2:
						playerAI.Move(MovementDirection::RIGHT, ActorType::AI);
						break;
					};
				}
				else if (playerAI.GetPositionX() == 19)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::UP, ActorType::AI);
						break;
					case 2:
						playerAI.Move(MovementDirection::LEFT, ActorType::AI);
						break;
					};
				}
				else
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::UP, ActorType::AI);
						break;
					case 2:
						int lastNum = psuedoNum;
						psuedoNum = rand() % 2;
						while (psuedoNum == lastNum && psuedoNum < 1 || psuedoNum > 2)
							psuedoNum = rand() % 2;
						if (psuedoNum == 1)
							playerAI.Move(MovementDirection::LEFT, ActorType::AI);
						else
							playerAI.Move(MovementDirection::RIGHT, ActorType::AI);
						break;
					};
				}

			}
			else if (playerAI.GetPositionY() == 0)
			{
				if (playerAI.GetPositionX() == 0)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::DOWN, ActorType::AI);
						break;
					case 2:
						playerAI.Move(MovementDirection::RIGHT, ActorType::AI);
						break;
					};
				}
				else if (playerAI.GetPositionX() == 19)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::DOWN, ActorType::AI);
						break;
					case 2:
						playerAI.Move(MovementDirection::LEFT, ActorType::AI);
						break;
					};
				}
				else
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(MovementDirection::DOWN, ActorType::AI);
						break;
					case 2:
						int lastNum = psuedoNum;
						psuedoNum = rand() % 2;
						while (psuedoNum == lastNum && psuedoNum < 1 || psuedoNum > 2)
							psuedoNum = rand() % 2;
						if (psuedoNum == 1)
							playerAI.Move(MovementDirection::LEFT, ActorType::AI);
						else
							playerAI.Move(MovementDirection::RIGHT, ActorType::AI);
						break;
					};
				}
			}
			else
			{
				psuedoNum = rand() % 4;
				while (psuedoNum < 1 || psuedoNum > 2)
					psuedoNum = rand() % 4;

				switch (psuedoNum)
				{
				case 1:
					playerAI.Move(MovementDirection::DOWN, ActorType::AI);
					break;
				case 2:
					playerAI.Move(MovementDirection::LEFT, ActorType::AI);
					break;
				case 3:
					playerAI.Move(MovementDirection::RIGHT, ActorType::AI);
					break;
				case 4:
					playerAI.Move(MovementDirection::UP, ActorType::AI);
					break;
				};
			}

			if (playerAI.GetMovement() <= 0 && oldPOS[0] != playerAI.GetPositionX() || oldPOS[1] != playerAI.GetPositionY())
				aiOldPosFlag = false;
		}

		playerAI.EndOfTurn();
		endTurn = false;
	}


}

void SceneGame::Attack(Battleship friendly, ActorType actor)
{
	helpFlag = true;

	if (actor == ActorType::PLAYER)
		std::cout << "\n**ATTACK INCOMING**\n";
	else
		std::cout << "\n**ATTACKING ENEMY**\n";

	cFormat.SetColour(14);
	int fNum = -1;
	int eNum = -1;
	std::cout << "\nAttacker Roll ";
	fNum = RandomNumber(DiceType::D20, 0);

	cFormat.SetColour(14);
	std::cout << "\nDefender Roll ";
	eNum = RandomNumber(DiceType::D20, fNum);


	cFormat.SetColour(15);


	if (friendly.GetShipChoice() == Ships::Dreadnought)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(DiceType::D6, 0)) + (RandomNumber(DiceType::D6, fNum));

			if (actor == ActorType::PLAYER)
			{
				cFormat.SetColour(12);
				std::cout << "** TAKING DAMAGE: " << fNum << "\n";
				playerOne.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
			else
			{
				cFormat.SetColour(10);
				std::cout << "** Attacking Enemy: " << fNum << "\n";
				playerAI.TakeDamage(fNum);
				cFormat.SetColour(15);
			}

		}
		else
		{
			cFormat.SetColour(15);
			std::cout << "\n **MISSED**";
		}
	}
	if (friendly.GetShipChoice() == Ships::SunkenLady)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(DiceType::D12, 0));
			if (actor == ActorType::PLAYER)
			{
				cFormat.SetColour(12);
				std::cout << "** TAKING DAMAGE: " << fNum << "\n";
				playerOne.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
			else
			{
				cFormat.SetColour(10);
				std::cout << "** Attacking Enemy: " << fNum << "\n";
				playerAI.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
		}
		else
		{
			cFormat.SetColour(15);
			std::cout << "\n **MISSED**\n";
		}
	}
	if (friendly.GetShipChoice() == Ships::Idris)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(DiceType::D6, 0) + RandomNumber(DiceType::D6, fNum) + RandomNumber(DiceType::D6, fNum));
			if (actor == ActorType::PLAYER)
			{
				cFormat.SetColour(12);
				std::cout << "** TAKING DAMAGE: " << fNum << "\n";
				playerOne.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
			else
			{
				cFormat.SetColour(10);
				std::cout << "** Attacking Enemy: " << fNum << "\n";
				playerAI.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
		}
		else
		{
			cFormat.SetColour(15);
			std::cout << "\n **MISSED**\n";
		};
	}
	if (friendly.GetShipChoice() == Ships::SuperNova)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = RandomNumber(DiceType::D20, 0);
			if (actor == ActorType::PLAYER)
			{
				cFormat.SetColour(12);
				std::cout << "** TAKING DAMAGE: " << fNum << " damage.\n";
				playerOne.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
			else
			{
				cFormat.SetColour(10);
				std::cout << "** Attacking Enemy: " << fNum << " damage.\n";
				playerAI.TakeDamage(fNum);
				cFormat.SetColour(15);
			}
		}
		else
		{
			cFormat.SetColour(15);
			std::cout << "\n **MISSED**\n";
		}
	}

	cFormat.PauseAfterAction();
}

int SceneGame::RandomNumber(DiceType dice, int lastNum)
{

	int range = -1;

	switch (dice) {
	case DiceType::D4:
		range = 4;
		cFormat.SetColour(14);
		std::cout << "\n\t ** D4 ROLL **";
		cFormat.SetColour(15);
		break;
	case DiceType::D6:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D6 ROLL **";
		cFormat.SetColour(15);
		range = 6;
		break;
	case DiceType::D8:
		cFormat.SetColour(14);
		std::cout << "\n\t** D8 ROLL **";
		cFormat.SetColour(15);
		range = 8;
		break;
	case DiceType::D10:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D10 ROLL **";
		cFormat.SetColour(15);
		range = 10;
		break;
	case DiceType::D12:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D12 ROLL **";
		cFormat.SetColour(15);
		range = 12;
		break;
	case DiceType::D20:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D20 ROLL **";
		cFormat.SetColour(15);
		range = 20;
		break;
	default:
		std::cout << "ERROR SELECTING DICE";
		break;
	}


	// Get a random number
	int psuedoNum = (1 + (rand() % range));
	while (psuedoNum == lastNum)
		psuedoNum = (1 + (rand() % range));

	cFormat.SetColour(14);
	std::cout << "\n\t ROLLED: " << psuedoNum << "\n";
	cFormat.SetColour(15);

	return psuedoNum;
}

void SceneGame::InitializePlayer()
{
	RunIntro();

	while (!playerOne.Initialize(ActorType::PLAYER))
	{
		cFormat.SetColour(15);
		std::string shipDesc;
		std::ifstream myFile("shipDesc.txt");


		std::cout << "CHOOSE YOUR SHIP: \n";

		while (std::getline(myFile, shipDesc))
		{
			std::cout << shipDesc << "\n";
		}
		myFile.close();

		cFormat.SetColour(14);
		std::cout << "\n\n-> ";
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
		cFormat.SetColour(15);

		if (userInput.compare("dreadnought") == 0)
		{
			playerOne.ChooseShip(Ships::Dreadnought);
		}
		else if (userInput.compare("sunkenlady") == 0)
		{
			playerOne.ChooseShip(Ships::SunkenLady);
		}
		else if (userInput.compare("idris") == 0)
		{
			playerOne.ChooseShip(Ships::Idris);
		}
		else if (userInput.compare("supernova") == 0)
		{
			playerOne.ChooseShip(Ships::SuperNova);
		}
		//Check for terminating characters
		else if (userInput.compare("quit") == 0 || userInput.compare("exit") == 0)
		{
			cFormat.SetColour(10);
			std::cout << "\n **Thanks For Playing! Goodbye!**\n";
			if (game->IsGameActive())
				game->SetGameActive(false);
			cFormat.SetColour(10);
			break;
		}

	}
	std::srand((unsigned)time(NULL));
	int psuedoNum = (rand() % 3);
	playerAI.Initialize(ActorType::AI);
	switch (psuedoNum)
	{
	case 0:
		playerAI.ChooseShip(Ships::Dreadnought);
		break;
	case 1:
		playerAI.ChooseShip(Ships::SunkenLady);
		break;
	case 2:
		playerAI.ChooseShip(Ships::Idris);
		break;
	case 3:
		playerAI.ChooseShip(Ships::SuperNova);
		break;
	default:
		playerAI.ChooseShip(Ships::UNDEFINEDSHIP);
		break;
	}

	playerOne.Spawn();
	playerAI.Spawn();
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

	cFormat.PauseAfterAction();
	cFormat.ClearScreen();

}

