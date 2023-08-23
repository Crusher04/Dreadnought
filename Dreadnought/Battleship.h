#pragma once
#include <iostream>
#include "ConsoleFormatting.h"

enum MovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum Ships
{
	Dreadnought,
	SunkenLady,
	Idris,
	SuperNova,
	UNDEFINEDSHIP
};

enum ActorType
{
	PLAYER,
	AI,
	UNDEFINEDACTOR
};



class Battleship
{
public:

	Battleship();
	bool Initialize(ActorType actor_);
	void ChooseShip(Ships shipChoice);
	void TakeDamage(int damage);
	bool Move(MovementDirection direction, ActorType actor);
	void TakeAction();
	void TakeBonusAction();
	void ResetAttributes();
	bool EndOfTurn();
	void RenderUI(int aiX, int aiY, int aiHealth, std::string aiShipName);
	bool Spawn();
	int GetPositionX() { return shipAttributes.position[0]; }
	int GetPositionY() { return shipAttributes.position[1]; }
	int GetMovement() { return shipAttributes.movement; }
	Ships GetShipChoice() { return shipAttributes.shipOfChoice; }
	int GetHealth() { return shipAttributes.health; }
	bool GetAction() { return shipAttributes.action; }
	bool GetBonusAction() { return shipAttributes.bonusAction; }
	std::string GetShipName() { return shipName; }

private:	
	struct Attributes {
		ActorType actor = UNDEFINEDACTOR;
		Ships shipOfChoice = UNDEFINEDSHIP;
		int health = 50;
		bool action = true;
		bool bonusAction = true;
		int movement = 20;
		bool aliveStatus = true;
		bool spawned = false;
		int position[2] = { -1,-1 };
		int minAttackRange = 0;
		int maxAttackRange = 0;

	};

	Attributes shipAttributes;
	ConsoleFormatting cFormat;
	const int defaultHealth = 50;
	const int defaultMovement = 20;
	std::string shipName;

};

