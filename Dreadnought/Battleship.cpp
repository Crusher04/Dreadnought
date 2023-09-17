#include "Battleship.h"
#include "MissileStorageComponent.h"
#include "MissileComponent.h"
#include "MissileLauncherComponent.h"
#include "EngineComponent.h"

void Battleship::InitializeCapacities()
{
	switch (shipType)
	{
	case Ships::Dreadnought:
		armamentCapacity[0] = 3;
		armamentCapacity[1] = 0;
		subsystemCapacity[0] = 5;
		subsystemCapacity[1] = 0;
		itemCapacity[0] = 2;
		itemCapacity[1] = 0;
		return;
		break;
	case Ships::SunkenLady:
		armamentCapacity[0] = 3;
		armamentCapacity[1] = 0;
		subsystemCapacity[0] = 5;
		subsystemCapacity[1] = 0;
		itemCapacity[0] = 1;
		itemCapacity[1] = 0;
		return;
		break;
	case Ships::Idris:
		armamentCapacity[0] = 4;
		armamentCapacity[1] = 0;
		subsystemCapacity[0] = 4;
		subsystemCapacity[1] = 0;
		itemCapacity[0] = 2;
		itemCapacity[1] = 0;
		return;
		break;
	case Ships::SuperNova:
		armamentCapacity[0] = 2;
		armamentCapacity[1] = 0;
		subsystemCapacity[0] = 5;
		subsystemCapacity[1] = 0;
		itemCapacity[0] = 4;
		itemCapacity[1] = 0;
		jetCapacity[0] = 6;
		jetCapacity[1] = 0;
		return;
		break;
	case Ships::Neptune:
		break;
	}

}

Battleship::Battleship(ActorType aType):shipType{Ships::UNDEFINEDSHIP}, thisActor{ActorType::UNDEFINEDACTOR}, isAlive{true}, isSinking{false},
onFire{ false }, onboardWaterAmount{ NULL }
{
	
	thisActor = aType;
}

Battleship::~Battleship()
{

}

void Battleship::UpdateFromComponents()
{
	for (auto theComponent : components)
	{
		if (dynamic_cast<MissileStorageComponent*>(theComponent.get()) != nullptr)
		{
			missileCapacity[0] = dynamic_cast<MissileStorageComponent*>(theComponent.get())->GetStorageAmount();
		}

		if (dynamic_cast<MissileLauncherComponent*>(theComponent.get()) != nullptr)
		{
			dynamic_cast<MissileLauncherComponent*>(theComponent.get())->Update();
		}

		

	}
}

bool Battleship::OnCreate()
{
	
	return true;
}

void Battleship::OnDestroy()
{
}

void Battleship::ListMissileComponents() const
{
	int ASM = 0, AST = 0 , SSCM = 0;

	for (auto component : components)
	{
		if (component->GetComponentType() == InventoryType::MISSILES)
		{
			if (component->GetName().compare("Anti-Ship Missile") == 0)
				ASM++;
			else if (component->GetName().compare("Anti-Ship Torpedo") == 0)
				AST++;
			else if (component->GetName().compare("Super Sonic Cruise Missile") == 0)
				SSCM++;
		}
	}

	if (ASM > 0)
		std::cout << "\nAnti-Ship Missile x" << ASM;

	if (AST > 0)
		std::cout << "\nAnti-Ship Torpedo x" << AST;

	if (SSCM > 0)
		std::cout << "\nSuper Sonic Cruise Missile x" << SSCM;
}

void Battleship::ListComponents() const
{
	std::cout << std::endl;

	std::cout << typeid(*this).name() << " contains the following components:\n";
	for (auto component : components) {
		std::cout << typeid(*component).name() << std::endl;
	}	
}

void Battleship::RemoveAllComponents()
{
	components.clear();
}

bool Battleship::AddComponentChecker(Ref<Component> component_)
{
	switch (component_->GetComponentType())
	{
	case InventoryType::ARMAMENT:
		if (armamentCapacity[1] < armamentCapacity[0])
		{
			armamentCapacity[1] += 1;
			return true;
		}
		else
		{
			std::cout << "\nNO MORE SPACE FOR ARMAMENTS\n";
		}
		break;
	case InventoryType::SUBSYSTEM:	
		if (subsystemCapacity[1] < subsystemCapacity[0])
		{
			subsystemCapacity[1] += 1;

			return true;
		}
		else
		{
			std::cout << "\nNO MORE SPACE FOR SUBSYSTEMS\n";
		}
		break;
	case InventoryType::JET:
		if (jetCapacity[1] < jetCapacity[0])
		{
			jetCapacity[1] += 1;
			return true;
		}
		else
		{
			std::cout << "\nNO MORE SPACE FOR JETS\n";
		}
		break;
	case InventoryType::MISSILES:
		if (missileCapacity[1] < missileCapacity[0])
		{
			missileCapacity[1] += 1;
			
			return true;
		}
		else
		{
			std::cout << "\n MISSILE STORAGE FULL!\n";
		}

		break;
	case InventoryType::ITEMS:
		if (itemCapacity[1] < itemCapacity[0])
		{
			itemCapacity[1] += 1;
			return true;
		}
		else
		{
			std::cout << "\nNO MORE ROOM FOR ITEMS\n";
		}
		break;
	}

	return false;
}

void Battleship::PrintCapacities()
{
	std::cout << "\n Capcities \nArmaments: " << armamentCapacity[1] << "/" << armamentCapacity[0]
		<< "\nSubsystems: " << subsystemCapacity[1] << "/" << subsystemCapacity[0]
		<< "\nItems: " << itemCapacity[1] << "/" << itemCapacity[0]
		<< "\nMissiles: " << missileCapacity[1] << "/" << missileCapacity[0]
		<< "\nJets: " << jetCapacity[1] << "/" << jetCapacity[0] << "\n";
}




