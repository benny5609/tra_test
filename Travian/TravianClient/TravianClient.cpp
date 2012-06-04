#include "TravianClient.h"



#pragma comment(lib,"libzmq.lib")
#ifdef _DEBUG
#pragma comment(lib,"libprotobuf_d.lib")
#else
#pragma comment(lib,"libprotobuf.lib")
#endif

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <zmq.h>
#include <time.h>

int main(int argc, char* argv[])
{

	printf("client1!\n");
	clock_t start = clock();
	int rc;
	void *ctx, *s;

	ctx = zmq_init(1);
	assert(ctx);

	s = zmq_socket(ctx, ZMQ_REQ);
	assert(s);

	rc = zmq_connect(s, "tcp://192.168.1.202:5555");
	assert(rc == 0);

	zmq_msg_t query, resultset;
	const char *query_string = "hello ZeroMQ.";
	for (int i =0; i < 1; ++i)
	{
		// send
		rc = zmq_msg_init_size(&query, strlen(query_string)+1);
		assert(rc == 0);
		memcpy(zmq_msg_data(&query), query_string, strlen(query_string)+1);
		rc = zmq_send(s, &query, 0);
		assert(rc == 0);
		// recv
		rc = zmq_msg_init(&resultset);
		assert(rc == 0);
		rc = zmq_recv(s, &resultset, 0);
		assert(rc == 0);
	}
	zmq_msg_close(&query);
	zmq_msg_close(&resultset);

	clock_t end = clock();

	double d = (double)(end - start) / CLOCKS_PER_SEC;

	printf("start:%ld end:%ld total:%lf sec\n",start,end, d);
	system("pause");
	zmq_close(s);
	zmq_term(ctx);

	//
	return 0;
};