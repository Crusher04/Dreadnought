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

void ConsoleFormatting::Pause()
{
	SetColour(15);
	std::cout << std::endl;
	system("pause");
}

void ConsoleFormatting::SetConsoleCursorPos(COORD pos)
{
	SetConsoleCursorPosition(hConsole, pos);
}

void ConsoleFormatting::ScrollToTop() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
