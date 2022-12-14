#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_Def.h"

#include "CObj__CHM_FNC__DEF.h"


#define  LEAK_CHECK__ITEM_SIZE						7


class CObj__CHM_FNC : public __IOBJ__STD_TYPE
{
private:
	//------------------------------------------------------------
	CString sObject_Name;

	CCommon_Error__USER_FNC mERROR__USER_FNC;

	// ...
	SCX__USER_LOG_CTRL xLOG_CTRL;
	int iActive__SIM_MODE;

	CUIntArray iLIST_ALID__PART;

	bool bActive__GAS_CLOSE_SKIP;
	//


	//------------------------------------------------------------
	// INTERNAL PROPERTY

	CX__VAR_DIGITAL_CTRL dCH__OBJ_CTRL;

	// OBJ PARAMETER ...
	CX__VAR_STRING_CTRL	 sCH__OBJ_STATUS;
	CX__VAR_STRING_CTRL	 sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  sCH__OBJ_TIMER;

	CX__VAR_STRING_CTRL	 sCH__CUR_OBJ_MODE;

	// MON PART ...
	CX__VAR_DIGITAL_CTRL dCH__MON_PART_ERROR_ACTIVE;

	// MON PARAMETER ...
	CX__VAR_STRING_CTRL  sCH__MON_PUMPING_STATE;

	CX__VAR_STRING_CTRL  sCH__TRANSFER_BALLAST_FLAG;
	CX__VAR_STRING_CTRL  sCH__PARA_XFER_BALLAST_WAIT_SKIP_FLAG;

	CX__VAR_STRING_CTRL  sCH__ACTIVE_VENTING_STATE;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_PROCESS_READY_CTRL_AFTER_CHM_PUMPING;
	
	CX__VAR_DIGITAL_CTRL dCH__CFG_USE_HIGH_VAC_PUMPING;

	// REFERENCE PRESSURE ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_REF_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VAC_REF_PRESSURE;

	// SENSOR PARAMETER ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_SNS_REF_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VAC_SNS_REF_PRESSURE;

	// FAST-VENTING PARAMETER ...
	CX__VAR_ANALOG_CTRL	 aCH__CFG_FAST_VENT_PRESSURE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_FAST_VENT_GAUGE_CHECK;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_VENT_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_VENT_ATM_SNS_ON_TIMEOUT;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_FAST_VENT_OVER_TIME;

	// SOFT-VENTING PARAMETER ...
	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_VENT_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_VAC_SNS_OFF_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_OVER_TIME;

	// SOFT-PUMPING PARAMETER ...
	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_PUMP_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_ATM_SNS_OFF_TIMEOUT;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_SOFT_PUMP_OVER_TIME;

	// FAST-PUMPING PARAMETER ...
	CX__VAR_ANALOG_CTRL	 aCH__CFG_FAST_PUMP_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_PUMP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_PUMP_VAC_SNS_ON_TIMEOUT;

	// HIGH_VAC-PUMPING PARAMETER ...
	CX__VAR_ANALOG_CTRL	 aCH__CFG_HIGH_VAC_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HIGH_VAC_TIMEOUT;

	// FORELINE PARAMETER ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_FORELINE_PUMPING_TIMEOUT;

	// PURGE PARAMETER ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_PURGE_CYCLE_COUNT;
	CX__VAR_STRING_CTRL  sCH__CUR_PURGE_CYCLE_COUNT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PURGE_UP_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PURGE_DOWN_PRESSURE;

	CX__VAR_ANALOG_CTRL	 aCH__CFG_ADD_PUMP_TIME_SECONDS_FOR_PP;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ADD_PURGE_TIME_SECONDS_FOR_PP;

	// LEAK-CHECK PARAMETER ...
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__ACTIVE_CALL_BY_CTC;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__CUR_TIME_COUNT;

	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__CFG_OVER_PUMPING_TIME;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__CFG_STABLE_TIME;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__CFG_TIME_MIN;
	
	CX__VAR_DIGITAL_CTRL dCH__LEAK_CHECK__CFG_VAT_VLV_POS_MOVING;
	CX__VAR_DIGITAL_CTRL dCH__LEAK_CHECK__ACTIVE_VAT_VLV_POS_MOVING;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__APP_DATE_FDC_MONTH;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__APP_START_TIME;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__APP_END_TIME;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__BASE_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__PRESSUREx_mTORR[LEAK_CHECK__ITEM_SIZE];
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__RATEx_mTORR_Per_MIN[LEAK_CHECK__ITEM_SIZE];
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__RESULT_mTORR_Per_MIN;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__VAT_MOVE__START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__VAT_MOVE__RESULT_PRESSURE_mTORR;

	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_MESSAGE;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_START_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_RATE_mTORR_Per_MIN;
	CX__VAR_STRING_CTRL  sCH__LEAK_CHECK__LOG_RESULT_mTORR_Per_MIN;

	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__MAX_PRESSURE_mTORR;
	CX__VAR_ANALOG_CTRL  aCH__LEAK_CHECK__CFG_RESULT_POSTING;

