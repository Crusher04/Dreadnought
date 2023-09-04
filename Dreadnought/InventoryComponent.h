#pragma once
#include "Component.h"
#include <iostream>
#include <unordered_map>
#include "JAMISAsset.h"

class InventoryComponent: public Component
{
private:

	//[Max Amount to have, slots used]
	int armamentSlots[2] = { 0,0 };
	int subsystemSlots[2] = { 0,0 };
	int jetSlots[2] = { 0,0 };
	int itemSlots[2] = {0, 0};
	int missileStorage[2] = { 0,0 };

public:

	//Quick access through to inventory. Don't really need to hide it for now
	//as it was causing problems.
	std::unordered_map<std::string, JAMISAsset> shipInventory;

	/// <summary>
	/// Inventory Constructor. Passes the type of ship. 
	/// </summary>
	/// <param name="shipType_"></param>
	InventoryComponent();

	/// <summary>
	/// Inventory deconstructor
	/// </summary>
	~InventoryComponent();

	void ListItemsInInventory() const {

		std::cout << "\nShip Loadout: \n";
		for (auto a : shipInventory)
			std::cout << a.first << "\n";
	}

	void ListStorageCapacities() const {
		std::cout << "\nStorage Capacities(used/max capacity): \n";
		std::cout << "Armament Slots: " << armamentSlots[1] << "/" << armamentSlots[0] << "\n";
		std::cout << "Subsytem Slots: " << subsystemSlots[1] << "/" << subsystemSlots[0] << "\n";
		std::cout << "Item Slots: " << itemSlots[1] << "/" << itemSlots[0] << "\n";
		std::cout << "Jet Slots: " << jetSlots[1] << "/" << jetSlots[0] << "\n";
		std::cout << "Missile Slots: " << missileStorage[1] << "/" << missileStorage[0] << "\n";

	}

	void AddToInventory(JAMISAsset asset_);

	void RemoveFromInventory(JAMISAsset asset_);

	void AddStorageCapacity(InventoryType iType, int amount);

	void RemoveStorageCapacity(InventoryType iType);
};

