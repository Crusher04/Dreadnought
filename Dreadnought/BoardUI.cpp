#include "BoardUI.h"
#include "ConsoleFormatting.h"
#include "RadarComponent.h"

ConsoleFormatting cFormat;

BoardUI::BoardUI() 
{
	//Initialize Variables
	boardSize[0] = 75;
	boardSize[1] = 25;
	chunkDefault[0] = boardSize[0];
	chunkDefault[1] = boardSize[1];
	chunkPosition[0] = 1;
	chunkPosition[1] = 1;
}

void BoardUI::MovePlayer(Battleship* player, MovementDirection direction)
{

	Render();
}

void BoardUI::Render()
{	
	//space 
	char space = 32;
	std::cout << "\t\t\t MAP \n\t\t\t-----"; 

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

	cFormat.SetColour(7);


	std::cout << "\n";
}

