#include "preCompile.h"
#include "WorldSession.h"

void WorldSession::HandlePlayerLoginOpcode( WorldPacket & recv_data )
{
	if(PlayerLoading() || GetPlayer() != NULL)
	{
		//sLog.outError("Player tryes to login again, AccountId = %d", GetAccountId());
		return;
	}

	m_playerLoading = true;
	uint64 playerGuid = 0;

	recv_data >> playerGuid;

// 	LoginQueryHolder *holder = new LoginQueryHolder(GetAccountId(), playerGuid);
// 	if(!holder->Initialize())
// 	{
// 		delete holder;                                      // delete all unprocessed queries
// 		m_playerLoading = false;
// 		return;
// 	}
// 
// 	CharacterDatabase.DelayQueryHolder(&chrHandler, &CharacterHandler::HandlePlayerLoginCallback, holder);
}