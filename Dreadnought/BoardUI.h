#pragma once
#include <vector>
#include <iostream>
#include "Battleship.h"
#include "Enums.h"

class BoardUI
{
public:
	BoardUI();

	/// <summary>
	/// Renders the board
	/// </summary>
	void Render(Battleship* player);

private:
	
	//Board/Chunk sizing arrays
	int boardRenderSize[2];							//X,Y board size. 2D Array.
	int chunkDefault[2];						//Default ChunkSize X/Y 
	int chunkPosition[2];						//Where the chunk currently is. X/Y. Starts at 1,1
	
	
	
};

