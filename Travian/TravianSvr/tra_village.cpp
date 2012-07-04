#include "tra_village.h"
#include "TravianSvr.h"

Village::Village(uint32 vid)
{

}

bool Village::LoadTown()
{
	QueryResult* res = app->_db->Query("select * from s2_vdata ");
	if(res != NULL)
	{
		do
		{
			int wref = res->Fetch()[0].GetUInt32();
			int x = res->Fetch()[2].GetUInt32();
			int y = res->Fetch()[3].GetUInt32();
			//printf("%d__x:%d, y%d\n", wref, x, y);
		}
		while(res->NextRow());
		delete res;
	};

	return true;
}