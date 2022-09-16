#include "StdAfx.h"
#include "Interface_Code.h"

#include "CObj__HEATER_MDx_LINK.h"
#include "CObj__MINI8_IO.h"



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
#define CLS__HEATER_MDx_LINK						"HEATER.MDx_LINK"
#define CLS__MINI8_IO								"MINI8.IO"


DECLARE_START__DLL_STD_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__HEATER_MDx_LINK);
ADD__OBJ_CLS(CLS__MINI8_IO);

DECLARE_END__DLL_STD_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_STD_OBJ__CREATE_LINK

IF__OBJ_CLS(CLS__HEATER_MDx_LINK)					return (new CObj__HEATER_MDx_LINK);
IF__OBJ_CLS(CLS__MINI8_IO)							return (new CObj__MINI8_IO);

DECLARE_END__DLL_STD_OBJ__CREATE_LINK

