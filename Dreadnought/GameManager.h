#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Battleship.h"
#include "ConsoleFormatting.h"
#include "Scene.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "SceneHowToPlay.h"
#include "AdvancedIO.h"
#include "Window.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include<cstdlib>
#include <time.h> 
#include <conio.h>
#include <stdio.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif



class GameManager
{
private:
	class Window* windowPtr;

	class Scene* currentScene;

	AdvancedIO IO;
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
