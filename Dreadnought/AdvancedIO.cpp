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
		key = Keywords::KEYWORD_NULL;
		std::getline(myFile, stringVar, ',');
		std::transform(stringVar.begin(), stringVar.end(), stringVar.begin(), [](unsigned char c) {return std::tolower(c); });
		stringVar.erase(std::remove_if(stringVar.begin(), stringVar.end(), [](unsigned char x) { return std::isspace(x); }), stringVar.end());

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
		else if (stringVar == "silostatus" || stringVar == "launcherstatus")
			key = Keywords::Silo_Status;
		else if (stringVar == "loadmissile")
			key = Keywords::Load_Missile;
		else if (stringVar == "antishipmissile" || stringVar == "antishiptorpedo" || stringVar == "supersoniccruisemissile"
			|| stringVar == "cruisemissile")
			key = Keywords::Missile;
		else if (stringVar == "navalbattery" || stringVar == "navalbattery250mm" || stringVar == "navalbattery250" || stringVar == "navalbattery400"
			|| stringVar == "navalbattery400mm" || stringVar == "naval" || stringVar == "battery")
			key = Keywords::Naval_Battery;
		else if (stringVar == "missile" || stringVar == "missilelauncher" || stringVar == "launcher")
			key = Keywords::Missile_Launcher;
		else if (stringVar == "armmissile")
			key = Keywords::Arm_Missile;

		keywordMap.insert({ stringVar, key });
	}

	myFile.close();
}

