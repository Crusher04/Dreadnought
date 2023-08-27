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

enum class Ships
{
	Dreadnought,
	SunkenLady,
	Idris,
	SuperNova,
	UNDEFINEDSHIP
};

enum class ActorType
{
	PLAYER,
	AI,
	UNDEFINEDACTOR
};

enum class Weapon {

}; 
#endif // !ENUM_H