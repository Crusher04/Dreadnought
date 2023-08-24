#pragma once
#ifndef SCENE_H
#define SCENE_H
class Scene
{
public:
	
	virtual ~Scene() {}
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update() = 0;


};

#endif