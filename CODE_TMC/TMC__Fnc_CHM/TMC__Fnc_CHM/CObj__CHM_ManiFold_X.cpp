#include "StdAfx.h"
#include "CObj__CHM_ManiFold_X.h"
#include "CObj__CHM_ManiFold_X__DEF.h"
#include "CObj__CHM_ManiFold_X__ALID.h"


//-------------------------------------------------------------------------
CObj__CHM_ManiFold_X::CObj__CHM_ManiFold_X()
{

}
CObj__CHM_ManiFold_X::~CObj__CHM_ManiFold_X()
{

}

//-------------------------------------------------------------------------
int CObj__CHM_ManiFold_X::__DEFINE__CONTROL_MODE(obj,l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT,    "INIT");
		ADD__CTRL_VAR(sMODE__ISOLATE, "ISOLATE");

		ADD__CTRL_VAR(sMODE__PUMP,    "PUMP");
		ADD__CTRL_VAR(sMODE__VENT,    "VENT");

		ADD__CTRL_VAR(sMODE__LEAK_CHECK,  "LEAK_CHECK");
		ADD__CTRL_VAR(sMODE__CYCLE_PURGE, "CYCLE_PURGE");
	}
	return 1;
}
int CObj__CHM_ManiFold_X::__DEFINE__VERSION_HISTORY(version)
{

	return 1;
}


// ...
#define MON_ID__IO_MONITOR				1

// ...
#define APP_DSP__CLOSE_OPEN				"UNKNOWN  CLOSE  OPEN"
#define APP_DSP__DISABLE_ENABLE			"DISABLE  ENABLE"


int CObj__CHM_ManiFold_X::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE;

	CCommon_Error__DEF_VARIABLE m_err_def_variable;
	p_variable->Link__DEF_VARIABLE__ERROR_FEEDBACK(&m_err_def_variable);

	// ...
	CString str_name;
	int i;

	// ...
	{
		str_name = "OTR.OUT.MON.OBJ.STATUS";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__OBJ_STATUS,str_name);

		str_name = "OTR.OUT.MON.OBJ.MSG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(xCH__OBJ_MSG,str_name);

		str_name = "OTR.OUT.MON.aPRESSURE.TORR";
		STD__ADD_ANALOG_WITH_COMMENT(str_name,"torr",3,0,1000,"");
		LINK__VAR_ANALOG_CTRL(aCH__TMC_CHM_PRESSURE_TORR,str_name);

		str_name = "OTR.IN.MON.sROBOT.MATERIAL.TRANSFER.FLAG";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__ROBOT_MATERIAL_TRANSFER_FLAG, str_name);
	}

	// ...
	{
		str_name = "CFG.LEAK.CHECK";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, APP_DSP__DISABLE_ENABLE,"");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_TMC_LEAK_CHECK, str_name);
	}

	// TMC : LEAK_CHECK PARA -----
	{
		str_name = "MON.LEAK_CHECK.TIME_COUNT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",0,0.0,9999,"");
		LINK__VAR_ANALOG_CTRL(aCH__TMC_LEAK_CHECK__TIME_COUNT, str_name);

		str_name = "CFG.LEAK_CHECK.OVER.PUMPING.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",0,0.0,9999,"");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMC_LEAK_CHECK__OVER_PUMPING_TIME, str_name);

		str_name = "CFG.LEAK_CHECK.STABLE.TIME";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",0,0.0,9999,"");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMC_LEAK_CHECK__STABLE_TIME, str_name);

		str_name = "CFG.LEAK_CHECK.CHECK_TIME.MIN";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",0,1,30,"");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMC_LEAK_CHECK__CHECK_TIME_MIN, str_name);

		//
		str_name = "MON.LEAK_CHECK.START.TIME";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__START_TIME, str_name);

		str_name = "MON.LEAK_CHECK.END.TIME";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__END_TIME, str_name);

		str_name = "MON.LEAK_CHECK.START.PRESSURE.TORR";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__START_PRESSURE_TORR, str_name);

		str_name = "MON.LEAK_CHECK.END.PRESSURE.TORR";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__END_PRESSURE_TORR, str_name);

		str_name = "MON.LEAK_CHECK.TOTAL.LEAK.RATE";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__TOTAL_LEAK_RATE, str_name);
	}

	// LeakBack AlarmRate ...
	{
		str_name = "CFG.LEAK_CHECK.ALARM.RATE";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mtorr_min", 0, 0, 1000, "rec:10");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_TMC_LEAK_CHECK__ALARM_RATE, str_name);

		for(i=0;i<CFG_LEAK_RATE__STEP_SIZE;i++)
		{
			str_name.Format("MON.LEAK_CHECK.STEP%1d.PRESSURE.TORR",i+1);
			STD__ADD_STRING_WITH_X_OPTION(str_name, "");
			LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__STEP_PRESSURE_TORR[i], str_name);

			str_name.Format("MON.LEAK_CHECK.STEP%1d.LEAK.RATE",i+1);
			STD__ADD_STRING_WITH_X_OPTION(str_name, "");
			LINK__VAR_STRING_CTRL(sCH__TMC_LEAK_CHECK__STEP_LEAK_RATE[i], str_name);
		}
	}

	// ...
	{
		str_name = "OTR.OUT.MON.dPRESSURE.STATUS";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__PRESSURE_STATUS, str_name);

		str_name = "dOTR.OUT.PUMPING.STS.FLAG";
		STD__ADD_DIGITAL_WITH_COMMENT(str_name,  "END PUMPING", "");
		LINK__VAR_DIGITAL_CTRL(dCH__PUMPING_STS_FLAG,str_name);
	}

	// Cycle Purge ...
	{
		str_name = "APP.PURGE.CYCLE.COUNT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "count", 0, 1, 100000, "");	
		LINK__VAR_ANALOG_CTRL(aCFG_CH__CYCLE_PURGE_COUNT,str_name);

		str_name = "APP.PURGE.CURRENT.COUNT";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCFG_CH__CYCLE_PURGE_CURRENT_COUNT,str_name);

		str_name = "APP.PURGE.MESSAGE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCFG_CH__CYCLE_PURGE_SEQ_MSG,str_name);
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(1.0, MON_ID__IO_MONITOR);
	}
	return 1;
}


