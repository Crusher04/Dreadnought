#pragma once
#include "Scene.h"
#include "AdvancedIO.h"
#include "ConsoleFormatting.h"
#include "GameManager.h"

class SceneHowToPlay: public Scene {

public:
	SceneHowToPlay(GameManager* game_);
	virtual ~SceneHowToPlay();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update();
	void GetUserInput();

private:
	ConsoleFormatting cFormat;
	AdvancedIO IO;
};