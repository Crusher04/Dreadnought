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
	void TypeWrite(std::string s, int speed);

private:
	bool starterShpSelected = false;
	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;
	bool attackFlag = false;
	
	Board theBoard;
	std::shared_ptr<Battleship> player;
	std::unique_ptr<std::unordered_map<std::string, Keywords>> keywordsMap = std::make_unique<std::unordered_map<std::string, Keywords>>();

	//Base Components
	std::shared_ptr<CommandCenterComponent> cmdCenter;
	std::shared_ptr<RadarComponent> radar;
	std::shared_ptr<EngineComponent> engine;

	
	DiceRoller dRoller;
};

