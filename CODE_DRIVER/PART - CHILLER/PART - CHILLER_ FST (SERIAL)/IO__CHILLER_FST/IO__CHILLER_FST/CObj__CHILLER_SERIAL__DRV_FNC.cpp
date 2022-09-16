#include "StdAfx.h"
#include "CObj__CHILLER_SERIAL.h"
#include "CObj__CHILLER_SERIAL__DEF.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int CObj__CHILLER_SERIAL
::__Read__ANALOG(const CString& var_name, 
				 const CDS_IO__CHANNEL_INFO& io_info, 
				 double& read_data)
{
	
	return -1;
}

int CObj__CHILLER_SERIAL
::__Read__DIGITAL(const CString& var_name,
				  const CDS_IO__CHANNEL_INFO& io_info, 
				  CString& read_data,
				  int& item_index)
{

	return -1;
}

int CObj__CHILLER_SERIAL
::__Read__STRING(const CString& var_name, 
				 const CDS_IO__CHANNEL_INFO& io_info, 
				 CString& read_data)
{

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__CHILLER_SERIAL
::__Write__ANALOG(const CString& var_name, 
				  const CDS_IO__CHANNEL_INFO& io_info, 
				  const double set_data)
{

	return -1;
}

int CObj__CHILLER_SERIAL
::__Write__DIGITAL(const CString& var_name,
				   const CDS_IO__CHANNEL_INFO& io_info, 
				   const CString& set_data,
				   const int item_index)
{
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		if(doCH__CHANNEL_SET_X[i]->Check__VARIABLE_NAME(var_name) > 0)
		{
			if(set_data.CompareNoCase(_Cmmd_IO__Set) == 0)
			{
				return _Drv__CMMD_SEND(i);			
			}
			else
			{
				return -11;
			}
		}
		else
		{
			continue;
		}
	}

	return -1;
}

int CObj__CHILLER_SERIAL
::__Write__STRING(const CString& var_name, 
				  const CDS_IO__CHANNEL_INFO& io_info, 
				  const CString& set_data)
{
	
	return -1;
}


// ...
int  CObj__CHILLER_SERIAL
::_Get__CHECK_SUM(const CString& set_cmmd)
{
	int sum_hexa = 0x00;

	int i_limit = set_cmmd.GetLength();
	int i;

	for(i=0; i<i_limit; i++)
	{
		unsigned char cur_hexa = set_cmmd.GetAt(i);
		sum_hexa += cur_hexa;
	}

	return sum_hexa;
}

int CObj__CHILLER_SERIAL
::_Get__Hexa_From_String(const CString& str_data)
{
	int i_hexa = 0;

	int i_limit = str_data.GetLength();
	int i;

	for(i=0; i<i_limit; i++)
	{
		char ch = str_data[i];

		i_hexa *= 0x10;

		if((ch >= '0') && (ch <= '9'))
		{
			i_hexa += (ch - '0');
			continue;
		}
		if((ch >= 'A') && (ch <= 'F'))
		{
			i_hexa += ((ch - 'A') + 10);
			continue;
		}
		if((ch >= 'a') && (ch <= 'f'))
		{
			i_hexa += ((ch - 'a') + 10);
			continue;
		}		
	}

	return i_hexa;
}

