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
#include "InventoryComponent.h"
#include "JAMISAsset.h"

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


	//All Ship Assets
	
	
};

