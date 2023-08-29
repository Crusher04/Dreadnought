#pragma once
#include "Component.h"
#include <vector>
#include <iostream>

class Inventory: public Component
{
protected:
	char primaryArmamentSlotMax = 0;		//Slot 0
	char subsystemSlotMax = 0;				//Slot 1
	char jetSlotMax = 0;					//Slot 2
	char missileSlotMax = 0;				//Slot 3
	char itemSlotMax = 0;					//Slot 4
	char allInventories[5];					//ALL SLOTS ABOVE

public:
	Inventory(Ships shipType);
	~Inventory();
	bool OnCreate();
	void OnDestroy();

	void IncreaseSlotType();
	
};

