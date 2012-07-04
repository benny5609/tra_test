#include "tra_db.h"

bool TravianDB::usr_register(const std::string& usr, const std::string& pwd, const std::string& email, E_TRIBE tribe, E_LOCATE locate, E_ACTIVE act)
{
	return true;
}

bool TravianDB::unRegister(const std::string& usr)
{
	return true;
}

bool TravianDB::deleteReinf(int id)
{
	return true;
}

bool TravianDB::updateResource(int vid, E_RESOURCE res, int num)
{
	return true;
}

bool TravianDB::checkExist(const std::string& usr_email, bool usrOrEmail)
{
	return true;
}

bool TravianDB::hasBeginnerProtection(int vid)
{
	return true;
}

bool TravianDB::updateUserFieldByName(int field, const std::string& value, const std::string& userName)
{
	return true;
}

bool TravianDB::updateUserFieldByID(int field, const std::string& value, int usrID)
{
	return true;
}

bool TravianDB::getUserFieldByName(int field, const std::string& userName)
{
	return true;
}

bool TravianDB::getUserFieldByID(int field, int usrID)
{
	return true;
}

bool TravianDB::login(const std::string& usr, const std::string& pwd)
{
	return true;
}

bool TravianDB::setDeleting(int uid, bool setDel)
{
	return true;
}

bool TravianDB::isDeleting(int uid)
{
	return true;
}

bool TravianDB::modifyGold(int uid, int gold)
{
	return true;
}

bool TravianDB::getUserArrayByName(const std::string& userName)
{
	return true;
}

bool TravianDB::getUserArrayByID(int usrID)
{
	return true;
}

bool TravianDB::activeModifyByName(const std::string& userName)
{
	return true;
}

bool TravianDB::activeModifyByID(int usrID)
{
	return true;
}

bool TravianDB::addActiveUser(const std::string& username, int time)
{
	return true;
}

bool TravianDB::updateActiveUser(const std::string& username, int time)
{
	return true;
}

bool TravianDB::checkactiveSession(const std::string& username, const std::string& sessid)
{
	return true;
}

bool TravianDB::getOnline(int uid)
{
	return true;
}

bool TravianDB::UpdateOnline(const std::string& username, int time, int uid, int mode)
{
	return true;
}

bool TravianDB::generateBase(E_LOCATE locate)
{
	return true;
}

bool TravianDB::setFieldTaken(int wid)
{
	return true;
}

bool TravianDB::addVillage(int wid, int uid, const std::string& username,int capital)
{
	return true;
}

//µØÐÎ?
bool TravianDB::addResourceFields(int vid, int resType)
{
	return true;
}

bool TravianDB::isVillageOases(int wid)
{
	return true;
}

bool TravianDB::countOasisTroops(int vid)
{
	return true;
}

bool TravianDB::canConquerOasis(int vid, int wid)
{
	return true;
}

bool TravianDB::conquerOasis(int vid, int wid)
{
	return true;
}

bool TravianDB::modifyOasisLoyalty(int wid)
{
	return true;
}

bool TravianDB::populateOasis()
{
	return true;
}

bool TravianDB::populateOasisUnitsLow()
{
	return true;
}

bool TravianDB::populateOasisUnitsHigh()
{
	return true;
}

bool TravianDB::removeOases(int wid)
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
bool TravianDB::getVillageState(int wid)
{
	return true;
}

bool TravianDB::getVillagesID(int uid)
{
	return true;
}

bool TravianDB::getVillage(int vid)
{
	return true;
}

bool TravianDB::getVillageBattleData(int vid)
{
	return true;
}

bool TravianDB::getPopulation(int uid)
{
	return true;
}

bool TravianDB::getOasisV(int vid)
{
	return true;
}

bool TravianDB::getOasis(int vid)
{
	return true;
}

bool TravianDB::getOasisInfo(int wid)
{
	return true;
}

bool TravianDB::getVillageField(int field, int wid)
{
	return true;
}

