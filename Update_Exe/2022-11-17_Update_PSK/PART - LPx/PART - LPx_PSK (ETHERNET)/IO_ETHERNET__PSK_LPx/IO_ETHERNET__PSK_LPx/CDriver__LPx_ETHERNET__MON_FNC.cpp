#include "StdAfx.h"
#include "CDriver__LPx_ETHERNET.h"
#include "CDriver__LPx_ETHERNET__DEF.h"
#include "CDriver__LPx_ETHERNET__ALID.h"

#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
void CDriver__LPx_ETHERNET
::Mon__DRV_STATE(CII_OBJECT__VARIABLE* p_variable,
				 CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		bActive__COMM_ONLINE = true;

		//
		sCH__INR__ERROR_ID_DEC->Set__DATA("0");
		sCH__INR__ERROR_ID_HEXA->Set__DATA("Ox0");

		sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");
	}
	else
	{
		bActive__COMM_ONLINE = false;
	}


	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.1);


		if(bActive__COMM_ONLINE)
		{
			sCH__MON_COMMUNICATION_STATE->Set__DATA(STR__ONLINE);
		}
		else
		{
			sCH__MON_COMMUNICATION_STATE->Set__DATA(STR__OFFLINE);

			// ...
			{
				CString r_act;
				int alarm_id = ALID__OFFLINE_ALARM;

				p_alarm->Check__ALARM(alarm_id,r_act);
				p_alarm->Post__ALARM(alarm_id);
			}
		}

		// ...
	}	
}

void CDriver__LPx_ETHERNET
::Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm)
{
	bool active__cfg_change = true;
	int i;

	// Config.Save ...
	{
		active__cfg_change = false;

		siCH__PIO_TP_INFO->Get__STRING();
		_Save__Config_Change();
	}


	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.1);


		// LP_STATE ...
		for(i=0; i<CFG_LPx__SIZE; i++)
		{
			siCH__LP_STATE_X[i]->Get__STRING();
		}

		// CONFIG.SAVE ...
		if(dEXT_CH__CONFIG_SAVE->Check__DATA(STR__UnChange) > 0)
		{
			if(active__cfg_change)
			{
				active__cfg_change = false;

				_Save__Config_Change();			
			}
		}
		else
		{
			active__cfg_change = true;
		}

		// ...
	}	
}

void CDriver__LPx_ETHERNET
::Mon__RECV_PROC(CII_OBJECT__VARIABLE* p_variable,
				 CII_OBJECT__ALARM* p_alarm)
{

	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.001);

		Proc__RECV_RSP(p_alarm, TRUE);
	}
}


