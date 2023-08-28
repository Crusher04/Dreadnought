#pragma once
#include <vector>
#include <iostream>
#include "Component.h"

class Battleship: public Component
{
protected:
	std::vector<Ref<Component>> components;


public:

	Battleship();
	~Battleship();

	template<typename ComponentTemplate>
	bool AddComponent(Ref<ComponentTemplate> component_)
	{
		if (GetComponent<ComponentTemplate>().get() != nullptr) {
#ifdef _DEBUG
			std::cerr << "WARNING: Trying to add a component type that is already added - ignored\n";
#endif
			return;
		}
		components.push_back(component_);
	}

	template<typename ComponentTemplate>
	Ref<ComponentTemplate> GetComponent() const {
		for (auto component : components) {
			if (dynamic_cast<ComponentTemplate*>(component.get()) != nullptr) {
				/// This is a dynamic cast designed for shared_ptr's
				/// https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast
				return std::dynamic_pointer_cast<ComponentTemplate>(component);
			}
		}
		return Ref<ComponentTemplate>(nullptr);
	}
};

