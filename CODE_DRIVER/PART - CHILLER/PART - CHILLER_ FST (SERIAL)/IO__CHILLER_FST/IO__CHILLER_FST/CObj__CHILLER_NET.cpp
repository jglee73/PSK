#include "StdAfx.h"
#include "CObj__CHILLER_NET.h"
#include "CObj__CHILLER_NET__DEF.h"
#include "CCommon_DEF.h"



//--------------------------------------------------------------------------------
CObj__CHILLER_NET::CObj__CHILLER_NET()
{

}
CObj__CHILLER_NET::~CObj__CHILLER_NET()
{

}

//--------------------------------------------------------------------------------
int CObj__CHILLER_NET::__DEFINE__CONTROL_MODE(obj, l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT, "INIT");

		ADD__CTRL_VAR(sMODE__LOCAL,  "LOCAL");
		ADD__CTRL_VAR(sMODE__REMOTE, "REMOTE");

		ADD__CTRL_VAR(sMODE__RUN,  "RUN");
		ADD__CTRL_VAR(sMODE__STOP, "STOP");
	}

	return 1;
}
int CObj__CHILLER_NET::__DEFINE__VERSION_HISTORY(version)
{
	version = "By JG Lee \n";

	return 1;
}


// ...
#define  MON_ID__IO_MONITOR						1


