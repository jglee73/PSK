#include "StdAfx.h"
#include "CObj__DB_SYS.h"
#include "CObj__DB_SYS__DEF.h"


//-------------------------------------------------------------------------
CObj__DB_SYS::CObj__DB_SYS()
{

}
CObj__DB_SYS::~CObj__DB_SYS()
{

}

//-------------------------------------------------------------------------
int CObj__DB_SYS::__DEFINE__CONTROL_MODE(obj,l_mode)
{
	sObject_Name = obj;

	return 1;
}
int CObj__DB_SYS::__DEFINE__VERSION_HISTORY(version)
{

	return 1;
}


// ...
#define APP_DSP__INTERLOCK_ITEM_LIST		"ENABLE  CONTROL  DISABLE  ALL_DISABLE"
#define APP_DSP__ENABLE_DISABLE				"ENABLE  DISABLE"
#define APP_DSP__ALARM_LEVEL				"LIGHT  HEAVY"
#define APP_DSP__OFF_ON						"OFF  ON"

#define APP_DSP__GAS_TYPE					\
"NONE										\
GAS1   GAS2   GAS3   GAS4   GAS5			\
GAS6   GAS7   GAS8   GAS9   GAS10			\
GAS11  GAS12  GAS13  GAS14  GAS15			\
GAS16  GAS17"


// ...
#define MON_ID__PARAMETER_CHECK				1


