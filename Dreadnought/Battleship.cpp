#include "Battleship.h"
#include "MissileStorageComponent.h"

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

Battleship::Battleship(ActorType aType):shipType{Ships::UNDEFINEDSHIP}, thisActor{ActorType::UNDEFINEDACTOR}, isAlive{true}
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
	}
}

bool Battleship::OnCreate()
{
	
	return true;
}

void Battleship::OnDestroy()
{
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


