/*******************************************************************************
* File Name:   app.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/5  Thursday  9:29:40
* Comments:  
*
********************************************************************************/

#ifndef __APP_H__
#define __APP_H__

class TravianDB;
class App
{
public:
	App();
	~App();
	bool init();
	bool uninit();
	bool run();

public:
	
};

extern App* g_app;
extern TravianDB* g_db;
#define sDB (*g_db) 

#endif  // end of guard app.h
