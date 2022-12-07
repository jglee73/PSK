#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Interlock__CHECK_PRESSURE(CII_OBJECT__ALARM* p_alarm,
						    const CString& stn_name,
						    const CString& act_name)
{
LOOP_RETRY:

	if((stn_name.CompareNoCase(STR__LBA) == 0)
	|| (stn_name.CompareNoCase(STR__LBB) == 0))
	{
		CII__VAR_ANALOG_CTRL *p_lbx_pressure;
		int alarm_id;

		if(stn_name.CompareNoCase(STR__LBA) == 0)
		{
			alarm_id = ALID__LBA__NOT_ATM_PRESSURE;
			p_lbx_pressure = aEXT_CH__LBA_PRESSURE_TORR.Get__PTR();
		}
		else if(stn_name.CompareNoCase(STR__LBB) == 0)
		{
			alarm_id = ALID__LBB__NOT_ATM_PRESSURE;
			p_lbx_pressure = aEXT_CH__LBB_PRESSURE_TORR.Get__PTR();
		}

		// ...
		double  ref__atm_pressure;
		double  cur__pressure;
		CString ch_data;

		aEXT_CH__CFG_REF_ATM_PRESSURE->Get__DATA(ch_data);
		ref__atm_pressure = atof(ch_data);

		p_lbx_pressure->Get__DATA(ch_data);
		cur__pressure = atof(ch_data);

		if(cur__pressure < ref__atm_pressure)
		{
			CString err_msg;
			CString err_bff;
			CString r_act;

			err_msg.Format("%s's (%f torr) Pressure must be more than (%f torr) Config ATM Pressure.\n",
							stn_name,
							cur__pressure,
							ref__atm_pressure);

			err_bff.Format("Robot can not %s.\n",act_name);
			err_msg += err_bff;

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
