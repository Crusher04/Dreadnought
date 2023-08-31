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

public:

	//Quick access through to inventory. Don't really need to hide it for now
	//as it was causing problems.
	std::unordered_map<std::string, JAMISAsset> shipInventory;

	/// <summary>
	/// Inventory Constructor. Passes the type of ship. 
	/// </summary>
	/// <param name="shipType_"></param>
	InventoryComponent() {}

	/// <summary>
	/// Inventory deconstructor
	/// </summary>
	~InventoryComponent() { shipInventory.clear(); }

	void ListItemsInInventory() const {

		std::cout << "\nShip Loadout: \n";
		for (auto a : shipInventory)
			std::cout << a.first << "\n";
	}

	void AddToInventory(JAMISAsset asset_) {
		
		if (shipInventory.find(asset_.GetName()) == shipInventory.end())
			shipInventory.insert({ asset_.GetName(), asset_ });
	}

	void RemoveFromInventory(JAMISAsset asset_) {
		auto it = shipInventory.find(asset_.GetName())->first;
		shipInventory.erase(it);
	}

};

