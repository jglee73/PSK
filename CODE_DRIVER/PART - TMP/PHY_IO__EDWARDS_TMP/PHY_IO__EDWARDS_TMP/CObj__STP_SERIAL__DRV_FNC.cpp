#include "StdAfx.h"
#include "CObj__STP_SERIAL.h"

#include "Macro_Function.h"


//------------------------------------------------------------------------------------
int CObj__STP_SERIAL
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__STP_SERIAL
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{

	return -1;
}

int CObj__STP_SERIAL
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	CString ch_data;
	CString str_cmmd;
	CString r_data;

	if(siCH__ReadMeasValue_Result->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "?[";
		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			read_data = "Error";
			return -1;
		}
		
		// 00(06) : Header
		// 07(30) : System reservation             // 01
		// 37(04) : TMS temperature                // 02
		CString para__tms_temp = r_data.Mid(37, 4);   
		// 41(04) : Motor temperature              // 03
		CString para__mtr_temp = r_data.Mid(41, 4);   
		// 45(02) : System reservation             // 04
		// 47(02) : Motor current                  // 05
		CString para__mtr_current = r_data.Mid(47, 2);   
		// 49(06) : System reservation             // 06
		// 55(04) : Measured rotational speed      // 07
		CString para__rot_speed_hz = r_data.Mid(55, 4); 
		// 59(12) : System reservation             // 08
		// 71(04) : Control unit temperature       // 09
		CString para__unit_temp = r_data.Mid(71, 4); 
		
		// 03 : Motor temperature		
		{
			int cur__mtr_temperature = Macro__HexToDec(para__mtr_temp);

			ch_data.Format("%1d", cur__mtr_temperature);
			sCH__INFO_MOTOR_TEMPERATURE_READ->Set__DATA(ch_data);
		}
		
		// 07 : Measured rotational speed (hz)
		{
			int cur__rot_hz = Macro__HexToDec(para__rot_speed_hz);
			
			ch_data.Format("%1d", cur__rot_hz);
			sCH__INFO_ROT_SPEED_HZ->Set__DATA(ch_data);
			
			ch_data.Format("%1d", cur__rot_hz * 60);
			sCH__INFO_ROT_SPEED_RPM->Set__DATA(ch_data);
		}
		
		read_data = "OK";
		return 1;
	}
	
	if(siCH__ReadModFonct->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "?M";

		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			read_data = "Error";
			return 1;
		}

		// ...
		CString para_01 = r_data.Mid(7, 2);
		CString para_02 = r_data.Mid(9, 2);

		int cur__op_mode = Macro__HexToDec(para_01);
		int cur__err_cnt = Macro__HexToDec(para_02);
			
		// OP_MODE ...
		{
			CString str__op_mode;

			switch(cur__op_mode)
			{
				case 1:			str__op_mode = STR__Levitation;			break;
				case 2:			str__op_mode = STR__NoLevitation;		break;
				case 3:			str__op_mode = STR__Acceleration;		break;
				case 4:			str__op_mode = STR__Normal;				break;
				case 5:			str__op_mode = STR__Deceleration;		break;
				case 6:			str__op_mode = STR__AutoTest;			break;
				case 7:			str__op_mode = STR__Tuning;				break;
				case 8:			str__op_mode = STR__Tuning_Complete;	break;

				case 9:
				case 10:
				case 11:
					str__op_mode = "[System Reservation]";		
					break;

				default:
					str__op_mode = "Unknown";
					break;
			}

			sCH__INFO_PUMP_OP_MODE->Set__DATA(str__op_mode);
		}
		// ERR_COUNT ...
		{
			ch_data.Format("%1d", cur__err_cnt);
			sCH__INFO_ERROR_COUNT->Set__DATA(ch_data);
		}

		read_data = "OK";
		return 1;
	}

	if(siCH__All_Version_Manual->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "?V";

		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			read_data = "Error";
			return 1;
		}

		// ...
		CString para_01 = r_data.Mid(7, 32); //  8bit - ASCII(16bit) - HEX(32bit)
		CString para_02 = r_data.Mid(39, 4); // 4bit
		CString para_03 = r_data.Mid(43, 4); // 4bit

		// ...
		{
			para_01.Format("%1d", Macro__HexToDec(para_01));
			ch_data = Macro__HEX_ASCII_TO_ASCII(para_01); // 8bit - ASCII(16bit) - HEX(32bit)
			sCH__INFO_VERSION__CTRL_UNIT->Set__DATA(ch_data);

			ch_data.Format("%1d", Macro__HexToDec(para_02)); // 4bit ASCII CHART(Motor Driver Version)
			sCH__INFO_VERSION__MTR_DRV->Set__DATA(ch_data);

			ch_data.Format("%1d", Macro__HexToDec(para_03)); // 4bit ASCII CHART(AMB Software Version)
			sCH__INFO_VERSION__AMB_SW->Set__DATA(ch_data);
		}

		read_data = "OK";
		return 1;
	}

	if(siCH__Read_SetPoint_Manual->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "?d";

		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			read_data = "Error";
			return 1;
		}

		CString para_01 = r_data.Mid(7, 4);
		CString para_02 = r_data.Mid(11, 4);

		// ...
		{
			int speed_hz = Macro__HexToDec(para_01);

			ch_data.Format("%1d", speed_hz);
			sCH__INFO_SPEED_SETPOINT_HZ->Set__DATA(ch_data);

			ch_data.Format("%1d", speed_hz * 60);
			sCH__INFO_SPEED_SETPOINT_RPM->Set__DATA(ch_data);

			//
			ch_data.Format("%1d", Macro__HexToDec(para_02));
			sCH__INFO_TMS_TEMPERATURE_SETTING->Set__DATA(ch_data);
		}

		read_data = "OK";
		return 1;
	}

	return -1;
	
}


