#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"

#include "math.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Fnc__StrTo2Word(const CString& data,
				  const char section,
				  CString *p_str1,
				  CString *p_str2)
{
	CString word;
	char str_ch[2];
	char ch;

	int init_flag;
	int para;
	int limit;
	int i;

	// ...
	init_flag = 0;
	para = 0;
	str_ch[1] = 0;

	limit = data.GetLength();

	for(i=0; i<=limit; i++)
	{
		if(i<limit)		ch = data.GetAt(i);
		else			ch = section;

		if(ch == section)
		{
			if(word.GetLength() > 0)
			{
					 if(para == 0)	*p_str1 = word;
				else if(para == 1)	*p_str2 = word;

				word = "";
			}

			para++;
		}
		else
		{
			str_ch[0] = ch;
			word += str_ch;
		}
	}

	return 1;
}
int  CObj__AtmRobot_FUSION
::Fnc__StrTo7Word(const CString& data,
				  const char section,
				  CString *p_str1,
				  CString *p_str2,
				  CString *p_str3,
				  CString *p_str4,
				  CString *p_str5,
				  CString *p_str6,
				  CString *p_str7)
{
	CString word;
	char str_ch[2];
	char ch;

	int init_flag;
	int para;
	int limit;
	int i;

	// ...
	init_flag = 0;
	para = 0;
	str_ch[1] = '\0';

	limit = data.GetLength();

	for(i=0;i<=limit;i++)
	{
		if(i<limit)		ch = data.GetAt(i);
		else			ch = section;

		if(ch == section)
		{
			if(word.GetLength() > 0)
			{
					 if(para == 0)	*p_str1 = word;
				else if(para == 1)	*p_str2 = word;
				else if(para == 2)  *p_str3 = word;
				else if(para == 3)  *p_str4 = word;
				else if(para == 4)  *p_str5 = word;
				else if(para == 5)  *p_str6 = word;
				else if(para == 6)  *p_str7 = word;

				word = "";
			}

			para++;
		}
		else
		{
			str_ch[0] = ch;
			word += str_ch;
		}
	}

	return 1;
}

//.....
int  CObj__AtmRobot_FUSION::
Fnc__IndexStrTo1Word(const CString& data,
					 const char section,
					 int index,
					 CString *p_str1)
{
	//.....
	CString word;
	char str_ch[2];
	char ch;
	
	int init_flag;
	int para;
	int limit;
	int i;

	//.....
	init_flag = 0;
	para = 0;
	str_ch[1] = '\0';
	
	limit = data.GetLength();
	index--;

	for(i=index;i<=limit;i++)
	{
		if(i<limit)		ch = data.GetAt(i);
		else			ch = section;

		if(ch == section)
		{
			if(word.GetLength() > 0)
			{
				if(para == 0)		*p_str1 = word;

				word = "";
			}

			para++;
		}
		else
		{
			str_ch[0] = ch;
			word += str_ch;
		}
	}

	//
	return 1;
}
int  CObj__AtmRobot_FUSION::
Fnc__IndexStrTo4Word(const CString& data,
					 const char section,
					 int index,
					 CString *p_str1,
					 CString *p_str2,
					 CString *p_str3,
					 CString *p_str4)
{
	//.....
	CString word;
	char str_ch[2];
	char ch;

	int  init_flag;
	int  para;
	int  limit;
	int  i;

	//.....
	init_flag = 0;
	para = 0;
	str_ch[1] = 0;

	limit = data.GetLength();
	index--;

	for(i=index;i<=limit;i++)
	{
		if(i<limit)			ch = data.GetAt(i);
		else				ch = section;

		if(ch == section)
		{
			if(word.GetLength() > 0)
			{
				     if(para == 0)	*p_str1 = word;
				else if(para == 1)	*p_str2 = word;
				else if(para == 2)  *p_str3 = word;
				else if(para == 3)  *p_str4 = word;

				word = "";
			}

			para++;
		}
		else
		{
			str_ch[0] = ch;
			word += str_ch;
		}
	}

	//
	return 1;
}
int  CObj__AtmRobot_FUSION::
Fnc__IndexStrTo5Word(const CString& data,
					 const char section,
					 int index,
					 CString *p_str1,
					 CString *p_str2,
					 CString *p_str3,
					 CString *p_str4,
					 CString *p_str5)
{
	//.....
	CString word;
	char str_ch[2];
	char ch;

	int  init_flag;
	int  para;
	int  limit;
	int  i;

	//.....
	init_flag = 0;
	para = 0;
	str_ch[1] = 0;

	limit = data.GetLength();
	index--;

	for(i=index;i<=limit;i++)
	{
		if(i<limit)			ch = data.GetAt(i);
		else				ch = section;

		if(ch == section)
		{
			if(word.GetLength() > 0)
			{
					 if(para == 0)	*p_str1 = word;
				else if(para == 1)	*p_str2 = word;
				else if(para == 2)  *p_str3 = word;
				else if(para == 3)  *p_str4 = word;
				else if(para == 4)  *p_str5 = word;

				word = "";
			}

			para++;
		}
		else
		{
			str_ch[0] = ch;
			word += str_ch;
		}
	}

	//
	return 1;
}

