#pragma once
#include "Component.h"
#include "Battleship.h"
#include "MissileComponent.h"
#include "DiceRoller.h"
#include <unordered_map>
#include <iostream>
class MissileLauncherComponent :  public Component
{
protected:
	std::unordered_map<int, std::string> silos;
	Armament launcherType;
	DiceRoller dRoller;
	bool isLauncherEmpty;
	int siloCounter;
	
public:

	/// <summary>
	/// Missile Launcher Constructor. Passes through launcher type. 
	/// 4, 6, or 8 silos. 
	/// </summary>
	/// <param name="launcherType_"></param>
	MissileLauncherComponent(Armament launcherType_);
	~MissileLauncherComponent();


	/// <summary>
	/// Component update method ensures that certain logic checks are continuously checked. 
	/// </summary>
	void Update();

	/// <summary>
	/// Checks if all silos are empty. triggers boolean isLauncherEmpty if true
	/// </summary>
	void CheckIfLauncherIsEmpty();

	/// <summary>
	/// Load Missile onto silo. Select silo based on launcher type.
	/// </summary>
	/// <param name="silo"></param>
	bool LoadMissile(Battleship* ship);

	/// <summary>
	/// Expendes all missile silos
	/// </summary>
	bool LaunchMissile(Battleship* ship, int silo);

	/// <summary>
	/// Returns the amount of vacant slots for missiles.
	/// </summary>
	/// <returns>amount as an int</returns>
	const int GetVacantSiloAmount() {
		return 0;
	}

	/// <summary>
	/// Returns if a silo is loaded or not. Need to pass through silo number.
	/// </summary>
	/// <param name="silo"></param>
	/// <returns>a bool of true if the silo is used or false if silo is empty. Can return NULL if wrong silo number has been passed.</returns>
	const void GetSiloStatus(Battleship* ship);
	

	/// <summary>
	/// Returns the amount of silos in this launcher. 
	/// </summary>
	/// <returns> silos.size() as an size_t </returns>
	const size_t GetSiloMaxSize() {
		return silos.size();
	}

	/// <summary>
	/// Gets boolean flag that tells us if the launcher has missiles or not
	/// </summary>
	/// <returns></returns>
	const bool GetIsLauncherEmpty() { return isLauncherEmpty; }

	/// <summary>
	/// Arms Missiles in silo
	/// </summary>
	/// <param name="missile"></param>
	/// <returns>returns bool value if successful (true) or not successful (false)</returns>
	bool ArmMissileInSilo(Battleship* ship, int silo);
	
};

