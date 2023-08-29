#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>

class Inventory: public Component
{
protected:
	char primaryArmamentSlotMax = 0;		
	char subsystemSlotMax = 0;				
	char jetSlotMax = 0;					
	char missileSlotMax = 0;				
	char itemSlotMax = 0;	

	/// <summary>
	/// Inventory Type and how many are installed on ship.
	/// </summary>
	std::unordered_map<InventoryType, char> myInventory;		
	std::string slotNames[5] = { "Primary Armament ", "Subsytem ", "Jet ", "Missile ", "Item "};
	Ships shipType;
public:
	
	Inventory(Ships shipType_);

	~Inventory();

	bool OnCreate();

	void OnDestroy();

	void IncreaseInvType(InventoryType iType);

	void DecreaseInvType(InventoryType iType);

	void AddItem();

	void PrintMaxInventorySlots();

	char GetMaxSlots(InventoryType iType);

	
};