int  CDriver__LPx_ETHERNET
::Proc__RECV_RSP(CII_OBJECT__ALARM* p_alarm, const BOOL active_prt)
{
	CStringArray l_rsp;
	CStringArray l_err;

	CString str_data;
	CString err_msg;
	CString key_word;
	CString fnc_name;
	CString log_msg;
	CString log_bff;

	int err_count = 0;


	while(1)
	{
		int r_len = mX_Net->DATA__RECV_QUEUE(&str_data, 1, &err_msg);
		if(r_len < 0)
		{
			Sleep(1);

			if(bActive__COMM_ONLINE)
			{
				bActive__COMM_ONLINE = true;
			}
			else
			{
				err_count++;
				if(err_count > 2)		bActive__COMM_ONLINE = false;
			}
			continue;
		}

		err_count = 0;
		bActive__COMM_ONLINE = true;

		// ...
		{
			log_msg.Format(" * Recv <- %s%s\n", str_data,sEnd_InStr);

			Fnc__DRV_LOG(log_msg);
		}

		// ...
		int k_limit = 40;
		int k;

		for(k=0; k<k_limit; k++)
		{
			if(k == 0)
			{
				key_word = _RSP_GET__STATE;
				fnc_name = _DRV_GET__STATE;
			}
		    else if(k == 1)
			{
				key_word = _RSP_GET__LP_MAP;
				fnc_name = _DRV_GET__LP_MAP;
			}
			else if(k == 2)
			{
				key_word = _RSP_GET__ALM_TXT;
				fnc_name = _DRV_GET__ALM_TXT;
			}
			else if(k == 3)
			{
				key_word = _RSP_GET__ALM_MSG;
				fnc_name = _DRV_GET__ALM_MSG;
			}
			else if(k == 4)
			{
				key_word = _RSP_GET__N2_STS;
				fnc_name = _DRV_GET__N2_STS;
			}
			else if(k == 5)
			{
				key_word = _RSP_GET__RFID_READ;
				fnc_name = _DRV_GET__RFID_READ;
			}
			else if(k == 6)
			{
				key_word = _RSP_GET__TIME_READ;
				fnc_name = _DRV_GET__TIME_READ;
			}

			else if(k == 21)
			{
				key_word = _RSP_SET__INIT;
				fnc_name = _DRV_SET__INIT;
			}
			else if(k == 22)
			{
				key_word = _RSP_SET__LOAD;
				fnc_name = _DRV_SET__LOAD;
			}
			else if(k == 23)
			{
				key_word = _RSP_SET__UNLOAD;
				fnc_name = _DRV_SET__UNLOAD;
			}
			else if(k == 24)
			{
				key_word = _RSP_SET__OPEN;
				fnc_name = _DRV_SET__OPEN;
			}
			else if(k == 25)
			{
				key_word = _RSP_SET__CLOSE;
				fnc_name = _DRV_SET__CLOSE;
			}
			else if(k == 26)
			{
				key_word = _RSP_SET__CLAMP;
				fnc_name = _DRV_SET__CLAMP;
			}
			else if(k == 27)
			{
				key_word = _RSP_SET__UCLAMP;
				fnc_name = _DRV_SET__UCLAMP;
			}
			else if(k == 28)
			{
				key_word = _RSP_SET__MODE;
				fnc_name = _DRV_SET__MODE;
			}
			else if(k == 29)
			{
				key_word = _RSP_SET__SIGNAL_LAMP;
				fnc_name = _DRV_SET__SIGNAL_LAMP;
			}
			else if(k == 30)
			{
				key_word = _RSP_SET__RESET;
				fnc_name = _DRV_SET__RESET;
			}
			else if(k == 31)
			{
				key_word = _RSP_SET__N2_RUN;
				fnc_name = _DRV_SET__N2_RUN;
			}
			else if(k == 32)
			{
				key_word = _RSP_SET__AVG_TIMEOUT;
				fnc_name = _DRV_SET__AVG_TIMEOUT;
			}
			else if(k == 33)
			{
				key_word = _RSP_SET__RFID_WRITE;
				fnc_name = _RSP_SET__RFID_WRITE;
			}
			else
			{
				continue;
			}

			// Check : Keyword ...
			CStringArray l_para;

			if(Check__MSG_KEY_WORD(str_data, key_word, l_para) < 0)
			{
				continue;
			}

			// ...
			CString str_para;

			CString para_id;
			CString para_rsp;
			CString para_data;

			int i_limit = l_para.GetSize();
			int i;

			for(i=0; i<i_limit; i++)
			{
				str_para = l_para[i];

				if(i == 0)
				{
					int str_len = str_para.GetLength();
					int str_i;

					for(str_i=0; str_i<str_len; str_i++)
					{
							 if(str_i == 0)		para_id  = str_para[0];
						else if(str_i == 1)		para_rsp = str_para[1];
					}
				}
				else if(i == 1)
				{
					para_data = str_para;
				}
			}

			// ...
			{
				log_msg = " * Result Report ... \n";

				log_bff.Format("  * para_id   <- %s \n", para_id);
				log_msg += log_bff;
				log_bff.Format("  * para_rsp  <- %s \n", para_rsp);
				log_msg += log_bff;
				log_bff.Format("  * para_data <- %s \n", para_data);
				log_msg += log_bff;

				if(para_rsp.CompareNoCase("2") == 0)
				{
					CString cancel_code = Get__CANCEL_CODE_OF_NAK(para_data);

					log_bff.Format("  ** Cancel_Code <- %s \n", cancel_code);
					log_msg += log_bff;

					sCH__DRV_CANCEL_CODE->Set__DATA(cancel_code);
				}
				log_msg += "\n";

				Fnc__DRV_LOG(log_msg);
			}

			if(mDrv_Msg.Check__MSG_DB(fnc_name, para_id))
			{
				int r_flag = mDrv_Msg.Set__MSG_INFO_OF_RSP(fnc_name, para_id, para_rsp, para_data);

				log_msg.Format("mDrv_Msg.Set__MSG_INFO_OF_RSP() ... r_flag (%1d) \n", r_flag);
				Fnc__DRV_LOG(log_msg);
			}
			else
			{
				log_msg.Format("mDrv_Msg.Check__MSG_DB(%s, %s) ... Error !!!! \n", fnc_name,para_id);
				Fnc__DRV_LOG(log_msg);

				if(para_rsp == "1")
				{
					if(fnc_name.CompareNoCase(_DRV_GET__STATE) == 0)
					{
						int lp_id = atoi(para_id);
						_Update__LPx_STATE(lp_id, para_data);
					}
				}

				mDrv_Msg.Delete__MSG_INFO(fnc_name, para_id);
			}
			break;
		}
	}

	return -1;
}

// ..
int CDriver__LPx_ETHERNET::_Save__Config_Change()
{
	CString log_msg;
	CString log_bff;

	log_msg = "_Save__Config_Change() ... \n";

	// ...
	CString ch_data;
	int i;

	// PIO_CFG.TPx ...
	{
		log_msg += "PIO_CFG.TPx \n";

		for(i=0; i<CFG_PIO__TP_SIZE; i++)
		{
			aCH__PIO_CFG__TP_X[i]->Get__DATA(ch_data);
			if(sCH__PIO_INFO__TP_X[i]->Check__DATA(ch_data) > 0)			continue;

			if(iActive__SIM_MODE > 0)
			{
				sCH__PIO_INFO__TP_X[i]->Set__DATA(ch_data);
			}

			log_bff.Format(" * %s <- %s \n",
							aoCH__PIO_TP_X[i]->Get__CHANNEL_NAME(),
							ch_data);
			log_msg += log_bff;

			int r_flag = aoCH__PIO_TP_X[i]->Set__DATA(ch_data);
			if(r_flag < 0)		return -1;
		}

		if(iActive__SIM_MODE > 0)
		{
			for(i=0; i<CFG_PIO__TP_SIZE; i++)
			{
				aCH__PIO_CFG__TP_X[i]->Get__DATA(ch_data);
				sCH__PIO_INFO__TP_X[i]->Set__DATA(ch_data);
			}
		}
	}

	xAPP_LOG_CTRL->WRITE__LOG(log_msg);
	return 1;
}
