#pragma once
#include "Component.h"

class RadarComponent : public Component
{
private:
	const int shipEyeSight = 10;
	const int radarDefaultDistance = 50;
	int totalRadarDetection;
	Subsystems coreSubsystemType = Subsystems::RADAR;

public:

	/// <summary>
	/// Type of radar to be added; Standard, Advanced, Satellite.
	/// </summary>
	/// <param name="typeOfRadar"></param>
	RadarComponent(Subsystems typeOfRadar);

	///<summary>
	///Deconstructor for Radar Component
	/// </summary>
	~RadarComponent();

	const int GetRadarDistance() { return totalRadarDetection; }

};

