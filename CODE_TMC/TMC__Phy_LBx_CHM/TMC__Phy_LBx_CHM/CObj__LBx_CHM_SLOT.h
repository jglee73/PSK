#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_System.h"

#include "CObj__LBx_CHM_SLOT__DEF.h"


class CObj__LBx_CHM_SLOT : public __IOBJ__STD_TYPE
{
private:
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	//-------------------------------------------------------------------------
	CString sObject_Name;

	// ...
	SCX__USER_LOG_CTRL xLOG_CTRL;
	int iActive__SIM_MODE;
	//

	//-------------------------------------------------------------------------
	// INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__MSG;
	CX__VAR_STRING_CTRL  sCH__OBJ_STATUS;

	// MON.STS ...
	CX__VAR_STRING_CTRL  sCH__PUMP_VLV_OPEN_FLAG;
	CX__VAR_STRING_CTRL  sCH__PRESSURE_CTRL_FLAG;
	CX__VAR_STRING_CTRL  sCH__OUTPROC_ACTIVE_FLAG;

	// PARA ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_SLOT_ID;

	CX__VAR_ANALOG_CTRL  aCH__PARA_PREHEAT_TIME;
	CX__VAR_ANALOG_CTRL  aCH__PARA_COOLING_TIME;
	CX__VAR_ANALOG_CTRL  aCH__PARA_PREMATERIAL_SLOT;	

	// SIM.TEST ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_SIM_TEST_ACTIVE__WAIT;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_AUTO_SV_DV_CLOSE_WHEN_PUMP_VENT;

	// DOOR VALVE ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_DOOR_1_VALVE_OPEN_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_DOOR_2_VALVE_OPEN_TIMEOUT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_DOOR_1_VALVE_CLOSE_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_DOOR_2_VALVE_CLOSE_TIMEOUT;

	// SLOT VALVE ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_SLOT_1_VALVE_OPEN_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SLOT_2_VALVE_OPEN_TIMEOUT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_SLOT_1_VALVE_CLOSE_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SLOT_2_VALVE_CLOSE_TIMEOUT;

	//
	CX__VAR_ANALOG_CTRL  aCH__CFG_EXHAUST_PUMP_PRESSURE_TORR;
	CX__VAR_ANALOG_CTRL  aCH__CFG_EXHAUST_PUMP_TIMEOUT;

	CX__VAR_DIGITAL_CTRL dCH__CFG_USE_SOFT_PUMP_VALVE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_PUMP_PRESSURE_TORR;

	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_COMPLETE_STABLE_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_PUMP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VAC_PRESSURE_TORR;

	//
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_VENT_PRESSURE_TORR;

	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_PRESS_STS_TOLERANCE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_FAST_VENT_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_PRESSURE_TORR;

	CX__VAR_ANALOG_CTRL  aCH__CFG_OVER_VENT_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_EQUALIZE_VENT_TIME;
	CX__VAR_DIGITAL_CTRL dCH__CFG_EQUAL_VLV_OPEN_WHEN_ATM;

	//
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_PUMP_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_SOFT_VENT_DELAY_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PUMP_VALVE_CLOSE_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VENT_VALVE_CLOSE_DELAY_TIME;

	//
	CX__VAR_ANALOG_CTRL  aCH__CFG_GAUGE_LIMIT_PRESSURE;

	// ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_IO_OFF_MODE;

	// ...
	CX__VAR_ANALOG_CTRL  aCH__PRESSURE_TORR;
	CX__VAR_DIGITAL_CTRL dCH__PRESSURE_STATUS;

	CX__VAR_DIGITAL_CTRL dCH__LIFT_PIN_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__VAC_SNS;

