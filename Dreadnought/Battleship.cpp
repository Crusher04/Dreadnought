#include "Battleship.h"

Battleship::Battleship()
{
}

Battleship::~Battleship()
{
}

bool Battleship::OnCreate()
{
	return false;
}

void Battleship::OnDestroy()
{
}

void Battleship::ListComponents() const
{
	std::cout << std::endl;

	std::cout << typeid(*this).name() << " contains the following components:\n";
	for (auto component : components) {
		std::cout << typeid(*component).name() << std::endl;
	}	
}

void Battleship::RemoveAllComponents()
{
	components.clear();
}
