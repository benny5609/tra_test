#include "preCompile.h"
#include "app.h"


#pragma comment(lib,"libmysql.lib")
#ifdef _DEBUG
#pragma comment(lib,"libprotobuf_d.lib")
#include <vld.h>
#pragma comment(lib,"vld.lib")
#pragma comment(lib, "aced.lib")
#else
#pragma comment(lib,"libprotobuf.lib")
#pragma comment(lib, "ace.lib")
#endif

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wsock32.lib")


App* g_app = NULL;
TravianDB* g_db = NULL;

App::App(){}

App::~App(){}

bool App::init()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	//init mysql 
	g_db = new TravianDB;
	bool bRet = g_db->connect_db();
	//if(!bRet)
	//	return false;

	sWorldSocketMgr->StartNetwork (3000, "0.0.0.0");
	return true;
}

bool App::uninit()
{
	google::protobuf::ShutdownProtobufLibrary();

	if(g_db)
		delete g_db;

	return true;
}

bool App::run()
{
	ACE_Based::Thread world_thread(new WorldRunnable);
	world_thread.setPriority(ACE_Based::Highest);
	sWorldSocketMgr->Wait ();
	world_thread.wait();
	return true;
}
