#include "StdAfx.h"
#include "CObj__PM_METAL.h"
#include "CObj__PM_METAL__DEF.h"
#include "CObj__PM_METAL__ALID.h"


// ...
void CObj__PM_METAL
::Mon__MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	int loop_count = 0;


	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.1);

		loop_count++;
		if(loop_count > 10)		loop_count = 1;


		// Alarm Offline ! 
		if(loop_count == 1)
		{
			if(bActive__COMM_ONLINE)
			{

			}
			else
			{
				int alarm_id = ALID__OFFLINE;
				CString alm_msg;
				CString	r_act;

				alm_msg = "";

				p_alarm->Check__ALARM(alarm_id,r_act);
				p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alm_msg);
			}
		}

		// ...
	}
}

