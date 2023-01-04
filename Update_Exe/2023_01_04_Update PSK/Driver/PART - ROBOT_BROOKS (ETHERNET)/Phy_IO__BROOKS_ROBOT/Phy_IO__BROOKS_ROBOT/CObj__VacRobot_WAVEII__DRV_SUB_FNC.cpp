#include "StdAfx.h"
#include "CObj__VacRobot_WAVEII.h"
#include "CObj__VacRobot_WAVEII__DEF.h"

#include "math.h"
#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_WAVEII
::Drv__CMD_COM_INIT(const CString& var_name)
{
	// This command is used to set the serial communications and command execution modes.
	return 1;

	/*
	int flag;

	CString str__send_data;
	CString str__for_error;

	// Init 1 : SET COMM M/B PKT FLOW SEQ LF OFF 
	{
		str__send_data.Format("SET COMM M/B PKT FLOW SEQ LF OFF");
		str__for_error.Format("SET COMM M/B PKT FLOW SEQ LF OFF%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	// Init 2 : SET IO ECHO N 
	{
		str__send_data.Format("SET IO ECHO N");
		str__for_error.Format("SET IO ECHO N%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	// Init 3 : STORE IO ECHO 
	{
		str__send_data.Format("STORE IO ECHO");		
		str__for_error.Format("STORE IO ECHO%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	// Init 4 : STORE COMM ALL 
	{
		str__send_data.Format("STORE COMM ALL");
		str__for_error.Format("STORE COMM ALL%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	// Init 5 : SET LOAD MODE TRI 
	{
		str__send_data.Format("SET LOAD MODE TRI");
		str__for_error.Format("SET LOAD MODE TRI%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	// Init 6 : STORE LOAD MODE 
	{
		str__send_data.Format("STORE LOAD MODE");
		str__for_error.Format("STORE LOAD MODE%s", sEnd_OutStr);

		flag = Drv__SEND_MESSAGE_RETURN(var_name, str__send_data, str__for_error);
		if(flag < 0) return -1;
	}

	return 1;
	*/
}

int CObj__VacRobot_WAVEII
::Drv__SEND_MESSAGE_RETURN(const CString& var_name, 
						   CString str__send_data, 
						   const CString& str__for_error)
{
	CString str__log;
	int index = 0;

	char check_char[10];

	// ...
	{
		str__log.Format("[%s] SEND => [%s]\n", var_name,str__for_error);
		Fnc__DRV_LOG(str__log);
	}

	// ...
	CString msg;
	mX_Net->CLEAR__BUFFER(&msg);

	// ...
	CString err_msg;
	int nRet = mX_Net->DATA__RECV(&str__send_data, m_Out_Time, &err_msg);
	
	str__log.Format("Ret:%d", nRet);
	Fnc__DRV_LOG(str__log);

	if(nRet >= 0)
	{
		m_nCommState = ONLINE;

		index = str__send_data.GetLength();
		if(index >= 2)
		{
			if(str__send_data.GetAt(1) == 'E')
			{
				for(int i=5; i<index; i++)
				{
					check_char[i-5] = str__send_data.GetAt(i);
				}
				
				m_sErrorID.Format("%s",&check_char);
				sCH__ERRID->Set__DATA(m_sErrorID);

				// ...
				{
					str__log.Format("[%s][%s] [ERROR] [ID:%s] => Problem of Command[%s]\n",
									var_name,
									str__for_error,
									m_sErrorID,
									str__send_data);

					Fnc__DRV_LOG(str__log);
				}

				return -1;
			}
			else
			{
				m_sErrorID.Format("0");
				sCH__ERRID->Set__DATA(m_sErrorID);

				// ...
				{
					str__log.Format("[%s] RECV <= [%s]\n", var_name,str__send_data);

					Fnc__DRV_LOG(str__log);
				}					
			}
		}

		return 1;
	}

	m_nCommState = OFFLINE;

	// ...
	{
		str__log.Format("[%s] [Error] => No response Send:(%s) Receive:(%s)\n",
						var_name, 
						str__for_error,
						str__send_data);

		Fnc__DRV_LOG(str__log);
	}

	return -1;
}

// ...
int  CObj__VacRobot_WAVEII
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
	str_cmmd.Format("%02d %s", msg_id,s_cmmd);

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
			printf(" * err_msg  : [%s] \n", err_msg);
			printf(" * str_data : [%s] \n", str_data);
		}

		// ...
		int check_done = -1;

		int k_limit = 4;
		int k;

		for(k=0; k<k_limit; k++)
		{
				 if(k == 0)		key_word = _ACK;
			else if(k == 1)		key_word = _ERR;
			else if(k == 2)		key_word = _RSP;
			else if(k == 3)		key_word = _DONE;
			else				break;

			// Check : Keyword ...
			CStringArray l_para;

			if(Check__MSG_KEY_WORD(str_data, key_word,l_para) > 0)
			{	
				if(active_prt)
				{
					printf("Check : \"%s\" ... \n", key_word);
					printf(" * key_word : [%s] \n", key_word);
				}

				// ...
				int active_rsp = -1;
				int active_err = -1;

				if(key_word.CompareNoCase(_RSP) == 0)
				{
					active_rsp = 1;
				}
				else if(key_word.CompareNoCase(_ERR) == 0)
				{
					active_err = 1;
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

					if(i == 0)
					{
						int cur_id = atoi(str_para);

						if(msg_id != cur_id)
						{
							active_rsp = -1;
							active_err = -1;
						}
					}
					else
					{
						if(active_rsp > 0)
						{
							l_rsp.Add(str_para);
						}
						else if(active_err > 0)
						{
							l_err.Add(str_para);
						}
					}
				}

				if(key_word.CompareNoCase(_DONE) == 0)
				{
					check_done = 1;
					break;
				}
			}
		}

		if(check_done > 0)
		{
			break;
		}
	}

	if(l_err.GetSize() > 0)
	{
		int err_id = atoi(l_err[0]);

		// ...
		CString err_code;
		CString err_msg;

		err_code.Format("%1d", err_id);
		err_msg = Get__Error_Msg_Of_Error_Code(err_id);

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

		// _ERR Info ...
		{
			i_limit = l_err.GetSize();

			log_msg.Format("_ERR Info (%1d) ... \n", i_limit);
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
	return 1;
}

int  CObj__VacRobot_WAVEII
::Check__MSG_KEY_WORD(const CString& str_data, 
					  const CString& key_word, 
					  CStringArray& l_para)
{
	int s_index = str_data.Find(key_word);
	if(s_index < 0)			return -1;

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
CString CObj__VacRobot_WAVEII
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
