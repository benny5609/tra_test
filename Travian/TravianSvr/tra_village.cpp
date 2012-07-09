#include "preCompile.h"
#include "tra_village.h"

Village::Village(uint32 vid):
	wref(vid)
{
	LoadVillageData();
}

bool Village::LoadVillageData()
{
	QueryResult* res = sDB.Query("select * from s2_vdata where wref = %d", wref);
	if(res == NULL)
		return false;
	
	int x = res->Fetch()[2].GetUInt32();
	int y = res->Fetch()[3].GetUInt32();

	res->Delete();
	
	return true;
}