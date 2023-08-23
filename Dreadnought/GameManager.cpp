#include "GameManager.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include<cstdlib>
#include <time.h> 


GameManager::GameManager()
{
	// Providing a seed value
	std::srand((unsigned)time(NULL));

	if (!gameActive)
		gameActive = true;

	theBoard.Generate();
	Title();
	
	while (!playerOne.Initialize(PLAYER))
	{
		SetConsoleTextAttribute(cFormat.hConsole, 15);
		std::cout << std::left << "To select a ship of choice, type the name of the ship. Choose a ship:";
		std::cout << "\n\nSHIPS\n------\n";
		std::cout << "\nDreadnought: \n------------\n    Movement:\t 20 NM\n    Weapon:\t Dual Canons (1D6 per canon)  (Action)\n    Weapon:\t AA Gun (Good against Missiles) (Adds 1D4 to defence rolls)  (Must Be Prepared) (Bonus Action)\n";
		std::cout << "\nSunkenLady: \n--------------\n    Movement:\t 20 NM\n    Weapon:\t Missles x 15 (1D12)  (Action)\n    Weapon:\t Turrets (1D4)  (Good against close ranged Ships)  (Bonus Action)\n";
		std::cout << "\nIdris: \n------------\n    Movement:\t 20 NM\n    Weapon:\t Triple Canons (1D6 per canon)  (Action)\n    Weapon:\t AA Gun (Good against Missiles)   (Adds 1D4 to defence rolls) (Must Be Prepared) (Bonus Action)\n";
		std::cout << "\nSuperNova: \n------------\n    Movement:\t 20 NM\n    Weapon:\t RailGun (1D20) (MUST BE CHARGED) (Action)\n    Defense:\t Turrets (1D4)  (Good against close ranged ships)  (Bonus Action)\n";


		SetConsoleTextAttribute(cFormat.hConsole, 14);
		std::cout << "\n\n-> ";
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
		SetConsoleTextAttribute(cFormat.hConsole, 15);

		if (userInput.compare("dreadnought") == 0)
		{
			playerOne.ChooseShip(Dreadnought);
		}
		else if (userInput.compare("sunkenlady") == 0)
		{
			playerOne.ChooseShip(SunkenLady);
		}
		else if (userInput.compare("idris") == 0)
		{
			playerOne.ChooseShip(Idris);
		}
		else if (userInput.compare("supernova") == 0)
		{
			playerOne.ChooseShip(SuperNova);
		}
		//Check for terminating characters
		else if (userInput.compare("quit") == 0 || userInput.compare("exit") == 0)
		{
			SetConsoleTextAttribute(cFormat.hConsole, 10);
			std::cout << "\n **Thanks For Playing! Goodbye!**\n";
			gameActive = false;
			SetConsoleTextAttribute(cFormat.hConsole, 15);
			break;
		}
		
	}
	std::srand((unsigned)time(NULL));
	int psuedoNum = (rand() % 3);
	playerAI.Initialize(AI);
	switch (psuedoNum)
	{
	case 0: 
		playerAI.ChooseShip(Dreadnought);
		break;
	case 1:
		playerAI.ChooseShip(SunkenLady);
		break;
	case 2: 
		playerAI.ChooseShip(Idris);
		break;
	case 3:
		playerAI.ChooseShip(SuperNova);
		break;
	default:
		playerAI.ChooseShip(UNDEFINEDSHIP);
		break;
	}
	
	playerOne.Spawn();
	playerAI.Spawn();

	
}

GameManager::~GameManager()
{
	gameActive = false;
}

bool GameManager::Run()
{
	return 	gameActive;

}

void GameManager::Title()
{
	SetConsoleTextAttribute(cFormat.hConsole, 7);
	std::cout << "Welcome To Battleship Combat Simulator!\n"
		<< "---------------------------------------\n"
		<< "To quit the game, type Quit or Exit at anytime, progress does not save!\n"
		<< "Type Help for all keywords.\n"
		<< "Goal of the game is to destroy your opponent! You'll have a choice of ships, each with a specific armament.\n"
		<< "The board is 20x20 and you move one square at a time. \nEach weapon will have a specific dice as damage and you roll to hit with every attack.\n"
		<< "Every turn you have 1 action, 1 bonus action and your movement speed. Good luck!\n"
		<< "---------------------------------------\n\n";
	SetConsoleTextAttribute(cFormat.hConsole, 15);
}

