#include "preCompile.h"
#include "mysqlDB.h"

#define DB_ADDR "localhost"
#define DB_USER "root"
#define DB_PASSWORD ""
#define DB_NAME "s2"


MySQLQueryResult::MySQLQueryResult(MYSQL_RES* res, uint32 FieldCount, uint32 RowCount) : QueryResult(FieldCount, RowCount), mResult(res)
{
	mCurrentRow = new Field[FieldCount];
}

MySQLQueryResult::~MySQLQueryResult()
{
	mysql_free_result(mResult);
	delete [] mCurrentRow;
}

bool MySQLQueryResult::NextRow()
{
	MYSQL_ROW row = mysql_fetch_row(mResult);
	if(row == NULL)
		return false;

	for(uint32 i = 0; i < mFieldCount; ++i)
		mCurrentRow[i].SetValue(row[i]);

	return true;
}

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

QueryResult* Mysql_DB::Query(const char* QueryString, ...)
{
	ACE_Guard<ACE_Thread_Mutex> query_connection_guard(mMutex);
	char sql[MAX_QUERY_LEN];
	va_list vlist;
	va_start(vlist, QueryString);
	vsnprintf(sql, MAX_QUERY_LEN, QueryString, vlist);
	va_end(vlist);

	// Send the query
	MySQLQueryResult* res = NULL;
	int result = mysql_query(conn, sql);
	if(result)
	{
		printf("sql [%s] get error [%s]\n", sql, mysql_error(conn));
	}
	else
	{
		MYSQL_RES* pRes = mysql_store_result(conn);
		uint32 uRows = (uint32)mysql_affected_rows(conn);
		uint32 uFields = (uint32)mysql_field_count(conn);

		if(uRows == 0 || uFields == 0 || pRes == 0)
		{
			if(pRes != NULL)
				mysql_free_result(pRes);
			return NULL;
		}
		res = new MySQLQueryResult(pRes, uFields, uRows);
		res->NextRow();
	}
	return res;
}



