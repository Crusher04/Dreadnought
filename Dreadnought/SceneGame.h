#pragma once
#include "Scene.h"
#include "BoardUI.h"
#include "GameManager.h"
#include "Enums.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "AIController.h"

#include "Battleship.h"
#include "EngineComponent.h"
#include "CommandCenterComponent.h"
#include "RadarComponent.h"
#include "MissileStorageComponent.h"
#include "MissileComponent.h"
#include "NavalBatteriesComponent.h"
#include "MissileLauncherComponent.h"

#include "DiceRoller.h"

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
	void GetUserInput();
	void KeywordSelection();
	void PlayerAttack();
	void PlayerArmingOrLaunchingMissile();
	void TypeWrite(std::string s, int speed);
	void GoToCommandsHelp();

private:

	//Flags
	bool starterShpSelected = false;
	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;
	bool attackFlag = false;
	bool armMissileFlag = false;
	bool launchMissileFlag = false;
	bool commandsHelpFlag = false;
	bool commandsHelpIntroFlag = false;

	//Counters
	int clearScreenCounter = 0;

	BoardUI theBoard;
	std::shared_ptr<Battleship> player;
	std::unique_ptr<std::unordered_map<std::string, Keywords>> keywordsMap = std::make_unique<std::unordered_map<std::string, Keywords>>();
	std::unique_ptr<std::unordered_map<Commands,std::string >> commandsMap = std::make_unique<std::unordered_map<Commands,std::string>>();
	DiceRoller dRoller;


	AIController enemies;
};

