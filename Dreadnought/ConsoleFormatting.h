#pragma once
#include <conio.h>
#include <windows.h>
#include <iostream>

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

	/// <summary>
	/// Pauses CMD and waits for user to press a button.
	/// </summary>
	void Pause();

	/// <summary>
	/// Sets Console Cursor position
	/// </summary>
	/// <param name="pos"></param>
	void SetConsoleCursorPos(COORD pos);
	
	/// <summary>
	/// Resets Colour to white on black.
	/// </summary>
	void ResetColour();

	void ScrollToTop();

private:
	HANDLE  hConsole;

};

