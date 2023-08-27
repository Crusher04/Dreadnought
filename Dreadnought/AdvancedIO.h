#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>

class AdvancedIO
{
public:
	AdvancedIO() = default;
	~AdvancedIO() = default;

	void GetUserInput(std::string& userInput_);
	void PrintFromFile(std::string filename);
	void PrintCursorPos();

};

