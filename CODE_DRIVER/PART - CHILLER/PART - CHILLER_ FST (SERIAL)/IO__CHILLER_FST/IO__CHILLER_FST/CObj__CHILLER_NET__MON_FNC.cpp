#include "StdAfx.h"
#include "CObj__CHILLER_NET.h"

#include "CObj__CHILLER_NET__DEF.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
void CObj__CHILLER_NET
::Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm)
{
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
		p_variable->Wait__SINGLE_OBJECT(0.5);


		// IO.Update ...
		{
			for(int i=0; i<_CFG__CH_SIZE; i++)
			{
				doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
			}
		}

		if(bActive__COMM_ONLINE)
		{
			sCH__MON_COMM_STS->Set__DATA(STR__ONLINE);
		}
		else
		{
			sCH__MON_COMM_STS->Set__DATA(STR__OFFLINE);

			// ...
			{
				int alarm_id = ALID__OFFLINE_ALARM;
				CString alm_msg;
				CString r_act;

				alm_msg = sCH__INFO_DRV_PARAMETER->Get__STRING();

				p_alarm->Check__ALARM(alarm_id,r_act);
				p_alarm->Post__ALARM_With_MESSAGE(alarm_id,alm_msg);
			}
		}


		// Fault ...
		{
			bool active__fault_check = false;

			for(int i=0; i<_CFG__CH_SIZE; i++)
			{
				CString err_msg;
				CString err_bff;

				// Status.2
				{
					if(sCH__MON_COMP_THERMOSTAT_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Comp. Thermostat \n";
						err_msg += err_bff;
					}
					if(sCH__MON_OVER_TEMPERATURE_HW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Over. Temperature (HW) \n";
						err_msg += err_bff;
					}
					if(sCH__MON_OVER_TEMPERATURE_SW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Over. Temperature (SW) \n";
						err_msg += err_bff;
					}
					if(sCH__MON_TEMPERATURE_FAIL_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Temperature Fail \n";
						err_msg += err_bff;
					}
				}
				// Status.3
				{
					if(sCH__MON_COMP_OVER_CURRENT_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Comp. Over-Current \n";
						err_msg += err_bff;
					}
					if(sCH__MON_COMP_PRESSURE_FAIL_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Comp. Pressure Fail \n";
						err_msg += err_bff;
					}
					if(sCH__MON_PUMP_OVER_CURRENT_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Pump. Over-Current \n";
						err_msg += err_bff;
					}
					if(sCH__MON_PUMP_PRESSURE_FAIL_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Pump. Pressure Fail \n";
						err_msg += err_bff;
					}
				}
				// Status.4
				{
					if(sCH__MON_TEMP_RANGE_OVER_LIMIT_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Temp. Range Over-Limit \n";
						err_msg += err_bff;
					}
					if(sCH__MON_LEVEL_EMPTY_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Level Empty \n";
						err_msg += err_bff;
					}
					if(sCH__MON_FLOW_LOW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Flow Low \n";
						err_msg += err_bff;
					}
				}
				// Status.5
				{
					if(sCH__MON_PCW_PRESSURE_LOW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "PCW Pressure Low \n";
						err_msg += err_bff;
					}
					if(sCH__MON_ANTI_PHASE_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Anti-Phase \n";
						err_msg += err_bff;
					}
					if(sCH__MON_WATER_LEAK_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Water Leak \n";
						err_msg += err_bff;
					}
				}

				// Status.8
				{
					if(sCH__MON_TOTAL_FAULT_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Total Fault \n";
						err_msg += err_bff;
					}
				}

				if(err_msg.GetLength() > 0)
				{
					active__fault_check = true;
					dCH__MON_ACTIVE_FAULT_X[i]->Set__DATA(STR__ON);

					// ...
					{
						int alm_id = ALID__PART_FAULT + i;
						CString r_act;

						p_alarm->Check__ALARM(alm_id, r_act);
						p_alarm->Post__ALARM_With_MESSAGE(alm_id, err_msg);						
					}
				}
				else
				{
					dCH__MON_ACTIVE_FAULT_X[i]->Set__DATA(STR__OFF);
				}
			}

			if(active__fault_check)			dCH__MON_ACTIVE_FAULT_ALL->Set__DATA(STR__ON);
			else							dCH__MON_ACTIVE_FAULT_ALL->Set__DATA(STR__OFF);
		}

		// Warning ...
		{
			bool active__warningt_check = false;

			for(int i=0; i<_CFG__CH_SIZE; i++)
			{
				CString err_msg;
				CString err_bff;

				// Status.9
				{
					if(sCH__MON_LEVEL_LOW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Level Low \n";
						err_msg += err_bff;
					}
					if(sCH__MON_TEMP_ALARM_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Temperature Alarm \n";
						err_msg += err_bff;
					}
				}
				// Status.10
				{
					if(sCH__MON_TOTAL_WARNING_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Total Warning \n";
						err_msg += err_bff;
					}
					if(sCH__MON_PLC_BATTERY_LOW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "PLC Battery Low \n";
						err_msg += err_bff;
					}
					if(sCH__MON_RESISTIVITY_LOW_X[i]->Check__DATA(STR__ON) > 0)
					{
						err_bff = "Resistivity Low \n";
						err_msg += err_bff;
					}
				}

				if(err_msg.GetLength() > 0)
				{
					active__warningt_check = true;
					dCH__MON_ACTIVE_WARNING_X[i]->Set__DATA(STR__ON);

					// ...
					{
						int alm_id = ALID__PART_WARNING + i;
						CString r_act;

						p_alarm->Check__ALARM(alm_id, r_act);
						p_alarm->Post__ALARM_With_MESSAGE(alm_id, err_msg);						
					}
				}
				else
				{
					dCH__MON_ACTIVE_WARNING_X[i]->Set__DATA(STR__OFF);
				}
			}

			if(active__warningt_check)			dCH__MON_ACTIVE_WARNING_ALL->Set__DATA(STR__ON);
			else								dCH__MON_ACTIVE_WARNING_ALL->Set__DATA(STR__OFF);
		}
	}
}

