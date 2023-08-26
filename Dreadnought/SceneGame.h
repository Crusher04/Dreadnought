#pragma once
#include "Scene.h"
#include "Battleship.h"	
#include "Board.h"
#include <algorithm>
#include "GameManager.h"

class SceneGame: public Scene
{

	enum DiceType
	{
		D4,
		D6,
		D8,
		D10,
		D12,
		D20
	};

public:
	explicit SceneGame(GameManager* game_);
	virtual ~SceneGame();

	virtual bool OnCreate();
	virtual void OnDestroy();

	virtual void Update(bool* gameActive_);
	void GetUserInput();
	void Attack(Battleship friendly, ActorType actor);
	int RandomNumber(DiceType dice, int lastNum);

private:
	bool gameActive = false;

	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;
	
	Board theBoard;
	Battleship playerOne;
	Battleship playerAI;
};

