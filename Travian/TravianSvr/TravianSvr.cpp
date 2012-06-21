#include "TravianSvr.h"
#include "WorldSocketMgr.h"
#include "WorldRunnable.h"
#include "WorldPacket.h"

#pragma comment(lib,"libmysql.lib")
#ifdef _DEBUG
#pragma comment(lib,"libprotobuf_d.lib")
//#include <vld.h>
//#pragma comment(lib,"vld.lib")
#pragma comment(lib, "aced.lib")
#else
#pragma comment(lib,"libprotobuf.lib")
#pragma comment(lib, "ace.lib")
#endif

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wsock32.lib")

App::App(){}

App::~App(){}

bool App::init()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	//init mysql 
	_db = new Mysql_DB;
	bool bRet = _db->connect_db();
	//if(!bRet)
	//	return false;

	 sWorldSocketMgr->StartNetwork (3000, "0.0.0.0");
	return true;
}

bool App::uninit()
{
	google::protobuf::ShutdownProtobufLibrary();

	if(_db)
		delete _db;

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

int main(int argc, char* argv[])
{
	App* app= new App;
	app->init();
	app->run();
	app->uninit();
	delete app;
	return 0;
};