void GameManager::Update()
{
	std::cout << std::endl;
	
	if (playerOne.GetHealth() <= 0)
	{
		cFormat.SetColour(12);
		std::cout << "\n\n\t ** YOU LOSE. GAME OVER! ** \n";
		gameActive = false;
		PauseAfterAction();
		return;
	}

	if (playerAI.GetHealth() <= 0)
	{
		cFormat.SetColour(10);
		std::cout << "\n\n\t ** YOU WIN. CONGRATULATIONS! ** \n";
		gameActive = false;
		PauseAfterAction();
		return;
	}

	if (!helpFlag && !moveFlag)
	{
		theBoard.Display(playerOne.GetPositionX(), playerOne.GetPositionY(), playerAI.GetPositionX(), playerAI.GetPositionY());

		playerOne.RenderUI(playerAI.GetPositionX(), playerAI.GetPositionY(), playerAI.GetHealth(), playerAI.GetShipName());
	}

	if (!endTurn)
		GetUserInput();

	if (playerOne.GetHealth() <= 0)
	{
		cFormat.SetColour(12);
		std::cout << "\n\n\t ** YOU LOSE. GAME OVER! ** \n";
		gameActive = false;
		PauseAfterAction();
		return;
	}

	if (playerAI.GetHealth() <= 0)
	{
		cFormat.SetColour(10);
		std::cout << "\n\n\t ** YOU WIN. CONGRATULATIONS! ** \n";
		gameActive = false;
		PauseAfterAction();
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
			Attack(playerAI, PLAYER);
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
						playerAI.Move(UP, AI);
						break;
					case 2:
						playerAI.Move(RIGHT, AI);
						break;
					};
				}
				else if (playerAI.GetPositionX() == 19)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(UP, AI);
						break;
					case 2:
						playerAI.Move(LEFT, AI);
						break;
					};
				}
				else
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(UP, AI);
						break;
					case 2:
						int lastNum = psuedoNum;
						psuedoNum = rand() % 2;
						while (psuedoNum == lastNum && psuedoNum < 1 || psuedoNum > 2 )
							psuedoNum = rand() % 2;
						if (psuedoNum == 1)
							playerAI.Move(LEFT, AI);
						else
							playerAI.Move(RIGHT, AI);
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
						playerAI.Move(DOWN, AI);
						break;
					case 2:
						playerAI.Move(RIGHT, AI);
						break;
					};
				}
				else if (playerAI.GetPositionX() == 19)
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(DOWN, AI);
						break;
					case 2:
						playerAI.Move(LEFT, AI);
						break;
					};
				}
				else
				{
					switch (psuedoNum)
					{
					case 1:
						playerAI.Move(DOWN, AI);
						break;
					case 2:
						int lastNum = psuedoNum;
						psuedoNum = rand() % 2;
						while (psuedoNum == lastNum && psuedoNum < 1 || psuedoNum > 2)
							psuedoNum = rand() % 2;
						if (psuedoNum == 1)
							playerAI.Move(LEFT, AI);
						else
							playerAI.Move(RIGHT, AI);
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
					playerAI.Move(DOWN, AI);
					break;
				case 2:
					playerAI.Move(LEFT, AI);
					break;
				case 3:
					playerAI.Move(RIGHT, AI);
					break;
				case 4:
					playerAI.Move(UP, AI);
					break;
				};
			}

			if ( playerAI.GetMovement() <= 0 && oldPOS[0] != playerAI.GetPositionX() || oldPOS[1] != playerAI.GetPositionY())
				aiOldPosFlag = false;
		}

		playerAI.EndOfTurn();
		endTurn = false;
	}
	
	

}
	

