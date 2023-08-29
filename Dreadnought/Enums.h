#pragma once
#ifndef ENUM_H
#define ENUM_H

enum class DiceType
{
	D4,
	D6,
	D8,
	D10,
	D12,
	D20
};

enum class MovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum class ShipClassification
{
	Battleship,
	Destroyer,
	Submarine,
	AircraftCarrier
};

enum class Ships
{
	Dreadnought,
	SunkenLady,
	Idris,
	SuperNova,
	Neptune,
	UNDEFINEDSHIP
};

enum class ActorType
{
	PLAYER,
	AI,
	UNDEFINEDACTOR
};

enum class Armament {
	NavalBattery250mm,
	NavalBattery400mm,
	AntiShipMissile, //ASM
	AntiShipTorpedo,
	SuperSonicCruiseMissile,
	ActiveDefenceSystem,
	RailGun,
	F14Tomcat,
	F18Hornet
	
	
}; 

enum class ShipSystems
{
	FireControl,
	HullRepair,
	WaterDisplacement,
	AntiMineRadar,
	AdvancedShipRadar,
	Sonar
};

enum class EngineType {
	EV10 = 10,
	EV15 = 15,
	EV20 = 20,
	EV25 = 25,
	EV30 = 30,
	E_NULL = 0
};

/// <summary>
/// Subsystems that can be installed on ships. 
/// </summary>
enum class Subsystems {

	ADVANCED_RADAR,
	COUNTERMEASURE_DETECTION,
	EARLY_WARNING,
	ADVANCED_TRACKING,
	AUTO_WATER_DISPLACER,
	MISSILE_LAUNCHER_4SLOT,
	MISSILE_LAUNCHER_6SLOT,
	MISSILE_LAUNCHER_8SLOT, 
	MISSILE_STORAGE_5,
	MISSILE_STORAGE_10,
	MISSILE_STORAGE_15,
	MISSILE_STORAGE_20,
	MISSILE_STORAGE_25,
	Armour_25,
	Armour_30,
	Armour_35,
	Armour_40,
	Armour_50

};

enum class Items {
	HULL_REPAIRKIT,
	FIRE_DETERENT,
	SUBSYSTEM_REPAIRKIT,
	ARMAMENT_REPAIRKIT
};

enum class IventoryType {
	PRIMARY,
	SUBSYSTEM,
	JET,
	MISSILES,
	ITEMS
};
#endif // !ENUM_H