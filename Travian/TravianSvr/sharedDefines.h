/*******************************************************************************
* File Name:   sharedDefines.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/9  Monday  16:11:50
* Comments:  
*
********************************************************************************/

#ifndef __SHAREDDEFINES_H__
#define __SHAREDDEFINES_H__

enum ResponseCodes
{
	AUTH_BAD_SERVER_PROOF,      
	AUTH_UNAVAILABLE,       
	AUTH_SYSTEM_ERROR,   
	AUTH_BILLING_ERROR,
	AUTH_BILLING_EXPIRED,
	AUTH_VERSION_MISMATCH,
	AUTH_UNKNOWN_ACCOUNT,
	AUTH_INCORRECT_PASSWORD,      
	AUTH_SESSION_EXPIRED,              
	AUTH_SERVER_SHUTTING_DOWN , 
	AUTH_ALREADY_LOGGING_IN,    
	AUTH_LOGIN_SERVER_NOT_FOUND,
	AUTH_WAIT_QUEUE,                     
	AUTH_BANNED,                           
	AUTH_ALREADY_ONLINE,               
	AUTH_NO_TIME,                           
	AUTH_DB_BUSY,                           
	AUTH_SUSPENDED,                       
	AUTH_PARENTAL_CONTROL,           
	AUTH_LOCKED_ENFORCED, 
};
#endif  // end of guard sharedDefines.h
