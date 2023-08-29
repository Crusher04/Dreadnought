#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "ConsoleFormatting.h"
#include "AdvancedIO.h"

enum class SCENENUMBER {
	SCENE_MAINMENU = 0,
	SCENE_GAME = 1,
	SCENE_HOWTOPLAY = 2
};

class Scene
{
public:
	virtual ~Scene() {}
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update() = 0;

protected:
	class GameManager* game = NULL;
	std::unique_ptr<std::string> userInput = std::make_unique<std::string>();
	ConsoleFormatting cFormat;
	AdvancedIO myIO;

};

#endif