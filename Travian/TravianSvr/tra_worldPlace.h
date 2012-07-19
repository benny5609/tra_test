/*******************************************************************************
* File Name:   tra_worldPlace.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/10  Tuesday  14:41:00
* Comments:  
*
********************************************************************************/

#ifndef __TRA_WORLDPLACE_H__
#define __TRA_WORLDPLACE_H__
#include "common.h"
#include "UpdateObj.h"

class WorldPlace:public UpdateObj
{
public:
	WorldPlace(uint32 wid);
	void CreateForUpdate(uint16 valuesCount);
	uint32 wref;
	uint16 fieldtype;
	uint16 oasistype;
	int x;
	int y;
	int16 occupied;
	std::string image;
};

#endif  // end of guard tra_worldPlace.h

