#pragma once
#include <vector>
#include <iostream>
#include "Component.h"

class Battleship: public Component
{
protected:
	std::vector<Ref<Component>> components;
	Ships shipType;

public:

	Battleship(Ships starterShip);
	~Battleship();

	bool OnCreate();
	void OnDestroy();

	template<typename ComponentTemplate>
	bool AddComponent(Ref<ComponentTemplate> component_)
	{
		components.push_back(component_);
	}

	template<typename ComponentTemplate, typename ... Args>
	void AddComponent(Args&& ... args_) {

		/// If nothing else is messed up, finish building the component and
		/// add the component to the list
		/// Create the new object based on the template type and the argument list
		components.push_back(std::make_shared<ComponentTemplate>(std::forward<Args>(args_)...));
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

	template<typename ComponentTemplate>
	void RemoveComponent() {
		for (unsigned int i = 0; i < components.size(); i++) {
			if (dynamic_cast<ComponentTemplate*>(components[i].get()) != nullptr) {
				components.erase(components.begin() + i);
				break;
			}
		}
	}

	void ListComponents() const;
	void RemoveAllComponents();
	void ChangeStarterShip(Ships ship);

};

