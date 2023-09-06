#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <unordered_map>

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
	void ReadFileToUMap(std::unordered_map<std::string, bool> &keywordMap, std::string filename);
	void PrintFromUMap (std::unordered_map<std::string, bool> &uMap);
};

