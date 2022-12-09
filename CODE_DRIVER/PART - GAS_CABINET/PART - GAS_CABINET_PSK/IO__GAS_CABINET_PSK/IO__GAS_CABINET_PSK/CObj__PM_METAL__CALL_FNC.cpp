#include "StdAfx.h"
#include "CObj__PM_METAL.h"
#include "CObj__PM_METAL__ALID.h"
#include "CObj__PM_METAL__DEF.h"


// ...
int  CObj__PM_METAL
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}


// ...
#define POLYNORMIAL					0xA001

unsigned int CObj__PM_METAL
::_Make__READ_PACKET(unsigned char* s_data,
				     const unsigned char addr_id,
				     const unsigned char cmmd_id,
				     const unsigned int  start_addr,
					 const unsigned char read_num)
{
	int i = 0;

	s_data[i++] = 0x0ff & addr_id;				// 0
	s_data[i++] = 0x0ff & cmmd_id;				// 1
	s_data[i++] = 0x0ff & (start_addr >> 8);	// 2
	s_data[i++] = 0x0ff & (start_addr >> 0);	// 3
	s_data[i++] = 0x00;							// 4
	s_data[i++] = 0x0ff & read_num;				// 5	

	unsigned short crc = _Get__CRC16(s_data, i);
	/*
	s_data[i++] = 0x0ff & (crc >> 8);			// 6
	s_data[i++] = 0x0ff & (crc >> 0);			// 7		
	*/
	s_data[i++] = 0x0ff & (crc >> 0);			// 6
	s_data[i++] = 0x0ff & (crc >> 8);			// 7		

	return i;
}
unsigned int CObj__PM_METAL
::_Recv__READ_PACKET(unsigned char* s_data,
					 const int s_len)
{
	CString r_msg;
	mX_Serial->CLEAR__BUFFER(&r_msg);

	// ...
	int s_cmmd = 0x0ff & s_data[1];		// 1
	int s_reg  = 0x0ff & s_data[5];		// 5

	if(mX_Serial->CHAR__SEND(s_data, s_len) < 0)
	{
		return -1;
	}

	// ...
	int r_len;

	if(s_cmmd == _CMMD_ID__READ)
	{
		r_len = 5 + (s_reg * 2);
	}
	else if(s_cmmd == _CMMD_ID__WRITE)
	{
		r_len = 4 + 4;
	}

	s_data[0] = 0;
	if(mX_Serial->CHAR__RECV(s_data, &r_len, 500) < 0)
	{
		return -2;
	}

	if(s_cmmd == _CMMD_ID__READ)
	{
		return r_len;
	}
	if(s_cmmd == _CMMD_ID__WRITE)
	{
		return r_len;
	}

	return -11;
}

unsigned int CObj__PM_METAL
::_Make__WRITE_PACKET(unsigned char* s_data,
					  const unsigned char addr_id,
					  const unsigned char cmmd_id,
					  const unsigned int  start_addr,
					  const unsigned char write_num,
					  const unsigned short set_data,
					  const float set_value)
{
	int i = 0;

	s_data[i++] = 0x0ff & addr_id;					// 0
	s_data[i++] = 0x0ff & cmmd_id;					// 1
	s_data[i++] = 0x0ff & (start_addr >> 8);		// 2
	s_data[i++] = 0x0ff & (start_addr >> 0);		// 3
	s_data[i++] = 0x00;								// 4
	s_data[i++] = 0x0ff & write_num;				// 5	

	s_data[i++] = 0x0ff & (write_num * 2);			// 6

	if(write_num == 1)
	{
		JG_UI2 set_ui;
		set_ui.uiValue = set_data;

		s_data[i++] = 0x0ff & set_ui.uData[1];		// 7
		s_data[i++] = 0x0ff & set_ui.uData[0];		// 8

		unsigned short crc = _Get__CRC16(s_data, i);

		s_data[i++] = 0x0ff & (crc >> 0);			// 9
		s_data[i++] = 0x0ff & (crc >> 8);			// 10		
	}
	else if(write_num == 2)
	{
		JG_F4 set_fx;
		set_fx.fValue = set_value;

		s_data[i++] = 0x0ff & set_fx.uData[1];		// 7
		s_data[i++] = 0x0ff & set_fx.uData[0];		// 8
		s_data[i++] = 0x0ff & set_fx.uData[3];		// 9
		s_data[i++] = 0x0ff & set_fx.uData[2];		// 10
	
		unsigned short crc = _Get__CRC16(s_data, i);

		s_data[i++] = 0x0ff & (crc >> 0);			// 11
		s_data[i++] = 0x0ff & (crc >> 8);			// 12		
	}

	return i;
}

unsigned short  CObj__PM_METAL
::_Get__CRC16(unsigned char* s_data, const int data_len)
{
	unsigned short crc, flag;
	int count = data_len;

	crc = 0xffff;

	while(count--)
	{
		crc ^= *s_data++;
	
		for (int i=0; i<8; i++)
		{
			flag = crc & 0x0001;
			crc >>= 1;
			if(flag) crc ^= POLYNORMIAL;
		}
	}
	return crc;
}