#include "StdAfx.h"
#include "CObj__APS_8301.h"


//--------------------------------------------------------------------------------
CObj__APS_8301::CObj__APS_8301()
{
	m_Rcv_Time	= 1000;
	cfg__delay_sec = 0.0; //KMS
	bActive__Delay_Check = false;
}
CObj__APS_8301::~CObj__APS_8301()
{

}

//--------------------------------------------------------------------------------
int CObj__APS_8301::__DEFINE__CONTROL_MODE(obj, l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT, "INIT");

		ADD__CTRL_VAR(sMODE__ON,  "ON");
		ADD__CTRL_VAR(sMODE__OFF, "OFF");

		ADD__CTRL_VAR(sMODE__RAMP_UP,   "RAMP_UP");
		ADD__CTRL_VAR(sMODE__RAMP_DOWN, "RAMP_DOWN");

		ADD__CTRL_VAR(sMODE__ALARM_RESET, "ALARM_RESET");
	}

	return 1;
}
int CObj__APS_8301::__DEFINE__VERSION_HISTORY(version)
{
	version = "@pck 20180914 \n";

	return 1;
}


// ...
#define  MON_ID__IO_MONITOR				1


#define _LIST__OFF_ON					"OFF  ON"
#define _LIST__NO_YES					"NO  YES"


int CObj__APS_8301::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE

	// ...
	CString str_name;

	// OBJ ...
	{
		str_name = "OBJ.MSG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__OBJ_MSG, str_name);
	}

	// INFO ...
	{
		str_name = "INFO.DRV.COM_PORT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_DRV_COM_PORT, str_name);

		str_name = "INFO.DRV.PARAMETER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_DRV_PARAMETER, str_name);
	}

	// MON ...
	{
		str_name = "MON.COMM.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_COMM_STS, str_name);

		str_name = "MON.SYSTEM.ABORT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_SYSTEM_ABORT, str_name);

		str_name = "MON.ESC.STABLE.DELAY.TIME"; // KMS:221024
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__MON_ESC_STABLE_DELAY_TIME, str_name);
		mCtrl__Delay_Timer->REGISTER__COUNT_CHANNEL_NAME(sCH__MON_ESC_STABLE_DELAY_TIME->Get__CHANNEL_NAME());
	}

	// PARA ...
	{
		str_name = "PARA.VOLTAGE.SET";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "V", 0, 0, 3000, "");
		LINK__VAR_ANALOG_CTRL(aCH__PARA_VOLTAGE_SET, str_name);
	}

	// INFO ...
	{
		str_name = "INFO.POWER.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_POWER_STS, str_name);

		str_name = "INFO.HIGH_VOLTAGE.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_HIGH_VOLTAGE_STS, str_name);

		str_name = "INFO.REVERSE_VOLTAGE.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_REVERSE_VOLTAGE_STS, str_name);

		str_name = "INFO.OVER_CURRENT_ALARM.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_OVER_CURRENT_ALARM_STS, str_name);

		str_name = "INFO.SYSTEM_ALARM.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_SYSTEM_ALARM_STS, str_name);

		//
		str_name = "INFO.FIRMWARE_VER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_FIRMWARE_VER, str_name);
	}

	// CFG ...
	{
		// LIMIT ...
		{
			str_name = "CFG.STABLE.DELAY.TIME";								// KMS:221024
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 0, 10, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_STABLE_DELAY_SEC, str_name);

			str_name = "CFG.LEAK_CURRUNT.LIMIT";
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "µA", 0, 0, 9999, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_LEAK_CURRUNT_LIMIT, str_name);
		}

		// RAMP UP/DOWN ...
		{
			str_name = "CFG.RAMP.START_VOLTAGE";
			STD__ADD_ANALOG(str_name, "V", 0, 0, 3000, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_RAMP_START_VOLTAGE, str_name);

			str_name = "CFG.RAMP.UP_TIME";
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "msec", 0, 0, 9999, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_RAMP_UP_TIME, str_name);

			str_name = "CFG.RAMP.DOWN_TIME";
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "msec", 0, 0, 9999, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_RAMP_DOWN_TIME, str_name);
		}

		// AUTO_TOGGLE ...
		{
			str_name = "CFG.AUTO_TOGGLE.USE";
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, _LIST__NO_YES, "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_AUTO_TOGGLE_USE, str_name);

			str_name = "CFG.AUTO_TOGGLE.COUNT";
			STD__ADD_ANALOG(str_name, "count", 0, 0, 9999, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_AUTO_TOGGLE_COUNT, str_name);

			str_name = "CFG.AUTO_TOGGLE.START_VOLTAGE";
			STD__ADD_ANALOG(str_name, "V", 0, 0, 3000, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_AUTO_TOGGLE_START_VOLTAGE, str_name);

			str_name = "CFG.AUTO_TOGGLE.DOWN_RATE";
			STD__ADD_ANALOG(str_name, "%", 1, 0, 100, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_AUTO_TOGGLE_DOWN_RATE, str_name);
		}
		
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(3.0, MON_ID__IO_MONITOR);
	}
	return 1;
}
int CObj__APS_8301::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;
	int alarm_id;

	// ...
	{
		alarm_id = ALID__ESC_OFFLINE_ALARM;

		alarm_title  = title;
		alarm_title += "ESC Communication Offline !";

		alarm_msg = "ESC Controller Offline !";

		l_act.RemoveAll();
		l_act.Add(ACT__CHECK);

		ADD__ALARM_EX(alarm_id, alarm_title, alarm_msg, l_act);
	}

	// ...
	{
		alarm_id = ALID__ESC_HIGH_CURRENT_LIMIT;

		alarm_title  = title;
		alarm_title += "ESC Leak-Current Limit !";

		alarm_msg = "A high leak-current error has occurred.";

		l_act.RemoveAll();
		l_act.Add(ACT__ABORT);

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	return 1;
}

