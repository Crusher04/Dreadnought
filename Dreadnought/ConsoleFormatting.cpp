#include "ConsoleFormatting.h"
/*
* Programmer:		Ahmed Hammoud
* This class is to do with anything that formats the console view; Colouring, Advanced Spacing, Pausing, etc. 
*/

ConsoleFormatting::ConsoleFormatting()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleFormatting::SetColour(int colour)
{
	SetConsoleTextAttribute(hConsole, colour);
}

void ConsoleFormatting::ClearScreen()
{
	system("cls");
	
}

void ConsoleFormatting::PauseAfterAction()
{
	SetColour(15);
	std::cout << std::endl;
	system("pause");
}
