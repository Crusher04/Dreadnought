#include "CommandCenterComponent.h"

CommandCenterComponent::CommandCenterComponent(): health{NULL}, armour{NULL}, money{NULL}, adsDefence{NULL}
{
	name = "Command Center";
	componentType = InventoryType::SUBSYSTEM;
}

CommandCenterComponent::~CommandCenterComponent()
{
	health = NULL;
	armour = NULL;
	money = NULL;
	adsDefence = NULL;
}


bool CommandCenterComponent::OnCreate(int health_, int armour_, int money_, int acDefence_)
{
	if (isCreated == false)
	{
		health = health_;
		maxHealth = health;
		armour = armour_;
		money = money_;
		adsDefence = acDefence_;
		isCreated = true;
		return true;
	}
	
	return false;
}

void CommandCenterComponent::TakeDamage(int damage)
{
	if (armour != 0 && armour > damage)
		armour -= damage;
	else if (armour != 0)
	{
		health -= (damage - armour);
		armour = 0;
	}
	else
		health -= damage;	
}

void CommandCenterComponent::Heal(int healAmount)
{
	health += healAmount;
}

void CommandCenterComponent::AddArmour(int armourAmount)
{
	armour += armourAmount;
}

void CommandCenterComponent::AddMoney(int amount)
{
	money += amount;
}

void CommandCenterComponent::AddToADS(int amount)
{
	adsDefence += amount;
}

void CommandCenterComponent::RemoveFromADS(int amount)
{
	adsDefence -= amount;
}

bool CommandCenterComponent::RemoveMoney(int amount)
{
	if (money >= amount)
	{
		money -= amount;
		return true;
	}
	
		return false;
}
