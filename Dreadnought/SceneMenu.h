#pragma once
#ifndef SCENEMENU_H
#define SCENEMENU_H
#include "Scene.h"	
#include <fstream>
#include "ConsoleFormatting.h"
#include "GameManager.h"
#include "AdvancedIO.h"

class SceneMenu : public Scene
{
public:
	 SceneMenu(GameManager* game_);
	 virtual ~SceneMenu();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update();
	void GetUserInput();
	void Title();

protected:
	AdvancedIO IO;

};

#endif

