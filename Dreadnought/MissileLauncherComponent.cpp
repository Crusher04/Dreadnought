#include "MissileLauncherComponent.h"
#include <iostream>

MissileLauncherComponent::MissileLauncherComponent(Armament launcherType_):
	launcherSlots{NULL}
{

	//Set Launcher Type
	launcherType = launcherType_;

	//Component Type
	componentType = InventoryType::ARMAMENT;

	//Action Type
	componentAction = ActionType::ACTION;

	switch (launcherType)
	{
	case Armament::MissileLauncher_4:
		launcherSlots[0] = 4;
		break;
	case Armament::MissileLauncher_6:
		launcherSlots[0] = 6;
		break;
	case Armament::MissileLauncher_8:
		launcherSlots[0] = 8;
		break;
	}

	//Its created
	isCreated = true;
}

MissileLauncherComponent::~MissileLauncherComponent()
{
	launcherSlots[0] = NULL;
	launcherSlots[1] = NULL;
	launcherType = Armament::ARMAMENT_NULL;
	missileSilos.clear();
}

void MissileLauncherComponent::LoadMissile(MissileComponent missile)
{
	if (launcherSlots[1] < launcherSlots[0])
	{
		missileSilos.push_back(missile);
	}
	else
		std::cout << "\n\t SILOS ARE ALL LOADED.\n";
}

void MissileLauncherComponent::LaunchMissiles()
{
	int amountToLaunch = 0;

	for (auto missile : missileSilos)
	{
		if (missile.GetArmedStatus())
		{
			amountToLaunch += 1;
			
		}
	}
}
