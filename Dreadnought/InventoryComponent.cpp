#include "InventoryComponent.h"

InventoryComponent::InventoryComponent()
{

}

InventoryComponent::~InventoryComponent()
{
	shipInventory.clear();
}

void InventoryComponent::AddToInventory(JAMISAsset asset_)
{

	if (shipInventory.find(asset_.GetName()) == shipInventory.end())
	{
		switch (shipInventory.find(asset_.GetName())->second.GetInventoryType()) {
		case InventoryType::ARMAMENT:
			if (armamentSlots[1] < armamentSlots[0])
			{
				shipInventory.insert({ asset_.GetName(), asset_ });
				armamentSlots[1] += 1;
			}
			else
				std::cout << "\n NOT ENOUGH ARMAMENT SLOTS AVAILABLE\n";
			break;
		case InventoryType::SUBSYSTEM:
			if (subsystemSlots[1] < subsystemSlots[0])
			{
				shipInventory.insert({ asset_.GetName(), asset_ });
				subsystemSlots[1] += 1;
			}
			else
				std::cout << "\n NOT ENOUGH ARMAMENT SLOTS AVAILABLE\n";
			break;
		case InventoryType::JET:
			if (jetSlots[1] < jetSlots[0])
			{
				shipInventory.insert({ asset_.GetName(), asset_ });
				jetSlots[1] += 1;
			}
			else
				std::cout << "\n NOT ENOUGH ARMAMENT SLOTS AVAILABLE\n";
			break;
		case InventoryType::MISSILES:
			if (missileStorage[1] < missileStorage[0])
			{
				shipInventory.insert({ asset_.GetName(), asset_ });
				missileStorage[1] += 1;
			}
			else
				std::cout << "\n NOT ENOUGH ARMAMENT SLOTS AVAILABLE\n";
			break;
		case InventoryType::ITEMS:
			if (itemSlots[1] < itemSlots[0])
			{
				shipInventory.insert({ asset_.GetName(), asset_ });
				itemSlots[1] += 1;
			}
			else
				std::cout << "\n NOT ENOUGH ARMAMENT SLOTS AVAILABLE\n";
			break;
		}
	}
}

void InventoryComponent::RemoveFromInventory(JAMISAsset asset_)
{
	auto it = shipInventory.find(asset_.GetName())->first;
	shipInventory.erase(it);
}

void InventoryComponent::AddStorageCapacity(InventoryType iType, int amount)
{
	switch (iType) {
	case InventoryType::ARMAMENT:
		armamentSlots[0] += amount;
		break;
	case InventoryType::SUBSYSTEM:
		subsystemSlots[0] += amount;
		break;
	case InventoryType::JET:
		jetSlots[0] += amount;
		break;
	case InventoryType::MISSILES:
		missileStorage[0] += amount;
		break;
	case InventoryType::ITEMS:
		itemSlots[0] += amount;
		break;

	}
}

void InventoryComponent::RemoveStorageCapacity(InventoryType iType)
{
	switch (iType) {
	case InventoryType::ARMAMENT:
		armamentSlots[0] = 0;
		break;
	case InventoryType::SUBSYSTEM:
		subsystemSlots[0] = 0;
		break;
	case InventoryType::JET:
		jetSlots[0] = 0;
		break;
	case InventoryType::MISSILES:
		missileStorage[0] = 0;
		break;
	case InventoryType::ITEMS:
		itemSlots[0] = 0;
		break;

	}
}
