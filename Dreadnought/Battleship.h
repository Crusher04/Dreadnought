#pragma once
#include <vector>
#include <iostream>
#include "Component.h"

class Battleship: public Component
{
protected:
	std::vector<Ref<Component>> components;
	ActorType thisActor;
	Ships shipType;
	int health;
	char armour;
	bool isAlive;

public:

	Battleship(ActorType aType);
	~Battleship();

	bool OnCreate(ActorType thisActor_, Ships shipType_, int health_, char armour_);
	void OnDestroy();

	template<typename ComponentTemplate>
	bool AddComponent(Ref<ComponentTemplate> component_)
	{
		components.push_back(component_);
	}

	template<typename ComponentTemplate, typename ... Args>
	void AddComponent(Args&& ... args_) {
		components.push_back(std::make_shared<ComponentTemplate>(std::forward<Args>(args_)...));
	}

	template<typename ComponentTemplate>
	Ref<ComponentTemplate> GetComponent() const {
		for (auto component : components) {
			if (dynamic_cast<ComponentTemplate*>(component.get()) != nullptr) {
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

	void TakeDamage(int damage);
	void AddArmour(char armour_);

};

