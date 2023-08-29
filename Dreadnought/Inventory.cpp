#include "Inventory.h"

Inventory::Inventory(Ships shipType_):shipType{Ships::UNDEFINEDSHIP}
{
	shipType = shipType_;
}

Inventory::~Inventory()
{
	
}

bool Inventory::OnCreate()
{
	if (shipType == Ships::Dreadnought)
	{
		primaryArmamentSlotMax = 2;
		subsystemSlotMax = 3;
		itemSlotMax = 2;
		return true;
	}
	else if (shipType == Ships::Idris)
	{

	}
	else
		return false;
	
}

void Inventory::OnDestroy()
{
}
