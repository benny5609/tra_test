#include "preCompile.h"
#include "UpdateData.h"

UpdateData::UpdateData():m_blockCount(0)
{

}

void UpdateData::AddUpdateBlock(const ByteBuffer &block)
{
	m_data.append(block);
	++m_blockCount;
}

bool UpdateData::BuildPacket(WorldPacket *packet)
{
	ASSERT(packet->empty());                                // shouldn't happen

	ByteBuffer buf(4 + m_data.wpos());
	buf << (uint32) (m_blockCount + 1);
	buf.append(m_data);
	packet->append( buf );
	packet->SetOpcode( SMSG_UPDATE_OBJECT );

	return true;
}

void UpdateData::Clear()
{

}