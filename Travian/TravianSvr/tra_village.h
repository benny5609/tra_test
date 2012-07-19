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

struct PlaceField
{
	PlaceField():fieldType(0),fieldLevel(0){}
	uint16 fieldType;
	uint16 fieldLevel;
};

class Village:public WorldPlace
{
public:
	Village(uint32 vid, Player* player);
	bool LoadVillageData();
	bool LoadVillageField();
	bool UpdateRes();
	float GetWoodProd();
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
	float woodProd;
	float clayProd;
	float ironProd;
	float cropProd;
	std::map<uint16, PlaceField> placeFields;

protected:
};
#endif  // end of guard tra_village.h
