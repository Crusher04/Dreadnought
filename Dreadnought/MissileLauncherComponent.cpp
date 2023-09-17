#include "MissileLauncherComponent.h"

MissileLauncherComponent::MissileLauncherComponent(Armament launcherType_) : isLauncherEmpty{ true }, siloCounter{0}
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

void MissileLauncherComponent::Update()
{
	
	CheckIfLauncherIsEmpty();

}

void MissileLauncherComponent::CheckIfLauncherIsEmpty()
{
	siloCounter = 0;

	for (auto silo : silos)
	{
		if (silo.second.compare("") == 0)
			siloCounter++;
	}

	if (siloCounter == silos.size())
		isLauncherEmpty = true;
	else
		isLauncherEmpty = false;
}

bool MissileLauncherComponent::LoadMissile(Battleship* ship)
{
	
	for (auto silo : silos)
	{
		auto missile = ship->GetComponent<MissileComponent>();
		int amountOfMisiles = ship->GetAmountOfComponents<MissileLauncherComponent>();
		message.str("");

		if (missile->GetSiloNumber() == -1 && silo.second.compare("") == 0)
		{
			if(isLauncherEmpty)
				isLauncherEmpty = false;

			missile->LoadMissile(silo.first);
			silos.at(silo.first).clear();
			silos.at(silo.first).append(missile->GetName());

			message << "\n" << missile->GetName() << " Loaded in silo " << missile->GetSiloNumber() + 1;
			ship->SetConsoleMessage(message.str());
			return true;
		}
		else if ((missile->GetSiloNumber()+1) == silos.size() && silo.second.compare("") != 0)
		{
			message << "\n Missile Launcher is full. All silos are loaded.";
			ship->SetConsoleMessage(message.str());
			return true;
		}
		else if (amountOfMisiles <= silos.size())
		{
			message << "\n No More Missiles to Load.\n";
			ship->SetConsoleMessage(message.str());
			return true;
		}
	}

	return false;
}//End of Load Missile

bool MissileLauncherComponent::LaunchMissile(Battleship* ship, int silo)
{
	int siloNum = silo - 1;
	message.str("");
	
	if (silos.at(siloNum).compare("") == 0)
	{
		message << "\n Silo Is Not Loaded!\n";
		ship->SetConsoleMessage(message.str());
		return false;
	}

	while (ship->GetComponent<MissileComponent>()->GetSiloNumber() != siloNum)
		ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());
	
	auto missile = ship->GetComponent<MissileComponent>();

	if (!missile->GetArmedStatus())
	{
		message << "\n\t MISSILE IS NOT ARMED. Cannot Launch Missile. \n";
		ship->SetConsoleMessage(message.str());

	}
	else
	{
		message << "Silo " << missile->GetSiloNumber() + 1 << " LAUNCHED SUCCESSFUL! \n";
		ship->SetConsoleMessage(message.str());
		silos.at(siloNum).clear();
		silos.at(siloNum).append("");
		for(int i = 0; i < missile->GetDiceMultiplier(); i++)
			dRoller.RollDice(missile->GetDamageDice());
		ship->RemoveComponent<MissileComponent>();
		return true;
	}

	return false;
}

const void MissileLauncherComponent::GetSiloStatus(Battleship* ship)
{
	message.str("");

	if (isLauncherEmpty)
	{
		for(auto silo : silos)
			message << "\n Silo " << silo.first + 1 << " is Empty\n";
		
		ship->SetConsoleMessage(message.str());

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
				message << "\n\t" << ship->GetComponent<MissileComponent>()->GetName() << " in Silo " << silo.first + 1 << " is ARMED\n";
			}
			else if (ship->GetComponent<MissileComponent>()->GetSiloNumber() == silo.first && !ship->GetComponent<MissileComponent>()->GetArmedStatus())
			{
				message << "\n\t" << ship->GetComponent<MissileComponent>()->GetName() << " in Silo " << silo.first + 1 << " is ON STANDBY\n";

			}
			else if (silo.second.compare("") == 0)
				message << "\n\tSilo " << silo.first + 1 << " is Empty\n";

			ship->SetConsoleMessage(message.str());
			
			ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());

		}
	}
	
}//End of GetSiloStatus()

bool MissileLauncherComponent::ArmMissileInSilo(Battleship* ship, int silo)
{
	
	int siloNum = silo - 1;
	message.str("");

	if (silos.at(siloNum).compare("") == 0)
	{
		message << "\n Silo Is Not Loaded!\n";
		return false;
	}

	while (ship->GetComponent<MissileComponent>()->GetSiloNumber() != siloNum)
		ship->PushComponentToEnd(ship->GetComponentPosition<MissileComponent>());

	auto missile = ship->GetComponent<MissileComponent>();


	if (missile->GetArmedStatus())
		message << "\n\tMissile already armed.\n";
	else
	{
		ship->GetComponent<MissileComponent>()->ArmMissile();
		message << "\n Missile " << missile->GetName() << " in Silo " << missile->GetSiloNumber() + 1 << " is ARMED\n";
		return true;
	}
	return false;
}//End of ArmMissileInSilo
