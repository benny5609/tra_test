#include <ace/Message_Block.h>
#include <ace/OS_NS_string.h>
#include <ace/OS_NS_unistd.h>
#include <ace/os_include/arpa/os_inet.h>
#include <ace/os_include/netinet/os_tcp.h>
#include <ace/os_include/sys/os_types.h>
#include <ace/os_include/sys/os_socket.h>
#include <ace/OS_NS_string.h>
#include <ace/Reactor.h>
#include <ace/Auto_Ptr.h>

#include "WorldSocket.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "WorldSession.h"
#include "WorldSocketMgr.h"
#include "World.h"
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

WorldSocket::WorldSocket (void) :
WorldHandler (),
m_Session (0),
m_RecvWPct (0),
m_RecvPct (),
m_Header (sizeof (ClientPktHeader)),
m_OutBuffer (0),
m_OutBufferSize (65536),
m_OutActive (false),
m_Seed (static_cast<uint32> (/*rand32 ()*/11)),
m_OverSpeedPings (0),
m_LastPingTime (ACE_Time_Value::zero)
{
    reference_counting_policy ().value (ACE_Event_Handler::Reference_Counting_Policy::ENABLED);

    msg_queue()->high_water_mark(8*1024*1024);
    msg_queue()->low_water_mark(8*1024*1024);
}



WorldSocket::~WorldSocket (void)
{
    if (m_RecvWPct)
        delete m_RecvWPct;

    if (m_OutBuffer)
        m_OutBuffer->release ();

	ACE_INET_Addr remote_addr;
	if (peer ().get_remote_addr (remote_addr) == -1)
	{
		printf("~WorldSocket,  peer ().get_remote_addr errno = %s\n", ACE_OS::strerror (errno));
	}
	else
	{
		printf("~WorldSocket,close socket (%s:%d) \n", 
			remote_addr.get_host_addr (), remote_addr.get_port_number());
	}

// 	typedef ACE_Atomic_Op<ACE_SYNCH_MUTEX, long> AtomicInt;
// 	static AtomicInt destructNum = 0;
// 	printf("destructNum %d\n", ++destructNum);

    closing_ = true;

    peer ().close ();
}

bool WorldSocket::IsClosed (void) const
{
    return closing_;
}

void WorldSocket::CloseSocket (void)
{
    {
        ACE_GUARD (LockType, Guard, m_OutBufferLock);

        if (closing_)
            return;

        closing_ = true;

        peer ().close_writer ();
    }

    {
        ACE_GUARD (LockType, Guard, m_SessionLock);

        m_Session = NULL;
    }
}

const std::string& WorldSocket::GetRemoteAddress (void) const
{
    return m_Address;
}

int WorldSocket::SendPacket (const WorldPacket& pct)
{
    ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);
/*
    if (closing_)
        return -1;

    ServerPktHeader header(pct.size()+2, pct.GetOpcode());

     if (m_OutBuffer->space () >= pct.size () + header.getHeaderLength() && msg_queue()->is_empty())
     {
         // Put the packet on the buffer.
         if (m_OutBuffer->copy ((char*) header.header, header.getHeaderLength()) == -1)
             ACE_ASSERT (false);

         if (!pct.empty ())
             if (m_OutBuffer->copy ((char*) pct.contents (), pct.size ()) == -1)
                 ACE_ASSERT (false);
    }
    else
    {
        // Enqueue the packet.
        ACE_Message_Block* mb;

        ACE_NEW_RETURN(mb, ACE_Message_Block(pct.size () + header.getHeaderLength()), -1);

        mb->copy((char*) header.header, header.getHeaderLength());

         if (!pct.empty ())
             mb->copy((const char*)pct.contents(), pct.size ());

        if(msg_queue()->enqueue_tail(mb,(ACE_Time_Value*)&ACE_Time_Value::zero) == -1)
        {
            printf("WorldSocket::SendPacket enqueue_tail\n");
            mb->release();
            return -1;
        }
    }
*/
    return 0;
}

long WorldSocket::AddReference (void)
{
    return static_cast<long> (add_reference ());
}

long WorldSocket::RemoveReference (void)
{
    return static_cast<long> (remove_reference ());
}

int WorldSocket::open (void *a)
{
    ACE_UNUSED_ARG (a);

    // Prevent double call to this func.
    if (m_OutBuffer)
        return -1;

    // This will also prevent the socket from being Updated
    // while we are initializing it.
    m_OutActive = true;

    // Hook for the manager.
    if (sWorldSocketMgr->OnSocketOpen (this) == -1)
        return -1;

    // Allocate the buffer.
    ACE_NEW_RETURN (m_OutBuffer, ACE_Message_Block (m_OutBufferSize), -1);

    // Store peer address.
    ACE_INET_Addr remote_addr;

    if (peer ().get_remote_addr (remote_addr) == -1)
    {
        printf("WorldSocket::open: peer ().get_remote_addr errno = %s\n", ACE_OS::strerror (errno));
        return -1;
    }

    m_Address = remote_addr.get_host_addr ();

 
    // Register with ACE Reactor
    if (reactor ()->register_handler(this, ACE_Event_Handler::READ_MASK | ACE_Event_Handler::WRITE_MASK) == -1)
    {
        printf("WorldSocket::open: unable to register client handler errno = %s\n", ACE_OS::strerror (errno));
        return -1;
    }

	ACE_NEW_RETURN (m_Session, WorldSession (123456, this), -1);

	sWorld->AddSession (m_Session);
    // reactor takes care of the socket from now on
    remove_reference ();

//  	WorldPacket packet(SMSG_DBLOOKUP, 100);
//  	packet << uint32(0x11223344);                                // team id
//  	packet << uint8(0x55); 
//  	m_Session->SendPacket(&packet);
    return 0;
}

