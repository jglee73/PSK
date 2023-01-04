#include "StdAfx.h"
#include "CObj__NAVII_SERIAL.h"


// ...
int CObj__NAVII_SERIAL
::Call__INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	// ...
	int flag = 1;

	// Control.Mode 
	{
		doCH__CONTROL_MODE_CH->Set__DATA(STR__HOST);
		if(iActive_SIM > 0) sCH__INFO_CTRL_MODE_CH->Set__DATA(STR__HOST);
	}


	{// Clear Latched Faults
		doCH__CLEAR_LATCH_FAULTS->Set__DATA(STR__SET);
	}

	// Preset
	{
		doCH__INTERNAL_EXTERNAL_PRESET_CH->Set__DATA(STR__INTERNAL);
	}
	// Capacitor
	{
		//doCH__CAPACITOR_LIMIT_CH->Set__DATA(STR__SET);
	}

	doCH__ALL_CAPACITOR_INIT->Set__DATA(STR__SET);
	//... Wait For Init Work
	{
		int iTempCouint = 0;
		bool bEndLatch = false;
		while(true)
		{
			if(iActive_SIM > 0)
			{
				if(iTempCouint >= 6 && iTempCouint < 15)
				{
					aCH__INFO_LOAD_POS_CH -> Set__VALUE(100.0);
					aCH__INFO_TUNE_POS_CH -> Set__VALUE(100.0);
					aCH__INFO_CAP_POS_CH -> Set__VALUE(100.0);
				}
				else
				{
					aCH__INFO_LOAD_POS_CH -> Set__VALUE(0.0);
					aCH__INFO_TUNE_POS_CH -> Set__VALUE(0.0);
					aCH__INFO_CAP_POS_CH -> Set__VALUE(0.0);
				}
			}
			double TempCapPose = aCH__INFO_CAP_POS_CH->Get__VALUE();
			if(iTempCouint>=20 && TempCapPose == 0 && bEndLatch == true)
			{
				break;
			}
			else if(TempCapPose >= 90)
			{
				bEndLatch = true;
			}
			if(iTempCouint >= 400){break;}//Time out
			if(p_variable->Check__CTRL_ABORT() > 0){return -1;}
			Sleep(150);
			iTempCouint++;
		}
	}
	Sleep(500);
	// after Init, All Set Pramter Vaule
	doCH__LOAD_POS_CH->Set__DATA(STR__SET);
	doCH__TUNE_POS_CH->Set__DATA(STR__SET);
	doCH__AUXILIARY_CAP_POS->Set__DATA(STR__SET);
	if(iActive_SIM > 0)
	{
		aCH__INFO_CAP_POS_CH -> Set__VALUE(atof(aCH__PARA_CAP_POS_CH->Get__STRING()));
		aCH__INFO_LOAD_POS_CH ->Set__VALUE(atof(aCH__PARA_LOAD_POS_CH->Get__STRING()));
		aCH__INFO_TUNE_POS_CH ->Set__VALUE(atof(aCH__PARA_TUNE_POS_CH->Get__STRING()));
	}
	

	return flag;
}

//
int  CObj__NAVII_SERIAL
::Call__AUTO_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active_all)
{
	// ...
	CString ch_data;
	if(active_all)
	{
		doCH__CONTROL_MODE_CH->Set__DATA(STR__AUTO);
	}
	else
	{;
		doCH__CONTROL_MODE_CH->Set__DATA(STR__AUTO);
		if(iActive_SIM > 0) sCH__INFO_CTRL_MODE_CH->Set__DATA(STR__AUTO);
		
	}
	return 1;
}

int  CObj__NAVII_SERIAL
::Call__MANUAL_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const bool active_all)
{
	// ...
	CString ch_data;

	if(active_all)
	{
		doCH__CONTROL_MODE_CH->Set__DATA(STR__HOST);
	}
	else
	{
		doCH__CONTROL_MODE_CH->Set__DATA(STR__HOST);
		doCH__LOAD_POS_CH->Set__DATA(STR__SET);
		doCH__TUNE_POS_CH->Set__DATA(STR__SET);
		doCH__AUXILIARY_CAP_POS->Set__DATA(STR__SET);
		if(iActive_SIM > 0)
		{
			sCH__INFO_CTRL_MODE_CH->Set__DATA(STR__HOST);
			aCH__INFO_CAP_POS_CH -> Set__VALUE(atof(aCH__PARA_CAP_POS_CH->Get__STRING()));
			aCH__INFO_LOAD_POS_CH ->Set__VALUE(atof(aCH__PARA_LOAD_POS_CH->Get__STRING()));
			aCH__INFO_TUNE_POS_CH ->Set__VALUE(atof(aCH__PARA_TUNE_POS_CH->Get__STRING()));
		}
	}
	return 1;
}

