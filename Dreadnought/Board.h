#pragma once
#include <vector>
#include <iostream>
#include <map>

class Board
{
public:
	Board();
	bool Generate();
	void Display(int actorX, int actorY, int aiX, int aiY);

private:
	bool hasBeenGenerated = false;
	int boardX;
	int boardY;
	
};

