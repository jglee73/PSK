#include "StdAfx.h"
#include "CObj__AFC_RTU.h"
#include "CObj__AFC_RTU__DEF.h"


//------------------------------------------------------------------------------------
int CObj__AFC_RTU
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__AFC_RTU
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{

	return -1;
}

int CObj__AFC_RTU
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	CString log_msg;
	CString log_bff;

	// ...
	CString ch_data;

	unsigned char s_data[256];	
	int data_len;

	if(siCH__Matcher_Info ->Check__VARIABLE_NAME(var_name) > 0)
	{
		unsigned char addr_id = iPara__Slave_ID;
		unsigned char cmmd_id = _CMMD_ID__READ_INPUT;
		unsigned int  start_addr = 0;
		unsigned char read_num = 8; // _AICP 9
		data_len = _Make__READ_PACKET(s_data, addr_id,cmmd_id, start_addr, read_num);
		{
			log_msg.Format(" [%s] ->> ", var_name);

			for(int i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}

			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}

		data_len = _Recv__READ_PACKET(s_data, data_len);

		// Data Parsing
		{
			log_msg.Format(" [%1d] <<- ", data_len);
			for(int i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}

			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}
		CString Read_Data_Format="";
		{	// Matcher Status
			int off_i = 3;
			unsigned char byte_00 = s_data[off_i + 1];
			unsigned char byte_01 = s_data[off_i + 0];

			{
				unsigned char byte_bit = byte_00;

				if(0x01 & byte_bit)			dCH__MON_MAT_STS_MANUAL_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_MANUAL_ACTIVE->Set__DATA(STR__OFF);

				if(0x02 & byte_bit)			dCH__MON_MAT_STS_PRESET_ENABLE_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_PRESET_ENABLE_ACTIVE->Set__DATA(STR__OFF);

				if(0x04 & byte_bit)			dCH__MON_MAT_STS_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x08 & byte_bit)			dCH__MON_MAT_STS_RFON_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_RFON_ACTIVE->Set__DATA(STR__OFF);

				if(0x10 & byte_bit)			dCH__MON_MAT_STS_TUNE_MATCHED_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_TUNE_MATCHED_ACTIVE->Set__DATA(STR__OFF);
			}
			// Bit : 08 ~ 15
			{
				unsigned char byte_bit = byte_01;

				if(0x01 & byte_bit)			dCH__MON_MAT_STS_COAXIAL_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_COAXIAL_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x04 & byte_bit)			dCH__MON_MAT_STS_COVER_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_COVER_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x08 & byte_bit)			dCH__MON_MAT_STS_MOTOR_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_MOTOR_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x10 & byte_bit)			dCH__MON_MAT_STS_FAN1_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_FAN1_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x20 & byte_bit)			dCH__MON_MAT_STS_FAN2_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_FAN2_ALARM_ACTIVE->Set__DATA(STR__OFF);
			}
			Read_Data_Format.Format("%02X %02X ", byte_00,byte_01);
		}

		{	
			unsigned int VRMS = 0.0;
			double IRMS = 0.0;
			double Phase = 0.0;
			double Z_Imp = 0.0;


			// Value_Data
			int off_i = 5;
			int result_value = (s_data[off_i]<<8) + (s_data[off_i+1]);
			ch_data.Format("%.2f", ((double)result_value / 100.0));
			sCH__MON_CUR_LOAD_POSITION->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";

			off_i =7;
			result_value = (s_data[off_i]<<8) + (s_data[off_i+1]);
			ch_data.Format("%.2f", ((double)result_value / 100.0));
			sCH__MON_CUR_TUNE_POSITION->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";

			off_i =9;
			result_value = (s_data[off_i]<<8) + (s_data[off_i+1]);
			ch_data.Format("%1d", (unsigned int)result_value);
			sCH__MON_CUR_VPP->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";

			off_i =13;
			VRMS = (s_data[off_i]<<8) + (s_data[off_i+1]);
			ch_data.Format("%1d", VRMS);
			sCH__MON_CUR_VRMS->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";

			off_i =15;
			IRMS += ((s_data[off_i]<<8) + (s_data[off_i+1]))/100.0;
			ch_data.Format("%.2f", IRMS);
			sCH__MON_CUR_IRMS->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";
			
			off_i =17;
			Phase = ((s_data[off_i]<<8) + (s_data[off_i+1]))/10.0;
			ch_data.Format("%.2f", Phase);
			sCH__MON_CUR_Phase->Set__DATA(ch_data);
			Read_Data_Format += ch_data + " ";

			Z_Imp = VRMS/IRMS;
			aCH__MON_CUR_IMPEDANCE->Set__VALUE(Z_Imp);
			aCH__MON_CUR_REAL->Set__VALUE((double)(Z_Imp*cos(Phase)));
			aCH__MON_CUR_IMAGE->Set__VALUE((double)(Z_Imp*sin(Phase)));
			aCH__MON_CUR_DELIVERY_POWER->Set__VALUE((double)(VRMS*IRMS*cos(Phase)));
			
			read_data = Read_Data_Format;
			bActive__COMM_ONLINE = true;
			return 1;
		}





	}


	#pragma region BF_Section
	if((siCH__Matcher_State->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__Load_Position->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__Tune_Position->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__VPP->Check__VARIABLE_NAME(var_name)   > 0)
	|| (siCH__VRMS->Check__VARIABLE_NAME(var_name)  > 0)
	|| (siCH__IRMS->Check__VARIABLE_NAME(var_name)  > 0)
	|| (siCH__Phase->Check__VARIABLE_NAME(var_name) > 0))
	{
		unsigned char addr_id = iPara__Slave_ID;
		unsigned char cmmd_id = _CMMD_ID__READ_INPUT;
		unsigned int  start_addr;
		unsigned char read_num = 1;
		int i;

		if(siCH__Matcher_State->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 0;
		}
		else if(siCH__Load_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 1;
		}
		else if(siCH__Tune_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 2;
		}
		else if(siCH__VPP->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 3;
		}
		else if(siCH__VRMS->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 5;
		}
		else if(siCH__IRMS->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 6;
		}
		else if(siCH__Phase->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 7;
		}

		data_len = _Make__READ_PACKET(s_data, addr_id,cmmd_id, start_addr, read_num);

		// ...
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

		// ...
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
			read_data = STR__OFFLINE;
			bActive__COMM_ONLINE = false;
			return 1;
		}
		if(data_len < 5)
		{
			unsigned char err_code = s_data[2];
			
			ch_data.Format("%02X", err_code);
			sCH__MON_ERROR_CODE->Set__DATA(ch_data);

			ch_data = _Get__Error_Code(err_code);
			sCH__MON_ERROR_MSG->Set__DATA(ch_data);

			// ...
			{
				log_msg.Format(" Error Info ... \n");

				log_bff.Format(" * %s <- %s \n",
								sCH__MON_ERROR_CODE->Get__VARIABLE_NAME(),
								sCH__MON_ERROR_CODE->Get__STRING());
				log_msg += log_bff;

				log_bff.Format(" * %s <- %s \n",
								sCH__MON_ERROR_MSG->Get__VARIABLE_NAME(),
								sCH__MON_ERROR_MSG->Get__STRING());
				log_msg += log_bff;

				xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
			}

			//
			read_data = STR__ERROR;
			bActive__COMM_ONLINE = true;
			return 1;
		}

		// ...
		int off_i = 3;
		unsigned char byte_00 = s_data[off_i + 1];
		unsigned char byte_01 = s_data[off_i + 0];

		int result_value = (byte_01 << 8) + (byte_00);

		//
		if(siCH__Matcher_State->Check__VARIABLE_NAME(var_name) > 0)
		{
			// Bit : 00 ~ 07
			{
				unsigned char byte_bit = byte_00;

				if(0x01 & byte_bit)			dCH__MON_MAT_STS_MANUAL_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_MANUAL_ACTIVE->Set__DATA(STR__OFF);

				if(0x02 & byte_bit)			dCH__MON_MAT_STS_PRESET_ENABLE_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_PRESET_ENABLE_ACTIVE->Set__DATA(STR__OFF);

				if(0x04 & byte_bit)			dCH__MON_MAT_STS_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x08 & byte_bit)			dCH__MON_MAT_STS_RFON_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_RFON_ACTIVE->Set__DATA(STR__OFF);

				if(0x10 & byte_bit)			dCH__MON_MAT_STS_TUNE_MATCHED_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_TUNE_MATCHED_ACTIVE->Set__DATA(STR__OFF);
			}
			// Bit : 08 ~ 15
			{
				unsigned char byte_bit = byte_01;

				if(0x01 & byte_bit)			dCH__MON_MAT_STS_COAXIAL_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_COAXIAL_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x04 & byte_bit)			dCH__MON_MAT_STS_COVER_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_COVER_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x08 & byte_bit)			dCH__MON_MAT_STS_MOTOR_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_MOTOR_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x10 & byte_bit)			dCH__MON_MAT_STS_FAN1_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_FAN1_ALARM_ACTIVE->Set__DATA(STR__OFF);

				if(0x20 & byte_bit)			dCH__MON_MAT_STS_FAN2_ALARM_ACTIVE->Set__DATA(STR__ON);
				else						dCH__MON_MAT_STS_FAN2_ALARM_ACTIVE->Set__DATA(STR__OFF);
			}
		}
		else if(siCH__Load_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%.2f", ((double)result_value / 100.0));
			sCH__MON_CUR_LOAD_POSITION->Set__DATA(ch_data);
		}
		else if(siCH__Tune_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%.2f", ((double)result_value / 100.0));
			sCH__MON_CUR_TUNE_POSITION->Set__DATA(ch_data);
		}
		else if(siCH__VPP->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%1d", (unsigned int)result_value);
			sCH__MON_CUR_VPP->Set__DATA(ch_data);
		}
		else if(siCH__VRMS->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%1d", (unsigned int)result_value);
			sCH__MON_CUR_VRMS->Set__DATA(ch_data);
		}
		else if(siCH__IRMS->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%.2f", (double)result_value / 100.0);
			sCH__MON_CUR_IRMS->Set__DATA(ch_data);
		}
		else if(siCH__Phase->Check__VARIABLE_NAME(var_name) > 0)
		{
			ch_data.Format("%.2f", ((double)result_value / 10.0));
			sCH__MON_CUR_Phase->Set__DATA(ch_data);
		}



		read_data.Format("%02X %02X", byte_00,byte_01);
		bActive__COMM_ONLINE = true;
		return 1;
	}
	#pragma endregion

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__AFC_RTU
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{
	CString log_msg;
	CString log_bff;

	unsigned char s_data[256];	
	int data_len;

	if((aoCH__Preset_Load_Position->Check__VARIABLE_NAME(var_name) > 0)
	|| (aoCH__Preset_Tune_Position->Check__VARIABLE_NAME(var_name) > 0))
	{
		unsigned char addr_id = iPara__Slave_ID;
		unsigned char cmmd_id = _CMMD_ID__WRITE_HOLDING;
		unsigned int  start_addr = 0;
		unsigned int  write_num  = 1;	
		int i;

		if(aoCH__Preset_Load_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 10001; // AlphaCham : 0x1004
		}
		else if(aoCH__Preset_Tune_Position->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 10002; // AlphaCham : 0x1005
		}

		//
		short int set_i = (int) (set_data * 100.0);

		data_len = _Make__WRITE_PACKET_EX(s_data, addr_id,cmmd_id, start_addr, set_i);

		// ...
		{
			log_msg.Format(" [%s] ->> ", var_name);

			for(i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}

			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}

		//
		data_len = _Recv__READ_PACKET(s_data, data_len);

		// ...
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
			return -1;
		}

		return 1;
	}

	return -1;
}

