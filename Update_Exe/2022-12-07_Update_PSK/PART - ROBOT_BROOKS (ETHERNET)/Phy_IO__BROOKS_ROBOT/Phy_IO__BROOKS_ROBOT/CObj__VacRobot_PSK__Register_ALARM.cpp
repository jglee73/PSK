#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "CCommon_DEF.h"


//--------------------------------------------------------------------------------
#define  REG_ACT__ABORT							\
	l_act.RemoveAll();								\
	l_act.Add("ABORT");

#define  REG_ACT__ABORT_SENSORSYNC				\
	l_act.RemoveAll();								\
	l_act.Add("ABORT");								\
	l_act.Add("SENSOR_SYNC");


void CObj__VacRobot_PSK
::Register__ALARM_INF(CII_DEFINE__ALARM* p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;
	int alarm_id;

	// ...
	{
		alarm_id = ALID__CONTROLLER_ERROR_CODE;

		alarm_title  = title;
		alarm_title += "Controller Error Code";

		alarm_msg = "";

		REG_ACT__ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__VACRB1_MATERIAL_DIFFERENT_INFO;

		alarm_title  = title;
		alarm_title += "VACRB: Mapping Information Error";

		alarm_msg.Format("After Map Complete, Wafer Status is different from Mapping Sensor.\n");

		REG_ACT__ABORT_SENSORSYNC;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}
}
