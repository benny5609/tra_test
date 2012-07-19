/*******************************************************************************
* File Name:   UpdateObj.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/19  Thursday  9:43:13
* Comments:  
*
********************************************************************************/

#ifndef __UPDATEOBJ_H__
#define __UPDATEOBJ_H__
class ByteBuffer;
class UpdateMask;
class Player;

class UpdateObj
{
public:
	
	virtual ~UpdateObj();
	
	void BuildValuesUpdate(uint8 updatetype, ByteBuffer *data, UpdateMask *updateMask, Player* player) const;

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

	void SetInt32Value(uint16 index,        int32  value);
	void SetUInt32Value(uint16 index,       uint32  value);
	void SetUInt64Value(uint16 index, const uint64 &value);
	void SetFloatValue(uint16 index,       float   value);
	void SetByteValue(uint16 index, uint8 offset, uint8 value);


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
	UpdateObj();
	void _CreateForUpdate(uint16 valuesCount);
	void _ClearUpdateObj();
	void _InitValues();
	virtual void _SetUpdateBits(UpdateMask *updateMask, Player *target) const;

private:
	UpdateObj(const UpdateObj&);                              // prevent generation copy constructor
	UpdateObj& operator=(UpdateObj const&);  
};
#endif  // end of guard UpdateObj.h
