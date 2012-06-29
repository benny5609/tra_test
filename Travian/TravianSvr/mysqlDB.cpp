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
