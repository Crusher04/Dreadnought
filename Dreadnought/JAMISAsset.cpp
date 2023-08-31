#include "JAMISAsset.h"

JAMISAsset::JAMISAsset(std::string name_, InventoryType iType):name{NULL}, invType{InventoryType::INV_NULL}
	,armamentType{Armament::ARMAMENT_NULL}, subsystemType{Subsystems::SUBSYSTEM_NULL}, itemType{Items::ITEM_NULL}
	,myAction{ActionType::ACTION_NULL}, damageDice{DiceType::DICE_NULL}, storageOrSlots{NULL}, rangeOfAttack{NULL}
	,diceMultiplier{NULL}, timeInAir{NULL}, isDestroyed{false}, mustBePrepared{NULL}, prepared{NULL}, returningToCarrier{NULL}
{
	name = name_;
	invType = iType;
}

JAMISAsset::~JAMISAsset()
{
	name.clear();
	armamentType = Armament::ARMAMENT_NULL;
	subsystemType = Subsystems::SUBSYSTEM_NULL;
	itemType = Items::ITEM_NULL;
	invType = InventoryType::INV_NULL;
	myAction = ActionType::ACTION_NULL;
	damageDice = DiceType::DICE_NULL;
	storageOrSlots = NULL;
	rangeOfAttack = NULL;
	diceMultiplier = NULL;
	timeInAir = NULL;
	isDestroyed = NULL;
	mustBePrepared = NULL;
	prepared = NULL;
	returningToCarrier = NULL;
}

void JAMISAsset::Initialize(Armament armType, char diceMultiplier_)
{
	switch (armType)
	{
	case Armament::NavalBattery250mm:
		myAction = ActionType::ACTION;
		damageDice = DiceType::D6;
		diceMultiplier = diceMultiplier_;
		rangeOfAttack = 30;
		isDestroyed = false;
		break;
	case Armament::NavalBattery400mm:
		myAction = ActionType::ACTION;
		damageDice = DiceType::D10;
		diceMultiplier = diceMultiplier_;
		rangeOfAttack = 30;
		isDestroyed = false;
		break;
	case Armament::AntiShipMissile:
		myAction = ActionType::ACTION;
		mustBePrepared = true;
		prepared = false;
		damageDice = DiceType::D12;
		diceMultiplier = diceMultiplier_;
		rangeOfAttack = 50;
		isDestroyed = false;
		break;
	case Armament::AntiShipTorpedo:
		myAction = ActionType::ACTION;
		mustBePrepared = true;
		prepared = false;
		damageDice = DiceType::D12;
		diceMultiplier = diceMultiplier_;
		rangeOfAttack = 50;
		isDestroyed = false;
		break;
	case Armament::SuperSonicCruiseMissile:
		myAction = ActionType::ACTION;
		mustBePrepared = true;
		prepared = false;
		damageDice = DiceType::D12;
		diceMultiplier = diceMultiplier_;
		rangeOfAttack = 70;
		isDestroyed = false;
		break;
	case Armament::MissileLauncher_4:
		myAction = ActionType::PASSIVE;
		storageOrSlots = 4;
		isDestroyed = false;
		break;
	case Armament::MissileLauncher_6:
		myAction = ActionType::PASSIVE;
		storageOrSlots = 6;
		isDestroyed = false;
		break;
	case Armament::MissileLauncher_8:
		myAction = ActionType::PASSIVE;
		storageOrSlots = 8;
		isDestroyed = false;
		break;
	case Armament::ActiveDefenceSystem:
		myAction = ActionType::PASSIVE;
		mustBePrepared = true;
		prepared = false;
		isDestroyed = false;
		break;
	case Armament::RailGun:
		myAction = ActionType::ACTION;
		damageDice = DiceType::D10;
		diceMultiplier = diceMultiplier_;
		mustBePrepared = true;
		prepared = false;
		isDestroyed = false;
		break;
	case Armament::F14Tomcat:
		myAction = ActionType::PASSIVE; 
		rangeOfAttack = 5;
		isDestroyed = false;
		returningToCarrier = false;
		break;

	case Armament::F18Hornet:
		myAction = ActionType::ACTION;
		rangeOfAttack = 5;
		damageDice = DiceType::D8;
		diceMultiplier = diceMultiplier_;
		isDestroyed = false;
		returningToCarrier = false;
		break;

	case Armament::MineDeployment:
		myAction = ActionType::ACTION;
		damageDice = DiceType::D8;
		diceMultiplier = diceMultiplier_;
		storageOrSlots = 5;
		isDestroyed = false;
		break;

	}
}

void JAMISAsset::Initialize(Subsystems subType)
{
	switch(subType) {
		
	}

}

void JAMISAsset::Initialize(Items itemType_)
{

}
