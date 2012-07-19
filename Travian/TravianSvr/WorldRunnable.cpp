#include "preCompile.h"
#include "WorldSocketMgr.h"
#include "Common.h"
#include "World.h"
#include "WorldRunnable.h"
#include "timer.h"
#include <conio.h>
#define WORLD_SLEEP_CONST 50

/// Heartbeat for the World
void WorldRunnable::run()
{
    uint32 realCurrTime = 0;
    uint32 realPrevTime = getMSTime();

    uint32 prevSleepTime = 0;                               // used for balanced full tick time length near WORLD_SLEEP_CONST

	  sWorld->SetInitialWorldSettings();
    ///- While we have not World::m_stopEvent, update the world
    while (!World::IsStopped())
    {
		if(_kbhit())
		{
			if(_getch() == '=')
			{
				sWorld->StopNow(0);
				ACE_Based::Thread::Sleep(50);
			}
		}
        realCurrTime = getMSTime();

        uint32 diff = getMSTimeDiff(realPrevTime,realCurrTime);

        sWorld->Update( diff );
        realPrevTime = realCurrTime;

        // diff (D0) include time of previous sleep (d0) + tick time (t0)
        // we want that next d1 + t1 == WORLD_SLEEP_CONST
        // we can't know next t1 and then can use (t0 + d1) == WORLD_SLEEP_CONST requirement
        // d1 = WORLD_SLEEP_CONST - t0 = WORLD_SLEEP_CONST - (D0 - d0) = WORLD_SLEEP_CONST + d0 - D0
        if (diff <= WORLD_SLEEP_CONST+prevSleepTime)
        {
            prevSleepTime = WORLD_SLEEP_CONST+prevSleepTime-diff;
            ACE_Based::Thread::Sleep(prevSleepTime);
        }
        else
            prevSleepTime = 0;

    }

	sWorld->KickAll();
    sWorld->UpdateSessions( 1 );                             // real players unload required UpdateSessions call
	
    sWorldSocketMgr->StopNetwork();
}
