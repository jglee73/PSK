#include "stdafx.h"

#include "CObj__LPx_CTRL__ALID.h"
#include "CObj__LPx_CTRL__DEF.h"
#include "CObj__LPx_CTRL.h"

#include "CDriver__LPx_ETHERNET__DEF.h"


//--------------------------------------------------------------------------------
void CObj__LPx_CTRL
::Fnc__APP_LOG(const CString& log_msg)
{
	xAPP__LOG_CTRL->WRITE__LOG(log_msg);
}

int  CObj__LPx_CTRL
::Is__ONLINE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(sEXT_CH__MON_COMMUNICATION_STATE->Check__DATA(STR__ONLINE) < 0)
	{
		int alarm_id = ALID__OFFLINE;

		p_alarm->Post__ALARM(alarm_id);
		return -1;
	}
	return 1;
}

int CObj__LPx_CTRL
::Wait__LP_STATE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	// KMS:221110 WAIT IDEL -> RUN
	{
		int Count_Check = 0;

		while(sEXT_CH__LP_INFO__STATUS->Check__DATA(STR__RUN) < 0)
		{
			Sleep(500);
			
			Count_Check++;

			// ...
			{
				CString log_msg;
				CString log_bff;
				
				log_msg = "_Wait__LP_INFO__STATE() - Report ... \n";
				log_bff.Format(" * Delayed Run Mode Chanbe <- [%1d] \n", Count_Check);
				log_msg += log_bff;
				log_bff.Format(" * %s <- %s \n",
								sEXT_CH__LP_INFO__STATUS->Get__CHANNEL_NAME(),
								sEXT_CH__LP_INFO__STATUS->Get__STRING());
				log_msg += log_bff;
				Fnc__APP_LOG(log_msg);
			}

			if(Count_Check > 10)
			{
				return -1011;
			}

			if(iActive__SIM_MODE > 0)
			{
				if(Count_Check > 5)			sEXT_CH__LP_INFO__STATUS->Set__DATA(STR__RUN);
			}
		}

		// ...
		{
			CString log_msg;

			log_msg.Format(" * %s <- %s (RUN <- STOP CHECK)\n",
							sEXT_CH__LP_INFO__STATUS->Get__CHANNEL_NAME(),
							sEXT_CH__LP_INFO__STATUS->Get__STRING());
		
			Fnc__APP_LOG(log_msg);
		}			
	}

	int r_flag = _Wait__LP_STATE(p_variable, p_alarm);

	// ...
	{
		CString log_msg;
		CString log_bff;

		log_msg = "_Wait__LP_STATE() - Report ... \n";

		log_bff.Format(" * r_flag <- [%1d] \n", r_flag);
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n",
						siEXT_CH__LP_STATE->Get__CHANNEL_NAME(),
						siEXT_CH__LP_STATE->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n",
						sEXT_CH__LP_INFO__STATUS->Get__CHANNEL_NAME(),
						sEXT_CH__LP_INFO__STATUS->Get__STRING());
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}

	return r_flag;
}
int CObj__LPx_CTRL
::_Wait__LP_STATE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int sim_count = 0;

	if(iActive__SIM_MODE > 0)
	{
		siEXT_CH__LP_STATE->Set__DATA(STR__OK);
		sEXT_CH__LP_INFO__STATUS->Set__DATA(STR__RUN);
	}

	while(1)
	{
		if(p_variable->Check__CTRL_ABORT() > 0)						return -1;

		if(siEXT_CH__LP_STATE->Check__DATA(STR__OK) < 0)			return -11;
		if(sEXT_CH__LP_INFO__STATUS->Check__DATA(STR__ERROR) > 0)	return -21;
		if(sEXT_CH__LP_INFO__STATUS->Check__DATA(STR__STOP) > 0)
		{
			CString log_msg;
			log_msg.Format(" * %s <- %s (STOP <- RUN CHECK)\n",
			sEXT_CH__LP_INFO__STATUS->Get__CHANNEL_NAME(),
			sEXT_CH__LP_INFO__STATUS->Get__STRING());
			Fnc__APP_LOG(log_msg);
			return 1;
		}
		Sleep(100);

		if(iActive__SIM_MODE > 0)
		{
			sim_count++;
			if(sim_count >= 10)
			{
				sEXT_CH__LP_INFO__STATUS->Set__DATA(STR__STOP);
			}
		}
	}

	return -11;
}


//--------------------------------------------------------------------------------
int CObj__LPx_CTRL
::Fnc__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__INIT);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sEXT_CH__LP_INFO__INITIAL->Set__DATA(STR__ON);
	}

	if(sEXT_CH__LP_INFO__INITIAL->Check__DATA(STR__ON) < 0)
	{
		return -12;
	}
	return 1;
}

int CObj__LPx_CTRL
::Fnc__DOOR_OPEN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__OPEN);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sEXT_CH__LP_INFO__DOOR_STATUS->Set__DATA(STR__OPEN);
	}

	if(sEXT_CH__LP_INFO__DOOR_STATUS->Check__DATA(STR__OPEN) < 0)
	{
		return -12;
	}
	return 1;
}
int CObj__LPx_CTRL
::Fnc__DOOR_CLOSE(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__CLOSE);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sEXT_CH__LP_INFO__DOOR_STATUS->Set__DATA(STR__CLOSE);
	}

	if(sEXT_CH__LP_INFO__DOOR_STATUS->Check__DATA(STR__CLOSE) < 0)
	{
		return -12;
	}
	return 1;
}

