#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>
#include "JAMISAsset.h"

class InventoryComponent: public Component
{
private:

	//[Max Amount to have, slots used]
	char primarySlots[2] = { 0,0 };
	char subsystemSlots[2] = { 0,0 };
	char jetSlots[2] = { 0,0 };
	char itemSlots[2] = {0, 0};

	std::vector<JAMISAsset> assets;

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

	void ListItemsInInventory() const;
};

