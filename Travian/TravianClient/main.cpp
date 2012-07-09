#include "ace/Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/Connector.h"
#include "ace/Synch.h"
#include "ace/SOCK_Connector.h"
#include <iostream>
#include "msg_login.pb.h"
#include "Opcodes.h"
#include "common.h"
#include "ByteBuffer.h"
#include "WorldPacket.h"
#include <ostream>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/gzip_stream.h>

#pragma comment(lib, "aced.lib")
#pragma comment(lib,"libprotobuf_d.lib")

class My_Svc_Handler; 
typedef ACE_Connector<My_Svc_Handler,ACE_SOCK_CONNECTOR> MyConnector; 


typedef ACE_UINT8 uint8;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;

namespace ByteConverter
{
	template<size_t T>
	inline void convert(char *val)
	{
		std::swap(*val, *(val + T - 1));
		convert<T - 2>(val + 1);
	}

	template<> inline void convert<0>(char *) {}
	template<> inline void convert<1>(char *) {}            // ignore central byte

	template<typename T> inline void apply(T *val)
	{
		convert<sizeof(T)>((char *)(val));
	}
}

template<typename T> inline void EndianConvert(T&) { }
template<typename T> inline void EndianConvertReverse(T& val) { ByteConverter::apply<T>(&val); }

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
		return 5;
	}

	bool isLargePacket()
	{
		return size > 0x7FFF;
	}
	uint32 getCmd()
	{
		uint32 cmd = 0;
		if(isLargePacket())
			cmd = *((uint32*)(header+3));
		else
			cmd = *((uint32*)(header+2));
		return cmd;
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

	typedef ACE_Thread_Mutex LockType;
	typedef ACE_Guard<LockType> GuardType;
public: 
	My_Svc_Handler():
		m_RecvWPct (0),
		m_RecvPct (),
		m_Header (5),
		m_OutBuffer (0),
		m_OutActive (false),
		m_OutBufferSize (65536){}
	int open(void*) 
	{ 
		ACE_OS::printf("\nConnection established\n");

		 ACE_NEW_RETURN (m_OutBuffer, ACE_Message_Block (m_OutBufferSize), -1);
		//注册相应事件
		ACE_Reactor::instance()->register_handler(this, 
			ACE_Event_Handler::READ_MASK| ACE_Event_Handler::WRITE_MASK); 
		return 0; 
	}

	int Update (void)
	{
		return 0;
	}

	int handle_input(ACE_HANDLE) 
	{ 
// 		int rev = peer().recv(data,1024); 
// 		if(rev == 0)
// 		{
// 			delete this;
// 			return -1;
// 		}
// 		else
// 		{
// 			std::string echoStr= (char*)data+5;
// 			echo::EchoRequest req;
// 			req.ParseFromString(echoStr);
// 			//data[rev]='\0';
// 			//ACE_OS::printf("<<rev:\t %s\n",data); 
// 			return 0; 
// 		}
		switch (handle_input_missing_data ())
		{
		case -1 :
			{
				if ((errno == EWOULDBLOCK) ||
					(errno == EAGAIN))
				{
					return Update ();                           // interesting line ,isn't it ?
				}

				printf("WorldSocket::handle_input: Peer error closing connection errno = %s\n", ACE_OS::strerror (errno));

				errno = ECONNRESET;
				return -1;
			}
		case 0:
			{
				printf("WorldSocket::handle_input: Peer has closed connection\n");

				errno = ECONNRESET;
				return -1;
			}
		case 1:
			return 1;
		default:
			return Update ();                               // another interesting line ;)
		}
	}

	int sendData(char *msg, unsigned int size)
	{
		ACE_OS::printf("<<send:\t %s\n",msg);
		return peer().send(msg,size);    
	}

	int  sendProtoBuf(int opcode, const google::protobuf::Message& message)
	{
		std::string strMsg = message.SerializeAsString();

		ClientPktHeader clientHeader={0};
		clientHeader.cmd = opcode;
		clientHeader.size = strMsg.length() + 4;

		ACE_Message_Block* mb;
		ACE_NEW_RETURN(mb, ACE_Message_Block(clientHeader.size), -1);

		mb->copy((char*) &clientHeader, 4);
		mb->copy((const char*)strMsg.c_str(), strMsg.length());
		sendData(mb->rd_ptr(), mb->length());
		return 0;
	}

	int handle_output (ACE_HANDLE)
	{
		ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);

		if (closing_)
			return -1;

		const size_t send_len = m_OutBuffer->length ();

		if (send_len == 0)
			return handle_output_queue (Guard);

#ifdef MSG_NOSIGNAL
		ssize_t n = peer ().send (m_OutBuffer->rd_ptr (), send_len, MSG_NOSIGNAL);
#else
		ssize_t n = peer ().send (m_OutBuffer->rd_ptr (), send_len);
#endif // MSG_NOSIGNAL

		if (n == 0)
			return -1;
		else if (n == -1)
		{
			if (errno == EWOULDBLOCK || errno == EAGAIN)
				return schedule_wakeup_output (Guard);

			return -1;
		}
		else if (n < (ssize_t)send_len) //now n > 0
		{
			m_OutBuffer->rd_ptr (static_cast<size_t> (n));

			// move the data to the base of the buffer
			m_OutBuffer->crunch ();

			return schedule_wakeup_output (Guard);
		}
		else //now n == send_len
		{
			m_OutBuffer->reset ();

			return handle_output_queue (Guard);
		}

		ACE_NOTREACHED (return 0);
	}

	int handle_output_queue (GuardType& g)
	{
		if(msg_queue()->is_empty())
			return cancel_wakeup_output(g);

		ACE_Message_Block *mblk;

		if(msg_queue()->dequeue_head(mblk, (ACE_Time_Value*)&ACE_Time_Value::zero) == -1)
		{
			printf("WorldSocket::handle_output_queue dequeue_head\n");
			return -1;
		}

		const size_t send_len = mblk->length ();

#ifdef MSG_NOSIGNAL
		ssize_t n = peer ().send (mblk->rd_ptr (), send_len, MSG_NOSIGNAL);
#else
		ssize_t n = peer ().send (mblk->rd_ptr (), send_len);
#endif // MSG_NOSIGNAL

		if (n == 0)
		{
			mblk->release();

			return -1;
		}
		else if (n == -1)
		{
			if (errno == EWOULDBLOCK || errno == EAGAIN)
			{
				msg_queue()->enqueue_head(mblk, (ACE_Time_Value*) &ACE_Time_Value::zero);
				return schedule_wakeup_output (g);
			}

			mblk->release();
			return -1;
		}
		else if (n < (ssize_t)send_len) //now n > 0
		{
			mblk->rd_ptr (static_cast<size_t> (n));

			if (msg_queue()->enqueue_head(mblk, (ACE_Time_Value*) &ACE_Time_Value::zero) == -1)
			{
				printf("WorldSocket::handle_output_queue enqueue_head\n");
				mblk->release();
				return -1;
			}

			return schedule_wakeup_output (g);
		}
		else //now n == send_len
		{
			mblk->release();

			return msg_queue()->is_empty() ? cancel_wakeup_output(g) : ACE_Event_Handler::WRITE_MASK;
		}

		ACE_NOTREACHED(return -1);
	}

	int cancel_wakeup_output (GuardType& g)
	{
		if (!m_OutActive)
			return 0;

		m_OutActive = false;

		g.release ();

		if (reactor ()->cancel_wakeup
			(this, ACE_Event_Handler::WRITE_MASK) == -1)
		{
			// would be good to store errno from reactor with errno guard
			printf("WorldSocket::cancel_wakeup_output\n");
			return -1;
		}

		return 0;
	}

	int schedule_wakeup_output (GuardType& g)
	{
		if (m_OutActive)
			return 0;

		m_OutActive = true;

		g.release ();

		if (reactor ()->schedule_wakeup
			(this, ACE_Event_Handler::WRITE_MASK) == -1)
		{
			printf("WorldSocket::schedule_wakeup_output\n");
			return -1;
		}

		return 0;
	}
