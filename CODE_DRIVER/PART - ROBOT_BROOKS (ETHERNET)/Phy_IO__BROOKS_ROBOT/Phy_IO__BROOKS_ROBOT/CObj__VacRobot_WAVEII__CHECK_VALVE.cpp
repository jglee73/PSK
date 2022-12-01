#include "StdAfx.h"
#include "CObj__VacRobot_WAVEII.h"
#include "CObj__VacRobot_WAVEII__DEF.h"
#include "CObj__VacRobot_WAVEII__ALID.h"

#include "Macro_Function.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_WAVEII
::Interlock__CHECK_VALVE(CII_OBJECT__ALARM* p_alarm,
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
			alarm_id = ALID__LBA__NOT_VALVE_OPEN;
			p_lb_door = dEXT_CH__LBA_SLIT_VALVE_STATUS.Get__PTR();
		}
		else if(stn_name.CompareNoCase(STR__LBB) == 0)
		{
			alarm_id = ALID__LBB__NOT_VALVE_OPEN;
			p_lb_door = dEXT_CH__LBB_SLIT_VALVE_STATUS.Get__PTR();
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
	int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

	if((pm_index >= 0)
	&& (pm_index <  m_nPM_LIMIT))
	{
		if(dEXT_CH__CFG_PMx_SV_USE[pm_index]->Check__DATA("NO") > 0)
		{
			return 1;
		}

		if(dEXT_CH__PMx_SLIT_VALVE_STATUS[pm_index]->Check__DATA(STR__OPEN) < 0)
		{
			int alarm_id = ALID__PMx__NOT_VALVE_OPEN;
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
