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
	CMSG_AUTH_SESSION								= 0x050,
	CMSG_PLAYER_LOGIN								= 0x051,
	NUM_MSG_TYPES	
};
#endif  // end of guard Opcodes.h
