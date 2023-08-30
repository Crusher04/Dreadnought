#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>

class InventoryComponent: public Component
{
protected:
	//[Max Amount to have, slots used]
	char primarySlots[2] = { 0,0 };
	char subsystemSlots[2] = { 0,0 };
	char jetSlots[2] = { 0,0 };
	char missileSlots[2] = { 0,0 };
	char itemSlots[2] = { 0, 0};
	std::unordered_map<InventoryType, char[]> s;
	std::string slotNames[5] = { "Primary Armament ", "Subsytem ", "Jet ", "Missile ", "Item "};
	Ships shipType;
public:
	
	/// <summary>
	/// Inventory Constructor. Passes the type of ship. 
	/// </summary>
	/// <param name="shipType_"></param>
	InventoryComponent(Ships shipType_);

	/// <summary>
	/// Inventory deconstructor
	/// </summary>
	~InventoryComponent();

	/// <summary>
	/// Initializes the inventory to match the ship selection
	/// </summary>
	/// <returns></returns>
	bool OnCreate();

	void OnDestroy();

	void IncreaseInvType(InventoryType iType);

	void DecreaseInvType(InventoryType iType);

	void AddItem();

	void RemoveItem();

	void PrintMaxInventorySlots();

	char GetMaxSlots(InventoryType iType);

	void CheckInventory();
};

