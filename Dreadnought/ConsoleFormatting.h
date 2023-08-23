#pragma once
#include <conio.h>
#include <windows.h>


class ConsoleFormatting
{
public:
	/// <summary>
	/// Constuctor to initialize handle variable.
	/// </summary>
	ConsoleFormatting();

	/// <summary>
	/// Sets the colour of the console before printing.
	/// </summary>
	/// <param name="colour"></param>
	void SetColour(int colour);

	/// <summary>
	/// Clears the console screen
	/// </summary>
	void ClearScreen();

private:
	HANDLE  hConsole;

};