//.....
int  CObj__AtmRobot_FUSION::
Fnc__HexToDec(const CString& str_dec)
{
	//.....
	CString string;
	char str_ch[2];
	char ch;

	int  value;
	int  limit;
	int  i;

	//.....
	string = str_dec;
	string.MakeUpper();

	value = 0;
	str_ch[1] = 0;

	limit = string.GetLength();

	for(i=0;i<limit;i++)
	{
		if(i > 0)	value *= 16;

		//.....
		ch = string.GetAt(i);
		str_ch[0] = ch;

		     if(((ch >= '0')&&(ch <= '9')))		value += atoi(str_ch);
		else if(ch == 'A')						value += 10;
		else if(ch == 'B')						value += 11;
		else if(ch == 'C')						value += 12;
		else if(ch == 'D')						value += 13;
		else if(ch == 'E')						value += 14;
		else if(ch == 'F')						value += 15;		
	}

	//
	return value;
}
int  CObj__AtmRobot_FUSION::
Fnc__DecToBin(int dec,
			  CString *p_str)
{
	//.....
	CString str_result;
	CString word;
	int value;
	int bit;

	//.....
	int flag = 1;

	while(flag > 0)
	{
		value = dec / 2;
		bit   = dec % 2;
		dec   = value;

		if(value >= 0)
		{
			word.Format("%1d",bit);
			str_result += word;
		}

		if(value == 0)
		{
			flag = 0;
		}
	}

	//.....
	char str_ch[2];
	int limit;
	int i;

	str_ch[1] = 0;
	word = "";

	limit = str_result.GetLength();

	for(i=limit-1;i>=0;i--)
	{
		str_ch[0] = str_result.GetAt(i); 
		word += str_ch;
	}
	
	*p_str = word;
	return 1;
}


// ...
#define _RUN_STATE__IDLE					1
#define _RUN_STATE__RUN						2

#define _CMD_STATE__READY					11
#define _CMD_STATE__ACK						12
#define _CMD_STATE__NAK						13
#define _CMD_STATE__ERR						14


