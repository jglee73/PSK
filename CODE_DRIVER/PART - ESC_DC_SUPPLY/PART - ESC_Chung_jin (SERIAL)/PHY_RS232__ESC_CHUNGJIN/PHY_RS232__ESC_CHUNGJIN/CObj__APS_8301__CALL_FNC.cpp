#include "stdafx.h"
#include "CObj__APS_8301.h"


// ...
int  CObj__APS_8301
::Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	siCH__ESC_FIRMWARE_VER->Get__STRING();

	if(iActive__SIM_MODE > 0)
	{
		sCH__INFO_FIRMWARE_VER->Set__DATA("VER ?.?");
	}

	//
	doCH__ESC_ALARM_RESET_SET->Set__DATA(STR__ON);

	// ...
	{
		double cfg__set_value;

		cfg__set_value = aCH__CFG_LEAK_CURRUNT_LIMIT_mA->Get__VALUE();
		aCH__PARA_LEAK_CURRUNT_LIMIT_mA->Set__VALUE(cfg__set_value);

		cfg__set_value = 0.0;
		aCH__PARA_TIME_DELAY_mSEC->Set__VALUE(cfg__set_value);

		cfg__set_value = aCH__CFG_RAMP_UP_mSEC->Get__VALUE();
		aCH__PARA_RAMP_UP_mSEC->Set__VALUE(cfg__set_value);

		cfg__set_value = aCH__CFG_RAMP_DOWN_mSEC->Get__VALUE();
		aCH__PARA_RAMP_DOWN_mSEC->Set__VALUE(cfg__set_value);

		Call__PARA_SET(p_variable, p_alarm);
	}

	doCH__ESC_VOLTAGE_OUTPUT_SET->Set__DATA(STR__OFF);
	aoCH__ESC_VOLTAGE_SET_V->Set__VALUE(0.0);
	doCH__ESC_DISCHARGE_MODE_SET->Set__DATA(STR__OFF);

	// ...
	{
		bActive__Delay_Check = false;     // KMS:221024
		mCtrl__Delay_Timer->STOP_ZERO();
	}
	return 1;
}

int  CObj__APS_8301
::Call__PARA_SET(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	double para__set_value;

	para__set_value = aCH__PARA_LEAK_CURRUNT_LIMIT_mA->Get__VALUE();
	aoCH__ESC_CURRENT_LIMIT_SET_mA->Set__VALUE(para__set_value);

	para__set_value = aCH__PARA_TIME_DELAY_mSEC->Get__VALUE();
	aoCH__ESC_TIME_DELAY_mSEC->Set__VALUE(para__set_value);

	para__set_value = aCH__PARA_RAMP_UP_mSEC->Get__VALUE();
	aoCH__ESC_RAMP_UP_mSEC->Set__VALUE(para__set_value);

	para__set_value = aCH__PARA_RAMP_DOWN_mSEC->Get__VALUE();
	aoCH__ESC_RAMP_DOWN_mSEC->Set__VALUE(para__set_value);

	return 1;
}

int  CObj__APS_8301
::Call__ALARM_RESET(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	doCH__ESC_ALARM_RESET_SET->Set__DATA(STR__ON);

	siCH__ESC_SYSTEM_STS->Get__STRING();
	sCH__INFO_SYSTEM_ALARM_STS->When__DATA(STR__OFF, 2.0);

	if(sCH__INFO_SYSTEM_ALARM_STS->Check__DATA(STR__ON) > 0)
	{
		// Alarm 

		return -1;
	}
	return 1;
}

// ...
int  CObj__APS_8301
::Call__ON(CII_OBJECT__VARIABLE*	p_variable, CII_OBJECT__ALARM* p_alarm)
{	
	double para__set_value;
	double cur__set_value;

	doCH__ESC_VOLTAGE_OUTPUT_SET->Set__DATA(STR__OFF);

	// TIME_DELAY.mSEC ...
	{
		para__set_value = aCH__PARA_TIME_DELAY_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_TIME_DELAY_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_TIME_DELAY_mSEC->Set__VALUE(para__set_value);
	}
	// RAMP_UP.mSEC ...
	{
		para__set_value = aCH__PARA_RAMP_UP_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_RAMP_UP_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_RAMP_UP_mSEC->Set__VALUE(para__set_value);
	}
	// RAMP_DOWN.mSEC ...
	{
		para__set_value = aCH__PARA_RAMP_DOWN_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_RAMP_DOWN_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_RAMP_DOWN_mSEC->Set__VALUE(para__set_value);
	}

	// VOLTAGE.SET ...
	{
		para__set_value = aCH__PARA_VOLTAGE_SET->Get__VALUE();
		aoCH__ESC_VOLTAGE_SET_V->Set__VALUE(para__set_value);
	}

	doCH__ESC_POWER_SET->Set__DATA(STR__ON);
	doCH__ESC_VOLTAGE_OUTPUT_SET->Set__DATA(STR__ON);

	// ...
	{
		bActive__Delay_Check = true;

		mCtrl__Delay_Timer->STOP_ZERO();
		mCtrl__Delay_Timer->START__COUNT_UP(9999);
	}

	return 1;
}
int  CObj__APS_8301
::Call__OFF(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	doCH__ESC_VOLTAGE_OUTPUT_SET->Set__DATA(STR__OFF);
	aoCH__ESC_VOLTAGE_SET_V->Set__VALUE(0.0);

	// ...
	double para__set_value;
	double cur__set_value;

	// TIME_DELAY.mSEC ...
	{
		para__set_value = aCH__PARA_TIME_DELAY_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_TIME_DELAY_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_TIME_DELAY_mSEC->Set__VALUE(para__set_value);
	}
	// RAMP_UP.mSEC ...
	{
		para__set_value = aCH__PARA_RAMP_UP_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_RAMP_UP_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_RAMP_UP_mSEC->Set__VALUE(para__set_value);
	}
	// RAMP_DOWN.mSEC ...
	{
		para__set_value = aCH__PARA_RAMP_DOWN_mSEC->Get__VALUE();
		cur__set_value  = aoCH__ESC_RAMP_DOWN_mSEC->Get__VALUE();

		if(para__set_value != cur__set_value)			aoCH__ESC_RAMP_DOWN_mSEC->Set__VALUE(para__set_value);
	}

	// ...
	{
		bActive__Delay_Check = false;      // KMS:221024
		mCtrl__Delay_Timer->STOP_ZERO();
	}
	return 1;
}

