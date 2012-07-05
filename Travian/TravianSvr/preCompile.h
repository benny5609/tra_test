/*******************************************************************************
* File Name:   preCompile.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/5  Thursday  9:55:58
* Comments:  
*
********************************************************************************/

#ifndef __PRECOMPILE_H__
#define __PRECOMPILE_H__

#include "common.h"

#include "ace/ace.h"
#include "ace/Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/Acceptor.h"
#include "ace/Synch.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/TP_Reactor.h"

#include "mysqlDB.h"
#include "tra_db.h"

#include "WorldSocketMgr.h"
#include "WorldRunnable.h"
#include "WorldPacket.h"
#include "app.h"

#endif  // end of guard preCompile.h
