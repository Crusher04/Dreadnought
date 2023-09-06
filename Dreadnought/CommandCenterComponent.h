#pragma once
#include "Component.h"

class CommandCenterComponent: public Component
{
private:

	//Class variables
	int health;
	int armour;
	int money;
	int adsDefence;

public:

	CommandCenterComponent();
	~CommandCenterComponent();

	bool OnCreate(int health_, int armour_, int money_ , int acDefence_);

	void TakeDamage(int damage);
	void Heal(int healAmount);
	void AddArmour(int armourAmount);
	void AddMoney(int amount);
	void AddToADS(int amount);
	void RemoveFromADS(int amount);
	bool RemoveMoney(int amount);

	const int GetArmour() { return armour; }
	const int GetHealth() { return health; }
	const int GetADSDefence() { return adsDefence; }
	const int GetMoney() { return money; }
};

