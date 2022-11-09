#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_System.h"

#include "CObj_Opr__AUTO_MODE__DEF.h"
#include "CObj_Opr__AUTO_MODE__ALID.h"


// ...
#define  CYCLE_MODE__DISABLE		1
#define  CYCLE_MODE__ENABLE			2
#define  CYCLE_MODE__FOREVER		3


class CObj_Opr__AUTO_MODE : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString sObject_Name;

	CCommon_Error__DEF_VARIABLE mERROR__DEF_VAR;
	CCommon_Error__USER_FNC     mERROR__USER_FNC;

	// ...
	SCX__CTC__SCH_MATERIAL_CTRL xSCH_MATERIAL_CTRL;
	SCX__CTC__JOB_FILE_CTRL xSCH_JOB_FILE_CTRL;
	SCX__CTC__JOB_FILE_CTRL xLPx_JOB_FILE_CTRL[CFG_LP_LIMIT];

	SCX__SEQ_INFO xSEQ_INFO;
	int iSIM_MODE;

	// SCX__LOT_LOG_CTRL xLOT_LOG_CTRL;
	SCX__USER_LOG_CTRL xLOG_CTRL;

	int iMAINT_FLAG;
	CString sDIR_ROOT;
	CString sDIR_WFR_DATA;
	CString sDIR_PROCESS;

	// ...
	int iLPx_UNIT_SIZE;
	int iLPx_SLOT_SIZE;

	int iBUFF_UNIT_SIZE;
	int iBUFF_SLOT_SIZE;

	int iAL1_SLOT_SIZE;

	int iPMx_UNIT_SIZE;
	//
	
	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// STATUS
	CX__VAR_STRING_CTRL  xCH__JOB_CTRL;
	CX__VAR_STRING_CTRL  xCH_PRE__JOB_CTRL;

	CX__VAR_STRING_CTRL  xCH__JOB_STATUS;
	CX__VAR_STRING_CTRL  xCH_PRE__JOB_STATUS;

	CX__VAR_STRING_CTRL  xCH__JOB_READY_START_FLAG;

	//
	CX__VAR_STRING_CTRL  xCH__RESYNC_EDIT_STATUS_CUR;
	CX__VAR_STRING_CTRL  xCH__RESYNC_EDIT_STATUS_REQ;

	//
	CX__VAR_DIGITAL_CTRL xCH__CFG_SCH_MODE;
	CX__VAR_DIGITAL_CTRL xCH__CFG_SCH_REF;

	CX__VAR_STRING_CTRL  xCH__PORT_UPLOAD_FILE_FLAG[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_PJOBID[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__SYS_STATUS;

	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK_START_FLAG;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK__IDLE_RUN_DATE;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK__IDLE_PRE_DATE;
	CX__VAR_STRING_CTRL  xCH__LEAK_CHECK__IDLE_PRE_STATUS;

	CX__VAR_STRING_CTRL  xCH__AUTO_PM_START_FLAG;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM__IDLE_RUN_DATE;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM__IDLE_PRE_DATE;
	CX__VAR_STRING_CTRL  xCH__AUTO_PM__IDLE_PRE_STATUS;

	// CYCLE PARA
	int iCYCLE_MODE;

	int iCYCLE_LOT_COUNT;
	int iCYCLE_REF_TICK;
	double dCYCLE_ELAPSE_SEC;

	int iCYCLE_STEADY_LOT_COUNT;
	int iCYCLE_STEADY_REF_TICK;
	double dCYCLE_STEADY_ELAPSE_SEC;

	SYSTEMTIME mCYCLE_START_TIME;
	SYSTEMTIME mCYCLE_END_TIME;

	CX__VAR_DIGITAL_CTRL xCH_CFG__CYCLE_MODE; 
	CX__VAR_ANALOG_CTRL  xCH_CFG__CYCLE_LIMIT;

	CX__VAR_ANALOG_CTRL  xCH_CFG__CYCLE_COUNT_PICK;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CYCLE_COUNT_PLACE;

	CX__VAR_STRING_CTRL  xCH_CFG__CYCLE_START_TIME;
	CX__VAR_STRING_CTRL  xCH_CFG__CYCLE_ELAPSE_TIME;
	CX__VAR_STRING_CTRL  xCH_CFG__CYCLE_THROUGHPUT;

	CX__VAR_STRING_CTRL  xCH_CFG__CYCLE_STEADY_ELAPSE_TIME;
	CX__VAR_STRING_CTRL  xCH_CFG__CYCLE_STEADY_THROUGHPUT;
	CX__VAR_ANALOG_CTRL  xCH_CFG__CYCLE_STEADY_COUNT_LIMIT;

	CX__VAR_DIGITAL_CTRL xCH_CFG__SCH_TEST_PORT_CURRENT_APPLY;

	// jglee : 2021.11.11
	CX__VAR_DIGITAL_CTRL dCH_CFG__LLx_STATE_CHECK_FOR_JOB_START;

	//
	CX__VAR_DIGITAL_CTRL dCH_CFG__DUMMY_PORT_USE_MODE;

	//
	CX__VAR_DIGITAL_CTRL dCH_CFG__DUMMY_PORT_CTRL_TYPE;

	//
	CX__VAR_DIGITAL_CTRL dCH_CFG__DUMMY_PORT_WAFER_PER_PMC;

	CX__VAR_DIGITAL_CTRL dCH_CFG__DUMMY_PORT_PMC_IDLE_MODE;
	CX__VAR_ANALOG_CTRL  aCH_CFG__DUMMY_PORT_PMC_IDLE_TIME;

	CX__VAR_ANALOG_CTRL  aCH_CFG__DUMMY_PORT_PMx_IDLE_TIME[CFG_PM_LIMIT];

	CX__VAR_DIGITAL_CTRL xCH_CFG__DUMMY_PORT_SLOT_USE[CFG_LP__SLOT_MAX];
	CX__VAR_ANALOG_CTRL  aCH_CFG__DUMMY_PORT_SLOT_MAX_COUNT[CFG_LP__SLOT_MAX];

	CX__VAR_STRING_CTRL  sCH_APP__DUMMY_PORT_CUR_COUNT_RESET_REQ;
	CX__VAR_ANALOG_CTRL  aCH_CFG__DUMMY_PORT_COUNT_WARNING_ALARM;

	CX__VAR_DIGITAL_CTRL xCH_CFG__LPx_PICK_MODE;
	//


	//-------------------------------------------------------------------------
	//  EXTERNAL PROPERTY

	// MSG ...
	CX__VAR_STRING_CTRL   sEXT_CH__SYS_MSG;
	CX__VAR_STRING_CTRL   sEXT_CH__FNC_MSG;

	// DB CFG -----
	CX__VAR_DIGITAL_CTRL  dEXT_CH__CFG_JOB_START_READY_CTRL_MODE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__CFG_JOB_START_READY_PMx_USE[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL  dEXT_CH__CFG_JOB_END_READY_PMx_USE[CFG_PM_LIMIT];

	CX__VAR_DIGITAL_CTRL  dEXT_CH__SCH_TEST_CFG_PMX_DUMMY_BY_CTC[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_CONCURRENT_ALWAYS_APPLY;

	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DUMMY_CLEAN_USE_FLAG;
	CX__VAR_ANALOG_CTRL   xEXT_CH__CFG_DUMMY_CLEAN_SYSTEM_IDLE_TIME;
	CX__VAR_ANALOG_CTRL   xEXT_CH__DUMMY_CLEAN_SYSTEM_IDLE_TIME_COUNT;
	CX__VAR_ANALOG_CTRL   xEXT_CH__CFG_DUMMY_CLEAN_WAFER_PER_PMC;
	CX__VAR_STRING_CTRL   sEXT_CH__APP_DUMMY_PORT_CUR_COUNT_SLOTx[CFG_LP__SLOT_MAX];

	//
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG__PMx_USE[CFG_PM_LIMIT];

	//
	CX__VAR_STRING_CTRL   xEXT_CH__USER_LEVEL;
	CX__VAR_STRING_CTRL   xEXT_CH__USER_ID;

	// SCH.START_JOB.XXX ...
	CX__VAR_STRING_CTRL   sEXT_CH__SCH_START_JOB_LLx_IN_SIZE;
	CX__VAR_STRING_CTRL   sEXT_CH__SCH_START_JOB_LLx_OUT_SIZE;

	// SCH.MODE.XXX ...
	CX__VAR_STRING_CTRL   sEXT_CH__SCH_MODE_LLx_IN;
	CX__VAR_STRING_CTRL   sEXT_CH__SCH_MODE_LLx_OUT;

	// CFG_DB : AL1 ...
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_AL1_USE_FLAG;

	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_AL1_SLOT01_USE_FLAG;
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_AL1_SLOT02_USE_FLAG;

	// SCH_DB : AL1 ...
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_AL1_USE_FLAG;

	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_AL1_SLOT01_USE_FLAG;
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_AL1_SLOT02_USE_FLAG;
	// ...

	// CFG DB ...
	// LLx
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_LLx_USE_FLAG[CFG_LLx_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_LLx_SLOT_MAX[CFG_LLx_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_DB_LLx_IDLE_STATUS[CFG_LLx_LIMIT];

	CII__VAR_DIGITAL_CTRL *pEXT_CH__CFG_DB_LLx_MODE_TYPE[CFG_LLx_LIMIT];
	CII__VAR_DIGITAL_CTRL *pEXT_CH__CFG_DB_LLx_SLOT_STATUS[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];
	CII__VAR_DIGITAL_CTRL *pEXT_CH__CFG_DB_LLx_SLOT_MODE[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];

	// PMx 
	CX__VAR_STRING_CTRL   sEXT_CH__PMx__CUR_PRE_COUNT[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL   sEXT_CH__PMx__CUR_POST_COUNT[CFG_PM_LIMIT];
	//

	// SCH DB ...
	// LLx
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_LLx_USE_FLAG[CFG_LLx_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_LLx_SLOT_MAX[CFG_LLx_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__SCH_DB_LLx_IDLE_STATUS[CFG_LLx_LIMIT];

	CII__VAR_DIGITAL_CTRL *pEXT_CH__SCH_DB_LLx_MODE_TYPE[CFG_LLx_LIMIT];
	CII__VAR_DIGITAL_CTRL *pEXT_CH__SCH_DB_LLx_SLOT_STATUS[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];
	CII__VAR_DIGITAL_CTRL *pEXT_CH__SCH_DB_LLx_SLOT_MODE[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];

	// ...
	CX__VAR_DIGITAL_CTRL  xEXT_CH__PMx_CFG_USE[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__PMx_PROCESS_TYPE[CFG_PM_LIMIT];

	//
	CX__VAR_STRING_CTRL   xEXT_CH__PMx_AUTO_PM_FLAG[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__AUTO_PM__IDLE_USE_FLAG;
	SCX__ASYNC_TIMER_CTRL xI_AUTO_PM_IDLE_TIMER;
	CX__VAR_ANALOG_CTRL   xEXT_CH__AUTO_PM__IDLE_REF_TIME;
	CX__VAR_ANALOG_CTRL   xEXT_CH__AUTO_PM__IDLE_CUR_TIME;
	CX__VAR_ANALOG_CTRL   xEXT_CH__AUTO_PM__IDLE_REF_COUNT;
	CX__VAR_ANALOG_CTRL   xEXT_CH__AUTO_PM__IDLE_CUR_COUNT;

	//
	CX__VAR_STRING_CTRL   xEXT_CH__PMx_LEAK_CHECK_FLAG[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL  xEXT_CH__LEAK_CHECK__IDLE_USE_FLAG;
	SCX__ASYNC_TIMER_CTRL xI_LEAK_CHECK_IDLE_TIMER;
	CX__VAR_ANALOG_CTRL   xEXT_CH__LEAK_CHECK__IDLE_REF_TIME;
	CX__VAR_ANALOG_CTRL   xEXT_CH__LEAK_CHECK__IDLE_CUR_TIME;
	CX__VAR_ANALOG_CTRL   xEXT_CH__LEAK_CHECK__IDLE_REF_COUNT;
	CX__VAR_ANALOG_CTRL   xEXT_CH__LEAK_CHECK__IDLE_CUR_COUNT;

	//
	CX__VAR_DIGITAL_CTRL  xEXT_CH__CFG_CYCLE_FOUP_CTRL_MODE;
	//

	// ATM RB -----
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_DB_STx_JOB_WAIT_MODULE;
	CX__VAR_STRING_CTRL  xEXT_CH__CUR_STx_SIZE;

	//
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_DB_STx_APPLY_MODE;

	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_DB_STx_TRANSFER_MODE;
	CX__VAR_ANALOG_CTRL  xEXT_CH__CFG_DB_BUFFER_WAFER_CLEAN_TIME;
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_DB_STx_WAFER_PICK_MODE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DB_STx_OUT_MODE_BUFFER_TO_LPo;

	//
	CX__VAR_DIGITAL_CTRL xEXT_CH__SCH_DB_STx_TRANSFER_MODE;
	CX__VAR_STRING_CTRL  sEXT_CH__SCH_DB_ST1_USE_FLAG;
	CX__VAR_STRING_CTRL  sEXT_CH__SCH_DB_ST2_USE_FLAG;

	CX__VAR_ANALOG_CTRL  xEXT_CH__SCH_DB_ST1_WAFER_CLEAN_TIME;
	CX__VAR_ANALOG_CTRL  xEXT_CH__SCH_DB_ST2_WAFER_CLEAN_TIME;

	CX__VAR_DIGITAL_CTRL xEXT_CH__SCH_DB_ST1_WAFER_PICK_MODE;
	CX__VAR_DIGITAL_CTRL xEXT_CH__SCH_DB_ST2_WAFER_PICK_MODE;

	CX__VAR_DIGITAL_CTRL xEXT_CH__SCH_DB_STx_APPLY_MODE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SCH_DB_ST1_OUT_MODE_BUFFER_TO_LPo;
	CX__VAR_DIGITAL_CTRL dEXT_CH__SCH_DB_ST2_OUT_MODE_BUFFER_TO_LPo;
	// ...

	// LPx -----
	CII_EXT_OBJECT__CTRL *pPORT__OBJ_CTRL[CFG_LP_LIMIT];

	CX__VAR_DIGITAL_CTRL xCH__PORT_CFG_USE_TYEP[CFG_LP_LIMIT];
	CX__VAR_DIGITAL_CTRL xCH__PORT_CFG_SLOT_MAX[CFG_LP_LIMIT];
	
	CX__VAR_DIGITAL_CTRL xCH__PORT_CST_STATUS[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  sCH__PORT_HOQ_REQ[CFG_LP_LIMIT];

	CX__VAR_ANALOG_CTRL  xCH__PORT_LAST_PICK_SLOT[CFG_LP_LIMIT];
	CX__VAR_ANALOG_CTRL  xCH__PORT_LAST_RESERVE_SLOT[CFG_LP_LIMIT];

	CX__VAR_DIGITAL_CTRL xCH__PORT_CTRL[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_JOB_POPUP_TYPE[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_CJOBID[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_JOB_NAME[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__CSTID[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_STATUS[CFG_LP_LIMIT];
	CX__VAR_DIGITAL_CTRL xCH__PORT_SLOT_STS[CFG_LP_LIMIT][CFG_LP__SLOT_MAX];
	CX__VAR_STRING_CTRL  xCH__PORT_LOTID[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_PPID[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__PORT_EXCEPTION[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_LAMP_STATUS[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__PORT_DB_LOTID[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_DB_ROUTEID[CFG_LP_LIMIT];
	CX__VAR_ANALOG_CTRL  xCH__PORT_DB_CYCLE_START_SLOT[CFG_LP_LIMIT];
	CX__VAR_ANALOG_CTRL  xCH__PORT_DB_CYCLE_END_SLOT[CFG_LP_LIMIT];
	CX__VAR_ANALOG_CTRL  xCH__PORT_DB_CYCLE_COUNT[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_DB_CYCLE_MSG[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__PORT_END_REQ_FLAG[CFG_LP_LIMIT];
	CX__VAR_ANALOG_CTRL  xCH__PORT_CUR_CYCLE_COUNT[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__PORT_MANUAL_CTRL_FLAG[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_CYCLE_CTRL_FLAG[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__PORT_MANUAL_CTRL_RUNNING_FLAG[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__PORT_CYCLE_CTRL_RUNNING_FLAG[CFG_LP_LIMIT];

	CX__VAR_DIGITAL_CTRL xCH__LPx__CFG_PROCESS_TYPE[CFG_LP_LIMIT];

	CX__VAR_STRING_CTRL  xCH__LPx_END_REQ_FLAG[CFG_LP_LIMIT];
	CX__VAR_STRING_CTRL  xCH__LPx_RETURN_REQ_FLAG[CFG_LP_LIMIT];

	
	// BUFFER_X ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__BUFFx_SLOT[CFG_BUFFER__UNIT_LIMIT][CFG_BUFFER__SLOT_MAX];
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_DB_STx_USE_FLAG[CFG_BUFFER__UNIT_LIMIT];

	// ATM_RB ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__ATM_RB_A__MATERIAL_STATUS_ARM;
	CX__VAR_STRING_CTRL  sEXT_CH__ATM_RB_A__MATERIAL_TITLE_ARM;

	// AL1 ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__AL1_X__MATERIAL_STATUS_SLOT[CFG_AL__SLOT_MAX];
	CX__VAR_STRING_CTRL  sEXT_CH__AL1_X__MATERIAL_TITLE_SLOT[CFG_AL__SLOT_MAX];

	// LLx ...
	int iLLx_SIZE;
	int iLLx__SLOT_SIZE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__LLx_X__MATERIAL_STATUS_SLOT[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];
	CX__VAR_STRING_CTRL  sEXT_CH__LLx_X__MATERIAL_TITLE_SLOT[CFG_LLx_LIMIT][CFG_LLx__SLOT_MAX];

	// VAC_RB ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__VAC_RB_A__MATERIAL_STATUS_ARM;
	CX__VAR_STRING_CTRL  sEXT_CH__VAC_RB_A__MATERIAL_TITLE_ARM;

	CX__VAR_DIGITAL_CTRL dEXT_CH__VAC_RB_B__MATERIAL_STATUS_ARM;
	CX__VAR_STRING_CTRL  sEXT_CH__VAC_RB_B__MATERIAL_TITLE_ARM;


	// PMx -----
	CII_EXT_OBJECT__CTRL *pPMx__OBJ_CTRL[CFG_PM_LIMIT];

	CX__VAR_DIGITAL_CTRL xEXT_CH__PMx__OBJ_CTRL[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  xEXT_CH__PMx_OBJECT_STATUS[CFG_PM_LIMIT];
	CX__VAR_DIGITAL_CTRL xEXT_CH__PMx__OBJ_STATUS[CFG_PM_LIMIT];

	CX__VAR_STRING_CTRL  xEXT_CH__PMx_CFG_DUMMY_PROC_RCP[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  xEXT_CH__PMx_CFG_DUMMY_CLN_RCP[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  xEXT_CH__PMx_CFG_DUMMY_PRE_RCP[CFG_PM_LIMIT];

	CX__VAR_ANALOG_CTRL  xEXT_CH__PMx_CUR_IDLE_TIME[CFG_PM_LIMIT];

	CX__VAR_DIGITAL_CTRL dEXT_CH__PMx_SLOT_STATUS[CFG_PM_LIMIT];

	CX__VAR_STRING_CTRL  sEXT_CH__PMx_PRE_INFO_JOB_START_READY_PORTID[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  sEXT_CH__PMx_PRE_INFO_JOB_START_READY_JOBID[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  sEXT_CH__PMx_REQ_INFO_JOB_START_READY_PORTID[CFG_PM_LIMIT];
	CX__VAR_STRING_CTRL  sEXT_CH__PMx_REQ_INFO_JOB_START_READY_JOBID[CFG_PM_LIMIT];

	// ROBOT PAUSE ...
	CX__VAR_STRING_CTRL  sEXT_CH__ATM_ROBOT__PAUSE_FLAG;
	CX__VAR_STRING_CTRL  sEXT_CH__VAC_ROBOT__PAUSE_FLAG;
	//


	//-------------------------------------------------------------------------
	CString sMODE__MAINT;
	int  Call__MAINT_MODE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//-------------------------------------------------------------------------
	void Mon__ALL_STATE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__SYSTEM_IDLE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	void Fnc__MANUAL_CTRL(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	void Fnc__SYS_STATUS(CII_OBJECT__VARIABLE *p_varlable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__RESYNC_EDIT_CTRL(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	void Fnc__DUMMY_SLOT_COUNT_WARNING(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	void Mon__PORT_CTRL(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	void Fnc__LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  Fnc__TIME_LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  Fnc__IDLE_LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	void Fnc__AUTO_PM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  Fnc__TIME_AUTO_PM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  Fnc__IDLE_AUTO_PM(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	void Seq__JOB_CLEAR();
	void Seq__JOB_CTRL();
	void Seq__JOB_END(CII_OBJECT__ALARM* p_alarm);

	void Seq__UPLOAD_RESERVE_PORT(CII_OBJECT__ALARM *p_alarm);

	void Seq__UPLOAD_JOB(CII_OBJECT__ALARM *p_alarm);
	int  Check__SYSTEM_ERROR(CII_OBJECT__ALARM *p_alarm);
	int  Check__LPx_CID_ERROR(CII_OBJECT__ALARM *p_alarm,const int ptn,const CString& cstid);
	void Seq__CHECK_PORT_COMPLETE(CII_OBJECT__ALARM *p_alarm);
	int  Check__ALL_PORT_COMPLETE();

	int  _Seq__UPLOAD_JOB(CII_OBJECT__ALARM *p_alarm,const int lp_index);

	void Seq__ABORT_ALL_PORT();
	void Seq__CLEAR_ALL_PORT(CII_OBJECT__ALARM *p_alarm,const int alarm_box = 1);

	void Seq__UPDATE_PORT_INFO();

	int  Fnc__UPLOAD_JOB(CII_OBJECT__ALARM *p_alarm,
							const int ptn,
							const CString& dir_lp,
							const CString& lp_rcp);

	// ...
	int  Fnc__DUMMY_PROC_JOB(CII_OBJECT__ALARM* p_alarm, const int src_ptn,const CStringArray& l_pmc);

	int  Fnc__GET_DUMMY_PORT();
	int  Fnc__GET_DUMMY_SLOT(const int port_id,int& slot_id);
	int  Fnc__SET_DUMMY_SLOT_READY(const int port_id);

	int  Fnc__GET_PORT_SLOTMAPLIST(const int port_id,CString& str_maplist);
	int  Fnc__GET_PORT_SLOTJOBLIST(const int port_id,CString& str_joblist);

	// ...
	int  iPICK_COUNT;
	int  iPLACE_COUNT;

	int  Fnc__CYCLE_START(CII_OBJECT__ALARM *p_alarm);
	void Fnc__CYCLE_END(CII_OBJECT__ALARM *p_alarm);
	void Fnc__CYCLE_COUNT();

	int  Check__CYCLE_MODE()
	{
		switch(iCYCLE_MODE)
		{
			case CYCLE_MODE__ENABLE:
			case CYCLE_MODE__FOREVER:
				return 1;
		}
		return -1;
	}

	int  Check__LPx_CYCLE_MODE(const int lp_index,const int count_flag);

	// ...
	void Datalog__Write_Lot(const int ptn);
	
	// ...
	void Fnc__Wafer_Info_Resynch_With_Scheduler_DB();

	//
	void Fnc__Check_Wafer_Duplication_Of_UI(CStringArray& l_ui_pos,
											CStringArray& l_ui_wfr_status,
											CStringArray& l_ui_wfr_title, 		
											CStringArray& l_err_pos,
											CStringArray& l_err_wfr_status,
											CStringArray& l_err_wfr_title);

	int  Fnc__Check_UI_Wafer_And_SCH_Wafer(const CStringArray& l_ui_pos,
											const CStringArray& l_ui_wfr_status,
											const CStringArray& l_ui_wfr_title, 		
											const CStringArray& l_sch_pos,
											const CStringArray& l_sch_wfr_status,
											const CStringArray& l_sch_wfr_title,
											CStringArray& l_err_pos,
											CStringArray& l_err_wfr_status,
											CStringArray& l_err_wfr_title);

	//
	void Fnc__Get_All_Wafer_Info_Of_UI(CStringArray& l_ui_pos,
									   CStringArray& l_ui_wfr_status,
									   CStringArray& l_ui_wfr_title);

	void Fnc__Get_All_Wafer_Info_Of_SCH(CStringArray& l_sch_pos,
										CStringArray& l_sch_wfr_status,
										CStringArray& l_sch_wfr_title);

	// ...
	CString Get__LLx_NAME(const int ll_i);

	int  Update__CFG_DB_TO_SCH_DB();
	int  Update__ROUTE_DB_TO_SCH_DB(const int lp_id);
	int  _Update__ROUTE_DB_TO_SCH_DB(const int lp_id);

	int  Check__ALx_OF_SCH_DB(const CStringArray& l_id,
							  const CStringArray& l_mode,
							  const CStringArray& l_slot);
	int  Check__LLx_IN_OF_SCH_DB(const CStringArray& l_id,
								 const CStringArray& l_mode,
								 const CStringArray& l_slot);
	int  Check__LLx_OUT_OF_SCH_DB(const CStringArray& l_id,
								  const CStringArray& l_mode,
								  const CStringArray& l_slot);
	int  Check__STx_OF_SCH_DB(const CStringArray& l_id,
							  const CStringArray& l_mode,
							  const CStringArray& l_slot,
							  const CStringArray& l_sec);

	int  Update__ADD_LLx_DB_TO_SCH_DB(SCI__CTC__JOB_FILE_CTRL *p_job_file,
									  const int slot_id);
	int  Check__ADD_LLx_IN_OF_SCH_DB(SCI__CTC__JOB_FILE_CTRL *p_job_file,
									 const int slot_id);
	int  Check__ADD_LLx_OUT_OF_SCH_DB(SCI__CTC__JOB_FILE_CTRL *p_job_file,
									  const int slot_id);
	int  _Check__ADD_LLx_OF_SCH_DB(const int ll_in_check,
								   const int ll_out_check,
								   const CStringArray& l_id,
		                           const CStringArray& l_mode,
		                           const CStringArray& l_slot);

	// ...
	int  SCH__PMx_JOB_START_READY(const int lp_id = -1);
	int  SCH_RUN__PMx_JOB_START_READY(const int pm_index, const CString& port_id,const CString& job_id);
	int  Check__PMx_JOB_START_READY(const int pm_index, const CString& port_id,const CString& job_id);	
	int  Clear__PMx_JOB_START_READY();	

	int  SCH__PMx_JOB_END_READY();

	int  PMx__Is_Available(const int pm_i);

	int  Check__STx_To_Use(const CStringArray& l_id);
	//


public:
	CObj_Opr__AUTO_MODE();
	~CObj_Opr__AUTO_MODE();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_def_fnc);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