int CObj__LPx_CTRL
::Fnc__LOAD(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__LOAD);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sCH__MON_FOUP_POS_STATUS->Set__DATA(STR__LOAD);

		sEXT_CH__LP_INFO__CLAMP_STATUS->Set__DATA(STR__CLAMP);
		sEXT_CH__LP_INFO__DOOR_STATUS->Set__DATA(STR__OPEN);
	}

	if(sEXT_CH__LP_INFO__DOOR_STATUS->Check__DATA(STR__OPEN) < 0)
	{
		return -12;
	}

	_Update__LPx_STATE();
	_Update__LPx_MAP();
	return 1;
}
int CObj__LPx_CTRL
::Fnc__UNLOAD(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	_Update__LPx_STATE();

	// ...
	{
		bool active__unload_check = true;

		if(sCH__MON_DOOR_STATUS->Check__DATA(STR__CLOSE) < 0)			active__unload_check = false;
		if(sCH__MON_CLAMP_STATUS->Check__DATA(STR__UNCLAMP) < 0)		active__unload_check = false;

		if(active__unload_check)
		{
			CString log_msg;
			CString log_bff;

			log_msg.Format("Already Unload  ... \n");

			log_bff.Format(" * %s <- %s \n",
							sCH__MON_DOOR_STATUS->Get__CHANNEL_NAME(),
							sCH__MON_DOOR_STATUS->Get__STRING());
			log_msg += log_bff;

			log_bff.Format(" * %s <- %s \n",
							sCH__MON_CLAMP_STATUS->Get__CHANNEL_NAME(),
							sCH__MON_CLAMP_STATUS->Get__STRING());
			log_msg += log_bff;

			Fnc__APP_LOG(log_msg);
			return 1;
		}
	}

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__UNLOAD);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sCH__MON_FOUP_POS_STATUS->Set__DATA(STR__UNLOAD);

		sEXT_CH__LP_INFO__DOOR_STATUS->Set__DATA(STR__CLOSE);
	}

	// ...
	int check_count = 0;

	while(1)
	{
		Sleep(200);		//KMS:221107, Unload Time Out Increase 15Sec

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -101;
		}

		if(sEXT_CH__LP_INFO__DOOR_STATUS->Check__DATA(STR__CLOSE) > 0)
		{
			break;
		}

		check_count++;
		if(check_count >= 75)	//KMS:221107, Unload Time Out Increase 15Sec
		{
			return -12;
		}
	}

	_Update__LPx_STATE();
	return 1;
}

int CObj__LPx_CTRL
::Fnc__SHUTTLE_IN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{

	return -1;
}
int CObj__LPx_CTRL
::Fnc__SHUTTLE_OUT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{

	return -1;
}

int CObj__LPx_CTRL
::Fnc__CLAMP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	_Update__LPx_STATE();

	// ...
	{
		bool active__clamp_check = false;

		if(sCH__MON_CLAMP_STATUS->Check__DATA(STR__CLAMP) > 0)		active__clamp_check = true;

		if(active__clamp_check)
		{
			CString log_msg;
			CString log_bff;

			log_msg.Format("Already Clamp ... \n");

			log_bff.Format(" * %s <- %s \n",
							sCH__MON_CLAMP_STATUS->Get__CHANNEL_NAME(),
							sCH__MON_CLAMP_STATUS->Get__STRING());
			log_msg += log_bff;

			Fnc__APP_LOG(log_msg);
			return 1;
		}
	}

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__CLAMP);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sEXT_CH__LP_INFO__CLAMP_STATUS->Set__DATA(STR__CLAMP);
	}

	if(sEXT_CH__LP_INFO__CLAMP_STATUS->Check__DATA(STR__CLAMP) < 0)
	{
		return -12;
	}
	return 1;
}
int CObj__LPx_CTRL
::Fnc__UNCLAMP(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	int state = Is__ONLINE(p_variable, p_alarm);
	if(state < 0)		return - 1;

	_Update__LPx_STATE();

	// ...
	{
		bool active__unclamp_check = false;

		if(sCH__MON_CLAMP_STATUS->Check__DATA(STR__UNCLAMP) > 0)		active__unclamp_check = true;

		if(active__unclamp_check)
		{
			CString log_msg;
			CString log_bff;

			log_msg.Format("Already Unclamp ... \n");

			log_bff.Format(" * %s <- %s \n",
							sCH__MON_CLAMP_STATUS->Get__CHANNEL_NAME(),
							sCH__MON_CLAMP_STATUS->Get__STRING());
			log_msg += log_bff;

			Fnc__APP_LOG(log_msg);
			return 1;
		}
	}

	// ...
	doEXT_CH__LP_CMMD->Set__DATA(_CMD__UNCLAMP);

	int r_flag = Wait__LP_STATE(p_variable, p_alarm);
	if(r_flag < 0)		return r_flag;

	if(iActive__SIM_MODE > 0)
	{
		sEXT_CH__LP_INFO__CLAMP_STATUS->Set__DATA(STR__UNCLAMP);
	}

	if(sEXT_CH__LP_INFO__CLAMP_STATUS->Check__DATA(STR__UNCLAMP) < 0)
	{
		return -12;
	}
	return 1;
}
