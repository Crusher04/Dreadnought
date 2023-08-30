#include "Battleship.h"

Battleship::Battleship(ActorType aType):shipType{Ships::UNDEFINEDSHIP}, thisActor{ActorType::UNDEFINEDACTOR}, health{0}, armour{0}, isAlive{true}
{
	thisActor = aType;
}

Battleship::~Battleship()
{

}


bool Battleship::OnCreate(ActorType thisActor_, Ships shipType_, int health_, char armour_)
{
	thisActor = thisActor_;
	shipType = shipType_;
	health = health_;
	armour = armour_;
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

void Battleship::TakeDamage(int damage)
{
	int incomingDMG = damage;
	if (armour > 0 && armour > damage)
		armour -= damage;
	else
	{
		if (armour > 0 && damage > armour)
		{
			incomingDMG -= armour;
			armour = 0;
		}

		health -= incomingDMG;	
	}

	if (health <= 0)
		isAlive = false;
}

void Battleship::AddArmour(char armour_)
{
	armour += armour_;
}

