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

/// \addtogroup world The World
/// @{
/// \file

#ifndef __WORLD_H
#define __WORLD_H

#include "Common.h"
#include "ace/Atomic_Op.h"
#include "LockedQueue.h"
#include <map>
#include <set>
#include <list>
#include "timer.h"
#include "tra_village.h"
class WorldPacket;
class WorldSession;

/// The World
class World
{
    public:
		static volatile bool m_stopEvent;
		typedef UNORDERED_MAP<uint32, WorldSession*> SessionMap;
		typedef UNORDERED_MAP<uint32, Village*> VillageMap;
		SessionMap m_sessions;
		VillageMap m_vilMap;
        World();
        ~World();
		void SetInitialWorldSettings();

        WorldSession* FindSession(uint32 id) const;
        void AddSession(WorldSession *s);
        bool RemoveSession(uint32 id);

		Village* FindVillage(uint32 id) ;
		bool AddVillage(Village *s);
		bool RemoveVillage(uint32 id);
     
		void AddUpdateVillage(uint32 id);
		void KickAll();
        static void StopNow(uint8 exitcode) { m_stopEvent = true; }
        static bool IsStopped() { return m_stopEvent; }

        void Update(uint32 diff);
        void UpdateSessions( uint32 diff );
		void UpdateVillages( uint32 diff );
		static World* Instance ();

        //sessions that are added async
        void AddSession_(WorldSession* s);
        ACE_Based::LockedQueue<WorldSession*, ACE_Thread_Mutex> addSessQueue;
		ACE_Based::LockedQueue<uint32, ACE_Thread_Mutex> updateVilQueue;

protected:
	time_t m_startTime;
	time_t m_gameTime;
	IntervalTimer m_timers[WUPDATE_COUNT];
	ACE_Thread_Mutex mMutex;

};
#define sWorld World::Instance ()
#endif
/// @}