	// TRANSFER.BALLAST PARAMETER ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_TRANSFER_BALLAST_ENABLED;

	// CHAMBER.BALLAST PARAMETER ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_CHAMBER_BALLAST_ENABLED;

	// AUTO.LEARN PARAMETER ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_BEFORE_AUTO_LEARNING_DELAY_TIME;

	// CFG : TMP ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_BEFORE_VENT_TURBO_PUMP_OFF;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PUMP_TURBO_STABLE_TIME;
	//


	//------------------------------------------------------------
	// EXTERNAL PROPERTY

	// OBJ - DB_INF ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__ACTIVE_CALL_BY_CTC;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SYSTEM_TRANSFER_MODE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__PMC_SLIT_VLV_STS;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CHM_PRESSURE_TORR;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CHM_PRESSURE_mTORR;
	CX__VAR_STRING_CTRL  sEXT_CH__CHM_PRESSURE_STATE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__PMP_PRESSURE_TORR;
	CX__VAR_STRING_CTRL  sEXT_CH__PMP_PRESSURE_STATE;
	CX__VAR_STRING_CTRL  sEXT_CH__PMP_VAC_SNS;

	CX__VAR_DIGITAL_CTRL dEXT_CH__WAFER_SLOT01_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DECHUCK_CTRL_MODE;

	// OBJ - DB_SYS ...
	CX__VAR_STRING_CTRL  sEXT_CH__SIM_PRESSURE_TORR;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CTC_LEAK_CHECK_USE_FLAG;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_OVER_PUMPING_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_STABLE_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CTC_LEAK_CHECK_TIME_MIN;

	CX__VAR_STRING_CTRL  sEXT_CH__SYSTEM_INTERLOCK_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_PMC_ATM_MAINT_ACTIVE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_CHM_MANOMETER_PRESS_SW1_SETTING;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_CHM_MANOMETER_PRESS_SW2_SETTING;

	// OBJ : PMC LOG ...
	bool bActive__PMC_LOG;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__PMC_LOG;

	CX__VAR_STRING_CTRL  xEXT_CH__PMC_LOG__SUB_DIR;
	CX__VAR_STRING_CTRL  xEXT_CH__PMC_LOG__FILE_NAME;
	CX__VAR_ANALOG_CTRL  xEXT_CH__PMC_LOG__SAMPLING_PERIOD;

	// OBJ : TRANSFER ...
	bool bActive__TRANSFER_OBJ;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__TRANSFER;

