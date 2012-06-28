/*******************************************************************************
* File Name:   tra_enum.h
* Version:   1.0.1.0
* Author:    benny.liang (benny1315@163.com)
* Created:   2012/6/27  Wednesday  16:50:25
* Comments:  
*
********************************************************************************/

#ifndef __TRA_ENUM_H__
#define __TRA_ENUM_H__

enum E_TRIBE{
	Roman =0,
	Teuton = 1,
	Gaul = 2,
};

enum E_LOCATE{
	 North_West = 0,
	 North_East = 1,
	 South_West= 2,
	 South_East = 3,
};

enum E_ACTIVE{
	Register = 0,
	Active = 1,
	Deleting = 2,
	Deleted =3
};

enum E_RESOURCE{
	Wood =0,
	Clay = 1,
	Iron = 2,
	Crop = 3
};
#endif  // end of guard tra_enum.h
