#include "StdAfx.h"
#include "CObj__APS_8301.h"


// ...
void CObj__APS_8301
::Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;

	if(iActive__SIM_MODE > 0)
	{
		bActive__COMM_ONLINE = true;
	}
	else
	{
		bActive__COMM_ONLINE = false;
	}

	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.1);


		if(bActive__COMM_ONLINE)
		{
			sCH__MON_COMM_STS->Set__DATA(STR__ONLINE);
		}
		else
		{
			sCH__MON_COMM_STS->Set__DATA(STR__OFFLINE);
		}

		if(sCH__MON_COMM_STS->Check__DATA(STR__OFFLINE) > 0)
		{
			int alarm_id = ALID__ESC_OFFLINE_ALARM;
			CString alm_msg;
			CString	r_act;

			alm_msg  = "Please, check the communication state of ESC unit ! \n\n";
			alm_msg += sCH__INFO_DRV_PARAMETER->Get__STRING();

			p_alarm->Check__ALARM(alarm_id,r_act);
			p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alm_msg);
		}

		// Leak_Current Limit Check ...
		{
			double cfg__leak_limit = aCH__CFG_LEAK_CURRUNT_LIMIT_mA->Get__VALUE();
			double cfg__delay_sec  = aCH__CFG_STABLE_DELAY_SEC->Get__VALUE();     // KMS:221024

			ch_data = siCH__ESC_LEAK_CURRENT_mA->Get__STRING();
			double cur_value = atof(ch_data);

			// KMS:221024 Delay 추가 ...
			if(bActive__Delay_Check == true)     
			{
				if(mCtrl__Delay_Timer->Get__CURRENT_TIME() >= cfg__delay_sec) 
				{
					mCtrl__Delay_Timer->STOP_ZERO();

					bActive__Delay_Check = false;
				}
			}
			else
			{
				if(cur_value > cfg__leak_limit)
				{
					sCH__MON_SYSTEM_ABORT->Set__DATA(STR__YES);

					_Fnc__Abort_Ctrl();

					//
					int alarm_id = ALID__ESC_HIGH_CURRENT_LIMIT;
					CString alm_msg;
					CString alm_bff;
					CString	r_act;

					alm_bff.Format("The config leak-current is %.3f (mA). \n", cfg__leak_limit);
					alm_msg += alm_bff;
					
					alm_bff.Format("The current leak-current is %.3f (mA). \n", cur_value);
					alm_msg += alm_bff;

					p_alarm->Check__ALARM(alarm_id,r_act);
					p_alarm->Post__ALARM_With_MESSAGE(alarm_id,alm_msg);
				}
				else
				{
					sCH__MON_SYSTEM_ABORT->Set__DATA(STR__NO);
				}
			}
		}

		// ...
	}
}

