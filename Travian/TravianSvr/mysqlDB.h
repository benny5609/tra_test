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
#include "field.h"
#include "my_global.h"
#include "mysql.h"
#include "ace/Thread_Mutex.h"
#include "ace/Guard_T.h"

#define MAX_QUERY_LEN   32*1024

class QueryResult;

class Mysql_DB
{
public:
	Mysql_DB();
	virtual ~Mysql_DB();
	bool connect_db();
	QueryResult* Query(const char* QueryString, ...);
protected:
	MYSQL *conn;
	ACE_Thread_Mutex mMutex;
};

class QueryResult
{
public:
	QueryResult(uint32 fields, uint32 rows) : mFieldCount(fields), mRowCount(rows), mCurrentRow(NULL) {}
	virtual ~QueryResult() {}

	virtual bool NextRow() = 0;
	void Delete() { delete this; }

	Field* Fetch() { return mCurrentRow; }
	uint32 GetFieldCount() const { return mFieldCount; }
	uint32 GetRowCount() const { return mRowCount; }

protected:
	uint32 mFieldCount;
	uint32 mRowCount;
	Field* mCurrentRow;
};

class MySQLQueryResult : public QueryResult
{
public:
	MySQLQueryResult(MYSQL_RES* res, uint32 FieldCount, uint32 RowCount);
	~MySQLQueryResult();

	bool NextRow();

protected:
	MYSQL_RES* mResult;
};

#endif  // end of guard mysqlDB.h
