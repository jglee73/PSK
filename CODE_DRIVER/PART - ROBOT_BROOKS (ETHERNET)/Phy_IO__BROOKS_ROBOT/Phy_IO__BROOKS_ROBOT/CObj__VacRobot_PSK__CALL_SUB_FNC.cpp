#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "math.h"
#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_PSK
::Is__LOCAL(CII_OBJECT__ALARM* p_alarm)
{
	return 1;
}

int  CObj__VacRobot_PSK
::Is__OFFLINE(CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(iActive__SIM_MODE > 0)
	{
		diCH__COMM_STS->Set__DATA(STR__ONLINE);
	}

	if(diCH__COMM_STS->Check__DATA(STR__OFFLINE) > 0)
	{
		int alarm_id = ALID__OFFLINE_ALARM__ACT;
		CString r_act;

		p_alarm->Popup__ALARM(alarm_id,r_act);

		if(r_act.CompareNoCase("RETRY") == 0)		goto LOOP_RETRY;
		else										return -1;
	}

	return 1;
}

CString  CObj__VacRobot_PSK
::Get__CFG_STN_NUM(const CString& stn_name, const CString& slot_id)
{
	CString cfg_stn_num = "?";

	// LLx ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			int slot_index = atoi(slot_id) - 1;

			if((slot_index >= 0) && (slot_index < CFG_LBx__SLOT_SIZE))
			{
				aCH__CFG_LLx_STN_NUM_X[ll_index][slot_index]->Get__DATA(cfg_stn_num);
			}
		}
	}

	// PMx ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			aCH__CFG_PMx_STN_NUM[pm_index]->Get__DATA(cfg_stn_num);
		}
	}

	return cfg_stn_num;
}

CString  CObj__VacRobot_PSK
::Get__CFG_STN_CPTR_NUM(const CString& stn_name, const CString& str_slot_id)
{
	CString cfg_val;

	// LLx ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			int slot_index = atoi(str_slot_id);

			if((slot_index >= 0) && (slot_index < CFG_LBx__SLOT_SIZE))
			{
				aCH__CFG_CPTR_SNS__LLx_NUM_X[ll_index][slot_index]->Get__DATA(cfg_val);
			}
		}
	}

	// PMX ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			aCH__CFG_CPTR_SNS__PMx_NUM[pm_index]->Get__DATA(cfg_val);
		}
	}

	return cfg_val;
}

int  CObj__VacRobot_PSK
::Is__ERROR_EXIST(CII_OBJECT__ALARM* p_alarm)
{
	int err_code;

	// Read ErrorID
	{
		CString ch_data = sCH__ERRID->Get__STRING();
		err_code = atoi(ch_data);

		CString log_msg;
		log_msg.Format("APP_GET_ERR_ID : [%d]", err_code);

		Fnc__APP_LOG(log_msg);
	}

	if(err_code == 0)
	{
		return OBJ_AVAILABLE;
	}

	// ...
	{
		int	alarm_id = ALID__CONTROLLER_ERROR_CODE;
		CString r_act;

		CString err_msg = Get__Error_Msg_Of_Error_Code(err_code);

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, err_msg, r_act);

		if(r_act.CompareNoCase("RETRY") == 0)		return OBJ_RETRY;
	}
	return OBJ_ABORT;
}

int  CObj__VacRobot_PSK
::_Update__WFR_CEN_DATA(CII_OBJECT__VARIABLE* p_variable)
{
	CString str_cmd = "WAF_CEN.DATA";
	
	int r_flag = doCH__COMMAND->Set__DATA(str_cmd);

	// ...
	CString log_msg;
	CString log_bff;

	log_msg = "\n";
	log_bff.Format(" * WFR_CEN_DATA : Report ... \n");
	log_msg += log_bff;

	log_bff.Format(" * %s <- %s  :  r_flag(%1d) \n",
					doCH__COMMAND->Get__CHANNEL_NAME(),
					str_cmd,
					r_flag);
	log_msg += log_bff;

	log_bff.Format(" * %s <- %s \n",
					sCH__DA_RESULT_FULL_VAL->Get__CHANNEL_NAME(),
					sCH__DA_RESULT_FULL_VAL->Get__STRING());
	log_msg += log_bff;

	// ...
	{
		log_msg += " * Result Report ... \n";

		log_msg += " * R & T Offset \n";
		log_bff.Format(" ** %s <- [%s] (mm) \n", 
						sCH__DA_RESULT_R_OFFSET_MM->Get__CHANNEL_NAME(),
						sCH__DA_RESULT_R_OFFSET_MM->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" ** %s <- [%s] (deg) \n", 
						sCH__DA_RESULT_T_OFFSET_DEG->Get__CHANNEL_NAME(),
						sCH__DA_RESULT_T_OFFSET_DEG->Get__STRING());
		log_msg += log_bff;

		log_msg += " * X & Y Offset \n";
		log_bff.Format(" ** %s <- [%s] (mm) \n", 
						sCH__DA_RESULT_X_OFFSET_MM->Get__CHANNEL_NAME(),
						sCH__DA_RESULT_X_OFFSET_MM->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" ** %s <- [%s] (mm) \n", 
						sCH__DA_RESULT_Y_OFFSET_MM->Get__CHANNEL_NAME(),
						sCH__DA_RESULT_Y_OFFSET_MM->Get__STRING());
		log_msg += log_bff;
	}

	Fnc__APP_LOG(log_msg);
	return 1;
}
