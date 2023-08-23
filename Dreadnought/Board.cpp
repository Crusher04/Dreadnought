#include "Board.h"
#include "ConsoleFormatting.h"

ConsoleFormatting cFormat;

Board::Board() :boardX(20), boardY(20)
{
	if (!hasBeenGenerated)
		hasBeenGenerated = Generate();
	else
		std::cout << "\n ** BOARD ALREADY GENERATED ** \n";
}

bool Board::Generate()
{

	return true;
}

void Board::Display(int actorX, int actorY, int aiX, int aiY)
{
	int yCounter = 0;
	//std::cout.width(20);
	cFormat.SetColour(14);
	std::cout << "\t\t\t    MAP";
	std::cout << "\n";

	while (yCounter < boardY)
	{
		for (int i = 0; i < boardX; i++)
		{
			if (actorX == i && actorY == yCounter)
			{
				cFormat.SetColour(27);
				std::cout << " 0 ";
			}
			else if (aiX == i && aiY == yCounter)
			{
				cFormat.SetColour(28);
				std::cout << " 0 ";
			}
			else
			{
				cFormat.SetColour(16);
				std::cout << " ~ ";
			}
			

		}
		cFormat.SetColour(15);
		std::cout << "\n";
		yCounter++;
	}
	cFormat.SetColour(15); 
}