bool TravianDB::setVillageField(int field, int wid, int value)
{
	return true;
}

bool TravianDB::setVillageLevel(int vid, int field, int value)
{
	return true;
}

bool TravianDB::getResourceLevel(int vid)
{
	return true;
}

bool TravianDB::getOasisField(int field, int wid)
{
	return true;
}

bool TravianDB::getCoor(int wid)
{
	return true;
}

bool TravianDB::getFLData(int id)
{
	return true;
}
//farmlist
bool TravianDB::checkVilExist(int wid)
{
	return true;
}

bool TravianDB::checkOasisExist(int wid)
{
	return true;
}

bool TravianDB::getAllianceName(int id)
{
	return true;
}

bool TravianDB::getAlliancePermissionByID(int id, int field)
{
	return true;
}

bool TravianDB::getAlliancePermissionByName(const std::string& usrName, int field)
{
	return true;
}

bool TravianDB::getAlliance(int id)
{
	return true;
}

bool TravianDB::setAlliName(int id, const std::string& name, const std::string& tag)
{
	return true;
}

bool TravianDB::isAllianceOwner(int id)
{
	return true;
}

bool TravianDB::allianceExist(int field, const std::string& ref)
{
	return true;
}

bool TravianDB::modifyPoints(int usrID, int point, int value)
{
	return true;
}

bool TravianDB::createAlliance(const std::string& tag, const std::string& name, int uid, int max)
{
	return true;
}

bool TravianDB::insertAlliNotice(int aid, const std::string& notice)
{
	return true;
}

bool TravianDB::deleteAlliance(int aid)
{
	return true;
}

bool TravianDB::readAlliNotice(int aid)
{
	return true;
}

bool TravianDB::createAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions)
{
	return true;
}

bool TravianDB::deleteAlliPermissions(int uid)
{
	return true;
}

bool TravianDB::updateAlliPermissions(int uid, int aid,const std::string& rank, int* pOptions)
{
	return true;
}

bool TravianDB::getAlliPermissions(int uid, int aid)
{
	return true;
}

bool TravianDB::submitAlliProfile(int aid, const std::string& notice, const std::string& desc)
{
	return true;
}

bool TravianDB::diplomacyInviteAdd(int alli1, int alli2, int type)
{
	return true;
}

bool TravianDB::diplomacyOwnOffers(int session_alli)
{
	return true;
}

bool TravianDB::getAllianceID(const std::string& name)
{
	return true;
}

bool TravianDB::getDiplomacy(int aid)
{
	return true;
}

bool TravianDB::diplomacyCancelOffer(int id)
{
	return true;
}

bool TravianDB::diplomacyInviteAccept(int id, int session_ali)
{
	return true;
}

bool TravianDB::diplomacyInviteDenied(int id, int session_ali)
{
	return true;
}

bool TravianDB::diplomacyInviteCheck(int session_ali)
{
	return true;
}

bool TravianDB::getAllianceWar(int aid)
{
	return true;
}

bool TravianDB::getAllianceWar2(int aid)
{
	return true;
}

bool TravianDB::getAllianceAlly(int aid, int type)
{
	return true;
}

bool TravianDB::diplomacyExistingRelationships(int session_ali)
{
	return true;
}

bool TravianDB::diplomacyExistingRelationships2(int session_ali)
{
	return true;
}

bool TravianDB::diplomacyCancelExistingRelationship(int id, int session_ali)
{
	return true;
}

bool TravianDB::getUserAlliance(int id)
{
	return true;
}


bool TravianDB::modifyResource(int vid, int wood, int clay, int iron, int crop)
{
	return true;
}

bool TravianDB::modifyOasisResource(int vid, int wood, int clay, int iron, int crop)
{
	return true;
}

bool TravianDB::getFieldLevel(int vid, int field)
{
	return true;
}

bool TravianDB::getFieldType(int vid, int field)
{
	return true;
}

