#include "InventoryComponent.h"

InventoryComponent::InventoryComponent():shipType{Ships::UNDEFINEDSHIP}
{
}

InventoryComponent::~InventoryComponent()
{

}

bool InventoryComponent::OnCreate()
{
	
	

	return true;
}

void InventoryComponent::OnDestroy()
{
}

void InventoryComponent::IncreaseInvType(InventoryType iType)
{
	
}

void InventoryComponent::DecreaseInvType(InventoryType iType)
{
}

