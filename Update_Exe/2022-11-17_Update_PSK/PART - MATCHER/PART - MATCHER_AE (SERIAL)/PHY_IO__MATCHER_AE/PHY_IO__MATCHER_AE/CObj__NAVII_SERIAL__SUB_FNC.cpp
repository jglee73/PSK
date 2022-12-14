#include "StdAfx.h"
#include "CObj__NAVII_SERIAL.h"


// ...
void  CObj__NAVII_SERIAL::
Fnc__Do_Abort(CII_OBJECT__ALARM* p_alarm)
{

}

int  CObj__NAVII_SERIAL::
Fnc__Is_Online(CII_OBJECT__ALARM* p_alarm)
{
	if(dCH__MON_COMM_STS->Check__DATA(STR__ONLINE) < 0)
	{
		CString r_act;

		p_alarm->Popup__ALARM(ALID__OFFLINE_ALARM, r_act);
		return -1;
	}
	return 1;
}

int CObj__NAVII_SERIAL
::_Convert_ToInt(int start_idx, int end_idx, unsigned char *data)
{
	unsigned int iResult = 0;
	for(int i = end_idx; i >= start_idx; i--)
	{
		iResult	+= 0x0ff & data[i];
		if(i > start_idx) iResult = iResult << 8;
	}
	return iResult;
}

// ...
void CObj__NAVII_SERIAL
::_Set_CheckSum(unsigned char* s_cmmd, const int s_len)
{
	unsigned char ch_cs = 0;
	int i;

	for(i=0; i<s_len ; i++)  
	{	
		ch_cs = ch_cs ^ s_cmmd[i];
	}

	s_cmmd[i]   = ch_cs;
	s_cmmd[i+1] = 0;
}

int CObj__NAVII_SERIAL
::_Recv__Command(const CString& var_name,
				 const byte addr_id,
				 const byte cmmd_id,
				 const byte s_data_len,
				 const byte r_data_len, 
				 unsigned char* send_data,
				 unsigned char* recv_data)
{
	// Log ...
	{
		CString s_msg;
		CString s_bff;

		s_bff.Format("_Recv__Command() \n");
		s_msg += s_bff;
		s_bff.Format("var_name <- %s \n", var_name);
		s_msg += s_bff;

		Write__DRV_LOG(s_msg);
	}

	// ...
	int	n_cnt = 1;

	do 
	{
		unsigned char s_cmmd[MAX_CHAR] = {0,};
		unsigned char r_data[MAX_CHAR] = {0,};
		byte ref_data = 6;

		int cmmd_len = 0;

		// Send Command ...
		{
			int db_i = 0;

			if(s_data_len > ref_data)		cmmd_len = 3 + s_data_len; 
			else							cmmd_len = 2 + s_data_len;

			if(s_data_len > ref_data)		s_cmmd[db_i++] = (addr_id << 3) + 0x07;
			else							s_cmmd[db_i++] = (addr_id << 3) + s_data_len;		

			s_cmmd[db_i++] = cmmd_id;

			if(s_data_len > ref_data)		s_cmmd[db_i++] = 0x0ff & s_data_len;

			for(byte k=0; k<(s_data_len); k++)
			{
				s_cmmd[db_i++] = 0x0ff & send_data[k];
			}

			_Set_CheckSum(s_cmmd, cmmd_len);  
		}

		// ...
		int s_flag;
		int s_len = cmmd_len + 1;		

		// Send Data ...
		{
			CString cls_bff;
			mX_Serial->CLEAR__BUFFER(&cls_bff);

			s_flag = mX_Serial->CHAR__SEND(s_cmmd, s_len);
		}

		// Receive Length : ACK(1) + Header(1) + Command(1) + ReturnByte(n) + Checksum(1)
		int r_flag;
		int r_len = 4 + r_data_len;
		if(r_data_len > ref_data)			r_len++;

		// Receive Data ...
		{
			r_flag = mX_Serial->CHAR__RECV(r_data, &r_len, m_Rcv_Time);
		}

		// Send Log ...
		{
			CString s_msg;
			CString s_bff;

			s_msg.Format("s_flag : %1d \n", s_flag);

			for(int i=0; i<s_len; i++)
			{
				s_bff.Format("%02X ", s_cmmd[i]);
				s_msg += s_bff;
			}

			Write__DRV_LOG(s_msg);
		}
		// Receive Log ...
		{
			CString r_msg;
			CString r_bff;

			r_msg.Format("r_flag : %1d \n", r_flag);

			for(int i=0; i<r_len; i++)
			{
				r_bff.Format("%02X ", r_data[i]);
				r_msg += r_bff;
			}

			Write__DRV_LOG(r_msg);
		}

		// ACK Check ...
		{
			for(int i=0; i<r_len; i++)
			{
				if(r_data[i] != ACK)		continue;

				// ...
				{
					unsigned char s_ack[2];
					s_ack[0] = ACK;

					mX_Serial->CHAR__SEND(s_ack, 1);
				}

				// ...
				int k = 0;

				for(i++; i<r_len; i++)
				{
					recv_data[k++] = r_data[i];
				}
				recv_data[k] = 0;

				bActive__COMM_ONLINE = true;
				return k;
			}
		}

		Sleep(100);
	}
	while(++n_cnt <= m_RetryCnt);

	bActive__COMM_ONLINE = false;
	return -1;
}

CString CObj__NAVII_SERIAL
::_Get__CSR_CODE(const byte csr_code)
{
	if(csr_code == 0)		return "Command accepted.";

	if(csr_code == 1)		return "Control mode is incorrect.";
	if(csr_code == 2)		return "Output is on (change not allowed).";

	if(csr_code == 4)		return "Command specifies a value that exceeds the limit for that parameter.";
	if(csr_code == 5)		return "User port off signal is active.";

	if(csr_code == 7)		return "One or more faults are active.";
	if(csr_code == 8)		return "Setpoint ramping is active.";
	if(csr_code == 9)		return "Command's data byte count is incorrect.";

	if(csr_code == 12)		return "Feature is not available on this unit.";
	if(csr_code == 17)		return "Minimum off time is active.";
	if(csr_code == 19)		return "Recipe feature is active.";

	if(csr_code == 28)		return "Setpoint exceeds user limit.";
	if(csr_code == 30)		return "EEPROM read/write error.";

	if(csr_code == 41)		return "One or more warnings are active.";
	if(csr_code == 42)		return "DHCP is active.";

	if(csr_code == 50)		return "Frequency is out of range.";
	if(csr_code == 51)		return "Duty cycle is out of range.";
	if(csr_code == 52)		return "Minimum On or Off time is violated.";

	if(csr_code == 61)		return "Real time clock was busy.";
	if(csr_code == 63)		return "Flash mode is active.";

	if(csr_code == 99)		return "Command not accepted (there is no such command).";
	if(csr_code == 199)		return "This CSR indicates that PROFIBUS communication was reset.";

	// ...
	CString str_data;

	str_data.Format("Unknown CSR Code : %1d", csr_code);
	return str_data;
}
