#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"

#include "math.h"
#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_PSK
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
	CStringArray l_para;
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
	//str_cmmd.Format("%02d %s", msg_id,s_cmmd); // KMS:NOT Use msg_id;
	str_cmmd.Format("%s",s_cmmd); // KMS:Only Send Message


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
			l_para.Add(str_data);
			if(str_data.CompareNoCase(_RDY) == 0)
			{
				break;
			}
		}
	}
		
	// ...	
	CString str_para;
	CString str__err_id = _ERR;

	int i_limit = l_para.GetSize();

	for(int i=0; i<i_limit; i++)
	{
		str_para = l_para[i];
		
		//..
		int active_rsp = -1;
		int active_err = -1;

		if(str_para.Find(str__err_id) >= 0)
		{
			active_err = 1;
		}
		else
		{
			active_rsp = 1;
		}

		if(active_rsp > 0)
		{
			l_rsp.Add(str_para);
		}
		else if(active_err > 0)
		{
			CString err_code = str_para;

			int err_index = err_code.Find(str__err_id);
			int del_size = err_index + str__err_id.GetLength();

			if(err_index >= 0)
			{
				if(del_size < err_code.GetLength())
				{
					err_code.Delete(0, del_size);
					err_code.Trim();
				}

				l_err.Add(err_code);
			}
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

int  CObj__VacRobot_PSK
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
CString CObj__VacRobot_PSK
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


int CObj__VacRobot_PSK
::RB_LOG_EXTRACT(const CString& var_name,  const CString& s_cmmd,
				 const double to_sec, const BOOL active_prt, CStringArray& l_rsp, CStringArray& l_err)
{
}