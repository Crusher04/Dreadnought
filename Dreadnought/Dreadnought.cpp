/*
* Created & Designed by: Ahmed Hammoud
* Dreadnought is a rogue-like windows terminal game.
*/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "GameManager.h"

int main()
{
    GameManager game;

    while (game.IsGameActive())
    {
        game.Run();
    }

    { _CrtDumpMemoryLeaks(); }

    

    return 0;
}

