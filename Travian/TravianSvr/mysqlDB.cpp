#include "mysqlDB.h"

#define DB_ADDR "localhost"
#define DB_USER "root"
#define DB_PASSWORD ""
#define DB_NAME "s2"

Mysql_DB::Mysql_DB()
{
	printf("MySQL client version: %s\n", mysql_get_client_info());
	conn = mysql_init(NULL);

	if (conn == NULL) 
	{
		printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
	}
}

Mysql_DB::~Mysql_DB()
{
	if(conn)
		mysql_close(conn);
}

bool Mysql_DB::connect_db()
{
	if (mysql_real_connect(conn, DB_ADDR, DB_USER, 
		DB_PASSWORD, DB_NAME, 0, NULL, 0) == NULL) 
	{
		printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
		return false;
	}

	return true;
}


bool Mysql_DB::usr_register(const std::string& usr, const std::string& pwd, const std::string& email, E_TRIBE tribe, E_LOCATE locate, E_ACTIVE act)
{
	return true;
}

bool Mysql_DB::unRegister(const std::string& usr)
{
	return true;
}

bool Mysql_DB::deleteReinf(int id)
{
	return true;
}

bool Mysql_DB::updateResource(int vid, E_RESOURCE res, int num)
{
	return true;
}

bool Mysql_DB::checkExist(const std::string& usr_email, bool usrOrEmail)
{
	return true;
}

bool Mysql_DB::hasBeginnerProtection(int vid)
{
	return true;
}

bool Mysql_DB::updateUserFieldByName(int field, const std::string& value, const std::string& userName)
{
	return true;
}

bool Mysql_DB::updateUserFieldByID(int field, const std::string& value, int usrID)
{
	return true;
}

bool Mysql_DB::getUserFieldByName(int field, const std::string& userName)
{
	return true;
}

bool Mysql_DB::getUserFieldByID(int field, int usrID)
{
	return true;
}

bool Mysql_DB::login(const std::string& usr, const std::string& pwd)
{
	return true;
}

bool Mysql_DB::setDeleting(int uid, bool setDel)
{
	return true;
}

bool Mysql_DB::isDeleting(int uid)
{
	return true;
}

bool Mysql_DB::modifyGold(int uid, int gold)
{
	return true;
}

bool Mysql_DB::getUserArrayByName(const std::string& userName)
{
	return true;
}

bool Mysql_DB::getUserArrayByID(int usrID)
{
	return true;
}

bool Mysql_DB::activeModifyByName(const std::string& userName)
{
	return true;
}

bool Mysql_DB::activeModifyByID(int usrID)
{
	return true;
}

bool Mysql_DB::addActiveUser(const std::string& username, int time)
{
	return true;
}

bool Mysql_DB::updateActiveUser(const std::string& username, int time)
{
	return true;
}

bool Mysql_DB::checkactiveSession(const std::string& username, const std::string& sessid)
{
	return true;
}

bool Mysql_DB::getOnline(int uid)
{
	return true;
}

bool Mysql_DB::UpdateOnline(const std::string& username, int time, int uid, int mode)
{
	return true;
}

bool Mysql_DB::generateBase(E_LOCATE locate)
{
	return true;
}

bool Mysql_DB::setFieldTaken(int wid)
{
	return true;
}

bool Mysql_DB::addVillage(int wid, int uid, const std::string& username,int capital)
{
	return true;
}

//µØÐÎ?
bool Mysql_DB::addResourceFields(int vid, int resType)
{
	return true;
}

bool Mysql_DB::isVillageOases(int wid)
{
	return true;
}

bool Mysql_DB::countOasisTroops(int vid)
{
	return true;
}

bool Mysql_DB::canConquerOasis(int vid, int wid)
{
	return true;
}

bool Mysql_DB::conquerOasis(int vid, int wid)
{
	return true;
}

bool Mysql_DB::modifyOasisLoyalty(int wid)
{
	return true;
}

bool Mysql_DB::populateOasis()
{
	return true;
}

bool Mysql_DB::populateOasisUnitsLow()
{
	return true;
}

bool Mysql_DB::populateOasisUnitsHigh()
{
	return true;
}

bool Mysql_DB::removeOases(int wid)
{
	return true;
}

