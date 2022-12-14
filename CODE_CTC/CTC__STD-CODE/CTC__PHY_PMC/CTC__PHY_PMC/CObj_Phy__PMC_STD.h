#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CObj_Phy__PMC_STD__DEF.h"


#define  CFG__PMx_MAX_SLOT							5
#define  CFG__LPx_SIZE								5


class CObj_Phy__PMC_STD : public __IOBJ__STD_TYPE
{
private:
	//-----------------------------------------------------------
	CString sObject_Name;

	CCommon_Error__DEF_VARIABLE mERROR__DEF_VAR;
	CCommon_Error__MODULE_OBJ   mERROR__MODULE_OBJ;

	// ...
	int iSIM_MODE;
	int iSIM__PMC_DUMMY_MODE;

	// ...
	SCI__THREAD_SYNC_CTRL xI_Sync_Ctrl;
	int iPRC_STS;
	int iFNC_STS;

	CString sDir_ROOT;

	// ...
	int iPRC_ALARM_FLAG;

	SCX__CTC__MODULE_OBJ xI_Module_Obj;
	SCX__CTC__SCH_MATERIAL_CTRL xSCH_MATERIAL_CTRL;
	
	SCX__LCD_DB_CTRL  xI_LCD_DB_CTRL;
	SCX__LOT_LOG_CTRL xI_LOT_LOG_CTRL;

	SCX__USER_LOG_CTRL xLOG_CTRL;
	//	
	
	
	//-----------------------------------------------------------
	// INTERNAL PROPERTY

	//  MODULE CTRL & MODE
	CX__VAR_DIGITAL_CTRL xEXT_CH__MODULE_OBJ_CTRL;
	CX__VAR_DIGITAL_CTRL xEXT_CH__MODULE_OBJ_MODE;

	//  CONTROL 
	CX__VAR_DIGITAL_CTRL xCH__OBJ_CTRL;
	CString dVAR__MODE;

	//  STATUS 
	CX__VAR_STRING_CTRL  xCH__OBJ_VIRTUAL_STATUS;
	CX__VAR_STRING_CTRL  xCH__OBJ_VIRTUAL_STAGE1_STATUS;
	CX__VAR_STRING_CTRL  xCH__OBJ_VIRTUAL_STAGE2_STATUS;

	CX__VAR_DIGITAL_CTRL xCH__OBJ_STATUS;
	CX__VAR_STRING_CTRL  xCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  xCH__OBJ_FNC_MSG;
	
	CX__VAR_STRING_CTRL  xCH__PMC_PROC_READY_FLAG;

	bool bActive__Init_Act;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_INIT_STATE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_SLIT_VALVE_CLOSE_CHECK;

	// PMC REQUEST ...
	CX__VAR_STRING_CTRL  sCH__WAFER_STATUS_CONVERTED_TO_PROCESSED_BY_PMC_REQ_COUNT;

	//
	CX__VAR_DIGITAL_CTRL dCH__SLIT_VLV_STS;
	CX__VAR_STRING_CTRL  sCH__LIFT_PIN_STS;
	CX__VAR_STRING_CTRL  sCH__CHUCK_STS;
	CX__VAR_DIGITAL_CTRL dCH__PRC_STS;
	CX__VAR_STRING_CTRL  sCH__VAC_SNS;

	CX__VAR_STRING_CTRL  sCH__RF_ON_STS;
	CX__VAR_STRING_CTRL  sCH__WAP_CUR_POS_STS;

	//
	CX__VAR_DIGITAL_CTRL xCH__MOVE_FLAG;
	CX__VAR_STRING_CTRL  xCH__X_PICK_FLAG;
	CX__VAR_STRING_CTRL  xCH__X_PLACE_FLAG;
	CX__VAR_STRING_CTRL  xCH__JOB_READY_FLAG;

	CX__VAR_ANALOG_CTRL  xCH__SLOT_NO;

	CX__VAR_STRING_CTRL  xCH__PRESSURE_VALUE;
	CX__VAR_DIGITAL_CTRL xCH__PRESSURE_STATUS;
	
	//
	CX__VAR_STRING_CTRL  sCH__MODULE_TIME;

