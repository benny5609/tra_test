#ifndef __WORLDRUNNABLE_H
#define __WORLDRUNNABLE_H

#include "Threading.h"
/// Heartbeat thread for the World
class WorldRunnable : public ACE_Based::Runnable
{
    public:
        void run();
};
#endif

