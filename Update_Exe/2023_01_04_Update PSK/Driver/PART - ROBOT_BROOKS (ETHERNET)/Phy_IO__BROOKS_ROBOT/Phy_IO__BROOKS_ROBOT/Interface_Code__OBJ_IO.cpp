#include "StdAfx.h"
#include "Interface_Code.h"

#include "CObj__AtmRobot_FUSION.h"
#include "CObj__Driver_FUSION.h"
#include "CObj__VacRobot_WAVEII.h"
#include "CObj__VacRobot_PSK.h"



//----------------------------------------------------------
DECLARE_START__DLL_IO_OBJ__GET_VERSION

#ifdef _DEBUG
debug_mode =  1;
#else
debug_mode = -1;			
#endif

DECLARE_END__DLL_IO_OBJ__GET_VERSION
//----------------------------------------------------------


//----------------------------------------------------------
#define CLS__AtmRobot_FUSION				"AtmRobot.FUSION"
#define CLS__Driver_FUSION					"Driver.FUSION"
#define CLS__VacRobot_WAVEII				"VacRobot.WAVEII"
#define CLS__VacRobot_PSK   				"VacRobot.PSK"


DECLARE_START__DLL_IO_OBJ__GET_CLASS_LIST

ADD__OBJ_CLS(CLS__AtmRobot_FUSION);
ADD__OBJ_CLS(CLS__Driver_FUSION);
ADD__OBJ_CLS(CLS__VacRobot_WAVEII);
ADD__OBJ_CLS(CLS__VacRobot_PSK);

DECLARE_END__DLL_IO_OBJ__GET_CLASS_LIST


DECLARE_START__DLL_IO_OBJ__CREATE_LINK

IF__OBJ_CLS(CLS__AtmRobot_FUSION)			return (new CObj__AtmRobot_FUSION);
IF__OBJ_CLS(CLS__Driver_FUSION)				return (new CObj__Driver_FUSION);
IF__OBJ_CLS(CLS__VacRobot_WAVEII)			return (new CObj__VacRobot_WAVEII);
IF__OBJ_CLS(CLS__VacRobot_PSK)				return (new CObj__VacRobot_PSK);

DECLARE_END__DLL_IO_OBJ__CREATE_LINK
