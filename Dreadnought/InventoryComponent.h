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

	template<typename asset>
	void AddComponent(Ref<asset> asset_) {
		/// before you add the component ask if you have the component in the list already,
		/// if so - don't add a second one. 
		if (GetComponent<asset>().get() != nullptr) {
#ifdef _DEBUG
			std::cerr << "WARNING: Trying to add a component type that is already added - ignored\n";
#endif		
			return;
		}
		/// If nothing else is messed up, finish building the component and
		/// add the component to the list
		/// Create the new object based on the template type and the argument list
		assets.push_back(asset_);
	}

	std::vector<JAMISAsset> GetAssets() {
		return assets;
	}


};

