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

void AdvancedIO::PrintCursorPos()
{
	POINT point;
	if (GetCursorPos(&point)) {
		std::cout << point.x << "," << point.y << "\n";
	}
}

