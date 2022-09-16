#include "StdAfx.h"
#include "CObj__SHUTTER_IO.h"
#include "CObj__SHUTTER_IO__ALID.h"
#include "CObj__SHUTTER_IO__DEF.h"


// ...
int CObj__SHUTTER_IO
::Mon__STATUS(CII_OBJECT__VARIABLE *p_variable,CII_OBJECT__ALARM *p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		dEXT_CH__DI_SHUTTER_CLOSE->Set__DATA(STR__ON);
		dEXT_CH__DI_SHUTTER_OPEN->Set__DATA(STR__OFF);
	}

	int loop_count = 0;

	while(1)
	{
		p_variable->Wait__SINGLE_OBJECT(0.1);


		loop_count++;
		if(loop_count > 10)			loop_count = 1;

		if(loop_count == 1)
		{
			int active__err_check = p_alarm->Check__Posted_Internal_Alarm(iLIST_ALID__PIN);

			if(active__err_check > 0)		dCH__MON_PART_ERROR_ACTIVE->Set__DATA(STR__ON);
			else							dCH__MON_PART_ERROR_ACTIVE->Set__DATA(STR__OFF);
		}

		// ...
		{
			if((dEXT_CH__DI_SHUTTER_CLOSE->Check__DATA(STR__ON) > 0)
			&& (dEXT_CH__DI_SHUTTER_OPEN->Check__DATA(STR__OFF) > 0))
			{
				sEXT_CH__SHUTTER_STATE->Set__DATA(STR__CLOSE);
			}
			else if((dEXT_CH__DI_SHUTTER_CLOSE->Check__DATA(STR__OFF) > 0)
				 && (dEXT_CH__DI_SHUTTER_OPEN->Check__DATA(STR__ON)   > 0))
			{
				sEXT_CH__SHUTTER_STATE->Set__DATA(STR__OPEN);
			}
			else
			{
				sEXT_CH__SHUTTER_STATE->Set__DATA(STR__UNKNOWN);
			}
		}
	}

	return 1;
}
