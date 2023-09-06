#include "MissileComponent.h"

MissileComponent::MissileComponent(Armament missileType_) :
	missileType{ Armament::ARMAMENT_NULL }, armed{ false }, damageDice{ DiceType::DICE_NULL }, rangeOfAttack{ NULL }, diceMultiplier{NULL}
{
	//Set Component type to missiless
	componentType = InventoryType::MISSILES;

	//Assign variables to passed through vars
	missileType = missileType_;

	//Set damage dice
	switch (missileType)
	{
	case Armament::AntiShipMissile:
		rangeOfAttack = 50;
		damageDice = DiceType::D12;
		diceMultiplier = 1;
		break;
	case Armament::AntiShipTorpedo:
		rangeOfAttack = 50;
		damageDice = DiceType::D12;
		diceMultiplier = 2;
		break;
	case Armament::SuperSonicCruiseMissile:
		rangeOfAttack = 70;
		damageDice = DiceType::D12;
		diceMultiplier = 3;
		break;
	}

	isCreated = true;
}

MissileComponent::~MissileComponent()
{
	missileType = Armament::ARMAMENT_NULL;
	armed = false;
	damageDice = DiceType::DICE_NULL;
	rangeOfAttack = NULL;
	diceMultiplier = NULL;
}
