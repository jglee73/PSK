#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"

#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
void CObj__AtmRobot_FUSION
::Mon__ANI_MONITOR(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm)
{

	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.2);

		if((dCH__SIM_CFG__REAL_TEST->Check__DATA(STR__YES) < 0)
		&& (iActive__SIM_MODE > 0))
		{
			iCFG__SIM_MODE = 1;
		}
		else
		{
			iCFG__SIM_MODE = -1;
		}
	}
}

void CObj__AtmRobot_FUSION
::Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm)
{
	CString var_data;
	int iCount = 0;

	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.5);

		if(iCFG__SIM_MODE > 0)
		{
			if(diCH__COMM_STS->Check__DATA(STR__ONLINE) < 0)
			{
				diCH__COMM_STS->Set__DATA(STR__ONLINE);
				sCH__OTR_OUT_MON__COMM_STS->Set__DATA(STR__ONLINE);
			}
		}
		else
		{
			if(diCH__COMM_STS->Check__DATA(STR__OFFLINE) > 0)
			{
				if(iCount < 6)
				{
					iCount++;
					continue;
				}
				sCH__OTR_OUT_MON__COMM_STS->Set__DATA(STR__OFFLINE);

				// ...
				{
					CString r_act;
					int alarm_id = ALID__OFFLINE_ALARM;

					p_alarm->Check__ALARM(alarm_id,r_act);
					p_alarm->Post__ALARM(alarm_id);

					iCount = 0;
				}
			}
			else
			{
				iCount = 0;
				sCH__OTR_OUT_MON__COMM_STS->Set__DATA(STR__ONLINE);
			}
		}

		// ...
		{
			if(sCH__Robot_GetInfo_Update_Req->Check__DATA(STR__YES) > 0)
			{
				soCH__GET_INFO_CMD->Set__DATA("");

				sCH__Robot_GetInfo_Update_Req->Set__DATA("");
			}
			else if(sCH__AL_GetInfo_Update_Req->Check__DATA(STR__YES) > 0)
			{
				doCH__COMMAND->Set__DATA("ALResult");

				sCH__AL_GetInfo_Update_Req->Set__DATA("");
			}

			diCH__ROBOT_CURR_POS->Get__DATA(var_data);
			diCH__ROBOT_Z_POS->Get__DATA(var_data);
			diCH__ROBOT_AR_POS->Get__DATA(var_data);
			diCH__ROBOT_T_POS->Get__DATA(var_data);
		}
	}	
}

void CObj__AtmRobot_FUSION
::Mon__HYPER_TERMINAL_SEND(CII_OBJECT__VARIABLE* p_variable,
						   CII_OBJECT__ALARM* p_alarm)
{
	SCX__SEQ_INFO x_seq_info;
	
	CString str_msg;
	CString str_time;
	CString log_msg;
	CString var_data;
	int count = 0;


	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.5);


		if(dCH__HYPER_TERMINAL_SEND_REQ->Check__DATA("YES") > 0)
		{
			xCH__LOCK_FLAG->Set__DATA("YES");		// LockÀ» °Ç´Ù.

			// Do Action ...
			sCH__HYPER_TERMINAL_SEND_MSG->Get__DATA(var_data);
			log_msg.Format("COMMAND:%s \n\n", var_data);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(log_msg);

			//
			xCH__UPDATE_FLAG->Get__DATA(str_msg);
			var_data.Format("%1d", atoi(str_msg)+1);
			xCH__UPDATE_FLAG->Set__DATA(var_data);
			_sleep(500);

			str_time = x_seq_info->Get__DATE_TIME_STRING();
			log_msg.Format("[%s] : <----- SEND -----> \n", str_time);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(log_msg);

			//
			xCH__UPDATE_FLAG->Get__DATA(str_msg);
			var_data.Format("%1d", atoi(str_msg)+1);
			xCH__UPDATE_FLAG->Set__DATA(var_data);
			_sleep(500);

			// command
			sCH__HYPER_TERMINAL_SEND_MSG->Get__DATA(var_data);
			soCH__HYPER_TERMINAL_CMD->Set__DATA(var_data);

			dCH__HYPER_TERMINAL_SEND_REQ->Set__DATA("NO");
		}
	}	
}
