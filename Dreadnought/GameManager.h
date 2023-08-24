#pragma once
#include "Board.h"
#include "Battleship.h"
#include "ConsoleFormatting.h"
#include "Scene.h"
#include "SceneMenu.h"

enum DiceType
{
	D4,
	D6,
	D8,
	D10,
	D12,
	D20
};

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool Run();
	void Title();
	void Update();
	void GetUserInput();
	void Attack(Battleship friendly, ActorType actor);
	int RandomNumber(DiceType dice, int lastNum);
	void PauseAfterAction();
	



private:
	enum class SCENENUMBER {
		SCENE_MAIN_MENU = 0,
		SCENE_GAME = 1
	};

	class Scene* currentScene;

	bool gameActive = false;
	bool helpFlag = false;
	bool moveFlag = false;
	bool endTurn = false;
	bool aiOldPosFlag = false;



	std::string userInput;
	Board theBoard;
	Battleship playerOne;
	Battleship playerAI;
	ConsoleFormatting cFormat;

	bool BuildScene(SCENENUMBER scene_);
	
	
};

