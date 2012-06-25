#include "ace/Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/Connector.h"
#include "ace/Synch.h"
#include "ace/SOCK_Connector.h"
#include <iostream>
#include "msg_login.pb.h"
#include "Opcodes.h"
#include "echo.pb.h"
#pragma comment(lib, "aced.lib")
#pragma comment(lib,"libprotobuf_d.lib")

class My_Svc_Handler; 
typedef ACE_Connector<My_Svc_Handler,ACE_SOCK_CONNECTOR> MyConnector; 


typedef ACE_UINT8 uint8;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;

#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

struct ServerPktHeader
{
	//size is the length of the payload _plus_ the length of the opcode

	ServerPktHeader(uint32 size, uint16 cmd) : size(size)
	{
		uint8 headerIndex=0;
		if(isLargePacket())
		{
			header[headerIndex++] = 0x80|(0xFF &(size>>16));
		}
		header[headerIndex++] = 0xFF &(size>>8);
		header[headerIndex++] = 0xFF &size;

		header[headerIndex++] = 0xFF & cmd;
		header[headerIndex++] = 0xFF & (cmd>>8);
	}

	uint8 getHeaderLength()
	{
		// cmd = 2 bytes, size= 2||3bytes
		return 2+(isLargePacket()?3:2);
	}

	bool isLargePacket()
	{
		return size > 0x7FFF;
	}

	const uint32 size;
	uint8 header[5];
};

struct ClientPktHeader
{
	uint16 size;
	uint16 cmd;
};

#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)

#endif
class My_Svc_Handler: 
	public ACE_Svc_Handler <ACE_SOCK_STREAM,ACE_NULL_SYNCH> 
{ 
public: 
	int open(void*) 
	{ 
		ACE_OS::printf("\nConnection established\n");

		//注册相应事件
		ACE_Reactor::instance()->register_handler(this, 
			ACE_Event_Handler::READ_MASK); 
		return 0; 
	}

	int handle_input(ACE_HANDLE) 
	{ 
		int rev = peer().recv(data,1024); 
		if(rev == 0)
		{
			delete this;
			return -1;
		}
		else
		{
			std::string echoStr= (char*)data+5;
			echo::EchoRequest req;
			req.ParseFromString(echoStr);
			//data[rev]='\0';
			//ACE_OS::printf("<<rev:\t %s\n",data); 
			return 0; 
		}
	}

	int sendData(char *msg, unsigned int size)
	{
		ACE_OS::printf("<<send:\t %s\n",msg);
		return peer().send(msg,size);    
	}

private: 
	char data[1024]; 
}; 



int main(int argc, char* argv[]) 
{ 
	//ACE_INET_Addr addr(3000,"192.168.1.143"); 
	ACE_INET_Addr addr(3000,"127.0.0.1");

	My_Svc_Handler *svchandler = new My_Svc_Handler();
	MyConnector connector;

	if(connector.connect(svchandler,addr)==-1)
	{
		ACE_OS::printf("Connect fail");
	}

  	login::login log;
  	log.set_username("hello");
  	log.set_password("benny");
  	std::string myLog = log.SerializeAsString();
//  
 	ClientPktHeader testHeader={0};
  	testHeader.cmd = CMSG_CHAR_CREATE;
  	testHeader.size = myLog.length() + 4;
  
  	ACE_Message_Block* mb;
  	ACE_NEW_RETURN(mb, ACE_Message_Block(testHeader.size), -1);
  
  	mb->copy((char*) &testHeader, 4);
  	mb->copy((const char*)myLog.c_str(), myLog.length());
  	svchandler->sendData(mb->rd_ptr(), mb->length());

//  	char szSend[1024]={0};
//  	std::cin>>szSend;
//  	svchandler->sendData(szSend, strlen(szSend));
	

	while(1) 
		ACE_Reactor::instance()->handle_events(); 
} 

