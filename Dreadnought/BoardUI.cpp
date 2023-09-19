#include "BoardUI.h"
#include "ConsoleFormatting.h"
#include "RadarComponent.h"
#include "CommandCenterComponent.h"
#include "EngineComponent.h"
#include "MissileLauncherComponent.h"

ConsoleFormatting cFormat;

BoardUI::BoardUI() 
{
	//Initialize Variables
	boardSize[0] = 92;
	boardSize[1] = 25;
	chunkDefault[0] = boardSize[0];
	chunkDefault[1] = boardSize[1];
	chunkPosition[0] = 1;
	chunkPosition[1] = 1;
}

void BoardUI::Render(Battleship* player)
{	
	//Header
	std::cout << "\t\t\t MAP \n\t\t\t-----"; 

	//Print out the board
	for (int i = 0; i < boardSize[1]; i++)
	{
		cFormat.SetColour(7);
		std::cout << "\n";
		for (int i = 0; i < boardSize[0]; i++)
		{
			cFormat.SetColour(23);
			std::cout << "~";
		}
	}

	//Set Colour back to normal, new line
	cFormat.SetColour(7);
	std::cout << "\n";
	
	
	//Top Border for UI
	for (int i = 0; i < boardSize[0]; i++)
		std::cout << "-";

	//Print ship name

	std::cout << "\nShip Name: " << player->GetShipName();

	/* **** Health **** */	
	std::cout << " | Health: ";
	
	int maxHealth = player->GetComponent<CommandCenterComponent>()->GetMaxHealth();
	int health = player->GetComponent<CommandCenterComponent>()->GetHealth();
	
	if ((maxHealth / health) < 2)
	{
		cFormat.SetColour(7);
		std::cout << health;
	}
	else if ((maxHealth / health) < 4)
	{
		cFormat.SetColour(14);
		std::cout << health;
		
	}
	else
	{
		cFormat.SetColour(12);
		std::cout << health;
	}

	//Reset Colour to white
	cFormat.SetColour(7);

	//Movement
	std::cout << " | Movement: " << player->GetComponent<EngineComponent>()->GetMovement();

	if (player->GetComponent<MissileLauncherComponent>().get() != nullptr)
	{
		//Silo Status
		std::cout << "| Silo Status: "; 

		int amountOfSilos = player->GetComponent<MissileLauncherComponent>()->GetSiloMaxSize();
		for (int i = 0; i < amountOfSilos; i++)
		{
			if (player->GetComponent<MissileLauncherComponent>()->GetSiloUMAP().at(i) != "")
			{
				for (int j = 0; j < player->GetAmountOfComponents<MissileComponent>(); j++)
				{
					if (player->GetComponent<MissileComponent>()->GetSiloNumber() == i)
					{
						if (player->GetComponent<MissileComponent>()->GetArmedStatus())
						{
							cFormat.SetColour(12);
							std::cout << 0;
							cFormat.SetColour(7);
						}
						else if(player->GetComponent<MissileComponent>()->CheckIfLoaded())
						{
							cFormat.SetColour(10);
							std::cout << 0;
							cFormat.SetColour(7);
						}
						break;
					}
					else
					{
						auto missilePOS = player->GetComponentPosition<MissileComponent>();
						player->PushComponentToEnd(missilePOS);

					}
				}
			}
			else
			{
				cFormat.SetColour(7);
				std::cout << 0;
			}
		}

		//Show missile quantity
		cFormat.SetColour(7);
		std::cout << " | Missile Quantity: " << player->GetAmountOfComponents<MissileComponent>();
	}
		

	//NEW LINE
	std::cout << "\n";

	//Actions
	std::cout << "Action: ";
	if (player->GetComponent<CommandCenterComponent>()->GetAction())
	{
		cFormat.SetColour(10);
		std::cout << " AVAILABLE";
	}
	else
	{
		cFormat.SetColour(12);
		std::cout << " NOT AVAILABLE";

	}

	//Reset colour
	cFormat.SetColour(7);

	//Bonus Actions
	std::cout << " | Bonus Action: ";
	if (player->GetComponent<CommandCenterComponent>()->GetBonusAction())
	{
		cFormat.SetColour(10);
		std::cout << " AVAILABLE";
	}
	else
	{
		cFormat.SetColour(12);
		std::cout << " NOT AVAILABLE";

	}

	//Reset colour
	cFormat.SetColour(7);


	//Bottom Border for UI
	std::cout << "\n";
	for (int i = 0; i < boardSize[0]; i++)
		std::cout << "-";
}

