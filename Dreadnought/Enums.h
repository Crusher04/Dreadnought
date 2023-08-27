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
	InterceptorSystem, //Point Defense Missile System PDSM
	RailGun,
	AntiAirGun,
	F14Jet,
	F18Jets
	
	
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