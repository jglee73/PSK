#include "StdAfx.h"
#include "CObj__PM_METAL.h"
#include "CObj__PM_METAL__DEF.h"
#include "CObj__PM_METAL.h"


// ...
void CObj__PM_METAL::_Update__BOTTLE_STATE(const unsigned int i_data)
{
	CString str_sts;
	CString str_msg;

	if(i_data == 1)
	{
		str_sts = "IDLE";
		str_msg = "IDLE";
	}
	else if(i_data == 2)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "GAS REMOVAL";
	}
	else if(i_data == 3)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "SHUTOFF TEST";
	}
	else if(i_data == 4)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "PRE-PURGE";
	}
	else if(i_data == 5)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "CYLINDER CHANGE";
	}
	else if(i_data == 6)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "VACUUM LEAKCHECK";
	}
	else if(i_data == 7)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "PRESSURE LEAKCHECK";
	}
	else if(i_data == 8)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "POST-PURGE";
	}
	else if(i_data == 9)
	{
		str_sts = "AUTO.STAND-BT";
		str_msg = "STAND-BY";
	}
	else if(i_data == 10)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "GAS READY";
	}
	else if(i_data == 11)
	{
		str_sts = "AUTO.SERVICE";
		str_msg = "SERVICE";
	}
	else if(i_data == 12)
	{
		str_sts = "MANUAL.SERVICE";
		str_msg = "MANUAL SERVICE";
	}
	else if(i_data == 13)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "AUTO PURGE START";
	}
	else if(i_data == 14)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "GAS SUPPLY";
	}
	else if(i_data == 25)
	{
		str_sts = "AUTO.PURGE";
		str_msg = "SERVICE PAUSE";
	}
	else
	{
		str_sts = "UNKNOWN";
		str_msg.Format("UNKNOWN (%1d)", i_data);
	}

	// ...
	int x_index = 0;				

	sCH__INFO_BOTTLE_STATE_X[x_index]->Set__DATA(str_sts);
	sCH__INFO_BOTTLE_MSG_X[x_index]->Set__DATA(str_msg);
}

void CObj__PM_METAL::_Update__BOTTLE_VALVE(const unsigned int i_data)
{
	CString str__vlv_sts;
	int x_index = 0;				

	// AV1 ...
	{
		if(i_data & 0x01)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV1_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV2 ...
	{
		if(i_data & 0x002)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV2_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV3 ...
	{
		if(i_data & 0x004)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV3_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV4 ...
	{
		if(i_data & 0x008)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV4_X[x_index]->Set__DATA(str__vlv_sts);
	}

	// AV5 ...
	{
		if(i_data & 0x010)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV5_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// VS ...
	{
		if(i_data & 0x020)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_VS_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV6 ...
	{
		if(i_data & 0x040)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV6_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV7 ...
	{
		if(i_data & 0x080)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV7_X[x_index]->Set__DATA(str__vlv_sts);
	}

	// AV8 ...
	{
		if(i_data & 0x100)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV8_X[x_index]->Set__DATA(str__vlv_sts);
	}
	// AV9 ...
	{
		if(i_data & 0x200)			str__vlv_sts = STR__OPEN;
		else						str__vlv_sts = STR__CLOSE;	

		dCH__INFO_BOTTLE_AV9_X[x_index]->Set__DATA(str__vlv_sts);
	}
}

void CObj__PM_METAL::_Update__ALARM_ACTIVE(const unsigned int i_data)
{
	CString str__sts;

	// 0x001
	{
		if(i_data & 0x001)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_PURGE->Set__DATA(str__sts);
	}

	// 0x004
	{
		if(i_data & 0x004)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_HEAVY->Set__DATA(str__sts);
	}
	// 0x008
	{
		if(i_data & 0x008)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_LIGHT->Set__DATA(str__sts);
	}

	// 0x010
	{
		if(i_data & 0x010)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_EMERGENCY_STOP->Set__DATA(str__sts);
	}
	// 0x020
	{
		if(i_data & 0x020)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_LEAK->Set__DATA(str__sts);
	}
	// 0x040
	{
		if(i_data & 0x040)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_FIRE->Set__DATA(str__sts);
	}
	// 0x080
	{
		if(i_data & 0x080)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_HIGH_TEMPERATURE->Set__DATA(str__sts);
	}

	// 0x200
	{
		if(i_data & 0x200)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_PT1_LOW_1->Set__DATA(str__sts);
	}
	// 0x400
	{
		if(i_data & 0x400)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_PT1_LOW_2->Set__DATA(str__sts);
	}
	// 0x800
	{
		if(i_data & 0x800)			str__sts = STR__ON;
		else						str__sts = STR__OFF;

		dCH__INFO_ALARM_ACTIVE_CDA_LOW->Set__DATA(str__sts);
	}
}