int	 getVillageType(int wid)
{
	return true;
}
//id, fieldtype
int	 getVillageType2(int wid)
{
	return true;
}
//oasistype
int	 getVillageType3(int wid)
{
	return true;
}
//all 
bool Mysql_DB::getVillageState(int wid)
{
	return true;
}

bool Mysql_DB::getVillagesID(int uid)
{
	return true;
}

bool Mysql_DB::getVillage(int vid)
{
	return true;
}

bool Mysql_DB::getVillageBattleData(int vid)
{
	return true;
}

bool Mysql_DB::getPopulation(int uid)
{
	return true;
}

bool Mysql_DB::getOasisV(int vid)
{
	return true;
}

bool Mysql_DB::getOasis(int vid)
{
	return true;
}

bool Mysql_DB::getOasisInfo(int wid)
{
	return true;
}

bool Mysql_DB::getVillageField(int field, int wid)
{
	return true;
}

bool Mysql_DB::setVillageField(int field, int wid, int value)
{
	return true;
}

bool Mysql_DB::setVillageLevel(int vid, int field, int value)
{
	return true;
}

bool Mysql_DB::getResourceLevel(int vid)
{
	return true;
}

bool Mysql_DB::getOasisField(int field, int wid)
{
	return true;
}

bool Mysql_DB::getCoor(int wid)
{
	return true;
}

bool Mysql_DB::getFLData(int id)
{
	return true;
}
//farmlist
bool Mysql_DB::checkVilExist(int wid)
{
	return true;
}

bool Mysql_DB::checkOasisExist(int wid)
{
	return true;
}

bool Mysql_DB::getAllianceName(int id)
{
	return true;
}

bool Mysql_DB::getAlliancePermissionByID(int id, int field)
{
	return true;
}

bool Mysql_DB::getAlliancePermissionByName(const std::string& usrName, int field)
{
	return true;
}

bool Mysql_DB::getAlliance(int id)
{
	return true;
}

bool Mysql_DB::setAlliName(int id, const std::string& name, const std::string& tag)
{
	return true;
}

bool Mysql_DB::isAllianceOwner(int id)
{
	return true;
}

bool Mysql_DB::allianceExist(int field, const std::string& ref)
{
	return true;
}

bool Mysql_DB::modifyPoints(int usrID, int point, int value)
{
	return true;
}

bool Mysql_DB::createAlliance(const std::string& tag, const std::string& name, int uid, int max)
{
	return true;
}

bool Mysql_DB::insertAlliNotice(int aid, const std::string& notice)
{
	return true;
}

bool Mysql_DB::deleteAlliance(int aid)
{
	return true;
}

bool Mysql_DB::readAlliNotice(int aid)
{
	return true;
}

bool Mysql_DB::createAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions)
{
	return true;
}

bool Mysql_DB::deleteAlliPermissions(int uid)
{
	return true;
}

bool Mysql_DB::updateAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions)
{
	return true;
}

bool Mysql_DB::getAlliPermissions(int uid, int aid)
{
	return true;
}

bool Mysql_DB::submitAlliProfile(int aid, const std::string& notice, const std::string& desc)
{
	return true;
}

bool Mysql_DB::diplomacyInviteAdd(int alli1, int alli2, int type)
{
	return true;
}

bool Mysql_DB::diplomacyOwnOffers(int session_alli)
{
	return true;
}

bool Mysql_DB::getAllianceID(const std::string& name)
{
	return true;
}

bool Mysql_DB::getDiplomacy(int aid)
{
	return true;
}

bool Mysql_DB::diplomacyCancelOffer(int id)
{
	return true;
}

bool Mysql_DB::diplomacyInviteAccept(int id, int session_ali)
{
	return true;
}

bool Mysql_DB::diplomacyInviteDenied(int id, int session_ali)
{
	return true;
}

bool Mysql_DB::diplomacyInviteCheck(int session_ali)
{
	return true;
}

bool Mysql_DB::getAllianceWar(int aid)
{
	return true;
}

bool Mysql_DB::getAllianceWar2(int aid)
{
	return true;
}

bool Mysql_DB::getAllianceAlly(int aid, int type)
{
	return true;
}

bool Mysql_DB::diplomacyExistingRelationships(int session_ali)
{
	return true;
}

bool Mysql_DB::diplomacyExistingRelationships2(int session_ali)
{
	return true;
}

bool Mysql_DB::diplomacyCancelExistingRelationship(int id, int session_ali)
{
	return true;
}

