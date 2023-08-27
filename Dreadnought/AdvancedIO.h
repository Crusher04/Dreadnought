#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

class AdvancedIO
{
public:
	AdvancedIO() = delete;
	~AdvancedIO() = delete;

	void GetUserInput(std::string& userInput_);
	void PrintFromFile(std::string filename);

};

