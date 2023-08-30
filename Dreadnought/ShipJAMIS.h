#pragma once
/*
* JAMIS stands for Jets, Armament, Missiles, Item, Subsystem. This header file
* is to create all the types of weapones, subsystems, jets and so on that will be used
* in the game. I decided on structs because each type of JAMIS has different data types 
* different ways they work.
*/
#include "Enums.h"

class ShipJAMIS {
private:
	Armament armamentType;
	Subsystems subsystemType;
	Items itemType;

	char missileLauncherSlots;
	char missileStorageMax;
public:
};