bool Mysql_DB::getUserAlliance(int id)
{
	return true;
}


bool Mysql_DB::modifyResource(int vid, int wood, int clay, int iron, int crop)
{
	return true;
}

bool Mysql_DB::modifyOasisResource(int vid, int wood, int clay, int iron, int crop)
{
	return true;
}

bool Mysql_DB::getFieldLevel(int vid, int field)
{
	return true;
}

bool Mysql_DB::getFieldType(int vid, int field)
{
	return true;
}

bool Mysql_DB::getVSumField(int uid, int field)
{
	return true;
}

bool Mysql_DB::updateVillage(int vid)
{
	return true;
}

bool Mysql_DB::updateOasis(int vid)
{
	return true;
}

bool Mysql_DB::setVillageName(int vid, const std::string& name)
{
	return true;
}

bool Mysql_DB::modifyPop(int vid, int pop)
{
	return true;
}

bool Mysql_DB::addCP(int wid, int cp)
{
	return true;
}

bool Mysql_DB::addCel(int wid, int cel, int type)
{
	return true;
}

bool Mysql_DB::getCel()
{
	return true;
}

bool Mysql_DB::clearCel(int wid)
{
	return true;
}

bool Mysql_DB::setCelCp(int uid, int cp)
{
	return true;
}

bool Mysql_DB::clearExpansionSlot(int id)
{
	return true;
}

bool Mysql_DB::getInvitation(int uid)
{
	return true;
}

bool Mysql_DB::getAliInvitations(int aid)
{
	return true;
}

bool Mysql_DB::sendInvitation(int uid, int alli, int sender)
{
	return true;
}

bool Mysql_DB::removeInvitation(int id)
{
	return true;
}

bool Mysql_DB::sendMessage(int target, int owner, const std::string& topic, const std::string& msg, int sender ,int alli, int player, int coor, int report)
{
	return true;
}

bool Mysql_DB::setArchived(int id)
{
	return true;
}

bool Mysql_DB::setNorm(int id)
{
	return true;
}


bool Mysql_DB::getMessage(int id, int mode)
{
	return true;
}

bool Mysql_DB::getDelSent(int uid)
{
	return true;
}

bool Mysql_DB::getDelInbox(int uid)
{
	return true;
}

bool Mysql_DB::getDelArchive(int uid)
{
	return true;
}

bool Mysql_DB::unarchiveNotice(int id)
{
	return true;
}

bool Mysql_DB::archiveNotice(int id)
{
	return true;
}

bool Mysql_DB::removeNotice(int id)
{
	return true;
}

bool Mysql_DB::noticeViewed(int id)
{
	return true;
}

bool Mysql_DB::addNotice(int uid, int wid, int aid, int type, const std::string& notice, const std::string& data, int time)
{
	return true;
}

bool Mysql_DB::getNotice(int uid)
{
	return true;
}

bool Mysql_DB::getNotice2(int uid, int field)
{
	return true;
}

bool Mysql_DB::getNotice3(int uid)
{
	return true;
}

bool Mysql_DB::getNotice4(int uid)
{
	return true;
}

bool Mysql_DB::createTradeRoute(int uid, int wid, int from, int r1, int r2, int r3, int r4, int start, int deliveries, int merchant, int time, int timeleft)
{
	return true;
}

bool Mysql_DB::getTradeRoute(int uid)
{
	return true;
}

bool Mysql_DB::getTradeRoute2(int uid)
{
	return true;
}

bool Mysql_DB::getTradeRouteUid(int id)
{
	return true;
}

bool Mysql_DB::editTradeRoute(int id, int column, int value)
{
	return true;
}

bool Mysql_DB::deleteTradeRoute(int id)
{
	return true;
}

bool Mysql_DB::addBuilding(int vid, int field, int type, int loop, int time, int master, int level)
{
	return true;
}

bool Mysql_DB::removeBuilding(int id)
{
	return true;
}

bool Mysql_DB::addDemolition(int wid, int field)
{
	return true;
}

bool Mysql_DB::getDemolition(int wid)
{
	return true;
}

bool Mysql_DB::finishDemolition(int wid)
{
	return true;
}

bool Mysql_DB::delDemolition(int wid)
{
	return true;
}

bool Mysql_DB::getJobs(int wid)
{
	return true;
}

