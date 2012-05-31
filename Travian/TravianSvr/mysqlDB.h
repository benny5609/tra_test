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


#include <zmq.hpp>
#include <string>
#include <iostream>
#include <windows.h>

#include "my_global.h"
#include "mysql.h"

class Mysql_DB
{
public:
	Mysql_DB();
	virtual ~Mysql_DB();
	bool connect_db();
protected:
	MYSQL *conn;
};
#endif  // end of guard mysqlDB.h
