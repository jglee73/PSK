#include "StdAfx.h"
#include "CObj__Driver_FUSION.h"
#include "CObj__Driver_FUSION__DEF.h"
#include "CObj__Driver_FUSION__ALID.h"

#include "Macro_Function.h"


//-------------------------------------------------------------------------	
// INIT -----
int  CObj__Driver_FUSION
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iCFG__SIM_MODE > 0)
	{
		Sleep(1500);
		return 1;
	}

	// ...
	int status = -1;

	// ...
	{
		soCH__GET_INFO_CMD->Set__DATA("");

		status = Fnc__ONLINE_CHECK(p_alarm,0);
		if(status <= 0)		return -1;
	}

	if(status <= 0)		return -1;
	return 1;
}

int  CObj__Driver_FUSION
::Fnc__ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm,
					const int alarm_check)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	if(iCFG__SIM_MODE > 0)     
	{
		diCH__COMM_STS->Set__DATA("Online");
		aiCH__ERROR_ID->Set__DATA("0");

		sCH__INR__ERROR_ID_DEC->Set__DATA("0");
		sCH__INR__ERROR_ID_HEXA->Set__DATA("Ox0");

		sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");
	}

	if(diCH__COMM_STS->Check__DATA("Online") > 0)
	{
		CString str__err_id;
		int i__err_id;

		sCH__INR__ERROR_ID_DEC->Get__DATA(str__err_id);
		i__err_id = atoi(str__err_id);

		if((i__err_id != 0)&&(alarm_check == 1))
		{
			return Fnc__ROBOT_ALARM_POST(p_alarm,i__err_id);
		}
		return 1;
	} 

	// Offline Alarm Post
	{
		int alarm_id = ALID__OFFLINE_ALARM__ACT;

		CString err_msg;
		CString r_act;

		err_msg  = "1. Check the ethernet cable\n";
		err_msg += "2. Check the robot power";

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			 if(r_act.CompareNoCase("ABORT") == 0)		return -1;
		else if(r_act.CompareNoCase("RETRY") == 0)		return 0;
	}

	return -1;
}

// ...
int  CObj__Driver_FUSION
::Call__ROBOT_CMMD(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm)
{
	CString parm_arm  = dCH__PARA_ARM_TYPE->Get__STRING();
	CString para_stn  = dCH__PARA_STN_NAME->Get__STRING();
	CString para_slot = dCH__PARA_STN_SLOT->Get__STRING();

	if(Set_IO__ARM_TYPE(parm_arm, para_stn, para_slot) < 0)
	{
		return -11;
	}

	// ...
	CString set_cmmd = dCH__PARA_ROBOT_CMMD->Get__STRING();
	
	if(iCFG__SIM_MODE > 0)
	{
		sCH__RBx_CMMD_STATE->Set__DATA("RUN");
	}

	// ...
	{
		CString log_msg;
		CString log_bff;

		log_msg.Format(" * iCFG__SIM_MODE <- [%1d] \n", iCFG__SIM_MODE);

		log_bff.Format(" * %s <- %s \n", 
					   sCH__RBx_CMMD_STATE->Get__CHANNEL_NAME(),
					   sCH__RBx_CMMD_STATE->Get__STRING());
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}

	return doCH__RBx_CMMD->Set__DATA(set_cmmd);
}

int  CObj__Driver_FUSION
::Call__ALx_CMMD(CII_OBJECT__VARIABLE* p_variable,
				 CII_OBJECT__ALARM* p_alarm)
{
	CString set_cmmd = dCH__PARA_ALx_CMMD->Get__STRING();

	if(iCFG__SIM_MODE > 0)
	{
		sCH__ALx_CMMD_STATE->Set__DATA("RUN");
	}

	CString para_slot = dCH__PARA_STN_SLOT->Get__STRING();
	aoCH__ALIGN_SLOT->Set__DATA(para_slot);

	CString para_angle = sCH__PARA_ALING_ANGLE->Get__STRING();
	dDRV__RB_ANGLE_DEG = atof(para_angle);

	return doCH__ALx_CMMD->Set__DATA(set_cmmd);
}
int  CObj__Driver_FUSION
::Call__ALx_RESULT(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm)
{
	doCH__ALx_REPORT->Set__DATA("ALResult");				// AL Result

	// ...
	CString log_msg;
	CString log_bff;

	log_msg = "\n";

	log_bff.Format(" * %s <- %s \n",
				    sCH__GetInfo_AL_GetEccentricityAngle->Get__VARIABLE_NAME(),
				    sCH__GetInfo_AL_GetEccentricityAngle->Get__STRING());
	log_msg += log_bff;

	log_bff.Format(" * %s <- %s \n",
					sCH__GetInfo_AL_GetEccentricityMagnitude->Get__VARIABLE_NAME(),
					sCH__GetInfo_AL_GetEccentricityMagnitude->Get__STRING());
	log_msg += log_bff;

	log_bff.Format(" * %s <- %s \n",
					sCH__GetInfo_AL_GetEccentricityTransform->Get__VARIABLE_NAME(),
					sCH__GetInfo_AL_GetEccentricityTransform->Get__STRING());
	log_msg += log_bff;

	log_bff.Format(" * %s <- %s \n",
					sCH__GetInfo_AL_GetFiducialAngle->Get__VARIABLE_NAME(),
					sCH__GetInfo_AL_GetFiducialAngle->Get__STRING());
	log_msg += log_bff;

	Fnc__APP_LOG(log_msg);
	return 1;
}
