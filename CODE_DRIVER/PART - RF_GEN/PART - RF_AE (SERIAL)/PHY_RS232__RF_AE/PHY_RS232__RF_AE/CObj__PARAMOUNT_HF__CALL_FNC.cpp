#include "StdAfx.h"
#include "CObj__PARAMOUNT_HF.h"


// ...
int CObj__PARAMOUNT_HF
::Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int flag = 1;

	if(Call__POWER_SET(p_variable, p_alarm, false) < 0) 
	{
		flag = -1;
	}

	aCH__PARA_SET_POWER->Set__DATA("0.0");
	doCH__REGULATION_MODE->Set__DATA(STR__FORWARD);

	if(Call__CTRL_MODE(p_variable, p_alarm, true) < 0) 
	{
		flag = -1;
	}
	if(Call__POWER_SET(p_variable, p_alarm, false) < 0)
	{
		flag = -1;
	}

	return flag;
}

int  CObj__PARAMOUNT_HF
::Call__CTRL_MODE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const bool active_remote)
{
	int flag = -1;

	if(active_remote)		flag = doCH__CTRL_MODE->Set__DATA(STR__HOST);
	else					flag = doCH__CTRL_MODE->Set__DATA(STR__ANALOG);

	return flag;
}

int  CObj__PARAMOUNT_HF
::Call__POWER_SET(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const bool active_set)
{
	CString ch_data;
	int	flag;

	if(active_set)
	{
		aCH__PARA_SET_POWER->Get__DATA(ch_data);
		aoCH__POWER_SET->Set__DATA(ch_data);
	}
	else
	{
		flag = doCH__POWER_MODE->Set__DATA(STR__OFF);

		aoCH__POWER_SET->Set__DATA("0.0");
	}
	return flag;
}
int  CObj__PARAMOUNT_HF
::Call__POWER_ON(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{

	return doCH__POWER_MODE->Set__DATA(STR__ON);
}

int CObj__PARAMOUNT_HF
::Call__PROC_SET(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	CString log_msg;
	int	flag = -1;

	CString trg_value;
	aCH__PARA_SET_POWER->Get__DATA(trg_value);

	if(sCH__INFO_CTRL_MODE_READ->Check__DATA(STR__HOST) < 0)
	{
		flag = Call__CTRL_MODE(p_variable, p_alarm, true);		
		if(flag < 0)
		{
			int alm_id = ALID__GEN_CONTROL_MODE_ERROR;
			CString r_act;

			p_alarm->Check__ALARM(alm_id, r_act);
			p_alarm->Post__ALARM(alm_id);
			return -11;
		}
	}	

	flag = Call__POWER_SET(p_variable, p_alarm, true);
	if (flag < 0)
	{
		int alm_id = ALID__GEN_POWER_SET_ERROR;
		CString r_act;

		p_alarm->Check__ALARM(alm_id, r_act);
		p_alarm->Post__ALARM(alm_id);
		return -21;
	}

	return 1;
}
