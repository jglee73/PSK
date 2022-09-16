#include "StdAfx.h"
#include "CObj__LLx_TwoManiFold.h"
#include "CObj__LLx_TwoManiFold__DEF.h"
#include "CObj__LLx_TwoManiFold__ALID.h"


// ...
int  CObj__LLx_TwoManiFold
::Check__OBJECT_BUSY(const CString& obj_sts)
{
	if(obj_sts.CompareNoCase(STR__AVAILABLE) == 0)		return -1;
	if(obj_sts.CompareNoCase(STR__ABORTED) == 0)		return -1;
	if(obj_sts.CompareNoCase(STR__IDLE) == 0)			return -1;

	return 1;
}

int  CObj__LLx_TwoManiFold
::Check__SYSTEM_VAC_PRESSURE(CII_OBJECT__VARIABLE* p_variable,
							 CII_OBJECT__ALARM* p_alarm,
							 const int lba_pump_flag,
							 const int lbb_pump_flag,
							 int& retry_flag)
{
	int alarm_flag = -1;
	CString alarm_info;

	// LBA -----
	if((dCH__CFG_LBA_LEAK_CHECK->Check__DATA(STR__ENABLE) > 0)
	&& (lba_pump_flag > 0))
	{
		if(Check__SYSTEM_VAC_PRESSURE_WITHOUT_ALARM(p_variable,
													p_alarm,
													"LBA",
													aEXT_CH__LBA__PRESSURE_TORR.Get__PTR(),
													alarm_info) < 0)
		{
			alarm_flag = 1;
		}
	}

	// LBB -----
	if((dCH__CFG_LBB_LEAK_CHECK->Check__DATA(STR__ENABLE) > 0)
	&& (lbb_pump_flag > 0))
	{
		if(Check__SYSTEM_VAC_PRESSURE_WITHOUT_ALARM(p_variable,
													p_alarm,
													"LBB",
													aEXT_CH__LBB__PRESSURE_TORR.Get__PTR(),
													alarm_info) < 0)
		{
			alarm_flag = 1;
		}
	}

	if(alarm_flag > 0)
	{
		double cfg__vac_press;
		CString var_data;

		aEXT_CH__CFG_REF_VAC_PRESSURE->Get__DATA(var_data);
		cfg__vac_press = atof(var_data);

		// ...
		{
			int alarm_id = -1;
			CString alarm_msg;
			CString r_act;

			     if(lba_pump_flag > 0)			alarm_id = ALID__LEFT_LLx__VAC_PRESSURE_ERROR;
			else if(lbb_pump_flag > 0)			alarm_id = ALID__RIGHT_LLx__VAC_PRESSURE_ERROR;

			alarm_msg.Format("Config VAC Pressure : %.3f\n",cfg__vac_press);
			alarm_msg += alarm_info;

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,alarm_msg,r_act);

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				retry_flag = 1;
				return 1;
			}
			return -1;
		}
	}

	return 1;
}

int  CObj__LLx_TwoManiFold::
Check__SYSTEM_VAC_PRESSURE_WITHOUT_ALARM(CII_OBJECT__VARIABLE* p_variable,
										 CII_OBJECT__ALARM* p_alarm,
										 const CString& module_name,
										 CII__VAR_ANALOG_CTRL* pch_module_pressure,
										 CString& alarm_msg)
{
	double cur__module_press;
	double cfg__atm_press;
	double cfg__vac_press;
	CString var_data;

	pch_module_pressure->Get__DATA(var_data);
	cur__module_press = atof(var_data);

	aEXT_CH__CFG_REF_ATM_PRESSURE->Get__DATA(var_data);
	cfg__atm_press = atof(var_data);

	aEXT_CH__CFG_REF_VAC_PRESSURE->Get__DATA(var_data);
	cfg__vac_press = atof(var_data);

	// VAC Check
	if(cur__module_press <= cfg__vac_press)
	{

	}
	// ATM Check
	else if(cur__module_press >= cfg__atm_press)
	{

	}
	else
	{
		/*
		CString alarm_bff;
		CString r_act;

		alarm_bff.Format("Current %s Pressure : %.3f\n", module_name, cur__module_press);
		alarm_msg += alarm_bff;
		*/

		return -1;
	}

	return 1;
}

int  CObj__LLx_TwoManiFold::
Check__ALL_VLV_CLOSE(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& act_name)
{
	DECLARE__EXT_CTRL(p_variable);

LOOP_RETRY:

	// ...
	CStringArray l_err_msg;
	CString err_msg;
	int i;

	// LBA
	if(dEXT_CH__LBA__SLIT_VALVE_STATUS->Check__DATA(STR__CLOSE) < 0)
	{
		err_msg = "LBA";
		l_err_msg.Add(err_msg);
	}

	// LBB
	if(dEXT_CH__LBB__SLIT_VALVE_STATUS->Check__DATA(STR__CLOSE) < 0)
	{
		err_msg = "LBB";
		l_err_msg.Add(err_msg);
	}

	if(l_err_msg.GetSize() > 0)
	{
		int alarm_id = ALID__SLIT_VALVE__NOT_CLOSE;
		CString alarm_msg;
		CString alarm_bff;
		CString r_act;

		alarm_msg.Format("Can not %s !\n",act_name);
		alarm_msg += "Please, close all slot-valve.\n";
		alarm_msg += "Check the following modules;\n";

		int limit = l_err_msg.GetSize();
		int i;

		for(i=0;i<limit;i++)
		{
			alarm_msg += l_err_msg[i];
			alarm_msg += "\n";
		}

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,alarm_msg,r_act);

		if(r_act.CompareNoCase(ACT__CHECK_RETRY) == 0)
		{
			goto LOOP_RETRY;
		}
		return -1;
	}

	return 1;
}