int CObj__CHILLER_NET::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE

	// ...
	CString str_name;
	int i;

	// OBJ ...
	{
		str_name = "OBJ.MSG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__OBJ_MSG, str_name);
	}

	// INFO ...
	{
		str_name = "INFO.DRV.IP_PORTT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_DRV_IP_PORT, str_name);

		str_name = "INFO.DRV.PARAMETER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_DRV_PARAMETER, str_name);
	}

	// MON...
	{
		str_name = "MON.COMM.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_COMM_STS, str_name);

		//
		str_name = "MON.ACTIVE.FAULT.ALL";	
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dCH__MON_ACTIVE_FAULT_ALL, str_name);

		str_name = "MON.ACTIVE.WARNING.ALL";	
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dCH__MON_ACTIVE_WARNING_ALL, str_name);
	}

	// MON.STATE...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		int id = i + 1;

		// Error ...
		{
			str_name.Format("MON.ACTIVE.FAULT.%1d", id);
			STD__ADD_DIGITAL(str_name, "OFF ON");
			LINK__VAR_DIGITAL_CTRL(dCH__MON_ACTIVE_FAULT_X[i], str_name);

			str_name.Format("MON.ACTIVE.WARNING.%1d", id);
			STD__ADD_DIGITAL(str_name, "OFF ON");
			LINK__VAR_DIGITAL_CTRL(dCH__MON_ACTIVE_WARNING_X[i], str_name);
		}

		// Common ...
		{
			str_name.Format("MON.ACTUAL_TEMPERATURE.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_ACTUAL_TEMPERATURE_X[i], str_name);

			str_name.Format("MON.FLOW_RATE.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_FLOW_RATE_X[i], str_name);

			str_name.Format("MON.RESISTIVITY.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_RESISTIVITY_X[i], str_name);
		}

		// Status.1
		{
			str_name.Format("MON.CONNECT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_CONNECT_X[i], str_name);

			str_name.Format("MON.LEVEL_FULL.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_LEVEL_FULL_X[i], str_name);

			str_name.Format("MON.CONTROL.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_CONTROL_X[i], str_name);
		}
		// Status.2
		{
			str_name.Format("MON.COMP_THERMOSTAT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_COMP_THERMOSTAT_X[i], str_name);

			str_name.Format("MON.OVER_TEMPERATURE_HW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_OVER_TEMPERATURE_HW_X[i], str_name);

			str_name.Format("MON.OVER_TEMPERATURE_SW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_OVER_TEMPERATURE_SW_X[i], str_name);

			str_name.Format("MON.TEMPERATURE_FAIL.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_TEMPERATURE_FAIL_X[i], str_name);
		}
		// Status.3
		{
			str_name.Format("MON.COMP_OVER_CURRENT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_COMP_OVER_CURRENT_X[i], str_name);

			str_name.Format("MON.COMP_PRESSURE_FAIL.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_COMP_PRESSURE_FAIL_X[i], str_name);

			str_name.Format("MON.PUMP_OVER_CURRENT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_PUMP_OVER_CURRENT_X[i], str_name);

			str_name.Format("MON.PUMP_PRESSURE_FAIL.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_PUMP_PRESSURE_FAIL_X[i], str_name);
		}
		// Status.4
		{
			str_name.Format("MON.TEMP_RANGE_OVER_LIMIT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_TEMP_RANGE_OVER_LIMIT_X[i], str_name);

			str_name.Format("MON.LEVEL_EMPTY.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_LEVEL_EMPTY_X[i], str_name);

			str_name.Format("MON.FLOW_LOW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_FLOW_LOW_X[i], str_name);
		}
		// Status.5
		{
			str_name.Format("MON.PCW_PRESSURE_LOW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_PCW_PRESSURE_LOW_X[i], str_name);

			str_name.Format("MON.ANTI_PHASE.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_ANTI_PHASE_X[i], str_name);

			str_name.Format("MON.WATER_LEAK.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_WATER_LEAK_X[i], str_name);
		}

		// Status.8
		{
			str_name.Format("MON.TOTAL_FAULT.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_TOTAL_FAULT_X[i], str_name);
		}
		// Status.9
		{
			str_name.Format("MON.LEVEL_LOW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_LEVEL_LOW_X[i], str_name);

			str_name.Format("MON.TEMP_ALARM.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_TEMP_ALARM_X[i], str_name);
		}
		// Status.10
		{
			str_name.Format("MON.TOTAL_WARNING.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_TOTAL_WARNING_X[i], str_name);

			str_name.Format("MON.PLC_BATTERY_LOW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_PLC_BATTERY_LOW_X[i], str_name);

			str_name.Format("MON.RESISTIVITY_LOW.%1d", id);
			STD__ADD_STRING(str_name);
			LINK__VAR_STRING_CTRL(sCH__MON_RESISTIVITY_LOW_X[i], str_name);
		}
	}

	// PARA.USER ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("PARA.USER.TEMPERATURE.%1d", id);
		STD__ADD_ANALOG(str_name, "C", 1, 0, 100);
		LINK__VAR_ANALOG_CTRL(aCH__PARA_USER_TEMPERATURE_X[i], str_name);

		//
		str_name.Format("PARA.USER.CONTROL.%1d", id);
		STD__ADD_DIGITAL(str_name, "STOP RUN");
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_USER_CONTROL_X[i], str_name);

		str_name.Format("PARA.USER.CONNECT.%1d", id);
		STD__ADD_DIGITAL(str_name, "LOCAL REMOTE");
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_USER_CONNECT_X[i], str_name);
	}

	// PARA.SET ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("PARA.SET.TEMPERATURE.%1d", id);
		STD__ADD_ANALOG(str_name, "C", 1, 0, 100);
		LINK__VAR_ANALOG_CTRL(aCH__PARA_SET_TEMPERATURE_X[i], str_name);

		//
		str_name.Format("PARA.SET.CONTROL.%1d", id);
		STD__ADD_DIGITAL(str_name, "STOP RUN");
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_SET_CONTROL_X[i], str_name);

		str_name.Format("PARA.SET.CONNECT.%1d", id);
		STD__ADD_DIGITAL(str_name, "LOCAL REMOTE");
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_SET_CONNECT_X[i], str_name);
	}

	// CFG ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("CFG.INIT.TEMPERATURE.%1d", id);
		STD__ADD_ANALOG(str_name, "C", 1, 0, 100);
		LINK__VAR_ANALOG_CTRL(aCH__CFG_INIT_TEMPERATURE_X[i], str_name);

		//
		str_name.Format("CFG.INIT.CONTROL.%1d", id);
		STD__ADD_DIGITAL(str_name, "STOP RUN");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INIT_CONTROL_X[i], str_name);

		str_name.Format("CFG.INIT.CONNECT.%1d", id);
		STD__ADD_DIGITAL(str_name, "LOCAL REMOTE");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_INIT_CONNECT_X[i], str_name);
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(3.0,MON_ID__IO_MONITOR);
	}
	return 1;
}
int CObj__CHILLER_NET::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CString alarm_bff;
	CStringArray l_act;

	int alarm_id;
	int i;

	// Offline ...
	{
		alarm_id = ALID__OFFLINE_ALARM;

		alarm_title  = title;
		alarm_title += "Pump Offline !";

		alarm_msg = "Check the status of communication !";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// PART.FAULT ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		alarm_id = ALID__PART_FAULT + i;

		alarm_title  = title;
		alarm_bff.Format("Channel(%1d) Fault !", i+1);
		alarm_title += alarm_bff;

		alarm_msg = "Please, check the state of chiller !";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// PART.WARNING ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		alarm_id = ALID__PART_WARNING + i;

		alarm_title  = title;
		alarm_bff.Format("Channel(%1d) Warning !", i+1);
		alarm_title += alarm_bff;

		alarm_msg = "Please, check the state of chiller !";

		l_act.RemoveAll();
		l_act.Add("CHECK");

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	return 1;
}


// ...
#define _LIST__SET					\
	"Set"


int CObj__CHILLER_NET::__DEFINE__VARIABLE_IO(p_io_variable)
{
	DECLARE__IO_VARIABLE;

	// ...
	CString str_name;
	int i;

	// DO ...
	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("do.CHANNEL_SET.%02d", id);
		IO__ADD_DIGITAL_WRITE(str_name, _LIST__SET);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__CHANNEL_SET_X[i], str_name);
	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__CHILLER_NET::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{
	CString file_name;
	CString log_msg;

	CString def_name;
	CString obj_name;
	CString ch_name;
	CString var_name;

	// ...
	{
		file_name.Format("%s_APP.log", sObject_Name);

		log_msg  = "\n\n";
		log_msg += "//------------------------------------------------------------------------";

		xAPP__LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
		xAPP__LOG_CTRL->SET__PROPERTY(file_name,12*1,60);

		xAPP__LOG_CTRL->DISABLE__TIME_LOG();
		xAPP__LOG_CTRL->WRITE__LOG(log_msg);

		xAPP__LOG_CTRL->ENABLE__TIME_LOG();
		xAPP__LOG_CTRL->WRITE__LOG("   START   \n");
	}

	// ...
	{
		file_name.Format("%s-DRV.log", sObject_Name);

		log_msg  = "\n\n";
		log_msg += "//------------------------------------------------------------------------";

		xDRV__LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
		xDRV__LOG_CTRL->SET__PROPERTY(file_name, 2*3, 30);

		xDRV__LOG_CTRL->DISABLE__TIME_LOG();
		xDRV__LOG_CTRL->WRITE__LOG(log_msg);

		xDRV__LOG_CTRL->ENABLE__TIME_LOG();
		xDRV__LOG_CTRL->WRITE__LOG("   START   \n");
	}

	// ...
	{
		SCX__SEQ_INFO x_seq_info;

		iActive__SIM_MODE = x_seq_info->Is__SIMULATION_MODE();
	}
	return 1;
}
int CObj__CHILLER_NET
::__INITIALIZE__IO(p_io_para)
{
	//-------------------------------------------------------
	// Set Driver Parameter
	//------------------------------------------------------
	// ...
	CString para__net_ip = "127.0.0.1";
	int para__net_port   = -1;

	// ...
	{
		CString para_cmmd;
		CString para_data;

		// 1.
		{
			para_cmmd = "IP";

			if(p_io_para->Get__PARAMETER_DATA(para_cmmd, para_data) > 0)
			{
				para__net_ip = para_data;
			}
		}
		// 2.
		{
			para_cmmd = "PORT";

			if(p_io_para->Get__PARAMETER_DATA(para_cmmd, para_data) > 0)
			{
				para__net_port = atoi(para_data);
			}
		}

		//
		CString str_info;

		str_info.Format("%s (%1d)", para__net_ip,para__net_port);
		sCH__INFO_DRV_IP_PORT->Set__DATA(str_info);
	}

	// ...
	CString log_msg;
	CString log_bff;

	// ...
	{
		log_msg = "Connect to Ethernet-Server. \n";

		log_bff.Format("Net.IP : %s \n", para__net_ip);
		log_msg += log_bff;

		log_bff.Format("Net.Port : %1d \n", para__net_port);
		log_msg += log_bff;
	}

	// ...
	{
		CString str_info = "Terminal String : <CR>";

		sCH__INFO_DRV_PARAMETER->Set__DATA(str_info);

		//
		log_msg += str_info;
		log_msg += "\n";
		log_msg += "\n";
	}

	if(iActive__SIM_MODE > 0)
	{
		log_msg += "Initial Ethernet-Driver Complete. \n";
		log_msg += "Simulation Mode !!! \n";

		WRITE__DRV_LOG_MSG(log_msg);
		return -1;
	}

	// ...
	char end_str[10];
	end_str[0] = CR;

	mX_Net->SET__ETHERNET_TYPE__CLIENT();
	mX_Net->SET__TERMINAL_OutSTRING(end_str, 1);
	mX_Net->SET__TERMINAL_InSTRING(end_str,  1);

	mX_Net->INIT__PROPERTY(para__net_ip, para__net_port);

	// ...
	CString r_err;

	if(mX_Net->CONNECT(&r_err) < 0)
	{
		log_bff.Format("Connect() : Error ! \n");
		log_msg += log_bff;

		log_bff.Format(" * Error <- [%s] \n", r_err);
		log_msg += log_bff;

		WRITE__DRV_LOG_MSG(log_msg);
		return -1;
	}
	else
	{
		log_msg += "Connect() completed ! \n";

		WRITE__DRV_LOG_MSG(log_msg);
	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__CHILLER_NET::__CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm)
{
	int flag = -1;	

	// ...
	{
		IF__CTRL_MODE(sMODE__INIT)			flag = Call__INIT(p_variable,p_alarm);

		ELSE_IF__CTRL_MODE(sMODE__LOCAL)		flag = Call__LOCAL(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__REMOTE)		flag = Call__REMOTE(p_variable,p_alarm);

		ELSE_IF__CTRL_MODE(sMODE__RUN)			flag = Call__RUN(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__STOP)			flag = Call__STOP(p_variable, p_alarm);
	}

	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		CString log_msg;
		log_msg.Format("Aborted ... :  [%s]",mode);

		sCH__OBJ_MSG->Set__DATA(log_msg);
		WRITE__APP_LOG_MSG(log_msg);		
	}
	else
	{
		CString log_msg;
		log_msg.Format("Completed ... :  [%s]",mode);

		sCH__OBJ_MSG->Set__DATA(log_msg);
		WRITE__APP_LOG_MSG(log_msg);
	}

	return flag;
}

int CObj__CHILLER_NET::__CALL__MONITORING(id, p_variable, p_alarm)
{
	switch(id)
	{
		case MON_ID__IO_MONITOR:
			Mon__IO_MONITOR(p_variable,p_alarm);
			break;
	}

	return 1;
}
