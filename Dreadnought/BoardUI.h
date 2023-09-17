#pragma once
#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Enums.h"

class BoardUI
{
public:
	BoardUI();
	void MovePlayer(Battleship* player, MovementDirection direction);

	/// <summary>
	/// Renders the board
	/// </summary>
	void Render();

private:

	
	//Board/Chunk sizing arrays
	int boardSize[2];							//X,Y board size. 2D Array.
	int chunkDefault[2];						//Default ChunkSize X/Y 
	int chunkPosition[2];						//Where the chunk currently is. X/Y. Starts at 1,1
	
	//Symbol Variables
	char waterSymbol = 126;
	
};

