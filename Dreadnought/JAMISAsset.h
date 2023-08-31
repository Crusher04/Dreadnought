#pragma once
/*
* JAMIS stands for Jets, Armament, Missiles, Item, Subsystem. This header file
* is to create all the types of weapones, subsystems, jets and so on that will be used
* in the game. I decided on structs because each type of JAMIS has different data types 
* different ways they work.
*/
#include "Enums.h"
#include <iostream>

class JAMISAsset {
private:
	std::string name;

	Armament armamentType;
	Subsystems subsystemType;
	Items itemType;

	InventoryType invType;
	ActionType myAction;
	DiceType damageDice;

	char storageOrSlots;

	char rangeOfAttack;
	char diceMultiplier;

	const char maxTimeInAir = 3;
	char timeInAir;

	bool isDestroyed;
	bool mustBePrepared;
	bool prepared;
	bool returningToCarrier;

public:

	JAMISAsset(std::string name_, InventoryType iType);
	~JAMISAsset();
	

	/// <summary>
	/// Intialize Armament
	/// </summary>
	/// <param name="armType"></param>
	void Initialize(Armament armType, char diceMultiplier_);

	/// <summary>
	/// Initialize Subsystem
	/// </summary>
	/// <param name="subType"></param>
	void Initialize(Subsystems subType);

	/// <summary>
	/// Initialize Item
	/// </summary>
	/// <param name="itemType_"></param>
	void Initialize(Items itemType_);

	///////GETTERS///////
	const std::string GetName() { return name; }
	const char GetStorageOrSlot() { return storageOrSlots; }
	const DiceType GetDiceType() { return damageDice; }
	const ActionType GetActionType() { return myAction; }
	const char GetRangeOfAttack() { return rangeOfAttack; }
	const char GetDiceMultiplier() { return diceMultiplier; }
	const char GetMaxTimeInAir() { return maxTimeInAir; }
	const char GetTimeInAir() { return timeInAir; }
	const bool CheckIfDestroyed() { return isDestroyed; }
	const bool GetMustBePrepared() { return mustBePrepared; }
	const bool GetPreparedStatus() { return prepared; }
	const bool CheckIfReturningToCarrier() { return returningToCarrier; }

	///////SETTERS///////
	void SetTimeInAir(char timeInAir_) { timeInAir = timeInAir_; }
	void DestroyFlag(bool flag) {
		isDestroyed = flag;
	}
	void DestroyFlag() { isDestroyed = true; }
	void SetPreparedStatus(bool p) { prepared = p; }
	void SetReturningToCarrierStatus(bool r) { returningToCarrier = r; }
};


