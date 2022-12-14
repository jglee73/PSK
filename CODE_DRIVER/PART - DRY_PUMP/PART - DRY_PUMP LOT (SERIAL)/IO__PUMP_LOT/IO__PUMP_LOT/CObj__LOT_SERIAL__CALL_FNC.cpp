#include "StdAfx.h"
#include "CObj__LOT_SERIAL.h"


// ..
int CObj__LOT_SERIAL
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}

int CObj__LOT_SERIAL
::Call__LOCAL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}
int CObj__LOT_SERIAL
::Call__REMOTE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}

int CObj__LOT_SERIAL
::Call__ON(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		sCH__MON_MODE_STS->Set__DATA(STR__Start);
	}

	return doCH__MODE_SET->Set__DATA(_Cmmd_IO__Start);
}
int CObj__LOT_SERIAL
::Call__AUTO_SHUTDOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		sCH__MON_MODE_STS->Set__DATA(STR__Ready);
	}

	return doCH__MODE_SET->Set__DATA(_Cmmd_IO__Stop_Slow);
}
int CObj__LOT_SERIAL
::Call__FAST_SHUTDOWN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		sCH__MON_MODE_STS->Set__DATA(STR__Ready);
	}

	return doCH__MODE_SET->Set__DATA(_Cmmd_IO__Stop);
}
