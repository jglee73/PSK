#include "StdAfx.h"
#include "CObj__Driver_FUSION.h"
#include "CObj__Driver_FUSION__DEF.h"
#include "CObj__Driver_FUSION__ALID.h"

#include "math.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
#define  ACT__RETRY_ABORT						\
l_act.RemoveAll();								\
l_act.Add("RETRY");								\
l_act.Add("ABORT");


void CObj__Driver_FUSION
::Register__ALARM_INF(CII_DEFINE__ALARM* p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ATM-Robot Error : ", sObject_Name);

	int alarm_id;
	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;

	// ...
	{
		alarm_id = ALID__ATMRB_FUSION_ERROR;

		alarm_title  = title;
		alarm_title += "Fusion Error Code !";

		alarm_msg = "";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__ATMRB_MODULE_NO_EXIST_ERROR;

		alarm_title  = title;
		alarm_title += "Module No Exist Error";

		alarm_msg = "Can't Set Command, Check Config option..";

		ACT__ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}
}

int  CObj__Driver_FUSION
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
