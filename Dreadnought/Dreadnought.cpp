/*
* Created & Designed by: Ahmed Hammoud
* Dreadnought is a rogue-like windows terminal game.
*/

#include "GameManager.h"

int main()
{
    GameManager game;

    while (game.IsGameActive())
    {
        game.Run();
    }
    
    return 0;
}

