#pragma once
#include <windows.h>
class ConsoleFormatting
{
public:
	ConsoleFormatting();
	void SetColour(int colour);
	
	HANDLE  hConsole;

};