int WorldSocket::close (int)
{
    shutdown ();

    closing_ = true;

    remove_reference ();

    return 0;
}

int WorldSocket::handle_input (ACE_HANDLE)
{
    if (closing_)
        return -1;

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

    ACE_NOTREACHED(return -1);
}

int WorldSocket::handle_output (ACE_HANDLE)
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

int WorldSocket::handle_output_queue (GuardType& g)
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

int WorldSocket::handle_close (ACE_HANDLE h, ACE_Reactor_Mask)
{
    // Critical section
    {
        ACE_GUARD_RETURN (LockType, Guard, m_OutBufferLock, -1);

        closing_ = true;

        if (h == ACE_INVALID_HANDLE)
            peer ().close_writer ();
    }

    // Critical section
    {
        ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

        m_Session = NULL;
    }

    return 0;
}

int WorldSocket::Update (void)
{
    if (closing_)
        return -1;

    if (m_OutActive || (m_OutBuffer->length () == 0 && msg_queue()->is_empty()))
        return 0;

    int ret;
    do
        ret = handle_output (get_handle ());
    while( ret > 0 );

    return ret;
}

int WorldSocket::handle_input_header (void)
{
    ACE_ASSERT (m_RecvWPct == NULL);

    ACE_ASSERT (m_Header.length () == sizeof (ClientPktHeader));

//     ClientPktHeader& header = *((ClientPktHeader*) m_Header.rd_ptr ());
// 
//     //EndianConvertReverse(header.size);
//     //EndianConvert(header.cmd);
// 
//     if ((header.size < 4) || (header.size > 10240) || (header.cmd  > 10240))
//     {
//         printf("WorldSocket::handle_input_header: client sent malformed packet size = %d , cmd = %d\n",
//                        header.size, header.cmd);
// 
//         errno = EINVAL;
//         return -1;
//     }
// 
//     header.size -= 4;
// 
//     ACE_NEW_RETURN (m_RecvWPct, WorldPacket ((uint16) header.cmd, header.size), -1);
// 
//     if(header.size > 0)
//     {
//          m_RecvWPct->resize (header.size);
//          m_RecvPct.base ((char*) m_RecvWPct->contents (), m_RecvWPct->size ());
//     }
//     else
//     {
//         ACE_ASSERT(m_RecvPct.space() == 0);
//     }

    return 0;
}

int WorldSocket::handle_input_payload (void)
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

int WorldSocket::handle_input_missing_data (void)
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
	printf(">>>recv: %s\n",message_block.base());

	//return n == recv_size ? 1 : 2;

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

int WorldSocket::cancel_wakeup_output (GuardType& g)
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

int WorldSocket::schedule_wakeup_output (GuardType& g)
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

int WorldSocket::ProcessIncoming (WorldPacket* new_pct)
{
    ACE_ASSERT (new_pct);

    // manage memory ;)
    ACE_Auto_Ptr<WorldPacket> aptr (new_pct);

    const ACE_UINT16 opcode = new_pct->GetOpcode ();

//      if (opcode >= NUM_MSG_TYPES)
//      {
//          printf( "SESSION: received non-existed opcode 0x%.4X\n", opcode);
//          return -1;
//      }

    if (closing_)
        return -1;

    // Dump received packet.
    //sLog.outWorldPacketDump(uint32(get_handle()), new_pct->GetOpcode(), LookupOpcodeName(new_pct->GetOpcode()), new_pct, true);

    switch(opcode)
    {
       /* case CMSG_PING:
            return HandlePing (*new_pct);
        case CMSG_AUTH_SESSION:
             if (m_Session)
             {
                 sLog.outError ("WorldSocket::ProcessIncoming: Player send CMSG_AUTH_SESSION again");
                 return -1;
             }

            return HandleAuthSession (*new_pct);
        case CMSG_KEEP_ALIVE:
            DEBUG_LOG ("CMSG_KEEP_ALIVE ,size: "SIZEFMTD" ", new_pct->size ());

            return 0;
        default:
        {
            ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);

             if (m_Session != NULL)
             {
                 // OK ,give the packet to WorldSession
                 aptr.release ();
                 // WARNINIG here we call it with locks held.
                 // Its possible to cause deadlock if QueuePacket calls back
                 m_Session->QueuePacket (new_pct);
                 return 0;
             }
             else
             {
                 sLog.outError ("WorldSocket::ProcessIncoming: Client not authed opcode = %u", uint32(opcode));
                 return -1;
             }*/
	default:
			{
				ACE_GUARD_RETURN (LockType, Guard, m_SessionLock, -1);
				if (m_Session != NULL)
				{
					// OK ,give the packet to WorldSession
					aptr.release ();
					// WARNINIG here we call it with locks held.
					// Its possible to cause deadlock if QueuePacket calls back
					m_Session->QueuePacket (new_pct);
				}
				return 0;
			}
    }

	return 0;
    ACE_NOTREACHED (return 0);
}