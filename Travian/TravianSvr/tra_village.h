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

class Village:public WorldPlace
{
public:
	Village(uint32 vid);
	bool LoadVillageData();

	uint32 owner;
	uint32 capital;
	uint32 pop;
	uint32 cp;
	int celebration;
	int type;
	float wood;
	float clay;
	float iron;
	uint32 crop;
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
};
#endif  // end of guard tra_village.h
