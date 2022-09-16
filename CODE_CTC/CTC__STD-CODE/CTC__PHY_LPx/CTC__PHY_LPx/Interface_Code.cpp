#include "StdAfx.h"
#include "Interface_Code.h"

#include "CObj_Phy__LPx_STD.h"


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
#define CLS__LPx_STD						"LPx.STD"


DECLARE_START__DLL_STD_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__LPx_STD);

DECLARE_END__DLL_STD_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_STD_OBJ__CREATE_LINK

IF__OBJ_CLS(CLS__LPx_STD)				return (new CObj_Phy__LPx_STD);

DECLARE_END__DLL_STD_OBJ__CREATE_LINK
