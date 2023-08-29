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
	switch (shipType) {
	case Ships::Dreadnought:
		primaryArmamentSlotMax = 2;
		subsystemSlotMax = 3;
		itemSlotMax = 2;
		missileSlotMax = 15;
		return true;
		break;
	case Ships::Idris:
		primaryArmamentSlotMax = 3;
		subsystemSlotMax = 2;
		itemSlotMax = 2;
		return true;
		break;
	case Ships::SunkenLady:
		primaryArmamentSlotMax = 3;
		subsystemSlotMax = 2;
		itemSlotMax = 1;
		missileSlotMax = 10;
		return true;
		break;
	case Ships::SuperNova:

	}
}

void Inventory::OnDestroy()
{
}

void Inventory::IncreaseInvType(InventoryType iType)
{
	switch (iType) {
	case InventoryType::PRIMARY:
		primaryArmamentSlotMax += 1;
		break;
	case InventoryType::SUBSYSTEM:
		subsystemSlotMax += 1;
		break;
	case InventoryType::JET:
		jetSlotMax += 1;
		break;
	case InventoryType::MISSILES:
		missileSlotMax += 1;
		break;
	case InventoryType::ITEMS:
		itemSlotMax += 1;

	}
}
