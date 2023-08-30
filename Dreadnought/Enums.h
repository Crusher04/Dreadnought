#pragma once
#ifndef ENUM_H
#define ENUM_H

enum class DiceType
{
	D4 = 4,
	D6 = 6,
	D8 = 8,
	D10 = 10,
	D12 = 12,
	D20 = 20,
	DICE_NULL
};

enum class ActionType {
	ACTION,
	BONUS_ACTION,
	PASSIVE,
	ACTION_NULL
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
	AntiShipMissile, 
	AntiShipTorpedo,
	SuperSonicCruiseMissile,
	ActiveDefenceSystem,
	RailGun,
	F14Tomcat,
	F18Hornet,
	MissileLauncher_4 = 4,
	MissileLauncher_6 = 6,
	MissileLauncher_8 = 8,
	MineDeployment,
	ARMAMENT_NULL
	
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

enum class Subsystems {

	ADVANCED_RADAR,
	ADVANCED_TRACKING,
	COUNTERMEASURE_DETECTION,
	EARLY_WARNING,
	AUTO_WATER_DISPLACER,
	AUTO_FIRE_DETERENT,
	MISSILE_STORAGE_5 = 5,
	MISSILE_STORAGE_10 = 10,
	MISSILE_STORAGE_15 = 15,
	MISSILE_STORAGE_20 = 20,
	MISSILE_STORAGE_25 = 25,
	Armour_20 = 20,
	Armour_30 = 30,
	Armour_35 = 35,
	Armour_40 = 40,
	Armour_50 = 50,
	ANTIMINE_RADAR,
	SUBSYSTEM_NULL

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
	ARMAMENT_REPAIRKIT,
	ITEM_NULL
};

/// <summary>
/// Describes the type of each inventory slot type for a ship.
/// Such as: Primary Armament Slots, Subsystem slots,
/// Jet Slots, Missile slots, Item Slots 
/// </summary>
/// <param name="PRIMARY, SUBSYSTEM, JET, MISSILES, ITEMS"></param>
enum class InventoryType {
	ARMAMENT,
	SUBSYSTEM,
	JET,
	MISSILES,
	ITEMS,
	INV_NULL
};
#endif // !ENUM_H