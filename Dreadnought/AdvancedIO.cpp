#include "AdvancedIO.h"

void AdvancedIO::GetUserInput(std::string &userInput_)
{
	std::getline(std::cin, userInput_);

	//Set input string to lower case and clear white spaces. 
	std::transform(userInput_.begin(), userInput_.end(), userInput_.begin(), [](unsigned char c) {return std::tolower(c); });
	userInput_.erase(std::remove_if(userInput_.begin(), userInput_.end(), [](unsigned char x) { return std::isspace(x); }), userInput_.end());

}

void AdvancedIO::PrintFromFile(std::string filename)
{
	std::string stringVar;
	std::ifstream myFile(filename);
	while (std::getline(myFile, stringVar))
	{
		std::cout << stringVar << "\n";
	}
	myFile.close();

}

void AdvancedIO::PrintFromFile(std::string filename, bool csvFile)
{
	std::string stringVar;
	std::ifstream myFile(filename);
	while (!myFile.eof())
	{
		std::getline(myFile, stringVar, ',');
		std::cout << stringVar << "\n";
	}
	myFile.close();
}

void AdvancedIO::PrintCursorPos()
{
	POINT point;
	if (GetCursorPos(&point)) {
		std::cout << point.x << "," << point.y << "\n";
	}
}

void AdvancedIO::PrintFromUMap(std::unordered_map<std::string, Keywords> &uMap)
{
	for (auto i : uMap)
		std::cout << "\n" << i.first << "\n";
}

void AdvancedIO::ReadFileToUMap(std::unordered_map<std::string, Keywords> &keywordMap, std::string filename)
{
	std::string stringVar;
	std::ifstream myFile(filename);
	Keywords key;

	while (!myFile.eof())
	{
		std::getline(myFile, stringVar, ',');
		
		if (stringVar == "quit" || stringVar == "exit")
			key = Keywords::Quit;
		else if (stringVar == "help")
			key = Keywords::Help;
		else if (stringVar == "menu")
			key = Keywords::Menu;
		else if (stringVar == "back")
			key = Keywords::Back;
		else if (stringVar == "attack")
			key = Keywords::Attack;
		else if (stringVar == "move")
			key = Keywords::Move;
		else if (stringVar == "silostatus")
			key = Keywords::Silo_Status;

		keywordMap.insert({ stringVar, key });
	}

	myFile.close();
}

