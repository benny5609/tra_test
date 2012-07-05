#include "preCompile.h"
#include "tra_village.h"

Village::Village(uint32 vid)
{

}

bool Village::LoadTown()
{
	QueryResult* res = sDB.Query("select * from s2_vdata ");
	if(res == NULL)
		return false;
	
	int wref = res->Fetch()[0].GetUInt32();
	int x = res->Fetch()[2].GetUInt32();
	int y = res->Fetch()[3].GetUInt32();
	delete res;
	
	return true;
}