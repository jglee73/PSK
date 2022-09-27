#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CObj__ESC_IO__ALID.h"
#include "CObj__ESC_IO__DEF.h"



class CObj__ESC_IO : public __IOBJ__STD_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString sObject_Name;

	// ...
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	SCX__USER_LOG_CTRL xLOG_CTRL;

	int iActive__SIM_MODE;

	int iACTIVE_FLAG;
	int iACTIVE__WAFER_LEAK_CHECK;

	// ...
	CUIntArray iLIST_ALID__ESC;
	CUIntArray iLIST_ALID__HE_FLOW;
	//


	//-------------------------------------------------------------------------
	// INTERNAL PROPERTY

	// ...
	CX__VAR_STRING_CTRL  sCH__APP_LOG_MSG;
	CX__VAR_STRING_CTRL  sCH__APP_LOG_SUB_MSG;

	CX__VAR_STRING_CTRL  sCH__APP_TIMER_COUNT;

	// MON.PART.ACTIVE ...
	CX__VAR_DIGITAL_CTRL dCH__MON_ESC_CTRL_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_ESC_ERROR_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__MON_HE_FLOW_CTRL_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_HE_FLOW_ERROR_ACTIVE;

	// MON.HE ...
	CX__VAR_STRING_CTRL  sCH__REQ_HE_FINAL_CENTER__3WAY_VLV;
	CX__VAR_STRING_CTRL  sCH__MON_HE_FINAL_CENTER__3WAY_VLV;

	CX__VAR_STRING_CTRL  sCH__REQ_HE_FINAL_EDGE__3WAY_VLV;
	CX__VAR_STRING_CTRL  sCH__MON_HE_FINAL_EDGE__3WAY_VLV;

	// ...
	CX__VAR_STRING_CTRL  sCH__MON_ESC_OBJ_STATUS;
	CX__VAR_STRING_CTRL  sCH__MON_He_OBJ_STATUS;

	CX__VAR_DIGITAL_CTRL dCH__MON_CHUCK_STATUS;	
	CX__VAR_STRING_CTRL  sCH__MON_He_FLOW_STATUS;

	//
	CX__VAR_STRING_CTRL  sCH__MON_He_LEAK_SCCM_CENTER;
	CX__VAR_STRING_CTRL  sCH__MON_He_LEAK_SCCM_EDGE;

	CX__VAR_STRING_CTRL  sCH__MON_He_Pressure_CENTER;
	CX__VAR_STRING_CTRL  sCH__MON_He_Pressure_EDGE;

	CX__VAR_STRING_CTRL  sCH__MON_He_Flow_CENTER;
	CX__VAR_STRING_CTRL  sCH__MON_He_Flow_EDGE;

	// MON.ESC_ON ...
	CX__VAR_STRING_CTRL  sCH__MON_ESC_ON_TIME_START_DATE;
	CX__VAR_ANALOG_CTRL  aCH__MON_ESC_ON_TIME_TOTAL_HOUR;
	CX__VAR_ANALOG_CTRL  aCH__MON_ESC_ON_TIME_TOTAL_SEC;
	CX__VAR_DIGITAL_CTRL dCH__MON_ESC_ON_TIME_RESET;

	// ZERO.CAL ...
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_REQ_HE_PRESSURE_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_REQ_HE_PRESSURE_EDGE;

	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_RESET_HE_PRESSURE_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_RESET_HE_PRESSURE_EDGE;

	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_He_Pressure_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_He_Pressure_EDGE;

	//
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_REQ_HE_FLOW_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_REQ_HE_FLOW_EDGE;

	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_RESET_HE_FLOW_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_RESET_HE_FLOW_EDGE;

	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_He_Flow_CENTER;
	CX__VAR_STRING_CTRL  sCH__ZERO_CAL_He_Flow_EDGE;

	// ...
	CX__VAR_DIGITAL_CTRL dCH__MON_STABLE_ACTIVE;
	CX__VAR_DIGITAL_CTRL dCH__MON_FAULT_ACTIVE;

	CX__VAR_DIGITAL_CTRL dCH__MON_ESC_VOLTAGE_ACTIVE;

	// ESC.CENTER ...
	CX__VAR_STRING_CTRL  sCH__MON_ESC_CENTER_CTRL_CHECK;

	CX__VAR_STRING_CTRL  sCH__MON_CENTER_CHANGE_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_CENTER_CHANGE_ESC_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_CENTER_STABLE_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_CENTER_STABLE_ESC_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_CENTER_FAULT_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_CENTER_FAULT_ESC_TIME;

	CX__VAR_DIGITAL_CTRL dCH__MON_CENTER_ESC_VOLTAGE_STATE;

	// ESC.EDGE ...
	CX__VAR_STRING_CTRL  sCH__MON_ESC_EDGE_CTRL_CHECK;

	CX__VAR_STRING_CTRL  sCH__MON_EDGE_CHANGE_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_EDGE_CHANGE_ESC_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_EDGE_STABLE_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_EDGE_STABLE_ESC_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_EDGE_FAULT_ESC_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_EDGE_FAULT_ESC_TIME;

	CX__VAR_DIGITAL_CTRL dCH__MON_EDGE_ESC_VOLTAGE_STATE;

	// HE.CENTER ...
	CX__VAR_STRING_CTRL  sCH__MON_HE_CENTER_CTRL_CHECK;

	CX__VAR_STRING_CTRL  sCH__MON_CHANGE_HE_CENTER_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_CHANGE_HE_CENTER_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_STABLE_HE_CENTER_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_STABLE_HE_CENTER_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_FAULT_HE_CENTER_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_FAULT_HE_CENTER_TIME;

	// HE.EDGE ...
	CX__VAR_STRING_CTRL  sCH__MON_HE_EDGE_CTRL_CHECK;

	CX__VAR_STRING_CTRL  sCH__MON_CHANGE_HE_EDGE_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_CHANGE_HE_EDGE_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_STABLE_HE_EDGE_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_STABLE_HE_EDGE_TIME;
	CX__VAR_STRING_CTRL  sCH__MON_FAULT_HE_EDGE_STATE;
	CX__VAR_STRING_CTRL  sCH__MON_FAULT_HE_EDGE_TIME;

	CX__VAR_STRING_CTRL  sCH__MON_MSG_STABLE_CHECK;
	//

	// Control Parameter ...
	// PARA.CENTER ...
	CX__VAR_ANALOG_CTRL  aCH__TEST_PARA_He_SET_PRESSURE_CENTER;
	CX__VAR_STRING_CTRL  sCH__PARA_ESC_CENTER_SET_VOLTAGE;
	CX__VAR_STRING_CTRL  sCH__PARA_ESC_CENTER_CURRENT_LIMIT;
	CX__VAR_STRING_CTRL  sCH__PARA_He_SET_PRESSURE_CENTER;

	// PARA.EDGE ...
	CX__VAR_ANALOG_CTRL  aCH__TEST_PARA_He_SET_PRESSURE_EDGE;
	CX__VAR_STRING_CTRL  sCH__PARA_ESC_EDGE_SET_VOLTAGE;
	CX__VAR_STRING_CTRL  sCH__PARA_ESC_EDGE_CURRENT_LIMIT;
	CX__VAR_STRING_CTRL  sCH__PARA_He_SET_PRESSURE_EDGE;

	CX__VAR_STRING_CTRL  sCH__PARA_STABLE_CHECK_REQ;
	CX__VAR_STRING_CTRL  sCH__PARA_STABLE_CHECK_MODE;

	// ESC Parameter ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_ELECTROSTATIC_CHUCK_TYPE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_VOLTAGE_FULL_SCALE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_STABLE_TIME_FOR_ESC_HELIUM_SETPOINT_CHANGE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ERROR_TIMEOUT_FOR_ESC_HELIUM_STATE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_CHECKING_TIME_FOR_ESC_HELIUM_STABLE;

	// CFG.CENTER ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_VOLTAGE_MAX_SETPOINT_FOR_CHUCKING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_VOLTAGE_MIN_SETPOINT_FOR_CHUCKING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_VOLTAGE_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_CURRENT_LIMIT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_VOLTAGE_MAX_SETPOINT_FOR_DECHUCKING;

	// CFG.EDGE ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_VOLTAGE_MAX_SETPOINT_FOR_CHUCKING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_VOLTAGE_MIN_SETPOINT_FOR_CHUCKING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_VOLTAGE_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_CURRENT_LIMIT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_VOLTAGE_MAX_SETPOINT_FOR_DECHUCKING;

	// Helium Parameter ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_PRESSURE_FULL_SCALE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_FLOW_FULL_SCALE;	
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_PRESSURE_MAX_SETPOINT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_He_CENTER_PRESSURE_THRESHOLD_MIN_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_CENTER_PRESSURE_THRESHOLD_MAX_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_CENTER_PRESSURE_THRESHOLD_MIN_FAULT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_CENTER_PRESSURE_THRESHOLD_MAX_FAULT;

	// Chuck Step - Parameter ...
	// Center ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_CHUCKING_VOLTAGE_SETPOINT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_CHUCKING_VOLTAGE_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_CENTER_CHUCKING_VOLTAGE_FAULT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_PRESSURE_SETPOINT;		
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_PRESSURE_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_PRESSURE_FAULT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_FLOW_MIN_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_FLOW_MAX_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__MON_HE_CENTER_FLOW_MIN_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__MON_HE_CENTER_FLOW_MAX_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_WAFER_MAX_LEAK;

	// Edge ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_CHUCKING_VOLTAGE_SETPOINT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_CHUCKING_VOLTAGE_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_EDGE_CHUCKING_VOLTAGE_FAULT;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_PRESSURE_SETPOINT;		
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_PRESSURE_WARNING;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_PRESSURE_FAULT;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_FLOW_MIN_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_FLOW_MAX_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__MON_HE_EDGE_FLOW_MIN_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__MON_HE_EDGE_FLOW_MAX_THRESHOLD;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_WAFER_MAX_LEAK;

	//
	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_SEL;
	CX__VAR_STRING_CTRL  sCH__CUR_CHUCK_SEL;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HV_OFF_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];			    // CFG.HV_OFF.TIME.CHUCK?
	CX__VAR_ANALOG_CTRL  aCH__CFG_HV_ON_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];			        // CFG.HV_ON.TIME.CHUCK?
	CX__VAR_ANALOG_CTRL  aCH__CFG_HV_STABLE_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];		        // CFG.HV_STABLE.TIME.CHUCK?
	CX__VAR_ANALOG_CTRL  aCH__CFG_HV_HOLDING_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];	        // CFG.HV_HOLDING.TIME.CHUCK?
	CX__VAR_ANALOG_CTRL  aCH__CFG_RF_ON_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];			        // CFG.RF_ON.TIME.CHUCK?
	CX__VAR_ANALOG_CTRL  aCH__CFG_FINAL_FLOW_STABLE_TIME_CHUCK_X[DEF__CHUCK_MODE_SIZE];		// CFG.FINAL_FLOW_STABLE.TIME.CHUCK?

	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_CHART_TIME[DEF__CHUCK_CHART_SIZE];
	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_CHART_TIME_TOTAL;
	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_CHART_TIME_CHUCK;
	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_CHART_TIME_CHUCK1;
	CX__VAR_STRING_CTRL  sCH__CFG_CHUCK_CHART_TIME_CHUCK2;
	//

	// TEST & RESULT ...
	CX__VAR_STRING_CTRL  sCH__TEST_CH1_ESC_CHUCKING_VOLTAGE_SETPOINT_START;
	CX__VAR_STRING_CTRL  sCH__TEST_CH2_ESC_CHUCKING_VOLTAGE_SETPOINT_START;

	CX__VAR_STRING_CTRL  sCH__TEST_HE_CENTER_PRESSURE_SETPOINT_START;
	CX__VAR_STRING_CTRL  sCH__TEST_HE_EDGE_PRESSURE_SETPOINT_START;

	//
	CX__VAR_STRING_CTRL  sCH__RESULT_CH1_ESC_CHUCKING_VOLTAGE_READING_POINT1;
	CX__VAR_STRING_CTRL  sCH__RESULT_CH1_ESC_CHUCKING_CURRENT_READING_POINT1;

	CX__VAR_STRING_CTRL  sCH__RESULT_CH2_ESC_CHUCKING_VOLTAGE_READING_POINT1;
	CX__VAR_STRING_CTRL  sCH__RESULT_CH2_ESC_CHUCKING_CURRENT_READING_POINT1;

	//
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_CENTER_PRESSURE_READING_POINT1;
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_CENTER_FLOW_READING_POINT1;

	CX__VAR_STRING_CTRL  sCH__RESULT_HE_EDGE_PRESSURE_READING_POINT1;
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_EDGE_FLOW_READING_POINT1;

	//
	CX__VAR_STRING_CTRL  sCH__RESULT_CH1_ESC_CHUCKING_VOLTAGE_READING_POINT2;
	CX__VAR_STRING_CTRL  sCH__RESULT_CH1_ESC_CHUCKING_CURRENT_READING_POINT2;

	CX__VAR_STRING_CTRL  sCH__RESULT_CH2_ESC_CHUCKING_VOLTAGE_READING_POINT2;
	CX__VAR_STRING_CTRL  sCH__RESULT_CH2_ESC_CHUCKING_CURRENT_READING_POINT2;

	//
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_CENTER_PRESSURE_READING_POINT2;
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_CENTER_FLOW_READING_POINT2;

	CX__VAR_STRING_CTRL  sCH__RESULT_HE_EDGE_PRESSURE_READING_POINT2;
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_EDGE_FLOW_READING_POINT2;

	//
	CX__VAR_STRING_CTRL  sCH__TEST_CHUCK_CHART_TIME[DEF__CHUCK_CHART_SIZE];
	CX__VAR_STRING_CTRL  sCH__TEST_CHUCK_CHART_TIME_TOTAL;
	CX__VAR_STRING_CTRL  sCH__TEST_CHUCK_CHART_TIME_CHUCK1;
	CX__VAR_STRING_CTRL  sCH__TEST_CHUCK_CHART_TIME_CHUCK2;
	CX__VAR_STRING_CTRL  sCH__TEST_CHUCK_CHART_TIME_CHUCK;

	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TIME[DEF__CHUCK_CHART_SIZE];
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TIME_TOTAL;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TIME_CHUCK1;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TIME_CHUCK2;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TIME_CHUCK;

	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TEST_DATE;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TEST_MODE;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_TEST_RESULT;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_MAIN_MSG;
	CX__VAR_STRING_CTRL  sCH__RESULT_CHUCK_CHART_SUB_MSG;

	CX__VAR_STRING_CTRL  sCH__RESULT_HE_CENTER_WAFER_LEAK_CHECK_RESULT;
	CX__VAR_STRING_CTRL  sCH__RESULT_HE_EDGE_WAFER_LEAK_CHECK_RESULT;

	CX__VAR_STRING_CTRL  sCH__TEST_HE_CENTER_WAFER_LEAK_CHECK_REF;
	CX__VAR_STRING_CTRL  sCH__TEST_HE_EDGE_WAFER_LEAK_CHECK_REF;
	//

	// Config Parameter ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_He_DUMP_TIME_BEFORE_DECHUCK;

	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_POWER_ZERO_VOLTAGE_READING_NOISE_RANGE;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ESC_POWER_ZERO_CURRENT_READING_NOISE_RANGE;

	//
	CX__VAR_DIGITAL_CTRL dCH__CFG_HW_CHECK_USE_DURING_INITIAL;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_PRESSURE_FOR_HW_CHECK;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_PRESSURE_FOR_HW_CHECK;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_BYPASS_FLOW_FOR_HW_CHECK;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_BYPASS_FLOW_FOR_HW_CHECK;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_FLOW_ERROR_RANGE_FOR_HW_CHECK;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_STABLE_TIME_FOR_HW_CHECK;

	// Dechuck Verify ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_He_DECHUCK_CHECK_APPLY;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_MINIMUM_LEAK_FOR_DECHUCK_VERIFY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_CENTER_PRESSURE_DURING_DECHUCK_VERIFY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_EDGE_PRESSURE_DURING_DECHUCK_VERIFY;
	CX__VAR_STRING_CTRL  sCH__CUR_HE_CENTER_BYPASS_FLOW_FOR_DECHUCK_VERIFY;
	CX__VAR_STRING_CTRL  sCH__CUR_HE_EDGE_BYPASS_FLOW_FOR_DECHUCK_VERIFY;

	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_BYPASS_FLOW_STABLE_TIME_FOR_DECHUCK_VERIFY;
	CX__VAR_ANALOG_CTRL  aCH__CFG_HE_FINAL_FLOW_STABLE_TIME_FOR_DECHUCK_VERIFY;

	// Dechucking Parameter ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_CENTER_DECHUCK_X__STEPx_VOLT[DEF__DECHUCK_MODE_SIZE][DEF_DECHUCK__STEP_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_EDGE_DECHUCK_X__STEPx_VOLT[DEF__DECHUCK_MODE_SIZE][DEF_DECHUCK__STEP_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_DECHUCK_X__STEPx_TIME[DEF__DECHUCK_MODE_SIZE][DEF_DECHUCK__STEP_SIZE];

	CX__VAR_ANALOG_CTRL  aCH__CFG_CENTER_DECHUCK_X__LAST_VOLT[DEF__DECHUCK_MODE_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_EDGE_DECHUCK_X__LAST_VOLT[DEF__DECHUCK_MODE_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_DECHUCK_X__LAST_TIME[DEF__DECHUCK_MODE_SIZE];
	//

	// Recipe Parameter ...
	CX__VAR_STRING_CTRL  sCH__RCP_STABLE_CHECK_COUNT;

	CX__VAR_STRING_CTRL  sCH__RCP_He_CENTER_PRESSURE_SETPOINT_TORR;
	CX__VAR_STRING_CTRL  sCH__RCP_He_EDGE_PRESSURE_SETPOINT_TORR;

	CX__VAR_STRING_CTRL  sCH__RCP_He_CENTER_FLOW_MAX_THRESHOLD;
	CX__VAR_STRING_CTRL  sCH__RCP_He_CENTER_FLOW_MIN_THRESHOLD;

	CX__VAR_STRING_CTRL  sCH__RCP_He_EDGE_FLOW_MAX_THRESHOLD;
	CX__VAR_STRING_CTRL  sCH__RCP_He_EDGE_FLOW_MIN_THRESHOLD;

	// CFG Interlock ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_LEVEL_ALL;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_LEVEL_VACUUM;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_LEVEL_WAFER;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_LEVEL_CHM_ISO;

	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_MODE_ALL;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_MODE_VACUUM;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_MODE_WAFER;
	CX__VAR_DIGITAL_CTRL dCH__CFG_INTERLOCK_MODE_CHM_ISO;
	//


	//-------------------------------------------------------------------------
	// EXTERNAL PROPERTY

	// OBJ.DB_INF ...
	CX__VAR_STRING_CTRL  sEXT_CH__CHM_PRESSURE_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__WAFER_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_DECHUCK_CTRL_MODE;

	bool bActive__SHUTTER_STATUS;
	CX__VAR_STRING_CTRL  sEXT_CH__SHUTTER_STATUS;

	bool bActive__SLOT_VALVE_STATE;
	CX__VAR_STRING_CTRL  sEXT_CH__SLOT_VALVE_STATE;

	// OBJ.DB_SYS ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_PMC_ATM_MAINT_ACTIVE;

	// LINK Channel ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CONFIG_SAVE;

	// IO OBJ ...
	// ESC All ...
	CX__VAR_DIGITAL_CTRL doEXT_CH__ESC_All_Voltage;

	// Center & Edge Use ...
	bool bActive__CENTER_USE;
	bool bActive__CENTER_3WAY_VLV;

	bool bActive__EDGE_USE;
	bool bActive__EDGE_3WAY_VLV;

	// ECS Center ...
	CX__VAR_ANALOG_CTRL  aoEXT_CH__ESC_Voltage_CENTER;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__ESC_Voltage_CENTER;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__ESC_Current_CENTER;

	// ECS Edge ...
	CX__VAR_ANALOG_CTRL  aoEXT_CH__ESC_Voltage_EDGE;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__ESC_Voltage_EDGE;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__ESC_Current_EDGE;

	// He_Line Type ...
	int iDATA__HE_LINE_TYPE;

	// Helium ...
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Side_Supply_Vlv;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Exhaust_Vlv;

	// He.Center.Vlv 
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Final_Out_Vlv_CENTER;

	bool bActive__He_Final_Dump_Vlv_CENTER;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Final_Dump_Vlv_CENTER;

	bool bActive__He_Side_Dump_Vlv_CENTER;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Side_Dump_Vlv_CENTER;

	bool bActive__He_Side_Exhaust_Vlv_CENTER;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Side_Exhaust_Vlv_CENTER;

	// He.Edge.Vlv
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Final_Out_Vlv_EDGE;

	bool bActive__He_Final_Dump_Vlv_EDGE;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Final_Dump_Vlv_EDGE;

	bool bActive__He_Side_Dump_Vlv_EDGE;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Side_Dump_Vlv_EDGE;

	bool bActive__He_Side_Exhaust_Vlv_EDGE;
	CX__VAR_DIGITAL_CTRL doEXT_CH__He_Side_Exhaust_Vlv_EDGE;

	// He.Center.PRessure
	CX__VAR_ANALOG_CTRL  aoEXT_CH__He_Pressure_CENTER;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__He_Pressure_CENTER_IO;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__He_Flow_CENTER_IO;

	// He.Edge.PRessure
	CX__VAR_ANALOG_CTRL  aoEXT_CH__He_Pressure_EDGE;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__He_Pressure_EDGE_IO;
	CX__VAR_ANALOG_CTRL  aiEXT_CH__He_Flow_EDGE_IO;

	// ESC_IO OBJ ...
	CII_EXT_OBJECT__CTRL *pOBJ_CTRL__ESC_IO;

	CX__VAR_ANALOG_CTRL  eaoEXT_CH__ESC_IO__CUR_LIMIT_SETPOINT_CENTER;
	CX__VAR_ANALOG_CTRL  eaoEXT_CH__ESC_IO__CUR_LIMIT_SETPOINT_EDGE;
	//


	//------------------------------------------------------------------------------
	// INIT ...
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// TO.DECHUCKED ...
	CString sMODE__TO_DECHUCKED;
	int  Call__TO_DECHUCKED(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// HE.CLOSE ...
	CString sMODE__HE_CLOSE;
	int  Call__HE_CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__HE_CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// HW.CHECK ...
	CString sMODE__HW_CHECK;
	int  Call__HW_CHECK(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__HW_CHECK(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// DECHUCK.VERIFY ...
	CString sMODE__DECHUCK_VERIFY;
	int  Call__DECHUCK_VERIFY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__DECHUCK_VERIFY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// VENT.READY ...
	CString sMODE__VENT_READY;
	int  Call__VENT_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__VENT_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// PUMP.READY ...
	CString sMODE__PUMP_READY;
	int  Call__PUMP_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__PUMP_READY(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// CHUCK ...
	CString sMODE__CHUCK_CFG;
	CString sMODE__CHUCK1_CFG;
	CString sMODE__CHUCK2_CFG;
	int  Call__CHUCK_OF_CONFIG(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const int chuck_mode);

	CString sMODE__CHUCK_TEST;
	CString sMODE__CHUCK_PROC;
	CString sMODE__CHUCK1_PROC;
	CString sMODE__CHUCK2_PROC;
	int  Call__CHUCK_OF_PROCESS(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const int proc_mode);

	int  Fnc__CHUCK(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const int chuck_mode);

	int  Fnc__HV_SENSOR_INTERLOCK_CHECK(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__HV_SETPOINT_INTERLOCK_CHECK(CII_OBJECT__ALARM* p_alarm, const double set_volt_center,const double set_volt_edge);
	int  Fnc__HE_SETPOINT_INTERLOCK_CHECK(CII_OBJECT__ALARM* p_alarm, const double center_pressure,const double edge_pressure);

	int  Fnc__HV_ERROR_CHECK(CII_OBJECT__ALARM* p_alarm, const int check_point, const int alm_report = 1);
	int  Fnc__HE_ERROR_CHECK(CII_OBJECT__ALARM* p_alarm, const int he_type,const int check_point, const int alm_report = 1);

	// HE_SET.PROC ...
	CString sMODE__HE_SET_PROC;
	int  Call__HE_SET_OF_PROC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	int  Fnc__HE_SET_OF_PROC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// DECHUCK ...
	CString sMODE__DECHUCK_END;
	CString sMODE__DECHUCK;
	CString sMODE__DECHUCK1;
	CString sMODE__DECHUCK2;

	int  Call__DECHUCK(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const int dechuck_mode);

	int  Fnc__DECHUCK(CII_OBJECT__VARIABLE* p_variable, 
						CII_OBJECT__ALARM* p_alarm, 
						const int dechuck_mode);

	int  Fnc__ESC_ABORT(CII_OBJECT__VARIABLE *p_variable, 
						CII_OBJECT__ALARM *p_alarm, 
						const CString err_msg);

	// ...
	int  He_REQ_Fnc__Init(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  He_REQ_Fnc__Open_Supply(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm, const double set_press);
	int  He_REQ_Fnc__Close_Supply(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  He_REQ_Fnc__Open_Final(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	int  He_REQ_Fnc__Close_Final(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm);
	//


	//------------------------------------------------------------------------------
	// ...
	void Mon__REQ_CTRL(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	void Mon__SYS_INFO(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);

	void Mon__ESC_STABLE_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	void Mon__HELIUM_STABLE_CHECK(CII_OBJECT__VARIABLE *p_variable, CII_OBJECT__ALARM *p_alarm);
	//


	//------------------------------------------------------------------------------
	// ...
	int  Check__CHUCK_STATUS(CII_OBJECT__ALARM *p_alarm, const CString status);

	// ...
	int  Alarm__CHECK_RETRY_ABORT(CII_OBJECT__ALARM *p_alarm, const CString msg, const int alarm_id);
	void Alarm__CHECK_POST(CII_OBJECT__ALARM *p_alarm, const CString msg, const int alarm_id);
	//


public:
	CObj__ESC_IO();
	~CObj__ESC_IO();

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
