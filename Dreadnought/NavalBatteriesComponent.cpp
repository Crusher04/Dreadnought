#include "NavalBatteriesComponent.h"

NavalBatteriesComponent::NavalBatteriesComponent(Armament batteryType_, int canonVariant) : 
	batteryType{ Armament::ARMAMENT_NULL }, rangeOfAttack { NULL }, diceMultiplier{ NULL }, damageDice{ DiceType::DICE_NULL }
{
	//Set Component Type
	componentType = InventoryType::ARMAMENT;

	//Set Battery Type
	batteryType = batteryType_;

	//Set Action Type
	componentAction = ActionType::ACTION;

	//Define Battery Specs
	switch (batteryType)
	{
	case Armament::NavalBattery250mm:
		rangeOfAttack = 30;
		if(canonVariant > 0 && canonVariant < 5)
			diceMultiplier = canonVariant;
		damageDice = DiceType::D6;
		name = "Naval Battery 250mm";
		break;
	case Armament::NavalBattery400mm:
		rangeOfAttack = 30;
		if(canonVariant < 4 && canonVariant > 0)
			diceMultiplier = canonVariant;
		damageDice = DiceType::D10;
		name = "Naval Battery 400mm";
		break;
	}


	//Its created
	isCreated = true;

}

NavalBatteriesComponent::~NavalBatteriesComponent()
{
	batteryType = Armament::ARMAMENT_NULL;
	damageDice = DiceType::DICE_NULL;
	rangeOfAttack = NULL;
	diceMultiplier = NULL;
}