void GameManager::GetUserInput()
{
	/*
	* Basic user input to accept only keywords. No filtration system, wont find keywords in a mess of a sentence like ' asjflasjj quit '
	*/

	SetConsoleTextAttribute(cFormat.hConsole, 14);
	std::cout << "\nCOMMAND-> ";
	std::cin >> userInput;
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
	SetConsoleTextAttribute(cFormat.hConsole, 15);

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
		SetConsoleTextAttribute(cFormat.hConsole, 10);
		std::cout << "\n **Thanks For Playing! Goodbye!**\n";
		gameActive = false;
		SetConsoleTextAttribute(cFormat.hConsole, 15);

	}
	else if (userInput.compare("move") == 0)
	{
		cFormat.SetColour(15);
		moveFlag = true;

		while (moveFlag)
		{
			if(playerOne.GetMovement() != 0)
			std::cout << "Where would you like to move? (LEFT, RIGHT, UP, DOWN)";

			SetConsoleTextAttribute(cFormat.hConsole, 14);
			std::cout << "\n\nMOVE COMMAND-> ";
			std::cin >> userInput;
			std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](unsigned char c) {return std::tolower(c); });
			SetConsoleTextAttribute(cFormat.hConsole, 15);

			if (moveFlag && userInput.compare("left") == 0 || userInput.compare("right") == 0 || userInput.compare("up") == 0 || userInput.compare("down") == 0 || userInput.compare("back") == 0)
			{
				
				if (moveFlag && userInput.compare("left") == 0)
					moveFlag = playerOne.Move(LEFT, PLAYER);
				else if (moveFlag && userInput.compare("right") == 0)
					moveFlag = playerOne.Move(RIGHT, PLAYER);
				else if (moveFlag && userInput.compare("up") == 0)
					moveFlag = playerOne.Move(UP, PLAYER);
				else if (moveFlag && userInput.compare("down") == 0)
					moveFlag = playerOne.Move(DOWN, PLAYER);
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
			Attack(playerOne, AI);			
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

void GameManager::Attack(Battleship friendly, ActorType actor)
{
	helpFlag = true;

	if (actor == PLAYER)
		std::cout << "\n**ATTACK INCOMING**\n";
	else
		std::cout << "\n**ATTACKING ENEMY**\n";
	
	cFormat.SetColour(14);
	int fNum = -1;
	int eNum = -1;
	std::cout << "\nAttacker Roll ";
	fNum = RandomNumber(D20, 0);
	
	cFormat.SetColour(14);
	std::cout << "\nDefender Roll ";
	eNum = RandomNumber(D20, fNum);

	
	cFormat.SetColour(15);
	

	if (friendly.GetShipChoice() == Dreadnought)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(D6, 0)) + (RandomNumber(D6, fNum));
			
			if (actor == PLAYER)
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
	if (friendly.GetShipChoice() == SunkenLady)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(D12, 0));
			if (actor == PLAYER)
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
	if (friendly.GetShipChoice() == Idris)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = (RandomNumber(D6, 0) + RandomNumber(D6, fNum) + RandomNumber(D6, fNum));
			if (actor == PLAYER)
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
	if (friendly.GetShipChoice() == SuperNova)
	{
		if (fNum > eNum)
		{
			std::cout << "\n** Rolling Damage: \n";
			fNum = RandomNumber(D20, 0);
			if (actor == PLAYER)
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

	PauseAfterAction();
}



int GameManager::RandomNumber(DiceType dice, int lastNum)
{
	
	int range = -1;
	
	switch (dice) {
	case 0:
		range = 4;
		cFormat.SetColour(14);
		std::cout << "\n\t ** D4 ROLL **";
		cFormat.SetColour(15);
		break;
	case 1:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D6 ROLL **";
		cFormat.SetColour(15);
		range = 6;
		break;
	case 2:
		cFormat.SetColour(14);
		std::cout << "\n\t** D8 ROLL **";
		cFormat.SetColour(15);
		range = 8;
		break;
	case 3:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D10 ROLL **";
		cFormat.SetColour(15);
		range = 10;
		break;
	case 4:
		cFormat.SetColour(14);
		std::cout << "\n\t ** D12 ROLL **";
		cFormat.SetColour(15);
		range = 12;
		break;
	case 5:
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
	while(psuedoNum == lastNum)
		psuedoNum = (1 + (rand() % range));

	cFormat.SetColour(14);
	std::cout << "\n\t ROLLED: " << psuedoNum << "\n";
	cFormat.SetColour(15);

	return psuedoNum;
}

void GameManager::PauseAfterAction()
{
	cFormat.SetColour(15);
	moveFlag = false;
	helpFlag = false;
	std::cout << std::endl;
	system("pause");
}
