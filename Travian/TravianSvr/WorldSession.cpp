#include "preCompile.h"
#include "WorldSocket.h"                                    // must be first to make ACE happy with ACE includes in it
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "tra_village.h"

/// WorldSession constructor
WorldSession::WorldSession(uint32 id, WorldSocket *sock) :
/*_player(NULL),*/ m_Socket(sock),_accountId(id)
{
    if (sock)
    {
        m_Address = sock->GetRemoteAddress ();
        sock->AddReference ();
    }
}

/// WorldSession destructor
WorldSession::~WorldSession()
{
    /// - If have unclosed socket, close it
    if (m_Socket)
    {
        m_Socket->CloseSocket ();
        m_Socket->RemoveReference ();
        m_Socket = NULL;
    }

    ///- empty incoming packet queue
    WorldPacket* packet;
    while(_recvQueue.next(packet))
        delete packet;
}

void WorldSession::Handle_NULL( WorldPacket& recvPacket )
{

}

/// Send a packet to the client
void WorldSession::SendPacket(WorldPacket const* packet)
{
    if (!m_Socket)
        return;

    if (m_Socket->SendPacket (*packet) == -1)
        m_Socket->CloseSocket ();
}

/// Add an incoming packet to the queue
void WorldSession::QueuePacket(WorldPacket* new_packet)
{
    _recvQueue.add(new_packet);
}

/// Update the WorldSession (triggered by World update)
bool WorldSession::Update(uint32 /*diff*/)
{
   ///- Retrieve packets from the receive queue and call the appropriate handlers
    /// not proccess packets if socket already closed
    WorldPacket* packet;
    while (m_Socket && !m_Socket->IsClosed() && _recvQueue.next(packet))
    {
//          OpcodeHandler& opHandle = opcodeTable[packet->GetOpcode()];
//          switch (opHandle.status)
//          {
//              case STATUS_LOGGEDIN:
//                  // lag can cause STATUS_LOGGEDIN opcodes to arrive after the player started a transfer
//                  break;
//              case STATUS_LOGGEDIN_OR_RECENTLY_LOGGEDOUT:
// 
//                  break;
//              case STATUS_TRANSFER:
// 
//                  break;
//              case STATUS_AUTHED:
//                  // single from authed time opcodes send in to after logout time
//                  // and before other STATUS_LOGGEDIN_OR_RECENTLY_LOGGOUT opcodes.
// 
//                  (this->*opHandle.handler)(*packet);
// 
//                  break;
//              case STATUS_NEVER:
//                  sLog.outError( "SESSION: received not allowed opcode %s (0x%.4X)",
//                      LookupOpcodeName(packet->GetOpcode()),
//                      packet->GetOpcode());
//                  break;
//              case STATUS_UNHANDLED:
//                  sLog.outDebug("SESSION: received not handled opcode %s (0x%.4X)",
//                      LookupOpcodeName(packet->GetOpcode()),
//                      packet->GetOpcode());
//                  break;
//              default:
//                  sLog.outError("SESSION: received wrong-status-req opcode %s (0x%.4X)",
//                      LookupOpcodeName(packet->GetOpcode()),
//                      packet->GetOpcode());
//                  break;
//         }
        delete packet;
    }

    ///- Cleanup socket pointer if need
    if (m_Socket && m_Socket->IsClosed ())
    {
        m_Socket->RemoveReference ();
        m_Socket = NULL;
    }

    ///- If necessary, log the player out
    time_t currTime = time(NULL);

    if (!m_Socket)
        return false;                                       //Will remove this session from the world session map

    return true;
}

/// Kick a player out of the World
void WorldSession::KickPlayer()
{
    if (m_Socket)
        m_Socket->CloseSocket ();
}