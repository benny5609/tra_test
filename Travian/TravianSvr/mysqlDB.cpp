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