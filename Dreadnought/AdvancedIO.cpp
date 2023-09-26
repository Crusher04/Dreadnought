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

void AdvancedIO::ReadKeywordFileToUMap(std::unordered_map<std::string, Keywords> &keywordMap, std::string filename)
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
		else if (stringVar == "back" || stringVar == "cancel")
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
		else if (stringVar == "missile" || stringVar == "missilelauncher" || stringVar == "launcher" || stringVar == "attacklauncher"
			|| stringVar == "launchmissile")
			key = Keywords::Missile_Launcher;
		else if (stringVar == "armmissile")
			key = Keywords::Arm_Missile;
		else if (stringVar == "commands")
			key = Keywords::Commands;

		keywordMap.insert({ stringVar, key });
	}

	myFile.close();
}

void AdvancedIO::ReadCommandsFileToUMap(std::unordered_map<std::string, Commands> &commandsMap)
{
	std::string stringVar;
	std::ifstream myFile("TextFiles/commands.txt");
	Keywords command;

	//Combs through the commands.txt file and assings the details to the command
	//Must have the if statements in order of the file commands
	while (!myFile.eof())
	{
		command = Keywords::KEYWORD_NULL;
		std::getline(myFile, stringVar, '*');

		if (stringVar == "move")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Move });
			
		}
		else if (stringVar == "attack")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Attack });

		}
		else if(stringVar == "loadmissile")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Load_Missile });

		}
		else if(stringVar == "armmissile")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Arm_Missile });

		}
		else if(stringVar == "silostatus")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Silo_Status });

		}
		else if(stringVar == "endturn")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::End_Turn });

		}
		else if(stringVar=="jets")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Jets });

		}
		else if(stringVar == "colourlegend")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Colour_Legend });

		}
		else if(stringVar == "deployjets")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Deploy_Jets });

		}
		else if(stringVar =="preparedefense")
		{
			std::getline(myFile, stringVar, '*');
			commandsMap.insert({ stringVar, Commands::Prepare_Defense });

		}

	}

	myFile.close();

}

