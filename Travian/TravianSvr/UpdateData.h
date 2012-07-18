/*******************************************************************************
* File Name:   UpdateData.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/18  Wednesday  12:40:31
* Comments:  
*
********************************************************************************/

#ifndef __UPDATEDATA_H__
#define __UPDATEDATA_H__

class UpdateData
{
public:
	UpdateData();
	void AddUpdateBlock(const ByteBuffer &block);
	bool BuildPacket(WorldPacket *packet);
	bool HasData() { return m_blockCount > 0;}
	void Clear();

protected:
	uint32 m_blockCount;
	ByteBuffer m_data;
};

#endif  // end of guard UpdateData.h
