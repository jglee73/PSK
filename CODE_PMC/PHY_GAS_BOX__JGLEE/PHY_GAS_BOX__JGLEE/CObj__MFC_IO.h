#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_Def.h"

#include "CClass__Error_Timer.h"

#include "CObj__MFC_IO__DEF.h"
#include "CObj__MFC_IO__ALID.h"


class CObj__MFC_IO : public __IOBJ__STD_TYPE
{
private:
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	//-------------------------------------------------------------------------
	CString sObject_Name;

	// ...
	SCX__USER_LOG_CTRL xLOG_CTRL;
	int iActive__SIM_MODE;

	CUIntArray iLIST_ALID__PART;
	//


	//-------------------------------------------------------------------------
	// INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;
	CX__VAR_STRING_CTRL  sCH__ACT_MODE;
	CX__VAR_STRING_CTRL  sCH__OBJ_TIMER;

	// PARA ...
	CX__VAR_ANALOG_CTRL	 aCH__PARA_SET_VALUE;
	CX__VAR_ANALOG_CTRL	 aCH__PARA_RAMP_SEC;

	// INFO ...
	CX__VAR_STRING_CTRL  sCH__INFO_LINK_DATA__TYPE;
	CX__VAR_STRING_CTRL  sCH__INFO_LINK_DATA__MAX_FLOW;
	CX__VAR_STRING_CTRL  sCH__INFO_LINK_DATA__MAX_DEFAULT;

	// MON.PART.ACTIVE ...
	CX__VAR_DIGITAL_CTRL dCH__MON_PART_ERROR_ACTIVE;

	// MON ...
	CX__VAR_STRING_CTRL  sCH__MON_MFC_STATE;

	//
	CX__VAR_ANALOG_CTRL  aCH__MON_MFC_SET_FLOW;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_SET_PERCENT;

	CX__VAR_ANALOG_CTRL  aCH__MON_MFC_READ_FLOW;	
	CX__VAR_STRING_CTRL  sCH__MON_MFC_FLOW_PERCENT;

	//
	CX__VAR_STRING_CTRL  sCH__MON_MFC_EXCEPTION_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_EXCEPTION_INFO;

	CX__VAR_STRING_CTRL  sCH__MON_MFC_READ_VALVE_VOLTAGE;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_VALVE_VOLTAGE_PERCENT;

	CX__VAR_STRING_CTRL  sCH__MON_MFC_READ_INLET_PRESSURE;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_INLET_PRESSURE_PERCENT;

	CX__VAR_STRING_CTRL  sCH__MON_MFC_READ_TEMPERATURE;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_TEMPERATURE_PERCENT;

	// MFC.FLOW
	CX__VAR_DIGITAL_CTRL dCH__MON_MFC_PROC_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__MON_ERROR_CHECK_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_MFC_ABORT_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_MFC_STABLE_ACTIVE;
	
	CX__VAR_STRING_CTRL  sCH__MON_MFC_STABLE_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_STABLE_MAX;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_STABLE_DELAY_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_STABLE_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_WARNING_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_ABORT_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_ABORT_MAX;
	CX__VAR_STRING_CTRL  sCH__MON_MFC_ABORT_CHECK_TIME;

	// PT
	CX__VAR_DIGITAL_CTRL dCH__MON_ERROR_CHECK_ACTIVE_PT;
	CX__VAR_DIGITAL_CTRL dCH__MON_ABORT_ACTIVE_PT;
	CX__VAR_DIGITAL_CTRL dCH__MON_STABLE_ACTIVE_PT;

	CX__VAR_STRING_CTRL  sCH__MON_STABLE_CHECK_TIME_PT;
	CX__VAR_STRING_CTRL  sCH__MON_WARNING_MIN_PT;
	CX__VAR_STRING_CTRL  sCH__MON_WARNING_MAX_PT;
	CX__VAR_STRING_CTRL  sCH__MON_WARNING_CHECK_TIME_PT;
	CX__VAR_STRING_CTRL  sCH__MON_ABORT_MIN_PT;
	CX__VAR_STRING_CTRL  sCH__MON_ABORT_MAX_PT;
	CX__VAR_STRING_CTRL  sCH__MON_ABORT_CHECK_TIME_PT;

	// CFG ...
	CX__VAR_STRING_CTRL	 sCH__CFG_GAS_NAME;
	CX__VAR_DIGITAL_CTRL dCH__CFG_MFC_USE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_LEAK_CHECK_USE;
	CX__VAR_DIGITAL_CTRL dCH__REPORT_LEAK_CHECK_STATE;

	CX__VAR_ANALOG_CTRL	 aCH__CFG_MFC_MIN_VALUE;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_MFC_MAX_VALUE;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_MFC_DEC_VALUE;