// ...
int CObj__APS_8301::__DEFINE__VARIABLE_IO(p_io_variable)
{
	DECLARE__IO_VARIABLE;

	//-------------------------------------------------------
	CString str_name;

	// Analog ...
	{
		// AO ...
		{
			str_name = "ao.ESC.VOLTAGE_SET";
			IO__ADD_ANALOG_WRITE(str_name, "V", 0, 0, 3000);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ESC_VOLTAGE_SET, str_name);
		
			str_name = "ao.ESC.CURRENT_LIMIT_SET";
			IO__ADD_ANALOG_WRITE(str_name, "µA", 0, 0, 999);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ESC_CURRENT_LIMIT_SET, str_name);

			//
			str_name = "ao.ESC.TIME_DELAY.SET";
			IO__ADD_ANALOG_WRITE(str_name, "msec", 0, 0, 9999);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ESC_TIME_DELAY_SET, str_name);

			str_name = "ao.ESC.RAMP_TIME.SET";
			IO__ADD_ANALOG_WRITE(str_name, "msec", 0, -9999, 9999);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ESC_RAMP_TIME_SET, str_name);
		}
	}

	// Digital ...
	{
		// DO ...
		{
			str_name = "do.ESC.POWER.SET";
			IO__ADD_DIGITAL_WRITE(str_name, _LIST__OFF_ON);	
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ESC_POWER_SET, str_name);

			str_name = "do.ESC.VOLTAGE_OUTPUT.SET";
			IO__ADD_DIGITAL_WRITE(str_name, _LIST__OFF_ON);	
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ESC_VOLTAGE_OUTPUT_SET, str_name);

			str_name = "do.ESC.DISCHARGE_MODE.SET";
			IO__ADD_DIGITAL_WRITE(str_name, _LIST__OFF_ON);	
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ESC_DISCHARGE_MODE_SET, str_name);

			str_name = "do.ESC.ALARM_RESET.SET";
			IO__ADD_DIGITAL_WRITE(str_name, _LIST__OFF_ON);	
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ESC_ALARM_RESET_SET, str_name);
		}
	}

	// String ...
	{
		// SI ...
		{
			str_name = "si.ESC.VOLTAGE";
			IO__ADD_STRING_READ_WITH_OPTION(str_name, "", "", "", 0.1, "");
			IO__CHANGE_ANALOG__LOG_INTERVAL();
			LINK__IO_VAR_STRING_CTRL(siCH__ESC_VOLTAGE, str_name);
		
			str_name = "si.ESC.LEAK_CURRENT";
			IO__ADD_STRING_READ_WITH_OPTION(str_name, "", "", "", 0.1, "");
			IO__CHANGE_ANALOG__LOG_INTERVAL();
			LINK__IO_VAR_STRING_CTRL(siCH__ESC_LEAK_CURRENT, str_name);

			str_name = "si.ESC.SYSTEM_STS";
			IO__ADD_STRING_READ(str_name);
			LINK__IO_VAR_STRING_CTRL(siCH__ESC_SYSTEM_STS, str_name);

			str_name = "si.ESC.FIRMWARE_VER";
			IO__ADD_STRING_READ__MANUAL(str_name);
			LINK__IO_VAR_STRING_CTRL(siCH__ESC_FIRMWARE_VER, str_name);
		}
	}

	return 1;
}

