#pragma once
#include "Scene.h"
#include "Board.h"
#include "GameManager.h"
#include "Enums.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Battleship.h"
#include "EngineComponent.h"
#include "InventoryComponent.h"
#include "JAMISAsset.h"
#include "CommandCenterComponent.h"

class SceneGame: public Scene
{

	

public:
	explicit SceneGame(GameManager* game_);
	virtual ~SceneGame();

	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update();

	int RandomNumber(DiceType dice, int lastNum);
	void RunIntro();
	void SelectStarterShip();
	void LoadAssets();



private:
	bool starterShpSelected = false;
	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;
	
	Board theBoard;
	std::shared_ptr<Battleship> player;



	
};

