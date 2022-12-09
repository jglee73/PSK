#include "StdAfx.h"
#include "CObj__PM_METAL.h"
#include "CObj__PM_METAL__DEF.h"


#define _DEF__ADDRESS_2000				2000


// ...
int CObj__PM_METAL
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__PM_METAL
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{

	return -1;
}

int CObj__PM_METAL
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	CString log_msg;
	CString log_bff;

	CString ch_data;

	unsigned char s_data[256];	
	int data_len;

	
	if((siCH__D2000_BOTTLE_CONDITION->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2005_BOTTLE_WEIGHT_PER->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2007_BOTTLE_PT1->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2008_BOTTLE_PT2->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2009_BOTTLE_PT3->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2020_BOTTLE_VALVE->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__D2029_ALARM_STATE->Check__VARIABLE_NAME(var_name) > 0))
	{
		unsigned char addr_id = iPara__Addr_ID;
		unsigned char cmmd_id = _CMMD_ID__READ;
		unsigned int  start_addr = _DEF__ADDRESS_2000;
		unsigned char read_num = 1;
		int i;

		if(siCH__D2000_BOTTLE_CONDITION->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 0;
		}
		else if(siCH__D2005_BOTTLE_WEIGHT_PER->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 5;
		}
		else if(siCH__D2007_BOTTLE_PT1->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 7;
		}
		else if(siCH__D2008_BOTTLE_PT2->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 8;
		}
		else if(siCH__D2009_BOTTLE_PT3->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 9;
		}
		else if(siCH__D2020_BOTTLE_VALVE->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 20;
		}
		else if(siCH__D2029_ALARM_STATE->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr += 29;
		}

		data_len = _Make__READ_PACKET(s_data, addr_id,cmmd_id, start_addr, read_num);

		// SEND ...
		{
			log_msg.Format(" [%s] ->> ", var_name);
			
			for(i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}

			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}

		data_len = _Recv__READ_PACKET(s_data, data_len);

		// RECV ...
		{
			log_msg.Format(" [%1d] <<- ", data_len);

			for(i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}

			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}

		if(data_len < 0)
		{
			bActive__COMM_ONLINE = false;
			return -1;
		}
		else
		{
			bActive__COMM_ONLINE = true;
		}

		if(read_num == 1)
		{
			JG_UI2 get_ui;
			int off_i = 3;

			unsigned char byte_0 = 0x0ff & s_data[off_i + 0];
			unsigned char byte_1 = 0x0ff & s_data[off_i + 1];

			get_ui.uData[1] = byte_0;
			get_ui.uData[0] = byte_1;

			read_data.Format("%02X %02X", byte_0, byte_1);
			unsigned int i_data = get_ui.uiValue;

			if(siCH__D2000_BOTTLE_CONDITION->Check__VARIABLE_NAME(var_name) > 0)
			{
				_Update__BOTTLE_STATE(i_data);
				return 1;
			}
			if(siCH__D2020_BOTTLE_VALVE->Check__VARIABLE_NAME(var_name) > 0)
			{
				_Update__BOTTLE_VALVE(i_data);
				return 1;
			}
			if(siCH__D2029_ALARM_STATE->Check__VARIABLE_NAME(var_name) > 0)
			{
				_Update__ALARM_ACTIVE(i_data);
				return 1;
			}
			
			if(siCH__D2005_BOTTLE_WEIGHT_PER->Check__VARIABLE_NAME(var_name) > 0)
			{
				ch_data.Format("%1d", i_data);
				sCH__INFO_BOTTLE_WEIGHT_PER->Set__DATA(ch_data);
				return 1;
			}

			if(siCH__D2007_BOTTLE_PT1->Check__VARIABLE_NAME(var_name) > 0)
			{
				ch_data.Format("%1d", i_data);
				sCH__INFO_PT1_PSI->Set__DATA(ch_data);
				return 1;
			}
			if(siCH__D2008_BOTTLE_PT2->Check__VARIABLE_NAME(var_name) > 0)
			{
				ch_data.Format("%1d", i_data);
				sCH__INFO_PT2_PSI->Set__DATA(ch_data);
				return 1;
			}
			if(siCH__D2009_BOTTLE_PT3->Check__VARIABLE_NAME(var_name) > 0)
			{
				ch_data.Format("%1d", i_data);
				sCH__INFO_PT3_PSI->Set__DATA(ch_data);
				return 1;
			}
		}
		else
		{
			JG_F4 get_fx;
			int off_i = 3;

			unsigned char byte_0 = 0x0ff & s_data[off_i + 0];
			unsigned char byte_1 = 0x0ff & s_data[off_i + 1];
			unsigned char byte_2 = 0x0ff & s_data[off_i + 2];
			unsigned char byte_3 = 0x0ff & s_data[off_i + 3];

			read_data.Format("%02X %02X %02X %02X", byte_0, byte_1, byte_2, byte_3);

			/*
			get_fx.uData[3] = byte_2;
			get_fx.uData[2] = byte_3;
			get_fx.uData[1] = byte_0;
			get_fx.uData[0] = byte_1;

			read_data.Format("%.3f", get_fx.fValue);
			*/
		}

		return 1;
	}

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__PM_METAL
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{

	return -1;
}

int CObj__PM_METAL
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{

	return -1;
}

int CObj__PM_METAL
::__Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data)
{

	return -1;
}

