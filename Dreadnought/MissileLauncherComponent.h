#pragma once
#include "Component.h"
#include "MissileComponent.h"
#include "DiceRoller.h"
#include<vector>
class MissileLauncherComponent :  public Component
{
protected:
	int launcherSlots[2];
	Armament launcherType;
	std::vector<MissileComponent> missileSilos;
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
	void LoadMissile(MissileComponent missile);

	/// <summary>
	/// Expendes all missile silos
	/// </summary>
	void LaunchMissiles();

	/// <summary>
	/// Returns the amount of silos in the launcher. 
	/// </summary>
	/// <returns>launcherSlot[0] as an int</returns>
	const int GetSiloAmount() { return launcherSlots[0]; }

	/// <summary>
	/// Returns if a silo is loaded or not. Need to pass through silo number.
	/// </summary>
	/// <param name="silo"></param>
	/// <returns>a bool of true if the silo is used or false if silo is empty. Can return NULL if wrong silo number has been passed.</returns>
	const bool GetSiloStatus(int silo) {
		return false;
	}
};