	//
	int iLBx_SLOT_SIZE;
	CX__VAR_DIGITAL_CTRL dCH__SLOT_STATUS[CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__SLOT_TITLE[CFG_LBx__SLOT_SIZE];

	CX__VAR_STRING_CTRL  sCH__SLOT_LOTID[CFG_LBx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dCH__SLIT_VALVE_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__SLIT_VALVE_STATUS_X[CFG_LBx__SLOT_SIZE];

	CX__VAR_STRING_CTRL  sCH__SLIT_VALVE_LOCK_FLAG;
	CX__VAR_STRING_CTRL  sCH__SLIT_VALVE_LOCK_FLAG_X[CFG_LBx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dCH__DOOR_VALVE_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__DOOR_VALVE_STATUS_X[CFG_LBx__SLOT_SIZE];

	//
	SCX__ASYNC_TIMER_CTRL xI_ASYNC_TIMER;
	CX__VAR_ANALOG_CTRL  aCH__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__PUMPING_ELAPSED_TIME;
	CX__VAR_ANALOG_CTRL  aCH__VENTING_ELAPSED_TIME;

	CX__VAR_ANALOG_CTRL  aCH_SV_UP__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH_SV_DOWN__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH_SV_OPEN__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH_SV_CLOSE__TIME_COUNT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ATM_HIGH_PRESSURE_TORR;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MAX_SV_OPEN_DIFF_PRESS;
	CX__VAR_DIGITAL_CTRL dCH__CFG_PUMP_DOWN_OPTION;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VAC_LOWER_TOLERANCE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_VAC_UPPER_TOLERANCE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_HEATER_USE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HEATING_TIME;
	CX__VAR_STRING_CTRL  sCH__APP_HEATING_TIMECOUNT;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HEATER_SOFT_VENT_USE;

	// TAS Channel ...
	CX__VAR_STRING_CTRL  sCH__TAS_RESET_REQ_SLOT[CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT_SLOT[CFG_ACT__SIZE][CFG_LBx__SLOT_SIZE];
	//


	//-------------------------------------------------------------------------
	// EXTERNAL PROPERTY

	// LINK.LLx_ID ...
	int iLLx_ID;

	// OBJ NNAME ...
	CString m_sLBx__MODULE_NAME;

	// DB OBJ ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_SETUP_TEST_MODE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_SETUP_AUTO_VENTING_PUMPING;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_SETUP_LLx_DOOR_SLOT_VLV_CONTROL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_TRANSFER_MODE;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_REF_ATM_PRESSURE;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_REF_VAC_PRESSURE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_SLOT_VLV_CLOSE_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_SLOT_VLV_OPEN_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_DOOR_VLV_CLOSE_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_DOOR_VLV_OPEN_TIME;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_LLx_SLOW_VENT_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_LLx_FAST_VENT_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_LLx_SLOW_PUMP_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_SIM_LLx_FAST_PUMP_TIME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_SV_EXIST_FLAG;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_LIFT_PIN_EXIST_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_LIFT_PIN_DOWM_MODE_AFTER_DOOR_CLOSE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_LIFT_PIN_UP_MODE_AFTER_HEATING;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_LIFT_PIN_UP_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_LIFT_PIN_DOWN_TIMEOUT;

	// OBJ__ATM_ROBOT ...
	bool bActive__ATM_RB_OBJ_CTRL;
	CII_EXT_OBJECT__CTRL *pATM_RB__OBJ_CTRL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ATM_RB__MON_ACTIVE_ACTION_TO_LL;

	// OBJ__VAC_ROBOT ...
	bool bActive__VAC_RB_OBJ_CTRL;
	CII_EXT_OBJECT__CTRL *pVAC_RB__OBJ_CTRL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__VAC_RB__MON__LLx_ARM_STATE;

	// LINK OBJECT ...
	bool bActive__OBJ_GAS;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__GAS;

	bool bActive__OBJ_VAT;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__VAT;

	// I/O OBJECT ...
	// VENT VLV
	bool bActive__SOFT_VENT_VLV;
	CX__VAR_DIGITAL_CTRL doEXT_CH__SOFT_VENT_VLV__SET;

	CX__VAR_DIGITAL_CTRL doEXT_CH__FAST_VENT_VLV__SET;

	bool bActive__ATM_EQUAL_VLV;
	CX__VAR_DIGITAL_CTRL doEXT_CH__ATM_EQUAL_VLV__SET;

	// PUMP VLV
	CX__VAR_DIGITAL_CTRL doEXT_CH__SOFT_PUMP_VLV__SET;
	CX__VAR_DIGITAL_CTRL doEXT_CH__FAST_PUMP_VLV__SET;

	// DI.FR.VLV 
	bool bActive__DI_FR_VLV_OPEN;
	CX__VAR_DIGITAL_CTRL diEXT_CH__DI_FR_VLV_OPEN;

	bool bActive__DI_FR_VLV_CLOSE;
	CX__VAR_DIGITAL_CTRL diEXT_CH__DI_FR_VLV_CLOSE;

	// DI.SR.VLV 
	bool bActive__DI_SR_VLV_OPEN;
	CX__VAR_DIGITAL_CTRL diEXT_CH__DI_SR_VLV_OPEN;

	bool bActive__DI_SR_VLV_CLOSE;
	CX__VAR_DIGITAL_CTRL diEXT_CH__DI_SR_VLV_CLOSE;

	// SLOT CONTROL ...
	// SV 
	CX__VAR_DIGITAL_CTRL doEXT_CH__LLx__SV_OPEN_X[CFG_LBx__SLOT_SIZE];
	CX__VAR_DIGITAL_CTRL doEXT_CH__LLx__SV_CLOSE_X[CFG_LBx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL diEXT_CH__LLx__SV_OPEN_X[CFG_LBx__SLOT_SIZE];
	CX__VAR_DIGITAL_CTRL diEXT_CH__LLx__SV_CLOSE_X[CFG_LBx__SLOT_SIZE];

	// DV 
	CX__VAR_DIGITAL_CTRL doEXT_CH__LLx__DV_OPEN_X[CFG_LBx__SLOT_SIZE];
	CX__VAR_DIGITAL_CTRL doEXT_CH__LLx__DV_CLOSE_X[CFG_LBx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL diEXT_CH__LLx__DV_OPEN_X[CFG_LBx__SLOT_SIZE];
	CX__VAR_DIGITAL_CTRL diEXT_CH__LLx__DV_CLOSE_X[CFG_LBx__SLOT_SIZE];

	// GAUGE VLV ...
	bool bAtive__GAUGE_VLV;
	CX__VAR_DIGITAL_CTRL doEXT_CH__GAUGE_VLV;

	// ROBOT ARM SNS ...
	int iData__VAC_RB_ARM_RNE;
	CX__VAR_DIGITAL_CTRL diEXT_CH__VAC_RB_RNE_X[_CFG_RBx__ARM_RNE_SIZE];

	int iData__ATM_RB_ARM_RNE;
	CX__VAR_DIGITAL_CTRL diEXT_CH__ATM_RB_RNE_X[_CFG_RBx__ARM_RNE_SIZE];

	CString sDATA__RNE_ON;
	CString sDATA__RNE_OFF;

	// WAFER.SLIDE SENSOR ...
	int iData__WAFER_SLIDE_OUT;
	CX__VAR_DIGITAL_CTRL diEXT_CH__WAFER_SKIDE_OUT_X[_CFG__WAFER_OUT_SIZE];

	// PUMP OBJECT ...
	CII_EXT_OBJECT__CTRL *pPUMP__OBJ_CTRL;

	CX__VAR_STRING_CTRL  sEXT_CH__MON_PUMP_COMM_STS;
	CX__VAR_STRING_CTRL  sEXT_CH__MON_PUMP_RUN_STS;

	// GAUGE OBJECT ...
	CX__VAR_ANALOG_CTRL  aiEXT_CH__LBx__PRESSURE_TORR;

	bool bActive__LBx__EXHAUST_PRESSURE;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__LBx__EXHAUST_PRESSURE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__PHY_TM__PRESS_STS;
	CX__VAR_ANALOG_CTRL  aEXT_CH__PHY_TM__PRESS_TORR;

	// DI.SNS ...
	bool bActive__ATM_SNS_Virtual_Type;
	CX__VAR_DIGITAL_CTRL diEXT_CH__LBx__ATM_SNS;
	CX__VAR_DIGITAL_CTRL diEXT_CH__LBx__VAC_SNS;

	CString sDATA__ATM_ON;
	CString sDATA__ATM_OFF;

	CString sDATA__VAC_ON;
	CString sDATA__VAC_OFF;

	// LID ...
	int iData__LID_SIZE;
	CX__VAR_DIGITAL_CTRL diEXT_CH__LID_CLOSE_SNS_X[_CFG_LLx__SLOT_SIZE];

	// LIFT_PIN ...
	bool bActive__LIFT_PIN;

	CX__VAR_DIGITAL_CTRL doEXT_CH__LBx__LIFT_PIN_UP;
	CX__VAR_DIGITAL_CTRL doEXT_CH__LBx__LIFT_PIN_DOWN;

	CX__VAR_DIGITAL_CTRL diEXT_CH__LBx__LIFT_PIN_UP;
	CX__VAR_DIGITAL_CTRL diEXT_CH__LBx__LIFT_PIN_DOWN;
	//


	//------------------------------------------------------------------------------
	// INIT ----- 
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// CL.PUMP_VLV -----
	CString sMODE__CL_PUMP_VLV;
	int  Call__CL_PUMP_VLV(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// OP.PUMP_VLV -----
	CString sMODE__OP_PUMP_VLV;
	int  Call__OP_PUMP_VLV(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// PUMP -----
	CString sMODE__PUMP;
	int  Call__PUMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__PUMP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// VENT -----
	CString sMODE__VENT;
	int  Call__VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  _Fnc__VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  _Sub__VENT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// DOOR VLV CLOSE -----
	CString sMODE__DV_CLOSE;
	int  Call__DV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	int  Fnc__DV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	// DOOR VLV OPEN -----
	CString sMODE__DV_OPEN;
	int  Call__DV_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	int  Fnc__DV_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	// SLIT VLV CLOSE -----
	CString sMODE__SV_CLOSE;
	int  Call__SV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	int  Fnc__SV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	// SLIT VLV OPEN -----
	CString sMODE__SV_OPEN;
	int  Call__SV_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	int  Fnc__SV_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	// ALL GAS VLV CLOSE -----
	CString sMODE__ALL_GAS_VLV_CLOSE;
	int  Call__ALL_GAS_VLV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// LIFT_PIN UP / DOWN-----
	CString sMODE__LIFT_PIN_UP;
	int  Call__LIFT_PIN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__LIFT_PIN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__LIFT_PIN_DOWN;
	int  Call__LIFT_PIN_DOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__LIFT_PIN_DOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Is__LIFT_PIN_UP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Is__LIFT_PIN_DOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);


	// SV_TRANSFER -----
	CString sMODE__SV_TRANSFER_OPEN;
	int  Call__SV_TRANSFER_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);
	int  Fnc__SV_TRANSFER_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	CString sMODE__SV_TRANSFER_CLOSE;
	int  Call__SV_TRANSFER_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);
	int  Fnc__SV_TRANSFER_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	// DV_TRANSFER -----
	CString sMODE__DV_TRANSFER_OPEN;
	int  Call__DV_TRANSFER_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);
	int  Fnc__DV_TRANSFER_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);

	CString sMODE__DV_TRANSFER_CLOSE;
	int  Call__DV_TRANSFER_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);
	int  Fnc__DV_TRANSFER_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int slot_id);


	// PREPMATER -----
	CString sMODE__PREPMATER;
	int  Call__PREPMATER(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// COMPMATER -----
	CString sMODE__COMPMATER;
	int  Call__COMPMATER(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);


	// IN_PROC -----
	CString sMODE__IN_PROC;
	int  Call__IN_PROC(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__IN_PROC(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// OUT_PROC -----
	CString sMODE__OUT_PROC;
	int  Call__OUT_PROC(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__OUT_PROC(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// AUTO CTRL ---------------
	// PUMP VLV CLOSE -----
	CString sMODE__AUTO_PUMP_VLV_CLOSE;
	int  Call__AUTO_PUMP_VLV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__AUTO_PUMP_VLV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// TIME TEST ...
	CString sMODE__TIME_TEST;
	int  Call__TIME_TEST(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	//

	// ...
	bool Is__ALL_DV_OPEN();
	bool Is__ANY_DV_OPEN();
	bool Is__SLOT_DV_OPEN();
	bool Is__SLOT_DV_CLOSE();

	int  Set_IO__DV_OPEN();
	int  End_IO__DV_OPEN();

	int  Set_IO__DV_CLOSE();
	int  End_IO__DV_CLOSE();

	// ...
	bool Is__ALL_SV_OPEN();
	bool Is__ALL_SV_CLOSE();
	bool Is__ANY_SV_OPEN();
	bool Is__SLOT_SV_OPEN();
	bool Is__SLOT_SV_CLOSE();

	int  Set_IO__SV_OPEN();
	int  End_IO__SV_OPEN();

	int  Set_IO__SV_CLOSE();
	int  End_IO__SV_CLOSE();

	// ...
	int  Check__PRESSURE_ATM(CII_OBJECT__ALARM* p_alarm, const int alarm_id);
	int  Check__PRESSURE_ATM_TO_DV_OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const int alarm_id);

	int  Check__PRESSURE_VAC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Check__LLx_LID__CLOSE(CII_OBJECT__ALARM* p_alarm, const CString& act_name);
	int  Check__TRANSFER_VLV__CLOSE(CII_OBJECT__ALARM* p_alarm,	const CString& act_name);

	int  Check__VENT_ALL_VLV__CLOSE(CII_OBJECT__ALARM* p_alarm);
	int  Check__PUMP_ALL_VLV__CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Check__FR_VLV__OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Check__PUMP_VLV__OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	void Update__PUMP_VLV_STS(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Is_SV_CLOSE_CONDITION(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Is_DV_CLOSE_CONDITION(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__VENT_ALL_VLV__CLOSE(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__VENT_ALL_VLV__CLOSE_WITHOUT_EQUAL_VLV(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__PUMP_ALL_VLV__CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__PUMP_SOFT_VLV__OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Fnc__PUMP_SOFT_VLV__CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Fnc__PUMP_FAST_VLV__OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__VENT_SOFT_VLV__OPEN(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__VENT_SOFT_VLV__CLOSE(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__VENT_FAST_VLV__OPEN(CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Sub__SV_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const double dblTimeout);
	int  Sub__SV_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const double dblTimeout);

	int  Check__SV_OPEN_MAX_DIFFERENTIAL_PRESS(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  _Update__ACTION_MIN_MAX(const int db_i,const int slot_i, const double cur_sec);
	int  _Fnc__ACTION_MIN_MAX(const int db_i,const int slot_i, const double cur_sec);

	// OBJ FNC ...
	int  _Fnc__OBJ_GAS__ALL_CLOSE();

	int  _Fnc__OBJ_VAT__OPEN();
	int  _Fnc__OBJ_VAT__CLOSE();
	//

	//------------------------------------------------------------------------------
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Fnc__INTERLOCK(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Update__PRESSURE_STS(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Update__SV_STS(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Update__DV_STS(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Update__LIFT_PIN_STS(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Check__SR_VALVE_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check);
	int  Check__SR_VALVE_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check);
	int  _Check__SR_VALVE_STATE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check, const bool active__close_check);

	int  Check__FR_VALVE_CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check);
	int  Check__FR_VALVE_OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check);
	int  _Check__FR_VALVE_STATE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active__wait_check, const bool active__close_check);

	// ...
	void Fnc__MSG(const CString &sMsg);		// sCH__MSG
	void Fnc__LOG(const CString &sMsg);
	//

public:
	CObj__LBx_CHM_SLOT();
	~CObj__LBx_CHM_SLOT();

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