int  CObj__AtmRobot_FUSION
::Proc__CMMD_RSP(const CString& var_name, 
				 const CString& s_cmmd,
				 const double to_sec,
				 const BOOL active_prt,
				 CStringArray& l_rsp,
				 CStringArray& l_err)
{
	CString str_data;
	CString err_msg;
	CString key_word;
	CString log_msg;
	CString log_bff;

	// ...
	{
		l_rsp.RemoveAll();
		l_err.RemoveAll();
	}

	// ...
	{
		mX_Net->CLEAR__BUFFER(&err_msg);

		if(err_msg.GetLength() > 0)
		{
			log_msg.Format("Var_Name(%s) - Clear__Buffer() .. \n", var_name);
			log_msg += " * Clear_Msg : ";
			log_msg += err_msg;
			log_msg += "\n";

			Fnc__DRV_LOG(log_msg);			
		}
	}

	// ...
	int msg_id = Get__Msg_ID();

	CString str_cmmd;
	str_cmmd.Format("%03d %s", msg_id,s_cmmd);

	log_msg.Format(" %s -> %s%s", var_name,str_cmmd,sEnd_OutStr);
	Fnc__DRV_LOG(log_msg);

	mX_Net->DATA__SEND(str_cmmd, 1, &err_msg);

	if(active_prt)
	{
		printf(" -> %s \n", str_cmmd);
	}

	// ...
	SCX__ASYNC_TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->START__COUNT_UP(99999.9);

	double ref__to_msec = to_sec;
	int r_cnt = 0;

	// ...
	int run_state = _RUN_STATE__RUN;
	int cmd_state = _CMD_STATE__READY;

	CString rsp_err = "";

	while(1)
	{
		int r_len = mX_Net->DATA__RECV_QUEUE(&str_data, 1, &err_msg);
		if(r_len < 0)
		{
			// Check : Timeout ...
			if(x_timer_ctrl->Get__CURRENT_TIME() > ref__to_msec)
			{
				// Error Msg ...
				{
					log_msg.Format("Error : %s <- Timeout(%.0f sec) \n", var_name,ref__to_msec);

					log_bff.Format("  * r_cnt [%1d] \n", r_cnt);
					log_msg += log_bff;

					Fnc__DRV_LOG(log_msg);
				}

				m_nCommState = OFFLINE;
				return -1;
			}
			continue;
		}

		r_cnt++;

		// ...
		{
			log_msg.Format(" %s <- %s%s\n", var_name,str_data,sEnd_InStr);
			
			log_bff.Format("  * r_cnt [%1d] \n", r_cnt);
			log_msg += log_bff;
			
			Fnc__DRV_LOG(log_msg);
		}

		if(active_prt)
		{
			printf(" * r_cnt : %1d \n", r_cnt);
			printf(" * r_len : %1d \n", r_len);
			printf(" * err_msg  : %s \n",   err_msg);
			printf(" * str_data : %s%s \n", str_data,sEnd_InStr);
		}

		// ...
		int check_done = -1;

		int k_limit = 10;
		int k;

		for(k=0; k<k_limit; k++)
		{
			     if(k == 0)		key_word = _ACK;
			else if(k == 1)		key_word = _NAK;
			else if(k == 2)		key_word = _ERR;
			else if(k == 3)		key_word = _RSP;
			else if(k == 4)		key_word = _EVN;
			else if(k == 5)		key_word = _DNE;
			else				break;

			// Check : Keyword ...
			int rsp_id;
			CStringArray l_para;

			if(Check__MSG_KEY_WORD(str_data, key_word, rsp_id,l_para) < 0)
			{
				continue;
			}

			if(active_prt)
			{
				printf("Check : \"%s\" ... \n", key_word);
				printf(" * key_word : [%s] \n", key_word);

				printf(" * rsp_id : [%1d] \n", rsp_id);
			}

			if(msg_id != rsp_id)
			{
				continue;
			}

			// ...
			int active_rsp = -1;
			int active_err = -1;

			if(key_word.CompareNoCase(_ACK) == 0)
			{
				cmd_state = _CMD_STATE__ACK;
			}
			else if(key_word.CompareNoCase(_RSP) == 0)
			{
				active_rsp = 1;
				l_rsp.RemoveAll();
			}
			else if(key_word.CompareNoCase(_NAK) == 0)
			{
				cmd_state = _CMD_STATE__NAK;
				rsp_err = str_data;
			}
			else if(key_word.CompareNoCase(_ERR) == 0)
			{
				cmd_state = _CMD_STATE__ERR;
				rsp_err = str_data;

				active_err = 1;
				l_err.RemoveAll();
			}

			// ...
			CString str_para;

			int i_limit = l_para.GetSize();
			int i;

			for(i=0; i<i_limit; i++)
			{
				str_para = l_para[i];

				if(active_prt)
				{
					printf(" ** %1d) [%s] \n", i+1,str_para);
				}

				if(active_rsp > 0)
				{
					l_rsp.Add(str_para);
				}
				else if(active_err > 0)
				{
					l_err.Add(str_para);
				}
			}

			if(key_word.CompareNoCase(_DNE) == 0)
			{
				check_done = 1;
				break;
			}
		}

		if(check_done > 0)
		{
			run_state = _RUN_STATE__IDLE;
			break;
		}
	}

	if(l_err.GetSize() > 0)
	{
		int err_id = atoi(l_err[0]);
		iDRV__ERROR_ID = err_id;

		// ...
		CString err_code;
		CString err_msg;

		err_code.Format("%1d", err_id);
		err_msg = Get__Fusion_Error_Msg_Of_Error_Code(err_id);

		mMNG__ERR_CODE.Load__Error_Code(err_code,err_msg);
	}

	// ...
	{
		int i_limit;
		int i;

		// _RSP Info ...
		{
			i_limit = l_rsp.GetSize();

			log_msg.Format("_RSP Info (%1d) ... \n", i_limit);
			if(active_prt)		printf(log_msg);

			for(i=0; i<i_limit; i++)
			{
				log_bff.Format(" * %1d) [%s] \n", i+1,l_rsp[i]);
				if(active_prt)		printf(log_bff);

				log_msg += log_bff;
			}

			Fnc__DRV_LOG(log_msg);
		}

		// _ERR or _NAK Info ...
		{
			i_limit = l_err.GetSize();

			log_msg.Format("%s Info (%1d) ... \n", key_word,i_limit);
			if(active_prt)		printf(log_msg);

			for(i=0; i<i_limit; i++)
			{
				log_bff.Format(" * %1d) [%s] \n", i+1,l_err[i]);
				if(active_prt)		printf(log_bff);

				log_msg += log_bff;
			}

			Fnc__DRV_LOG(log_msg);
		}
	}

	m_nCommState = ONLINE;

	if(cmd_state == _CMD_STATE__ACK)
	{
		return 1;
	}

	// Error Report ...
	{
		/*
		str_cmmd
		rsp_err		
		*/
	}
	return -1;
}

int  CObj__AtmRobot_FUSION
::Check__MSG_KEY_WORD(const CString& str_data, 
					  const CString& key_word, 
					  int& msg_id,
					  CStringArray& l_para)
{
	int s_index = str_data.Find(key_word);
	if(s_index < 0)			return -1;

	msg_id = atoi(str_data);

	s_index += key_word.GetLength();
	l_para.RemoveAll();

	// ...
	CString word = "";
	char ch;

	int i_limit = str_data.GetLength();
	int i;

	for(i=s_index; i<i_limit; i++)
	{
		ch = str_data.GetAt(i);

		if(ch == ' ')
		{
			if(word.GetLength() > 0)
			{
				l_para.Add(word);
			}

			word = "";
		}
		else
		{
			word += ch;
		}
	}

	if(word.GetLength() > 0)
	{
		l_para.Add(word);
	}
	return 1;
}
CString CObj__AtmRobot_FUSION
::Get__STRING_OF_LIST(const CStringArray& l_str)
{
	CString str_line = "";

	int i_limit = l_str.GetSize();
	int i;

	for(i=0; i<i_limit; i++)
	{
		if(i > 0)		str_line += " ";

		str_line += l_str[i];
	}
	return str_line;
}