//------------------------------------------------------------------------------------
int CObj__STP_SERIAL
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{
	CString str_cmmd;
	CString s_data;
	CString r_data;

	if(aoCH__SET_SPEED_HZ->Check__VARIABLE_NAME(var_name) > 0)
	{
		s_data.Format("%04X", (int) set_data); // 0190 :400hz : 24,000rpm

		str_cmmd  = " h";
		str_cmmd += s_data;

		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			return -1;
		}

		return 1;
	}

	return 1;
}

int CObj__STP_SERIAL
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	CString str_cmmd;
	CString r_data;


	if(doCH__OP_CMMD->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = " E";

			 if(set_data.CompareNoCase(CMMD__START) == 0)			str_cmmd += "01";
		else if(set_data.CompareNoCase(CMMD__STOP)  == 0)			str_cmmd += "02";
		else if(set_data.CompareNoCase(CMMD__RESET) == 0)			str_cmmd += "04";
		else
		{
			return -1;
		}

		int r_val = Recv_Command(var_name, str_cmmd, r_data);
		if(r_val < 0)
		{
			return -1;
		}

		return 1;
	}

	return -1;
}

int CObj__STP_SERIAL
::__Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data)
{

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__STP_SERIAL
::Recv_Command(const CString& var_name, const CString& s_cmmd, CString& r_data)
{
	r_data = "";

	// ...
	int cfg_msec = (int) aCH__CFG_DRV_MON_INTERVAL->Get__VALUE();
	int n_cnt = 0;

	do 
	{
		unsigned char send_cmmd[256];
		unsigned char recv_cmmd[256];
		int  data_i;

		// Send_Command ...
		{
			data_i = 0;
			send_cmmd[data_i++] = _STX;
			send_cmmd[data_i++] = '0';
			send_cmmd[data_i++] = '0';
			send_cmmd[data_i++] = '1';
		
			int k_limit = s_cmmd.GetLength();
			for(int k=0; k<k_limit; k++)
			{
				send_cmmd[data_i++] = s_cmmd[k];
			}
			send_cmmd[data_i++] = _ETX;
			// LRC
			send_cmmd[data_i++] = _Get__CheckSum(send_cmmd, data_i);
		}
		// Recv_Command ...
		{
			memset(recv_cmmd, 0, sizeof(char)*255);
		}

		// ...
		{
			CString log_msg;
			log_msg.Format("Var_Name <- %s \n", var_name);
			xDRV_LOG_CTRL->WRITE__LOG(log_msg); 
		}
		// ...
		{
			CString log_msg;
			CString log_bff;

			log_msg  = "\n";
			log_msg += "Send >> \n";

			for(int i=0; i<data_i; i++)
			{
				log_bff.Format("%c ", send_cmmd[i]);
				// log_bff.Format("%02X ", send_cmmd[i]);
				log_msg += log_bff;
			}

			xDRV_LOG_CTRL->WRITE__LOG(log_msg);
		}
		// ...
		CString err_msg;
		mX_Serial->CLEAR__BUFFER(&err_msg);
		
		mX_Serial->CHAR__SEND(send_cmmd, data_i); // 처음 Command 전송
		
		// ...
		int r_len = 0;
		int r_val = mX_Serial->CHAR__RECV(recv_cmmd, _ETX,&r_len, 500); // ACK - STX Recived
		
		if(r_val >= 0)
		{
			bActive__COOM_ONLINE = true;

			// Recv Response Message...
			{
				CString log_msg;
				CString log_bff;

				log_msg  = "\n";
				log_msg += "Recv << ";

				for(int i=0; i<r_len; i++)
				{
					log_bff.Format("%02X ", recv_cmmd[i]);
					log_msg += log_bff;
				}

				xDRV_LOG_CTRL->WRITE__LOG(log_msg);
			}

			// ...
			char r_rsp = recv_cmmd[0];
			
			if(r_rsp == _ACK)     //_ACK -> _STX
			{
				r_data = "";
				for(int i=0; i<r_len; i++)
				{
					r_data += recv_cmmd[i];
				}

				// SEND > ACK 
				{ 
					data_i = 0;
					send_cmmd[data_i++] = _ACK;
					
					mX_Serial->CHAR__SEND(send_cmmd, data_i);
					
					// Send.OK ...
					{
						CString log_msg;
						log_msg.Format("Send >> ACK \n");
						xDRV_LOG_CTRL->WRITE__LOG(log_msg);
					}
					
					Sleep(cfg_msec);
					return 1;
				}
			}
			
			// Sens.ACK ...
			{
				CString log_msg;
				CString log_bff;

				log_msg  = "\n";
				log_bff.Format("Error : No ACK(%1d) \n", r_len);
				log_msg += log_bff;

				xDRV_LOG_CTRL->WRITE__LOG(log_msg);
			}
		}

		// Recv.Error ...
		{
			CString log_msg;
			CString log_bff;

			log_msg  = "\n";
			log_bff.Format(" Error (%1d) \n", r_len);
			log_msg += log_bff;

			xDRV_LOG_CTRL->WRITE__LOG(log_msg);
		}
		
		Sleep(cfg_msec);
	} 
	while(++n_cnt < 2);

	bActive__COOM_ONLINE = false;

	Sleep(cfg_msec);
	return -1;
}

byte CObj__STP_SERIAL::_Get__CheckSum(const unsigned char* s_cmmd, const int s_len)
{
	// byte LRC = 0x00; // Yujin Code
	byte LRC = 0xFF; // PSK COde

	for(int i = 0; i < s_len; i++)
	{
		LRC ^= (byte) s_cmmd[i];
	}
	// LRC ^= 0xFF; Yujin Code

	return LRC;
}
