#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_Def.h"

#include "CClass__Error_Timer.h"


#define  _VAT_CTRL_TYPE__OBJ				1
#define  _VAT_CTRL_TYPE__IO					2
#define  _VAT_CTRL_TYPE__HEXA				3


class CObj__VAT_IO : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	SCX__USER_LOG_CTRL xI_LOG_CTRL;

	int iActive__SIM_MODE;

	CUIntArray iLIST_ALID__VAT;
	//

	//-------------------------------------------------------------------------
	// OBJ ...
	CX__VAR_STRING_CTRL   sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL   sCH__OBJ_STATUS;

	CX__VAR_STRING_CTRL   sCH__CUR_MODE;

	// PARA ...
	CX__VAR_ANALOG_CTRL   aCH__PARA_PRESSURE;
	CX__VAR_ANALOG_CTRL   aCH__PARA_PRESSURE_mTORR;

	CX__VAR_ANALOG_CTRL   aCH__PARA_POSITION;
	CX__VAR_ANALOG_CTRL   aCH__PARA_HOLD_SEC;

	// MON.PART ...
	CX__VAR_DIGITAL_CTRL  dCH__MON_VAT_CTRL_ACTIVE;
	CX__VAR_DIGITAL_CTRL  dCH__MON_VAT_ERROR_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__MON_VAT_PRESSURE_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_VAT_PRESSURE_ABORT_ACTIVE;

	// MON ...
	CX__VAR_STRING_CTRL   sCH__MON_SET_PRESSURE_TORR;
	CX__VAR_STRING_CTRL   sCH__MON_SET_PRESSURE_mTORR;

	CX__VAR_STRING_CTRL   sCH__MON_PRESSURE_TORR;
	CX__VAR_STRING_CTRL   sCH__MON_PRESSURE_mTORR;

	CX__VAR_STRING_CTRL   sCH__MON_SET_POSITION;
	CX__VAR_STRING_CTRL   sCH__MON_POSITION;

	CX__VAR_STRING_CTRL   sCH__MON_SET_HOLD_SEC;

	CX__VAR_STRING_CTRL   sCH__MON_DO_APC_CTRL_MODE;
	CX__VAR_STRING_CTRL   sCH__MON_AO_APC_SETPOINT_DATA;
	CX__VAR_STRING_CTRL   sCH__MON_DO_APC_SETPOINT_TYPE;

	CX__VAR_STRING_CTRL   sCH__MON_DI_APC_STATE;
	CX__VAR_STRING_CTRL   sCH__MON_DI_APC_VLV_CLOSE;
	CX__VAR_STRING_CTRL   sCH__MON_DI_APC_VLV_OPEN;
	CX__VAR_STRING_CTRL   sCH__MON_DI_APC_VLV_STATE;

	// MON : STABLE_IDLE ...
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_PRESSURE_CHECK_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_PRESSURE_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_PRESSURE_ABORT_ACTIVE;

	//
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_STABLE_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_STABLE_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_STABLE_DELAY_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_STABLE_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_WARNING_CHECK_TIME;

	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_ABORT_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_ABORT_MAX;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_PRESSURE_ABORT_CHECK_TIME;

	// MON : STABLE_PROC ...
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_PRESSURE_CHECK_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_PRESSURE_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_PRESSURE_ABORT_ACTIVE;

	//
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_STABLE_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_STABLE_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_STABLE_DELAY_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_STABLE_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_WARNING_CHECK_TIME;

	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_ABORT_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_ABORT_MAX;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_PRESSURE_ABORT_CHECK_TIME;

	// CFG : TIMEOUT ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_TIMEOUT_OPEN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TIMEOUT_CLOSE;

	// CFG : SYSTEM ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_USE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_MIN_VALUE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_MAX_VALUE;
	CX__VAR_STRING_CTRL  sCH__CFG_PRESSURE_MAX_mTORR;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_DEC_VALUE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_STABLE_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_STABLE_CHECK_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_WARNING_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_ABORT_TIMEOUT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_WARNING_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_PRESSURE_WARNING_BAND;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PRESSURE_ABORT_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_PRESSURE_ABORT_BAND;

	CX__VAR_ANALOG_CTRL  aCH__CFG_Zero_Setpoint_Tolerance_Compensation;

	CX__VAR_ANALOG_CTRL  aCH__CFG_OPEN_INTERLOCK_OVER_PRESSURE;

	// HIGH.LIMIT CHAMBER PRESSURE ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_HIGH_LIMIT_ATM_SENSOR_APPLY;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HIGH_LIMIT_VAC_SENSOR_APPLY;

	CX__VAR_DIGITAL_CTRL dCH__CFG_HIGH_LIMIT_CHM_PRESSURE_APPLY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HIGH_LIMIT_CHM_PRESSURE_TORR;

	// TRANSFER.BALLAST PARAMETER ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_TRANSFER_BALLAST_CTRL_MODE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_BALLAST_POSITION;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_BALLAST_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_BALLAST_TOL_PRESSURE_MIN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_BALLAST_TOL_PRESSURE_MAX;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TRANSFER_BALLAST_TOL_TIMEOUT;

	// CHAMBER.BALLAST PARAMETER ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_CHAMBER_BALLAST_CTRL_MODE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHAMBER_BALLAST_POSITION;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHAMBER_BALLAST_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHAMBER_BALLAST_TOL_PRESSURE_MIN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHAMBER_BALLAST_TOL_PRESSURE_MAX;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHAMBER_BALLAST_TOL_TIMEOUT;
	//


	//-------------------------------------------------------------------------
	// DB_SYS ...
	CX__VAR_DIGITAL_CTRL  dEXT_CH__CFG_PMC_ATM_MAINT_ACTIVE;

	CX__VAR_STRING_CTRL   sEXT_CH__SIM_PRESSURE_TORR;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_SYSTEM_PROCESS_ACTIVE;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_SYSTEM;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_SYSTEM;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_CHAMBER;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_CHAMBER;

	// VAT_CTRL.TYPE ...
	int iDATA__VAT_CTRL_TYPE;

	// LINK : OBJ ...
	CII_EXT_OBJECT__CTRL* pOBJ_CTRL__VAT;

	CString sVAT_CMMD__INIT;
	CString sVAT_CMMD__CLOSE;
	CString sVAT_CMMD__OPEN;
	CString sVAT_CMMD__POSITION;
	CString sVAT_CMMD__PRESSURE;

	int iPARA__PRESSURE_UNIT;

	CX__VAR_ANALOG_CTRL   aEXT_CH__VAT__PARA_PRESSURE_VALUE;
	CX__VAR_ANALOG_CTRL   aEXT_CH__VAT__PARA_POSITION_PER;

	CX__VAR_ANALOG_CTRL   aEXT_CH__VAT__CUR_PRESSURE_VALUE;
	CX__VAR_ANALOG_CTRL   aEXT_CH__VAT__CUR_POSITION_PER;

	// LINK : HEXA ...
	int iLINK_HEXA__MAX_VALUE;

	CX__VAR_STRING_CTRL   sEXT_CH__SO_APC_CTRL_MODE;
	CX__VAR_STRING_CTRL   sEXT_CH__SO_APC_SETPOINT_DATA;
	CX__VAR_STRING_CTRL   sEXT_CH__SO_APC_SETPOINT_TYPE;

	CX__VAR_STRING_CTRL   sEXT_CH__SI_APC_STATE_HEXA;
	CX__VAR_STRING_CTRL   sEXT_CH__SI_APC_PRESSURE;
	CX__VAR_STRING_CTRL   sEXT_CH__SI_APC_POSITION;

	// LINK : IO. ...
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DO_APC_CTRL_MODE;
	CX__VAR_ANALOG_CTRL   aEXT_CH__AO_APC_SETPOINT_DATA;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DO_APC_SETPOINT_TYPE;

	CX__VAR_ANALOG_CTRL   aEXT_CH__AI_APC_PRESSURE;
	CX__VAR_ANALOG_CTRL   aEXT_CH__AI_APC_POSITION;

	bool bActive__DI_APC_STATE_IO;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_APC_STATE_IO;

	bool bActive__SI_APC_STATE_IO;
	CX__VAR_STRING_CTRL   sEXT_CH__SI_APC_STATE_IO;

	bool bActive__DI_APC_VLV_CLOSE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_APC_VLV_CLOSE;

	bool bActive__DI_APC_VLV_OPEN;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_APC_VLV_OPEN;

	bool bActive__DI_APC_VLV_STATE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_APC_VLV_STATE;

	// LINK.IO ...
	// DI.ATM_SENSOR
	bool bActive__DI_ATM_SENSOR;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_ATM_SENSOR;

	// DI.VAC_SENSOR
	bool bActive__DI_VAC_SENSOR;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_VAC_SENSOR;

	// AU.CHM_PRESSURE_TORR
	bool bActive__AI_CHM_PRESSURE_TORR;
	CX__VAR_ANALOG_CTRL   aEXT_CH__AI_CHM_PRESSURE_TORR;

	// LINK_INTERLOCK ...
	bool bActive__DI_TMP_LINE_ACTIVE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__DI_TMP_LINE_ACTIVE;
	//


	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__OPEN;
	int Call__OPEN(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__CLOSE;
	int Call__CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Interlock__CLOSE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__POSITION;
	int Call__POSITION(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int Fnc__POSITION(CII_OBJECT__ALARM *p_alarm, const double set_value);

	CString sMODE__PRESSURE;
	int Call__PRESSURE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__PRESSURE_mTORR;
	int Call__PRESSURE_mTORR(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Fnc__PRESSURE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const double set_value);

	//
	CString sMODE__BALLAST_TRANSFER;
	int Call__BALLAST_TRANSFER(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	
	CString sMODE__BALLAST_CHAMBER;
	int Call__BALLAST_CHAMBER(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	//

	// ...
	int Mon__STATE_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int Mon__IDLE_ERROR_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Mon__PROC_ERROR_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	CString Get__ERROR_MSG(CClass__Error_Timer* p_error);
	//

public:
	CObj__VAT_IO();
	~CObj__VAT_IO();

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