// ...
#define  ACT__RETRY_ABORT						\
	l_act.RemoveAll();								\
	l_act.Add("RETRY");								\
	l_act.Add("ABORT");

#define  ACT__CHK_RETRY_ABORT					\
	l_act.RemoveAll();								\
	l_act.Add("CHECK_RETRY");						\
	l_act.Add("ABORT");

#define  ACT__CHECK								\
	l_act.RemoveAll();								\
	l_act.Add("CHECK");								


int CObj__CHM_ManiFold_X::__DEFINE__ALARM(p_alarm)
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
		alarm_id = ALID__SLIT_VALVE__NOT_CLOSE;

		alarm_title  = title;
		alarm_title += "Slot-Valve is not Close !";

		alarm_msg = "";

		ACT__CHK_RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__TMC_LEAK_CHECK_BAD_RESULT_ALARM;

		alarm_title  = title;
		alarm_title += "TMC Leak Check is higher than config value !";

		alarm_msg = "";

		ACT__CHECK;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	return 1;
}

//-------------------------------------------------------------------------
int CObj__CHM_ManiFold_X::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{
	CString def_name;
	CString def_data;
	CString obj_name;
	CString str_name;
	int i;

	// ...
	{
		CString file_name;
		CString log_msg;

		file_name.Format("%s_App.log", sObject_Name);

		log_msg  = "\n\n";
		log_msg += "//------------------------------------------------------------------------";

		xLOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
		xLOG_CTRL->SET__PROPERTY(file_name,24*5,60);

		xLOG_CTRL->DISABLE__TIME_LOG();
		xLOG_CTRL->WRITE__LOG(log_msg);

		xLOG_CTRL->ENABLE__TIME_LOG();
		xLOG_CTRL->WRITE__LOG("   START   \n");
	}


	// PM SIZE ...
	{
		def_name = "PM_SIZE";
		p_variable->Get__DEF_CONST_DATA(def_name, def_data);

		m_nPM_LIMIT = atoi(def_data);
		if(m_nPM_LIMIT > CFG_PMx__SIZE)			m_nPM_LIMIT = CFG_PMx__SIZE;
	}

	// DB OBJECT ...
	{
		def_name = "OBJ__DB";
		p_variable->Get__DEF_CONST_DATA(def_name, obj_name);

		//
		str_name = "CFG.TRANSFER.MODE";
		LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__CFG_TRANSFER_MODE, obj_name,str_name);

		str_name = "CFG.REF.ATM.PRESSURE";
		LINK__EXT_VAR_ANALOG_CTRL(aEXT_CH__CFG_REF_ATM_PRESSURE, obj_name,str_name);

		str_name = "CFG.REF.VAC.PRESSURE";
		LINK__EXT_VAR_ANALOG_CTRL(aEXT_CH__CFG_REF_VAC_PRESSURE, obj_name,str_name);

		//
		for(i=0; i<m_nPM_LIMIT; i++)
		{
			str_name.Format("CFG.PM%1d.EXIST.FLAG", i+1);
			LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__CFG_PMx_EXIST_FLAG[i], obj_name,str_name);

			str_name.Format("CFG.PM%1d.SV.USE", i+1);
			LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__CFG_PMx_SV_USE[i], obj_name,str_name);
		}
	}

	// TMC CHM
	{
		def_name = "OBJ__TMC_CHM";
		p_variable->Get__DEF_CONST_DATA(def_name, obj_name);

		pTMC_CHM__OBJ_CTRL = p_ext_obj_create->Create__OBJECT_CTRL(obj_name);

		//
		str_name = "OTR.OUT.MON.OBJ.STATUS";
		LINK__EXT_VAR_STRING_CTRL(sEXT_CH__TMC_CHM__OBJ_STATUS, obj_name,str_name);

		str_name = "OTR.OUT.MON.PUMP.VLV.OPEN.FLAG";
		LINK__EXT_VAR_STRING_CTRL(sEXT_CH__TMC_CHM__PUMP_VLV_OPEN_FLAG, obj_name,str_name);

		str_name = "OTR.OUT.MON.PRESSURE.CTRL.FLAG";
		LINK__EXT_VAR_STRING_CTRL(sEXT_CH__TMC_CHM__PRESSURE_CTRL_FLAG, obj_name,str_name);

		str_name = "OTR.OUT.MON.aPRESSURE.TORR";
		LINK__EXT_VAR_ANALOG_CTRL(aEXT_CH__TMC_CHM__PRESSURE_TORR, obj_name,str_name);

		str_name = "OTR.OUT.MON.dPRESSURE.STATUS";
		LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__TMC_CHM__PRESSURE_STATUS, obj_name,str_name);
	}

	// LLx OBJ ...
	{
		def_name = "DATA.LLx_SIZE";
		p_variable->Get__DEF_CONST_DATA(def_name, def_data);

		iDATA__LLx_SIZE  = atoi(def_data);
		if(iDATA__LLx_SIZE > CFG_LLx__SIZE)			iDATA__LLx_SIZE = CFG_LLx__SIZE;

		for(i=0; i<iDATA__LLx_SIZE; i++)
		{
			// OBJ_FNC ...
			{
				def_name.Format("LINK_LLx.OBJ_FNC.%1d", i+1);
				p_variable->Get__DEF_CONST_DATA(def_name, obj_name);

				pLLx__OBJ_FNC_X[i] = p_ext_obj_create->Create__OBJECT_CTRL(obj_name);

				//
				str_name = "dOTR.OUT.PUMPING.STS.FLAG";
				LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__LLx__PUMPING_STS_FLAG_X[i], obj_name,str_name);
			}

			// OBJ_PHY ...
			{
				def_name.Format("LINK_LLx.OBJ_PHY.%1d", i+1);
				p_variable->Get__DEF_CONST_DATA(def_name, obj_name);

				pLLx__OBJ_PHY_X[i] = p_ext_obj_create->Create__OBJECT_CTRL(obj_name);

				//
				str_name = "OTR.OUT.MON.dSLIT.VALVE.STATUS";
				LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__LLx__SLIT_VALVE_STATUS_X[i], obj_name,str_name);

				//
				str_name = "OTR.OUT.MON.PRESSURE.CTRL.FLAG";
				LINK__EXT_VAR_STRING_CTRL(sEXT_CH__LLx__PRESSURE_CTRL_FLAG_X[i], obj_name,str_name);

				str_name = "OTR.OUT.MON.dPRESSURE.STATUS";
				LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__LLx__PRESSURE_STATUS_X[i], obj_name,str_name);
			}
		}
	}

	// PMx OBJ ...
	{
		def_name = "OBJ__PMx";
		p_variable->Get__DEF_CONST_DATA(def_name, obj_name);

		pPMx__OBJ_CTRL = p_ext_obj_create->Create__OBJECT_CTRL(obj_name);
		
		//
		for(i=0; i<m_nPM_LIMIT; i++)
		{
			str_name.Format("OTR.OUT.MON.dPM%1d.SLIT.VALVE.STATUS",i+1);
			LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__PMx__SLIT_VALVE_STATUS[i], obj_name,str_name);
		}
	}

	return 1;
}

