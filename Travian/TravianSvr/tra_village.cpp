#include "preCompile.h"
#include "tra_village.h"

Village::Village(uint32 vid):
	WorldPlace(vid)
{
	LoadVillageData();
}

bool Village::LoadVillageData()
{
	QueryResult* res = sDB.Query("SELECT * FROM s2_wdata left JOIN s2_vdata ON s2_vdata.wref = s2_wdata.id where s2_wdata.id = %d", wref);
	if(res == NULL)
		return false;
	
	Field* field = res->Fetch();
	wref = field[0].GetUInt32();
	fieldtype = field[1].GetUInt16();
	oasistype = field[2].GetUInt16();
	x = field[3].GetInt32();
	y = field[4].GetInt32();
	occupied = field[5].GetInt16();
	image = field[6].GetCppString();

	owner = field[8].GetUInt32();
	name = field[9].GetCppString();
	capital = field[10].GetUInt32();
	pop = field[11].GetUInt32();
	cp = field[12].GetUInt32();
	celebration = field[13].GetInt32();
	type = field[14].GetInt32();
	wood = field[15].GetFloat();
	clay = field[16].GetFloat();
	iron = field[17].GetFloat();
	maxstore = field[18].GetUInt32();
	crop = field[19].GetFloat();
	maxcrop = field[20].GetUInt32();
	lastupdate = field[21].GetUInt32();
	loyalty = field[22].GetUInt32();
	exp1 = field[23].GetInt32();
	exp2 = field[24].GetInt32();
	exp3 = field[25].GetInt32();
	created = field[26].GetInt32();
	natar = field[27].GetUInt32();
	starv = field[28].GetUInt32();
	evasion = field[29].GetUInt32();
	
	res->Delete();
	
	return true;
}