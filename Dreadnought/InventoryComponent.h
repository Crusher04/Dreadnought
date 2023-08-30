#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>
#include "ShipJAMIS.h"

class InventoryComponent: public Component
{
private:

	//[Max Amount to have, slots used]
	char primarySlots[2] = { 0,0 };
	char subsystemSlots[2] = { 0,0 };
	char jetSlots[2] = { 0,0 };
	char missileSlots[2] = { 0,0 };
	char itemSlots[2] = { 0, 0};		
	
	

	Ships shipType;
public:
	
	/// <summary>
	/// Inventory Constructor. Passes the type of ship. 
	/// </summary>
	/// <param name="shipType_"></param>
	InventoryComponent();

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

	void RemoveItem();

	void PrintMaxInventorySlots();

	char GetMaxSlots(InventoryType iType);



	void ListItemsInInventory() const;
};