	//
	CX__VAR_STRING_CTRL  sCH__TIME_ACT_START;
	CX__VAR_STRING_CTRL  sCH__TIME_ACT_END;
	CX__VAR_STRING_CTRL  sCH__TIME_ACT_TACK;
	CX__VAR_STRING_CTRL  sCH__TIME_ACT_RESULT;

	//
	CX__VAR_STRING_CTRL  xCH__LOG_SUB_DIRECTORY;
	CX__VAR_STRING_CTRL  xCH__LOG_FILE_NAME;
	
	CX__VAR_STRING_CTRL  xCH__WFR_LOG_INFO;

	CX__VAR_STRING_CTRL  xCH__SLOT_LOG_SUB_DIRECTORY[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_LOG_FILE_NAME[CFG__PMx_MAX_SLOT];

	//
	CX__VAR_STRING_CTRL  sCH__FDC_CHM_ID;
	CX__VAR_STRING_CTRL  xCH__FDC_RECIPE;
	CX__VAR_STRING_CTRL  xCH__FDC_CLN_RECIPE;
	CX__VAR_STRING_CTRL  xCH__FDC_PRE_RECIPE;
	CX__VAR_STRING_CTRL  xCH__FDC_LOTID;

	//
	CX__VAR_STRING_CTRL  xCH__CJOBID;
	CX__VAR_STRING_CTRL  xCH__PJOBID;
	CX__VAR_STRING_CTRL  xCH__RECIPE;
	CX__VAR_STRING_CTRL  xCH__LOTID;
	CX__VAR_STRING_CTRL  xCH__MATERIAL_ID;
	CX__VAR_STRING_CTRL  xCH__MATERIAL_SIZE;
	CX__VAR_STRING_CTRL  xCH__LPx_CID;
	CX__VAR_STRING_CTRL  xCH__LPx_PORT_ID;
	CX__VAR_STRING_CTRL  xCH__LPx_SLOT_ID;

	CX__VAR_STRING_CTRL  xCH_PRE__LOTID;
	CX__VAR_STRING_CTRL  xCH_PRE__MATERIAL_ID;
	CX__VAR_STRING_CTRL  xCH_PRE__LPx_PORT_ID;
	CX__VAR_STRING_CTRL  xCH_PRE__LPx_SLOT_ID;
	CX__VAR_STRING_CTRL  xCH_PRE__LPx_CID;

	//
	CX__VAR_STRING_CTRL  sCH__PMC_SEND_APC_APPLY;
	CX__VAR_STRING_CTRL  sCH__PMC_SEND_APC_DATA;

	//
	CX__VAR_STRING_CTRL  xCH__SLOT_RECIPE[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_LOTID[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_MATERIALID[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_LPx_CID[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_LPx_PORT_ID[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_LPx_SLOT_ID[CFG__PMx_MAX_SLOT];

	//
	CX__VAR_STRING_CTRL  xCH__PROCESS_FLAG;
	CX__VAR_STRING_CTRL  xCH__TOTAL_PRC_TIME;
	CX__VAR_STRING_CTRL  xCH__CHANGE_PRC_TIME;
	CX__VAR_STRING_CTRL  xCH__CURRENT_PRC_TIME;
	CX__VAR_STRING_CTRL  xCH__PROCESS_ASYNC_TIME;
	CX__VAR_STRING_CTRL  xCH__PROCESS_PERCENT;
	CX__VAR_STRING_CTRL  xCH__PROCESS_STATUS;

	CX__VAR_ANALOG_CTRL  xCH__PRC_TIME_COUNT;

	//
	CX__VAR_STRING_CTRL  xCH__SVID_SLOT_DATA;

	//
	CX__VAR_DIGITAL_CTRL xCH__SLOT_STATUS[CFG__PMx_MAX_SLOT];
	CX__VAR_STRING_CTRL  xCH__SLOT_TITLE[CFG__PMx_MAX_SLOT];

	CX__VAR_STRING_CTRL  xCH__ACC_MATERIAL_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__ACC_PROCESSED_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__ACC_ABORTED_COUNT;

	CX__VAR_ANALOG_CTRL  xCH__RCP_PAS__MATERIAL_COUNT;
	CX__VAR_ANALOG_CTRL  xCH__RCP_NP__MATERIAL_COUNT;
	CX__VAR_ANALOG_CTRL  xCH__RCP_ACT__MATERIAL_COUNT;
	CX__VAR_ANALOG_CTRL  xCH__RCP_OTHER__MATERIAL_COUNT;
	CX__VAR_ANALOG_CTRL  xCH__RCP_TOTAL__MATERIAL_COUNT;

	//
	CX__VAR_STRING_CTRL  xCH__UTILITY_CFG_TO_CSV_REQ;

	// ...
	CX__VAR_DIGITAL_CTRL xCH_CFG__PMC_USE;
	CX__VAR_DIGITAL_CTRL xCH__PROCESS_TYPE__BONDING_FLAG;

	//
	CX__VAR_STRING_CTRL  sCH_REQ__GOTO_MAINT;
	CX__VAR_DIGITAL_CTRL dCH_LINK_REQ__GOTO_MAINT;

	//
	CX__VAR_STRING_CTRL  xCH__NEXT_PROCESS;
	CX__VAR_STRING_CTRL  xCH__NEXT_PROCESS_REQ;
	CX__VAR_STRING_CTRL  xCH__NEXT_PROCESS_END_FLAG;
	CX__VAR_DIGITAL_CTRL xCH_CFG__AUTO_MATERIAL_COUNT_FLAG;

	//
	CX__VAR_STRING_CTRL  xCH_CFG__CLEAN_MODE;
	CX__VAR_DIGITAL_CTRL xCH_CFG__CLEAN_USE;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_FREQUENCY;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_COUNT;
	CX__VAR_STRING_CTRL  xCH_CFG__CLEAN_RECIPE;

	CX__VAR_STRING_CTRL  sCH_CUR__CLEAN_WAFER_COUNT;

	//
	CX__VAR_ANALOG_CTRL  xCH__SYSTEM_TOTAL_MATERIAL_COUNT;

	//
	CX__VAR_DIGITAL_CTRL xCH_CFG__DUMMY_CLEAN_USE;
	CX__VAR_STRING_CTRL  xCH_CFG__DUMMY_CLEAN_RECIPE;

	//
	CX__VAR_STRING_CTRL  xCH_CFG__DUMMY_PROC_RECIPE;
	CX__VAR_STRING_CTRL  xCH_CFG__DUMMY_CLN_RECIPE;
	CX__VAR_STRING_CTRL  xCH_CFG__DUMMY_PRE_RECIPE;

	//
	CX__VAR_ANALOG_CTRL  xCH__PMC_IDLE_TIME;
	CX__VAR_STRING_CTRL  xCH__PMC_FIRST_WAFER_FLAG;

	//
	CX__VAR_STRING_CTRL  xCH__PRC_PRE_RECIPE;

	//
	CX__VAR_STRING_CTRL  xCH__LAYER_CLEAN_RECIPE;
	CX__VAR_STRING_CTRL  xCH__POST_CLEAN_RECIPE;

	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_SYS_IDLE_REF_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_FIRST_COUNT;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_SECOND_COUNT;

	CX__VAR_DIGITAL_CTRL xCH_CFG__CLEAN_RF_USE;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_RF_REF_TIME;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CLEAN_RF_CUR_TIME;
	CX__VAR_STRING_CTRL  xCH_CFG__CLEAN_RF_RECIPE;

	// CTC LEAK_CHECK ...
	CX__VAR_ANALOG_CTRL  aCH_CFG__CTC_LEAK_CHECK_OVER_PUMPING_TIME;
	CX__VAR_ANALOG_CTRL  aCH_CFG__CTC_LEAK_CHECK_STABLE_TIME;
	CX__VAR_ANALOG_CTRL  aCH_CFG__CTC_LEAK_CHECK_TIME_MIN;

	CX__VAR_STRING_CTRL  sCH__CTC_LEAK_CHECK_MESSAGE;
	CX__VAR_STRING_CTRL  sCH__CTC_LEAK_CHECK_TIME_COUNT;

	// AUTO LEAK_CHECK ...
	CX__VAR_DIGITAL_CTRL xCH_CFG__AUTO_LEAK_CHECK_USE_MODE;
	CX__VAR_ANALOG_CTRL  xCH_CFG__AUTO_LEAK_CHECK_REF_TIME;
	CX__VAR_ANALOG_CTRL  xCH_CFG__AUTO_LEAK_CHECK_CUR_TIME;
	CX__VAR_DIGITAL_CTRL xCH_CFG__AUTO_LEAK_CHECK_MODE;

	CX__VAR_STRING_CTRL  xCH__AUTO_LEAK_CHECK_RUN_FLAG;
	CX__VAR_STRING_CTRL  xCH__AUTO_LEAK_CHECK_RUN_DATE;
	CX__VAR_STRING_CTRL  xCH__AUTO_LEAK_CHECK_RUN_DAY;
	CX__VAR_STRING_CTRL  xCH__AUTO_LEAK_CHECK_RUN_COMPLETE;

	// 
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_IDLE_REF_TIME;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK_IDLE_CUR_TIME;

	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_IDLE_REF_COUNT;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK_IDLE_CUR_COUNT;

	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK_IDLE_RUN_DATE;

	//
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_START_TIME_HOUR;
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_START_TIME_MINUTE;
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_START_TIME_SECOND;

	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_END_TIME_HOUR;
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_END_TIME_MINUTE;
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_END_TIME_SECOND;
	
	//
	CX__VAR_DIGITAL_CTRL xCH__LEAK_CHECK_WARNING_USE_MODE;
	CX__VAR_ANALOG_CTRL  xCH__LEAK_CHECK_WARNING_TIMEOUT;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK_WARNING_CUR_TIME;

	// AUTO_PMK ...
	CX__VAR_DIGITAL_CTRL xCH_CFG__AUTO_PM_USE_MODE;
	CX__VAR_ANALOG_CTRL  xCH_CFG__AUTO_PM_REF_TIME;
	CX__VAR_ANALOG_CTRL  xCH_CFG__AUTO_PM_CUR_TIME;
	CX__VAR_DIGITAL_CTRL xCH_CFG__AUTO_PM_MODE;

	CX__VAR_STRING_CTRL  xCH__AUTO_PM_RUN_FLAG;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_RUN_DATE;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_RUN_DAY;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_RUN_COMPLETE;

	// 
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_IDLE_REF_TIME;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_IDLE_CUR_TIME;

	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_IDLE_REF_COUNT;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_IDLE_CUR_COUNT;

	CX__VAR_STRING_CTRL  xCH__AUTO_PM_IDLE_RUN_DATE;

	//
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_START_TIME_HOUR;
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_START_TIME_MINUTE;
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_START_TIME_SECOND;

	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_END_TIME_HOUR;
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_END_TIME_MINUTE;
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_END_TIME_SECOND;

	//
	CX__VAR_DIGITAL_CTRL xCH__AUTO_PM_WARNING_USE_MODE;
	CX__VAR_ANALOG_CTRL  xCH__AUTO_PM_WARNING_TIMEOUT;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM_WARNING_CUR_TIME;

	// ...
	CX__VAR_STRING_CTRL  xCH__STEP_START;
	CX__VAR_STRING_CTRL  xCH__STEP_END;

	// ...
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__TOTAL_PROC_TIME;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__CUR_PROC_TIME;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__TOTAL_STEP_COUNT;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__CUR_STEP_COUNT;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__STEP_TOTAL_TIME;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__STEP_CUR_TIME;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__STEP_MSG;
	CX__VAR_STRING_CTRL  xCH__PROC_INFO__PROCESS_STATUS;

	// ...
	CX__VAR_STRING_CTRL  xCH__RMS_ID;
	CX__VAR_STRING_CTRL  xCH__RMS_ACT;
	CX__VAR_STRING_CTRL  xCH__RMS_FILE_TYPE;
	CX__VAR_STRING_CTRL  xCH__RMS_FILE_NAME;
	CX__VAR_STRING_CTRL  xCH__RMS_CREATE_TIME;
	CX__VAR_STRING_CTRL  xCH__RMS_UPDATE_TIME;

	// ...
	CX__VAR_STRING_CTRL  xCH__MATERIAL_CLEAR_REQ;
	CX__VAR_STRING_CTRL  xCH__MATERIAL_CLEAR_SLOT;

	CX__VAR_STRING_CTRL  xCH__LPx_WAFER_COUNT;
	CX__VAR_STRING_CTRL  xCH_CFG__LPx_WAFER_COUNT[CFG__LPx_SIZE];

	// ...
	CX__VAR_DIGITAL_CTRL xCH__CFG_2st_SLOT_EMPTY_CHECK;

	// ...
	CX__VAR_DIGITAL_CTRL xCH__ALARM_LOG_MODE;

	void Post__PMx_ALARM(CII_OBJECT__ALARM *p_alarm);
	void Clear__PMx_ALARM(CII_OBJECT__ALARM *p_alarm);


	// ...
	SCX__ASYNC_TIMER_CTRL xTIMER__SYS_IDLE;
	CX__VAR_ANALOG_CTRL  xCH__SYS_IDLE_TIME;

	// ...
	CX__VAR_STRING_CTRL  xCH__ECS_MODE;

	// ECS TRANSFER .....
	CX__VAR_STRING_CTRL  xCH_TRANSFER__ECS_PIO_FLAG;
	CX__VAR_STRING_CTRL  xCH_TRANSFER__CFG_USE_FLAG;
	CX__VAR_STRING_CTRL  xCH_TRANSFER__ECS_EXCHANGE_FLAG;
	CX__VAR_STRING_CTRL  xCH_TRANSFER__ECS_EXIT_FLAG;

	// EXCEPTION CTRL .....
	CX__VAR_STRING_CTRL  xCH__ABORT_LOCK_FLAG;
	CX__VAR_STRING_CTRL  xCH__END_LOCK_FLAG;
	CX__VAR_STRING_CTRL  xCH__SKIP_LOCK_FLAG;
	CX__VAR_STRING_CTRL  xCH__JUMP_LOCK_FLAG;

	CX__VAR_STRING_CTRL  xCH__EXCEPTION_ACT;
	CX__VAR_STRING_CTRL  xCH__EXCEPTION_MSG;

	CX__VAR_STRING_CTRL  xCH__APP_FLAG_ABORT_BY_USER;

	// DA OFFSET ...
	CX__VAR_STRING_CTRL  xCH__FDC_DA_RT_OFFSET;
	CX__VAR_STRING_CTRL  xCH__FDC_DA_R_OFFSET;
	CX__VAR_STRING_CTRL  xCH__FDC_DA_T_OFFSET;

	// JOB READY ...
	CX__VAR_STRING_CTRL  sCH__PRE_INFO_JOB_START_READY_PORTID;
	CX__VAR_STRING_CTRL  sCH__PRE_INFO_JOB_START_READY_JOBID;

	CX__VAR_STRING_CTRL  sCH__REQ_INFO_JOB_START_READY_PORTID;
	CX__VAR_STRING_CTRL  sCH__REQ_INFO_JOB_START_READY_JOBID;

	// ...
	CX__VAR_STRING_CTRL  sCH__PARA_TEMPLATE_FILE;
	//	

	//-----------------------------------------------------------
	// EXTERNAL PROPERTY

	SCX__MODULE_INFO xI__MODULE_INFO;
	
	int iLOG_ID;
	int iLOG_SLOT_MAX;
	int iSEQ_ID;
	int iPMx_ID;
	int iPMx_SLOT_MAX;

	// ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__SCH_TEST_CFG_PMC_DUMMY_BY_CTC;

	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_PROC_PRE_SEC;
	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_PROC_MAIN_SEC;
	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_PROC_POST_SEC;

	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_JOB_START_READY_SEC;
	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_JOB_END_READY_SEC;
	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_IDLE_START_SEC;

	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_LEAK_CHECK_SEC;
	CX__VAR_ANALOG_CTRL  aCH__SCH_TEST_CFG_PMC_AUTO_PM_SEC;

	//
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__PMC_USE;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__PMC_STAGE1_USE;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__PMC_STAGE2_USE;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__PMC_PROCESS_TYPE;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__PMC_SLOT_MAX;

	CX__VAR_ANALOG_CTRL  xEXT_CH_CFG__REF_ATM_PRESSURE;
	CX__VAR_ANALOG_CTRL  xEXT_CH_CFG__REF_VAC_PRESSURE;
	CX__VAR_DIGITAL_CTRL dEXT_CH_CFG__TRANSFER_MODE;

	// LEAK CHECK TIME  .....
	CX__VAR_STRING_CTRL  xEXT_CH__LEAK_CHECK__SCH_SEQUENCE_MODE__REQ_FLAG;
	CX__VAR_STRING_CTRL  xEXT_CH__LEAK_CHECK__IDLE_USE_FLAG;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__LEAK_CHECK__TIME_MODE;
	CX__VAR_STRING_CTRL  xEXT_CH__PMC_LEAK_CHECK_FLAG;

	// AUTO_PM ...
	CX__VAR_STRING_CTRL  xEXT_CH__AUTO_PM__SCH_SEQUENCE_MODE__REQ_FLAG;
	CX__VAR_STRING_CTRL  xEXT_CH__AUTO_PM__IDLE_USE_FLAG;
	CX__VAR_DIGITAL_CTRL xEXT_CH_CFG__AUTO_PM__TIME_MODE;
	CX__VAR_STRING_CTRL  xEXT_CH__PMC_AUTO_PM_FLAG;

	// MARATHON_TEST ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__ALL_PM_MARATHON_TEST_USE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__PM_ID_MARATHON_TEST_USE;
	CX__VAR_ANALOG_CTRL  aEXT_CH__PM_ID_MARATHON_TEST_WAIT_SEC;

	// ...
	CX__VAR_STRING_CTRL  xEXT_CH_CFG__PMC_MSG_WIN_CTRL;
	CX__VAR_STRING_CTRL  xEXT_CH_CFG__PMC_MSG_WIN_NAME;

	CX__VAR_STRING_CTRL  xEXT_CH__LPx_JOB_START_FLAG[CFG__LPx_SIZE];

	CX__VAR_DIGITAL_CTRL xEXT_CH__PMC_CONNECT_STATUS;
	
	// RMS SVID .....
	int iRMS_SVID__PP_CREATE;
	int iRMS_SVID__PP_UPDATE;
	int iRMS_SVID__PP_DELETE;
	//

	//-----------------------------------------------------------
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL;

	// ...
	CString sMODE__TIME_INIT;
	int  Call__TIME_INIT(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__SYSTEM_INIT;
	int  Call__SYSTEM_INIT(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__AUTO_INIT;
	int  Call__AUTO_INIT(CII_OBJECT__VARIABLE* p_variable);

	//.....
	CString sMODE__SYSTEM_MAINT;
	int  Call__SYSTEM_MAINT(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__PUMP;
	int  Call__PUMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__VENT;
	int  Call__VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__SLOT_OPEN;
	int  Call__SLOT_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__SLOT_CLOSE;
	int  Call__SLOT_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PIN_UP;
	int  Call__PIN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PIN_DOWN;
	int  Call__PIN_DOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PICK_READY;
	int  Call__PICK_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PICK_X_READY;
	int  Call__PICK_X_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Seq__PICK_X_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PICK_COMPLETE;
	int  Call__PICK_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PICK_X_COMPLETE;
	int  Call__PICK_X_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__PLACE_READY;
	int  Call__PLACE_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Seq__PLACE_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PLACE_X_READY;
	int  Call__PLACE_X_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PLACE_COMPLETE;
	int  Call__PLACE_COMPLETE(CII_OBJECT__VARIABLE* p_variable);
	int  Seq__PLACE_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__PLACE_X_COMPLETE;
	int  Call__PLACE_X_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__PRO_READY;
	int  Call__PRO_READY(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm);
	int  Seq__PRO_READY(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PRO_START;
	int  Call__PRO_START(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm,
						 const int fa_report_flag = -1);
	int  Seq__PRO_START(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const int fa_report_flag);
	int  _Seq__PRO_START(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm,
						 const int fa_report_flag);

	CString sMODE__AUTO_PRO;
	int  Call__AUTO_PRO(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm);

	CString sMODE__AUTO_PRO_EX;
	int  Call__AUTO_PRO_EX(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__PRE_RCP_READY;
	int  Call__PRE_RCP_READY(CII_OBJECT__VARIABLE* p_variable, 
							 const int dummy_cln_flag = -1);

	CString sMODE__PRE_RCP_START;
	int  Call__PRE_RCP_START(CII_OBJECT__VARIABLE* p_variable,
							 CII_OBJECT__ALARM* p_alarm,
							 const int dummy_cln_flag = -1);

	CString sMODE__AUTO_PRE_RCP;
	int  Call__AUTO_PRE_RCP(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__CLN_READY;
	int  Call__CLN_READY(CII_OBJECT__VARIABLE* p_variable, 
						 const int dummy_cln_flag = -1);

	CString sMODE__CLN_START;
	int  Call__CLN_START(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm,
						 const int dummy_cln_flag = -1);

	CString sMODE__AUTO_CLN;
	int  Call__AUTO_CLN(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__POST_CLN;
	int  iFLAG__WAC_PROC;
	int  Call__POST_CLN(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm);

	int  Fnc__POST_CLN_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__POST_CLN_START(CII_OBJECT__VARIABLE* p_variable,
							 CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__AUTO_DUMMY_CLN;
	int  Call__AUTO_DUMMY_CLN(CII_OBJECT__VARIABLE* p_variable,
							  CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__LAYER_CLN_READY;
	int  Call__LAYER_CLN_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__LAYER_CLN_START;
	int  Call__LAYER_CLN_START(CII_OBJECT__VARIABLE* p_variable,
						       CII_OBJECT__ALARM* p_alarm);

	CString sMODE__AUTO_LAYER_CLN;
	int  Call__AUTO_LAYER_CLN(CII_OBJECT__VARIABLE* p_variable,
						      CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__MNT_READY;
	int  Call__MNT_READY(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__MNT_START;
	int  Call__MNT_START(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__AUTO_MNT;
	int  Call__AUTO_MNT(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__LEAK_CHECK;
	int  Call__LEAK_CHECK(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__LEAK_CHECK(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__LEAK_CHECK_EX;
	int  Call__LEAK_CHECK_EX(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__AUTO_PM;
	int  Call__AUTO_PM(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__AUTO_PM(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__AUTO_PM_EX;
	int  Call__AUTO_PM_EX(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__NEXT_PROC;
	int  Call__NEXT_PROC(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__JOB_START_READY;
	int  Call__JOB_START_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Save__JOB_START_READY();

	CString sMODE__JOB_END_READY;
	int  Call__JOB_END_READY(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__IDLE_START;
	int  Call__IDLE_START(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__LOAD;
	int  Call__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	
	CString sMODE__UNLOAD;
	int  Call__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__READY_TO_UNLOAD;
	int  Call__READY_TO_UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Fnc__SET_TIME();

	//
	CString sMODE__SCH_TEST_CFG;
	int  Call__SCH_TEST_CFG(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);


	// CTC SIM ...
	int  Call__CTC_SIM__TIME_INIT(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__SYSTEM_INIT(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__AUTO_INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__SYSTEM_MAINT(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__PUMP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__VENT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__SLOT_OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__SLOT_CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__PIN_UP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__PIN_DOWN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__PICK_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PICK_X_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PICK_COMPLETE(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PICK_X_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__PLACE_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PLACE_X_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PLACE_COMPLETE(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PLACE_X_COMPLETE(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__PRO_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Seq__CTC_SIM__PRO_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__PRO_START(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm, const int fa_report_flag = -1);
	int  Seq__CTC_SIM__PRO_START(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm, const int fa_report_flag = -1);
	int  Fnc__CTC_SIM__PRO_START(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm, const int fa_report_flag = -1);
	int  _Fnc__CTC_SIM__PRO_START(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm, const int fa_report_flag = -1);
	int  Call__CTC_SIM__AUTO_PRO(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__AUTO_PRO_EX(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__AUTO_DUMMY_CLN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__PRE_RCP_READY(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int dummy_pre_flag = -1);
	int  Fnc__CTC_SIM__PRE_RCP_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__PRE_RCP_START(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int dummy_pre_flag = -1);
	int  Fnc__CTC_SIM__PRE_RCP_START(CII_OBJECT__VARIABLE* p_variable,	CII_OBJECT__ALARM* p_alarm);
	int  Call__CTC_SIM__AUTO_PRE_RCP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Call__CTC_SIM__CLN_READY(CII_OBJECT__VARIABLE* p_variable, const int dummy_cln_flag = -1);
	int  Fnc__CTC_SIM__POST_CLN_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__CLN_START(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm, const int dummy_cln_flag = -1);
	int  Fnc__CTC_SIM__POST_CLN_START(CII_OBJECT__VARIABLE* p_variable,	CII_OBJECT__ALARM* p_alarm);
	int  Call__CTC_SIM__AUTO_CLN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__POST_CLN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Seq__CTC_SIM__POST_CLN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);

	int  Call__CTC_SIM__MNT_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__MNT_START(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__AUTO_MNT(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__LEAK_CHECK(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__LEAK_CHECK_EX(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__AUTO_PM(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__AUTO_PM_EX(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__HEADER_RCP(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__NEXT_PROC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	int  Call__CTC_SIM__JOB_START_READY(CII_OBJECT__VARIABLE* p_variable);
	int  Call__CTC_SIM__JOB_END_READY(CII_OBJECT__VARIABLE* p_variable);

	int  Call__CTC_SIM__IDLE_START(CII_OBJECT__VARIABLE* p_variable);
	//

	
	//-----------------------------------------------------------
	void Mon__All_State(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	// * GoTo_Maint
	// * Count_Ctrl
	void Fnc__LPx_Wafer_Count(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__Clean_Rcp_Count(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__Leak_Check(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__Auto_PM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__Process_Time(double& total_time);

	// ...
	int  iFLAG__STEP_REPORT;
	void Mon__FA_Report(CII_OBJECT__VARIABLE* p_variable);

	//-----------------------------------------------------------
	void Set__Module_Time();
	void Set__Place_Ready_Parameter(CII_OBJECT__VARIABLE *p_variable);
	void Set__Slot_No_Parameter(CII_OBJECT__VARIABLE *p_variable);
	void Set__Prc_Ready_Parameter(CII_OBJECT__VARIABLE *p_variable);
	void Set__Pre_Ready_Parameter(CII_OBJECT__VARIABLE *p_variable,const int dummy_cln_flag);
	void Set__Cln_Ready_Parameter(CII_OBJECT__VARIABLE *p_variable,const int dummy_cln_flag);
	void Set__Layer_Cln_Ready_Parameter(CII_OBJECT__VARIABLE *p_variable);

	void Set__Slot_Info(CII_OBJECT__VARIABLE *p_variable);
	void Check__Slot_Info(CII_OBJECT__VARIABLE *p_variable);

	void Clear__PMC_Info();

	void Check__Material_Count(CII_OBJECT__VARIABLE *p_variable);
	void Check__RF_Time(CII_OBJECT__VARIABLE *p_variable);
	void Check__Material_Clear();

	int  Check__Standby_Or_CtcInUse();

	//-----------------------------------------------------------
	void Check__PMx_Slot_Max();
	int  Get__PMx_Occupied_Slot();
	int  Get__Material_Count();

	//-----------------------------------------------------------
	void Fnc__PMC_Datalog(const CString& lotid,
						  const int lp_slotid,
						  CString& pm_log_path);

	// ...
	void Datalog__Write_Lot_Proc_Slot_Start(const int slot_index,
											const int slot_log_count,
											const int pm_slot_id,
											const IDS__SCH_MATERIAL_INFO& db_info,
											CString& pm_log_path);
	
	void Datalog__Write_Lot_Proc_Slot_End(const int pm_slot_id,
										  const CString& lotid,
										  const CString& lp_id,
										  const int lp_slot_id);

	// ...
	void Datalog__Write_Lot_Clean_Slot_Start(const CString& str_lotid,
									         const CString& str_lp_slotid);

	void Datalog__Write_Lot_Clean_Slot_End(const CString& str_lotid,
										     const CString& str_lp_slotid);

	// ...
	void _Process_Report__Wafer_Info();
	//


public:
	// ...
	int  Is_Available();
	int  Is_Ready();

	CString Get_SlotStatus(const int slot_id);
	CString Get_SlotTitle(const int slot_id);
	//

public:
	CObj_Phy__PMC_STD();
	~CObj_Phy__PMC_STD();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	int __START__OBJECT();

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
