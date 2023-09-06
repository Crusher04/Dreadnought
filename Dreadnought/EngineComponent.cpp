#include "EngineComponent.h"

EngineComponent::EngineComponent(EngineType eType)
{
	defaultNauticalMiles = (int)eType;
	componentType = InventoryType::SUBSYSTEM;
	if (OnCreate())
		isCreated = true;
	else
	{
		std::cout << "ERROR: Failed to create Engine Component!\n";
		return;
	}
}
EngineComponent::~EngineComponent()
{
	isCreated = false;
}


bool EngineComponent::OnCreate()
{
	movement = defaultNauticalMiles;
	setMovemementFlag = true;
	return true;
}

void EngineComponent::OnDestroy()
{

}

int EngineComponent::GetMovement()
{
	return movement;
}

void EngineComponent::SetSpawn(int x, int y)
{
	position[0] = x;
	position[1] = y;
}

void EngineComponent::DecrementMovement()
{
	if(movement > 0)
		movement -= 5;
}

void EngineComponent::MoveShip(int x, int y)
{
	position[0] = x;
	position[1] = y;
}

void EngineComponent::ChangeEngineType(EngineType eType)
{
	if(defaultNauticalMiles = (int)eType)
		movement = defaultNauticalMiles;
}