//-------------------------------------------------------------------------
int CObj__CHM_ManiFold_X::__CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm)
{
	// ...
	{
		CString log_msg;
		log_msg.Format("Start ... :  [%s]",mode);

		xCH__OBJ_MSG->Set__DATA(log_msg);
		xLOG_CTRL->WRITE__LOG(log_msg);
	}

	int flag = -1;

	// ...
	{
			 IF__CTRL_MODE(sMODE__INIT)				flag = Call__INIT(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ISOLATE)			flag = Call__ISOLATE(p_variable,p_alarm);

		ELSE_IF__CTRL_MODE(sMODE__PUMP)				flag = Call__PUMP(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__VENT)				flag = Call__VENT(p_variable,p_alarm);

		ELSE_IF__CTRL_MODE(sMODE__LEAK_CHECK)		flag = Call__LEAK_CHECK(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__CYCLE_PURGE)		flag = Call__CYCLE_PURGE(p_alarm,p_variable);
	}

	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		CString log_msg;
		log_msg.Format("Aborted ... :  [%s] [Flag : %1d]",mode,flag);

		xCH__OBJ_MSG->Set__DATA(log_msg);
		xLOG_CTRL->WRITE__LOG(log_msg);
	}
	else
	{
		CString log_msg;
		log_msg.Format("Completed ... :  [%s]",mode);

		xCH__OBJ_MSG->Set__DATA(log_msg);
		xLOG_CTRL->WRITE__LOG(log_msg);
	}

	dCH__PUMPING_STS_FLAG->Set__DATA("END");
	return flag;
}
int CObj__CHM_ManiFold_X::__CALL__MONITORING(id,p_variable,p_alarm)
{
	switch(id)
	{
	case MON_ID__IO_MONITOR:
		Mon__IO_MONITOR(p_variable,p_alarm);
		break;
	}
	return 1;
}