bool TravianDB::getVSumField(int uid, int field)
{
	return true;
}

bool TravianDB::updateVillage(int vid)
{
	return true;
}

bool TravianDB::updateOasis(int vid)
{
	return true;
}

bool TravianDB::setVillageName(int vid, const std::string& name)
{
	return true;
}

bool TravianDB::modifyPop(int vid, int pop)
{
	return true;
}

bool TravianDB::addCP(int wid, int cp)
{
	return true;
}

bool TravianDB::addCel(int wid, int cel, int type)
{
	return true;
}

bool TravianDB::getCel()
{
	return true;
}

bool TravianDB::clearCel(int wid)
{
	return true;
}

bool TravianDB::setCelCp(int uid, int cp)
{
	return true;
}

bool TravianDB::clearExpansionSlot(int id)
{
	return true;
}

bool TravianDB::getInvitation(int uid)
{
	return true;
}

bool TravianDB::getAliInvitations(int aid)
{
	return true;
}

bool TravianDB::sendInvitation(int uid, int alli, int sender)
{
	return true;
}

bool TravianDB::removeInvitation(int id)
{
	return true;
}

bool TravianDB::sendMessage(int target, int owner, const std::string& topic, const std::string& msg, int sender ,int alli, int player, int coor, int report)
{
	return true;
}

bool TravianDB::setArchived(int id)
{
	return true;
}

bool TravianDB::setNorm(int id)
{
	return true;
}


bool TravianDB::getMessage(int id, int mode)
{
	return true;
}

bool TravianDB::getDelSent(int uid)
{
	return true;
}

bool TravianDB::getDelInbox(int uid)
{
	return true;
}

bool TravianDB::getDelArchive(int uid)
{
	return true;
}

bool TravianDB::unarchiveNotice(int id)
{
	return true;
}

bool TravianDB::archiveNotice(int id)
{
	return true;
}

bool TravianDB::removeNotice(int id)
{
	return true;
}

bool TravianDB::noticeViewed(int id)
{
	return true;
}

bool TravianDB::addNotice(int uid, int wid, int aid, int type, const std::string& notice, const std::string& data, int time)
{
	return true;
}

bool TravianDB::getNotice(int uid)
{
	return true;
}

bool TravianDB::getNotice2(int uid, int field)
{
	return true;
}

bool TravianDB::getNotice3(int uid)
{
	return true;
}

bool TravianDB::getNotice4(int uid)
{
	return true;
}

bool TravianDB::createTradeRoute(int uid, int wid, int from, int r1, int r2, int r3, int r4, int start, int deliveries, int merchant, int time, int timeleft)
{
	return true;
}

bool TravianDB::getTradeRoute(int uid)
{
	return true;
}

bool TravianDB::getTradeRoute2(int uid)
{
	return true;
}

bool TravianDB::getTradeRouteUid(int id)
{
	return true;
}

bool TravianDB::editTradeRoute(int id, int column, int value)
{
	return true;
}

bool TravianDB::deleteTradeRoute(int id)
{
	return true;
}

bool TravianDB::addBuilding(int vid, int field, int type, int loop, int time, int master, int level)
{
	return true;
}

bool TravianDB::removeBuilding(int id)
{
	return true;
}

bool TravianDB::addDemolition(int wid, int field)
{
	return true;
}

bool TravianDB::getDemolition(int wid)
{
	return true;
}

bool TravianDB::finishDemolition(int wid)
{
	return true;
}

bool TravianDB::delDemolition(int wid)
{
	return true;
}

bool TravianDB::getJobs(int wid)
{
	return true;
}

bool TravianDB::FinishWoodcutter(int wid)
{
	return true;
}

bool TravianDB::getMasterJobs(int wid)
{
	return true;
}

bool TravianDB::getMasterJobsByField(int wid, int field)
{
	return true;
}

bool TravianDB::getBuildingByField(int wid, int field)
{
	return true;
}

