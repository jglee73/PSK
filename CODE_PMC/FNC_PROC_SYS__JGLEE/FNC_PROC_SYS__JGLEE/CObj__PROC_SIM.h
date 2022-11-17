#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_System.h"
#include "CCommon_LEARNED_ITEM.h"


class CObj__PROC_SIM : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString sObject_Name;

	// ...
	SCX__USER_LOG_CTRL xI_LOG_CTRL;

	CDS__LEARNED_ITEM_CTRL mCTRL__LEARNED_ITEM;

	// ...
	int iActive__PROC_START;
	CUIntArray iLIST_ALID__PART;

	// ...
	SCX__RECIPE_FILE xRCP__FILE_CTRL;
	CString sDir_PROC;

	int iActive__SIM_MODE;
	//


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL	 sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL	 sCH__OBJ_TIMER;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_DA_OFFSET_CHECK_BEFORE_PROCESSING;

	// CTC REPORT ...
	CX__VAR_STRING_CTRL  sCH__PRC_TOTAL_TIME_TO_CTC;
	CX__VAR_STRING_CTRL  sCH__PRC_CHANGE_TIME_TO_CTC;

	// PARA ...
	CX__VAR_DIGITAL_CTRL dCH__PARA_MANUAL_PROCESS_DECHUCK_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__PARA_MANUAL_STEP_CTRL_ACTIVE;
	CX__VAR_STRING_CTRL  sCH__PARA_MANUAL_STEP_CTRL_REQ;

	CX__VAR_STRING_CTRL  sCH__ACT_RECOVERY_RESTART_FLAG;

	// LEARNED INFO ... 
	CX__VAR_DIGITAL_CTRL dCH__CFG_LEARNED_APPLY_MODE;
	CX__VAR_STRING_CTRL  sCH__CUR_LEARNED_RESULT;

	CX__VAR_STRING_CTRL  sCH__PRE_LOTID;
	CX__VAR_STRING_CTRL  sCH__CUR_LEARNED_APPLY_STATUS;

	CX__VAR_STRING_CTRL  sCH__RCP_FILE_UPLOAD_FLAG;

	// WIN.JUMP_STEP ...
	CX__VAR_ANALOG_CTRL  aCH__JUMP_STEP_ID;
	CX__VAR_ANALOG_CTRL  aCH__CONTINUE_OVER_STEP_TIME;
	CX__VAR_STRING_CTRL  sCH__EXCEPTION_CONTINUE_REQ;

	CX__VAR_STRING_CTRL  sCH__WIN_CTRL_JUMP_PAGE;
	CX__VAR_STRING_CTRL  sCH__WIN_CTRL_MSG;

	CX__VAR_DIGITAL_CTRL dCH__WIN_CTRL_LOCK_ACTIVE_JUMP;
	CX__VAR_DIGITAL_CTRL dCH__WIN_CTRL_LOCK_ACTIVE_CONTINUE;
	CX__VAR_DIGITAL_CTRL dCH__WIN_CTRL_LOCK_ACTIVE_ABORT;

	// MON.PART ...
	CX__VAR_DIGITAL_CTRL dCH__MON_PART_ERROR_ACTIVE;

	// MON ...
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_ABORT;
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_END;
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_SKIP;
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_JUMP;
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_PAUSE;
	CX__VAR_DIGITAL_CTRL dCH__MON_LOCK_ACTIVE_RESUME;

	CX__VAR_DIGITAL_CTRL dCH__MON_EXCEPTION_ACT;
	CX__VAR_STRING_CTRL  sCH__MON_EXCEPTION_MSG;

	// MON.WAFER_INFO ...
	CX__VAR_STRING_CTRL  sCH__MON_WAFER_INFO_TOTAL_COUNT_START_DATE;
	CX__VAR_ANALOG_CTRL  aCH__MON_WAFER_INFO_TOTAL_COUNT_VALUE;
	CX__VAR_DIGITAL_CTRL dCH__MON_WAFER_INFO_TOTAL_COUNT_RESET;

	CX__VAR_STRING_CTRL  sCH__MON_WAFER_INFO_CURRENT_COUNT_START_DATE;
	CX__VAR_ANALOG_CTRL  aCH__MON_WAFER_INFO_CURRENT_COUNT_VALUE;
	CX__VAR_DIGITAL_CTRL dCH__MON_WAFER_INFO_CURRENT_COUNT_RESET;

	// CUR ...
	CX__VAR_STRING_CTRL  sCH__CUR_RCP_FILE_PATH;
	CX__VAR_DIGITAL_CTRL dCH__CUR_PROCESS_TYPE;

	// Loop Parameter ...
	bool bACTIVE__LOOP_STEP;

	int iLOOP__STEP_START;
	int iLOOP__STEP_END;
	int iLOOP__STEP_REPEAT;
	int iLOOP__STEP_COUNT;

	// Recipe Info ...
	CX__VAR_STRING_CTRL  sCH__PRC_TOTAL_TIME;
	CX__VAR_STRING_CTRL  sCH__PRC_CUR_TIME;
	CX__VAR_STRING_CTRL  sCH__STEP_CUR_TIME;
	CX__VAR_ANALOG_CTRL  aCH__STEP_TOTAL_NUM;
	CX__VAR_ANALOG_CTRL  aCH__STEP_CUR_NUM;
	CX__VAR_STRING_CTRL  sCH__STEP_LOOP_MSG;

	CX__VAR_ANALOG_CTRL  aCH__RCP_JUMP_STEP_ID;

	// Recipe Parameter ...
	CX__VAR_DIGITAL_CTRL dCH__RCP_STEP_MODE;

	CX__VAR_ANALOG_CTRL  aCH__RCP_LOOP_START;
	CX__VAR_ANALOG_CTRL  aCH__RCP_LOOP_REPEAT;
	//

	//-------------------------------------------------------------------------
	// ...
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__PRE_READY;
	int  Call__PRE_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PRE_START;
	int  Call__PRE_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__MAIN_READY;
	int Call__MAIN_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__MAIN_START;
	int Call__MAIN_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__POST_READY;
	int Call__POST_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__POST_START;
	int Call__POST_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__MANUAL_READY;
	int Call__MANUAL_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__MANUAL_START;
	int Call__MANUAL_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__JOB_STRT_READY;
	int Call__JOB_START_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__JOB_END_READY;
	int Call__JOB_END_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	//

public:
	CObj__PROC_SIM();
	~CObj__PROC_SIM();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