int CObj__AFC_RTU
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	CString log_msg;
	CString log_bff;

	unsigned char s_data[256];	
	int data_len;

	if(doCH__OP_Mode->Check__VARIABLE_NAME(var_name) > 0)
	{
		unsigned char addr_id = iPara__Slave_ID;
		unsigned char cmmd_id = _CMMD_ID__WRITE_HOLDING;
		unsigned int  start_addr;	
		unsigned short ui_data;
		int i;

		if(doCH__OP_Mode->Check__VARIABLE_NAME(var_name) > 0)
		{
			start_addr = 10000;
			ui_data = 0x00;
			if(dCH__PARA_DRV_CTRL_MODE->Check__DATA(STR__MANUAL) > 0)		ui_data += 0x01;
			if(dCH__PARA_DRV_PRESET->Check__DATA(STR__ENABLE) > 0)			ui_data += 0x02;

		}
		//
		data_len = _Make__WRITE_PACKET_EX(s_data, addr_id,cmmd_id, start_addr,ui_data);

		// ...
		{
			log_msg.Format(" [%s] ->> ", var_name);
			for(i=0; i<data_len; i++)
			{
				log_bff.Format("[%02X] ", s_data[i]);
				log_msg += log_bff;
			}
			xI__DRV_LOG_CTRL->WRITE__LOG(log_msg);
		}

		//
		data_len = _Recv__READ_PACKET(s_data, data_len);

		// ...
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
			return -1;
		}

		return 1;
	}

	return -1;
}

int CObj__AFC_RTU
::__Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data)
{

	return -1;
}
