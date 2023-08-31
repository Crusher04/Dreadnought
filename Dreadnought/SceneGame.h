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


	//All Ship Assets
	std::shared_ptr<JAMISAsset> NavalBattery250;
	std::shared_ptr<JAMISAsset> NavalBattery400;
	std::shared_ptr<JAMISAsset> ASM;
	std::shared_ptr<JAMISAsset> AST;
	std::shared_ptr<JAMISAsset> SSCM;
	std::shared_ptr<JAMISAsset> MissileLauncher;
	std::shared_ptr<JAMISAsset> ADS;
	std::shared_ptr<JAMISAsset> RailGun;
	std::shared_ptr<JAMISAsset> F14Tomcat;
	std::shared_ptr<JAMISAsset> F18Hornet;
	std::shared_ptr<JAMISAsset> MDS;
	
	
};

