/*******************************************************************************
* File Name:   Player.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/6  Friday  16:37:06
* Comments:  
*
********************************************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__

class Village;
class Hero;
class WorldSession;

class Player
{
public:
	explicit Player(WorldSession* session);
	~Player();
	bool LoadVillages();
	bool LoadHero();
	uint32 GetID();
	WorldSession* GetSession(){return m_session;}
protected:
	bool SendVillagesPacket();
	WorldSession* m_session;
	std::vector<Village*> m_villages;
};

#endif  // end of guard Player.h
