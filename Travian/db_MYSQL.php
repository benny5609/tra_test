<?php

/** --------------------------------------------------- **\
 * | ********* DO NOT REMOVE THIS COPYRIGHT NOTICE ********* |
 * +---------------------------------------------------------+
 * | Credits:     All the developers including the leaders:  |
 * |              K1d4r3              |
 * |                                                         |
 * | Copyright:   Travian Project All rights reserved       |
 * \** --------------------------------------------------- **/


        class MYSQL_DB {

        	std::string connection;
        	function MYSQL_DB() {
        		std::string this->connection = mysql_connect(SQL_SERVER, SQL_USER, SQL_PASS) or die(mysql_error());
        		mysql_select_db(SQL_DB, std::string this->connection) or die(mysql_error());
        	}

        	function register(std::string username, std::string password, std::string email, std::string tribe, std::string locate, std::string act) {
        		std::string time = time();
        		std::string timep = (time() + PROTECTION);
        		std::string q = "INSERT INTO tra_users (username,password,access,email,timestamp,tribe,location,act,protect) VALUES ('std::string username', 'std::string password', " . USER . ", 'std::string email', std::string time, std::string tribe, std::string locate, 'std::string act', std::string timep)";
        		if(mysql_query(std::string q, std::string this->connection)) {
        			return mysql_insert_id(std::string this->connection);
        		} else {
        			return false;
        		}
        	}

        	function activate(std::string username, std::string password, std::string email, std::string tribe, std::string locate, std::string act, std::string act2) {
        		std::string time = time();
        		std::string q = "INSERT INTO tra_activate (username,password,access,email,tribe,timestamp,location,act,act2) VALUES ('std::string username', 'std::string password', " . USER . ", 'std::string email', std::string tribe, std::string time, std::string locate, 'std::string act', 'std::string act2')";
        		if(mysql_query(std::string q, std::string this->connection)) {
        			return mysql_insert_id(std::string this->connection);
        		} else {
        			return false;
        		}
        	}

        	function unreg(std::string username) {
        		std::string q = "DELETE from tra_activate where username = 'std::string username'";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function deleteReinf(std::string id) {
        		std::string q = "DELETE from tra_enforcement where id = 'std::string id'";
        		mysql_query(std::string q, std::string this->connection);
        	}
        	function updateResource(std::string vid, std::string what, std::string number) {

        		std::string q = "UPDATE tra_vdata set " . std::string what . "=" . std::string number . " where wref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function checkExist(std::string ref, std::string mode) {

        		if(!std::string mode) {
        			std::string q = "SELECT username FROM tra_users where username = 'std::string ref' LIMIT 1";
        		} else {
        			std::string q = "SELECT email FROM tra_users where email = 'std::string ref' LIMIT 1";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function checkExist_activate(std::string ref, std::string mode) {

        		if(!std::string mode) {
        			std::string q = "SELECT username FROM tra_activate where username = 'std::string ref' LIMIT 1";
        		} else {
        			std::string q = "SELECT email FROM tra_activate where email = 'std::string ref' LIMIT 1";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

			public function hasBeginnerProtection(std::string vid) {
				std::string q = "SELECT u.protect FROM ".TB_PREFIX."users u,".TB_PREFIX."vdata v WHERE u.id=v.owner AND v.wref=".std::string vid;
				std::string result = mysql_query(std::string q, std::string this->connection);
				std::string dbarray = mysql_fetch_array(std::string result);
				if(!empty(std::string dbarray)) {
					if(time()<std::string dbarray[0]) {
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			}

        	function updateUserField(std::string ref, std::string field, std::string value, std::string switch) {
        		if(!std::string switch) {
        			std::string q = "UPDATE tra_users set std::string field = 'std::string value' where username = 'std::string ref'";
        		} else {
        			std::string q = "UPDATE tra_users set std::string field = 'std::string value' where id = 'std::string ref'";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getSitee(std::string uid) {
        		std::string q = "SELECT id from tra_users where sit1 = std::string uid or sit2 = std::string uid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function removeMeSit(std::string uid, std::string uid2) {
        		std::string q = "UPDATE tra_users set sit1 = 0 where id = std::string uid and sit1 = std::string uid2";
        		mysql_query(std::string q, std::string this->connection);
        		std::string q2 = "UPDATE tra_users set sit2 = 0 where id = std::string uid and sit2 = std::string uid2";
        		mysql_query(std::string q2, std::string this->connection);
        	}

        	function getUserField(std::string ref, std::string field, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT std::string field FROM tra_users where id = 'std::string ref'";
        		} else {
        			std::string q = "SELECT std::string field FROM tra_users where username = 'std::string ref'";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];
        	}

        	function getActivateField(std::string ref, std::string field, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT std::string field FROM tra_activate where id = 'std::string ref'";
        		} else {
        			std::string q = "SELECT std::string field FROM tra_activate where username = 'std::string ref'";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];
        	}

        	function login(std::string username, std::string password) {
        		std::string q = "SELECT password,sessid FROM tra_users where username = 'std::string username' and access != " . BANNED;
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		if(std::string dbarray['password'] == md5(std::string password)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function checkActivate(std::string act) {
        		std::string q = "SELECT * FROM tra_activate where act = 'std::string act'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);

        		return std::string dbarray;
        	}

        	function sitterLogin(std::string username, std::string password) {
        		std::string q = "SELECT sit1,sit2 FROM tra_users where username = 'std::string username' and access != " . BANNED;
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		if(std::string dbarray['sit1'] != 0) {
        			std::string q2 = "SELECT password FROM tra_users where id = " . std::string dbarray['sit1'] . " and access != " . BANNED;
        			std::string result2 = mysql_query(std::string q2, std::string this->connection);
        			std::string dbarray2 = mysql_fetch_array(std::string result2);
        		} else
        			if(std::string dbarray['sit2'] != 0) {
        				std::string q3 = "SELECT password FROM tra_users where id = " . std::string dbarray['sit2'] . " and access != " . BANNED;
        				std::string result3 = mysql_query(std::string q3, std::string this->connection);
        				std::string dbarray3 = mysql_fetch_array(std::string result3);
        			}
        		if(std::string dbarray['sit1'] != 0 || std::string dbarray['sit2'] != 0) {
        			if(std::string dbarray2['password'] == md5(std::string password) || std::string dbarray3['password'] == md5(std::string password)) {
        				return true;
        			} else {
        				return false;
        			}
        		} else {
        			return false;
        		}
        	}

        	function setDeleting(std::string uid, std::string mode) {
        		std::string time = time() + 72 * 3600;
        		if(!std::string mode) {
        			std::string q = "INSERT into tra_deleting values (std::string uid,std::string time)";
        		} else {
        			std::string q = "DELETE FROM tra_deleting where uid = std::string uid";
        		}
        		mysql_query(std::string q, std::string this->connection);
        	}

        	function isDeleting(std::string uid) {
        		std::string q = "SELECT timestamp from tra_deleting where uid = std::string uid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['timestamp'];
        	}

        	function modifyGold(std::string userid, std::string amt, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_users set gold = gold - std::string amt where id = std::string userid";
        		} else {
        			std::string q = "UPDATE tra_users set gold = gold + std::string amt where id = std::string userid";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/*****************************************
        	Function to retrieve user array via Username or ID
        	Mode 0: Search by Username
        	Mode 1: Search by ID
        	References: Alliance ID
        	*****************************************/

        	function getUserArray(std::string ref, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT * FROM tra_users where username = 'std::string ref'";
        		} else {
        			std::string q = "SELECT * FROM tra_users where id = std::string ref";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function activeModify(std::string username, std::string mode) {
        		std::string time = time();
        		if(!std::string mode) {
        			std::string q = "INSERT into tra_active VALUES ('std::string username',std::string time)";
        		} else {
        			std::string q = "DELETE FROM tra_active where username = 'std::string username'";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addActiveUser(std::string username, std::string time) {
        		std::string q = "REPLACE into tra_active values ('std::string username',std::string time)";
        		if(mysql_query(std::string q, std::string this->connection)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function updateActiveUser(std::string username, std::string time) {
        		std::string q = "REPLACE into tra_active values ('std::string username',std::string time)";
        		std::string q2 = "UPDATE tra_users set timestamp = std::string time where username = 'std::string username'";
        		std::string exec1 = mysql_query(std::string q, std::string this->connection);
        		std::string exec2 = mysql_query(std::string q2, std::string this->connection);
        		if(std::string exec1 && std::string exec2) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function checkactiveSession(std::string username, std::string sessid) {
        		std::string q = "SELECT username FROM tra_users where username = 'std::string username' and sessid = 'std::string sessid' LIMIT 1";
        		std::string result = mysql_query(std::string q, std::string this->connection);   
        		if(mysql_num_rows(std::string result) != 0) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function submitProfile(std::string uid, std::string gender, std::string location, std::string birthday, std::string des1, std::string des2) {
        		std::string q = "UPDATE tra_users set gender = std::string gender, location = 'std::string location', birthday = 'std::string birthday', desc1 = 'std::string des1', desc2 = 'std::string des2' where id = std::string uid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function gpack(std::string uid, std::string gpack) {
        		std::string q = "UPDATE tra_users set gpack = 'std::string gpack' where id = std::string uid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function UpdateOnline(std::string mode, std::string name = "", std::string time = "") {
        		global std::string session;
        		if(std::string mode == "login") {
        			std::string q = "INSERT IGNORE INTO tra_online (name, time) VALUES ('std::string name', " . time() . ")";
        			return mysql_query(std::string q, std::string this->connection);
        		} else {
        			std::string q = "DELETE FROM tra_online WHERE name ='" . std::string session->username . "'";
        			return mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	function generateBase(std::string sector) {
        		std::string qeinde = "9999";
        		std::string sector = rand(1, 4);
        		std::string query = "select * from tra_wdata where fieldtype = 3 and occupied = 0";
        		std::string result = mysql_query(std::string query, std::string this->connection);
        		for(std::string i = 0; std::string row = mysql_fetch_assoc(std::string result); std::string i++) {
        			std::string oke = '1';
        			std::string x = std::string row['x'];
        			std::string y = std::string row['y'];
        			if(std::string x[0] == "-") {
        				std::string x = (std::string x * -1);
        				if(std::string sector == '2' or std::string sector == '4') {
        					std::string oke = '0';
        				}
        			} else {
        				if(std::string sector == '1' or std::string sector == '3') {
        					std::string oke = '0';
        				}
        			}
        			if(std::string y[0] == "-") {
        				std::string y = (std::string y * -1);
        				if(std::string sector == '1' or std::string sector == '2') {
        					std::string oke = '0';
        				}
        			} else {
        				if(std::string sector == '3' or std::string sector == '4') {
        					std::string oke = '0';
        				}
        			}
        			std::string afstand = sqrt(pow(std::string x, 2) + pow(std::string y, 2));
        			if(std::string oke == '1') {
        				if(std::string qeinde > std::string afstand) {
        					std::string rand = rand(1, 10);
        					if(std::string rand == '3') {
        						std::string qeinde = std::string afstand;
        						std::string qid = std::string row['id'];
        					}
        				}
        			}
        		}
        		if(isset(std::string qid)) {
        			return std::string qid;
        		} else {
        			std::string query = "select * from tra_wdata where fieldtype = 3 and occupied = 0 LIMIT 0,1";
        			std::string result = mysql_query(std::string query, std::string this->connection);
        			std::string row = mysql_fetch_array(std::string result);
        			return std::string row['id'];
        		}
        	}

        	function setFieldTaken(std::string id) {
        		std::string q = "UPDATE tra_wdata set occupied = 1 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addVillage(std::string wid, std::string uid, std::string username, std::string capital) {
        		std::string total = count(std::string this->getVillagesID(std::string uid));
        		if(std::string total >= 1) {
        			std::string vname = std::string username . "\ village" . (std::string total + 1);
        		} else {
        			std::string vname = std::string username . "\ village";
        		}
        		std::string time = time();
        		std::string q = "INSERT into tra_vdata (wref, owner, name, capital, pop, cp, celebration, wood, clay, iron, maxstore, crop, maxcrop, lastupdate, created) values ('std::string wid', 'std::string uid', 'std::string vname', 'std::string capital', 2, 1, 0, 750, 750, 750, ".STORAGE_BASE.", 750, ".STORAGE_BASE.", 'std::string time', 'std::string time')";
        		return mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        	}

        	function addResourceFields(std::string vid, std::string type) {
        		switch(std::string type) {
        			case 1:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,4,4,1,4,4,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 2:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,3,4,1,3,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 3:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,1,4,1,3,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 4:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,1,4,1,2,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 5:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,1,4,1,3,1,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 6:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,4,4,1,3,4,4,4,4,4,4,4,4,4,4,4,2,4,4,1,15)";
        				break;
        			case 7:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,1,4,4,1,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 8:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,3,4,4,1,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 9:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,3,4,4,1,1,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 10:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,3,4,1,2,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        			case 11:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,3,1,1,3,1,4,4,3,3,4,4,3,1,4,4,2,4,4,1,15)";
        				break;
        			case 12:
        				std::string q = "INSERT into tra_fdata (vref,f1t,f2t,f3t,f4t,f5t,f6t,f7t,f8t,f9t,f10t,f11t,f12t,f13t,f14t,f15t,f16t,f17t,f18t,f26,f26t) values(std::string vid,1,4,1,1,2,2,3,4,4,3,3,4,4,1,4,2,1,2,1,15)";
        				break;
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function isVillageOases(std::string wref) {
        		std::string q = "SELECT id, oasistype FROM tra_wdata where id = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['oasistype'];
        	}

			public function VillageOasisCount(std::string vref) {
				std::string q = "SELECT count(*) FROM `".TB_PREFIX."odata` WHERE conqured=std::string vref";
				std::string result = mysql_query(std::string q, std::string this->connection);
				std::string row = mysql_fetch_row(std::string result);
				return std::string row[0];
			}

			public function canConquerOasis(std::string vref,std::string wref) {
				std::string AttackerFields = std::string this->getResourceLevel(std::string vref);
				for(std::string i=19;std::string i<=38;std::string i++) {
					if(std::string AttackerFields['f'.std::string i.'t'] == 37) { std::string HeroMansionLevel = std::string AttackerFields['f'.std::string i]; }
				}
				if(std::string this->VillageOasisCount(std::string vref) < floor((std::string HeroMansionLevel-5)/5)) {
					std::string OasisInfo = std::string this->getOasisInfo(std::string wref);
					if(std::string OasisInfo['conqured'] == 0 || std::string OasisInfo['conqured'] != 0 && std::string OasisInfo['loyalty'] < 99 / min(3,(4-std::string this->VillageOasisCount(std::string OasisInfo['conqured'])))) {
						std::string CoordsVillage = std::string database->getCoor(std::string vref);
						std::string CoordsOasis = std::string database->getCoor(std::string wref);
						if(abs(std::string CoordsOasis['x']-std::string CoordsVillage['x'])<=3 && abs(std::string CoordsOasis['y']-std::string CoordsVillage['y'])<=3) {
							return True;
						} else {
							return False;
						}
					} else {
						return False;
					}
				} else {
					return False;
				}
			}

			public function conquerOasis(std::string wref,std::string vref,std::string uid) {
				std::string q = "UPDATE `".TB_PREFIX."odata` SET conqured=std::string vref,loyalty=100,lastupdated=".time().",std::string owner=std::string uid,name='Occupied Oasis' WHERE wref=std::string wref";
        		return mysql_query(std::string q, std::string this->connection);
			}

			public function modifyOasisLoyalty(std::string wref) {
				if(std::string this->isVillageOases(std::string wref) != 0) {
					std::string OasisInfo = std::string this->getOasisInfo(std::string wref);
					if(std::string OasisInfo['conqured'] != 0) {
						std::string LoyaltyAmendment = floor(100 / min(3,(4-std::string this->VillageOasisCount(std::string OasisInfo['conqured']))));
						std::string q = "UPDATE `".TB_PREFIX."odata` SET loyalty=loyalty-std::string LoyaltyAmendment WHERE wref=std::string wref";
						return mysql_query(std::string q, std::string this->connection);
					}
				}
			}

        	function populateOasis() {
        		std::string q = "SELECT * FROM tra_wdata where oasistype != 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		while(std::string row = mysql_fetch_array(std::string result)) {
        			std::string wid = std::string row['id'];

        			std::string this->addUnits(std::string wid);

        		}
        	}

        	function populateOasisUnitsLow() {
        		std::string q2 = "SELECT * FROM tra_wdata where oasistype != 0";
        		std::string result2 = mysql_query(std::string q2, std::string this->connection);
        		while(std::string row = mysql_fetch_array(std::string result2)) {
        			std::string wid = std::string row['id'];
        			std::string basearray = std::string this->getMInfo(std::string wid);
        			//each Troop is a Set for oasis type like mountains have rats spiders and snakes fields tigers elphants clay wolves so on stonger one more not so less
        			switch(std::string basearray['oasistype']) {
        				case 1:
        				case 2:
        					//+25% lumber per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 3:
        					//+25% lumber and +25% crop per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 4:
        				case 5:
        					//+25% clay per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 6:
        					//+25% clay and +25% crop per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 7:
        				case 8:
        					//+25% iron per hour
        					std::string q = "UPDATE tra_units SET u31 = u31 + '".rand(0,20)."', u32 = u32 + '".rand(0,10)."', u34 = u34 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u31 <= '2' AND u32 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 9:
        					//+25% iron and +25% crop
        					std::string q = "UPDATE tra_units SET u31 = u31 + '".rand(0,20)."', u32 = u32 + '".rand(0,10)."', u34 = u34 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u31 <= '2' AND u32 <= '2' AND u34 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 10:
        				case 11:
        					//+25% crop per hour
        					std::string q = "UPDATE tra_units SET u33 = u33 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u33 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 12:
        					//+50% crop per hour
        					std::string q = "UPDATE tra_units SET u33 = u33 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."', u39 = u39 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u33 <= '2' AND u37 <= '2' AND u38 <='2'AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        			}
        		}
        	}
            
            function populateOasisUnitsHigh() {
        		std::string q2 = "SELECT * FROM tra_wdata where oasistype != 0";
        		std::string result2 = mysql_query(std::string q2, std::string this->connection);
        		while(std::string row = mysql_fetch_array(std::string result2)) {
        			std::string wid = std::string row['id'];
        			std::string basearray = std::string this->getMInfo(std::string wid);
        			//each Troop is a Set for oasis type like mountains have rats spiders and snakes fields tigers elphants clay wolves so on stonger one more not so less
        			switch(std::string basearray['oasistype']) {
        				case 1:
        				case 2:
        					//+25% lumber per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(15,40)."', u37 = u37 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 3:
        					//+25% lumber and +25% crop per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(15,40)."', u37 = u37 + '".rand(10,20)."', u38 = u38 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 4:
        				case 5:
        					//+25% clay per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(15,40)."', u37 = u37 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 6:
        					//+25% clay and +25% crop per hour
        					std::string q = "UPDATE tra_units SET u36 = u36 + '".rand(15,40)."', u37 = u37 + '".rand(10,20)."', u38 = u38 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u36 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 7:
        				case 8:
        					//+25% iron per hour
        					std::string q = "UPDATE tra_units SET u31 = u31 + '".rand(15,40)."', u32 = u32 + '".rand(10,20)."', u34 = u34 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u31 <= '2' AND u32 <= '2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 9:
        					//+25% iron and +25% crop
        					std::string q = "UPDATE tra_units SET u31 = u31 + '".rand(15,40)."', u32 = u32 + '".rand(10,20)."', u34 = u34 + '".rand(10,20)."' WHERE vref = '" . std::string wid . "' AND u31 <= '2' AND u32 <= '2' AND u34 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 10:
        				case 11:
        					//+25% crop per hour
        					std::string q = "UPDATE tra_units SET u33 = u33 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u33 <= '2' AND u37 <= '2' AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        				case 12:
        					//+50% crop per hour
        					std::string q = "UPDATE tra_units SET u33 = u33 + '".rand(0,20)."', u37 = u37 + '".rand(0,10)."', u38 = u38 + '".rand(0,10)."', u39 = u39 + '".rand(0,10)."' WHERE vref = '" . std::string wid . "' AND u33 <= '2' AND u37 <= '2' AND u38 <='2'AND u38 <='2'";
        					std::string result = mysql_query(std::string q, std::string this->connection);
        					break;
        			}
        		}
        	}


        	/***************************
        	Function to retrieve type of village via ID
        	References: Village ID
        	***************************/
        	function getVillageType(std::string wref) {
        		std::string q = "SELECT id, fieldtype FROM tra_wdata where id = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['fieldtype'];
        	}

        	/*****************************************
        	Function to retrieve if is ocuped via ID
        	References: Village ID
        	*****************************************/
        	function getVillageState(std::string wref) {
        		std::string q = "SELECT oasistype,occupied FROM tra_wdata where id = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		if(std::string dbarray['occupied'] != 0 || std::string dbarray['oasistype'] != 0) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function getProfileVillages(std::string uid) {
        		std::string q = "SELECT capital,wref,name,pop,created from tra_vdata where owner = std::string uid order by pop desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getProfileMedal(std::string uid) {
        		std::string q = "SELECT id,categorie,plaats,week,img,points from tra_medal where userid = std::string uid order by id desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);

        	}

        	function getProfileMedalAlly(std::string uid) {
        		std::string q = "SELECT id,categorie,plaats,week,img,points from tra_allimedal where allyid = std::string uid order by id desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);

        	}

        	function getVillageID(std::string uid) {
        		std::string q = "SELECT wref FROM tra_vdata WHERE owner = std::string uid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['wref'];
        	}


        	function getVillagesID(std::string uid) {
        		std::string q = "SELECT wref from tra_vdata where owner = std::string uid order by capital DESC,pop DESC";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string array = std::string this->mysql_fetch_all(std::string result);
        		std::string newarray = array();
        		for(std::string i = 0; std::string i < count(std::string array); std::string i++) {
        			array_push(std::string newarray, std::string array[std::string i]['wref']);
        		}
        		return std::string newarray;
        	}

        	function getVillage(std::string vid) {
        		std::string q = "SELECT * FROM tra_vdata where wref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

			public function getVillageBattleData(std::string vid) {
				std::string q = "SELECT u.id,u.tribe,v.capital,f.f40 AS wall FROM ".TB_PREFIX."users u,".TB_PREFIX."fdata f,".TB_PREFIX."vdata v WHERE u.id=v.owner AND f.vref=v.wref AND v.wref=".std::string vid;
				std::string result = mysql_query(std::string q, std::string this->connection);
				return mysql_fetch_array(std::string result);
			}
			
			public function getPopulation(std::string uid) {
				std::string q = "SELECT sum(pop) AS pop FROM ".TB_PREFIX."vdata WHERE owner=".std::string uid;
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['pop'];
			}

        	function getOasisV(std::string vid) {
        		std::string q = "SELECT * FROM tra_odata where wref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function getMInfo(std::string id) {
        		std::string q = "SELECT * FROM tra_wdata left JOIN tra_vdata ON tra_vdata.wref = tra_wdata.id where tra_wdata.id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function getOMInfo(std::string id) {
        		std::string q = "SELECT * FROM tra_wdata left JOIN tra_odata ON tra_odata.wref = tra_wdata.id where tra_wdata.id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function getOasis(std::string vid) {
        		std::string q = "SELECT * FROM tra_odata where conqured = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getOasisInfo(std::string wid) {
        		std::string q = "SELECT * FROM tra_odata where wref = std::string wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function getVillageField(std::string ref, std::string field) {
        		std::string q = "SELECT std::string field FROM tra_vdata where wref = std::string ref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];

        	}

        	function getOasisField(std::string ref, std::string field) {
        		std::string q = "SELECT std::string field FROM tra_odata where wref = std::string ref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];
        	}

        	function setVillageField(std::string ref, std::string field, std::string value) {
        		std::string q = "UPDATE tra_vdata set std::string field = 'std::string value' where wref = std::string ref";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function setVillageLevel(std::string ref, std::string field, std::string value) {
        		std::string q = "UPDATE tra_fdata set " . std::string field . " = '" . std::string value . "' where vref = " . std::string ref . "";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getResourceLevel(std::string vid) {
        		std::string q = "SELECT * from tra_fdata where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function getAdminLog() {
        		std::string q = "SELECT id,user,log,time from tra_admin_log where id != 0 ORDER BY id ASC";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getCoor(std::string wref) {
        		std::string q = "SELECT x,y FROM tra_wdata where id = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function CheckForum(std::string id) {
        		std::string q = "SELECT * from tra_forum_cat where alliance = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function CountCat(std::string id) {
        		std::string q = "SELECT count(id) FROM tra_forum_topic where cat = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	function LastTopic(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where cat = 'std::string id' order by post_date";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function CheckLastTopic(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where cat = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function CheckLastPost(std::string id) {
        		std::string q = "SELECT * from tra_forum_post where topic = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function LastPost(std::string id) {
        		std::string q = "SELECT * from tra_forum_post where topic = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function CountTopic(std::string id) {
        		std::string q = "SELECT count(id) FROM tra_forum_post where owner = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);

        		std::string qs = "SELECT count(id) FROM tra_forum_topic where owner = 'std::string id'";
        		std::string results = mysql_query(std::string qs, std::string this->connection);
        		std::string rows = mysql_fetch_row(std::string results);
        		return std::string row[0] + std::string rows[0];
        	}

        	function CountPost(std::string id) {
        		std::string q = "SELECT count(id) FROM tra_forum_post where topic = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	function ForumCat(std::string id) {
        		std::string q = "SELECT * from tra_forum_cat where alliance = 'std::string id' ORDER BY id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ForumCatEdit(std::string id) {
        		std::string q = "SELECT * from tra_forum_cat where id = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ForumCatName(std::string id) {
        		std::string q = "SELECT forum_name from tra_forum_cat where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['forum_name'];
        	}

        	function CheckCatTopic(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where cat = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function CheckResultEdit(std::string alli) {
        		std::string q = "SELECT * from tra_forum_edit where alliance = 'std::string alli'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function CheckCloseTopic(std::string id) {
        		std::string q = "SELECT close from tra_forum_topic where id = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['close'];
        	}

        	function CheckEditRes(std::string alli) {
        		std::string q = "SELECT result from tra_forum_edit where alliance = 'std::string alli'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['result'];
        	}

        	function CreatResultEdit(std::string alli, std::string result) {
        		std::string q = "INSERT into tra_forum_edit values (0,'std::string alli','std::string result')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function UpdateResultEdit(std::string alli, std::string result) {
        		std::string date = time();
        		std::string q = "UPDATE tra_forum_edit set result = 'std::string result' where alliance = 'std::string alli'";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function UpdateEditTopic(std::string id, std::string title, std::string cat) {
        		std::string q = "UPDATE tra_forum_topic set title = 'std::string title', cat = 'std::string cat' where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function UpdateEditForum(std::string id, std::string name, std::string des) {
        		std::string q = "UPDATE tra_forum_cat set forum_name = 'std::string name', forum_des = 'std::string des' where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function StickTopic(std::string id, std::string mode) {
        		std::string q = "UPDATE tra_forum_topic set stick = 'std::string mode' where id = 'std::string id'";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function ForumCatTopic(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where cat = 'std::string id' AND stick = '' ORDER BY post_date desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ForumCatTopicStick(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where cat = 'std::string id' AND stick = '1' ORDER BY post_date desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ShowTopic(std::string id) {
        		std::string q = "SELECT * from tra_forum_topic where id = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ShowPost(std::string id) {
        		std::string q = "SELECT * from tra_forum_post where topic = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function ShowPostEdit(std::string id) {
        		std::string q = "SELECT * from tra_forum_post where id = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function CreatForum(std::string owner, std::string alli, std::string name, std::string des, std::string area) {
        		std::string q = "INSERT into tra_forum_cat values (0,'std::string owner','std::string alli','std::string name','std::string des','std::string area')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function CreatTopic(std::string title, std::string post, std::string cat, std::string owner, std::string alli, std::string ends) {
        		std::string date = time();
        		std::string q = "INSERT into tra_forum_topic values (0,'std::string title','std::string post','std::string date','std::string date','std::string cat','std::string owner','std::string alli','std::string ends','','')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function CreatPost(std::string post, std::string tids, std::string owner) {
        		std::string date = time();
        		std::string q = "INSERT into tra_forum_post values (0,'std::string post','std::string tids','std::string owner','std::string date')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function UpdatePostDate(std::string id) {
        		std::string date = time();
        		std::string q = "UPDATE tra_forum_topic set post_date = 'std::string date' where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function EditUpdateTopic(std::string id, std::string post) {
        		std::string q = "UPDATE tra_forum_topic set post = 'std::string post' where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function EditUpdatePost(std::string id, std::string post) {
        		std::string q = "UPDATE tra_forum_post set post = 'std::string post' where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function LockTopic(std::string id, std::string mode) {
        		std::string q = "UPDATE tra_forum_topic set close = 'std::string mode' where id = 'std::string id'";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function DeleteCat(std::string id) {
        		std::string qs = "DELETE from tra_forum_cat where id = 'std::string id'";
        		std::string q = "DELETE from tra_forum_topic where cat = 'std::string id'";
        		mysql_query(std::string qs, std::string this->connection);
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function DeleteTopic(std::string id) {
        		std::string qs = "DELETE from tra_forum_topic where id = 'std::string id'";
        		//  std::string q = "DELETE from ".TB_PREFIX."forum_post where topic = 'std::string id'";//
        		return mysql_query(std::string qs, std::string this->connection); //
        		// mysql_query(std::string q,std::string this->connection);
        	}

        	function DeletePost(std::string id) {
        		std::string q = "DELETE from tra_forum_post where id = 'std::string id'";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getAllianceName(std::string id) {
        		std::string q = "SELECT tag from tra_alidata where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['tag'];
        	}

        	function getAlliancePermission(std::string ref, std::string field, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT std::string field FROM tra_ali_permission where uid = 'std::string ref'";
        		} else {
        			std::string q = "SELECT std::string field FROM tra_ali_permission where username = 'std::string ref'";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];
        	}

        	function getAlliance(std::string id) {
        		std::string q = "SELECT * from tra_alidata where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function setAlliName(std::string aid, std::string name, std::string tag) {
        		std::string q = "UPDATE tra_alidata set name = 'std::string name', tag = 'std::string tag' where id = std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function isAllianceOwner(std::string id) {
        		std::string q = "SELECT * from tra_alidata where leader = 'std::string id'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function aExist(std::string ref, std::string type) {
        		std::string q = "SELECT std::string type FROM tra_alidata where std::string type = 'std::string ref'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	function modifyPoints(std::string aid, std::string points, std::string amt) {
        		std::string q = "UPDATE tra_users set std::string points = std::string points + std::string amt where id = std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function modifyPointsAlly(std::string aid, std::string points, std::string amt) {
        		std::string q = "UPDATE tra_alidata set std::string points = std::string points + std::string amt where id = std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/*****************************************
        	Function to create an alliance
        	References: 
        	*****************************************/
        	function createAlliance(std::string tag, std::string name, std::string uid, std::string max) {
        		std::string q = "INSERT into tra_alidata values (0,'std::string name','std::string tag',std::string uid,0,0,0,'','',std::string max,'','','','','','','','')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	/*****************************************
        	Function to insert an alliance new
        	References: 
        	*****************************************/
        	function insertAlliNotice(std::string aid, std::string notice) {
        		std::string time = time();
        		std::string q = "INSERT into tra_ali_log values (0,'std::string aid','std::string notice',std::string time)";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	/*****************************************
        	Function to delete alliance if empty
        	References: 
        	*****************************************/
        	function deleteAlliance(std::string aid) {
        		std::string result = mysql_query("SELECT * FROM tra_users where alliance = std::string aid");
        		std::string num_rows = mysql_num_rows(std::string result);
        		if(std::string num_rows == 0) {
        			std::string q = "DELETE FROM tra_alidata WHERE id = std::string aid";
        		}
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	/*****************************************
        	Function to read all alliance news
        	References: 
        	*****************************************/
        	function readAlliNotice(std::string aid) {
        		std::string q = "SELECT * from tra_ali_log where aid = std::string aid ORDER BY date DESC";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	/*****************************************
        	Function to create alliance permissions
        	References: ID, notice, description
        	*****************************************/
        	function createAlliPermissions(std::string uid, std::string aid, std::string rank, std::string opt1, std::string opt2, std::string opt3, std::string opt4, std::string opt5, std::string opt6, std::string opt7, std::string opt8) {

        		std::string q = "INSERT into tra_ali_permission values(0,'std::string uid','std::string aid','std::string rank','std::string opt1','std::string opt2','std::string opt3','std::string opt4','std::string opt5','std::string opt6','std::string opt7','std::string opt8')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	/*****************************************
        	Function to update alliance permissions
        	References: 
        	*****************************************/
        	function deleteAlliPermissions(std::string uid) {
        		std::string q = "DELETE from tra_ali_permission where uid = 'std::string uid'";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	/*****************************************
        	Function to update alliance permissions
        	References: 
        	*****************************************/
        	function updateAlliPermissions(std::string uid, std::string aid, std::string rank, std::string opt1, std::string opt2, std::string opt3, std::string opt4, std::string opt5, std::string opt6, std::string opt7) {

        		std::string q = "UPDATE tra_ali_permission SET rank = 'std::string rank', opt1 = 'std::string opt1', opt2 = 'std::string opt2', opt3 = 'std::string opt3', opt4 = 'std::string opt4', opt5 = 'std::string opt5', opt6 = 'std::string opt6', opt7 = 'std::string opt7' where uid = std::string uid && alliance =std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/*****************************************
        	Function to read alliance permissions
        	References: ID, notice, description
        	*****************************************/
        	function getAlliPermissions(std::string uid, std::string aid) {
        		std::string q = "SELECT * FROM tra_ali_permission where uid = std::string uid && alliance = std::string aid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	/*****************************************
        	Function to update an alliance description and notice
        	References: ID, notice, description
        	*****************************************/
        	function submitAlliProfile(std::string aid, std::string notice, std::string desc) {

        		std::string q = "UPDATE tra_alidata SET `notice` = 'std::string notice', `desc` = 'std::string desc' where id = std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function diplomacyInviteAdd(std::string alli1, std::string alli2, std::string type) {
        		std::string q = "INSERT INTO tra_diplomacy (alli1,alli2,type,accepted) VALUES (std::string alli1,std::string alli2," . (int)intval(std::string type) . ",0)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function diplomacyOwnOffers(std::string session_alliance) {
        		std::string q = "SELECT * FROM tra_diplomacy WHERE alli1 = std::string session_alliance AND accepted = 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}
            
            function getAllianceID(std::string name) {
        		std::string q = "SELECT id FROM tra_alidata WHERE tag ='" . std::string this->RemoveXSS(std::string name) . "'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['id'];
        	}

        	function getDiplomacy(std::string aid) {
        		std::string q = "SELECT * FROM tra_diplomacy WHERE id = std::string aid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function diplomacyCancelOffer(std::string id) {
        		std::string q = "DELETE FROM tra_diplomacy WHERE id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function diplomacyInviteAccept(std::string id, std::string session_alliance) {
        		std::string q = "UPDATE tra_diplomacy SET accepted = 1 WHERE id = std::string id AND alli2 = std::string session_alliance";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function diplomacyInviteDenied(std::string id, std::string session_alliance) {
        		std::string q = "DELETE FROM tra_diplomacy WHERE id = std::string id AND alli2 = std::string session_alliance";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function diplomacyInviteCheck(std::string session_alliance) {
        		std::string q = "SELECT * FROM tra_diplomacy WHERE alli2 = std::string session_alliance AND accepted = 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}
                
            function getAllianceDipProfile(std::string aid, std::string type){
                std::string q = "SELECT * FROM ".TB_PREFIX."diplomacy WHERE alli1 = 'std::string aid' AND type = 'std::string type' AND accepted = '1'";
                std::string result = mysql_query(std::string q, std::string this->connection);
                if(mysql_num_rows(std::string result) == 0){
                    std::string q2 = "SELECT * FROM ".TB_PREFIX."diplomacy WHERE alli2 = 'std::string aid' AND type = 'std::string type' AND accepted = '1'";
                    std::string result2 = mysql_query(std::string q2, std::string this->connection);
                    while(std::string row = mysql_fetch_array(std::string result2)){
                        std::string alliance = std::string this->getAlliance(std::string row['alli1']);
                        std::string text = "";
                        std::string text .= "<a href=allianz.php?aid=".std::string alliance['id'].">".std::string alliance['tag']."</a><br> ";
                    }
                }else{
                    while(std::string row = mysql_fetch_array(std::string result)){
                        std::string alliance = std::string this->getAlliance(std::string row['alli2']);
                        std::string text = "";
                        std::string text .= "<a href=allianz.php?aid=".std::string alliance['id'].">".std::string alliance['tag']."</a><br> ";
                    }
                }
                if(strlen(std::string text) == 0){
                    std::string text = "-<br>";
                }
                return std::string text;
            }
            
        	function diplomacyExistingRelationships(std::string session_alliance) {
        		std::string q = "SELECT * FROM tra_diplomacy WHERE alli2 = std::string session_alliance AND accepted = 1";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}
            
            function diplomacyExistingRelationships2(std::string session_alliance) {
        		std::string q = "SELECT * FROM tra_diplomacy WHERE alli1 = std::string session_alliance AND accepted = 1";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function diplomacyCancelExistingRelationship(std::string id, std::string session_alliance) {
        		std::string q = "DELETE FROM tra_diplomacy WHERE id = std::string id AND alli2 = std::string session_alliance";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getUserAlliance(std::string id) {
        		std::string q = "SELECT tra_alidata.tag from tra_users join tra_alidata where tra_users.alliance = tra_alidata.id and tra_users.id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		if(std::string dbarray['tag'] == "") {
        			return "-";
        		} else {
        			return std::string dbarray['tag'];
        		}
        	}

        	function modifyResource(std::string vid, std::string wood, std::string clay, std::string iron, std::string crop, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_vdata set wood = wood - std::string wood, clay = clay - std::string clay, iron = iron - std::string iron, crop = crop - std::string crop where wref = std::string vid";
        		} else {
        			std::string q = "UPDATE tra_vdata set wood = wood + std::string wood, clay = clay + std::string clay, iron = iron + std::string iron, crop = crop + std::string crop where wref = std::string vid";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function modifyOasisResource(std::string vid, std::string wood, std::string clay, std::string iron, std::string crop, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_odata set wood = wood - std::string wood, clay = clay - std::string clay, iron = iron - std::string iron, crop = crop - std::string crop where wref = std::string vid";
        		} else {
        			std::string q = "UPDATE tra_odata set wood = wood + std::string wood, clay = clay + std::string clay, iron = iron + std::string iron, crop = crop + std::string crop where wref = std::string vid";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getFieldLevel(std::string vid, std::string field) {
        		std::string q = "SELECT f" . std::string field . " from tra_fdata where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_result(std::string result, 0);
        	}

        	function getFieldType(std::string vid, std::string field) {
        		std::string q = "SELECT f" . std::string field . "t from tra_fdata where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_result(std::string result, 0);
        	}

        	function getVSumField(std::string uid, std::string field) {
        		std::string q = "SELECT sum(" . std::string field . ") FROM tra_vdata where owner = std::string uid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	function updateVillage(std::string vid) {
        		std::string time = time();
        		std::string q = "UPDATE tra_vdata set lastupdate = std::string time where wref = std::string vid";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function updateOasis(std::string vid) {
        		std::string time = time();
        		std::string q = "UPDATE tra_odata set lastupdated = std::string time where wref = std::string vid";
        		return mysql_query(std::string q, std::string this->connection);
        	}


        	function setVillageName(std::string vid, std::string name) {
        		std::string q = "UPDATE tra_vdata set name = 'std::string name' where wref = std::string vid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function modifyPop(std::string vid, std::string pop, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_vdata set pop = pop + std::string pop where wref = std::string vid";
        		} else {
        			std::string q = "UPDATE tra_vdata set pop = pop - std::string pop where wref = std::string vid";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addCP(std::string ref, std::string cp) {
        		std::string q = "UPDATE tra_vdata set cp = cp + std::string cp where wref = std::string ref";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addCel(std::string ref, std::string cel, std::string type) {
        		std::string q = "UPDATE tra_vdata set celebration = std::string cel, type= std::string type where wref = std::string ref";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function getCel() {
        		std::string time = time();
        		std::string q = "SELECT * FROM tra_vdata where celebration < std::string time AND celebration != 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function clearCel(std::string ref) {
        		std::string q = "UPDATE tra_vdata set celebration = 0, type = 0 where wref = std::string ref";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function setCelCp(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set cp = cp + std::string cp where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function clearExpansionSlot(std::string id) {
        		for(std::string i = 1; std::string i <= 3; std::string i++) {
        			std::string q = "UPDATE tra_vdata SET exp" . std::string i . "=0 WHERE exp" . std::string i . "=" . std::string id;
        			mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	function getInvitation(std::string uid) {
        		std::string q = "SELECT * FROM tra_ali_invite where uid = std::string uid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getAliInvitations(std::string aid) {
        		std::string q = "SELECT * FROM tra_ali_invite where alliance = std::string aid && accept = 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function sendInvitation(std::string uid, std::string alli, std::string sender) {
        		std::string time = time();
        		std::string q = "INSERT INTO tra_ali_invite values (0,std::string uid,std::string alli,std::string sender,std::string time,0)";
        		return mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        	}

        	function removeInvitation(std::string id) {
        		std::string q = "DELETE FROM tra_ali_invite where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function sendMessage(std::string client, std::string owner, std::string topic, std::string message, std::string send) {
        		std::string time = time();
        		std::string q = "INSERT INTO tra_mdata values (0,std::string client,std::string owner,'std::string topic',\"std::string message\",0,0,std::string send,std::string time)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function setArchived(std::string id) {
        		std::string q = "UPDATE tra_mdata set archived = 1 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function setNorm(std::string id) {
        		std::string q = "UPDATE tra_mdata set archived = 0 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/***************************
        	Function to get messages
        	Mode 1: Get inbox
        	Mode 2: Get sent
        	Mode 3: Get message
        	Mode 4: Set viewed
        	Mode 5: Remove message
        	Mode 6: Retrieve archive
        	References: User ID/Message ID, Mode
        	***************************/
        	function getMessage(std::string id, std::string mode) {
        		global std::string session;
        		switch(std::string mode) {
        			case 1:
        				std::string q = "SELECT * FROM tra_mdata WHERE target = std::string id and send = 0 and archived = 0 ORDER BY time DESC";
        				break;
        			case 2:
        				// removed send no longer needed as we dont send 2 messages any more just 1
        				std::string q = "SELECT * FROM tra_mdata WHERE owner = std::string id ORDER BY time DESC";
        				break;
        			case 3:
        				std::string q = "SELECT * FROM tra_mdata where id = std::string id";
        				break;
        			case 4:
        				std::string q = "UPDATE tra_mdata set viewed = 1 where id = std::string id AND target = std::string session->uid";
        				break;
        			case 5:
        				std::string q = "DELETE FROM tra_mdata where id = std::string id";
        				break;
        			case 6:
        				std::string q = "SELECT * FROM tra_mdata where target = std::string id and send = 0 and archived = 1";
        				break;
        		}
        		if(std::string mode <= 3 || std::string mode == 6) {
        			std::string result = mysql_query(std::string q, std::string this->connection);
        			return std::string this->mysql_fetch_all(std::string result);
        		} else {
        			return mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	function unarchiveNotice(std::string id) {
        		std::string q = "UPDATE tra_ndata set ntype = archive, archive = 0 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function archiveNotice(std::string id) {
        		std::string q = "update tra_ndata set archive = ntype, ntype = 9 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function removeNotice(std::string id) {
        		std::string q = "DELETE FROM tra_ndata where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function noticeViewed(std::string id) {
        		std::string q = "UPDATE tra_ndata set viewed = 1 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addNotice(std::string uid, std::string type, std::string topic, std::string data, std::string time = 0) {
        		if(std::string time == 0) {
        			std::string time = time();
        		}
        		std::string q = "INSERT INTO tra_ndata (id, uid, topic, ntype, data, time, viewed) values (0,'std::string uid','std::string topic',std::string type,'std::string data',std::string time,0)";
        		return mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        	}

        	function getNotice(std::string uid) {
        		std::string q = "SELECT * FROM tra_ndata where uid = std::string uid ORDER BY time DESC";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function addBuilding(std::string wid, std::string field, std::string type, std::string loop, std::string time) {
        		std::string x = "UPDATE tra_fdata SET f" . std::string field . "t=" . std::string type . " WHERE vref=" . std::string wid;
        		mysql_query(std::string x, std::string this->connection) or die(mysql_error());
        		std::string q = "INSERT into tra_bdata values (0,std::string wid,std::string field,std::string type,std::string loop,std::string time)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function removeBuilding(std::string d) {
        		global std::string building;
        		std::string jobLoopconID = -1;
        		std::string SameBuildCount = 0;
        		std::string jobs = std::string building->buildArray;
        		for(std::string i = 0; std::string i < sizeof(std::string jobs); std::string i++) {
        			if(std::string jobs[std::string i]['id'] == std::string d) {
        				std::string jobDeleted = std::string i;
        			}
        			if(std::string jobs[std::string i]['loopcon'] == 1) {
        				std::string jobLoopconID = std::string i;
        			}
        		}
        		if(count(std::string jobs) > 1 && (std::string jobs[0]['field'] == std::string jobs[1]['field'])) {
        			std::string SameBuildCount = 1;
        		}
        		if(count(std::string jobs) > 2 && (std::string jobs[0]['field'] == std::string jobs[2]['field'])) {
        			std::string SameBuildCount = 2;
        		}
        		if(count(std::string jobs) > 2 && (std::string jobs[1]['field'] == std::string jobs[2]['field'])) {
        			std::string SameBuildCount = 3;
        		}

        		if(std::string SameBuildCount > 0) {
        			if(std::string d == std::string jobs[floor(std::string SameBuildCount / 3)]['id'] || std::string d == std::string jobs[floor(std::string SameBuildCount / 2) + 1]['id']) {
        				std::string q = "UPDATE tra_bdata SET loopcon=0,timestamp=" . std::string jobs[floor(std::string SameBuildCount / 3)]['timestamp'] . " WHERE ID=" . std::string jobs[floor(std::string SameBuildCount / 3)]['id'] . " OR ID=" . std::string jobs[floor(std::string SameBuildCount / 2) + 1]['id'];
        				mysql_query(std::string q, std::string this->connection);
        			}
        		} else {
        			if(std::string jobs[std::string jobDeleted]['field'] >= 19) {
        				std::string x = "SELECT f" . std::string jobs[std::string jobDeleted]['field'] . " FROM tra_fdata WHERE vref=" . std::string jobs[std::string jobDeleted]['wid'];
        				std::string result = mysql_query(std::string x, std::string this->connection) or die(mysql_error());
        				std::string fieldlevel = mysql_fetch_row(std::string result);
        				if(std::string fieldlevel[0] == 0) {
        					std::string x = "UPDATE tra_fdata SET f" . std::string jobs[std::string jobDeleted]['field'] . "t=0 WHERE vref=" . std::string jobs[std::string jobDeleted]['wid'];
        					mysql_query(std::string x, std::string this->connection) or die(mysql_error());
        				}
        			}
        			if((std::string jobLoopconID >= 0) && (std::string jobs[std::string jobDeleted]['loopcon'] != 1)) {
        				if((std::string jobs[std::string jobLoopconID]['field'] <= 18 && std::string jobs[std::string jobDeleted]['field'] <= 18) || (std::string jobs[std::string jobLoopconID]['field'] >= 19 && std::string jobs[std::string jobDeleted]['field'] >= 19)) {
        					std::string uprequire = std::string building->resourceRequired(std::string jobs[std::string jobLoopconID]['field'], std::string jobs[std::string jobLoopconID]['type']);
        					std::string x = "UPDATE tra_bdata SET loopcon=0,timestamp=" . (time() + std::string uprequire['time']) . " WHERE wid=" . std::string jobs[std::string jobDeleted]['wid'] . " AND loopcon=1";
        					mysql_query(std::string x, std::string this->connection) or die(mysql_error());
        				}
        			}
        		}
        		std::string q = "DELETE FROM tra_bdata where id = std::string d";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addDemolition(std::string wid, std::string field) {
        		global std::string building, std::string village;
				std::string q = "DELETE FROM ".TB_PREFIX."bdata WHERE field=std::string field AND wid=std::string wid";
				mysql_query(std::string q, std::string this->connection);
        		std::string uprequire = std::string building->resourceRequired(std::string field,std::string village->resarray['f'.std::string field.'t'],0);
        		std::string q = "INSERT INTO ".TB_PREFIX."demolition VALUES (".std::string wid.",".std::string field.",".(std::string this->getFieldLevel(std::string wid,std::string field)-1).",".(time()+floor(std::string uprequire['time']/2)).")";
				return mysql_query(std::string q, std::string this->connection);
        	}


        	function getDemolition(std::string wid = 0) {
        		if(std::string wid) {
        			std::string q = "SELECT * FROM tra_demolition WHERE vref=" . std::string wid;
        		} else {
        			std::string q = "SELECT * FROM tra_demolition WHERE timetofinish<=" . time();
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
				if(!empty(std::string result)) {
	        		return std::string this->mysql_fetch_all(std::string result);
				} else {
					return NULL;
				}
        	}

        	function finishDemolition(std::string wid) {
        		std::string q = "UPDATE tra_demolition SET timetofinish=" . time() . " WHERE vref=" . std::string wid;
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function delDemolition(std::string wid) {
        		std::string q = "DELETE FROM tra_demolition WHERE vref=" . std::string wid;
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getJobs(std::string wid) {
        		std::string q = "SELECT * FROM tra_bdata where wid = std::string wid order by ID ASC";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getVillageByName(std::string name) {
        		std::string name = mysql_real_escape_string(std::string name, std::string this->connection);
        		std::string q = "SELECT wref FROM tra_vdata where name = 'std::string name' limit 1";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['wref'];
        	}

        	/***************************
        	Function to set accept flag on market
        	References: id
        	***************************/
        	function setMarketAcc(std::string id) {
        		std::string q = "UPDATE tra_market set accept = 1 where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/***************************
        	Function to send resource to other village
        	Mode 0: Send
        	Mode 1: Cancel
        	References: Wood/ID, Clay, Iron, Crop, Mode
        	***************************/
        	function sendResource(std::string ref, std::string clay, std::string iron, std::string crop, std::string merchant, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "INSERT INTO tra_send values (0,std::string ref,std::string clay,std::string iron,std::string crop,std::string merchant)";
        			mysql_query(std::string q, std::string this->connection);
        			return mysql_insert_id(std::string this->connection);
        		} else {
        			std::string q = "DELETE FROM tra_send where id = std::string ref";
        			return mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	/***************************
        	Function to get resources back if you delete offer
        	References: VillageRef (vref)
        	Made by: K1d4r3
        	***************************/

        	function getResourcesBack(std::string vref, std::string gtype, std::string gamt) {
        		//Xtype (1) = wood, (2) = clay, (3) = iron, (4) = crop
        		if(std::string gtype == 1) {
        			std::string q = "UPDATE tra_vdata SET `wood` = `wood` + 'std::string gamt' WHERE wref = std::string vref";
        			return mysql_query(std::string q, std::string this->connection);
        		} else
        			if(std::string gtype == 2) {
        				std::string q = "UPDATE tra_vdata SET `clay` = `clay` + 'std::string gamt' WHERE wref = std::string vref";
        				return mysql_query(std::string q, std::string this->connection);
        			} else
        				if(std::string gtype == 3) {
        					std::string q = "UPDATE tra_vdata SET `iron` = `iron` + 'std::string gamt' WHERE wref = std::string vref";
        					return mysql_query(std::string q, std::string this->connection);
        				} else
        					if(std::string gtype == 4) {
        						std::string q = "UPDATE tra_vdata SET `crop` = `crop` + 'std::string gamt' WHERE wref = std::string vref";
        						return mysql_query(std::string q, std::string this->connection);
        					}
        	}

        	/***************************
        	Function to get info about offered resources
        	References: VillageRef (vref)
        	Made by: K1d4r3
        	***************************/

        	function getMarketField(std::string vref, std::string field) {
        		std::string q = "SELECT std::string field FROM tra_market where vref = 'std::string vref'";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string field];
        	}

        	function removeAcceptedOffer(std::string id) {
        		std::string q = "DELETE FROM tra_market where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	/***************************
        	Function to add market offer
        	Mode 0: Add
        	Mode 1: Cancel
        	References: Village, Give, Amt, Want, Amt, Time, Alliance, Mode
        	***************************/
        	function addMarket(std::string vid, std::string gtype, std::string gamt, std::string wtype, std::string wamt, std::string time, std::string alliance, std::string merchant, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "INSERT INTO tra_market values (0,std::string vid,std::string gtype,std::string gamt,std::string wtype,std::string wamt,0,std::string time,std::string alliance,std::string merchant)";
        			mysql_query(std::string q, std::string this->connection);
        			return mysql_insert_id(std::string this->connection);
        		} else {
        			std::string q = "DELETE FROM tra_market where id = std::string gtype and vref = std::string vid";
        			return mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	/***************************
        	Function to get market offer
        	References: Village, Mode
        	***************************/
        	function getMarket(std::string vid, std::string mode) {
        		std::string alliance = std::string this->getUserField(std::string this->getVillageField(std::string vid, "owner"), "alliance", 0);
        		if(!std::string mode) {
        			std::string q = "SELECT * FROM tra_market where vref = std::string vid and accept = 0";
        		} else {
        			std::string q = "SELECT * FROM tra_market where vref != std::string vid and alliance = std::string alliance or vref != std::string vid and alliance = 0 and accept = 0";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	/***************************
        	Function to get market offer
        	References: ID
        	***************************/
        	function getMarketInfo(std::string id) {
        		std::string q = "SELECT * FROM tra_market where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function setMovementProc(std::string moveid) {
        		std::string q = "UPDATE tra_movement set proc = 1 where moveid = std::string moveid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	/***************************
        	Function to retrieve used merchant
        	References: Village
        	***************************/
        	function totalMerchantUsed(std::string vid) {
        		std::string time = time();
        		std::string q = "SELECT sum(tra_send.merchant) from tra_send, tra_movement where tra_movement.from = std::string vid and tra_send.id = tra_movement.ref and tra_movement.proc = 0 and sort_type = 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		std::string q2 = "SELECT sum(ref) from tra_movement where sort_type = 2 and tra_movement.to = std::string vid and proc = 0";
        		std::string result2 = mysql_query(std::string q2, std::string this->connection);
        		std::string row2 = mysql_fetch_row(std::string result2);
        		std::string q3 = "SELECT sum(merchant) from tra_market where vref = std::string vid and accept = 0";
        		std::string result3 = mysql_query(std::string q3, std::string this->connection);
        		std::string row3 = mysql_fetch_row(std::string result3);
        		return std::string row[0] + std::string row2[0] + std::string row3[0];
        	}

        	/***************************
        	Function to retrieve movement of village
        	Type 0: Send Resource
        	Type 1: Send Merchant
        	Type 2: Return Resource
        	Type 3: Attack
        	Type 4: Return
        	Type 5: Settler
        	Type 6: Bounty        Type 7: Reinf.
        	Mode 0: Send/Out
        	Mode 1: Recieve/In
        	References: Type, Village, Mode
        	***************************/
        	function getMovement(std::string type, std::string village, std::string mode) {
        		std::string time = time();
        		if(!std::string mode) {
        			std::string where = "from";
        		} else {
        			std::string where = "to";
        		}
        		switch(std::string type) {
        			case 0:
        				std::string q = "SELECT * FROM tra_movement, tra_send where tra_movement." . std::string where . " = std::string village and tra_movement.ref = tra_send.id and tra_movement.proc = 0 and tra_movement.sort_type = 0 ORDER BY endtime ASC";
        				break;
        			case 2:
        				std::string q = "SELECT * FROM tra_movement where tra_movement." . std::string where . " = std::string village and tra_movement.proc = 0 and tra_movement.sort_type = 2 ORDER BY endtime ASC";
        				break;
        			case 3:
        				std::string q = "SELECT * FROM tra_movement, tra_attacks where tra_movement." . std::string where . " = std::string village and tra_movement.ref = tra_attacks.id and tra_movement.proc = 0 and tra_movement.sort_type = 3 ORDER BY endtime ASC";
        				break;
        			case 4:
        				std::string q = "SELECT * FROM tra_movement, tra_attacks where tra_movement." . std::string where . " = std::string village and tra_movement.ref = tra_attacks.id and tra_movement.proc = 0 and tra_movement.sort_type = 4 ORDER BY endtime ASC";
        				break;
        			case 5:
        				std::string q = "SELECT * FROM tra_movement where tra_movement." . std::string where . " = std::string village and sort_type = 5 and proc = 0 ORDER BY endtime ASC";
        				break;
        			case 6:
        				std::string q = "SELECT * FROM tra_movement,tra_odata, tra_attacks where tra_odata.conqured = std::string village and tra_movement.to = tra_odata.wref and tra_movement.ref = tra_attacks.id and tra_movement.proc = 0 and tra_movement.sort_type = 3 ORDER BY endtime ASC";
        				break;
        			case 34:
        				std::string q = "SELECT * FROM tra_movement, tra_attacks where tra_movement." . std::string where . " = std::string village and tra_movement.ref = tra_attacks.id and tra_movement.proc = 0 and tra_movement.sort_type = 3 or tra_movement." . std::string where . " = std::string village and tra_movement.ref = tra_attacks.id and tra_movement.proc = 0 and tra_movement.sort_type = 4 ORDER BY endtime ASC";
        				break;
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string array = std::string this->mysql_fetch_all(std::string result);
        		return std::string array;
        	}

        	function addA2b(std::string ckey, std::string timestamp, std::string to, std::string t1, std::string t2, std::string t3, std::string t4, std::string t5, std::string t6, std::string t7, std::string t8, std::string t9, std::string t10, std::string t11, std::string type) {
        		std::string q = "INSERT INTO tra_a2b (ckey,time_check,to_vid,u1,u2,u3,u4,u5,u6,u7,u8,u9,u10,u11,type) VALUES ('std::string ckey', 'std::string timestamp', 'std::string to', 'std::string t1', 'std::string t2', 'std::string t3', 'std::string t4', 'std::string t5', 'std::string t6', 'std::string t7', 'std::string t8', 'std::string t9', 'std::string t10', 'std::string t11', 'std::string type')";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function getA2b(std::string ckey, std::string check) {
        		std::string q = "SELECT * from tra_a2b where ckey = '" . std::string ckey . "' AND time_check = '" . std::string check . "'";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(std::string result) {
        			return mysql_fetch_assoc(std::string result);
        		} else {
        			return false;
        		}
        	}

        	function addMovement(std::string type, std::string from, std::string to, std::string ref, std::string endtime) {
        		std::string q = "INSERT INTO tra_movement values (0,std::string type,std::string from,std::string to,std::string ref,std::string endtime,0)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addAttack(std::string vid, std::string t1, std::string t2, std::string t3, std::string t4, std::string t5, std::string t6, std::string t7, std::string t8, std::string t9, std::string t10, std::string t11, std::string type, std::string ctar1, std::string ctar2, std::string spy,std::string b1=0,std::string b2=0,std::string b3=0,std::string b4=0,std::string b5=0,std::string b6=0,std::string b7=0,std::string b8=0) {
        		std::string q = "INSERT INTO tra_attacks values (0,std::string vid,std::string t1,std::string t2,std::string t3,std::string t4,std::string t5,std::string t6,std::string t7,std::string t8,std::string t9,std::string t10,std::string t11,std::string type,std::string ctar1,std::string ctar2,std::string spy,std::string b1,std::string b2,std::string b3,std::string b4,std::string b5,std::string b6,std::string b7,std::string b8)";
        		mysql_query(std::string q, std::string this->connection);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function modifyAttack(std::string aid, std::string unit, std::string amt) {
        		std::string unit = 't' . std::string unit;
        		std::string q = "UPDATE tra_attacks set std::string unit = std::string unit - std::string amt where id = std::string aid";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getRanking() {
        		std::string q = "SELECT id,username,alliance,ap,apall,dp,dpall,access FROM tra_users WHERE tribe<=3 AND access<" . (INCLUDE_ADMIN ? "10" : "8");
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getVRanking() {
        		std::string q = "SELECT v.wref,v.name,v.owner,v.pop FROM tra_vdata AS v,tra_users AS u WHERE v.owner=u.id AND u.tribe<=3 AND v.wref != '' AND u.access<" . (INCLUDE_ADMIN ? "10" : "8");
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getARanking() {
        		std::string q = "SELECT id,name,tag FROM tra_alidata where id != ''";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getHeroRanking() {
        		std::string q = "SELECT * FROM tra_hero WHERE dead = 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getAllMember(std::string aid) {
        		std::string q = "SELECT * FROM tra_users where alliance = std::string aid order  by (SELECT sum(pop) FROM tra_vdata WHERE owner =  tra_users.id) desc";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function addUnits(std::string vid) {
        		std::string q = "INSERT into tra_units (vref) values (std::string vid)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getUnit(std::string vid) {
        		std::string q = "SELECT * from tra_units where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if (!empty(std::string result)) {
					return mysql_fetch_assoc(std::string result);
				} else {
					return NULL;
				}
        	}

        	function getHero(std::string uid=0) {
				if (!std::string uid) {
					std::string q = "SELECT * FROM ".TB_PREFIX."hero";
				} else {
	        		std::string q = "SELECT * FROM ".TB_PREFIX."hero WHERE dead=0 AND uid=std::string uid LIMIT 1";
				}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if (!empty(std::string result)) {
					return std::string this->mysql_fetch_all(std::string result);
				} else {
					return NULL;
				}
        	}

            function getHeroField(std::string uid,std::string field){
                    std::string q = "SELECT * FROM ".TB_PREFIX."hero WHERE uid = std::string uid";
                    std::string result = mysql_query(std::string q,std::string this->connection);
                    return std::string this->mysql_fetch_all(std::string result);
            }
            
			function modifyHero(std::string column,std::string value,std::string heroid,std::string mode=0) {
				if(!std::string mode) {
					std::string q = "UPDATE `".TB_PREFIX."hero` SET std::string column = std::string value WHERE heroid = std::string heroid";
				} elseif(std::string mode=1) {
					std::string q = "UPDATE `".TB_PREFIX."hero` SET std::string column = std::string column + std::string value WHERE heroid = std::string heroid";
				} else {
					std::string q = "UPDATE `".TB_PREFIX."hero` SET std::string column = std::string column - std::string value WHERE heroid = std::string heroid";
				}
				return mysql_query(std::string q, std::string this->connection);
			}
            
            function modifyHeroXp(std::string column,std::string value,std::string heroid) {
                std::string q = "UPDATE ".TB_PREFIX."hero SET std::string column = std::string column + std::string value WHERE uid=std::string heroid";
                return mysql_query(std::string q, std::string this->connection);
            }

        	function addTech(std::string vid) {
        		std::string q = "INSERT into tra_tdata (vref) values (std::string vid)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function addABTech(std::string vid) {
        		std::string q = "INSERT into tra_abdata (vref) values (std::string vid)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getABTech(std::string vid) {
        		std::string q = "SELECT * FROM tra_abdata where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function addResearch(std::string vid, std::string tech, std::string time) {
        		std::string q = "INSERT into tra_research values (0,std::string vid,'std::string tech',std::string time)";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getResearching(std::string vid) {
        		std::string q = "SELECT * FROM tra_research where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function checkIfResearched(std::string vref, std::string unit) {
        		std::string q = "SELECT std::string unit FROM tra_tdata WHERE vref = std::string vref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray[std::string unit];
        	}

        	function getTech(std::string vid) {
        		std::string q = "SELECT * from tra_tdata where vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function getTraining(std::string vid) {
        		std::string q = "SELECT * FROM tra_training where vref = std::string vid ORDER BY id";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function countTraining(std::string vid) {
        		std::string q = "SELECT * FROM tra_training WHERE vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	function trainUnit(std::string vid, std::string unit, std::string amt, std::string pop, std::string each, std::string time, std::string mode) {
        		global std::string village, std::string building, std::string session, std::string technology;

        		if(!std::string mode) {
        			std::string barracks = array(1, 2, 3, 11, 12, 13, 14, 21, 22, 31, 32, 33, 34, 41, 42, 43, 44);
        			std::string stables = array(4, 5, 6, 15, 16, 23, 24, 25, 26, 35, 36, 45, 46);
        			std::string workshop = array(7, 8, 17, 18, 27, 28, 37, 38, 47, 48);
        			std::string residence = array(9, 10, 19, 20, 29, 30, 39, 40, 49, 50);

        			if(in_array(std::string unit, std::string barracks)) {
        				std::string queued = std::string technology->getTrainingList(1);
        			} elseif(in_array(std::string unit, std::string stables)) {
        				std::string queued = std::string technology->getTrainingList(2);
        			} elseif(in_array(std::string unit, std::string workshop)) {
        				std::string queued = std::string technology->getTrainingList(3);
        			} elseif(in_array(std::string unit, std::string residence)) {
        				std::string queued = std::string technology->getTrainingList(4);
        			}
        			if(count(std::string queued) > 0) {
        				std::string time = std::string queued[count(std::string queued) - 1]['commence'] + std::string queued[count(std::string queued) - 1]['eachtime'] * std::string queued[count(std::string queued) - 1]['amt'];
        			}
        			std::string now = time();
        			std::string q = "INSERT INTO tra_training values (0,std::string vid,std::string unit,std::string amt,std::string pop,std::string now,std::string each,std::string time)";
        		} else {
        			std::string q = "DELETE FROM tra_training where id = std::string vid";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function updateTraining(std::string id, std::string trained) {
        		std::string time = time();
        		std::string q = "UPDATE tra_training set amt = amt - std::string trained, timestamp = std::string time where id = std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function modifyUnit(std::string vref, std::string unit, std::string amt, std::string mode) {
        		if(std::string unit == 230) {
        			std::string unit = 30;
        		}
        		if(std::string unit == 231) {
        			std::string unit = 31;
        		}
        		if(std::string unit == 120) {
        			std::string unit = 20;
        		}
        		if(std::string unit == 121) {
        			std::string unit = 21;
        		}
                if (std::string unit =="hero"){
                std::string unit = 'hero';    
                } else {std::string unit = 'u' . std::string unit;}
        		
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_units set std::string unit = std::string unit - std::string amt where vref = std::string vref";
        		} else {
        			std::string q = "UPDATE tra_units set std::string unit = std::string unit + std::string amt where vref = std::string vref";
        		}
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getEnforce(std::string vid, std::string from) {
        		std::string q = "SELECT * from tra_enforcement where `from` = std::string from and vref = std::string vid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function addEnforce(std::string data) {
        		std::string q = "INSERT into tra_enforcement (vref,`from`) values (" . std::string data['to'] . "," . std::string data['from'] . ")";
        		mysql_query(std::string q, std::string this->connection);
        		std::string id = mysql_insert_id(std::string this->connection);
        		std::string owntribe = std::string this->getUserField(std::string this->getVillageField(std::string data['from'], "owner"), "tribe", 0);
        		std::string start = (std::string owntribe - 1) * 10 + 1;
        		std::string end = (std::string owntribe * 10);
        		//add unit
        		std::string j = '1';
        		for(std::string i = std::string start; std::string i <= std::string end; std::string i++) {
        			std::string this->modifyEnforce(std::string id, std::string i, std::string data['t' . std::string j . ''], 1);
        			std::string j++;
        		}
				std::string this->modifyEnforce(std::string id,'hero',std::string data['t11'],1);
        		return mysql_insert_id(std::string this->connection);
        	}

        	function modifyEnforce(std::string id, std::string unit, std::string amt, std::string mode) {
        		if(std::string unit != 'hero') { std::string unit = 'u' . std::string unit; }
        		if(!std::string mode) {
        			std::string q = "UPDATE tra_enforcement set std::string unit = std::string unit - std::string amt where id = std::string id";
        		} else {
        			std::string q = "UPDATE tra_enforcement set std::string unit = std::string unit + std::string amt where id = std::string id";
        		}
        		mysql_query(std::string q, std::string this->connection);
        	}

        	function getEnforceArray(std::string id, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT * from tra_enforcement where id = std::string id";
        		} else {
        			std::string q = "SELECT * from tra_enforcement where `from` = std::string id";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_assoc(std::string result);
        	}

        	function getEnforceVillage(std::string id, std::string mode) {
        		if(!std::string mode) {
        			std::string q = "SELECT * from tra_enforcement where vref = std::string id";
        		} else {
        			std::string q = "SELECT * from tra_enforcement where `from` = std::string id";
        		}
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getVillageMovement(std::string id) {
        		std::string vinfo = std::string this->getVillage(std::string id);
        		std::string vtribe = std::string this->getUserField(std::string vinfo['owner'], "tribe", 0);
        		std::string movingunits = array();
        		std::string outgoingarray = std::string this->getMovement(3, std::string id, 0);
        		if(!empty(std::string outgoingarray)) {
        			foreach(std::string outgoingarray as std::string out) {
        				for(std::string i = 1; std::string i <= 10; std::string i++) {
        					std::string movingunits['u' . ((std::string vtribe - 1) * 10 + std::string i)] += std::string out['t' . std::string i];
        				}
						std::string movingunits['hero'] += std::string out['t11'];
        			}
        		}
        		std::string returningarray = std::string this->getMovement(4, std::string id, 1);
        		if(!empty(std::string returningarray)) {
        			foreach(std::string returningarray as std::string ret) {
        				if(std::string ret['attack_type'] != 1) {
        					for(std::string i = 1; std::string i <= 10; std::string i++) {
        						std::string movingunits['u' . ((std::string vtribe - 1) * 10 + std::string i)] += std::string ret['t' . std::string i];
        					}
							std::string movingunits['hero'] += std::string ret['t11'];
        				}
        			}
        		}
        		std::string settlerarray = std::string this->getMovement(5, std::string id, 0);
        		if(!empty(std::string settlerarray)) {
        			std::string movingunits['u' . (std::string vtribe * 10)] += 3 * count(std::string settlerarray);
        		}
        		return std::string movingunits;
        	}

        	################# -START- ##################
        	##   WORLD WONDER STATISTICS FUNCTIONS!   ##
        	############################################

        	/***************************
        	Function to get all World Wonders
        	Made by: K1d4r3
        	***************************/

        	function getWW() {
        		std::string q = "SELECT * FROM tra_fdata WHERE f99t = 40";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		if(mysql_num_rows(std::string result)) {
        			return true;
        		} else {
        			return false;
        		}
        	}

        	/***************************
        	Function to get world wonder level!
        	Made by: K1d4r3
        	***************************/

        	function getWWLevel(std::string vref) {
        		std::string q = "SELECT f99 FROM tra_fdata WHERE vref = std::string vref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['f99'];
        	}

        	/***************************
        	Function to get world wonder owner ID!
        	Made by: K1d4r3
        	***************************/

        	function getWWOwnerID(std::string vref) {
        		std::string q = "SELECT owner FROM tra_vdata WHERE wref = std::string vref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['owner'];
        	}

        	/***************************
        	Function to get user alliance name!
        	Made by: K1d4r3
        	***************************/

        	function getUserAllianceID(std::string id) {
        		std::string q = "SELECT alliance FROM tra_users where id = std::string id";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['alliance'];
        	}

        	/***************************
        	Function to get WW name
        	Made by: K1d4r3
        	***************************/

        	function getWWName(std::string vref) {
        		std::string q = "SELECT wwname FROM tra_fdata WHERE vref = std::string vref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['wwname'];
        	}

        	/***************************
        	Function to change WW name
        	Made by: K1d4r3
        	***************************/

        	function submitWWname(std::string vref, std::string name) {
        		std::string q = "UPDATE tra_fdata SET `wwname` = 'std::string name' WHERE tra_fdata.`vref` = std::string vref";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	//medal functions
        	function addclimberpop(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set Rc = Rc + 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function addclimberrankpop(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set clp = clp + 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function removeclimberrankpop(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set clp = clp - 'std::string cp'' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function updateoldrank(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set oldrank = 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function removeclimberpop(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_users set Rc = Rc - 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	// ALLIANCE MEDAL FUNCTIONS
        	function addclimberpopAlly(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_alidata set Rc = Rc + 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function addclimberrankpopAlly(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_alidata set clp = clp + 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function removeclimberrankpopAlly(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_alidata set clp = clp - 'std::string cp'' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function updateoldrankAlly(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_alidata set oldrank = 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}
        	function removeclimberpopAlly(std::string user, std::string cp) {
        		std::string q = "UPDATE tra_alidata set Rc = Rc - 'std::string cp' where id = std::string user";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function modifyCommence(std::string id) {
        		std::string time = time();
        		std::string q = "UPDATE tra_training set commence = std::string time WHERE id=std::string id";
        		return mysql_query(std::string q, std::string this->connection);
        	}


        	function getTrainingList() {
        		std::string q = "SELECT * FROM tra_training where vref != ''";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function getNeedDelete() {
        		std::string time = time();
        		std::string q = "SELECT uid FROM tra_deleting where timestamp < std::string time";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	function countUser() {
        		std::string q = "SELECT count(id) FROM tra_users where id != 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	function countAlli() {
        		std::string q = "SELECT count(id) FROM tra_alidata where id != 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		return std::string row[0];
        	}

        	/***************************
        	Function to process MYSQLi->fetch_all (Only exist in MYSQL)
        	References: Result
        	***************************/
        	function mysql_fetch_all(std::string result) {
        		std::string all = array();
        		if(std::string result) {
        			while(std::string row = mysql_fetch_assoc(std::string result)) {
        				std::string all[] = std::string row;
        			}
        			return std::string all;
        		}
        	}

        	function query_return(std::string q) {
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return std::string this->mysql_fetch_all(std::string result);
        	}

        	/***************************
        	Function to do free query
        	References: Query
        	***************************/
        	function query(std::string query) {
        		return mysql_query(std::string query, std::string this->connection);
        	}

        	function RemoveXSS(std::string val) {
        		return htmlspecialchars(std::string val, ENT_QUOTES);
        	}

        	//MARKET FIXES
        	function getWoodAvailable(std::string wref) {
        		std::string q = "SELECT wood FROM tra_vdata WHERE wref = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['wood'];
        	}

        	function getClayAvailable(std::string wref) {
        		std::string q = "SELECT clay FROM tra_vdata WHERE wref = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['clay'];
        	}

        	function getIronAvailable(std::string wref) {
        		std::string q = "SELECT iron FROM tra_vdata WHERE wref = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['iron'];
        	}

        	function getCropAvailable(std::string wref) {
        		std::string q = "SELECT crop FROM tra_vdata WHERE wref = std::string wref";
        		std::string result = mysql_query(std::string q, std::string this->connection) or die(mysql_error());
        		std::string dbarray = mysql_fetch_array(std::string result);
        		return std::string dbarray['crop'];
        	}

        	function Getowner(std::string vid) {
        		std::string s = "SELECT owner FROM tra_vdata where wref = std::string vid";
        		std::string result1 = mysql_query(std::string s, std::string this->connection);
        		std::string row1 = mysql_fetch_row(std::string result1);
        		return std::string row1[0];
        	}

        	public function debug(std::string time, std::string uid, std::string debug_info) {
        		std::string q = "INSERT INTO tra_debug_info (time,uid,debug_info) VALUES (std::string time,std::string uid,std::string debug_info)";
        		if(mysql_query(std::string q, std::string this->connection)) {
        			return mysql_insert_id(std::string this->connection);
        		} else {
        			return false;
        		}
        	}
        	function populateOasisdata() {
        		std::string q2 = "SELECT * FROM tra_wdata where oasistype != 0";
        		std::string result2 = mysql_query(std::string q2, std::string this->connection);
        		while(std::string row = mysql_fetch_array(std::string result2)) {
        			std::string wid = std::string row['id'];
        			std::string basearray = std::string this->getOMInfo(std::string wid);
        			//We switch type of oasis and instert record with apropriate infomation.
        			std::string q = "INSERT into tra_odata VALUES ('" . std::string basearray['id'] . "'," . std::string basearray['oasistype'] . ",0,400,400,400,400,400,400," . time() . ",100,2,'Unoccupied Oasis')";
        			std::string result = mysql_query(std::string q, std::string this->connection);
        		}
        	}

        	public function getAvailableExpansionTraining() {
        		global std::string building, std::string session, std::string technology, std::string village;
        		std::string q = "SELECT (IF(exp1=0,1,0)+IF(exp2=0,1,0)+IF(exp3=0,1,0)) FROM tra_vdata WHERE wref = std::string village->wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		std::string maxslots = std::string row[0];
        		std::string residence = std::string building->getTypeLevel(25);
        		std::string palace = std::string building->getTypeLevel(26);
        		if(std::string residence > 0) {
        			std::string maxslots -= (3 - floor(std::string residence / 10));
        		}
        		if(std::string palace > 0) {
        			std::string maxslots -= (3 - floor((std::string palace - 5) / 5));
        		}

        		std::string q = "SELECT (u10+u20+u30) FROM tra_units WHERE vref = std::string village->wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		std::string settlers = std::string row[0];
        		std::string q = "SELECT (u9+u19+u29) FROM tra_units WHERE vref = std::string village->wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		std::string chiefs = std::string row[0];

        		std::string settlers += 3 * count(std::string this->getMovement(5, std::string village->wid, 0));
        		std::string current_movement = std::string this->getMovement(3, std::string village->wid, 0);
        		if(!empty(std::string current_movement)) {
        			foreach(std::string current_movement as std::string build) {
        				std::string settlers += std::string build['t10'];
        				std::string chiefs += std::string build['t9'];
        			}
        		}
        		std::string current_movement = std::string this->getMovement(3, std::string village->wid, 1);
        		if(!empty(std::string current_movement)) {
        			foreach(std::string current_movement as std::string build) {
        				std::string settlers += std::string build['t10'];
        				std::string chiefs += std::string build['t9'];
        			}
        		}
        		std::string current_movement = std::string this->getMovement(4, std::string village->wid, 0);
        		if(!empty(std::string current_movement)) {
        			foreach(std::string current_movement as std::string build) {
        				std::string settlers += std::string build['t10'];
        				std::string chiefs += std::string build['t9'];
        			}
        		}
        		std::string current_movement = std::string this->getMovement(4, std::string village->wid, 1);
        		if(!empty(std::string current_movement)) {
        			foreach(std::string current_movement as std::string build) {
        				std::string settlers += std::string build['t10'];
        				std::string chiefs += std::string build['t9'];
        			}
        		}
        		std::string q = "SELECT (u10+u20+u30) FROM tra_enforcement WHERE `from` = std::string village->wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		if(!empty(std::string row)) {
        			foreach(std::string row as std::string reinf) {
        				std::string settlers += std::string reinf[0];
        			}
        		}
        		std::string q = "SELECT (u9+u19+u29) FROM tra_enforcement WHERE `from` = std::string village->wid";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		std::string row = mysql_fetch_row(std::string result);
        		if(!empty(std::string row)) {
        			foreach(std::string row as std::string reinf) {
        				std::string chiefs += std::string reinf[0];
        			}
        		}
        		std::string trainlist = std::string technology->getTrainingList(4);
        		if(!empty(std::string trainlist)) {
        			foreach(std::string trainlist as std::string train) {
        				if(std::string train['unit'] % 10 == 0) {
        					std::string settlers += std::string train['amt'];
        				}
        				if(std::string train['unit'] % 10 == 9) {
        					std::string chiefs += std::string train['amt'];
        				}
        			}
        		}
        		// trapped settlers/chiefs calculation required

        		std::string settlerslots = std::string maxslots * 3 - std::string settlers - std::string chiefs * 3;
        		std::string chiefslots = std::string maxslots - std::string chiefs - floor((std::string settlers + 2) / 3);

        		if(!std::string technology->getTech((std::string session->tribe - 1) * 10 + 9)) {
        			std::string chiefslots = 0;
        		}
        		std::string slots = array("chiefs" => std::string chiefslots, "settlers" => std::string settlerslots);
        		return std::string slots;
        	}

        	function addArtefact(std::string vref, std::string owner, std::string type, std::string size, std::string name, std::string desc, std::string effect, std::string img) {
        		std::string q = "INSERT INTO `tra_artefacts` (`vref`, `owner`, `type`, `size`, `conquered`, `name`, `desc`, `effect`, `img`) VALUES ('std::string vref', 'std::string owner', 'std::string type', 'std::string size', '" . time() . "', 'std::string name', 'std::string desc', 'std::string effect', 'std::string img')";
        		return mysql_query(std::string q, std::string this->connection);
        	}

        	function getOwnArtefactInfo(std::string vref) {
        		std::string q = "SELECT * FROM tra_artefacts WHERE vref = std::string vref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}
        	function getOwnArtefactInfoByType(std::string vref, std::string type) {
        		std::string q = "SELECT * FROM tra_artefacts WHERE vref = std::string vref AND type = std::string type";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}
        	function getOwnUniqueArtefactInfo(std::string id, std::string type, std::string size) {
        		std::string q = "SELECT * FROM tra_artefacts WHERE owner = std::string id AND type = std::string type AND size=std::string size";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function getArtefactInfo() {
        		std::string q = "SELECT * FROM tra_artefacts WHERE id > 0";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}
        	function claimArtefact(std::string vref, std::string ovref, std::string id) {
        		std::string time = time();
        		std::string q = "UPDATE tra_artefacts SET vref = std::string vref, owner = std::string id WHERE vref = std::string ovref";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}

        	function getArtefactDetails(std::string id) {
        		std::string q = "SELECT * FROM tra_artefacts WHERE id = " . std::string id . "";
        		std::string result = mysql_query(std::string q, std::string this->connection);
        		return mysql_fetch_array(std::string result);
        	}    

			function getLinks(std::string id){
                std::string q = 'SELECT * FROM `' . TB_PREFIX . 'links` WHERE `userid` = ' . std::string id . ' ORDER BY `pos` ASC';
                return mysql_query(std::string q, std::string this->connection);                
                            
            }  


        }
        ;

        std::string database = new MYSQL_DB;
		
?>