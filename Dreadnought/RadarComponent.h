#pragma once
#include "Component.h"

class RadarComponent : public Component
{
private:
	const int shipEyeSight = 10;
	const int radarDefaultDistance = 50;
	int totalRaderDetection;

	bool StandardRadarActive;
	bool AdvancedRadarActive;
	bool SatelliteRadarActive;

public:

	RadarComponent();
	~RadarComponent();
	
	int RadarDection(Subsystems typeOfRadar);
};

