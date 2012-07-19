#include "preCompile.h"
#include "tra_worldPlace.h"

WorldPlace::WorldPlace(uint32 wid):wref(wid)
{

}

void WorldPlace::CreateForUpdate(uint16 valuesCount)
{
	UpdateObj::_CreateForUpdate(valuesCount);
}