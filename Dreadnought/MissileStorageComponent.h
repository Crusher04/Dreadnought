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
    MissileStorageComponent(Subsystems systemType_ );
    ~MissileStorageComponent();

    int GetStorageAmount() { return storage; }



};

