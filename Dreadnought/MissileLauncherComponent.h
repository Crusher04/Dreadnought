#pragma once
#include "Component.h"
#include "MissileComponent.h"
#include "DiceRoller.h"
#include <unordered_map>
#include <iostream>
class MissileLauncherComponent :  public Component
{
protected:
	std::unordered_map<int, bool> silos;
	Armament launcherType;
	DiceRoller dRoller;

public:

	/// <summary>
	/// Missile Launcher Constructor. Passes through laucnher type. 
	/// 4, 6, or 8 silos. 
	/// </summary>
	/// <param name="launcherType_"></param>
	MissileLauncherComponent(Armament launcherType_);
	~MissileLauncherComponent();

	/// <summary>
	/// Load Missile onto silo. Select silo based on launcher type.
	/// </summary>
	/// <param name="silo"></param>
	void LoadMissile(MissileComponent &missile);

	/// <summary>
	/// Expendes all missile silos
	/// </summary>
	void LaunchMissiles();

	/// <summary>
	/// Returns the amount of vacant slots for missiles.
	/// </summary>
	/// <returns>launcherSlot[0] as an int</returns>
	const int GetVacantSiloAmount() {
		int amount = 0;
		for (auto silo : silos)
		{
			if (!silo.second)
				amount++;
		}
		return amount;
	}

	/// <summary>
	/// Returns if a silo is loaded or not. Need to pass through silo number.
	/// </summary>
	/// <param name="silo"></param>
	/// <returns>a bool of true if the silo is used or false if silo is empty. Can return NULL if wrong silo number has been passed.</returns>
	const void GetSiloStatus() {
		
		for (auto silo : silos)
		{
			if(silo.second)
				std::cout << "\n Silo #" << silo.first + 1 << ": " << "LOADED.";
			else
				std::cout << "\n Silo #" << silo.first + 1 << ": " << "VACANT.";
		}
	}
};

