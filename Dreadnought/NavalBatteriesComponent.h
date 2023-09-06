#pragma once
#include "Component.h"
class NavalBatteriesComponent : public Component
{
protected:

	//Class Variables
	Armament batteryType;
	int rangeOfAttack;
	int diceMultiplier;
	DiceType damageDice;
	
public:

	/// <summary>
	/// Naval Battery Constructor. Pass through Naval Battery type and how many cannons it has:
	/// Single(1), Dual(2), Triple(3) or Quad(4). 400mm should not be quad. 
	/// </summary>
	/// <param name="batteryType_"></param>
	/// <param name="canonVariant"></param>
	NavalBatteriesComponent(Armament batteryType_, int canonVariant);
	~NavalBatteriesComponent();

	//Getters
	
	/// <summary>
	/// Gets the Damage Dice
	/// </summary>
	/// <returns> damageDice of DiceType</returns>
	const DiceType GetDamageDice() { return damageDice; }

	/// <summary>
	/// Gets the range of attack
	/// </summary>
	/// <returns>rangeOfAttack of int</returns>
	const int GetRangeOfAttack() { return rangeOfAttack; }

	/// <summary>
	/// Gets the naval battery type, 250mm or 400mm.
	/// </summary>
	/// <returns>batteryType of Armament</returns>
	const Armament GetBatteryType() { return batteryType; }
	
};

