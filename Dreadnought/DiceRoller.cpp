#include "DiceRoller.h"
#include <stdlib.h>
#include <iostream>
int DiceRoller::RollDice(DiceType dice)
{
	int roll = 0;

	switch (dice)
	{
	case DiceType::D4:
		roll = (rand() % 4 + 1);
		std::cout << "Dice D4 Roll = : " << roll << "\n";
		return roll;
		break;
	case DiceType::D6:
		roll = (rand() % 6 + 1);
		std::cout << "Dice D6 Roll = : " << roll << "\n";
		return roll;
		break;
	case DiceType::D8:
		roll = (rand() % 8 + 1);
		std::cout << "Dice D8 Roll = : " << roll << "\n";
		return roll;
		break;
	case DiceType::D10:
		roll = (rand() % 10 + 1);
		std::cout << "Dice D10 Roll = : " << roll << "\n";
		return roll;
		break;
	case DiceType::D12:
		roll = (rand() % 12 + 1);
		std::cout << "Dice D12 Roll = : " << roll << "\n";
		return roll;
		break;
	case DiceType::D20:
		roll = (rand() % 20 + 1);
		std::cout << "Dice D20 Roll = : " << roll << "\n";
		return roll;
		break;
	}
}
