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
#include <map>
#include <algorithm>

#include <ace/Basic_Types.h>
#include <ace/Default_Constants.h>
#include <ace/OS_NS_dlfcn.h>
#include <ace/ACE_export.h>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/message.h>

#include <unordered_map>
#define UNORDERED_MAP std::tr1::unordered_map

typedef signed __int64 int64;
typedef signed __int32 int32;
typedef signed __int16 int16;
typedef signed __int8 int8;

typedef unsigned __int64 uint64;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;
typedef unsigned __int8 uint8;

#include "tra_enum.h"
#include "sharedDefines.h"

#endif  // end of guard common.h
