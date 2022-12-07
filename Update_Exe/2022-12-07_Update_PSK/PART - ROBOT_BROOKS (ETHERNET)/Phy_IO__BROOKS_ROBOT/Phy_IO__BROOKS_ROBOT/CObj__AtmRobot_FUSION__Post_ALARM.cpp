#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_ALARM_POST(CII_OBJECT__ALARM* p_alarm,
					    const int err_id)
{
	if(err_id == 0)    
	{
		return 1;
	}

	// ...
	CString err_msg = Get__Fusion_Error_Msg_Of_Error_Code(err_id);

	// ...
	{
		CString log_msg;
	
		log_msg.Format("Error_ID : %1d \n", err_id);
		log_msg += err_msg;
		Fnc__APP_LOG(log_msg);
	}

	// ...
	int alm_id = ALID__ATMRB_FUSION_ERROR;
	CString r_act;

	p_alarm->Popup__ALARM_With_MESSAGE(alm_id,err_msg,r_act);

	if(r_act.CompareNoCase("ABORT") == 0)		return -1;
	if(r_act.CompareNoCase("RETRY") == 0)		return  0;

	return -1;
}
