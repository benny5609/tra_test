/*******************************************************************************
* File Name:   tra_village.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/3  Tuesday  15:32:51
* Comments:  
*
********************************************************************************/

#ifndef __TRA_VILLAGE_H__
#define __TRA_VILLAGE_H__
#include "common.h"
#include "tra_worldPlace.h"

class Player;
class Village:public WorldPlace
{
public:
	Village(uint32 vid, Player* player);
	bool LoadVillageData();
	void InitValues() { _InitValues(); }
	void BuildValuesUpdate(uint8 updatetype, ByteBuffer *data, UpdateMask *updateMask) const;
	bool UpdateRes();
	const int32& GetInt32Value( uint16 index ) const
	{
		ASSERT( index < m_valuesCount);
		return m_int32Values[ index ];
	}

	const uint32& GetUInt32Value( uint16 index) const
	{
		ASSERT( index < m_valuesCount);
		return m_uint32Values[ index ];
	}

	const uint64& GetUInt64Value( uint16 index) const
	{
		ASSERT( index + 1 < m_valuesCount);
		return *((uint64*)&(m_uint32Values[ index ]));
	}

	const float& GetFloatValue( uint16 index ) const
	{
		ASSERT( index < m_valuesCount);
		return m_floatValues[ index ];
	}

	void SetInt32Value(  uint16 index,        int32  value );
	void SetUInt32Value( uint16 index,       uint32  value );
	void SetUInt64Value( uint16 index, const uint64 &value );
	void SetFloatValue(  uint16 index,       float   value );
	void SetByteValue(   uint16 index, uint8 offset, uint8 value );

	Player* _player;
	uint32 owner;
	uint32 capital;
	uint32 pop;
	uint32 cp;
	int celebration;
	int type;
	float wood;
	float clay;
	float iron;
	float crop;
	uint32 maxstore;
	uint32 maxcrop;
	uint32 lastupdate;
	int exp1;
	int exp2;
	int exp3;
	int created;
	uint32 natar;
	uint32 starv;
	uint32 evasion;
	std::string name;
	uint32 loyalty;

	//for updatedata
	union
	{
		int32  *m_int32Values;
		uint32 *m_uint32Values;
		float  *m_floatValues;
	};
	uint32 *m_uint32Values_mirror;
	uint16 m_valuesCount;
	bool m_objectUpdated;


protected:
	void _InitValues();
	virtual void _SetUpdateBits(UpdateMask *updateMask, Player *target) const;
};
#endif  // end of guard tra_village.h
