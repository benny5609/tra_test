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


#include "my_global.h"
#include "mysql.h"

class Mysql_DB
{
public:
	Mysql_DB();
	virtual ~Mysql_DB();
	bool connect_db();
	bool usr_register(const std::string& usr, const std::string& pwd, const std::string& email, E_TRIBE tribe, E_LOCATE locate, E_ACTIVE act);
protected:
	MYSQL *conn;
};
#endif  // end of guard mysqlDB.h