bool TravianDB::getBuildingByType(int wid, int type)
{
	return true;
}


bool TravianDB::getDorf1Building(int wid)
{
	return true;
}

bool TravianDB::getDorf2Building(int wid)
{
	return true;
}

bool TravianDB::updateBuildingWithMaster(int id, int time, int loop)
{
	return true;
}

bool TravianDB::getVillageByName(const std::string& name)
{
	return true;
}

bool TravianDB::setMarketAcc(int id)
{
	return true;
}

bool TravianDB::sendResource(int id, int wood, int clay, int iron, int crop ,int merchant, int mode)
{
	return true;
}

bool TravianDB::getResourcesBack(int vid, int gtype, int amount)
{
	return true;
}

bool TravianDB::getMarketField(int vid, int field)
{
	return true;
}

bool TravianDB::removeAcceptedOffer(int id)
{
	return true;
}

bool TravianDB::addMarket(int vid, int gtype, int gamt, int wtype, int wamt, int time, int alli, int mechant, int mode)
{
	return true;
}

bool TravianDB::getMarket(int vid, int mode)
{
	return true;
}

bool TravianDB::getMarketInfo(int id)
{
	return true;
}


bool TravianDB::setMovementProc(int mid)
{
	return true;
}

bool TravianDB::totalMerchantUsed(int vid)
{
	return true;
}

bool TravianDB::getMovement(int type, int vid, int mode)
{
	return true;
}

bool TravianDB::addA2b(const std::string& ckey, int time, int to, int* t, int type)
{
	return true;
}

bool TravianDB::getA2b(const std::string& ckey, int check)
{
	return true;
}

bool TravianDB::addMovement(int type, int from, int to, int ref1, int startTime, 
						   int endTime, int send,int wood, int clay, int iron, int crop, int ref2)
{
	return true;
}

bool TravianDB::addAttack(int vid, int* t, int type, int ctar1, int ctar2, int spy, int* b)
{
	return true;
}

bool TravianDB::modifyAttack(int aid, int unit, int amount)
{
	return true;
}

bool TravianDB::getRanking()
{
	return true;
}

bool TravianDB::getVRanking()
{
	return true;
}

bool TravianDB::getARanking()
{
	return true;
}

bool TravianDB::getUserByTribe(int tribe)
{
	return true;
}

bool TravianDB::getUserByAlliance(int aid)
{
	return true;
}

bool TravianDB::getHeroRanking()
{
	return true;
}

bool TravianDB::getAllMember(int aid)
{
	return true;
}

bool TravianDB::addUnits(int vid)
{
	return true;
}

bool TravianDB::getUnit(int vid)
{
	return true;
}

bool TravianDB::getUnitsNumber(int vid)
{
	return true;
}

bool TravianDB::getHero(int uid, int all)
{
	return true;
}

bool TravianDB::getHeroField(int uid, int field)
{
	return true;
}

bool TravianDB::modifyHero(int column, int value, int heroid, int mode)
{
	return true;
}

bool TravianDB::modifyHeroByOwner(int column, int value, int uid, int mode)
{
	return true;
}

bool TravianDB::modifyHeroXp(int column, int value, int heroid)
{
	return true;
}

bool TravianDB::addTech(int vid)
{
	return true;
}

bool TravianDB::addABTech(int vid)
{
	return true;
}

bool TravianDB::getABTech(int vid)
{
	return true;
}

bool TravianDB::addResearch(int vid, int tech, int time)
{
	return true;
}

bool TravianDB::getResearching(int vid)
{
	return true;
}

bool TravianDB::checkIfResearched(int vref, int unit)
{
	return true;
}

bool TravianDB::getTech(int vid)
{
	return true;
}

bool TravianDB::getTraining(int vid)
{
	return true;
}

bool TravianDB::countTraining(int vid)
{
	return true;
}

bool TravianDB::trainUnit(int vid, int unit, int amount, int pop, int eachTime, int time, int mode)
{
	return true;
}

