#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <unordered_map>
#include "Enums.h"

class AdvancedIO
{
protected:
	std::string keywords[5] = { "menu", "quit", "exit", "help", "back" };
public:
	AdvancedIO() = default;
	~AdvancedIO() = default;

	void GetUserInput(std::string& userInput_);
	void PrintFromFile(std::string filename);
	void PrintFromFile(std::string filename, bool csvFile);
	void PrintCursorPos();
	void ReadKeywordFileToUMap(std::unordered_map<std::string, Keywords> &keywordMap, std::string filename);
	void ReadCommandsFileToUMap(std::unordered_map<Commands, std::string>& commandsMap);
	void PrintFromUMap (std::unordered_map<std::string, Keywords> &uMap);
};