//
int  CObj__NAVII_SERIAL
::Call__CTRL_MODE_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int ch_id)
{
	// ...
	CString ch_data;
	int flag = -1;

	if((ch_id == 0) || (ch_id == 1))
	{
		ch_data = dCH__PARA_CONTROL_MODE_CH->Get__STRING();
		flag	= doCH__CONTROL_MODE_CH->Set__DATA(ch_data);
		if(iActive_SIM > 0) sCH__INFO_CTRL_MODE_CH->Set__DATA(ch_data);
	}
	return flag;
}

int  CObj__NAVII_SERIAL
::Call__PRESET_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int ch_id)
{
	// ...
	CString ch_data;
	int flag = -1;

	if((ch_id == 0) || (ch_id == 1))
	{
		flag = doCH__ACTIVE_PRESET_CH->Set__DATA(STR__SET);
	}
	return flag;
}

int  CObj__NAVII_SERIAL
::Call__LOAD_POS_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int ch_id)
{
	// ...
	CString ch_data;
	int flag = -1;

	if((ch_id == 0) || (ch_id == 1))
	{
		flag = doCH__LOAD_POS_CH->Set__DATA(STR__SET);
		if(iActive_SIM > 0) aCH__INFO_LOAD_POS_CH ->Set__VALUE(atof(aCH__PARA_LOAD_POS_CH->Get__STRING()));
	}

	return flag;
}
int  CObj__NAVII_SERIAL
::Call__TUNE_POS_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int ch_id)
{
	// ...
	CString ch_data;
	int flag = -1;

	if((ch_id == 0) || (ch_id == 1))
	{
		flag = doCH__TUNE_POS_CH->Set__DATA(STR__SET);
		if(iActive_SIM > 0) aCH__INFO_TUNE_POS_CH ->Set__VALUE(atof(aCH__PARA_TUNE_POS_CH->Get__STRING()));
	}
	return flag;
}

int  CObj__NAVII_SERIAL
::Call__CAP_MOTOR_CH_X(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int ch_id)
{
	int flag = -1;

	flag = doCH__AUXILIARY_CAP_POS->Set__DATA(STR__SET);
	if(iActive_SIM > 0) aCH__INFO_CAP_POS_CH -> Set__VALUE(atof(aCH__PARA_CAP_POS_CH->Get__STRING()));
	
	return flag;
}

int  CObj__NAVII_SERIAL
::Call__PROC_CTRL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	// ...
	CString ch_data;

	// LOAD.POS ...
	{
		doCH__LOAD_POS_CH->Set__DATA(STR__SET);		
	}
	// TUNE.POS ...
	{
		doCH__TUNE_POS_CH->Set__DATA(STR__SET);
	}
	// CAP.POS ...
	{
		doCH__AUXILIARY_CAP_POS->Set__DATA(STR__SET);
	}

	if(iActive_SIM > 0)
	{

		aCH__INFO_CAP_POS_CH -> Set__VALUE(atof(aCH__PARA_CAP_POS_CH->Get__STRING()));
		aCH__INFO_LOAD_POS_CH ->Set__VALUE(atof(aCH__PARA_LOAD_POS_CH->Get__STRING()));
		aCH__INFO_TUNE_POS_CH ->Set__VALUE(atof(aCH__PARA_TUNE_POS_CH->Get__STRING()));
		CString ch_data;

		// LOAD.POS ...
		{
			aCH__PARA_LOAD_POS_CH->Get__DATA(ch_data);
		}
		// TUNE.POS ...
		{
			aCH__PARA_TUNE_POS_CH->Get__DATA(ch_data);
		}
		// CAP.POS ...
		{
			aCH__PARA_CAP_POS_CH->Get__DATA(ch_data);
		}
	}
	return 1;
}
