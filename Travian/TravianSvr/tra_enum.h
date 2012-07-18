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

//data fields
enum E_VillageFields{
	VIL_FIELD_OWNER,
	VIL_FIELD_CAPITAL,
	VIL_FIELD_POP ,
	VIL_FIELD_CP,
	VIL_FIELD_CELEBRATION,
	VIL_FIELD_TYPE,
	VIL_FIELD_WOOD,
	VIL_FIELD_CLAY,
	VIL_FIELD_IRON,
	VIL_FIELD_CROP,
	VIL_FIELD_WOOD_HOUR,
	VIL_FIELD_CLAY_HOUR,
	VIL_FIELD_IRON_HOUR,
	VIL_FIELD_CROP_HOUR,
	VIL_FIELD_MAXSTORE,
	VIL_FIELD_MAXCROP,
	VIL_FIELD_LOYALTY,
	VIL_FIELD_END,
};

enum E_UpdateType{
	UPDATE_TYPE_VILLAGE,
};
#endif  // end of guard tra_enum.h
