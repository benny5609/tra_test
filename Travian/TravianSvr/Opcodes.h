/*******************************************************************************
* File Name:   Opcodes.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/6/19  Tuesday  14:47:59
* Comments:  
*
********************************************************************************/

#ifndef __OPCODES_H__
#define __OPCODES_H__

enum Opcodes
{
	MSG_NULL_ACTION                                 = 0x000,
	SMSG_AUTH_CHALLENGE							= 0x049,
	CMSG_AUTH_SESSION								= 0x050,
	SMSG_AUTH_RESPONSE							= 0x051,
	CMSG_PLAYER_LOGIN								= 0x052,
	SMSG_LOAD_VILLAGES								= 0x053,
	SMSG_UPDATE_OBJECT							= 0x054,

	NUM_MSG_TYPES	
};
#endif  // end of guard Opcodes.h
