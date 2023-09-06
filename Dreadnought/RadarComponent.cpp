#include "RadarComponent.h"


RadarComponent::RadarComponent(Subsystems typeOfRadar): totalRadarDetection{shipEyeSight}
{
	componentType = InventoryType::SUBSYSTEM;

	switch (typeOfRadar)
	{
	case Subsystems::STANDARD_RADAR:
		totalRadarDetection = 50;
		break;
	case Subsystems::ADVANCED_RADAR:
		totalRadarDetection = 60;
		break;
	case Subsystems::SATELLITE_RADAR:
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

