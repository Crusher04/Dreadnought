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
	NavalBattery250mm = 0,
	NavalBattery400mm = 1,
	AntiShipMissile = 2, 
	AntiShipTorpedo = 3,
	SuperSonicCruiseMissile = 5,
	ActiveDefenceSystem = 7,
	RailGun = 9,
	F14Tomcat = 10,
	F18Hornet = 11,
	MissileLauncher_4 = 4,
	MissileLauncher_6 = 6,
	MissileLauncher_8 = 8,
	MineDeployment = 12,
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

	ADVANCED_RADAR = 0,
	ADVANCED_TRACKING = 1,
	COUNTERMEASURE_DETECTION = 2,
	EARLY_WARNING = 3,
	AUTO_WATER_DISPLACER = 4,
	AUTO_FIRE_DETERENT = 6,
	MISSILE_STORAGE_5,
	MISSILE_STORAGE_10,
	MISSILE_STORAGE_15,
	MISSILE_STORAGE_20,
	MISSILE_STORAGE_25,
	Armour_20,
	Armour_30,
	Armour_35,
	Armour_40,
	Armour_50,
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