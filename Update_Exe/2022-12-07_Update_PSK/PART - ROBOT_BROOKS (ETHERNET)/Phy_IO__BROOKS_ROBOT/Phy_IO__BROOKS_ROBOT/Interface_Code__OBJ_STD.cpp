#include "StdAfx.h"
#include "Interface_Code.h"



//----------------------------------------------------------
DECLARE_START__DLL_STD_OBJ__GET_VERSION

#ifdef _DEBUG
debug_mode =  1;
#else
debug_mode = -1;			
#endif

DECLARE_END__DLL_STD_OBJ__GET_VERSION
//----------------------------------------------------------


//----------------------------------------------------------
#define CLS__AtmRobot_STD				"AtmRobot.STD"


DECLARE_START__DLL_STD_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__AtmRobot_STD);

DECLARE_END__DLL_STD_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_STD_OBJ__CREATE_LINK

// IF__OBJ_CLS(CLS__AtmRobot_STD)			return (new CObj__AtmRobot_STD);

DECLARE_END__DLL_STD_OBJ__CREATE_LINK
