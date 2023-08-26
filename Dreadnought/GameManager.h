#pragma once
#include "Board.h"
#include "Battleship.h"
#include "ConsoleFormatting.h"
#include "Scene.h"
#include "SceneMenu.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include<cstdlib>
#include <time.h> 

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Run();
	bool IsGameActive() { return *gameActive; }
	void Update();
	
	

private:
	enum class SCENENUMBER {
		SCENE_MAINMENU = 0,
		SCENE_GAME = 1
	};

	class Scene* currentScene;


	std::string userInput;
	ConsoleFormatting cFormat;
	bool* gameActive;

	bool BuildScene(SCENENUMBER scene_);
	
	
};

