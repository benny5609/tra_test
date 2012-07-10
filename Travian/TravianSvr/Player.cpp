#include "preCompile.h"
#include "Player.h"
#include "tra_village.h"
#include "tra_hero.h"
#include "WorldSession.h"

Player::Player(WorldSession* session):m_session(session)
{
	LoadVillages();
}

Player::~Player()
{
	for(size_t i=0; i<m_villages.size(); i++)
	{
		delete m_villages[i];
	}
	m_villages.clear();
}

uint32 Player::GetID()
{
	if(!m_session)
		return 0;
	return m_session->_accountId;
}

bool Player::LoadVillages()
{
	QueryResult *result =
		sDB.Query ("SELECT wref FROM s2_vdata WHERE owner = %d",m_session->GetAccountId());
	if(!result)
		return false;

	do
	{
		uint32 vid = result->Fetch()[0].GetUInt32();
		Village* village = new Village(vid);
		m_villages.push_back(village);
	}
	while(result->NextRow());

	result->Delete();
	return true;
}

bool Player::LoadHero()
{
	return true;
}
