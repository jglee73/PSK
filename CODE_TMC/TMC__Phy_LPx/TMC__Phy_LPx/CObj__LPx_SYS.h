#pragma once

#include "Interface_Code.h"

#include "CCommon_System.h"
#include "CCommon_Error.h"

#include "CObj__LPx_SYS__DEF.h"


class CObj__LPx_SYS : public __IOBJ__STD_TYPE
{
private:
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	//-------------------------------------------------------------------------
	CString sObject_Name;

	SCX__USER_LOG_CTRL xLOG_CTRL;

	int iActive__SIM_MODE;
	//

	//-------------------------------------------------------------------------
	// INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;

	// PARA ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_PAGE_ID;
	CX__VAR_STRING_CTRL  sCH__PARA_PAGE_CID;
	CX__VAR_STRING_CTRL  sCH__PARA_PAGE_DATA;

	// MON ...
	CX__VAR_DIGITAL_CTRL dCH__MON_SLOT_STATUS[CFG_LPx__SLOT_MAX];
	CX__VAR_STRING_CTRL  sCH__MON_SLOT_TITLE[CFG_LPx__SLOT_MAX];

	CX__VAR_DIGITAL_CTRL dCH__MON_CLAMP_STS;
	CX__VAR_DIGITAL_CTRL dCH__MON_FOUP_STS;
	CX__VAR_DIGITAL_CTRL dCH__MON_FOUP_POS;
	CX__VAR_DIGITAL_CTRL dCH__MON_DOOR_STS;
	
	CX__VAR_DIGITAL_CTRL dCH__MON_TRANSFER_PIO_STATUS;

	// LINK_PIO ...
	CX__VAR_DIGITAL_CTRL dCH__LINK_PIO_ACTIVE_RUN;
	CX__VAR_DIGITAL_CTRL dCH__LINK_PIO_ACTIVE_FA_AUTO;
	CX__VAR_DIGITAL_CTRL dCH__LINK_PIO_ACTIVE_LOAD_REQ;
	CX__VAR_DIGITAL_CTRL dCH__LINK_PIO_ACTIVE_UNLOAD_REQ;

	// SIM ...
	CX__VAR_DIGITAL_CTRL dCH__SIM_PAUSE_ACTIVE;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_MAX_SLOT_COUNT;

	CX__VAR_DIGITAL_CTRL dCH__CFG_MACRO_LOAD_USE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_MACRO_UNLOAD_USE;

	CX__VAR_STRING_CTRL  sCH__CFG_BYPASS_READ_ID_FLAG;

	CX__VAR_STRING_CTRL  sCH__CFG_FA_MODE;
	CX__VAR_STRING_CTRL  sCH__CFG_FA_SERVICE_MODE;

	CX__VAR_STRING_CTRL  sCH__CFG_RELOAD_FLAG;
	CX__VAR_STRING_CTRL  sCH__MAP_SEQ_LOCK;

	// ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_RF_EXIST_FLAG;	

	CX__VAR_STRING_CTRL  sCH__FOUP_CID_STRING;
	CX__VAR_STRING_CTRL  sCH__FOUP_PAGE_STRING;

	// ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_PREPLOAD_CID_MODE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_LOAD_MAP_MODE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_LOAD_ACT_AUTO_MAP_MODE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_MAPPING_SENSOR_USE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_BEFORE_LOAD_CST_CHECK;
	CX__VAR_DIGITAL_CTRL dCH__CFG_LOAD_DOOR_OPEN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_LOAD_COMPT_DELAY_TIME;
	CX__VAR_DIGITAL_CTRL dCH__CFG_DYNAMIC_USE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_UNLD_CLAMP_OPT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_DOOR_OPEN_COMPLETE_DELAY_TIME;
	CX__VAR_DIGITAL_CTRL dCH__CFG_WAFER_SLIDE_SNS_CHECK;

	CX__VAR_DIGITAL_CTRL dCH__CFG_INIT_SLOT_STATE_UNKNOWN;

	CX__VAR_DIGITAL_CTRL dCH__CFG_LOAD_POS_STATE_USE;

	// CFG.INTERLOCK ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_ROBOT_AND_LPx_LOAD;

	// CFG.CYCLE ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_CYCLE_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__CUR_CYCLE_COUNT;

	// ACTIVE CHECK ...
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_CLAMP_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_CLAMP_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_UNCLAMP_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_UNCLAMP_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_EXT_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_EXT_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_RET_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_RET_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_DN_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_DN_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_UP_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_DOOR_UP_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_LATCH_OPEN_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_LATCH_OPEN_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_LATCH_CLOSE_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_LATCH_CLOSE_DI;

	CX__VAR_STRING_CTRL  dCH__ACTIVE_CHECK_DOOR_VAC_DO;
	CX__VAR_STRING_CTRL  dCH__ACTIVE_CHECK_DOOR_VAC_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_SHUTTLE_IN_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_SHUTTLE_IN_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_SHUTTLE_OUT_DO;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_SHUTTLE_OUT_DI;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_WAFER_SLID_OUT_DI;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_FOUP_PRESENT_DI;
	CX__VAR_STRING_CTRL  sCH__ACTIVE_CHECK_FOUP_PLACED_DI;
	//


	//-------------------------------------------------------------------------
	// EXTERNAL PROPERTY

	int iLPx_ID;

	// LINK_CH : OBJ_STATE ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__OBJ_STATE;

	// OBJ : LPx ...
	CII_EXT_OBJECT__CTRL *pLPx__OBJ_CTRL;

	CX__VAR_STRING_CTRL  sEXT_CH__LPx__CLAMP_STS;
	CX__VAR_STRING_CTRL  sEXT_CH__LPx__DOOR_STS;

