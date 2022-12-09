#include "StdAfx.h"
#include "CObj__PM_METAL.h"
#include "CObj__PM_METAL__ALID.h"
#include "CObj__PM_METAL__DEF.h"


//--------------------------------------------------------------------------------
CObj__PM_METAL::CObj__PM_METAL()
{

}
CObj__PM_METAL::~CObj__PM_METAL()
{

}

//--------------------------------------------------------------------------------
int CObj__PM_METAL::__DEFINE__CONTROL_MODE(obj, l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT, "INIT");
	}
	return 1;
}
int CObj__PM_METAL::__DEFINE__VERSION_HISTORY(version)
{
	version = "JG.Lee \n";

	return 1;
}


// ...
#define  MON_ID__MONITOR				1

// ...
#define  APP_DSP__OFF_ON				"OFF  ON"
#define  APP_DSP__VLV_STS				"UNKNOWN  CLOSE  OPEN"


int CObj__PM_METAL::__DEFINE__VARIABLE_STD(p_variable)
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

	// DRV_INFO ...
	{
		str_name = "DRV_INFO.COM_PORT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_COM_PORT, str_name);

		str_name = "DRV_INFO.PROTOCOL";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_PROTOCOL, str_name);

		str_name = "DRV_INFO.MODBUS_ADDR";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_MODBUS_ADDR, str_name);

		str_name = "DRV_INFO.BAUD_RATE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_BAUD_RATE, str_name);

		str_name = "DRV_INFO.COMM_PARITY";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_COMM_PARITY, str_name);

		str_name = "DRV_INFO.DATA_BIT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_DATA_BIT, str_name);

		str_name = "DRV_INFO.STOP_BIT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DRV_INFO_STOP_BIT, str_name);
	}

	// INFO.BOTTLE.STATE ...
	for(i=0; i<_CFG_SIZE__BOTTLE; i++)
	{
		int id = i + 1;

		str_name.Format("INFO.BOTTLE.STATE.%1d", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_BOTTLE_STATE_X[i], str_name);

		str_name.Format("INFO.BOTTLE.MSG.%1d", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_BOTTLE_MSG_X[i], str_name);
	}
	
	// INFO.BOTTLE.VALVE ...
	for(i=0; i<_CFG_SIZE__BOTTLE; i++)
	{
		int id = i + 1;

		str_name.Format("INFO.BOTTLE.AV1.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV1_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV2.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV2_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV3.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV3_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV4.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV4_X[i], str_name);

		str_name.Format("INFO_BOTTLE.AV5.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV5_X[i], str_name);

		str_name.Format("INFO.BOTTLE.VS.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_VS_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV6.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV6_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV7.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV7_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV8.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV8_X[i], str_name);

		str_name.Format("INFO.BOTTLE.AV9.%1d", id);
		STD__ADD_DIGITAL(str_name, APP_DSP__VLV_STS);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_BOTTLE_AV9_X[i], str_name);
	}

	// NFO.ALARM.ACTIVE ...
	{
		str_name = "INFO.ALARM.ACTIVE.PURGE";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_PURGE, str_name);

		str_name = "INFO.ALARM.ACTIVE.HEAVY";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_HEAVY, str_name);

		str_name = "INFO.ALARM.ACTIVE.LIGHT";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_LIGHT, str_name);

		str_name = "INFO.ALARM.ACTIVE.EMERGENCY_STOP";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_EMERGENCY_STOP, str_name);

		str_name = "INFO.ALARM.ACTIVE.LEAK";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_LEAK, str_name);

		str_name = "INFO.ALARM.ACTIVE.FIRE";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_FIRE, str_name);

		str_name = "INFO.ALARM.ACTIVE.HIGH_TEMPERATURE";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_HIGH_TEMPERATURE, str_name);

		str_name = "INFO.ALARM.ACTIVE.PT1_LOW_1";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_PT1_LOW_1, str_name);

		str_name = "INFO.ALARM.ACTIVE.PT1_LOW_2";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_PT1_LOW_2, str_name);

		str_name = "INFO.ALARM.ACTIVE.CDA_LOW";
		STD__ADD_DIGITAL(str_name, APP_DSP__OFF_ON);
		LINK__VAR_DIGITAL_CTRL(dCH__INFO_ALARM_ACTIVE_CDA_LOW, str_name);
	}

	// ...
	{
		str_name = "INFO.BOTTLE.WEIGHT_PER";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_BOTTLE_WEIGHT_PER, str_name);

		//
		str_name = "INFO.PT1_PSI";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_PT1_PSI, str_name);

		str_name = "INFO.PT2_PSI";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_PT2_PSI, str_name);

		str_name = "INFO.PT3_PSI";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INFO_PT3_PSI, str_name);
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(3.0, MON_ID__MONITOR);
	}
	return 1;
}


// ...
#define  _LALM__CLEAR							\
l_act.RemoveAll();								\
l_act.Add(_ACT__CLEAR);


int CObj__PM_METAL::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;
	int alarm_id;

	CString str_bff;


	// Offline ...
	{
		alarm_id = ALID__OFFLINE;

		alarm_title  = title;
		alarm_title += "Offlne !";

		alarm_msg.Format("Please, check the stage of gas-cabinet !");

		_LALM__CLEAR;

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	return 1;
}