	CX__VAR_ANALOG_CTRL	 aCH__CFG_STABLE_DELAY_TIME;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_STABLE_CHECK_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_TOL_WARN_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_TOL_ABORT_TIMEOUT;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_WARN_BAND;
	CX__VAR_ANALOG_CTRL	 aCH__CFG_ABORT_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_WARN_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_ABORT_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MFC_Zero_Setpoint_Tolerance_Compensation;

	CX__VAR_DIGITAL_CTRL dCH__CFG_ABORT_TOLE_VALVE_CLOSE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_FLOW_MODE;

	// CFG - RANGE ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_RANGE_MFC_UNIT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_MAX_PRESSURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_DEC_PRESSURE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_MAX_TEMPERATURE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_DEC_TEMPERATURE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_MAX_VOLTAGE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_RANGE_DEC_VOLTAGE;

	// CFG - HEXA.TYPE ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_HEXA_TYPE_FLOW;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HEXA_TYPE_PRESSURE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HEXA_TYPE_TEMPERATURE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_HEXA_TYPE_VOLTAGE;
	//

	//-------------------------------------------------------------------------
	// EXTERNAL PROPERTY

	// DB_SYS ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_PMC_ATM_MAINT_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DI_INTERLOCK_HEAVY_CHECK_SYSTEM;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DI_INTERLOCK_HEAVY_CHECK_CHAMBER;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DI_INTERLOCK_HEAVY_CHECK_GAS_BOX;

	//
	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_SYSTEM_PROCESS_ACTIVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_SYSTEM;
	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_SYSTEM;

	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_CHAMBER;
	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_CHAMBER;

	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_GAS_BOX;
	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_GAS_BOX;

	CX__VAR_DIGITAL_CTRL dEXT_CH__MON_ACTIVE_PROCESS_VALVE_READY_STATE;

	// LINK.DATA ...
	int iLINK_DATA__TYPE;
	int iLINK_DATA__MAX_FLOW;
	int iLINK_DATA__MAX_DEFAULT;

	// LINK IO ...
	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_SET_HEXA;
	CX__VAR_ANALOG_CTRL   aEXT_CH__IO_MFC_SET_DEC;

	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_READ_HEXA;
	CX__VAR_ANALOG_CTRL   aEXT_CH__IO_MFC_READ_DEC;

	//
	bool bActive__MFC_STATE;
	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_STATE;

	bool bActive__MFC_VALVE_VOLTAGE;
	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_VALVE_VOLTAGE;

	bool bActive__MFC_PRESSURE;
	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_PRESSURE;

	bool bActive__MFC_TEMPERATURE;
	CX__VAR_STRING_CTRL   sEXT_CH__IO_MFC_TEMPERATURE;

	//
	int iSIZE__VLV_PURGE_IN;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_PURGE_IN_X[_CFG_MFC_VLV__SIZE];

	int iSIZE__VLV_IN;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_IN_X[_CFG_MFC_VLV__SIZE];

	int iSIZE__VLV_OUT_ALL;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_OUT_ALL_X[_CFG_MFC_VLV__SIZE];

	int iSIZE__VLV_OUT_CENTER;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_OUT_CENTER_X[_CFG_MFC_VLV__SIZE];

	int iSIZE__VLV_OUT_EDGE;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_OUT_EDGE_X[_CFG_MFC_VLV__SIZE];

	int iSIZE__VLV_PURGE_OUT;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__IO_VLV_PURGE_OUT_X[_CFG_MFC_VLV__SIZE];
	//


	//------------------------------------------------------------------------------
	// CONTROL MODE ...

	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__OPEN;
	int  Call__OPEN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CLOSE;
	int  Call__CLOSE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CONTROL;
	int  Call__CONTROL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__CONTROL(const double set_flow, const int open_mode, const double cfg_ma);
	int  _Open__VALVE(const double set_flow, const int open_mode, const double cfg_ma);
	int  _Close__ALL_VALVE();

	CString sMODE__RAMP_CTRL;
	int  Call__RAMP_CTRL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__RAMP_CTRL(CII_OBJECT__VARIABLE* p_variable, const double set_flow, const int open_mode, const double cfg_max);

	CString sMODE__SET_FLOW;
	int  Call__SET_FLOW(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__SET_FLOW(const double set_flow);

	// ...
	CString sMODE__PURGE;
	int  Call__PURGE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__GAS_LINE_PURGE;
	int  Call__GAS_LINE_PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	CString sMODE__CHM_LINE_PURGE;
	int  Call__CHM_LINE_PURGE(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	//

	// ...
	int  Mon__STATE_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);

	int  Mon__ERROR_CHECK(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM* p_alarm);
	CString Get__ERROR_MSG(CClass__Error_Timer* p_error);
	//


public:
	CObj__MFC_IO();
	~CObj__MFC_IO();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	int __Define__USER_FUNCTION(CII_DEFINE__FUNCTION *p_fnc_ctrl);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
