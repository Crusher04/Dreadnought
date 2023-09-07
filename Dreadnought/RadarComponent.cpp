#include "RadarComponent.h"


RadarComponent::RadarComponent(Subsystems typeOfRadar): totalRadarDetection{shipEyeSight}
{
	componentType = InventoryType::SUBSYSTEM;

	switch (typeOfRadar)
	{
	case Subsystems::STANDARD_RADAR:
		name = "Standard Radar";
		totalRadarDetection = 50;
		break;
	case Subsystems::ADVANCED_RADAR:
		name = "Advanced Radar";
		totalRadarDetection = 60;
		break;
	case Subsystems::SATELLITE_RADAR:
		name = "Satellite Radar";
		totalRadarDetection = 80;
		break;
	default:
		totalRadarDetection = shipEyeSight;
		break;
	}
}

RadarComponent::~RadarComponent()
{
	totalRadarDetection = 0;
}