	CX__VAR_STRING_CTRL  sEXT_CH__LPx__FOUP_STS;
	CX__VAR_STRING_CTRL  sEXT_CH__LPx__FOUP_POS;

	CX__VAR_STRING_CTRL  sEXT_CH__LPx__RES_MAP_SLOT_X[CFG_LPx__SLOT_MAX];

	// OBJ : RFx ...
	bool bActive__RFx_OBJ;
	CII_EXT_OBJECT__CTRL *pRFx__OBJ_CTRL;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RFx__PARA_PAGE_ID;
	CX__VAR_STRING_CTRL  sEXT_CH__RFx__PARA_CID_DATA;
	CX__VAR_STRING_CTRL  sEXT_CH__RFx__PARA_PAGE_DATA;

	CX__VAR_STRING_CTRL  sEXT_CH__RFx__RSP_CID_DATA;
	CX__VAR_STRING_CTRL  sEXT_CH__RFx__RSP_PAGE_DATA;

	// OBJ : OHT ...
	bool bActive__LPx_OHT;
	CX__VAR_DIGITAL_CTRL dEXT_CH__REPORT_PIO_E84_RUN_STATE;

	// ARM_RNE.INFO ...
	bool bActive__DI_ROBOT_ARM_RNE_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_ARM_RNE_SNS;

	CString sDATA__RNE_ON;
	CString sDATA__RNE_OFF;

	// LINK_IO ...
	bool bActive__DI_SLIDE_OUT_SNS;
	CX__VAR_DIGITAL_CTRL diEXT_CH__LPx_WAFER_SLID_OUT;

	// OBJ.ROBOT ...
	bool bActive__ROBOT_OBJ_CTRL;
	CII_EXT_OBJECT__CTRL *pROBOT__OBJ_CTRL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT__MON_ACTIVE_ROBOT_ACTION_BUSY;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT__MON_ACTIVE_INTERLOCK_BY_LP;
	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT__MON_ACTIVE_WAIT_BY_LP;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT__MON_ACTIVE_ACTION_TO_LP;
	//


	//------------------------------------------------------------------------------
	// INIT ----- 
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__HOME;
	int  Call__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__ALARM_RESET;
	int  Call__ALARM_RESET(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// DOOR OPEN -----
	CString sMODE__DOOR_OPEN;
	int  Call__DOOR_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// CHECK DOOR OPEN -----
	CString sMODE__CHECK_DOOR_OPEN;
	int  Call__CHECK_DOOR_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// LOAD -----
	CString sMODE__LOAD;
	int  Call__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Seq__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// UNLOAD -----
	CString sMODE__UNLOAD;
	int  Call__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Seq__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// PREPLOAD -----
	CString sMODE__PREPLOAD;
	int  Call__PREPLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__PREPLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// RLSUNLOAD ----- 
	CString sMODE__RLSUNLOAD;
	int  Call__RLSUNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__RLSUNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// CYCLE ...
	CString sMODE__CYCLE;
	int  Call__CYCLE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// RF Reader/Writer ...
	CString sMODE__CID_READ;
	int  Call__CID_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__CID_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PAGE_READ;
	int  Call__PAGE_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CID_WRITE;
	int  Call__CID_WRITE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PAGE_WRITE;
	int  Call__PAGE_WRITE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// MAP -----
	CString sMODE__MAP;
	int  Call__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Update__MAP_INFO(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// CLAMP ...
	CString sMODE__CLAMP;
	int  Call__CLAMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__CLAMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// UNCLAMP ...
	CString sMODE__UNCLAMP;
	int  Call__UNCLAMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__UNCLAMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// SHUTTLE.IN ...
	CString sMODE__SHUTTLE_IN;
	int  Call__SHUTTLE_IN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__SHUTTLE_IN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// SHUTTLE_OUT ...
	CString sMODE__SHUTTLE_OUT;
	int  Call__SHUTTLE_OUT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__SHUTTLE_OUT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// EXTENDPADDLE -----
	CString sMODE__EXTENDPADDLE;
	int  Call__EXTENDPADDLE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// RETRACTPADDLE -----
	CString sMODE__RETRACTPADDLE;
	int  Call__RETRACTPADDLE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PADDLEDOWN;
	int  Call__PADDLEDOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PADDLEUP;
	int  Call__PADDLEUP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// LATCH -----
	CString sMODE__LATCH;
	int  Call__LATCH(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__LATCH(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// UNLATCH -----
	CString sMODE__UNLATCH;
	int  Call__UNLATCH(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__UNLATCH(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// CLOSEDOOR -----
	CString sMODE__CLOSEDOOR;
	int  Call__CLOSEDOOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__DOOR_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// OPENDOOR -----
	CString sMODE__OPENDOOR;
	int  Call__OPENDOOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__DOOR_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__OPENDOOR_WITH_NO_UNLATCH;
	int  Call__OPENDOOR_WITH_NO_UNLATCH(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// VACON -----
	CString sMODE__VACON;
	int  Call__VACON(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// VACOFF -----
	CString sMODE__VACOFF;
	int  Call__VACOFF(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// EXTENDSHUTTLE -----
	CString sMODE__EXTENDSHUTTLE;
	int  Call__EXTENDSHUTTLE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// RETRACTSHUTTLE -----
	CString sMODE__RETRACTSHUTTLE;
	int  Call__RETRACTSHUTTLE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// HALT -----
	CString sMODE__HALT;
	int  Call__HALT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	void Mon__ANI_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Alarm_Check__ARM_NOT_RETRACTED(CII_OBJECT__ALARM* p_alarm);

	int  Is__LOAD_CONDITION(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Is__LP_CLOSE_CND(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Update__LOAD_POS_STATE();
	//


public:
	CObj__LPx_SYS();
	~CObj__LPx_SYS();

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
