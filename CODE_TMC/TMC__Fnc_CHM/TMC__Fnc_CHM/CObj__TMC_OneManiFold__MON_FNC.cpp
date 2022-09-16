#include "StdAfx.h"
#include "CObj__TMC_OneManiFold.h"
#include "CObj__TMC_OneManiFold__DEF.h"


// ...
void CObj__TMC_OneManiFold::
Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	SCX__TIMER_CTRL cx_timer_ctrl;
	CString var__data;

	while(1)
	{
		Sleep(9);

		// OBJ STATUS -----
		sCH__OBJ_STATUS->Get__DATA(var__data);
		sEXT_CH__TMC_CHM__OBJ_STATUS->Set__DATA(var__data);

		// PRESSURE STATUS -----
		dEXT_CH__TMC_CHM__PRESSURE_STATUS->Get__DATA(var__data);
		sCH__PRESSURE_STATUS->Set__DATA(var__data);

		// PRESSURE TORR -----
		aEXT_CH__TMC_CHM__PRESSURE_TORR->Get__DATA(var__data);
		aCH__TMC_CHM_PRESSURE_TORR->Set__DATA(var__data);
	}	
}
