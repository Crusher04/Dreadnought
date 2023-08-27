#include "Battleship.h"
#include<cstdlib>

Battleship::Battleship()
{

}

bool Battleship::Initialize(ActorType actor_)
{
	shipAttributes.actor = actor_;

	if (shipAttributes.shipOfChoice == Ships::UNDEFINEDSHIP)
	{
		return false;
	}

	return true;
}

void Battleship::ChooseShip(Ships shipChoice)
{
	shipAttributes.shipOfChoice = shipChoice;
	switch (shipAttributes.shipOfChoice)
	{
	case Ships::Dreadnought:
		shipName = "Dreadnought";
		break;
	case Ships::SunkenLady:
		shipName = "SunkenLady";
		break;
	case Ships::Idris:
		shipName = "Idris";
		break;
	case Ships::SuperNova:
		shipName = "SuperNova";
		break;
	}
}

void Battleship::TakeDamage(int damage)
{
	shipAttributes.health -= damage;
	if (shipAttributes.health <= 0)
		shipAttributes.aliveStatus = false;
}

bool Battleship::Move(MovementDirection direction, ActorType actor)
{
	//LEFT
	if (shipAttributes.position[0] == 0 && direction == MovementDirection::LEFT)
	{
		cFormat.SetColour(6);
		if(actor == ActorType::PLAYER)
			std::cout << "\tINVALID DIRECTION\n";
		cFormat.SetColour(15);
		return true;
		
	}
	else if (shipAttributes.movement == 0)
	{
		cFormat.SetColour(6);
		if (actor == ActorType::PLAYER)
			std::cout << "\tNo Movement Left\n";
		cFormat.SetColour(15);
		return true;
		
	}
	else if(direction == MovementDirection::LEFT)
	{
		shipAttributes.position[0] -= 1;
		shipAttributes.movement -= 5;
		return false;
	}

	//RIGHT
	if (shipAttributes.position[0] == 20 && direction == MovementDirection::RIGHT)
	{
		cFormat.SetColour(6);
		if (actor == ActorType::PLAYER)
			std::cout << "\tINVALID DIRECTION\n";
		cFormat.SetColour(15);
		return true;
	}
	else if (shipAttributes.movement == 0)
	{
		cFormat.SetColour(6);
		std::cout << "\tNo Movement Left\n";
		cFormat.SetColour(15);
		return true;

	}
	else if(direction == MovementDirection::RIGHT)
	{
		shipAttributes.position[0] += 1;
		shipAttributes.movement -= 5;
		return false;
	}

	//UP
	if (shipAttributes.position[1] == 0 && direction == MovementDirection::UP)
	{
		cFormat.SetColour(6);
		if (actor == ActorType::PLAYER)
			std::cout << "\tINVALID DIRECTION\n";
		cFormat.SetColour(15);
		return true;
	}
	else if (shipAttributes.movement == 0)
	{
		cFormat.SetColour(6);
		std::cout << "\tNo Movement Left\n";
		cFormat.SetColour(15);
		return true;

	}
	else if (direction == MovementDirection::UP)
	{
		shipAttributes.position[1] -= 1;
		shipAttributes.movement -= 5;
		return false;
	}

	//DOWN
	if (shipAttributes.position[1] == 19 && direction == MovementDirection::DOWN)
	{
		cFormat.SetColour(6);
		if (actor == ActorType::PLAYER)
			std::cout << "\tINVALID DIRECTION\n";
		cFormat.SetColour(15);
		return true;
	}
	else if (shipAttributes.movement == 0)
	{
		cFormat.SetColour(6);
		std::cout << "\tNo Movement Left\n";
		cFormat.SetColour(15);
		return true;

	}
	else if (direction == MovementDirection::DOWN)
	{
		shipAttributes.position[1] += 1;
		shipAttributes.movement -= 5;
		return false;
	}

	

}

void Battleship::TakeAction()
{
	shipAttributes.action = false;

}

void Battleship::TakeBonusAction()
{
	shipAttributes.bonusAction = false;
}

