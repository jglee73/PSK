#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CClass__Error_Timer.h"

#include "CObj__RF_STD__ALID.h"
#include "CObj__RF_STD__DEF.h"


class CObj__RF_STD : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	CCommon_Error__USER_FNC mERROR__USER_FNC;	

	SCX__USER_LOG_CTRL xLOG_CTRL;

	int iActive__SIM_MODE;

	CUIntArray iLIST_ALID__RF;
	//

	
	//-------------------------------------------------------------------------
	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;

	// PARA : COMMON ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_SET_POWER;
	CX__VAR_ANALOG_CTRL  aCH__PARA_HOLD_TIME;

	CX__VAR_ANALOG_CTRL  aCH__PARA_RAMP_UP_TIME;
	CX__VAR_ANALOG_CTRL  aCH__PARA_RAMP_DOWN_TIME;

	CX__VAR_STRING_CTRL  sCH__PARA_STEP_TIME;
	CX__VAR_STRING_CTRL  sCH__PARA_RF_OFFSET_POWER;

	// PARA : FREQ ...
	CX__VAR_DIGITAL_CTRL dCH__PARA_FREQ_TUNE_USE;
	CX__VAR_ANALOG_CTRL  aCH__PARA_FREQ_TUNE_DELAY;
	CX__VAR_ANALOG_CTRL  aCH__PARA_FREQ_PRESET;
	CX__VAR_ANALOG_CTRL  aCH__PARA_FREQ_OUTPUT;
	CX__VAR_ANALOG_CTRL  aCH__PARA_FREQ_LEARNED;

	// PARA : RCP ...
	CX__VAR_DIGITAL_CTRL dCH__PARA_RCP_CTRL_ACTIVE;

	// MON.PART ...
	CX__VAR_DIGITAL_CTRL  dCH__MON_RF_CTRL_ACTIVE;
	CX__VAR_DIGITAL_CTRL  dCH__MON_RF_ERROR_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__MON_RF_POWER_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_RF_POWER_ABORT_ACTIVE;

	// MON : IO ...
	CX__VAR_STRING_CTRL  sCH__MON_IO_SET_POWER;
	CX__VAR_STRING_CTRL  sCH__MON_IO_FORWARD_POWER;
	CX__VAR_STRING_CTRL  sCH__MON_IO_REFLECT_POWER; 

	CX__VAR_DIGITAL_CTRL dCH__MON_IO_POWER_STATE; 

	// MON : RF_ON ...
	CX__VAR_STRING_CTRL  sCH__MON_RF_ON_TIME_START_DATE;
	CX__VAR_ANALOG_CTRL  aCH__MON_RF_ON_TIME_TOTAL_HOUR;
	CX__VAR_ANALOG_CTRL  aCH__MON_RF_ON_TIME_TOTAL_SEC;
	CX__VAR_DIGITAL_CTRL dCH__MON_RF_ON_TIME_RESET;

	// MON : STABLE_IDLE ...
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_POWER_CHECK_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_POWER_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_IDLE_POWER_ABORT_ACTIVE;

	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_STABLE_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_STABLE_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_ABORT_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_ABORT_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_STABLE_DELAY_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_STABLE_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_WARNING_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_IDLE_POWER_ABORT_CHECK_TIME;

	// MON : STABLE_PROC ...
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_POWER_CHECK_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_POWER_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_PROC_POWER_ABORT_ACTIVE;

	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_STABLE_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_STABLE_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_ABORT_MIN;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_ABORT_MAX;

	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_STABLE_DELAY_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_STABLE_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_WARNING_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_PROC_POWER_ABORT_CHECK_TIME;

	// MON : COMMON ...
	CX__VAR_STRING_CTRL  sCH__MON_REFLECT_HIGH_LIMIT_CHECK_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_REFLECT_MAX_COEFFICIENT_CHECK_TIME;

	CX__VAR_STRING_CTRL  sCH__MON_REFLECT_HIGH_LIMIT_ACTIVE;
	CX__VAR_STRING_CTRL  sCH__MON_REFLECT_MAX_COEFFICIENT_ACTIVE;

	// CFG : STABLE ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_USE_PART;

	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_MIN_VALUE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_MAX_VALUE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_DEC_VALUE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_STABLE_DELAY_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_STABLE_CHECK_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_WARNING_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_POWER_ABORT_TIMEOUT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_POWER_WARNING_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POWER_WARNING_BAND;

	CX__VAR_ANALOG_CTRL  aCH__CFG_IDLE_POWER_ABORT_BAND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PROC_POWER_ABORT_BAND;

	CX__VAR_ANALOG_CTRL  aCH__CFG_Zero_Setpoint_Tolerance_Compensation;

	//
	CX__VAR_ANALOG_CTRL  aCH__CFG_ERROR_CHECK_TIMEOUT;
	
	CX__VAR_ANALOG_CTRL  aCH__CFG_REFLECT_HIGH_LIMIT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_REFLECT_MAX_COEFFICIENT;

	// CAL ITEM ...
	CX__VAR_ANALOG_CTRL  aCH__RF_CAL__CFG_SET_POWER[CFG__ITEM_CHECK];

	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NEW_POWER[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NEW_METER[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NEW_OFFSET[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NEW_AVG_OFFSET;

	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NOW_POWER[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NOW_METER[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NOW_OFFSET[CFG__ITEM_CHECK];
	CX__VAR_STRING_CTRL  sCH__RF_CAL__CFG_NOW_AVG_OFFSET;

	CX__VAR_DIGITAL_CTRL dCH__RF_CAL__OFFSET_APPLY;
	CX__VAR_STRING_CTRL  sCH__RF_CAL__OFFSET_SAVE_DATE;

	CX__VAR_STRING_CTRL  sCH__RF_CAL__TEST_FLAG;

	//
	CX__VAR_DIGITAL_CTRL dCH__RF_ABORT_FLAG;
	CX__VAR_DIGITAL_CTRL dCH__RF_STABLE_FLAG;

	// USER CONFIG ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_MAX_ALLOWED_POWER;
	
	CX__VAR_DIGITAL_CTRL dCH__CFG_POWER_INTERLOCK_WITHOUT_WAFER;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MAX_POWER_WITHOUT_WAFER;
	
	CX__VAR_DIGITAL_CTRL dCH__CFG_FREQUENCY_USE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MIN_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_MAX_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_DEFAULT_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_DEFAULT_RAMP_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_DEFAULT_TUNE_DELAY;

	// RF Conductance Interlock Skip ...
	CX__VAR_DIGITAL_CTRL dCH__RF_CONDUCTANCE_INTLK_SKIP;
	//


	//-------------------------------------------------------------------------
	// DB_SYS ...
	CX__VAR_DIGITAL_CTRL  dEXT_CH__CFG_PMC_ATM_MAINT_ACTIVE;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_SYSTEM_PROCESS_ACTIVE;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_SYSTEM;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_SYSTEM;

	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_HEAVY_ACTIVE_CHAMBER;
	CX__VAR_DIGITAL_CTRL  dEXT_CH__MON_INTERLOCK_LIGHT_ACTIVE_CHAMBER;

	// Link : IO_RF_Object ...
	bool bActive__RF_FREQ_MODE;

	//
	bool bActive__RF_IO_OBJ;
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__IO_RF;

	CString sLINK__RF_MODE__INIT;
	CString sLINK__RF_MODE__LOCAL;
	CString sLINK__RF_MODE__REMOTE;
	CString sLINK__RF_MODE__SET_POWER;
	CString sLINK__RF_MODE__OFF;

	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_SET_POWER;

	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_PARA_TUNE_USE;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_TUNE_DELAY;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_START_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_OUTPUT_FREQUENCY;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_RAMP_UP_TIME;
	CX__VAR_ANALOG_CTRL  aEXT_CH__RF_PARA_RAMP_DOWN_TIME;

	bool bActive__RF_DO_POWER_CTRL;
	CX__VAR_DIGITAL_CTRL dEXT_CH__RF_DO_POWER_CTRL;

	CX__VAR_STRING_CTRL  sEXT_CH__RF_AO_SET_POWER;
	CX__VAR_STRING_CTRL  sEXT_CH__RF_AI_FORWARD_POWER;
	CX__VAR_STRING_CTRL  sEXT_CH__RF_AI_REFLECT_POWER; 

	// RF Power On Interlock Channel ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__DI_VAC_SNS;						// VAC Sensor ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__DI_ATM_SNS;						// ATM Sensor ...

	bool bActive__DI_CHM_LID_CLOSE_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__DI_CHM_LID_CLOSE_SNS;				// Chamber Top_Lid Close Sensor ...

	bool bActive__DI_CHM_LID_OPEN_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__DI_CHM_LID_OPEN_SNS;				// Chamber Top_Lid Open Sensor ...

	CX__VAR_DIGITAL_CTRL dEXT_CH__CHM_SHUTTER_STATE;				// Chamber Shutter State  ...

	CX__VAR_DIGITAL_CTRL dEXT_CH__INTERLOCK_ACTIVE;
	CX__VAR_STRING_CTRL  sEXT_CH__INTERLOCK_MSG;

	// ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__SLOT01_STATUS;					// WAFER PRESENT ...
	//


	//-------------------------------------------------------------------------
	// ...
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	int Fnc__DEFAULT_CONFIG_SET(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Fnc__RECIPE_CONTROL_SET(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__OFF;
	int Call__OFF(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	CString sMODE__QUICK_OFF;
	int Call__QUICK_OFF(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	//
	CString sMODE__SET_POWER;
	int Call__SET_POWER(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	int Fnc__SET_OFFSET_POWER(const double ref__set_pwr);

	//
	CString sMODE__REMOTE;
	int Call__REMOTE(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	CString sMODE__LOCAL;
	int Call__LOCAL(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	int Fnc__INTLK_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	//


	//-------------------------------------------------------------------------
	int Mon__STATE_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Mon__INTERLOCK_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	int Mon__IDLE_ERROR_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	int Mon__PROC_ERROR_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	CString Get__ERROR_MSG(CClass__Error_Timer* p_error);

	// ...
	int	 Alarm__CHECK_RETRY_ABORT(CII_OBJECT__ALARM* p_alarm, CString msg, const int alarm_id);
	void Alarm__POST_CHECK(CII_OBJECT__ALARM *p_alarm, CString msg, const int alarm_id);
	//


public:
	CObj__RF_STD();
	~CObj__RF_STD();

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
