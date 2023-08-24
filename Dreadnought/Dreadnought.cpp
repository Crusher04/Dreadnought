/*
* Created & Designed by: Ahmed Hammoud
* Dreadnought is a rogue-like windows terminal game.
*/

#include "GameManager.h"

int main()
{
    GameManager game;

    while (game.Run())
    {
        game.Update();
    }
    
    return 0;
}

