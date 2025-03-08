/*
* Created & Designed by: Ahmed Hammoud
* Dreadnought is a rogue-like windows terminal game.
*/


#include <stdlib.h>
#include <crtdbg.h>
#include "GameManager.h"
#include "MemoryMonitor.h"


#define _CRTDBG_MAP_ALLOC


int main()
{
    GameManager* game = DBG_NEW GameManager();

    while (game->IsGameActive())
    {
       game->Run();
    }

    delete game;

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
     _CrtDumpMemoryLeaks(); 
    return 0;

}

