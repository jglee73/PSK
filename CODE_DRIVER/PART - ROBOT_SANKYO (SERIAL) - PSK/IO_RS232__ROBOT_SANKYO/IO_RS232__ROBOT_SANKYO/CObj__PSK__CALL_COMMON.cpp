#include "StdAfx.h"
#include "CObj__PSK.h"
#include "CObj__PSK__DEF.h"
#include "CObj__PSK__ALID.h"

#include "Macro_Function.h"


// ...
int  CObj__PSK
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{

	return Call__HOME(p_variable, p_alarm, true);
}

int  CObj__PSK
::Call__HOME(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const bool active__al_init)
{
	CString log_msg;	
	CString log_bff;	

	if(Is__ONLINE(p_alarm) < 0)
	{
		log_msg = " * Online Error !";
		Fnc__APP_LOG(log_msg);
		return -1;
	}

	// VERSION ...
	{
		CString str_ver = siCH__VERSION->Get__STRING();

		log_msg.Format(" * Version Info \n");
		log_bff.Format("  * %s <- [%s] \n", siCH__VERSION->Get__CHANNEL_NAME(), str_ver);
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}

	// ERROR.RESET ...
	{
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__ERROR_RESET);

		int r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)
		{
			log_msg.Format("Error.Reset - Error (%1d) !", r_flag);
			Fnc__APP_LOG(log_msg);
			return -11;
		}

		log_msg = "Error.Reset - OK !";
		Fnc__APP_LOG(log_msg);
	}

	// ROBOT.CTRL ...
	{
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__INIT);

		int r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)
		{
			log_msg.Format("Robot.Init - Error (%1d) !", r_flag);
			Fnc__APP_LOG(log_msg);
			return -21;
		}

		log_msg = "Robot.Init - OK !";
		Fnc__APP_LOG(log_msg);
	}
	
	if(iActive__SIM_MODE)
	{
		if(dCH__MON_ARM_A_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)			sCH__MON_A_ARM_GRIPPER_STATE->Set__DATA(STR__NONE);
		else																	sCH__MON_A_ARM_GRIPPER_STATE->Set__DATA(STR__WAFER);

		if(dCH__MON_ARM_B_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)			sCH__MON_B_ARM_GRIPPER_STATE->Set__DATA(STR__NONE);
		else																	sCH__MON_B_ARM_GRIPPER_STATE->Set__DATA(STR__WAFER);
	}

	// ALIGNER.CTRL ...
	if(active__al_init)
	{
		int r_flag = Call__AL_INIT(p_variable, p_alarm);
		if(r_flag < 0)
		{
			log_msg.Format("Aligner.Init - Error (%1d) !", r_flag);
			Fnc__APP_LOG(log_msg);
			return -31;
		}

		log_msg = "Aligner.Init - OK !";
		Fnc__APP_LOG(log_msg);
	}

	// ERROR.RESET ...
	{
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__ERROR_RESET);

		int r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)
		{
			log_msg.Format("Error.Reset - Error (%1d) !", r_flag);
			Fnc__APP_LOG(log_msg);
			return -41;
		}

		log_msg = "Error.Reset - OK !";
		Fnc__APP_LOG(log_msg);
	}

	return 1;
}

int  CObj__PSK
::Call__ERROR_RESET(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm)
{
	// ERROR.RESET ...
	{
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__ERROR_RESET);

		int r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -11;
	}

	return 1;
}

// ...
int  CObj__PSK
::Call__VAC_ON(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& arm_type)
{
	int r_flag;

	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	// VAC.ON ...
	{
		dCH__PARA_RB_ARM_TYPE->Set__DATA(arm_type);

		//
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__CHUCK_ON);

		r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -11;
	}

	return 1;
}
int  CObj__PSK
::Call__VAC_OFF(CII_OBJECT__VARIABLE* p_variable,
				CII_OBJECT__ALARM* p_alarm,
				const CString& arm_type)
{
	int r_flag;

	if(Is__ONLINE(p_alarm) < 0)
	{
		return -1;
	}

	// VAC.OFF ...
	{
		dCH__PARA_RB_ARM_TYPE->Set__DATA(arm_type);

		//
		doCH__RB_COMMAND->Set__DATA(_RB_MODE__CHUCK_OFF);

		r_flag = _Wait__RB_ACTION(p_variable, p_alarm);
		if(r_flag < 0)			return -11;
	}

	return 1;
}

int  CObj__PSK
::Call__MAP(CII_OBJECT__VARIABLE* p_variable,
			CII_OBJECT__ALARM* p_alarm)
{
	int r_flag = Call__VAC_ON(p_variable,p_alarm, ARM_AB);
	if(r_flag < 0)			return -11;

	// ...
	{
		CString ch_data = siCH__RB_STATE_MANUAL->Get__STRING();

		Update__WAFER_INFO();
	
		if(dCH__MON_ARM_A_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)
		{
			Call__VAC_OFF(p_variable,p_alarm, ARM_A);
		}
		if(dCH__MON_ARM_B_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)
		{
			Call__VAC_OFF(p_variable,p_alarm, ARM_B);
		}
	}

	return 1;
}


