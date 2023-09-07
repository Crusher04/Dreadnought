#include "MissileStorageComponent.h"

MissileStorageComponent::MissileStorageComponent(Subsystems systemType_): storage{0}
{
	componentType = InventoryType::SUBSYSTEM;

	switch (systemType_)
	{
	case Subsystems::MISSILE_STORAGE_5:
		storage = 5;
		name = "Missile Storage - Capacity of 5.";
		break;
	case Subsystems::MISSILE_STORAGE_10:
		storage = 10;
		name = "Missile Storage - Capacity of 10.";
		break;
	case Subsystems::MISSILE_STORAGE_15:
		storage = 15;
		name = "Missile Storage - Capacity of 15.";
		break;
	case Subsystems::MISSILE_STORAGE_20:
		storage = 20;
		name = "Missile Storage - Capacity of 20.";
		break;
	case Subsystems::MISSILE_STORAGE_25:
		storage = 25;
		name = "Missile Storage - Capacity of 25.";
		break;
	default:
		storage = 0;
		break;
	}

	isCreated = true;
}

MissileStorageComponent::~MissileStorageComponent()
{
	storage = 0;
}
