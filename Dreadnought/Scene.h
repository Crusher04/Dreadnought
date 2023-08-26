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
	virtual void Update(bool* gameActive_) = 0;

protected:
	std::string userInput;
	ConsoleFormatting cFormat;
};

#endif