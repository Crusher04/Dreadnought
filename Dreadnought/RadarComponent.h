#pragma once
#include "Component.h"

class RadarComponent : public Component
{
private:
	const int shipEyeSight = 10;
	const int radarDefaultDistance = 50;
	int totalRader;

public:

	RadarComponent();
	~RadarComponent();

	


};

