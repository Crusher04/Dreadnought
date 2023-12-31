#pragma once

//Controls the movement and position of the ship
#include "Component.h"
#include <iostream>
#include "ConsoleFormatting.h"

class EngineComponent: public Component
{
private:
	bool setMovemementFlag = false;
	bool isSpawned = false;
	int movement = 0;
	int defaultNauticalMiles = 0;
	int position[2] = { 0,0 };
	ConsoleFormatting cFormat;

public:
	/// <summary>
	/// Engine Constructor
	/// </summary>
	EngineComponent(EngineType eType);

	///<summary>
	///Engine Deconstructor
	/// </summary>
	~EngineComponent();


	bool OnCreate();
	void OnDestroy();

	/// <summary>
	/// Gets the movement left on the ship. 
	/// </summary>
	/// <returns>int</returns>
	int GetMovement();

	/// <summary>
	/// Sets the initial spawn point of the ship
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void SetSpawn(int x, int y);

	/// <summary>
	/// Decrements movement by 5 Nautical Miles.
	/// </summary>
	void DecrementMovement();

	/// <summary>
	/// Sets new position of the ship
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void MoveShip(MovementDirection direction);

	/// <summary>
	/// Sets new position of ship with how far the ship wants to go
	/// </summary>
	/// <param name="direction"></param>
	/// <param name="distance"></param>
	void MoveShip(MovementDirection direction, int distance);

	//Resets Movement
	void ResetMovemnt();

	//Changes the engine type
	void ChangeEngineType(EngineType eType);

	//Return X / Y Positions
	int GetPositionX() { return position[0]; }
	int GetPositionY() { return position[1]; }




};