private:
	/// Helper functions for processing incoming data.
	int handle_input_header (void)
	{
		ACE_ASSERT (m_RecvWPct == NULL);

		ACE_ASSERT (m_Header.length () == 5);

		uint16 headerSize=0;
		uint16 headerCmd = 0;
		bool bighead = false;
		uint8 bufHead[5];
		uint32 ssss = 15;
		memcpy(bufHead, (char*)m_Header.rd_ptr (), 5);
		if(bufHead[4] == 0)
			bighead = false;
			
		if(bighead == false)
		{
			memcpy(&headerSize, (char*)m_Header.rd_ptr (), 2);
			memcpy(&headerCmd, (char*)m_Header.rd_ptr ()+2, 2);
			EndianConvertReverse(headerSize);
			EndianConvert(headerCmd);
		}
		else
		{
			memcpy(&headerSize, (char*)m_Header.rd_ptr (), 2);
			memcpy(&headerCmd, (char*)m_Header.rd_ptr ()+3, 2);
			EndianConvertReverse(headerSize);
			EndianConvert(headerCmd);
		}

		if ((headerSize < 5) || (headerSize > 10240) || (headerCmd  > 10240))
		{
			printf("WorldSocket::handle_input_header: client sent malformed packet size = %d , cmd = %d\n",
				headerSize, headerCmd);

			errno = EINVAL;
			return -1;
		}

		headerSize -= 5;

		ACE_NEW_RETURN (m_RecvWPct, WorldPacket ((uint16) headerCmd, headerSize), -1);

		if(headerSize > 0)
		{
			m_RecvWPct->resize (headerSize);
			m_RecvPct.base ((char*) m_RecvWPct->contents (), m_RecvWPct->size ());
		}
		else
		{
			ACE_ASSERT(m_RecvPct.space() == 0);
		}

		return 0;
	}

	int handle_input_payload (void)
	{
		// set errno properly here on error !!!
		// now have a header and payload

		ACE_ASSERT (m_RecvPct.space () == 0);
		ACE_ASSERT (m_Header.space () == 0);
		ACE_ASSERT (m_RecvWPct != NULL);

		const int ret = ProcessIncoming (m_RecvWPct);

		m_RecvPct.base (NULL, 0);
		m_RecvPct.reset ();
		m_RecvWPct = NULL;

		m_Header.reset ();

		if (ret == -1)
			errno = EINVAL;

		return ret;
	}

	int ProcessIncoming (WorldPacket* new_pct)
	{
		ACE_ASSERT (new_pct);

		// manage memory ;)
		ACE_Auto_Ptr<WorldPacket> aptr (new_pct);

		const ACE_UINT16 opcode = new_pct->GetOpcode ();

		if (opcode >= NUM_MSG_TYPES)
		{
			printf( "SESSION: received non-existed opcode 0x%.4X\n", opcode);
			return -1;
		}

		if (closing_)
			return -1;

		// Dump received packet.
		//sLog.outWorldPacketDump(uint32(get_handle()), new_pct->GetOpcode(), LookupOpcodeName(new_pct->GetOpcode()), new_pct, true);
		printf("client get msg %d\n", opcode);
		switch(opcode)
		{
		case SMSG_AUTH_CHALLENGE:
			{
				protocol::login::smsg_auth_challenge smsg;
				google::protobuf::io::ArrayInputStream istream (new_pct->contents(), new_pct->size());
				smsg.ParseFromZeroCopyStream(&istream);

				protocol::login::cmsg_auth_session cmsg;
				cmsg.set_clientbuid(1101);
				cmsg.set_clientseed("Client seed");
				cmsg.set_clienttime(smsg.svrtime()+ 50);
				cmsg.set_account("benny");
				sendProtoBuf(CMSG_AUTH_SESSION, cmsg);
				break;
			}
		case 123:
			{
// 				echo::EchoRequest msg;
// 				google::protobuf::io::ArrayInputStream istream (new_pct->contents(), new_pct->size());
// 				msg.ParseFromZeroCopyStream(&istream);
				
				break;
			}
		default:
			{

			}
				return 0;
			}

		return 0;
		ACE_NOTREACHED (return 0);
	}

	int handle_input_missing_data (void)
	{
		char buf [4096];

		ACE_Data_Block db ( sizeof (buf),
			ACE_Message_Block::MB_DATA,
			buf,
			0,
			0,
			ACE_Message_Block::DONT_DELETE,
			0);

		ACE_Message_Block message_block(&db,
			ACE_Message_Block::DONT_DELETE,
			0);

		const size_t recv_size = message_block.space ();

		const ssize_t n = peer ().recv (message_block.wr_ptr (),
			recv_size);

		if (n <= 0)
			return (int)n;

		message_block.wr_ptr (n);
		buf[n]='\0';
		char* msgBase = message_block.base();
		printf("client>>>recv: %s\n",message_block.base());

		while (message_block.length () > 0)
		{
			if (m_Header.space () > 0)
			{
				//need to receive the header
				const size_t to_header = (message_block.length () > m_Header.space () ? m_Header.space () : message_block.length ());
				m_Header.copy (message_block.rd_ptr (), to_header);
				message_block.rd_ptr (to_header);

				if (m_Header.space () > 0)
				{
					// Couldn't receive the whole header this time.
					ACE_ASSERT (message_block.length () == 0);
					errno = EWOULDBLOCK;
					return -1;
				}

				// We just received nice new header
				if (handle_input_header () == -1)
				{
					ACE_ASSERT ((errno != EWOULDBLOCK) && (errno != EAGAIN));
					return -1;
				}
			}

			// Its possible on some error situations that this happens
			// for example on closing when epoll receives more chunked data and stuff
			// hope this is not hack ,as proper m_RecvWPct is asserted around
			if (!m_RecvWPct)
			{
				printf("Forcing close on input m_RecvWPct = NULL\n");
				errno = EINVAL;
				return -1;
			}

			// We have full read header, now check the data payload
			if (m_RecvPct.space () > 0)
			{
				//need more data in the payload
				const size_t to_data = (message_block.length () > m_RecvPct.space () ? m_RecvPct.space () : message_block.length ());
				m_RecvPct.copy (message_block.rd_ptr (), to_data);
				message_block.rd_ptr (to_data);

				if (m_RecvPct.space () > 0)
				{
					// Couldn't receive the whole data this time.
					ACE_ASSERT (message_block.length () == 0);
					errno = EWOULDBLOCK;
					return -1;
				}
			}

			//just received fresh new payload
			if (handle_input_payload () == -1)
			{
				ACE_ASSERT ((errno != EWOULDBLOCK) && (errno != EAGAIN));
				return -1;
			}
		}

		return n == recv_size ? 1 : 2;
	}

private: 
	char data[1024];
	WorldPacket* m_RecvWPct;
	ACE_Message_Block m_RecvPct;
	ACE_Message_Block m_Header;
	ACE_Message_Block *m_OutBuffer;
	LockType m_OutBufferLock;
	size_t m_OutBufferSize;
	bool m_OutActive;
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

//   	login::login log;
//   	log.set_username("hello");
//   	log.set_password("benny");
//   	std::string myLog = log.SerializeAsString();
// 	svchandler->sendProtoBuf(CMSG_CHAR_CREATE, log);

//  	char szSend[1024]={0};
//  	std::cin>>szSend;
//  	svchandler->sendData(szSend, strlen(szSend));
	

	while(1) 
		ACE_Reactor::instance()->handle_events(); 
} 

