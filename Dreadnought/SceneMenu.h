#pragma once
#ifndef SCENEMENU
#define SCENEMENU
#include "Scene.h"	
#include <iostream>
#include <fstream>
#include "ConsoleFormatting.h"
#include "GameManager.h"

class SceneMenu : public Scene
{
public:
	explicit SceneMenu();
	virtual ~SceneMenu() {}
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(bool* gameActive_);
	void GetUserInput(bool* gameActive_);
	void Title();

protected:
	std::string asciiBanner;
};

#endif

