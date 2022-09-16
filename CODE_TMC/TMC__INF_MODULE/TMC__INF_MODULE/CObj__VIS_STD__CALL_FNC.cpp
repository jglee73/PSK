#include "StdAfx.h"
#include "CObj__VIS_STD.h"


//----------------------------------------------------------------------------------------------------
int  CObj__VIS_STD::Call__INIT(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("INIT");
}

//
int  CObj__VIS_STD::Call__PRO_READY(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PRO_READY");
}
int  CObj__VIS_STD::Call__PRO_START(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PRO_START");
}

int  CObj__VIS_STD::Call__PLACE_READY(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PLACE_READY");
}
int  CObj__VIS_STD::Call__PLACE_COMPLETE(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PLACE_COMPLETE");
}

int  CObj__VIS_STD::Call__PICK_READY(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PICK_READY");
}
int  CObj__VIS_STD::Call__PICK_COMPLETE(CII_OBJECT__VARIABLE* p_variable)
{
	return pVIS__OBJ_CTRL->Call__OBJECT("PICK_COMPLETE");
}
