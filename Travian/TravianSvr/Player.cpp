#include "preCompile.h"
#include "Player.h"
#include "tra_village.h"
#include "tra_hero.h"
#include "WorldSession.h"
#include "entity.pb.h"
#include "World.h"
Player::Player(WorldSession* session):m_session(session)
{
	LoadVillages();
	SendVillagesPacket();
}

Player::~Player()
{
// 	for(size_t i=0; i<m_villages.size(); i++)
// 	{
// 		delete m_villages[i];
// 	}
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
		Village* village = NULL;
		uint32 vid = result->Fetch()[0].GetUInt32();
		Village* vilInWord = sWorld->FindVillage(vid);
		if(vilInWord)
			village = vilInWord;
		else
		{
			village = new Village(vid, this);
			sWorld->AddVillage(village);
		}
		m_villages.push_back(village);
	}
	while(result->NextRow());

	result->Delete();
	return true;
}

Village* Player::GetVillage(uint32 vid)
{
	return sWorld->FindVillage(vid);
}

bool Player::SendVillagesPacket()
{
	entity::Villages villages;
	for(size_t i=0; i<m_villages.size();i++)
	{
		entity::Village* entityVil = villages.add_vil();
		Village* village = m_villages[i];
		entityVil->mutable_place()->set_wref(village->wref);
		entityVil->mutable_place()->set_fieldtype(village->fieldtype);
		entityVil->mutable_place()->set_oasistype(village->oasistype);
		entityVil->mutable_place()->set_x(village->x);
		entityVil->mutable_place()->set_y(village->y);
		entityVil->mutable_place()->set_occupied(village->occupied);
		entityVil->mutable_place()->set_image(village->image);
		entityVil->set_owner(village->owner);
		entityVil->set_capital(village->capital);
		entityVil->set_pop(village->pop);
		entityVil->set_cp(village->cp);
		entityVil->set_celebration(village->celebration);
		entityVil->set_type(village->type);
		entityVil->set_wood(village->wood);
		entityVil->set_clay(village->clay);
		entityVil->set_iron(village->iron);
		entityVil->set_crop(village->crop);
		entityVil->set_maxstore(village->maxstore);
		entityVil->set_maxcrop(village->maxcrop);
		entityVil->set_lastupdate(village->lastupdate);
		entityVil->set_name(village->name);
		entityVil->set_loyalty(village->loyalty);
		//int byteSize = entityVil->ByteSize(); //92
	}
	m_session->SendPacket(SMSG_LOAD_VILLAGES,villages);

	Village* village = m_villages[0];
	village->wood  = 9999;
	village->clay = 9999;
	village->UpdateRes();
	return true;
}

bool Player::LoadHero()
{
	return true;
}
