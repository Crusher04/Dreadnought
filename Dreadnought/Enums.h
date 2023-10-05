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

	STANDARD_RADAR,
	ADVANCED_RADAR,
	SATELLITE_RADAR,
	ADVANCED_TRACKING,
	COUNTERMEASURE_DETECTION,
	EARLY_WARNING,
	AUTO_WATER_DISPLACER,
	AUTO_FIRE_DETERENT ,
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
	SUBSYSTEM_NULL,
	RADAR,
	ENGINE,
	COMMAND_CENTER

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

enum class Keywords {
	KEYWORD_NULL,
	Quit,
	Menu,
	Back,
	Help,
	Attack,
	Move,
	Silo_Status,
	Load_Missile,
	Missile,
	Naval_Battery,
	Missile_Launcher,
	Arm_Missile,

};

enum class Commands {
	COMMAND_NULL,
	Attack,
	Move,
	Load_Missile,
	Arm_Missile,
	Silo_Status,
	End_Turn,
	Jets,
	Colour_Legend,
	Deploy_Jets,
	Prepare_Defense,
	Intro,
	Items,
	Ship_Components,
	Attack_Range,
	
};
#endif // !ENUM_H