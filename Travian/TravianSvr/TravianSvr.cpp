#include "TravianSvr.h"

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"libzmq.lib")
#ifdef _DEBUG
#pragma comment(lib,"libprotobuf_d.lib")
#else
#pragma comment(lib,"libprotobuf.lib")
#endif

#pragma comment(lib, "libevent.lib")
#pragma comment(lib, "libevent_extras.lib")
#pragma comment(lib, "libevent_core.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wsock32.lib")

int getpeeraddr(int sockfd) 
{
	char peeraddrstr[60];
	char peerip[18];
	struct sockaddr_in peeraddr;
	int len = 60;
	int ret = getpeername(sockfd, (struct sockaddr *)&peeraddr, &len);
	if (ret < 0)
	{
		ret = WSAGetLastError();
		return 0;
	}
	char * pIP = inet_ntoa(peeraddr.sin_addr);
	printf("peer address: %s:%d\n", pIP, ntohs(peeraddr.sin_port));
}

static void timeout_cb(evutil_socket_t fd, short event, void*arg)
{
	printf("调用 timeout_cb \n");
}


static void timeout_cb_ten(evutil_socket_t fd, short event, void*arg)
{
	printf("调用 timeout_cb 10\n");
}
/*
static void read_cb(evutil_socket_t fd, short event, void*sock)
{
	getpeeraddr(fd);
	printf("调用 read_cn read\n");

	zmq_msg_t msg;
	unsigned int events;
	size_t len= sizeof(events);
	zmq_getsockopt(sock, ZMQ_EVENTS, &events, &len);
	if ( events & ZMQ_POLLIN )
	{
		int dataRead = 0;
		while (1)
		{
			zmq_msg_init(&msg);
			dataRead = zmq_recv(sock, &msg, ZMQ_NOBLOCK);
			if (dataRead == -1 )
			{
				zmq_msg_close(&msg);
				printf("socket [%d] read end\n", fd);
				break;
			}
			
			printf("socket [%d] recv: %s\n", fd, (char *)zmq_msg_data(&msg));
			zmq_msg_close(&msg);
		}
	}
	else
	{
		printf("socket [%d ] event else %d \n", fd , events);
		if( events & ZMQ_POLLOUT)
		{

		}
	}
}
*/

void
on_read(int fd, short ev, void *arg)
{
        struct client *client = (struct client *)arg;
        u_char buf[8196];
        int len, wlen;

        len = read(fd, buf, sizeof(buf));
        if (len == 0) {
                /* Client disconnected, remove the read event and the
                 * free the client structure. */
                printf("Client disconnected.\n");
                close(fd);
                event_del(&client->ev_read);
                free(client);
                return;
        }
        else if (len < 0) {
                /* Some other error occurred, close the socket, remove
                 * the event and free the client structure. */
                printf("Socket failure, disconnecting client: %s",
                    strerror(errno));
                close(fd);
                event_del(&client->ev_read);
                free(client);
                return;
        }

        /* XXX For the sake of simplicity we'll echo the data write
         * back to the client.  Normally we shouldn't do this in a
         * non-blocking app, we should queue the data and wait to be
         * told that we can write.
         */
        wlen = write(fd, buf, len);
        if (wlen < len) {
                /* We didn't write all our data.  If we had proper
                 * queueing/buffering setup, we'd finish off the write
                 * when told we can write again.  For this simple case
                 * we'll just lose the data that didn't make it in the
                 * write.
                 */
                printf("Short write, not all data echoed back to client.\n");
        }
}

/**
 * This function will be called by libevent when there is a connection
 * ready to be accepted.
 */
void
on_accept(int fd, short ev, void *arg)
{
        int client_fd;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        struct client *client;

        /* Accept the new connection. */
        client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
                warn("accept failed");
                return;
        }

        /* Set the client socket to non-blocking mode. */
        if (setnonblock(client_fd) < 0)
                warn("failed to set client socket non-blocking");

        /* We've accepted a new client, allocate a client object to
         * maintain the state of this client. */
        client = calloc(1, sizeof(*client));
        if (client == NULL)
                err(1, "malloc failed");

        /* Setup the read event, libevent will call on_read() whenever
         * the clients socket becomes read ready.  We also make the
         * read event persistent so we don't have to re-add after each
         * read. */
        event_set(&client->ev_read, client_fd, EV_READ|EV_PERSIST, on_read, 
            client);

        /* Setting up the event does not activate, add the event so it
         * becomes active. */
        event_add(&client->ev_read, NULL);

        printf("Accepted connection from %s\n",
               inet_ntoa(client_addr.sin_addr));
}

App::App(){}

App::~App(){}

bool App::init()
{
	//init mysql 
	_db = new Mysql_DB;
	bool bRet = _db->connect_db();
	if(!bRet)
		return false;

	//init libevent2
	_base = event_base_new();

	//init zeromq
	_ctx = zmq_init(1);
	_mainSock= zmq_socket(_ctx, ZMQ_REP);
	zmq_bind(_mainSock, "tcp://*:5555");
	return true;
}

bool App::uninit()
{
	if(_db)
		delete _db;
	event_base_free(_base);

	zmq_close(_mainSock);
	zmq_term(_ctx);
	return true;
}

bool App::run()
{
	event_base_dispatch(_base);
	return true;
}

event* App::add_timer(bool once, event_callback_fn fn, void * arg, timeval& tv)
{
	event* evt = event_new(_base, -1 , (once?0:EV_PERSIST), fn, arg);
	if(evt)
	{
		event_add(evt, &tv);
		_events.push_back(evt);
	}
	return evt;
}

event* App::add_read(evutil_socket_t sock, event_callback_fn fn, void* arg)
{
	event* evt = event_new(_base, sock, EV_READ | EV_PERSIST, fn, arg);
	if(evt)
	{
		event_add(evt, NULL);
		_events.push_back(evt);
	}
	return evt;
}

int main(int argc, char* argv[])
{
	App* app= new App;
	app->init();
// 	timeval tv={1, 0};
// 	app->add_timer(false, timeout_cb, NULL, tv);
// 	timeval tv10={10, 0};
// 	app->add_timer(true, timeout_cb_ten, NULL, tv10);
 	int pairfd;
	size_t len = sizeof(pairfd);
	 zmq_getsockopt(app->_mainSock, ZMQ_FD, &pairfd, &len);
	app->add_read(pairfd, read_cb, app->_mainSock);
	app->run();	
	return 0;
};