int  CObj__CHILLER_SERIAL
::_Drv__CMMD_SEND(const int para__ch_index)
{
	CString cmmd_set = "";

	// ...
	{
		CString cmmd_bff;

		//
		double para__set_temp = aCH__PARA_SET_TEMPERATURE_X[para__ch_index]->Get__VALUE();
		int para__temp_hexa = (int) (para__set_temp * 10.0);

		int para__start_active  = 0;
		int para__remote_active = 0;

		if(dCH__PARA_SET_CONTROL_X[para__ch_index]->Check__DATA(STR__RUN)    > 0)		para__start_active  = 1;
		if(dCH__PARA_SET_CONNECT_X[para__ch_index]->Check__DATA(STR__REMOTE) > 0)		para__remote_active = 1;

		//
		cmmd_bff.Format("%02d", 0x0ff & para__ch_index+1);
		cmmd_set += cmmd_bff;
		cmmd_set += "00";

		cmmd_bff.Format("%04X", para__temp_hexa);
		cmmd_set += cmmd_bff;
		
		//
		unsigned char hexa_sts = 0x00;
		if(para__start_active  > 0)		hexa_sts += 0x02;
		if(para__remote_active > 0)		hexa_sts += 0x01;

		cmmd_bff.Format("%1X", hexa_sts);
		cmmd_set += cmmd_bff;

		//
		int check_sum = _Get__CHECK_SUM(cmmd_set);

		cmmd_bff.Format("%02X", (0x0ff & check_sum));    // 맞는지? 확인 필요 !
		cmmd_set += cmmd_bff; 
	}

	// ...
	int rty_cnt = 0;

LOOP_RETRY:
	
	// ...
	CString log_msg = "";
	CString log_bff = "";

	// ...
	CString bff;
	mX_Serial->CLEAR__BUFFER(&bff);

	// ...
	{
		log_msg = "SEND >> \n";

		log_bff.Format("<STX>%s<ETX><CR> \n", cmmd_set);
		log_msg += log_bff;
		
		WRITE__DRV_LOG_MSG(log_msg);
	}

	// ...
	{
		CString s_packet = "";

		s_packet += (char) STX;
		s_packet += cmmd_set;
		s_packet += (char) ETX;
		s_packet += (char) CR;
	
		mX_Serial->DATA__SEND(s_packet);
	}

	// ...
	CString cmmd_end = "";
	cmmd_end = (char) CR;

	CString r_data;
	int r_flag = mX_Serial->DATA__RECV(cmmd_end, &r_data, 200);

	// ...
	{
		log_msg.Format("RECV << (%1d) \n", r_flag);

		log_bff.Format("%s \n", r_data);
		log_msg += log_bff;

		WRITE__DRV_LOG_MSG(log_msg);
	}

	if(r_flag < 0)
	{
		rty_cnt++;	
		if (rty_cnt < 3)
		{
			log_msg.Format( "Error retry [%d] !", rty_cnt);
			WRITE__DRV_LOG_MSG(log_msg);

			goto LOOP_RETRY;
		}

		log_msg.Format( "Error timeout ! \n");
		WRITE__DRV_LOG_MSG(log_msg);

		bActive__COMM_ONLINE = false;
		return -1;
	}

	if(r_data.GetLength() > 27)
	{
		char cur_ch = r_data.GetAt(0);
		if(cur_ch == STX)
		{
			// 01. To_Address
			CString str__to_address = r_data.Mid(1, 2);

			// 03. Flow_Address
			CString str__flow_address = r_data.Mid(3, 2);

			// 05. Actual Temperature
			{
				CString str_data = r_data.Mid(5, 4);

				int i_hexa = _Get__Hexa_From_String(str_data);
				str_data.Format("%.1f", i_hexa * 0.1);

				sCH__MON_ACTUAL_TEMPERATURE_X[para__ch_index]->Set__DATA(str_data);
			}
			// 09. Flow Rate
			{
				CString str_data = r_data.Mid(9, 4);

				int i_hexa = _Get__Hexa_From_String(str_data);
				str_data.Format("%.1f", i_hexa * 0.1);

				sCH__MON_FLOW_RATE_X[para__ch_index]->Set__DATA(str_data);
			}
			// 13. Resistivity
			{
				CString str_data = r_data.Mid(13, 4);

				int i_hexa = _Get__Hexa_From_String(str_data);
				str_data.Format("%.1f", i_hexa * 0.1);

				sCH__MON_RESISTIVITY_X[para__ch_index]->Set__DATA(str_data);
			}

			// 17. Status_01
			{
				CString str_state = r_data.Mid(17, 1);

				_Update__STATE_01(para__ch_index, str_state);
			}
			// 18. Status_02
			{
				CString str_state = r_data.Mid(18, 1);

				_Update__STATE_02(para__ch_index, str_state);
			}
			// 19. Status_03
			{
				CString str_state = r_data.Mid(19, 1);

				_Update__STATE_03(para__ch_index, str_state);
			}
			// 20. Status_04
			{
				CString str_state = r_data.Mid(20, 1);

				_Update__STATE_04(para__ch_index, str_state);
			}
			// 21. Status_05
			{
				CString str_state = r_data.Mid(21, 1);

				_Update__STATE_05(para__ch_index, str_state);
			}
			// 22. Status_06
			{
				CString str_state = r_data.Mid(22, 1);

			}
			// 23. Status_07
			{
				CString str_state = r_data.Mid(23, 1);

			}
			// 24. Status_08
			{
				CString str_state = r_data.Mid(24, 1);

				_Update__STATE_08(para__ch_index, str_state);
			}
			// 25. Status_09
			{
				CString str_state = r_data.Mid(25, 1);

				_Update__STATE_09(para__ch_index, str_state);
			}
			// 26. Status_10
			{
				CString str_state = r_data.Mid(26, 1);

				_Update__STATE_10(para__ch_index, str_state);
			}
		}
	}

	bActive__COMM_ONLINE = true;
	return 1;
}

