/*******************************************************************************
* File Name:   mysqlDB.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/5/29  Tuesday  13:16:44
* Comments:  
*
********************************************************************************/

#ifndef __MYSQLDB_H__
#define __MYSQLDB_H__

#include "common.h"
#include "tra_enum.h"
#include "my_global.h"
#include "mysql.h"

class Mysql_DB
{
public:
	Mysql_DB();
	virtual ~Mysql_DB();
	bool connect_db();
	bool usr_register(const std::string& usr, const std::string& pwd, const std::string& email, E_TRIBE tribe, E_LOCATE locate, E_ACTIVE act);
	bool unRegister(const std::string& usr);
	bool deleteReinf(int id);
	bool updateResource(int vid, E_RESOURCE res, int num);
	bool checkExist(const std::string& usr_email, bool usrOrEmail);
	bool hasBeginnerProtection(int vid);
	bool updateUserFieldByName(int field, const std::string& value, const std::string& userName);
	bool updateUserFieldByID(int field, const std::string& value, int usrID);
	bool getUserFieldByName(int field, const std::string& userName);
	bool getUserFieldByID(int field, int usrID);
	bool login(const std::string& usr, const std::string& pwd);
	bool setDeleting(int uid, bool setDel);
	bool isDeleting(int uid);
	bool modifyGold(int uid, int gold);
	bool getUserArrayByName(const std::string& userName);
	bool getUserArrayByID(int usrID);
	bool activeModifyByName(const std::string& userName);
	bool activeModifyByID(int usrID);
	bool addActiveUser(const std::string& username, int time);
	bool updateActiveUser(const std::string& username, int time);
	bool checkactiveSession(const std::string& username, const std::string& sessid);
	bool getOnline(int uid);
	bool UpdateOnline(const std::string& username, int time, int uid, int mode);
	bool generateBase(E_LOCATE locate);
	bool setFieldTaken(int wid);
	bool addVillage(int wid, int uid, const std::string& username,int capital);
	//µØÐÎ?
	bool addResourceFields(int vid, int resType);
	bool isVillageOases(int wid);
	bool countOasisTroops(int vid);
	bool canConquerOasis(int vid, int wid);
	bool conquerOasis(int vid, int wid);
	bool modifyOasisLoyalty(int wid);
	bool populateOasis();
	bool populateOasisUnitsLow();
	bool populateOasisUnitsHigh();
	bool removeOases(int wid);
	int	 getVillageType(int wid);
	bool getVillageState(int wid);
	bool getVillagesID(int uid);
	bool getVillage(int vid);
	bool getVillageBattleData(int vid);
	int getPopulation(int uid);
	bool getVillageBattleData(int vid);
	bool getPopulation(int uid);
	bool getOasisV(int vid);
	bool getOasis(int vid);
	bool getOasisInfo(int wid);
	bool getVillageField(int field, int wid);
	bool setVillageField(int field, int wid, int value);
	bool setVillageLevel(int vid, int field, int value);
	bool getResourceLevel(int vid);
	bool getOasisField(int field, int wid);
protected:
	MYSQL *conn;
};
#endif  // end of guard mysqlDB.h
