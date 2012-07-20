#include "preCompile.h"
#include "tra_village.h"
#include "UpdateData.h"
#include "Player.h"
#include "WorldSession.h"
Village::Village(uint32 vid, Player* player):
	WorldPlace(vid), _player(player)
{
	CreateForUpdate(VIL_FIELD_END);
	LoadVillageField();
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
	
	woodProd = GetWoodProd();
	clayProd = GetClayProd();
	ironProd = GetIronProd();
	cropProd = GetCropProd();
	res->Delete();
	
	return true;
}

bool Village::LoadVillageField()
{
	QueryResult* res = sDB.Query("SELECT * FROM s2_fdata where vref= %d", wref);
	if(res == NULL)
		return false;

	Field* field = res->Fetch();
	PlaceField placeField;
	for(size_t i=0; i<20; i++)
	{
		uint16 fLevel = field[2*i + 1].GetUInt16();
		uint16 fType = field[2*i + 2].GetUInt16();
		if(fLevel !=0)
		{
			placeField.fieldLevel = fLevel;
			placeField.fieldType = fType;
			placeFields[i] = placeField;
		}
	}
	return true;
}

bool Village::UpdateRes()
{
	uint32 currTime = (uint32)(time(NULL));
	assert(currTime >= lastupdate);
	uint32 diffTime = currTime - lastupdate;
	if(diffTime > 0)
	{
		wood += woodProd /3600 * diffTime;
		clay += clay /3600 * diffTime;
		iron += iron /3600 * diffTime;
		crop += crop /3600 * diffTime;
		if(wood > maxstore)
			wood = maxstore;
		if(clay > maxstore)
			clay = maxstore;
		if(iron > maxstore)
			iron = maxstore;
		if(crop > maxcrop)
			crop = maxcrop;
	}
	lastupdate = currTime;

	SetUInt32Value(VIL_FIELD_POP, pop);
	SetFloatValue(VIL_FIELD_WOOD, wood);
	SetFloatValue(VIL_FIELD_CLAY, clay);
	SetFloatValue(VIL_FIELD_IRON, iron);
	SetFloatValue(VIL_FIELD_CROP, crop);

	SetFloatValue(VIL_FIELD_WOOD_HOUR, woodProd);
	SetFloatValue(VIL_FIELD_CLAY_HOUR, clayProd);
	SetFloatValue(VIL_FIELD_IRON_HOUR, ironProd);
	SetFloatValue(VIL_FIELD_CROP_HOUR, cropProd);

	SetUInt32Value(VIL_FIELD_MAXSTORE, maxstore);
	SetUInt32Value(VIL_FIELD_MAXCROP, maxcrop);
	SetUInt32Value(VIL_FIELD_LOYALTY, loyalty);
	SetUInt32Value(VIL_FIELD_LASTUPDATE, lastupdate);

	WorldPacket packet;
	UpdateData updateData;
	ByteBuffer buf(512);
	UpdateMask updateMask;
	updateMask.SetCount(m_valuesCount);
	_SetUpdateBits(&updateMask, _player);
	BuildValuesUpdate(UPDATE_TYPE_VILLAGE, &buf, &updateMask, _player);

	updateData.AddUpdateBlock(buf);
	updateData.BuildPacket(&packet);
	_player->GetSession()->SendPacket(&packet);
	return true;
}

float Village::GetWoodProd()
{
	float sum = 0.0f;
	for(size_t i=0; i<placeFields.size();i++)
	{
		PlaceField placeField= placeFields[i];
		if(placeField.fieldLevel != 0 
			&& placeField.fieldType == TWood)
		{
			sum += 50.0f * placeField.fieldLevel;
		}
	}
	return sum;
}

float Village::GetIronProd()
{
	float sum = 0.0f;
	for(size_t i=0; i<placeFields.size();i++)
	{
		PlaceField placeField= placeFields[i];
		if(placeField.fieldLevel != 0 
			&& placeField.fieldType == TIron)
		{
			sum += 50.0f * placeField.fieldLevel;
		}
	}
	return sum;
}

float Village::GetClayProd()
{
	float sum = 0.0f;
	for(size_t i=0; i<placeFields.size();i++)
	{
		PlaceField placeField= placeFields[i];
		if(placeField.fieldLevel != 0 
			&& placeField.fieldType == TClay)
		{
			sum += 50.0f * placeField.fieldLevel;
		}
	}
	return sum;
}

float Village::GetCropProd()
{
	float sum = 0.0f;
	for(size_t i=0; i<placeFields.size();i++)
	{
		PlaceField placeField= placeFields[i];
		if(placeField.fieldLevel != 0 
			&& placeField.fieldType == TCrop)
		{
			sum += 50.0f * placeField.fieldLevel;
		}
	}
	return sum;
}