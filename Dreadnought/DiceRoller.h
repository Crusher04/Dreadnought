#pragma once
#include "Enums.h"
class DiceRoller
{
protected:

public:

	DiceRoller() = default;
	~DiceRoller() = default;

	int RollDice(DiceType dice);

};

