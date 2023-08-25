#pragma once
#ifndef SCENEMENU
#define SCENEMENU
#include "Scene.h"	
#include <iostream>

class SceneMenu : public Scene
{
public:
	explicit SceneMenu();
	virtual ~SceneMenu() {}
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update();
	void GetUserInput();

protected:
	
};

#endif

