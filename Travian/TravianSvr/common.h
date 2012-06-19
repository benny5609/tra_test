/*******************************************************************************
* File Name:   common.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/6/19  Tuesday  14:43:39
* Comments:  
*
********************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

#include <sys/types.h>
#include <list>
#include <string>
#include <iostream>
#include <vector>

#include <ace/Basic_Types.h>
#include <ace/Default_Constants.h>
#include <ace/OS_NS_dlfcn.h>
#include <ace/ACE_export.h>

#include <unordered_map>
#define UNORDERED_MAP std::tr1::unordered_map

typedef ACE_INT64 int64;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;
typedef ACE_INT32 int32;
typedef ACE_UINT32 uint32;

#endif  // end of guard common.h
