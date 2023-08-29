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

/// <summary>
/// Types of engine install onto ship. 
/// </summary>
/// <param name=" EV10, EV15, EV20, EV25, EV30, E_NULL"></param>
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
/// <param name="ADVANCED_RADAR,
///COUNTERMEASURE_DETECTION,
///EARLY_WARNING,
///ADVANCED_TRACKING,
///AUTO_WATER_DISPLACER,
///MISSILE_LAUNCHER_4SLOT,
///MISSILE_LAUNCHER_6SLOT,
///MISSILE_LAUNCHER_8SLOT,
///MISSILE_STORAGE_5,
///MISSILE_STORAGE_10,
///MISSILE_STORAGE_15,
///MISSILE_STORAGE_20,
///MISSILE_STORAGE_25,
///Armour_25,
///Armour_30,
///Armour_35,
///Armour_40,
///Armour_50"></param>
enum class Subsystems {

	ADVANCED_RADAR,
	ADVANCED_TRACKING,
	COUNTERMEASURE_DETECTION,
	EARLY_WARNING,
	ADVANCED_TRACKING,
	AUTO_WATER_DISPLACER,
	AUTO_FIRE_DETERENT,
	MISSILE_LAUNCHER_4SLOT = 4,
	MISSILE_LAUNCHER_6SLOT = 6,
	MISSILE_LAUNCHER_8SLOT = 8, 
	MISSILE_STORAGE_5 = 5,
	MISSILE_STORAGE_10 = 10,
	MISSILE_STORAGE_15 = 15,
	MISSILE_STORAGE_20 = 20,
	MISSILE_STORAGE_25 = 25,
	Armour_20 = 20,
	Armour_30 = 30,
	Armour_35 = 35,
	Armour_40 = 40,
	Armour_50 = 50

};

/// <summary>
/// Types of Itemms that users can buy and load into
/// an inventory system.
/// </summary>
/// <param name="HULL_REPAIRKIT, FIRE_DETERENT, SUBSYSTEM_REPAIRKIT, ARMAMENT_REPAIRKIT"></param>
enum class Items {
	HULL_REPAIRKIT,
	FIRE_DETERENT,
	SUBSYSTEM_REPAIRKIT,
	ARMAMENT_REPAIRKIT
};

/// <summary>
/// Describes the type of each inventory slot type for a ship.
/// Such as: Primary Armament Slots, Subsystem slots,
/// Jet Slots, Missile slots, Item Slots 
/// </summary>
/// <param name="PRIMARY, SUBSYSTEM, JET, MISSILES, ITEMS"></param>
enum class InventoryType {
	PRIMARY,
	SUBSYSTEM,
	JET,
	MISSILES,
	ITEMS
};
#endif // !ENUM_H