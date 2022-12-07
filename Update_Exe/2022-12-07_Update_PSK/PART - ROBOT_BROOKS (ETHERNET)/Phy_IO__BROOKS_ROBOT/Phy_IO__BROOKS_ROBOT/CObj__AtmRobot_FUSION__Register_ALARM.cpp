#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"

#include "math.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
#define  ACT__RETRY_ABORT						\
l_act.RemoveAll();								\
l_act.Add("RETRY");								\
l_act.Add("ABORT");


void CObj__AtmRobot_FUSION
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
