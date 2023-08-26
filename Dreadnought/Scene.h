#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "ConsoleFormatting.h"

enum SCENENUMBER {
	SCENE_MAINMENU = 0,
	SCENE_GAME = 1
};

class Scene
{
public:
	virtual ~Scene() {}
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(bool* gameActive_) = 0;

protected:
	class GameManager* game = NULL;
	std::string userInput;
	ConsoleFormatting cFormat;

};

#endif