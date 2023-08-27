#pragma once
#include <iostream>
#include "ConsoleFormatting.h"
#include "Enums.h"
#include <vector>

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
		ActorType actor = ActorType::UNDEFINEDACTOR;
		Ships shipOfChoice = Ships::UNDEFINEDSHIP;
		ShipType typeOfShip;
		std::vector<Armament> ShipArmaments;
		std::vector<ShipSystems> Systems;
		int health = 0;
		int movement = 0;
		bool action = true;
		bool bonusAction = true;
		bool aliveStatus = true;
		bool spawned = false;
		int position[2] = { -1,-1 };

	};

	int defaultHealth = 0;
	int defaultMovement = 0;
	Attributes shipAttributes;
	ConsoleFormatting cFormat;
	std::string shipName;

};

