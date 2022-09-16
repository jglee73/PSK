#include "StdAfx.h"
#include "Interface_Code.h"

#include "CObj__LPx_STD.h"
#include "CObj__LPx_SYS.h"


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
#define CLS__LPx_STD					"LPx.STD"
#define CLS__LPx_SYS					"LPx.SYS"


DECLARE_START__DLL_STD_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__LPx_STD);
ADD__OBJ_CLS(CLS__LPx_SYS);

DECLARE_END__DLL_STD_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_STD_OBJ__CREATE_LINK

IF__OBJ_CLS(CLS__LPx_STD)				return (new CObj__LPx_STD);
IF__OBJ_CLS(CLS__LPx_SYS)				return (new CObj__LPx_SYS);

DECLARE_END__DLL_STD_OBJ__CREATE_LINK
