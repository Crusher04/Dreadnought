#pragma once
#include "Scene.h"
#include "Board.h"
#include <algorithm>
#include "GameManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Enums.h"
#include "Battleship.h"
#include "EngineComponent.h"

class SceneGame: public Scene
{

	

public:
	explicit SceneGame(GameManager* game_);
	virtual ~SceneGame();

	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update();

	void Attack(Battleship friendly, ActorType actor);
	int RandomNumber(DiceType dice, int lastNum);
	void InitializePlayer();
	void RunIntro();
	void SelectStarterShip();

private:
	bool starterShpSelected = false;
	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;
	
	Board theBoard;
	std::shared_ptr<Battleship> player;
	

};