bool Mysql_DB::FinishWoodcutter(int wid)
{
	return true;
}

bool Mysql_DB::getMasterJobs(int wid)
{
	return true;
}

bool Mysql_DB::getMasterJobsByField(int wid, int field)
{
	return true;
}

bool Mysql_DB::getBuildingByField(int wid, int field)
{
	return true;
}

bool Mysql_DB::getBuildingByType(int wid, int type)
{
	return true;
}


bool Mysql_DB::getDorf1Building(int wid)
{
	return true;
}

bool Mysql_DB::getDorf2Building(int wid)
{
	return true;
}

bool Mysql_DB::updateBuildingWithMaster(int id, int time, int loop)
{
	return true;
}

bool Mysql_DB::getVillageByName(const std::string& name)
{
	return true;
}

bool Mysql_DB::setMarketAcc(int id)
{
	return true;
}

bool Mysql_DB::sendResource(int id, int wood, int clay, int iron, int crop ,int merchant, int mode)
{
	return true;
}

bool Mysql_DB::getResourcesBack(int vid, int gtype, int amount)
{
	return true;
}

bool Mysql_DB::getMarketField(int vid, int field)
{
	return true;
}

bool Mysql_DB::removeAcceptedOffer(int id)
{
	return true;
}

bool Mysql_DB::addMarket(int vid, int gtype, int gamt, int wtype, int wamt, int time, int alli, int mechant, int mode)
{
	return true;
}

bool Mysql_DB::getMarket(int vid, int mode)
{
	return true;
}

bool Mysql_DB::getMarketInfo(int id)
{
	return true;
}


bool Mysql_DB::setMovementProc(int mid)
{
	return true;
}

bool Mysql_DB::totalMerchantUsed(int vid)
{
	return true;
}

bool Mysql_DB::getMovement(int type, int vid, int mode)
{
	return true;
}

bool Mysql_DB::addA2b(const std::string& ckey, int time, int to, int* t, int type)
{
	return true;
}

bool Mysql_DB::getA2b(const std::string& ckey, int check)
{
	return true;
}

bool Mysql_DB::addMovement(int type, int from, int to, int ref1, int startTime, 
						   int endTime, int send,int wood, int clay, int iron, int crop, int ref2)
{
	return true;
}

bool Mysql_DB::addAttack(int vid, int* t, int type, int ctar1, int ctar2, int spy, int* b)
{
	return true;
}

bool Mysql_DB::modifyAttack(int aid, int unit, int amount)
{
	return true;
}

bool Mysql_DB::getRanking()
{
	return true;
}

bool Mysql_DB::getVRanking()
{
	return true;
}

bool Mysql_DB::getARanking()
{
	return true;
}

bool Mysql_DB::getUserByTribe(int tribe)
{
	return true;
}

bool Mysql_DB::getUserByAlliance(int aid)
{
	return true;
}

bool Mysql_DB::getHeroRanking()
{
	return true;
}

bool Mysql_DB::getAllMember(int aid)
{
	return true;
}

bool Mysql_DB::addUnits(int vid)
{
	return true;
}

bool Mysql_DB::getUnit(int vid)
{
	return true;
}

bool Mysql_DB::getUnitsNumber(int vid)
{
	return true;
}

bool Mysql_DB::getHero(int uid, int all)
{
	return true;
}

bool Mysql_DB::getHeroField(int uid, int field)
{
	return true;
}

bool Mysql_DB::modifyHero(int column, int value, int heroid, int mode)
{
	return true;
}

bool Mysql_DB::modifyHeroByOwner(int column, int value, int uid, int mode)
{
	return true;
}

bool Mysql_DB::modifyHeroXp(int column, int value, int heroid)
{
	return true;
}

bool Mysql_DB::addTech(int vid)
{
	return true;
}

bool Mysql_DB::addABTech(int vid)
{
	return true;
}

bool Mysql_DB::getABTech(int vid)
{
	return true;
}

bool Mysql_DB::addResearch(int vid, int tech, int time)
{
	return true;
}

bool Mysql_DB::getResearching(int vid)
{
	return true;
}

bool Mysql_DB::checkIfResearched(int vref, int unit)
{
	return true;
}

bool Mysql_DB::getTech(int vid)
{
	return true;
}

bool Mysql_DB::getTraining(int vid)
{
	return true;
}

