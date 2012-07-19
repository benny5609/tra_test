#include "preCompile.h"
#include "UpdateObj.h"

UpdateObj::UpdateObj()
{
	m_valuesCount = 0;
	m_uint32Values = NULL;
	m_uint32Values_mirror = NULL;
}

UpdateObj::~UpdateObj()
{
	_ClearUpdateObj();
}

void UpdateObj::_ClearUpdateObj()
{
	if(m_uint32Values)
	{
		delete [] m_uint32Values;
		m_uint32Values = NULL;
	}
	if(m_uint32Values_mirror)
	{
		delete [] m_uint32Values_mirror;
		m_uint32Values_mirror = NULL;
	}
}

void UpdateObj::_CreateForUpdate(uint16 valuesCount)
{
	if(m_uint32Values)
		_ClearUpdateObj();
	
	m_valuesCount = valuesCount;
	_InitValues();
}

void UpdateObj::_InitValues()
{
	m_uint32Values = new uint32[ m_valuesCount ];
	memset(m_uint32Values, 0, m_valuesCount*sizeof(uint32));

	m_uint32Values_mirror = new uint32[ m_valuesCount ];
	memset(m_uint32Values_mirror, 0, m_valuesCount*sizeof(uint32));

	m_objectUpdated = false;
}

void UpdateObj::_SetUpdateBits(UpdateMask *updateMask, Player* /*target*/) const
{
	for( uint16 index = 0; index < m_valuesCount; ++index )
	{
		if(m_uint32Values_mirror[index]!= m_uint32Values[index])
			updateMask->SetBit(index);
	}
}

void UpdateObj::SetInt32Value( uint16 index, int32 value )
{
	ASSERT( index < m_valuesCount);

	if(m_int32Values[ index ] != value)
	{
		m_int32Values[ index ] = value;
		m_objectUpdated = true;
	}
}

void UpdateObj::BuildValuesUpdate(uint8 updatetype, ByteBuffer * data, UpdateMask *updateMask, Player* player) const
{
	if(!player)
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

void UpdateObj::SetUInt32Value( uint16 index, uint32 value )
{
	ASSERT( index < m_valuesCount);

	if(m_uint32Values[ index ] != value)
	{
		m_uint32Values[ index ] = value;
		m_objectUpdated = true;
	}
}

void UpdateObj::SetUInt64Value( uint16 index, const uint64 &value )
{
	ASSERT( index + 1 < m_valuesCount);
	if(*((uint64*)&(m_uint32Values[ index ])) != value)
	{
		m_uint32Values[ index ] = *((uint32*)&value);
		m_uint32Values[ index + 1 ] = *(((uint32*)&value) + 1);
		m_objectUpdated = true;
	}
}

void UpdateObj::SetFloatValue( uint16 index, float value )
{
	ASSERT( index < m_valuesCount);

	if(m_floatValues[ index ] != value)
	{
		m_floatValues[ index ] = value;
		m_objectUpdated = true;
	}
}

void UpdateObj::SetByteValue( uint16 index, uint8 offset, uint8 value )
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