//--------------------------------------------------------------------------------
int CObj__APS_8301::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{
	CString def_name;
	CString def_data;

	// ...
	{
		CString file_name;
		CString log_msg;

		// APP Log ...
		{
			file_name.Format("%s__APP.log", sObject_Name);

			log_msg  = "\n\n";
			log_msg += "//------------------------------------------------------------------------";

			xI__APP_LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
			xI__APP_LOG_CTRL->SET__PROPERTY(file_name,12*1,60);

			xI__APP_LOG_CTRL->DISABLE__TIME_LOG();
			xI__APP_LOG_CTRL->WRITE__LOG(log_msg);

			xI__APP_LOG_CTRL->ENABLE__TIME_LOG();
			xI__APP_LOG_CTRL->WRITE__LOG("   START   \n");
		}

		// DRV Log ...
		{
			file_name.Format("%s__DRV.log", sObject_Name);

			log_msg  = "\n\n";
			log_msg += "//------------------------------------------------------------------------";

			xI__DRV_LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
			xI__DRV_LOG_CTRL->SET__PROPERTY(file_name,12*1,60);

			xI__DRV_LOG_CTRL->DISABLE__TIME_LOG();
			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);

			xI__DRV_LOG_CTRL->ENABLE__TIME_LOG();
			xI__DRV_LOG_CTRL->WRITE__LOG("   START   \n");
		}
	}

	// ...
	{
		iFLAG__DRV_FLAG = 1;
	}

	// ...
	{
		SCX__SEQ_INFO x_seq_info;

		iActive_SIM = x_seq_info->Is__SIMULATION_MODE();
	}
	return 1;
}

int CObj__APS_8301::__INITIALIZE__IO(p_io_para)
{
	int com_port = -1;

	int nRate   = 9600;
	int nByte   = 8;			// 5, 6, 7, 8
	int nStop   = 1;			// 1, 2
	int nParity = 0;			// 0 ~ 4 : None, Odd, Even, Mark, Space

	sTerm_Str = (char) CR;	
	sTerm_Exp = "CR";	

	// ...
	{
		CString str_cmmd;
		CString str_data;

		// 1.
		{
			str_cmmd = "COM_PORT";

			if(p_io_para->Get__PARAMETER_DATA(str_cmmd, str_data) > 0)
			{
				com_port = atoi(str_data);
			}
		}

		// ...
		CString str_info;

		str_info.Format("%1d", com_port);
		sCH__INFO_DRV_COM_PORT->Set__DATA(str_info);
	}

	// ...
	CString log_msg;
	CString log_bff;

	// ...
	{
		log_msg = "Connect to Serial \n";

		log_bff.Format("Com Port: %1d \n", com_port);
		log_msg += log_bff;

		log_bff.Format("Baud Rate: %1d \n", nRate);
		log_msg += log_bff;

		log_bff.Format("Data Bit: %1d \n", nByte);
		log_msg += log_bff;

		log_bff.Format("Parity Bit: %1d \n", nParity);
		log_msg += log_bff;

		log_bff.Format("Stop Bit: %1d \n", nStop);
		log_msg += log_bff;

		//
		log_msg += "Terminal String : Byte Count \n";							  
	}

	// ...
	{
		CString str_info;

		str_info.Format("Rate[%1d] DataBit[%1d] StopBit[%1d] Parity[%1d]",
						nRate, 
						nByte, 
						nStop, 
						nParity);

		sCH__INFO_DRV_PARAMETER->Set__DATA(str_info);

		//
		log_bff.Format("Terminal String : [%s] \n", sTerm_Exp);
		log_msg += log_bff;
	}

	if(iActive_SIM > 0)
	{
		log_msg += "Initialize RS-232 Complete \n";
		log_msg += "Simulation Mode !!! \n";

		Write__APP_LOG(log_msg);
		Write__DRV_LOG(log_msg);
		return -1;
	}

	if(mX_Serial->INIT__COMPORT(com_port, nRate, nByte, nStop, nParity) < 0)
	{
		log_bff.Format("Fail to do INIT__COMPORT: %d, ret:-1\n", com_port);
		log_msg += log_bff;

		Write__APP_LOG(log_msg);
		Write__DRV_LOG(log_msg);
		return -1;
	}
	else
	{
		log_msg += "Initialize RS-232 Complete \n";

		Write__APP_LOG(log_msg);
		Write__DRV_LOG(log_msg);
	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__APS_8301::__CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm)
{
	CString log_msg;
	int flag = -1;

	// ...
	{
		log_msg.Format("%s Started...", mode);
		sCH__OBJ_MSG->Set__DATA(log_msg);

		Write__APP_LOG(log_msg);
	}

	// ...
	{
			 IF__CTRL_MODE(sMODE__INIT)				flag = Call__INIT(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ON)				flag = Call__ON(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__OFF)				flag = Call__OFF(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__RAMP_UP)			flag = Call__RAMP_UP(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__RAMP_DOWN)		flag = Call__RAMP_DOWN(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ALARM_RESET)		flag = Call__ALARM_RESET(p_variable, p_alarm);
	}

	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		log_msg.Format("%s Aborted (%1d)", mode, flag);
	}
	else
	{
		log_msg.Format("%s Completed (%1d)", mode, flag);
	}	

	// ...
	{
		sCH__OBJ_MSG->Set__DATA(log_msg);

		Write__APP_LOG(log_msg);
	}
	return flag;
}

int CObj__APS_8301::__CALL__MONITORING(id, p_variable, p_alarm)
{
	switch(id)
	{
		case MON_ID__IO_MONITOR:
			Mon__IO_MONITOR(p_variable, p_alarm);
			break;
	}

	return 1;
}
