#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"

#include "CObj__CHILLER_NET__DEF.h"


class CObj__CHILLER_NET : public __IOBJ__IO_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	// ...
	SCX__ETHERNET_JGLEE mX_Net;

	bool bActive__COMM_ONLINE;;
	int iActive__SIM_MODE;
	//

	//-------------------------------------------------------------------------
	SCX__USER_LOG_CTRL xAPP__LOG_CTRL;
	SCX__USER_LOG_CTRL xDRV__LOG_CTRL;

	void WRITE__APP_LOG_MSG(const CString& log_msg);
	void WRITE__DRV_LOG_MSG(const CString& log_msg);
	//

	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;

	// INFO ...
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_IP_PORT;
	CX__VAR_STRING_CTRL  sCH__INFO_DRV_PARAMETER;

	// PARA.USER ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_USER_TEMPERATURE_X[_CFG__CH_SIZE];

	CX__VAR_DIGITAL_CTRL dCH__PARA_USER_CONTROL_X[_CFG__CH_SIZE];
	CX__VAR_DIGITAL_CTRL dCH__PARA_USER_CONNECT_X[_CFG__CH_SIZE];

	// PARA.SET ...
	CX__VAR_ANALOG_CTRL  aCH__PARA_SET_TEMPERATURE_X[_CFG__CH_SIZE];

	CX__VAR_DIGITAL_CTRL dCH__PARA_SET_CONTROL_X[_CFG__CH_SIZE];
	CX__VAR_DIGITAL_CTRL dCH__PARA_SET_CONNECT_X[_CFG__CH_SIZE];

	// CFG ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_INIT_TEMPERATURE_X[_CFG__CH_SIZE];

	CX__VAR_DIGITAL_CTRL dCH__CFG_INIT_CONTROL_X[_CFG__CH_SIZE];
	CX__VAR_DIGITAL_CTRL dCH__CFG_INIT_CONNECT_X[_CFG__CH_SIZE];

	// IMON ...
	CX__VAR_STRING_CTRL  sCH__MON_COMM_STS;	

	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_FAULT_ALL;	
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_WARNING_ALL;	

	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_FAULT_X[_CFG__CH_SIZE];	
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_WARNING_X[_CFG__CH_SIZE];	

	// MON.STATE ...
	CX__VAR_STRING_CTRL  sCH__MON_ACTUAL_TEMPERATURE_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_FLOW_RATE_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_RESISTIVITY_X[_CFG__CH_SIZE];

	// Status.1
	CX__VAR_STRING_CTRL  sCH__MON_CONNECT_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_LEVEL_FULL_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_CONTROL_X[_CFG__CH_SIZE];

	// Status.2
	CX__VAR_STRING_CTRL  sCH__MON_COMP_THERMOSTAT_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_OVER_TEMPERATURE_HW_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_OVER_TEMPERATURE_SW_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_TEMPERATURE_FAIL_X[_CFG__CH_SIZE];

	// Status.3
	CX__VAR_STRING_CTRL  sCH__MON_COMP_OVER_CURRENT_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_COMP_PRESSURE_FAIL_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_PUMP_OVER_CURRENT_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_PUMP_PRESSURE_FAIL_X[_CFG__CH_SIZE];

	// Status.4
	CX__VAR_STRING_CTRL  sCH__MON_TEMP_RANGE_OVER_LIMIT_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_LEVEL_EMPTY_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_FLOW_LOW_X[_CFG__CH_SIZE];

	// Status.5
	CX__VAR_STRING_CTRL  sCH__MON_PCW_PRESSURE_LOW_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_ANTI_PHASE_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_WATER_LEAK_X[_CFG__CH_SIZE];

	// Status.8
	CX__VAR_STRING_CTRL  sCH__MON_TOTAL_FAULT_X[_CFG__CH_SIZE];

	// Status.9
	CX__VAR_STRING_CTRL  sCH__MON_LEVEL_LOW_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_TEMP_ALARM_X[_CFG__CH_SIZE];

	// Status.10
	CX__VAR_STRING_CTRL  sCH__MON_TOTAL_WARNING_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_PLC_BATTERY_LOW_X[_CFG__CH_SIZE];
	CX__VAR_STRING_CTRL  sCH__MON_RESISTIVITY_LOW_X[_CFG__CH_SIZE];
	//

	// IO CHANNEL  ...
	// DO
	CX__VAR_DIGITAL_CTRL doCH__CHANNEL_SET_X[_CFG__CH_SIZE];
	//

	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__LOCAL;
	int  Call__LOCAL(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	CString sMODE__REMOTE;
	int  Call__REMOTE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__RUN;
	int  Call__RUN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	CString sMODE__STOP;
	int  Call__STOP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	//

	// ...
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int _Get__CHECK_SUM(const CString& set_cmmd);
	int _Get__Hexa_From_String(const CString& str_data);

	// ...
	int _Drv__CMMD_SEND(const int para__ch_index);

	int _Update__STATE_01(const int ch_index, const CString& rsp_data);
	int _Update__STATE_02(const int ch_index, const CString& rsp_data);
	int _Update__STATE_03(const int ch_index, const CString& rsp_data);
	int _Update__STATE_04(const int ch_index, const CString& rsp_data);
	int _Update__STATE_05(const int ch_index, const CString& rsp_data);

	int _Update__STATE_08(const int ch_index, const CString& rsp_data);
	int _Update__STATE_09(const int ch_index, const CString& rsp_data);
	int _Update__STATE_10(const int ch_index, const CString& rsp_data);
	//


public:
	CObj__CHILLER_NET();
	~CObj__CHILLER_NET();

	// ...
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__VARIABLE_IO(p_rs232_variable);

	int __DEFINE__ALARM(p_alarm);

	// ...
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	int __INITIALIZE__IO(p_io_para);

	// ...
	int __CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm);
	int __CALL__MONITORING(id, p_variable, p_alarm);

	// ...
	int __Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data);
	int __Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index);
	int __Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data);

	int __Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data);
	int __Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index);
	int __Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data);
};
