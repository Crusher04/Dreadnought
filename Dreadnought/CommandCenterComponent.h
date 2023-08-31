#pragma once
#include "Component.h"

class CommandCenterComponent: public Component
{
private:

	//Class variables
	int health;
	int armour;
	int money;
	int acDefence;

public:

	CommandCenterComponent();
	~CommandCenterComponent();

	bool OnCreate(int health_, int armour_, int money_ , int acDefence_);

	void TakeDamage(int damage);
	void Heal(int healAmount);
	void AddArmour(int armourAmount);
	void AddMoney(int amount);
	bool RemoveMoney(int amount);
	int GetACDefence();
};

