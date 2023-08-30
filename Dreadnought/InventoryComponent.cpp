#include "InventoryComponent.h"

InventoryComponent::InventoryComponent(Ships shipType_):shipType{Ships::UNDEFINEDSHIP}
{
	shipType = shipType_;
}

InventoryComponent::~InventoryComponent()
{
	
}

bool InventoryComponent::OnCreate()
{
	switch (shipType) {
	case Ships::Dreadnought:
		primarySlots[0] = 2;
		primarySlots[1] = 1;
		subsystemSlots[0] = 3;
		subsystemSlots[1] = 1;
		itemSlots[0] = 2;
		itemSlots[1] = 1;
		missileSlots[0] = 15;
		missileSlots[1] = 10;

		return true;
		break;
	case Ships::Idris:
		primarySlots = 3;
		subsystemSlots = 2;
		itemSlots = 2;
		return true;
		break;
	case Ships::SunkenLady:
		primarySlots = 3;
		subsystemSlots = 2;
		itemSlots = 1;
		missileSlots = 10;
		return true;
		break;
	case Ships::SuperNova:
		primarySlots = 2;
		subsystemSlots = 2;
		missileSlots = 5;
		jetSlots = 6;
		itemSlots = 4;
		return true;
		break;
	}
}

void InventoryComponent::OnDestroy()
{
}

void InventoryComponent::IncreaseInvType(InventoryType iType)
{
	switch (iType) {
	case InventoryType::PRIMARY:
		primarySlots += 1;
		break;
	case InventoryType::SUBSYSTEM:
		subsystemSlots += 1;
		break;
	case InventoryType::JET:
		jetSlots += 1;
		break;
	case InventoryType::MISSILES:
		missileSlots += 1;
		break;
	case InventoryType::ITEMS:
		itemSlots += 1;
		break;

	}
}

void InventoryComponent::DecreaseInvType(InventoryType iType)
{
}
