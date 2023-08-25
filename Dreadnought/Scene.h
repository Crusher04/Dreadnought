#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "ConsoleFormatting.h"

class Scene
{
public:
	
	virtual ~Scene() {}
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update() = 0;

protected:
	std::unique_ptr<std::string> userInput = std::make_unique<std::string>();
	ConsoleFormatting cFormat;
};

#endif