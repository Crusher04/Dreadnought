#pragma once
#include "Component.h"
class MissileStorageComponent :
    public Component
{
protected:
    int storage;
public:

    /// <summary>
    /// Stores Missiles. Pass through type of component and storage amount.
    /// </summary>
    /// <param name="systemType"></param>
    MissileStorageComponent(Subsystems systemType_);
    ~MissileStorageComponent();

    /// <summary>
    /// Returns the amount of storage the ship has for missiles. 
    /// </summary>
    /// <returns>storage as an int</returns>
    const int GetStorageAmount() { return storage; }

    /// <summary>
    /// Returns  name of missile storage. 
    /// </summary>
    /// <returns>name as std::string </returns>
    const std::string GetName() { return name; }

};

