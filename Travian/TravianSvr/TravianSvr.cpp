#include "TravianSvr.h"

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"libzmq.lib")
#ifdef _DEBUG
#pragma comment(lib,"libprotobuf_d.lib")
#else
#pragma comment(lib,"libprotobuf.lib")
#endif

Mysql_DB* g_db = NULL;

int main(int argc, char* argv[])
{
 	g_db = new Mysql_DB;
 	bool bRet = g_db->connect_db();
 	if(!bRet)
 		return 0;

	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind ("tcp://*:5555");
	zmq::message_t request;
	zmq::message_t reply (5);
	int rc;
	while (true) 
	{
		//  Wait for next request from client
		rc  = socket.recv (&request);
		
		printf("client terminate %d\n", rc);
	
		//std::cout << "Received Hello" << std::endl;
		//  Do some 'work'
		//Sleep(1);
		//  Send reply back to client
		memcpy ((void *) reply.data (), "World", 5);
		socket.send (reply);
	}
	return 0;
};