int CObj__CHILLER_SERIAL
::_Update__STATE_01(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// RUN/STOP
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_CONTROL_X[ch_index]->Set__DATA(STR__RUN);
			else					sCH__MON_CONTROL_X[ch_index]->Set__DATA(STR__STOP);
		}
		else if(i == 1)				// LEVEL FULL
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_LEVEL_FULL_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_LEVEL_FULL_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// REMOTE/LOCAL
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_CONNECT_X[ch_index]->Set__DATA(STR__REMOTE);
			else					sCH__MON_CONNECT_X[ch_index]->Set__DATA(STR__LOCAL);
		}				
	}

	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_02(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Temp. Fail
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_TEMPERATURE_FAIL_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_TEMPERATURE_FAIL_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 1)				// Over. Temp (SW)
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_OVER_TEMPERATURE_SW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_OVER_TEMPERATURE_SW_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// Over. Temp (HW)
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_OVER_TEMPERATURE_HW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_OVER_TEMPERATURE_HW_X[ch_index]->Set__DATA(STR__OFF);
		}				
		else if(i == 3)				// Comp. Thermostat
		{
			bit_sts = i_data & 0x08;

			if(bit_sts > 0)			sCH__MON_COMP_THERMOSTAT_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_COMP_THERMOSTAT_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}

	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_03(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Pump.Pressure Fail
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_PUMP_PRESSURE_FAIL_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_PUMP_PRESSURE_FAIL_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 1)				// Pump.Over Current
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_PUMP_OVER_CURRENT_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_PUMP_OVER_CURRENT_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// Comp.Pressure Fail
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_COMP_PRESSURE_FAIL_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_COMP_PRESSURE_FAIL_X[ch_index]->Set__DATA(STR__OFF);
		}				
		else if(i == 3)				// Comp.Over Current
		{
			bit_sts = i_data & 0x08;

			if(bit_sts > 0)			sCH__MON_COMP_OVER_CURRENT_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_COMP_OVER_CURRENT_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}
			
	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_04(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Flow Low
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_FLOW_LOW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_FLOW_LOW_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 1)				// Level Empty
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_LEVEL_EMPTY_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_LEVEL_EMPTY_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// Temp. Range Over Limit
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_TEMP_RANGE_OVER_LIMIT_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_TEMP_RANGE_OVER_LIMIT_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}

	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_05(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Water Leak
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_WATER_LEAK_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_WATER_LEAK_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 1)				// Anti Phase
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_ANTI_PHASE_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_ANTI_PHASE_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// PCW Pressure Low
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_PCW_PRESSURE_LOW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_PCW_PRESSURE_LOW_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}

	return 1;
}

int CObj__CHILLER_SERIAL
::_Update__STATE_08(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 2)					// Total Fault
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_TOTAL_FAULT_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_TOTAL_FAULT_X[ch_index]->Set__DATA(STR__OFF);
		}
	}

	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_09(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Temp. Alarm
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_TEMP_ALARM_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_TEMP_ALARM_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 3)				// Level Low
		{
			bit_sts = i_data & 0x08;

			if(bit_sts > 0)			sCH__MON_LEVEL_LOW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_LEVEL_LOW_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}

	return 1;
}
int CObj__CHILLER_SERIAL
::_Update__STATE_10(const int ch_index, const CString& rsp_data)
{
	unsigned char bit_sts;
	unsigned char i_data = atoi(rsp_data);

	int i_limit = 8;
	for(int i=0; i<i_limit; i++)
	{
		if(i == 0)					// Resistivity Low
		{
			bit_sts = i_data & 0x01;

			if(bit_sts > 0)			sCH__MON_RESISTIVITY_LOW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_RESISTIVITY_LOW_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 1)				// PLC Battery Low
		{
			bit_sts = i_data & 0x02;

			if(bit_sts > 0)			sCH__MON_PLC_BATTERY_LOW_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_PLC_BATTERY_LOW_X[ch_index]->Set__DATA(STR__OFF);
		}
		else if(i == 2)				// Total Warning
		{
			bit_sts = i_data & 0x04;

			if(bit_sts > 0)			sCH__MON_TOTAL_WARNING_X[ch_index]->Set__DATA(STR__ON);
			else					sCH__MON_TOTAL_WARNING_X[ch_index]->Set__DATA(STR__OFF);
		}				
	}
	
	return 1;
}