int CObj__PM_METAL::__DEFINE__VARIABLE_IO(p_io_variable)
{
	DECLARE__IO_VARIABLE;

	CString str_name;

	// SI ...
	{
		str_name = "si.D2000.BOTTLE.CONDITION";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2000_BOTTLE_CONDITION, str_name);

		str_name = "si.D2005.BOTTLE.WEIGHT_PER";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2005_BOTTLE_WEIGHT_PER, str_name);

		str_name = "si.D2007.BOTTLE.PT1";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2007_BOTTLE_PT1, str_name);

		str_name = "si.D2008.BOTTLE.PT2";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2008_BOTTLE_PT2, str_name);

		str_name = "si.D2009.BOTTLE.PT3";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2009_BOTTLE_PT3, str_name);

		str_name = "si.D2020.BOTTLE.VALVE";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2020_BOTTLE_VALVE, str_name);

		str_name = "si.D2029.ALARM.STATE";
		IO__ADD_STRING_READ(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__D2029_ALARM_STATE, str_name);
	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__PM_METAL::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
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
		SCX__SEQ_INFO x_seq_info;

		iActive__SIM_MODE = x_seq_info->Is__SIMULATION_MODE();
	}
	return 1;
}
int CObj__PM_METAL::__INITIALIZE__IO(p_io_para)
{
	int com_port = -1;

	int baud_rate = 9600;
	int data_bit  = 8;    // 8;
	int stop_bit  = 1;    // 1;
	int parity    = 0;    // 0 : None

	CString str_parity;

	// ...
	{
		CString para_cmmd;
		CString para_data;

		// 1.
		{
			para_cmmd = "COM_PORT";

			if(p_io_para->Get__PARAMETER_DATA(para_cmmd, para_data) > 0)
			{
				com_port = atoi(para_data);
			}
		}

		iPara__Addr_ID = 1;
	}

	// ...
	CString log_msg;
	CString log_bff;

	CString str_data;

	// ...
	{
		log_msg.Format("Connecting to Serial ... \n");

		log_bff.Format(" * Com Port: %d \n", com_port);
		log_msg += log_bff;

		log_bff.Format(" * Baud Rate: %1d \n", baud_rate);
		log_msg += log_bff;

		log_bff.Format(" * Data Bit: %1d \n", data_bit);
		log_msg += log_bff;

		// ...
		{
			switch(parity)
			{
				case 0:		str_data = "None";		break;;
				case 1:		str_data = "Odd";		break;;
				case 2:		str_data = "Even";		break;;
				case 3:		str_data = "Mark";		break;;
				case 4:		str_data = "Space";		break;;

				default:	str_data = "???";		break;;
			}

			str_parity = str_data;

			log_bff.Format(" * Parity Bit: %s (%1d) \n", str_data, parity);
			log_msg += log_bff;
		}

		log_bff.Format(" * Stop Bit: %1d \n", stop_bit);
		log_msg += log_bff;

		xI__APP_LOG_CTRL->WRITE__LOG(log_msg);
		xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
	}

	if(iActive__SIM_MODE > 0)
	{
		bActive__COMM_ONLINE = true;
	}
	else
	{
		if(mX_Serial->INIT__COMPORT(com_port, baud_rate, data_bit, stop_bit, parity) < 0)
		{
			bActive__COMM_ONLINE = false;
		}
		else
		{
			bActive__COMM_ONLINE = true;
		}
	}

	// ...
	CString ch_data;

	// ...
	{
		ch_data.Format("%1d", com_port);
		sCH__DRV_INFO_COM_PORT->Set__DATA(ch_data);

		ch_data = "Modbus RTU";
		sCH__DRV_INFO_PROTOCOL->Set__DATA(ch_data);

		ch_data.Format("%1d", iPara__Addr_ID);
		sCH__DRV_INFO_MODBUS_ADDR->Set__DATA(ch_data);

		ch_data.Format("%1d", baud_rate);
		sCH__DRV_INFO_BAUD_RATE->Set__DATA(ch_data);

		ch_data.Format("%s (%1d)", str_parity, parity);
		sCH__DRV_INFO_COMM_PARITY->Set__DATA(ch_data);

		ch_data.Format("%1d", data_bit);
		sCH__DRV_INFO_DATA_BIT->Set__DATA(ch_data);

		ch_data.Format("%1d", stop_bit);
		sCH__DRV_INFO_STOP_BIT->Set__DATA(ch_data);
	}
	return 1;
}


//--------------------------------------------------------------------------------
int CObj__PM_METAL::__CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm)
{
	CString msg;
	int flag = -1;

	// ...
	{
		msg.Format("%s Started ...", mode);
		sCH__OBJ_MSG->Set__DATA(msg);

		xI__APP_LOG_CTRL->WRITE__LOG(msg);
	}

	// ...
	{
		IF__CTRL_MODE(sMODE__INIT)					flag = Call__INIT(p_variable,p_alarm);
	}

	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		msg.Format("%s Aborted (%1d)", mode, flag);
		sCH__OBJ_MSG->Set__DATA(msg);

		xI__APP_LOG_CTRL->WRITE__LOG(msg);
	}
	else
	{
		msg.Format("%s Completed (%1d)", mode, flag);
		sCH__OBJ_MSG->Set__DATA(msg);

		xI__APP_LOG_CTRL->WRITE__LOG(msg);
	}	

	return flag;
}

int CObj__PM_METAL::__CALL__MONITORING(id, p_variable, p_alarm)
{
	if(id == MON_ID__MONITOR)		Mon__MONITOR(p_variable, p_alarm);

	return 1;
}