	// VAC.VLV INFO ...
	int Call__VAC_VLV__ALL_CLOSE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm, const bool active__exhaust_vlv = true, const bool active__apc_vlv = true);
	int Call__VAC_VLV__SR_OPEN(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Call__VAC_VLV__FR_OPEN(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	
	int Call__VAC_VLV__EXHAUST_OPEN(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Call__VAC_VLV__EXHAUST_CLOSE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	int Call__VAC_VLV__APC_CLOSE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Call__VAC_VLV__APC_OPEN(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Call__VAC_VLV__APC_POSITION(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm, const double set_pos);

	int Call__VAC_VLV__APC_BALLAST_CTRL(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm, const bool active_xfer);
	int Run__VAC_VLV__APC_BALLAST_CTRL(const bool active_xfer);

	// OBJ : PHY_VAC_VLV ...
	bool bActive__PHY_VAC_VLV;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__PHY_VAC_VLV;

	CX__VAR_STRING_CTRL  sEXT_CH__VAC_VLV__MON_PUMPING_STATE;

	// OBJ : VAT ...
	bool bActive__VAT_OBJ;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__VAT;

	CX__VAR_ANALOG_CTRL  aEXT_CH__VAT_PARA_POSITION;
	CX__VAR_ANALOG_CTRL  aEXT_CH__VAT_PARA_PRESSURE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__VAT_CUR_POSITION;

	// OBJ : GAS_VLV ...
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__GAS_VLV;

	CX__VAR_STRING_CTRL sEXT_CH__GAS_VLV__PARA_MFC_INDEX;

	// OBJ : MFCx ...
	int iDATA__MFC_SIZE;

	CX__VAR_STRING_CTRL  sEXT_CH__CFG_GAS_NAME_X[_CFG__MFC_SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_MFC_USE_X[_CFG__MFC_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LEAK_CHECK_USE_X[_CFG__MFC_SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__REPORT_LEAK_CHECK_STATE_X[_CFG__MFC_SIZE];

	// OBJ : ESC ...
	bool bActive__ESC_OBJ;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__ESC;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ESC_MON_CHUCK_STATUS;

	// OBJ : TURBO_PUMP
	bool bActive__OBJ_CTRL__TURBO_PUMP;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__TURBO_PUMP;

	CX__VAR_DIGITAL_CTRL dEXT_CH__TURBO_PUMP__POWER_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__TURBO_PUMP__MON_PUMP_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__TURBO_PUMP__ACTIVE_INTERLOCK_SKIP_FORELINE_VAC;

	// OBJ : DRY_PUMP
	bool bActive__DRY_PUMP;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__DRY_PUMP;

	CX__VAR_DIGITAL_CTRL dEXT_CH__DRY_PUMP__POWER_SNS;

	// Channel Link ...
	bool bActive__CHM_SLOT_VLV_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_SLOT_VLV_STATE;

	bool bActive__CHM_SHUTTER_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_SHUTTER_STATE;

	//
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_VAC_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_ATM_SNS;

	bool bActive__CHM_LID_STATE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_LID_STATE;
	CString sCHM_LID__CLOSE_STATE;
	//


	//------------------------------------------------------------
	int _Check__CONTROL_INTERLOCK(const CString& mode, CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// ...
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__ALL_GAS_LINE_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__ALL_VAC_LINE_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__MAINT;
	int Call__MAINTMODE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PUMPING;
	CString sMODE__LOW_VAC_PUMP;
	int Call__LOW_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Check__LOW_VAC_PUMP();
	int Fnc__LOW_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int high_vac_flag,const int purge_flag);
	int _Fnc__LOW_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int high_vac_flag,const int purge_flag);
	
	int _Fnc__SOFT_LOW_VAC(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int purge_flag);

	//
	CString sMODE__HIGH_VAC_PUMP;
	int Call__HIGH_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__HIGH_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int _Fnc__HIGH_VAC_PUMP(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__PROC_READY;
	int Call__PROC_READY(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__CLOSE_VAC_LINE;
	int Call__CLOSE_VAC_LINE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__VENT;
	int Call__VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int purge_flag);

	int _Fnc__SOFT_VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int purge_flag);
	int _Fnc__FAST_VENT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const int purge_flag);

	//
	CString sMODE__LEAK_CHECK_CHM;
	CString sMODE__LEAK_CHECK_GAS;
	int Call__LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const bool active__gas_leak);

	int Fnc__LEAK_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const bool active__ctc_call, const bool active__gas_leak,const int mfc_index = -1);
	int Fnc__LEAK_CHECK__VAT_VLV_POS_MOVE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const bool active__ctc_call);

	//
	CString sMODE__PURGE;
	int Call__PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Seq__PURGE_VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int Seq__PURGE_PUMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const int cycle_count);

	//
	CString sMODE__SLOT_OPEN;
	int Call__SLOT_OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__SLOT_CLOSE;
	int Call__SLOT_CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// PICK ...
	CString sMODE__PICK_READY;
	int Call__PICK_READY(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PICK_X_READY;
	int Call__PICK_X_READY(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PICK_COMPLETE;
	int Call__PICK_COMPLETE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PICK_X_COMPLETE;
	int Call__PICK_X_COMPLETE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// PLACE ...
	CString sMODE__PLACE_READY;
	int Call__PLACE_READY(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PLACE_X_READY;
	int Call__PLACE_X_READY(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PLACE_COMPLETE;
	int Call__PLACE_COMPLETE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PLACE_X_COMPLETE;
	int Call__PLACE_X_COMPLETE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__TRANSFER_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__TRANSFER_END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	// 
	CString sMODE__CHM_BALLAST_START;
	int Call__CHM_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__CHM_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__TRANS_BALLAST_START;
	int Call__TRANS_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__TRANS_BALLAST_START(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);	

	CString sMODE__BALLAST_END;
	int Call__BALLAST_END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__BALLAST_END(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__APC_AUTO_LEARN;
	int Call__APC_AUTO_LEARN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__APC_AUTO_LEARN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);


	// Sub Function .....
	int Fnc__TURBO_PUMP_ON(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Fnc__DRY_PUMP_ON(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__PUMP_CTRL(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm,const int mode);

	// Additional Sub Function
	int Seq__LINE_PUMP(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Fnc__VENT_COMPLETE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);


	// MON Function .....
	void Mon__PRESSURE_STATUS(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);


	// OBJ_VAT.CTRL ...
	int VAT__CALL_OBJECT(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm, const CString& obj_mode);
	int VAT__RUN_OBJECT(const CString& obj_mode);
	//


public:
	CObj__CHM_FNC();
	~CObj__CHM_FNC();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_fnc_ctrl);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
