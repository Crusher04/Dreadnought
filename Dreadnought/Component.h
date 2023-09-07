#pragma once
#include <memory>
#include "Enums.h"
#include <iostream>

template<typename T>
using Ref = std::shared_ptr <T>;

class Component {
public:

	Component(): isCreated(false), componentAction(ActionType::ACTION_NULL), componentType(InventoryType::INV_NULL) {}
	virtual ~Component() = default;

	const InventoryType GetComponentType() { return componentType; }
	const ActionType GetActionType() { return componentAction; }

	/// <summary>
	/// Gets the name of the battery. Generally this will just say if its 250mm or 400mm
	/// </summary>
	/// <returns>name as std::string</returns>
	std::string GetName() const { return name; }

protected:
	bool isCreated;
	InventoryType componentType;
	ActionType componentAction;
	std::string name;
	
};