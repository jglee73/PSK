#include "StdAfx.h"
#include "CObj__PSK.h"
#include "CObj__PSK__DEF.h"
#include "CObj__PSK__ALID.h"

#include "Macro_Function.h"


// ...
int  CObj__PSK
::Call__AL_INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	// ...
	int r_flag = Fnc__AL_INIT(p_variable, p_alarm);

	// Chuck.Off ...
	{
		doCH__AL_COMMAND->Set__DATA(_AL_MODE__CHUCK_OFF);

		int r_flag = _Wait__AL_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -101;
	}
	return r_flag;
}
int  CObj__PSK
::Fnc__AL_INIT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(dCH__MON_AL_MATERIAL_STATUS->Check__DATA(STR__NONE) < 0)
	{
		// Chuck.On ...
		{
			doCH__AL_COMMAND->Set__DATA(_AL_MODE__CHUCK_ON);

			int r_flag = _Wait__AL_ACTION(p_variable, p_alarm);
			if(r_flag < 0)			return -11;
		}
	}

	// ALIGNER.CTRL ...
	{
		doCH__AL_COMMAND->Set__DATA(_AL_MODE__INIT);

		int r_flag = _Wait__AL_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -21;
	}


	return 1;
}


int  CObj__PSK
::Call__ALIGN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	return Fnc__ALIGN(p_variable, p_alarm);
}
int  CObj__PSK
::Fnc__ALIGN(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(dCH__CFG_ALIGN_MEASUREMENT_USE->Check__DATA(STR__NO) > 0)
	{
		return 10001;
	}

	// ...
	CString ref_angle = aCH__OTR_IN_PARA__AL1_CCD_POS->Get__STRING();

	// Chuck.On ...
	{
		CString log_msg = "Align.Chuck_On Start";
		Fnc__APP_LOG(log_msg);

		//
		doCH__AL_COMMAND->Set__DATA(_AL_MODE__CHUCK_ON);

		int r_flag = _Wait__AL_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -11;
	}

	// Measure.Start ...
	{
		CString log_msg = "Align.Measure Start";
		Fnc__APP_LOG(log_msg);

		//
		aCH__PARA_AL_NOTCH_ANGLE->Set__DATA(ref_angle);
		doCH__AL_COMMAND->Set__DATA(_AL_MODE__MEASURE_START);

		int r_flag = _Wait__AL_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -21;
	}

	// ...
	{
		CString log_msg;
		CString log_bff;

		CString ch_data = siCH__AL_MEASUREMENT->Get__STRING();

		//
		log_msg = "Align.Report ... \n";

		log_bff.Format(" * %s <- %s \n", 
						siCH__AL_MEASUREMENT->Get__CHANNEL_NAME(),
						ch_data);
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n", 
						sCH__MON_AL_BUSY_STATE->Get__CHANNEL_NAME(),
						sCH__MON_AL_BUSY_STATE->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n", 
						sCH__MON_AL_STATE->Get__CHANNEL_NAME(),
						sCH__MON_AL_STATE->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n", 
						sCH__MON_AL_X_ERROR->Get__CHANNEL_NAME(),
						sCH__MON_AL_X_ERROR->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n", 
						sCH__MON_AL_Y_ERROR->Get__CHANNEL_NAME(),
						sCH__MON_AL_Y_ERROR->Get__STRING());
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n", 
						sCH__MON_AL_NOTCH_ANGLE->Get__CHANNEL_NAME(),
						sCH__MON_AL_NOTCH_ANGLE->Get__STRING());
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}

	return 1;
}

int  CObj__PSK
::Call__AL_CHUCK_ON(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	doCH__AL_COMMAND->Set__DATA(_AL_MODE__CHUCK_ON);

	return _Wait__AL_ACTION(p_variable, p_alarm);
}
int  CObj__PSK
::Call__AL_CHUCK_OFF(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	doCH__AL_COMMAND->Set__DATA(_AL_MODE__CHUCK_OFF);

	return _Wait__AL_ACTION(p_variable, p_alarm);
}
