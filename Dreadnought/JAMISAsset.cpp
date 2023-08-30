#include "JAMISAsset.h"

JAMISAsset::JAMISAsset(std::string name_, InventoryType iType):name{NULL}, invType{InventoryType::INV_NULL}
	,armamentType{Armament::ARMAMENT_NULL}, subsystemType{Subsystems::SUBSYSTEM_NULL}, itemType{Items::ITEM_NULL}
	,myAction{ActionType::ACTION_NULL}, damageDice{DiceType::DICE_NULL}, storageOrSlots{0}, rangeOfAttack{0}
	,diceMultiplier{1}, timeInAir{0}, isDestroyed{false}, mustBePrepared{NULL}, prepared{NULL}
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
}
