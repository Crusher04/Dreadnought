#include "EngineComponent.h"
EngineComponent::EngineComponent(EngineType eType)
{
	defaultNauticalMiles = (int)eType;
	name = "Engine";
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

	isSpawned = true;
}

void EngineComponent::DecrementMovement()
{
	if(movement > 0)
		movement -= 5;
}

void EngineComponent::MoveShip(MovementDirection direction)
{
	if (movement > 0)
	{
		switch (direction)
		{
		case MovementDirection::UP:
			position[1] -= 1;
			break;
		case MovementDirection::DOWN:
			position[1] += 1;
			break;
		case MovementDirection::LEFT:
			position[0] -= 1;
			break;
		case MovementDirection::RIGHT:
			position[0] += 1;

			break;
		}

		DecrementMovement();
	}
	else
	{
		cFormat.SetColour(12);
		std::cout << "\n\t No Movement Left.\n";
		cFormat.ResetColour();
		cFormat.Pause();
	}
	
}

void EngineComponent::MoveShip(MovementDirection direction, int distance)
{
}

void EngineComponent::ResetMovemnt()
{
	movement = defaultNauticalMiles;
}

void EngineComponent::ChangeEngineType(EngineType eType)
{
	if(defaultNauticalMiles = (int)eType)
		movement = defaultNauticalMiles;
}
