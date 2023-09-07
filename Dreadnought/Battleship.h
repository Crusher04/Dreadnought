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

	//Conditional Variables
	bool isAlive;
	bool onFire;
	bool isSinking;
	int  onboardWaterAmount;

	//Storage types {MaxCapacity, CapacityUsed}
	int armamentCapacity[2] = { 0,0 };
	int subsystemCapacity[2] = { 0,0 };
	int itemCapacity[2] = { 0,0 };
	int jetCapacity[2] = { 0,0 };
	int missileCapacity[2] = { 0, 0 };

	//Called when shiptype is defined to initialize the proper capacities for all except missiles. 
	//Missiles rely on missile storage to update its capacity.
	void InitializeCapacities();

public:

	Battleship(ActorType aType);
	~Battleship();
	
	void UpdateFromComponents();

	bool OnCreate();
	void OnDestroy();

	template<typename ComponentTemplate>
	bool AddComponent(Ref<ComponentTemplate> component_)
	{
		if (AddComponentChecker(component_))
			components.push_back(component_);
		else
			return false;
		return true;
	}

	template<typename ComponentTemplate, typename ... Args>
	bool AddComponent(Args&& ... args_) 
	{
		auto component = std::make_shared<ComponentTemplate>(std::forward<Args>(args_)...);
		if (AddComponentChecker(component))
			components.push_back(std::make_shared<ComponentTemplate>(std::forward<Args>(args_)...));
		else
			return false;
		return true;
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
	int GetComponentPosition() const {
		int i = NULL;
		for (auto component : components) {
			if (dynamic_cast<ComponentTemplate*>(component.get()) != nullptr) {
				return i;
			}
			i++;
		}
		return i;
	}

	template<typename ComponentTemplate>
	void RemoveComponent() {
		for (unsigned int i = 0; i < components.size(); i++) {
			if (dynamic_cast<ComponentTemplate*>(components[i].get()) != nullptr) {
				components.erase(components.begin() + i);
				switch (components[i]->GetComponentType())
				{
				case InventoryType::ARMAMENT:
					if(armamentCapacity[1] > 0)
						armamentCapacity[1] -= 1;
					break;
				case InventoryType::SUBSYSTEM:
					if (subsystemCapacity[1] > 0)
						subsystemCapacity[1] -= 1;

					break;
				case InventoryType::JET:
					if (jetCapacity[1] > 0)
						jetCapacity[1] -= 1;
					break;
				case InventoryType::MISSILES:
					if (missileCapacity[1] > 0)
						missileCapacity[1] -= 1;
					break;
				case InventoryType::ITEMS:
					if (itemCapacity[1] > 0)
						itemCapacity[1] -= 1;
					break;
				}
				break;
			}
		}
	}

	void ListComponents() const;
	void RemoveAllComponents();
	void SetShipType(Ships shipType_) { shipType = shipType_; InitializeCapacities(); }
	bool AddComponentChecker(Ref<Component> component_);
	void PrintCapacities();
	void PushComponentToEnd(int index) {
		auto hold = components.at(index);
		components.erase(components.begin() + index);
		components.push_back(hold);
	}
};

