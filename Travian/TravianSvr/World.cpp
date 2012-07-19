/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup world
*/
#include "preCompile.h"
#include "Common.h"
#include "Opcodes.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "World.h"

volatile bool World::m_stopEvent = false;

/// World constructor
World::World()
{
	m_gameTime=time(NULL);
	m_startTime=m_gameTime;
}

/// World destructor
World::~World()
{
    ///- Empty the kicked session set
    while (!m_sessions.empty())
    {
        // not remove from queue, prevent loading new sessions
        delete m_sessions.begin()->second;
        m_sessions.erase(m_sessions.begin());
    }
}

/// Find a session by its id
WorldSession* World::FindSession(uint32 id) const
{
    SessionMap::const_iterator itr = m_sessions.find(id);

    if(itr != m_sessions.end())
        return itr->second;                                 // also can return NULL for kicked session
    else
        return NULL;
}

/// Remove a given session
bool World::RemoveSession(uint32 id)
{
    ///- Find the session, kick the user, but we can't delete session at this moment to prevent iterator invalidation
    SessionMap::const_iterator itr = m_sessions.find(id);

    if(itr != m_sessions.end() && itr->second)
    {
        itr->second->KickPlayer();
    }

    return true;
}

void World::AddSession(WorldSession* s)
{
    addSessQueue.add(s);
}

void
World::AddSession_ (WorldSession* s)
{
    //NOTE - Still there is race condition in WorldSession* being used in the Sockets

    ///- kick already loaded player with same account (if any) and remove session
    ///- if player is in loading and want to load again, return
    if (!RemoveSession (s->GetAccountId ()))
    {
        s->KickPlayer ();
        delete s;                                           // session not added yet in session list, so not listed in queue
        return;
    }

    // if session already exist, prepare to it deleting at next world update
    // NOTE - KickPlayer() should be called on "old" in RemoveSession()
    {
        SessionMap::const_iterator old = m_sessions.find(s->GetAccountId ());

        if(old != m_sessions.end())
        {
            delete old->second;
        }
    }

    m_sessions[s->GetAccountId ()] = s;
}

/// Kick (and save) all players
void World::KickAll()
{
	// session not removed at kick and will removed in next update tick
	for (SessionMap::const_iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
		itr->second->KickPlayer();
}

/// Update the World !
void World::Update(uint32 diff)
{
    /// <li> Handle session updates when the timer has passed
	///- Update the different timers
	for(int i = 0; i < WUPDATE_COUNT; ++i)
	{
		if (m_timers[i].GetCurrent()>=0)
			m_timers[i].Update(diff);
		else
			m_timers[i].SetCurrent(0);
	}

	if (m_timers[WUPDATE_VILLAGE_PRODUCE].Passed())
	{
		m_timers[WUPDATE_VILLAGE_PRODUCE].Reset();
	}

	if (m_timers[WUPDATE_SESSIONS].Passed())
	{
		m_timers[WUPDATE_SESSIONS].Reset();
		UpdateSessions(diff);
	}
}

void World::UpdateSessions( uint32 diff )
{
	///- Add new sessions
	WorldSession* sess;
	while(addSessQueue.next(sess))
		AddSession_ (sess);

	///- Then send an update signal to remaining ones
	for (SessionMap::iterator itr = m_sessions.begin(), next; itr != m_sessions.end(); itr = next)
	{
		next = itr;
		++next;
		///- and remove not active sessions from the list
		if(!itr->second->Update(diff))                      // As interval = 0
		{
			delete itr->second;
			m_sessions.erase(itr);
		}
	}
}
/// Initialize the World
void World::SetInitialWorldSettings()
{
	///- Initialize the random number generator
	srand((unsigned int)time(NULL));

	m_timers[WUPDATE_SESSIONS].SetInterval(0);
	m_timers[WUPDATE_VILLAGE_PRODUCE].SetInterval(1*IN_MILLISECONDS);
}

World*
World::Instance ()
{
	return ACE_Singleton<World,ACE_Thread_Mutex>::instance();
}

