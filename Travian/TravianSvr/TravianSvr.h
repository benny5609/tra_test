/*******************************************************************************
* File Name:   TravianSvr.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/5/29  Tuesday  12:55:04
* Comments:  
*
********************************************************************************/

#ifndef __TRAVIANSVR_H__
#define __TRAVIANSVR_H__


#include "ace/ace.h"
#include "ace/Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/Acceptor.h"
#include "ace/Synch.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/TP_Reactor.h"
#include "mysqlDB.h"


class App
{
public:
	App();
	~App();
	bool init();
	bool uninit();
	bool run();

public:
	Mysql_DB* _db;
};

#endif  // end of guard TravianSvr.h
