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

	//Actions
	bool action;
	bool bonusAction;

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

	void UseAction() { action = false; }
	void UseBonuseAction() { bonusAction = false; }
	void ResetActions() { action = true; bonusAction = true; }

	const int GetArmour() { return armour; }
	const int GetHealth() { return health; }
	const int GetADSDefence() { return adsDefence; }
	const int GetMoney() { return money; }
	const bool GetAction() { return action; }
	const bool GetBonusAction() { return bonusAction; }
};

