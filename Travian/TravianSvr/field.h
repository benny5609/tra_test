/*******************************************************************************
* File Name:   field.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/7/4  Wednesday  13:28:22
* Comments:  
*
********************************************************************************/

#ifndef __FIELD_H__
#define __FIELD_H__
#include "common.h"

#define I64FMTD "%I64u"

class Field
{
public:

	void SetValue(char* value) { mValue = value; }

	const char* GetString() { return mValue; }
	std::string GetCppString() const
	{
		return mValue ? mValue : "";                    // std::string s = 0 have undefine result in C++
	}
	float GetFloat() { return mValue ? static_cast<float>(atof(mValue)) : 0; }
	bool GetBool() { return mValue ? atoi(mValue) > 0 : false; }
	uint8 GetUInt8() { return mValue ? static_cast<uint8>(atol(mValue)) : 0; }
	int8 GetInt8() { return mValue ? static_cast<int8>(atol(mValue)) : 0; }
	uint16 GetUInt16() { return mValue ? static_cast<uint16>(atol(mValue)) : 0; }
	int16 GetInt16() { return mValue ? static_cast<int16>(atol(mValue)) : 0; }
	uint32 GetUInt32() { return mValue ? static_cast<uint32>(atol(mValue)) : 0; }
	int32 GetInt32() { return mValue ? static_cast<int32>(atol(mValue)) : 0; }
	uint64 GetUInt64()
	{
		if(mValue)
		{
			uint64 value;
#ifndef WIN32	// Make GCC happy.
			sscanf(mValue, I64FMTD, (long long unsigned int*)&value);
#else
			sscanf(mValue, I64FMTD, &value);
#endif
			return value;
		}
		else
			return 0;
	}

private:
	char* mValue;
};

#endif  // end of guard field.h
