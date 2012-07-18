#include "preCompile.h"
#include "tra_village.h"
#include "UpdateData.h"
#include "Player.h"
#include "WorldSession.h"
Village::Village(uint32 vid, Player* player):
	WorldPlace(vid), _player(player),m_valuesCount(VIL_FIELD_END)
{
	_InitValues();
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

void Village::_InitValues()
{
	m_uint32Values = new uint32[ m_valuesCount ];
	memset(m_uint32Values, 0, m_valuesCount*sizeof(uint32));

	m_uint32Values_mirror = new uint32[ m_valuesCount ];
	memset(m_uint32Values_mirror, 0, m_valuesCount*sizeof(uint32));

	m_objectUpdated = false;
}

void Village::_SetUpdateBits(UpdateMask *updateMask, Player* /*target*/) const
{
	for( uint16 index = 0; index < m_valuesCount; ++index )
	{
		if(m_uint32Values_mirror[index]!= m_uint32Values[index])
			updateMask->SetBit(index);
	}
}

void Village::SetInt32Value( uint16 index, int32 value )
{
	ASSERT( index < m_valuesCount);

	if(m_int32Values[ index ] != value)
	{
		m_int32Values[ index ] = value;
		m_objectUpdated = true;
	}
}

void Village::BuildValuesUpdate(uint8 updatetype, ByteBuffer * data, UpdateMask *updateMask) const
{
	if(!_player)
		return;

	ASSERT(updateMask && updateMask->GetCount() == m_valuesCount);
	*data << (uint8)updateMask->GetBlockCount();
	data->append( updateMask->GetMask(), updateMask->GetLength() );

	for( uint16 index = 0; index < m_valuesCount; ++index )
	{
		//where the bit is 1, need to update
		if(updateMask->GetBit(index))
		{
			*data << m_uint32Values[index];
		}
	}
}

void Village::SetUInt32Value( uint16 index, uint32 value )
{
	ASSERT( index < m_valuesCount);

	if(m_uint32Values[ index ] != value)
	{
		m_uint32Values[ index ] = value;
		m_objectUpdated = true;
	}
}

void Village::SetUInt64Value( uint16 index, const uint64 &value )
{
	ASSERT( index + 1 < m_valuesCount);
	if(*((uint64*)&(m_uint32Values[ index ])) != value)
	{
		m_uint32Values[ index ] = *((uint32*)&value);
		m_uint32Values[ index + 1 ] = *(((uint32*)&value) + 1);
		m_objectUpdated = true;
	}
}

void Village::SetFloatValue( uint16 index, float value )
{
	ASSERT( index < m_valuesCount);

	if(m_floatValues[ index ] != value)
	{
		m_floatValues[ index ] = value;
		m_objectUpdated = true;
	}
}

void Village::SetByteValue( uint16 index, uint8 offset, uint8 value )
{
	ASSERT( index < m_valuesCount);

	if(offset > 4)
	{
		printf("Object::SetByteValue: wrong offset %u", offset);
		return;
	}

	if(uint8(m_uint32Values[ index ] >> (offset * 8)) != value)
	{
		m_uint32Values[ index ] &= ~uint32(uint32(0xFF) << (offset * 8));
		m_uint32Values[ index ] |= uint32(uint32(value) << (offset * 8));
		m_objectUpdated = true;
	}
}

bool Village::UpdateRes()
{
	SetUInt32Value(VIL_FIELD_POP, pop);
	SetFloatValue(VIL_FIELD_WOOD, wood);
	SetFloatValue(VIL_FIELD_CLAY, clay);
	SetFloatValue(VIL_FIELD_IRON, iron);
	SetFloatValue(VIL_FIELD_CROP, crop);

	SetFloatValue(VIL_FIELD_WOOD_HOUR, 11);
	SetFloatValue(VIL_FIELD_CLAY_HOUR, 11);
	SetFloatValue(VIL_FIELD_IRON_HOUR, 11);
	SetFloatValue(VIL_FIELD_CROP_HOUR, 11);

	SetUInt32Value(VIL_FIELD_MAXSTORE, 11);
	SetUInt32Value(VIL_FIELD_MAXCROP, 11);
	SetUInt32Value(VIL_FIELD_LOYALTY, 11);

	WorldPacket packet;
	UpdateData updateData;
	ByteBuffer buf(512);
	UpdateMask updateMask;
	updateMask.SetCount(m_valuesCount);
	_SetUpdateBits(&updateMask, _player);
	BuildValuesUpdate(UPDATE_TYPE_VILLAGE, &buf, &updateMask);

	updateData.AddUpdateBlock(buf);
	updateData.BuildPacket(&packet);
	_player->GetSession()->SendPacket(&packet);
	return true;
}