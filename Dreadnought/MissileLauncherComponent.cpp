#include "MissileLauncherComponent.h"

MissileLauncherComponent::MissileLauncherComponent(Armament launcherType_)
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
		for (int i = 0; i < 4; i++)
			silos.insert({ i, false });
		break;
	case Armament::MissileLauncher_6:
		for (int i = 0; i < 6; i++)
			silos.insert({ i, false });
		break;
	case Armament::MissileLauncher_8:
		for (int i = 0; i < 8; i++)
			silos.insert({ i, false });
		break;
	}

	//Its created
	isCreated = true;
}

MissileLauncherComponent::~MissileLauncherComponent()
{
	silos.clear();
	launcherType = Armament::ARMAMENT_NULL;
}

void MissileLauncherComponent::LoadMissile(MissileComponent &missile)
{
	bool loadFlag = false;

	for (auto silo : silos)
	{
		if (silo.second == false)
		{
			auto it = silos.find(silo.first);
			it->second = true;
			missile.LoadMissile();
			loadFlag = true;
			std::cout << "\n MISSILE LOADED \n";
			return;
		}
	}

	if (!loadFlag)
		std::cout << "\n\t SILOS ARE ALL LOADED.\n";
}

void MissileLauncherComponent::LaunchMissiles()
{
	
}