bool Mysql_DB::countTraining(int vid)
{
	return true;
}

bool Mysql_DB::trainUnit(int vid, int unit, int amount, int pop, int eachTime, int time, int mode)
{
	return true;
}

bool Mysql_DB::updateTraining(int id, int trained, int each)
{
	return true;
}

bool Mysql_DB::modifyUnit(int vref)
{
	return true;
}

bool Mysql_DB::getEnforce(int vid, int from)
{
	return true;
}

bool Mysql_DB::addEnforce(int toID, int fromID)
{
	return true;
}

bool Mysql_DB::addEnforce2(int toID, int fromID, int tribe, int* dead)
{
	return true;
}

bool Mysql_DB::modifyEnforce(int id, int unit, int amount, int mode)
{
	return true;
}

bool Mysql_DB::getEnforceArray(int id, int mode)
{
	return true;
}

bool Mysql_DB::getEnforceVillage(int vid, int mode)
{
	return true;
}

bool Mysql_DB::getVillageMovement(int vid)
{
	return true;
}

//person pop
bool Mysql_DB::addClimberPop(int uid, int cp)
{
	return true;
}

bool Mysql_DB::removeClimberPop(int uid, int cp)
{
	return true;
}

bool Mysql_DB::addClimberRankPop(int uid, int cp)
{
	return true;
}

bool Mysql_DB::removeClimberRankPop(int uid, int cp)
{
	return true;
}

bool Mysql_DB::setClimberRankPop(int uid, int cp)
{
	return true;
}

bool Mysql_DB::updateOldRank(int uid, int cp)
{
	return true;
}

//ally pop
bool Mysql_DB::addClimberPopAlly(int uid, int cp)
{
	return true;
}

bool Mysql_DB::removeClimberPopAlly(int uid, int cp)
{
	return true;
}

bool Mysql_DB::addClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool Mysql_DB::removeClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool Mysql_DB::setClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool Mysql_DB::updateOldRankAlly(int uid, int cp)
{
	return true;
}


bool Mysql_DB::getTrainingList()
{
	return true;
}

bool Mysql_DB::getNeedDelete()
{
	return true;
}

bool Mysql_DB::countUser()
{
	return true;
}

bool Mysql_DB::countAlli()
{
	return true;
}

bool Mysql_DB::getResAvailable(int wid, int resType)
{
	return true;
}

bool Mysql_DB::Getowner(int vid)
{
	return true;
}

bool Mysql_DB::populateOasisData()
{
	return true;
}

bool Mysql_DB::getAvailableExpansionTraining()
{
	return true;
}


bool Mysql_DB::getMovementById(int mid)
{
	return true;
}

bool Mysql_DB::getVilFarmlist(int wid)
{
	return true;
}

bool Mysql_DB::getRaidList(int id)
{
	return true;
}

bool Mysql_DB::delFarmList(int id, int owner)
{
	return true;
}

bool Mysql_DB::delSlotFarm(int id)
{
	return true;
}

bool Mysql_DB::createFarmList(int wid, int owner, const std::string& name)
{
	return true;
}

bool Mysql_DB::addSlotFarm(int lid, int towRef, int x, int y, int distance, int* t)
{
	return true;
}

bool Mysql_DB::editSlotFarm(int eid,int lid, int towRef, int x, int y, int distance, int* t)
{
	return true;
}

bool Mysql_DB::getArrayMemberVillage(int uid)
{
	return true;
}

bool Mysql_DB::addPassword(int uid, int newPwd, int ConPwd)
{
	return true;
}

bool Mysql_DB::resetPassword(int uid, int ConPwd)
{
	return true;
}

bool Mysql_DB::getCropProdstarv(int wRef)
{
	return true;
}


//general statistics
bool Mysql_DB::addGeneralAttack(int casualties)
{
	return true;
}

bool Mysql_DB::getAttackByDate(int time)
{
	return true;
}

bool Mysql_DB::getAttackCasualties(int time)
{
	return true;
}

bool Mysql_DB::addFriend(int uid, int column, int friendID)
{
	return true;
}

bool Mysql_DB::deleteFriend(int uid, int column)
{
	return true;
}

bool Mysql_DB::checkFriends(int uid)
{
	return true;
}

bool Mysql_DB::setVillageEvasion(int vid)
{
	return true;
}