bool TravianDB::updateTraining(int id, int trained, int each)
{
	return true;
}

bool TravianDB::modifyUnit(int vref)
{
	return true;
}

bool TravianDB::getEnforce(int vid, int from)
{
	return true;
}

bool TravianDB::addEnforce(int toID, int fromID)
{
	return true;
}

bool TravianDB::addEnforce2(int toID, int fromID, int tribe, int* dead)
{
	return true;
}

bool TravianDB::modifyEnforce(int id, int unit, int amount, int mode)
{
	return true;
}

bool TravianDB::getEnforceArray(int id, int mode)
{
	return true;
}

bool TravianDB::getEnforceVillage(int vid, int mode)
{
	return true;
}

bool TravianDB::getVillageMovement(int vid)
{
	return true;
}

//person pop
bool TravianDB::addClimberPop(int uid, int cp)
{
	return true;
}

bool TravianDB::removeClimberPop(int uid, int cp)
{
	return true;
}

bool TravianDB::addClimberRankPop(int uid, int cp)
{
	return true;
}

bool TravianDB::removeClimberRankPop(int uid, int cp)
{
	return true;
}

bool TravianDB::setClimberRankPop(int uid, int cp)
{
	return true;
}

bool TravianDB::updateOldRank(int uid, int cp)
{
	return true;
}

//ally pop
bool TravianDB::addClimberPopAlly(int uid, int cp)
{
	return true;
}

bool TravianDB::removeClimberPopAlly(int uid, int cp)
{
	return true;
}

bool TravianDB::addClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool TravianDB::removeClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool TravianDB::setClimberRankPopAlly(int uid, int cp)
{
	return true;
}

bool TravianDB::updateOldRankAlly(int uid, int cp)
{
	return true;
}


bool TravianDB::getTrainingList()
{
	return true;
}

bool TravianDB::getNeedDelete()
{
	return true;
}

bool TravianDB::countUser()
{
	return true;
}

bool TravianDB::countAlli()
{
	return true;
}

bool TravianDB::getResAvailable(int wid, int resType)
{
	return true;
}

bool TravianDB::Getowner(int vid)
{
	return true;
}

bool TravianDB::populateOasisData()
{
	return true;
}

bool TravianDB::getAvailableExpansionTraining()
{
	return true;
}


bool TravianDB::getMovementById(int mid)
{
	return true;
}

bool TravianDB::getVilFarmlist(int wid)
{
	return true;
}

bool TravianDB::getRaidList(int id)
{
	return true;
}

bool TravianDB::delFarmList(int id, int owner)
{
	return true;
}

bool TravianDB::delSlotFarm(int id)
{
	return true;
}

bool TravianDB::createFarmList(int wid, int owner, const std::string& name)
{
	return true;
}

bool TravianDB::addSlotFarm(int lid, int towRef, int x, int y, int distance, int* t)
{
	return true;
}

bool TravianDB::editSlotFarm(int eid,int lid, int towRef, int x, int y, int distance, int* t)
{
	return true;
}

bool TravianDB::getArrayMemberVillage(int uid)
{
	return true;
}

bool TravianDB::addPassword(int uid, int newPwd, int ConPwd)
{
	return true;
}

bool TravianDB::resetPassword(int uid, int ConPwd)
{
	return true;
}

bool TravianDB::getCropProdstarv(int wRef)
{
	return true;
}


//general statistics
bool TravianDB::addGeneralAttack(int casualties)
{
	return true;
}

bool TravianDB::getAttackByDate(int time)
{
	return true;
}

bool TravianDB::getAttackCasualties(int time)
{
	return true;
}

bool TravianDB::addFriend(int uid, int column, int friendID)
{
	return true;
}

bool TravianDB::deleteFriend(int uid, int column)
{
	return true;
}

bool TravianDB::checkFriends(int uid)
{
	return true;
}

bool TravianDB::setVillageEvasion(int vid)
{
	return true;
}
