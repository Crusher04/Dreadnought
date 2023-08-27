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

enum class ShipType
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
#endif // !ENUM_H