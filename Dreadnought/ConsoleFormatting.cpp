#include "ConsoleFormatting.h"


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