int CObj__DB_SYS::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE;

	CCommon_Error__DEF_VARIABLE m_err_def_variable;
	p_variable->Link__DEF_VARIABLE__ERROR_FEEDBACK(&m_err_def_variable);

	// ...
	CString str_name;
	int i;
	int k;

	// ...
	{
		str_name = "SIM.PRESSURE.TORR";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__SIM_PRESSURE_TORR, str_name);
	}

	// MON.SYSTEM ...
	{
		str_name = "MON.SYSTEM.PROCESS.ACTIVE";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_STRING_CTRL(sCH__MON_SYSTEM_PROCESS_ACTIVE, str_name);

		str_name = "SYSTEM.PROCESS.STEP.ID";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_PROC_STEP_ID,str_name);

		str_name = "SYSTEM.PROCESS.LAST.STEP.FLAG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_PROC_LAST_STEP_FLAG,str_name);

		//
		str_name = "MON.INTERLOCK.HEAVY.ACTIVE.SYSTEM";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_HEAVY_ACTIVE_SYSTEM, str_name);

		str_name = "MON.INTERLOCK.LIGHT.ACTIVE.SYSTEM";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_LIGHT_ACTIVE_SYSTEM, str_name);

		str_name = "MON.INTERLOCK.HEAVY.MSG.SYSTEM";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_HEAVY_MSG_SYSTEM, str_name);

		str_name = "MON.INTERLOCK.LIGHT.MSG.SYSTEM";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_LIGHT_MSG_SYSTEM, str_name);

		//
		str_name = "MON.INTERLOCK.HEAVY.ACTIVE.HW";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_HEAVY_ACTIVE_HW, str_name);

		str_name = "MON.INTERLOCK.LIGHT.ACTIVE.HW";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_LIGHT_ACTIVE_HW, str_name);

		str_name = "MON.INTERLOCK.HEAVY.MSG.HW";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_HEAVY_MSG_HW, str_name);

		str_name = "MON.INTERLOCK.LIGHT.MSG.HW";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_LIGHT_MSG_HW, str_name);

		//
		str_name = "MON.INTERLOCK.HEAVY.ACTIVE.CHAMBER";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_HEAVY_ACTIVE_CHAMBER, str_name);

		str_name = "MON.INTERLOCK.LIGHT.ACTIVE.CHAMBER";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_LIGHT_ACTIVE_CHAMBER, str_name);

		str_name = "MON.INTERLOCK.HEAVY.MSG.CHAMBER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_HEAVY_MSG_CHAMBER, str_name);

		str_name = "MON.INTERLOCK.LIGHT.MSG.CHAMBER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_LIGHT_MSG_CHAMBER, str_name);

		//
		str_name = "MON.INTERLOCK.HEAVY.ACTIVE.GAS_BOX";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_HEAVY_ACTIVE_GAS_BOX, str_name);

		str_name = "MON.INTERLOCK.LIGHT.ACTIVE.GAS_BOX";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_LIGHT_ACTIVE_GAS_BOX, str_name);

		str_name = "MON.INTERLOCK.HEAVY.MSG.GAS_BOX";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_HEAVY_MSG_GAS_BOX, str_name);

		str_name = "MON.INTERLOCK.LIGHT.MSG.GAS_BOX";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_LIGHT_MSG_GAS_BOX, str_name);

		//
		str_name = "MON.INTERLOCK.HEAVY.ACTIVE.RF_SYS";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_HEAVY_ACTIVE_RF_SYS, str_name);

		str_name = "MON.INTERLOCK.LIGHT.ACTIVE.RF_SYS";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__MON_INTERLOCK_LIGHT_ACTIVE_RF_SYS, str_name);

		str_name = "MON.INTERLOCK.HEAVY.MSG.RF_SYS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_HEAVY_MSG_RF_SYS, str_name);

		str_name = "MON.INTERLOCK.LIGHT.MSG.RF_SYS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_INTERLOCK_LIGHT_MSG_RF_SYS, str_name);

		//
		str_name = "MON.ACTIVE.PROCESS.VALVE.READY.STATE";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);

		//
		str_name = "CFG.DI_INTERLOCK_HEAVY_CHECK.SYSTEM";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "YES NO", "");

		str_name = "CFG.DI_INTERLOCK_HEAVY_CHECK.CHAMBER";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "YES NO", "");

		str_name = "CFG.DI_INTERLOCK_HEAVY_CHECK.GAS_BOX";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "YES NO", "");
	}

	// CFG : GAS_BOX ...
	{
		str_name = "CFG.GAS_BOX.DIFF_PRESSURE.LOW_PRESSURE";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "pa", 1, 0, 500, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_GAS_BOX_DIFF_PRESSURE_LOW_PRESSURE, str_name);
	}

	// CFG : WAFER_COUNT ...
	{
		str_name = "CFG.WAFER_COUNT.WARNING.APPLY";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_WAFER_COUNT_WARNING_APPLY, str_name);

		str_name = "CFG.WAFER_COUNT.WARNING.REF";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "count", 0, 0, 999999, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_WAFER_COUNT_WARNING_REF, str_name);

		//
		str_name = "CFG.WAFER_COUNT.SYSTEM_DOWN.APPLY";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_WAFER_COUNT_SYSTEM_DOWN_APPLY, str_name);

		str_name = "CFG.WAFER_COUNT.SYSTEM_DOWN.REF";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "count", 0, 0, 999999, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_WAFER_COUNT_SYSTEM_DOWN_REF, str_name);
	}

	// CFG : SYSTEM_INITIAL ...
	{
		str_name = "CFG.SYSTEM_INITIAL.DI_SENSOR_INTERLOCK.CHECK";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_SYSTEM_INITIAL_DI_SENSOR_INTERLOCK_CHECK, str_name);

		str_name = "CFG.SYSTEM_INITIAL.AUTO_PM.CHECK";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_SYSTEM_INITIAL_AUTO_PM_CHECK, str_name);
	}

	// CFG : BEFORE_PROCESS ...
	{
		str_name = "CFG.BEFORE_PROCESS.DI_SENSOR_INTERLOCK.CHECK";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_BEFORE_PROCESS_DI_SENSOR_INTERLOCK_CHECK, str_name);
	}

	// CFG ...
	{
		str_name = "CFG.PMC.NAME";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__PMC_NAME,str_name);

		str_name = "CFG.PMC.TYPE";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__PMC_TYPE,str_name);

		//
		str_name = "SYSTEM.LOCK";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_LOCK, str_name);

		//
		str_name = "SYSTEM.MSG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(xCH__SYSTEM_MSG, str_name);

		str_name = "FUNCTION.MSG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(xCH__FNC_MSG, str_name);

		//
		str_name = "SYSTEM.SETUP.REQ";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_SETUP_REQ, str_name);

		str_name = "REQ.GOTO_MAINT";
		STD__ADD_DIGITAL(str_name, "NO YES");
		LINK__VAR_DIGITAL_CTRL(dCH__REQ_GOTO_MAINT, str_name);

		str_name = "CUR.NEXT.PROCESS";
		STD__ADD_STRING(str_name, "NO YES");
		LINK__VAR_STRING_CTRL(sCH__CUR_NEXT_PROCESS, str_name);

		//
		str_name = "CFG.SCH_TEST.SIM.ALARM_REPORT.MODE";
		STD__ADD_DIGITAL(str_name, "ENABLE DISABLE");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_SCH_TEST_SIM_ALARM_REPORT_MODE, str_name);

		str_name = "CFG.SCH_TEST.SIM.ALARM_STEP.ACTIVE";
		STD__ADD_DIGITAL(str_name, "DISABLE ENABLE");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_SCH_TEST_SIM_ALARM_STEP_ACTIVE, str_name);

		//
		str_name = "SYSTEM.INTERLOCK.FLAG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_INTERLOCK_FLAG,str_name);

		str_name = "SYSTEM.INTERLOCK.MSG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__SYSTEM_INTERLOCK_MSG,str_name);
	}

	// INTERLOCK ...
	{
		// ...
		{
			str_name = "CFG.INTERLOCK.USE.MODE";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__INTERLOCK_ITEM_LIST,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE_FLAG, str_name);

			str_name = "CFG.INTERLOCK.USE.ALWAYS_ENABLE";
			STD__ADD_DIGITAL(str_name, "ENABLE");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE_ALWAYS_ENABLE, str_name);
		}

		// USE ...
		{
			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.ALL";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_ALL, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN1";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN1, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN2";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN2, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN3, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN4";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN4, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN5";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN5, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.FAN6";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN6, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.EMO";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_EMO, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.LEAK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_LEAK, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.GAS_LEAK_NH3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_NH3, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.GAS_LEAK_NF3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_NF3, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.GAS_LEAK_H2";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_H2, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.PLASMA_OVERTIME";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_PLASMA_OVERTIME, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.BIAS_OVERTIME";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_BIAS_OVERTIME, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.PC_ALIVE_ERROR";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_PC_ALIVE_ERROR, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.HEATER1_INTERLOCK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_HEATER1_INTERLOCK, str_name);

			str_name = "CFG.INTERLOCK.USE.INTERLOCK_SNS.HEATER2_INTERLOCK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_HEATER2_INTERLOCK, str_name);
		}

		// LEVEL ...
		{
			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN1";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_LEVEL__INTERLOCK_SNS_FAN1, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN2";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN2, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN3, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN4";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN4, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN5";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN5, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.FAN6";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_FAN6, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.EMO";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_EMO, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.LEAK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_LEAK, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.GAS_LEAK_NH3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_NH3, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.GAS_LEAK_NF3";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_NF3, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.GAS_LEAK_H2";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_GAS_LEAK_H2, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.PLASMA_OVERTIME";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_PLASMA_OVERTIME, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.BIAS_OVERTIME";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_BIAS_OVERTIME, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.PC_ALIVE_ERROR";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_PC_ALIVE_ERROR, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.HEATER1_INTERLOCK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_HEATER1_INTERLOCK, str_name);

			str_name = "CFG.INTERLOCK.LEVEL.INTERLOCK_SNS.HEATER2_INTERLOCK";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ALARM_LEVEL, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__INTERLOCK_SNS_HEATER2_INTERLOCK, str_name);
		}

		//
		str_name = "CFG.INTERLOCK.CHECK.SEC";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 0, 10, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_INTERLOCK_CHECK_SEC, str_name);

		str_name = "CUR.SNS.TIMECOUNT.FAN1";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_FAN1, str_name);

		str_name = "CUR.SNS.TIMECOUNT.FAN2";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_FAN2, str_name);

		str_name = "CUR.SNS.TIMECOUNT.FAN3";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_FAN3, str_name);

		str_name = "CUR.SNS.TIMECOUNT.EMO";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_EMO, str_name);

		str_name = "CUR.SNS.TIMECOUNT.LEAK";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_LEAK, str_name);

		str_name = "CUR.SNS.TIMECOUNT.GAS_LEAK_NH3";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_GAS_LEAK_NH3, str_name);

		str_name = "CUR.SNS.TIMECOUNT.GAS_LEAK_NF3";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_GAS_LEAK_NF3, str_name);

		str_name = "CUR.SNS.TIMECOUNT.GAS_LEAK_H2";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_GAS_LEAK_H2, str_name);

		str_name = "CUR.SNS.TIMECOUNT.PLASMA_OVERTIME";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_PLASMA_OVERTIME, str_name);

		str_name = "CUR.SNS.TIMECOUNT.BIAS_OVERTIME";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_BIAS_OVERTIME, str_name);

		str_name = "CUR.SNS.TIMECOUNT.PC_ALIVE_ERROR";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_PC_ALIVE_ERROR, str_name);

		str_name = "CUR.SNS.TIMECOUNT.HEATER1_INTERLOCK";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_HEATER1_INTERLOCK, str_name);

		str_name = "CUR.SNS.TIMECOUNT.HEATER2_INTERLOCK";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__CUR_SNS_TIMECOUNT_HEATER2_INTERLOCK, str_name);

		//
		str_name = "CFG.INTERLOCK.USE.CHM_MANOMETER_ISO";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__CHM_MANOMETER_ISO, str_name);

		str_name = "CFG.INTERLOCK.USE.TMP_VAT_OPEN";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__TMP_VAT_OPEN, str_name);

		str_name = "CFG.INTERLOCK.USE.FORELINE_VLV_OPEN";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__FORELINE_VLV_OPEN, str_name);

		str_name = "CFG.INTERLOCK.USE.MFC_OUT_VLV_OPEN";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_USE__MFC_OUT_VLV_OPEN, str_name);

		//
		for(i=0;i<CFG_INTERLOCK__LIMIT;i++)
		{
			str_name.Format("CFG.INTERLOCK.ID%1d.USE_FLAG", i+1);
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_ID_USE_FLAG[i], str_name);
		}
	}

	// ...
	{
		str_name = "CTC.LEAK_CHECK.USE.FLAG";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__ENABLE_DISABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CTC_LEAK_CHECK_USE_FLAG, str_name);

		str_name = "CTC.LEAK_CHECK.OVER_PUMPING.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 0.0, 9999, "");
		LINK__VAR_ANALOG_CTRL(aCH__CTC_LEAK_CHECK_OVER_PUMPING_TIME,str_name);

		str_name = "CTC.LEAK_CHECK.STABLE.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 0.0, 9999, "");
		LINK__VAR_ANALOG_CTRL(aCH__CTC_LEAK_CHECK_STABLE_TIME,str_name);

		str_name = "CTC.LEAK_CHECK.TIME.MIN";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "min", 0, 0, 7, "");
		LINK__VAR_ANALOG_CTRL(aCH__CTC_LEAK_CHECK_TIME_MIN,str_name);
	}

	// Interlock Channel ...
	{		
		// MFC Object ...
		for(i=0;i<CFG_SIZE__MFC_OBJ;i++)
		{
			for(k=0;k<CFG_INTERLOCK__MFC_SIZE;k++)
			{
				str_name.Format("CFG.INTERLOCK.MFC%1d.MFC_TYPE%1d", i+1,k+1);
				STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__GAS_TYPE,"");
				LINK__VAR_DIGITAL_CTRL(dCH__CFG_INTERLOCK_MFC_TYPE[i][k], str_name);
			}
		}
	}

	// ... 
	{
		str_name = "CFG.aCHM.MANOMETER.PRESS.SW1.SETTING";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 10000, "");
		LINK__VAR_ANALOG_CTRL(CFG_aCHM_MANOMETER_PRESS_SW1_SETTING,str_name);

		str_name = "CFG.aCHM.MANOMETER.PRESS.SW2.SETTING";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 10000, "");
		LINK__VAR_ANALOG_CTRL(CFG_aCHM_MANOMETER_PRESS_SW2_SETTING,str_name);

		//
		str_name = "CFG.SOFTWARE.VERSION";
		STD__ADD_STRING_WITH_X_OPTION(str_name, "");
		LINK__VAR_STRING_CTRL(sCH__CFG_SOFTWARE_VERSION, str_name);

		//
		str_name = "CFG.CHM.MANOMETER.MAX.PRESSURE.mTORR";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 1000000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_CHM_MANOMETER_MAX_PRESSURE_mTORR, str_name);

		str_name = "CFG.PROCESS.MANOMETER.MAX.PRESSURE.mTORR";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 10000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_PROCESS_MANOMETER_MAX_PRESSURE_mTORR, str_name);

		str_name = "CFG.PROCESS.MANOMETER.ISO.PRESSURE.mTORR";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 100000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_PROCESS_MANOMETER_ISO_PRESSURE_mTORR, str_name);

		//
		str_name = "CFG.VX.CONFIG.MEMORY.LIMIT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "%", 0, 0, 20, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_VX_CONFIG_MEMORY_LIMIT, str_name);

		str_name = "CFG.VX.FREE.MEMORY.LIMIT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "%", 0, 0, 20, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_VX_FREE_MEMORY_LIMIT, str_name);

		str_name = "CFG.VOLUME.SIZE";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "ml", 0, 50000, 105000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_VOLUME_SIZE, str_name);

		str_name = "CFG.GAS.BOX.PRIMARY.VALVE.DELAY.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "msec", 0, 0, 1000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_GAS_BOX_PRIMARY_VALVE_DELAY_TIME, str_name);

		str_name = "CFG.GAS.BOX.SECONDARY.VALVE.DELAY.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "msec", 0, 0, 1000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_GAS_BOX_SECONDARY_VALVE_DELAY_TIME, str_name);
	}

	// TMP Parameter ...
	{
		str_name = "CFG.aTMP.ISOLATION.MAX.PRESSURE.mTORR";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 500, 1000, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMP_ISOLATION_MAX_PRESSURE_mTORR, str_name);

		str_name = "CFG.aTMP.FORELINE.VLV.OPEN.PRESSURE.mTORR";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr", 0, 0, 500, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMP_FORELINE_VLV_OPEN_PRESSURE_mTORR, str_name);

		str_name = "CFG.aTMP.FORELINE.VLV.OPEN.IDLE.TIMEOUT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 30, 9999, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMP_FORELINE_VLV_OPEN_IDLE_TIMEOUT, str_name);
	}

	// ...
	{
		str_name = "CFG.CHM_PM_ITEM.WAP_CONDUCTANCE.APPLY";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "DISABLE ENABLE", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_CHM_PM_ITEM_WAP_CONDUCTANCE_APPLY, str_name);

		str_name = "CHM_PM_ITEM.WAP_CONDUCTANCE.FLAG";
		STD__ADD_STRING_WITH_X_OPTION(str_name, "");
		LINK__VAR_STRING_CTRL(sCH__CHM_PM_ITEM__WAP_CONDUCTANCE_FLAG, str_name);
	}

	// LEAKCHECK.CHAMBER ...
	{
		// PARA ...
		{
			str_name = "LEAK_CHECK.CHECK.START_DATE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.CHECK.LOG_DAY";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.CHECK.LOG_REQ";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");
		}

		// LOG ...
		{
			str_name = "LEAK_CHECK.LOG.CHECK_TIME";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.LOG.BASE_PRESSURE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.LOG.START_PRESSURE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			for(i=0;i<CFG_SIZE__LOG_LEAKCHECK;i++)
			{
				str_name.Format("LEAK_CHECK.LOG.PRESSURE.%1d", i+1);
				STD__ADD_STRING_WITH_COMMENT(str_name,"");

				str_name.Format("LEAK_CHECK.LOG.LEAKRATE.%1d", i+1);
				STD__ADD_STRING_WITH_COMMENT(str_name,"");
			}

			str_name = "LEAK_CHECK.LOG.LEAKRATE.RESULT";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			//
			str_name = "LEAK_CHECK.LOG.GRAPH.CUR_DATA";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.LOG.GRAPH.REF_ALARM";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");
		}
	}

	// LEAKCHECK.GAS_LINE ...
	{
		// PARA ...
		{
			str_name = "LEAK_CHECK.GAS_CHECK.START_DATE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.GAS_CHECK.LOG_DAY";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.GAS_CHECK.LOG_REQ";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");
		}

		// LOG ...
		{
			str_name = "LEAK_CHECK.GAS_LOG.CHECK_TIME";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.GAS_LOG.BASE_PRESSURE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.GAS_LOG.START_PRESSURE";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			for(i=0;i<CFG_SIZE__LOG_LEAKCHECK;i++)
			{
				str_name.Format("LEAK_CHECK.GAS_LOG.PRESSURE.%1d", i+1);
				STD__ADD_STRING_WITH_COMMENT(str_name,"");

				str_name.Format("LEAK_CHECK.GAS_LOG.LEAKRATE.%1d", i+1);
				STD__ADD_STRING_WITH_COMMENT(str_name,"");
			}

			str_name = "LEAK_CHECK.GAS_LOG.LEAKRATE.RESULT";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			//
			str_name = "LEAK_CHECK.GAS_LOG.GRAPH.CUR_DATA";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");

			str_name = "LEAK_CHECK.GAS_LOG.GRAPH.REF_ALARM";
			STD__ADD_STRING_WITH_COMMENT(str_name,"");
		}
	}

	// MFC ...
	{
		str_name = "CFG.MFC_FLOW_WARNING.TIMEOUT_SEC";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.3, 1.0, "");

		str_name = "CFG.MFC_CLOSE_WARNING.TIMEOUT_SEC";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.3, 1.0, "");

		//
		str_name = "CFG.MFC_485.SETPOINT_READ.CONFIRM_USE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ENABLE DISABLE", "");

		str_name = "CFG.MFC_485.COMM_OFFLINE_ALARM.USE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ENABLE DISABLE", "");

		str_name = "CFG.MFC_485.CONTROL_TIMEOUT_ALARM.USE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ENABLE DISABLE", "");
	}

	// CFG ...
	{
		str_name = "CFG.PMC.ATM_MAINT.ACTIVE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "OFF ON", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_PMC_ATM_MAINT_ACTIVE, str_name);
	}

	// RECIPE CONFIG ...
	{
		str_name = "CFG.RF_OFF.RAMP_DOWN_TIME.APPLY";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ENABLE DISABLE", "");	
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_RF_OFF_RAMP_DOWN_TIME_APPLY, str_name);
	}


	// ...
	{
		p_variable->Add__MONITORING_PROC(1.0, MON_ID__PARAMETER_CHECK);
	}
	return 1;
}
int CObj__DB_SYS::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ", sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;
	int alarm_id;

	// ...
	{
		alarm_id = ALID__SIMULATION_MODE_ACTIVE;

		alarm_title  = title;
		alarm_title += "Simulation mode is active !";

		alarm_msg = "";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__SETPOINT_INTERLOCK__DISABLE;

		alarm_title  = title;
		alarm_title += "Setpoint Interlock Disable !";

		alarm_msg  = "Config Page에서 Setpoint Interlock를 Disable 설정했습니다.\n";
		alarm_msg += "정상적인 설비 운영시에는 반드시 Enable로 전환 바랍니다.\n";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}
	// ...
	{
		alarm_id = ALID__SETPOINT_AND_MONITORING_INTERLOCK__DISABLE;

		alarm_title  = title;
		alarm_title += "Setpoint & Monitoring Interlock Disable !";

		alarm_msg  = "Config Page에서 Setpoint & Monitoring Interlock를 Disable 설정했습니다.\n";
		alarm_msg += "정상적인 설비 운영시에는 반드시 Enable로 전환 바랍니다.\n";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__ATM_MAINT_MODE_ACTIVE;

		alarm_title  = title;
		alarm_title += "\"Maint Mode\" is active !";

		alarm_msg  = "ATM Mode mode가 선택 되었습니다.\n";
		alarm_msg += "정상적인 설비 운영시에는 반드시 No로 전환 바랍니다.\n";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	return 1;
}

//-------------------------------------------------------------------------
int CObj__DB_SYS::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{	
	// ...
	{
		SCX__SEQ_INFO x_seq_info;

		iSIM_MODE = x_seq_info->Is__SIMULATION_MODE();
	}
	return 1;
}

//-------------------------------------------------------------------------
int CObj__DB_SYS::__CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm)
{
	return -1;
}

int CObj__DB_SYS::__CALL__MONITORING(id,p_variable, p_alarm)
{
	switch(id)
	{
		case MON_ID__PARAMETER_CHECK:
				Mon__PARAMETER_CHECK(p_variable, p_alarm);
				return 1;
	}

	return 1;
}