// ...
int  CObj__PSK::_Wait__RB_ACTION(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	int  r_flag = __Wait__RB_ACTION(p_variable);

	// ...
	{
		CString log_msg;
		CString log_bff;

		log_msg = "_Wait__RB_ACTION() \n";

		log_bff.Format(" * r_flag <- [%1d] \n", r_flag);
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n",
						sCH__MON_COMMAND_RUN->Get__CHANNEL_NAME(),
						sCH__MON_COMMAND_RUN->Get__STRING());
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}
	return r_flag;
}
int  CObj__PSK::__Wait__RB_ACTION(CII_OBJECT__VARIABLE* p_variable)
{
	int check_count = 0;

	CString ch_data = siCH__RB_STATE_MANUAL->Get__STRING();

	while(1)
	{
		Sleep(50);

		if(p_variable->Check__CTRL_ABORT() > 0)			return -11;

		if(iActive__SIM_MODE > 0)
		{
			sCH__MON_COMMAND_RUN->Set__DATA(STR__OFF);
			sCH__MON_RB_TASK_STATE->Set__DATA(STR__OFF);
		}

		// ...
		{
			ch_data = sCH__MON_COMMAND_RUN->Get__STRING();
			if(ch_data.CompareNoCase(STR__OFF) != 0)
			{
				check_count = 0;
				continue;
			}
		}

		check_count++;
		if(check_count >= 10)			break;
	}
	return 1;
}

int  CObj__PSK::_Wait__AL_ACTION(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	int r_flag = __Wait__AL_ACTION(p_variable);


	// ...
	{
		CString log_msg;
		CString log_bff;

		log_msg = "_Wait__AL_ACTION() \n";

		log_bff.Format(" * r_flag <- [%1d] \n", r_flag);
		log_msg += log_bff;

		log_bff.Format(" * %s <- %s \n",
						sCH__MON_AL_BUSY_STATE->Get__CHANNEL_NAME(),
						sCH__MON_AL_BUSY_STATE->Get__STRING());
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}
	return r_flag;
}
int  CObj__PSK::__Wait__AL_ACTION(CII_OBJECT__VARIABLE* p_variable)
{
	int check_count = 0;

	CString ch_data = siCH__RB_STATE_MANUAL->Get__STRING();

	while(1)
	{
		Sleep(50);

		if(p_variable->Check__CTRL_ABORT() > 0)			return -11;

		if(iActive__SIM_MODE > 0)
		{
			sCH__MON_AL_BUSY_STATE->Set__DATA(STR__OFF);
		}

		// ...
		{
			ch_data = sCH__MON_AL_BUSY_STATE->Get__STRING();
			if(ch_data.CompareNoCase(STR__OFF) != 0)
			{
				check_count = 0;
				continue;
			}
		}

		check_count++;
		if(check_count >= 10)			break;
	}
	return 1;
}


// ...
int  CObj__PSK::Is__ONLINE(CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(diCH__COMM_STS->Check__DATA(STR__OFFLINE) > 0)
	{
		int alarm_id = ALID__OFFLINE_ALARM;
		CString r_act;

		p_alarm->Popup__ALARM(alarm_id,r_act);

		if(r_act.CompareNoCase("RETRY") == 0)
		{
			goto LOOP_RETRY;
		}
		return -1;
	}

	return 1;
}

int  CObj__PSK::Get__CFG_STN_NUM(const CString& stn_name,const CString& stn_slot, CString& stage_code,CString& stn_id,CString& pos_slot)
{
	CString cfg_stn_num;

	stage_code = "1";
	pos_slot = stn_slot;

   if(stn_name.CompareNoCase(STR__AL1) == 0)
   {
	   stage_code = "0";
	   pos_slot = "1";

	   aCH__CFG__AL1_STN_NUM->Get__DATA(cfg_stn_num);
   }
	else if(stn_name.CompareNoCase(STR__LBA) == 0)
	{	
		stage_code = "0";
		pos_slot = "1";

			 if(stn_slot.CompareNoCase("1") == 0)			aCH__CFG__LL1_1_STN_NUM->Get__DATA(cfg_stn_num);
		else if(stn_slot.CompareNoCase("2") == 0)			aCH__CFG__LL1_2_STN_NUM->Get__DATA(cfg_stn_num);
		else												return -11;
	}
	else if(stn_name.CompareNoCase(STR__LBB) == 0)
	{
		stage_code = "0";
		pos_slot = "1";

			 if(stn_slot.CompareNoCase("1") == 0)			aCH__CFG__LL2_1_STN_NUM->Get__DATA(cfg_stn_num);
		else if(stn_slot.CompareNoCase("2") == 0)			aCH__CFG__LL2_2_STN_NUM->Get__DATA(cfg_stn_num);
		else												return -21;
	}
	else if(stn_name.CompareNoCase(STR__BUFF1) == 0)
	{
		aCH__CFG__ST1_STN_NUM->Get__DATA(cfg_stn_num);
	}
	else if(stn_name.CompareNoCase(STR__LP1) == 0)		    aCH__CFG__LPx_STN_NUM[INT__LP1]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP2) == 0)		    aCH__CFG__LPx_STN_NUM[INT__LP2]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP3) == 0)		    aCH__CFG__LPx_STN_NUM[INT__LP3]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP4) == 0)		    aCH__CFG__LPx_STN_NUM[INT__LP4]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP5) == 0)		    aCH__CFG__LPx_STN_NUM[INT__LP5]->Get__DATA(cfg_stn_num);	
	else													return -1;

	stn_id = cfg_stn_num;
	return 1;
}
