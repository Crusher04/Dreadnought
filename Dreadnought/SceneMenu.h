#pragma once
#ifndef SCENEMENU_H
#define SCENEMENU_H
#include "Scene.h"	
#include <iostream>
#include <fstream>
#include "ConsoleFormatting.h"
#include "GameManager.h"

class SceneMenu : public Scene
{
public:
	 SceneMenu(GameManager* game_);
	 virtual ~SceneMenu();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(bool* gameActive_);
	void GetUserInput(bool* gameActive_);
	void Title();

protected:
	

};

#endif

