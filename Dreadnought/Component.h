#pragma once
#include <memory>
#include "Enums.h"

template<typename T>
using Ref = std::shared_ptr <T>;

class Component {
public:

	Component(): isCreated(false), componentAction(ActionType::ACTION_NULL), componentType(InventoryType::INV_NULL) {}
	virtual ~Component() = default;

	const InventoryType GetComponentType() { return componentType; }
	const ActionType GetActionType() { return componentAction; }

protected:
	bool isCreated;
	InventoryType componentType;
	ActionType componentAction;
	
};