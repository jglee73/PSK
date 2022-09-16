#include "StdAfx.h"
#include "Interface_Code.h"

#include "CObj_Phy__ALx_STD.h"
#include "CObj_Phy__LBx_STD.h"
#include "CObj_Phy__VIS_STD.h"

#include "CObj_Phy__CHM_STD.h"
#include "CObj_Phy__SYS_STD.h"


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
#define CLS__ALx_STD				"ALx.STD"
#define CLS__LBx_STD				"LBx.STD"
#define CLS__VIS_STD				"VIS.STD"

#define CLS__CHM_STD				"CHM.STD"
#define CLS__SYS_STD				"SYS.STD"


DECLARE_START__DLL_STD_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__ALx_STD);
ADD__OBJ_CLS(CLS__LBx_STD);
ADD__OBJ_CLS(CLS__VIS_STD);

ADD__OBJ_CLS(CLS__CHM_STD);
ADD__OBJ_CLS(CLS__SYS_STD);

DECLARE_END__DLL_STD_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_STD_OBJ__CREATE_LINK

IF__OBJ_CLS(CLS__ALx_STD)				return (new CObj_Phy__ALx_STD);
IF__OBJ_CLS(CLS__LBx_STD)				return (new CObj_Phy__LBx_STD);
IF__OBJ_CLS(CLS__VIS_STD)				return (new CObj_Phy__VIS_STD);

IF__OBJ_CLS(CLS__CHM_STD)				return (new CObj_Phy__CHM_STD);
IF__OBJ_CLS(CLS__SYS_STD)				return (new CObj_Phy__SYS_STD);

DECLARE_END__DLL_STD_OBJ__CREATE_LINK
