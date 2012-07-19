/*******************************************************************************
* File Name:   tra_oasis.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/19  Thursday  16:59:13
* Comments:  
*
********************************************************************************/

#ifndef __TRA_OASIS_H__
#define __TRA_OASIS_H__
#include "common.h"
#include "tra_worldPlace.h"

class Oasis:public WorldPlace
{
public:
	Oasis(uint32 vid, Player* player);
	bool LoadOasisData();

	bool UpdateRes();
	Player* _player;
	uint32 owner;
	int conqured;
	int type;
	float wood;
	float clay;
	float iron;
	float crop;
	uint32 maxstore;
	uint32 maxcrop;
	uint32 lastupdate;
	std::string name;
	uint32 loyalty;

protected:
};

#endif  // end of guard tra_oasis.h
