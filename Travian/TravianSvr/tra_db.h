/*******************************************************************************
* File Name:   tra_db.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/4  Wednesday  13:38:05
* Comments:  
*
********************************************************************************/

#ifndef __TRA_DB_H__
#define __TRA_DB_H__

#include "mysqlDB.h"
#include "field.h"
class TravianDB:public Mysql_DB
{
public:
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
	int	 getVillageType(int wid); //id, fieldtype
	int	 getVillageType2(int wid); //oasistype
	int	 getVillageType3(int wid); //all 
	bool getVillageState(int wid);
	bool getVillagesID(int uid);
	bool getVillage(int vid);
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
	bool getCoor(int wid);
	bool getFLData(int id); //farmlist
	bool checkVilExist(int wid);
	bool checkOasisExist(int wid);
	bool getAllianceName(int id);
	bool getAlliancePermissionByID(int id, int field);
	bool getAlliancePermissionByName(const std::string& usrName, int field);
	bool getAlliance(int id);
	bool setAlliName(int id, const std::string& name, const std::string& tag);
	bool isAllianceOwner(int id);
	bool allianceExist(int field, const std::string& ref);
	bool modifyPoints(int usrID, int point, int value);
	bool createAlliance(const std::string& tag, const std::string& name, int uid, int max);
	bool insertAlliNotice(int aid, const std::string& notice);
	bool deleteAlliance(int aid);
	bool readAlliNotice(int aid);
	bool createAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions);
	bool deleteAlliPermissions(int uid);
	bool updateAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions);
	bool getAlliPermissions(int uid, int aid);
	bool submitAlliProfile(int aid, const std::string& notice, const std::string& desc);
	bool diplomacyInviteAdd(int alli1, int alli2, int type);
	bool diplomacyOwnOffers(int session_alli);
	bool getAllianceID(const std::string& name);
	bool getDiplomacy(int aid);
	bool diplomacyCancelOffer(int id);
	bool diplomacyInviteAccept(int id, int session_ali);
	bool diplomacyInviteDenied(int id, int session_ali);
	bool diplomacyInviteCheck(int session_ali);
	bool getAllianceWar(int aid);
	bool getAllianceWar2(int aid);
	bool getAllianceAlly(int aid, int type);
	bool diplomacyExistingRelationships(int session_ali);
	bool diplomacyExistingRelationships2(int session_ali);
	bool diplomacyCancelExistingRelationship(int id, int session_ali);
	bool getUserAlliance(int id);

	bool modifyResource(int vid, int wood, int clay, int iron, int crop);
	bool modifyOasisResource(int vid, int wood, int clay, int iron, int crop);
	bool getFieldLevel(int vid, int field);
	bool getFieldType(int vid, int field);
	bool getVSumField(int uid, int field);
	bool updateVillage(int vid);
	bool updateOasis(int vid);
	bool setVillageName(int vid, const std::string& name);
	bool modifyPop(int vid, int pop);
	bool addCP(int wid, int cp);
	bool addCel(int wid, int cel, int type);
	bool getCel();
	bool clearCel(int wid);
	bool setCelCp(int uid, int cp);
	bool clearExpansionSlot(int id);
	bool getInvitation(int uid);
	bool getAliInvitations(int aid);
	bool sendInvitation(int uid, int alli, int sender);
	bool removeInvitation(int id);
	bool sendMessage(int target, int owner, const std::string& topic, const std::string& msg, int sender ,int alli, int player, int coor, int report);
	bool setArchived(int id);
	bool setNorm(int id);

	bool getMessage(int id, int mode);
	bool getDelSent(int uid);
	bool getDelInbox(int uid);
	bool getDelArchive(int uid);
	bool unarchiveNotice(int id);
	bool archiveNotice(int id);
	bool removeNotice(int id);
	bool noticeViewed(int id);
	bool addNotice(int uid, int wid, int aid, int type, const std::string& notice, const std::string& data, int time);
	bool getNotice(int uid);
	bool getNotice2(int uid, int field);
	bool getNotice3(int uid);
	bool getNotice4(int uid);
	bool createTradeRoute(int uid, int wid, int from, int r1, int r2, int r3, int r4, int start, int deliveries, int merchant, int time, int timeleft);
	bool getTradeRoute(int uid);
	bool getTradeRoute2(int uid);
	bool getTradeRouteUid(int id);
	bool editTradeRoute(int id, int column, int value);
	bool deleteTradeRoute(int id);
	bool addBuilding(int vid, int field, int type, int loop, int time, int master, int level);
	bool removeBuilding(int id);
	bool addDemolition(int wid, int field);
	bool getDemolition(int wid);
	bool finishDemolition(int wid);
	bool delDemolition(int wid);
	bool getJobs(int wid);
	bool FinishWoodcutter(int wid);
	bool getMasterJobs(int wid);
	bool getMasterJobsByField(int wid, int field);
	bool getBuildingByField(int wid, int field);
	bool getBuildingByType(int wid, int type);

	bool getDorf1Building(int wid);
	bool getDorf2Building(int wid);
	bool updateBuildingWithMaster(int id, int time, int loop);
	bool getVillageByName(const std::string& name);
	bool setMarketAcc(int id);
	bool sendResource(int id, int wood, int clay, int iron, int crop ,int merchant, int mode);
	bool getResourcesBack(int vid, int gtype, int amount);
	bool getMarketField(int vid, int field);
	bool removeAcceptedOffer(int id);
	bool addMarket(int vid, int gtype, int gamt, int wtype, int wamt, int time, int alli, int mechant, int mode);
	bool getMarket(int vid, int mode);
	bool getMarketInfo(int id);

	bool setMovementProc(int mid);
	bool totalMerchantUsed(int vid);
	bool getMovement(int type, int vid, int mode);
	bool addA2b(const std::string& ckey, int time, int to, int* t, int type);
	bool getA2b(const std::string& ckey, int check);
	bool addMovement(int type, int from, int to, int ref1, int startTime, 
		int endTime, int send,int wood, int clay, int iron, int crop, int ref2);
	bool addAttack(int vid, int* t, int type, int ctar1, int ctar2, int spy, int* b);
	bool modifyAttack(int aid, int unit, int amount);
	bool getRanking();
	bool getVRanking();
	bool getARanking();
	bool getUserByTribe(int tribe);
	bool getUserByAlliance(int aid);
	bool getHeroRanking();
	bool getAllMember(int aid);
	bool addUnits(int vid);
	bool getUnit(int vid);
	bool getUnitsNumber(int vid);
	bool getHero(int uid, int all);
	bool getHeroField(int uid, int field);
	bool modifyHero(int column, int value, int heroid, int mode);
	bool modifyHeroByOwner(int column, int value, int uid, int mode);
	bool modifyHeroXp(int column, int value, int heroid);
	bool addTech(int vid);
	bool addABTech(int vid);
	bool getABTech(int vid);
	bool addResearch(int vid, int tech, int time);
	bool getResearching(int vid);
	bool checkIfResearched(int vref, int unit);
	bool getTech(int vid);
	bool getTraining(int vid);
	bool countTraining(int vid);
	bool trainUnit(int vid, int unit, int amount, int pop, int eachTime, int time, int mode);
	bool updateTraining(int id, int trained, int each);
	bool modifyUnit(int vref);
	bool getEnforce(int vid, int from);
	bool addEnforce(int toID, int fromID);
	bool addEnforce2(int toID, int fromID, int tribe, int* dead);
	bool modifyEnforce(int id, int unit, int amount, int mode);
	bool getEnforceArray(int id, int mode);
	bool getEnforceVillage(int vid, int mode);
	bool getVillageMovement(int vid);
	//person pop
	bool addClimberPop(int uid, int cp);
	bool removeClimberPop(int uid, int cp);
	bool addClimberRankPop(int uid, int cp);
	bool removeClimberRankPop(int uid, int cp);
	bool setClimberRankPop(int uid, int cp);
	bool updateOldRank(int uid, int cp);
	//ally pop
	bool addClimberPopAlly(int uid, int cp);
	bool removeClimberPopAlly(int uid, int cp);
	bool addClimberRankPopAlly(int uid, int cp);
	bool removeClimberRankPopAlly(int uid, int cp);
	bool setClimberRankPopAlly(int uid, int cp);
	bool updateOldRankAlly(int uid, int cp);

	bool getTrainingList();
	bool getNeedDelete();
	bool countUser();
	bool countAlli();
	bool getResAvailable(int wid, int resType);
	bool Getowner(int vid);
	bool populateOasisData();
	bool getAvailableExpansionTraining();

	bool getMovementById(int mid);
	bool getVilFarmlist(int wid);
	bool getRaidList(int id);
	bool delFarmList(int id, int owner);
	bool delSlotFarm(int id);
	bool createFarmList(int wid, int owner, const std::string& name);
	bool addSlotFarm(int lid, int towRef, int x, int y, int distance, int* t);
	bool editSlotFarm(int eid,int lid, int towRef, int x, int y, int distance, int* t);
	bool getArrayMemberVillage(int uid);
	bool addPassword(int uid, int newPwd, int ConPwd);
	bool resetPassword(int uid, int ConPwd);
	bool getCropProdstarv(int wRef);

	//general statistics
	bool addGeneralAttack(int casualties);
	bool getAttackByDate(int time);
	bool getAttackCasualties(int time);
	bool addFriend(int uid, int column, int friendID);
	bool deleteFriend(int uid, int column);
	bool checkFriends(int uid);
	bool setVillageEvasion(int vid);
};
#endif  // end of guard tra_db.h
