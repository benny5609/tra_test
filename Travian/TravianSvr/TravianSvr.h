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

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <windows.h>

#include "mysqlDB.h"

#include "event2/event.h"
#include "event2/event_struct.h"

class App
{
public:
	App();
	~App();
	bool init();
	bool uninit();
	bool run();

public:
	event* add_timer(bool, event_callback_fn, void *, timeval&);
	event* add_read(evutil_socket_t, event_callback_fn, void*);

	Mysql_DB* _db;
	event_base* _base ;
	void *_ctx, *_mainSock;
	std::vector<event*> _events;
};

#endif  // end of guard TravianSvr.h
