#include "preCompile.h"
#include "tra_oasis.h"
#include "UpdateData.h"
#include "Player.h"
#include "WorldSession.h"

Oasis::Oasis(uint32 vid, Player* player):WorldPlace(vid)
{

}

bool Oasis::LoadOasisData()
{
	return true;
}

bool Oasis::UpdateRes()
{
	return true;
}