#pragma once
#include "Component.h"
class SubsystemComponent : public Component
{
protected:
	Subsystems subsystemType;
	

	int adsBonus;
	int missileStorage;
	int armourBonus;
	int AntiMineRange;
	int AntiTorpedoAmount;

public:

	SubsystemComponent(Subsystems type);
	~SubsystemComponent();

	int ADSBonusCheck();
	int MissileStorageCheck();
	int ArmourBonusCheck();
	int AntiMineCheck();
	int AntiTorpedoCheck();
	
	Subsystems GetSubsystemType() { return subsystemType; }

};

