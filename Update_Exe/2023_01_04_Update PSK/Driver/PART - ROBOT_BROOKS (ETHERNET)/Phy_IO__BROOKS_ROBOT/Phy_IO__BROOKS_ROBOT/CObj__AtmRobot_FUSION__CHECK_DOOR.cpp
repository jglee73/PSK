#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"

#include "Macro_Function.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Interlock__CHECK_DOOR(CII_OBJECT__ALARM* p_alarm,
					    const CString& stn_name,
					    const CString& act_name)
{
LOOP_RETRY:

	if((stn_name.CompareNoCase(STR__LBA) == 0)
	|| (stn_name.CompareNoCase(STR__LBB) == 0))
	{
		CII__VAR_DIGITAL_CTRL *p_lb_door;
		int alarm_id;

		if(stn_name.CompareNoCase(STR__LBA) == 0)
		{
			alarm_id = ALID__LBA__NOT_DOOR_OPEN;
			p_lb_door = dEXT_CH__LBA_DOOR_VALVE_STATUS.Get__PTR();
		}
		else if(stn_name.CompareNoCase(STR__LBB) == 0)
		{
			alarm_id = ALID__LBB__NOT_DOOR_OPEN;
			p_lb_door = dEXT_CH__LBB_DOOR_VALVE_STATUS.Get__PTR();
		}

		if(p_lb_door->Check__DATA(STR__OPEN) < 0)
		{
			CString err_msg;
			CString r_act;

			err_msg.Format("Robot can not %s.\n",act_name);

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				goto LOOP_RETRY;
			}
			return -1;
		}

		return 1;
	}

	// ...
	int lp_index = Macro__CHECK_LPx_INDEX(stn_name);

	if((lp_index >= 0) && (lp_index <  CFG_LPx__SIZE))
	{
		if(dEXT_CH__LPx_DOOR_STATUS[lp_index]->Check__DATA(STR__OPEN) < 0)
		{
			CString ch_data;
			aCH__CFG_LP__PADDLE_CHECK_TIME->Get__DATA(ch_data);

			int nRet = dEXT_CH__LPx_DOOR_STATUS[lp_index]->When__DATA(STR__OPEN, atof(ch_data));

			if(nRet == 0)
			{
				return OBJ_ABORT;
			}
			else if(nRet < 0)
			{
				int alarm_id = ALID__LP1__NOT_DOOR_OPEN + lp_index;

				CString err_msg;
				CString r_act;

				err_msg.Format("Robot can not %s.\n",act_name);

				p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

				if(r_act.CompareNoCase(ACT__RETRY) == 0)
				{
					goto LOOP_RETRY;
				}
				return -1;			
			}
		}

		if(dEXT_CH__LPx_FOUP_EXIST_FLAG[lp_index]->Check__DATA(STR__EXIST) < 0)
		{
			int alarm_id = ALID__LP1__FOUP_NOT_EXIST + lp_index;
			
			CString err_msg;
			CString r_act;

			err_msg.Format("Robot can not %s.\n",act_name);

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				goto LOOP_RETRY;
			}
			return -1;			
		}

		if(dEXT_CH__LPx_FOUP_CLAMP_STATUS[lp_index]->Check__DATA(STR__CLAMP) < 0)
		{
			int alarm_id = ALID__LP1__FOUP_NOT_CLAMP + lp_index;
			
			CString err_msg;
			CString r_act;

			err_msg.Format("Robot can not %s.\n",act_name);

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				goto LOOP_RETRY;
			}
			return -1;			
		}

		if(dEXT_CH__LPx_FOUP_POS_STATUS[lp_index]->Check__DATA(STR__LOAD) < 0)
		{
			int alarm_id = ALID__LP1__FOUP_NOT_LOAD + lp_index;

			CString err_msg;
			CString r_act;

			err_msg.Format("Robot can not %s.\n",act_name);

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				goto LOOP_RETRY;
			}
			return -1;			
		}
	}

	return 1;
}

int  CObj__AtmRobot_FUSION
::Interlock__CHECK_WAFER_LP_SLIDE(CII_OBJECT__ALARM* p_alarm,
								  const CString& stn_name,
								  const CString& act_name)
{
LOOP_RETRY:

	// ...
	int lp_index = Macro__CHECK_LPx_INDEX(stn_name);

	if((lp_index >= 0)	&& (lp_index <  CFG_LPx__SIZE))
	{
		CString ch_data;
		diEXT_CH__LPx__WFR_SLID_OUT_SNS[lp_index]->Get__DATA(ch_data);

		if(ch_data.CompareNoCase("OFF") != 0)
		{
			CString log_msg;

			log_msg.Format("During Robot [%s] Action to [%s] Stn.. WAFER SLIDE OUT SNS [%s] Status.. so Alarm Occur !!", 
				           act_name, stn_name, ch_data);

			Fnc__APP_LOG(log_msg);

			// ...
			{
				int alarm_id = ALID__LP1_WFR_SLIDE_SNS_ALARM + lp_index;
				CString r_act;
			
				p_alarm->Popup__ALARM(alarm_id,r_act);

				if(r_act.CompareNoCase("RETRY") == 0)
				{
					goto LOOP_RETRY;
				}
			}
			return -1;
		}
	}
	else
	{
		CString log_msg;

		log_msg.Format("Unknown %s Station...ret:-1", stn_name);

		Fnc__APP_LOG(log_msg);
		return -1;
	}

	return 1;
}
