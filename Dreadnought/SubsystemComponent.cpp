#include "SubsystemComponent.h"

SubsystemComponent::SubsystemComponent(Subsystems type)
{
	subsystemType = type;
	componentType = InventoryType::SUBSYSTEM;
}

SubsystemComponent::~SubsystemComponent()
{
}