void Battleship::ResetAttributes()
{
	shipAttributes.action = true;
	shipAttributes.bonusAction = true;
	shipAttributes.movement = defaultMovement;
	shipAttributes.health = defaultHealth;
	shipAttributes.aliveStatus = true;
	shipAttributes.spawned = false;
	shipAttributes.actor = ActorType::UNDEFINEDACTOR;
	shipAttributes.shipOfChoice = Ships::UNDEFINEDSHIP;
}

bool Battleship::EndOfTurn()
{
	shipAttributes.action = true;
	shipAttributes.bonusAction = true;
	shipAttributes.movement = defaultMovement;

	return true;
}

void Battleship::RenderUI(int aiX, int aiY, int aiHealth, std::string aiShipName)
{
	if (shipAttributes.actor == ActorType::PLAYER)
	{
		cFormat.SetColour(11);
		std::cout << "\n";
		for (int i = 0; i < 100; i++)
			std::cout << "-";
		std::cout << "\nShip: ";
		cFormat.SetColour(15);
		std::cout << shipName;
		cFormat.SetColour(11);
		std::cout << " | Health: ";
		cFormat.SetColour(15);
		if (shipAttributes.health < 50)
			cFormat.SetColour(6);
		if (shipAttributes.health < 25)
			cFormat.SetColour(12);
		std::cout << shipAttributes.health;
		cFormat.SetColour(11);
		std::cout << " | Movement: ";
		cFormat.SetColour(15);
		if(shipAttributes.movement == 0)
			cFormat.SetColour(12);
		std::cout << shipAttributes.movement;
		cFormat.SetColour(11);
		std::cout << " | Position: ";
		cFormat.SetColour(15);
		std::cout << shipAttributes.position[0] << "," << shipAttributes.position[1];
		cFormat.SetColour(11);
		std::cout << " | Enemy Ship Class: ";
		cFormat.SetColour(12);
		std::cout << aiShipName;

		cFormat.SetColour(11);
		std::cout << "\nAction: ";
		if (shipAttributes.action)
		{
			cFormat.SetColour(10);
			std::cout << "AVAILABLE";
		}
		else
		{
			cFormat.SetColour(12);
			std::cout << "NOT AVAILABLE";
		}

		cFormat.SetColour(11);
		std::cout << " | Bonus Action: ";
		if (shipAttributes.bonusAction)
		{
			cFormat.SetColour(10);
			std::cout << "AVAILABLE";
		}
		else
		{
			cFormat.SetColour(12);
			std::cout << "NOT AVAILABLE";
		}
		cFormat.SetColour(11);
		std::cout << " | Enemy Position: ";
		cFormat.SetColour(12);
		std::cout << aiX << "," << aiY;
		cFormat.SetColour(11);
		std::cout << " | Enemy Health: ";
		cFormat.SetColour(15);
		if (aiHealth < 50)
			cFormat.SetColour(6);
		if (aiHealth < 25)
			cFormat.SetColour(12);
		std::cout << aiHealth;
		cFormat.SetColour(11);


		cFormat.SetColour(11);
		std::cout << "\n";
		for (int i = 0; i < 100; i++)
			std::cout << "-";
		cFormat.SetColour(15);

	}
}

bool Battleship::Spawn()
{
	if (!shipAttributes.spawned)
		shipAttributes.spawned = true;
	
	// Providing a seed value
	std::srand((unsigned)time(NULL));
	int range = 20;

	// Get a random number
	int psuedoNum = rand() % range;

	
	if (shipAttributes.actor == ActorType::PLAYER)
	{
		shipAttributes.position[0] = psuedoNum;
		shipAttributes.position[1] = 0;
	}
	else
	{
		shipAttributes.position[0] = rand() % range;
		psuedoNum = (15 + (rand() % 18));
		while(psuedoNum > 19 || psuedoNum < 15)
			psuedoNum = (15 + (rand() % 18));
		shipAttributes.position[1] = psuedoNum;
	}
		

	return shipAttributes.spawned;
	
}