#include "MissileStorageComponent.h"

MissileStorageComponent::MissileStorageComponent(Subsystems systemType_): storage{0}
{
	componentType = InventoryType::SUBSYSTEM;

	switch (systemType_)
	{
	case Subsystems::MISSILE_STORAGE_5:
		storage = 5;
		break;
	case Subsystems::MISSILE_STORAGE_10:
		storage = 10;
		break;
	case Subsystems::MISSILE_STORAGE_15:
		storage = 15;
		break;
	case Subsystems::MISSILE_STORAGE_20:
		storage = 20;
		break;
	case Subsystems::MISSILE_STORAGE_25:
		storage = 25;
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
