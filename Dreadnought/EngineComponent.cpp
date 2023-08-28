#include "EngineComponent.h"

EngineComponent::EngineComponent()
{
	isCreated = true;
}

EngineComponent::~EngineComponent()
{
	isCreated = false;
}

int EngineComponent::GetMovement()
{
	return movement;
}

void EngineComponent::SetMovement(int newMovement)
{
	if (setMovemementFlag == false)
	{
		defaultNauticalMiles = newMovement;
		movement = defaultNauticalMiles;
		setMovemementFlag = true;
	}
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
