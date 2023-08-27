#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Board.h"
#include "Battleship.h"
#include "ConsoleFormatting.h"
#include "Scene.h"
#include "SceneMenu.h"
#include "SceneGame.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include<cstdlib>
#include <time.h> 
#include <conio.h>
#include <stdio.h>

class GameManager
{
private:
	class Scene* currentScene;

	ConsoleFormatting cFormat;
	bool* gameActive;

public:
	

	GameManager();
	~GameManager();

	void Run();
	bool IsGameActive() { return *gameActive; }
	bool BuildScene(SCENENUMBER scene_);
	void Update();
	void SetGameActive(bool newValue) { *gameActive = newValue; }
	
	


	
	
};
#endif
