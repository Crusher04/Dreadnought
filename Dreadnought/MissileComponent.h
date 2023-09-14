#pragma once
#include "Component.h"
class MissileComponent :
    public Component
{

protected:
    Armament missileType;
    bool armed;
    bool loaded;
    DiceType damageDice;
    int rangeOfAttack;
    int diceMultiplier;
    int siloNumber;
    int missileNumber;

public:

    /// <summary>
    /// Constructor for Missile Component. Pass through missile type and it'll be assigned
    /// the proper damageDice, rangeOfAttac and diceMultiplier.
    /// </summary>
    /// <param name="missileType_"></param>
    MissileComponent(Armament missileType_);
    ~MissileComponent();


    /// <summary>
    /// Arm Missile. Sets armed to true.
    /// </summary>
    void ArmMissile() { armed = true; }

    /// <summary>
    /// Disarm Missile. Sets armed to false.
    /// </summary>
    void DisarmMissile() { armed = false; }

    /// <summary>
    /// const return of the armed status as bool.
    /// </summary>
    /// <returns></returns>
    const bool GetArmedStatus() { return armed; }

    /// <summary>
    /// Sets loaded bool to true
    /// </summary>
    void LoadMissile(int siloNumber_) { loaded = true; siloNumber = siloNumber_; }

    /// <summary>
    /// const Return of the missileType as enum armament.
    /// </summary>
    /// <returns></returns>
    const Armament GetMissileType() { return missileType; }

    /// <summary>
    /// Get RangeOfAttack as int. 
    /// This is a const return.
    /// </summary>
    /// <returns></returns>
    const int GetRangeOfAttack() { return rangeOfAttack; }

    /// <summary>
    /// Get DiceMultiplier as int.
    /// This is a const return.
    /// </summary>
    /// <returns></returns>
    const int GetDiceMultiplier() { return diceMultiplier; }

    /// <summary>
    /// Get Damage dicetype as DiceType enum. 
    /// This is a const return.
    /// </summary>
    /// <returns></returns>
    const DiceType GetDamageDice() { return damageDice; }

    /// <summary>
    /// Returns a boolean dictating whether the missile is loaded in a silo or not. 
    /// </summary>
    /// <returns>bool loaded</returns>
    const bool CheckIfLoaded() { return loaded; }

    /// <summary>
    /// Returns which silo the missile is loaded in.
    /// </summary>
    /// <returns>siloNumber as int</returns>
    const int GetSiloNumber() { return siloNumber; }
};

