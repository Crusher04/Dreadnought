#include "MissileLauncherComponent.h"

MissileLauncherComponent::MissileLauncherComponent(Armament launcherType_) : isLauncherEmpty{ true }
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
		name = "Missile Launcher 4 Slot";
		for (int i = 0; i < 4; i++)
			silos.insert({ i, ""});
		break;
	case Armament::MissileLauncher_6:
		name = "Missile Launcher 6 Slot";
		for (int i = 0; i < 6; i++)
			silos.insert({ i, ""});
		break;
	case Armament::MissileLauncher_8:
		name = "Missile Launcher 8 Slot";
		for (int i = 0; i < 8; i++)
			silos.insert({ i, ""});
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

bool MissileLauncherComponent::LoadMissile(MissileComponent* missile)
{
	for (auto silo : silos)
	{
		if (missile->GetSiloNumber() == -1 && silo.second.compare("") == 0)
		{
			if(isLauncherEmpty)
				isLauncherEmpty = false;

			missile->LoadMissile(silo.first);
			silos.at(silo.first).clear();
			silos.at(silo.first).append(missile->GetName());
			std::cout << "\n" << missile->GetName() << " Loaded in silo " << missile->GetSiloNumber() + 1;
			return true;
		}
		else if (missile->GetSiloNumber() == 3 && silo.second.compare("") != 0)
		{
			std::cout << "\n Missile Launcher is full. All silos are loaded.";
			return true;
		}
	}

	return false;
}

bool MissileLauncherComponent::LaunchMissiles(MissileComponent &missile)
{
	return false;
}

const void MissileLauncherComponent::GetSiloStatus(Battleship* ship)
{
	if (isLauncherEmpty)
	{
		for(auto silo : silos)
			std::cout << "\n Silo " << silo.first + 1 << " is Empty\n";
	}
	else 
	{
		if (ship->GetComponent<MissileComponent>()->GetSiloNumber() != 0 && silos.at(0).compare("") != 0 && !isLauncherEmpty)
		{
			while(ship->GetComponent<MissileComponent>()->GetSiloNumber() != 0)
				ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());
		}

		for (auto silo : silos)
		{
			if (silo.second.compare("") == 0)
			{
				ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());
			}

			while(ship->GetComponent<MissileComponent>()->GetSiloNumber() == -1)
				ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());

			
			if (ship->GetComponent<MissileComponent>()->GetSiloNumber() == silo.first && ship->GetComponent<MissileComponent>()->GetArmedStatus())
			{
				std::cout << "\n " << ship->GetComponent<MissileComponent>()->GetName() << " in Silo " << silo.first + 1 << " is ARMED\n";
			}
			else if (ship->GetComponent<MissileComponent>()->GetSiloNumber() == silo.first && !ship->GetComponent<MissileComponent>()->GetArmedStatus())
			{
				std::cout << "\n" << ship->GetComponent<MissileComponent>()->GetName() << " in Silo " << silo.first + 1 << " is ON STANDBY\n";

			}
			else if (silo.second.compare("") == 0)
				std::cout << "\n Silo " << silo.first + 1 << " is Empty\n";
			
			ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());

		}
	}
	
}

bool MissileLauncherComponent::ArmMissileInSilo(MissileComponent* missile)
{
	

	for (auto silo : silos)
	{
		if (!missile->GetArmedStatus() && missile->GetSiloNumber() == silo.first)
		{
			missile->ArmMissile();
			std::cout << "\n\t" << missile->GetName() << " is Armed in Silo " << missile->GetSiloNumber() + 1;
			return true;
		}
	}
	return false;
}
