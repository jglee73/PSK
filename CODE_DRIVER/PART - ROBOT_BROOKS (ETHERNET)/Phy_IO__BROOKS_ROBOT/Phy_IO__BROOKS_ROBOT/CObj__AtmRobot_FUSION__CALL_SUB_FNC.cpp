#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"
#include "CObj__AtmRobot_FUSION__ALID.h"

#include "math.h"
#include "CCommon_DEF.h"
#include "Macro_Function.h"


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Is__LOCAL(CII_OBJECT__ALARM* p_alarm)
{

	return 1;
}
int  CObj__AtmRobot_FUSION
::Is__OFFLINE(CII_OBJECT__ALARM* p_alarm)
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

int  CObj__AtmRobot_FUSION
::Get__CFG_STN_NUM(const CString& stn_name, CString& stn_id)
{
	CString cfg_stn_num;

		 if(stn_name.CompareNoCase(STR__AL1) == 0)		    aCH__OTR_IN_CFG__AL1_STN_NUM->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__AL2) == 0)		    aCH__OTR_IN_CFG__AL2_STN_NUM->Get__DATA(cfg_stn_num);

	else if(stn_name.CompareNoCase(STR__VIS1) == 0)		    aCH__OTR_IN_CFG__VIS1_STN_NUM->Get__DATA(cfg_stn_num);

	else if(stn_name.CompareNoCase(STR__LBA) == 0)		    aCH__OTR_IN_CFG__LBA_STN_NUM->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LBB) == 0)		    aCH__OTR_IN_CFG__LBB_STN_NUM->Get__DATA(cfg_stn_num);
	
	else if(stn_name.CompareNoCase(STR__BUFF1) == 0)	    aCH__OTR_IN_CFG__BUF1_STN_NUM->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__BUFF2) == 0)	    aCH__OTR_IN_CFG__BUF2_STN_NUM->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__FULL_BUFF) == 0)	aCH__OTR_IN_CFG__FULL_BUF_STN_NUM->Get__DATA(cfg_stn_num);

	else if(stn_name.CompareNoCase(STR__LP1) == 0)		    aCH__OTR_IN_CFG__LPx_STN_NUM[INT__LP1]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP2) == 0)		    aCH__OTR_IN_CFG__LPx_STN_NUM[INT__LP2]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP3) == 0)		    aCH__OTR_IN_CFG__LPx_STN_NUM[INT__LP3]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP4) == 0)		    aCH__OTR_IN_CFG__LPx_STN_NUM[INT__LP4]->Get__DATA(cfg_stn_num);
	else if(stn_name.CompareNoCase(STR__LP5) == 0)		    aCH__OTR_IN_CFG__LPx_STN_NUM[INT__LP5]->Get__DATA(cfg_stn_num);

	else		
	{
		return -1;
	}

	stn_id = cfg_stn_num;
	return 1;
}


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Seq__ALIGN_PICK(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm,
				  const CString& arm_type,
				  const CString& stn_name,
				  const CString& stn_slot,
				  const CString& ccd_pos)
{
	CString log_msg;
	CString log_bff;

	// ...
	{
		log_msg = "Seq__ALIGN_PICK() : Started ... \n";

		log_bff.Format(" *** %s <- %s \n",
			           dEXT_CH__CFG_AL1_EXIST_FLAG->Get__CHANNEL_NAME(),
					   dEXT_CH__CFG_AL1_EXIST_FLAG->Get__STRING());
		log_msg += log_bff;

		log_bff.Format("  * arm_type <- %s \n", arm_type);
		log_msg += log_bff;
		log_bff.Format("  * stn_name <- %s \n", stn_name);
		log_msg += log_bff;
		log_bff.Format("  * stn_slot <- %s \n", stn_slot);
		log_msg += log_bff;
		log_bff.Format("  * ccd_pos  <- %s \n", ccd_pos);
		log_msg += log_bff;

		Fnc__APP_LOG(log_msg);
	}

LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA(STR__YES) > 0)
	{
		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}

		// ...
		{
			aoCH__ANGLE->Set__DATA(ccd_pos);
			doCH__COMMAND->Set__DATA("ALLoadPP");				// AL Setpoint

			int status = Fnc__ONLINE_CHECK(p_alarm,1);
				
			     if(status == 0)		goto LOOP_RETRY;
			else if(status  < 0)		return -1;	
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}

		return Seq__ROBOT_PICK(p_variable,p_alarm, "AlignPick",arm_type,stn_name,stn_slot);
	}

	return -1;
}

//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Set_IO__ARM_TYPE(const CString& arm_type,
				   const CString& para__stn_name,
				   const CString& para__stn_slot)
{
	CString drv__stn_name 
		= Get__Fusion_Resource_Name_Of_Module_Name(para__stn_name);

	if(drv__stn_name.GetLength() < 1)
	{
		return -1;
	}

	soCH__STN_NAME->Set__DATA(drv__stn_name);
	doCH__SLOT->Set__DATA(para__stn_slot);
	doCH__ARM->Set__DATA(arm_type);
	return 1;
}

int  CObj__AtmRobot_FUSION
::Set_IO__ARM_TYPE(const CString& para__stn_name)
{
	CString drv__stn_name
		= Get__Fusion_Resource_Name_Of_Module_Name(para__stn_name);

	if(drv__stn_name.GetLength() < 1)
	{
		return -1;
	}

	soCH__STN_NAME->Set__DATA(drv__stn_name);
	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__ROBOT_PICK(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm,
				  const CString& act_cmmd,
				  const CString& arm_type,
				  const CString& stn_name,
				  const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	int nDrv_Cmd_Ret = 0;
	CString str_log;

	if(stn_name.CompareNoCase(STR__AL1) == 0)
	{
		int nRet = Seq__ALALIGN_RESULT(p_variable, p_alarm);

		     if(nRet == OBJ_RETRY)		goto LOOP_RETRY;
		else if(nRet == OBJ_ABORT)		return -1;
	}

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// Align
	if(act_cmmd.CompareNoCase("AlignPick") == 0)
	{
		nDrv_Cmd_Ret = doCH__COMMAND->Set__DATA("Align");

		str_log.Format("Set Drv Cmd:%s, return :%d", act_cmmd, nDrv_Cmd_Ret);
		Fnc__APP_LOG(str_log);
		
		if(nDrv_Cmd_Ret < 0)
		{
			int alarm_id = ALID__ALGN_AND_PICK_TIMEOUT_ALARM;
			CString err_msg;
			CString r_act;

			err_msg = "1. Check the Timeout Config Value in the Config Page. \n";
			
			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);
			return OBJ_ABORT;
		}

		// ...
		{
			int status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status <  0)		return -1;	

			if(p_variable->Check__CTRL_ABORT() > 0)
			{
				return -1;
			}
		}

		doCH__COMMAND->Set__DATA("ALResult");			// AL Setpoint

	}
	else											
	{
		doCH__COMMAND->Set__DATA("Pick");
	}

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);
			 
			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;			// abort

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	// ...
	CString str_ret;

	if(stn_name.CompareNoCase(STR__LBA) == 0)
	{
		Fnc__APP_LOG("LL1 RNE Sns Check Start..");
		
		int nRet = dEXT_IO_CH__ARM_LL1_RNE_SNS->When__DATA("None", 3.0);
		if(nRet <= 0)
		{
			str_ret.Format("Sns Ret:%d", nRet);
			Fnc__APP_LOG(str_ret);
			
			return OBJ_ABORT;
		}
	}
	else if(stn_name.CompareNoCase(STR__LBB) == 0)
	{
		Fnc__APP_LOG("LL2 RNE Sns Check Start..");
		
		int nRet = dEXT_IO_CH__ARM_LL2_RNE_SNS->When__DATA("None", 3.0);
		if(nRet <= 0)
		{
			str_ret.Format("Sns Ret:%d", nRet);
			Fnc__APP_LOG(str_ret);

			return OBJ_ABORT;
		}
	}
	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__ROBOT_PLACE(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm,
				   const CString& arm_type,
				   const CString& stn_name,
				   const CString& stn_slot)
{
LOOP_RETRY:

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	doCH__COMMAND->Set__DATA("Place");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;				// abort

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	Sleep(1000);
	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__ROBOT_ROTATE(CII_OBJECT__VARIABLE* p_variable,
				    CII_OBJECT__ALARM* p_alarm,
				    const CString& arm_type,
				    const CString& stn_name,
				    const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,0);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;				// abort

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}	

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// ...
	CString wfr_type;
	dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(wfr_type);

	if(wfr_type.CompareNoCase(STR__NONE) == 0)			doCH__COMMAND->Set__DATA("PrepPick");
	else												doCH__COMMAND->Set__DATA("PrepPlace");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;				// abort

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}
	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__AL_HOME(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA("YES") > 0)
	{
		doCH__COMMAND->Set__DATA("ALHome");

		// ...
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;			// abort

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}
int  CObj__AtmRobot_FUSION
::Seq__AL_SCAN(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA("YES") > 0)
	{
		doCH__COMMAND->Set__DATA("ALScan");

		// ...
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;			

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__MAP(CII_OBJECT__VARIABLE* p_variable,
		   CII_OBJECT__ALARM* p_alarm)
{
	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA("YES") > 0)
	{
		if(Fnc__ROBOT_MAP(p_variable,p_alarm) < 0)
		{
			return -1;
		}
	}
	else
	{
		CString r_act;
		CString err_msg;
		
		int alarm_id = ALID__ATMRB_MODULE_NO_EXIST_ERROR;
		err_msg.Format("No Exist Module");

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

		if(r_act.CompareNoCase("ABORT") == 0)
		{
			return -1;
		}
		return -1;
	}

	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__EXTEND(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& arm_type,
			  const CString& stn_name,
			  const CString& stn_slot)
{
	return Fnc__ROBOT_EXTEND(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}
int  CObj__AtmRobot_FUSION
::Seq__RETRACT(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& arm_type,
			   const CString& stn_name,
			   const CString& stn_slot)
{
	return Fnc__ROBOT_RETRACT(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}

int  CObj__AtmRobot_FUSION
::Seq__GOUP(CII_OBJECT__VARIABLE* p_variable,
			CII_OBJECT__ALARM* p_alarm,
		    const CString& arm_type,
		    const CString& stn_name,
		    const CString& stn_slot)
{
	return Fnc__ROBOT_GOUP(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}
int  CObj__AtmRobot_FUSION
::Seq__GODOWN(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& arm_type,
			  const CString& stn_name,
			  const CString& stn_slot)
{
	return Fnc__ROBOT_GODOWN(p_variable,p_alarm, arm_type,stn_name,stn_slot);
}

int  CObj__AtmRobot_FUSION
::Seq__HOME(CII_OBJECT__VARIABLE* p_variable,
			CII_OBJECT__ALARM* p_alarm)
{
	// ...
	{
		Fnc__APP_LOG("Seq__HOME : Started ...");
	}

	if(Fnc__ROBOT_HOME(p_variable, p_alarm) < 0)
	{
		return -1;
	}

	if(iCFG__SIM_MODE > 0)
	{
		dEXT_IO_CH__ARM_LL1_RNE_SNS->Set__DATA("None");
		dEXT_IO_CH__ARM_LL2_RNE_SNS->Set__DATA("None");
	}
	return 1;
}

int  CObj__AtmRobot_FUSION
::Seq__LP_MAP(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& stn_name)
{
	if(Fnc__LP_MAP(p_variable, p_alarm, stn_name) < 0)
	{
		return -1;
	}
	return 1;
}


//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Seq__ALALIGN(CII_OBJECT__VARIABLE* p_variable, 
			   CII_OBJECT__ALARM* p_alarm, 
			   const CString& ccd_pos)
{
LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA(STR__YES) > 0)
	{
		dCH__INR_FLAG__ALGN_STS->Set__DATA("ALIGNING");

		// ...
		int status;

		aoCH__ANGLE->Set__DATA(ccd_pos);

		// ...
		{
			doCH__COMMAND->Set__DATA("ALAlign");				// AL Command

			status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status  < 0)		return -1;	
		}

		// ...
		{
			doCH__COMMAND->Set__DATA("ALResult");				// AL Result

			status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status  < 0)		return -1;	
		}
	}

	if(p_variable->Check__CTRL_ABORT() > 0)
	{
		return -1;
	}
	return 1;
}

//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Seq__SIM_ALALIGN(CII_OBJECT__VARIABLE* p_variable, 
				   CII_OBJECT__ALARM* p_alarm, 
				   const CString& ccd_pos)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	double  cfg__algn_time = 1.0;
	CString var_data;

LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA(STR__YES) > 0)
	{
		dCH__INR_FLAG__ALGN_STS->Set__DATA("ALIGNING");

		// ...
		int status;

		aoCH__ANGLE->Set__DATA(ccd_pos);

		// ...
		{
			doCH__COMMAND->Set__DATA("ALAlign");			// AL Command

			var_data = sCH__SIM_CFG__ALIGN_TIME->Get__STRING();
			cfg__algn_time = atof(var_data);

			if(x_timer_ctrl->WAIT(cfg__algn_time) < 0)
			{
				return -1;
			}

			status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status  < 0)		return -1;	
		}

		// ...
		{
			doCH__COMMAND->Set__DATA("ALResult");			// AL Result

			status = Fnc__ONLINE_CHECK(p_alarm,1);
	
				 if(status == 0)		goto LOOP_RETRY;
			else if(status  < 0)		return -1;	
		}
	}

	if(p_variable->Check__CTRL_ABORT() > 0)
	{
		return -1;
	}
	return 1;
}

//------------------------------------------------------------------------------------
int  CObj__AtmRobot_FUSION
::Seq__ALALIGN_RESULT(CII_OBJECT__VARIABLE* p_variable, 
					  CII_OBJECT__ALARM* p_alarm)
{
	int status;

	// ...
	{
		status = Fnc__ALIGNER_ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		return OBJ_RETRY;
		else if(status  < 0)		return -1;	

		doCH__COMMAND->Set__DATA("ALResult");				// AL Result
	}

	// ...
	{
		status = Fnc__ALIGNER_ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		return OBJ_RETRY;
		else if(status  < 0)		return -1;	
	}

	if(p_variable->Check__CTRL_ABORT() > 0)
	{
		return -1;
	}
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__IS_COMM_ONLINE()
{
	if(diCH__COMM_STS->Check__DATA("Online") > 0)
	{
		return 1;
	}
	return -1;
}
int  CObj__AtmRobot_FUSION
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

	if(Fnc__IS_COMM_ONLINE() > 0)
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
		int alarm_id = ALID__OFFLINE_ALARM;

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

int  CObj__AtmRobot_FUSION
::Fnc__ALIGNER_ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm,
				            const int alarm_check)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	if(iCFG__SIM_MODE > 0)
	{
		diCH__COMM_STS->Set__DATA("Online");
		
		sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");
	}

	if(Fnc__IS_COMM_ONLINE() > 0)
	{
		CString str__err_id;
		int i__err_id;

		sCH__INR__ALGINER_ERROR_ID->Get__DATA(str__err_id);
		i__err_id = atoi(str__err_id);

		if((i__err_id != 0)&&(alarm_check == 1))
		{
			sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");			// 초기화...

			return Fnc__ROBOT_ALARM_POST(p_alarm,i__err_id);
		}
		return 1;
	} 

	// Offline Alarm Post
	{
		int alarm_id = ALID__OFFLINE_ALARM;
		CString err_msg;
		CString r_act;

		err_msg  = "1. Check the Serial cable\n";
		err_msg += "2. Check the Robot power";

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

			 if(r_act.CompareNoCase("ABORT") == 0)		return -1;
		else if(r_act.CompareNoCase("RETRY") == 0)		return 0;
	}

    return -1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_INIT(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// ...
	Fnc__APP_LOG("==> Fnc_ROBOT_INIT... START");
	Fnc__APP_LOG("Set LL1 and LL2 Load Enable..");

	doEXT_IO_CH__LBA_LOAD_ENABLE->Set__DATA("ON");
	doEXT_IO_CH__LBB_LOAD_ENABLE->Set__DATA("ON");

	doCH__COMMAND->Set__DATA("Home");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;					

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	// ...
	{
		Fnc__APP_LOG("Fnc_ROBOT_MAP... START");
	
		if(Fnc__ROBOT_MAP(p_variable,p_alarm) < 0)
		{
			return -1;
		}

		Fnc__APP_LOG("Fnc_ROBOT_MAP... END");
	}

	if(iCFG__SIM_MODE > 0)
	{
		Sleep(1500);
	}

	if(p_variable->Check__CTRL_ABORT() > 0)
	{
		return -1;
	}

	Fnc__APP_LOG("<== Fnc_ROBOT_INIT... COMPLETE");
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ALIGNER_INIT(CII_OBJECT__VARIABLE* p_variable,
				    CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	Fnc__APP_LOG("==> Fnc_ALIGNER_INIT... START");

	// Aligner Command
	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA("YES") > 0)
	{
		// Aligner Init. -----
		Fnc__APP_LOG("Aligner INIT... START");

		CString wfr_size;
		dEXT_CH__CFG_AL1_MATERIAL_TYPE->Get__DATA(wfr_size);		

		     if(wfr_size.CompareNoCase("3inRnd")    == 0)		doCH__MATERIAL->Set__DATA("1"); 
		else if(wfr_size.CompareNoCase("82.5mmRnd") == 0)		doCH__MATERIAL->Set__DATA("2"); 
		else if(wfr_size.CompareNoCase("100mmRnd")  == 0)		doCH__MATERIAL->Set__DATA("3"); 
		else if(wfr_size.CompareNoCase("125mmRnd")  == 0)		doCH__MATERIAL->Set__DATA("4"); 
		else if(wfr_size.CompareNoCase("150mmRnd")  == 0)		doCH__MATERIAL->Set__DATA("5"); 
		else if(wfr_size.CompareNoCase("200mmRnd")  == 0)		doCH__MATERIAL->Set__DATA("6");  
		else if(wfr_size.CompareNoCase("300mmRnd")  == 0)		doCH__MATERIAL->Set__DATA("7"); 
		else													doCH__MATERIAL->Set__DATA("6"); 

		// Set CCD position
		if(wfr_size.CompareNoCase("300mmRnd") == 0)				doCH__WFR_CCD->Set__DATA("2");
		else													doCH__WFR_CCD->Set__DATA("1");

		// ...
		{
			doCH__COMMAND->Set__DATA("InitAlgn");			

			int status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status <  0)		return -1;				
			
			if(p_variable->Check__CTRL_ABORT() > 0)	
			{
				return -1;
			}
		}

		// ...
		{
			CString cfg__ccd_pos;

			aCH__OTR_IN_PARA__AL1_CCD_POS->Get__DATA(cfg__ccd_pos);		
			aoCH__ANGLE->Set__DATA(cfg__ccd_pos);
		}

		if(dEXT_CH__CFG_ALIGN_DEVICE->Check__DATA("ATM_RB") > 0)
		{
			doCH__COMMAND->Set__DATA("ALLoadPP");			
			
			if(p_variable->Check__CTRL_ABORT() > 0)
			{
				return -1;
			}

			int status = Fnc__ONLINE_CHECK(p_alarm,1);

				 if(status == 0)		goto LOOP_RETRY;
			else if(status <  0)		return -1;			
		}

		// End of Aligner Init -----
		if(Fnc__ROBOT_SET_WAFER(p_variable,p_alarm) < 0)
		{
			return -1;
		}

		// Aligner Home -----
		{
			doCH__COMMAND->Set__DATA("ALHome");

			int status = Fnc__ONLINE_CHECK(p_alarm,1);
			
				 if(status == 0)		goto LOOP_RETRY;
			else if(status <  0)		return -1;				

			if(p_variable->Check__CTRL_ABORT() > 0)
			{
				return -1;
			}
		}

		// AL Map -----
		{
			Fnc__APP_LOG("Aligner AlMap... START");
		
			if(Fnc__AL1_AlMap(p_variable,p_alarm) < 0)
			{
				return -1;
			}
		}
	}

	Fnc__APP_LOG("<== Fnc_ALIGNER_INIT... COMPLETE");
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_MAP(CII_OBJECT__VARIABLE* p_variable,
			     CII_OBJECT__ALARM* p_alarm)
{
	if(iCFG__SIM_MODE > 0)
	{
		Sleep(1500);
	
		dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__NONE);
	}
	else
	{
		if(doCH__COMMAND->Set__DATA("RB.GetMap") < 0)
		{
			return -1;
		}

		CString ch_data = sCH__GetInfo_RB_GetLocationStates->Get__STRING();

		if(ch_data.CompareNoCase("Unoccupied") == 0)
		{
			if(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA(STR__NONE) < 0)
			{
				// Alarm Check  ...

				dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__NONE);
				sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE->Set__DATA("");
			}	
		}
		else
		{
			if(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)
			{
				dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__UNKNOWN);
				sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE->Set__DATA("??");
			}	
		}
	}
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_EXTEND(CII_OBJECT__VARIABLE* p_variable,
				    CII_OBJECT__ALARM* p_alarm,
				    const CString& arm_type,
				    const CString& stn_name,
				    const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	{
		CString act_name;
		act_name.Format("extend from Arm-%s to %s-%s", arm_type,stn_name,stn_slot);

		Fnc__APP_LOG(act_name);

		// Pressure Check -----
		if(Interlock__CHECK_PRESSURE(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}

		// Valve Check -----
		if(Interlock__CHECK_DOOR(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}
	}

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// ...
	CString wfr_type;
	dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(wfr_type);

	if(wfr_type.CompareNoCase(STR__NONE) == 0)			doCH__COMMAND->Set__DATA("PrepPick");
	else												doCH__COMMAND->Set__DATA("PrepPlace");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;	

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}	
	}
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_RETRACT(CII_OBJECT__VARIABLE* p_variable,
				     CII_OBJECT__ALARM* p_alarm,
				     const CString& arm_type,
				     const CString& stn_name,
				     const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	{
		CString act_name;
		act_name.Format("retract from Arm-%s to %s-%s", arm_type,stn_name,stn_slot);

		Fnc__APP_LOG(act_name);

		// Pressure Check -----
		if(Interlock__CHECK_PRESSURE(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}

		// Valve Check -----
		if(Interlock__CHECK_DOOR(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}
	}

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// ...
	CString wfr_type;
	dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(wfr_type);

	if(wfr_type.CompareNoCase(STR__NONE) == 0)			doCH__COMMAND->Set__DATA("PrepPick");
	else												doCH__COMMAND->Set__DATA("PrepPlace");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;	

		if(p_variable->Check__CTRL_ABORT() > 0)	
		{
			return -1;
		}
	}	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_GOUP(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm,
				  const CString& arm_type,
				  const CString& stn_name,
				  const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	{
		CString act_name;
		act_name.Format("goup from Arm-%s to %s-%s", arm_type,stn_name,stn_slot);

		Fnc__APP_LOG(act_name);

		// Pressure Check -----
		if(Interlock__CHECK_PRESSURE(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}

		// Valve Check -----
		if(Interlock__CHECK_DOOR(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}
	}

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// ...
	CString wfr_type;
	dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(wfr_type);

	if(wfr_type.CompareNoCase(STR__NONE) == 0)			doCH__COMMAND->Set__DATA("PrepPick");
	else												doCH__COMMAND->Set__DATA("PrepPlace");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;	

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_GODOWN(CII_OBJECT__VARIABLE* p_variable,
				    CII_OBJECT__ALARM* p_alarm,
				    const CString& arm_type,
				    const CString& stn_name,
				    const CString& stn_slot)
{
LOOP_RETRY:

	// ...
	{
		CString act_name;
		act_name.Format("godown from Arm-%s to %s-%s", arm_type,stn_name,stn_slot);

		Fnc__APP_LOG(act_name);

		// Pressure Check -----
		if(Interlock__CHECK_PRESSURE(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}

		// Valve Check -----
		if(Interlock__CHECK_DOOR(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}
	}

	if(Set_IO__ARM_TYPE(arm_type,stn_name,stn_slot) < 0)
	{
		return -1;
	}

	// ...
	CString wfr_type;
	dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(wfr_type);

	if(wfr_type.CompareNoCase(STR__NONE) == 0)			doCH__COMMAND->Set__DATA("PrepPick");
	else												doCH__COMMAND->Set__DATA("PrepPlace");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;	

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_HOME(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm)
{	
LOOP_RETRY:

	doCH__COMMAND->Set__DATA("Home");

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;					

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__LP_MAP(CII_OBJECT__VARIABLE* p_variable, 
			  CII_OBJECT__ALARM* p_alarm, 
			  const CString& stn_name)
{
LOOP_RETRY:

	// Slot 정보 초기화  ...
	{
		for (int i=0; i<CFG_LPx__SLOT_SIZE; i++)
		{
			dCH__LPx_SLOT_STATUS[i]->Set__DATA("UNKNOWN");
		}
	}

	// ...
	CString log_msg;
	CString log_bff;

	// ...
	{
		CString act_name;
		
		act_name.Format("lp mapping to %s", stn_name);
		Fnc__APP_LOG(act_name);

		log_msg = "LP Door Open Checking ...";
		Fnc__APP_LOG(log_msg);

		// LP Door Open Check ...
		if(Interlock__CHECK_DOOR(p_alarm,stn_name,act_name) < 0)
		{
			return -1;
		}

		log_msg = "LP Slide Sensor Checking ...";
		Fnc__APP_LOG(log_msg);

		// LP Side Sensor Check ...
		if(dCH__CFG_MAPPING_ACTION_SLIDE_OUT_CHECK->Check__DATA("YES") > 0)
		{
			if(Interlock__CHECK_WAFER_LP_SLIDE(p_alarm,stn_name,act_name) < 0)
			{
				return -1;
			}
		}
	}

	if(Set_IO__ARM_TYPE(stn_name) < 0)
	{
		return -1;
	}

	// ...
	{
		int status = 1;
		CString str_cmd = "";

		if(status > 0)
		{
			str_cmd = "MapStn";
			status = doCH__COMMAND->Set__DATA(str_cmd);

			// ...
			{
				log_msg.Format("IO Set (%s) ... \n", str_cmd);

				log_bff.Format(" *** %s <- %s \n",
								doCH__COMMAND->Get__VARIABLE_NAME(),
								doCH__COMMAND->Get__STRING());
				log_msg += log_bff;

				log_bff.Format(" *** state : %1d \n",	status);
				log_msg += log_bff;

				Fnc__APP_LOG(log_msg);
			}
		}

		// < 0 일 때 Alarm 띄우는 부분 추가 할것...
		if(status < 0)
		{
			return -1;
		}

		if(status > 0)
		{
			CString str__err_id;
			int i__err_id;
		
			sCH__INR__ERROR_ID_DEC->Get__DATA(str__err_id);
			
			i__err_id = atoi(str__err_id);
			if(i__err_id != 0)
			{
				status = Fnc__ROBOT_ALARM_POST(p_alarm,i__err_id);

				if(status == 0)
				{
					goto LOOP_RETRY;
				}
				else if(status < 0)
				{
					return -1;
				}
			}

			// ...
			str_cmd = "GetMap";
			status = doCH__COMMAND->Set__DATA(str_cmd);

			// ...
			{
				log_msg.Format("IO Set (%s) ... \n", str_cmd);

				log_bff.Format(" *** %s <- %s \n",
								doCH__COMMAND->Get__VARIABLE_NAME(),
								doCH__COMMAND->Get__STRING());
				log_msg += log_bff;

				log_bff.Format(" *** state : %1d \n",	status);
				log_msg += log_bff;

				Fnc__APP_LOG(log_msg);
			}

			if(i__err_id != 0)
			{
				status = Fnc__ROBOT_ALARM_POST(p_alarm,i__err_id);
				
				if(status == 0)
				{
					goto LOOP_RETRY;
				}
				else if(status < 0)
				{
					return -1;
				}
			}
		}
	}

	if(iCFG__SIM_MODE > 0)
	{
		for (int i=0; i<CFG_LPx__SLOT_SIZE; i++)
		{
			dCH__LPx_SLOT_STATUS[i]->Set__DATA("PRESENT");
		}
	}

	// ...
	{
		int status = Fnc__ONLINE_CHECK(p_alarm,1);

			 if(status == 0)		goto LOOP_RETRY;
		else if(status  < 0)		return -1;	

		if(p_variable->Check__CTRL_ABORT() > 0)	
		{
			return -1;
		}
	}
	
	return 1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_MAP_ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm)
{
	if(iCFG__SIM_MODE > 0)
	{
		diCH__COMM_STS->Set__DATA("Online");
		aiCH__ERROR_ID->Set__DATA("0");

		sCH__INR__ERROR_ID_DEC->Set__DATA("0");
		sCH__INR__ERROR_ID_HEXA->Set__DATA("Ox0");
	}

	if(Fnc__IS_COMM_ONLINE() > 0)
	{
		CString str__err_id;
		int i__err_id;

		sCH__INR__ERROR_ID_DEC->Get__DATA(str__err_id);
		i__err_id = atoi(str__err_id);

		// ...
		{
			CString err_msg;

			err_msg.Format("Error ID  :  %s(%1d) \n", str__err_id,i__err_id);
			Fnc__APP_LOG(err_msg);
		}

		if(i__err_id == 712)
		{
			return 2;
		}

		if((i__err_id != 0)&&(i__err_id != 712))
		{
			return Fnc__ROBOT_ALARM_POST(p_alarm,i__err_id);
		}
		return 1;
	} 

	// Offline alarm post
	{
		int alarm_id = ALID__OFFLINE_ALARM;

		CString err_msg;
		CString r_act;
		
		err_msg  = "1. Check the Serial cable\n";
		err_msg += "2. Check the Robot power\n";

		p_alarm->Popup__ALARM_With_MESSAGE(alarm_id,err_msg,r_act);

		if(r_act.CompareNoCase("ABORT") == 0)		return -1;
		if(r_act.CompareNoCase("RETRY") == 0)		return 0;
	}
    return -1;
}

int  CObj__AtmRobot_FUSION
::Fnc__ROBOT_SET_WAFER(CII_OBJECT__VARIABLE* p_variable,
					   CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// ...
	CString cfg__material_type;
	dEXT_CH__CFG_AL1_MATERIAL_TYPE->Get__DATA(cfg__material_type);

	// Wafer Shape ...
	{
		if((cfg__material_type.CompareNoCase("3inRnd")    == 0)	
		|| (cfg__material_type.CompareNoCase("82.5mmRnd") == 0)
		|| (cfg__material_type.CompareNoCase("100mmRnd")  == 0)	
		|| (cfg__material_type.CompareNoCase("125mmRnd")  == 0)	
		|| (cfg__material_type.CompareNoCase("150mmRnd")  == 0)
		|| (cfg__material_type.CompareNoCase("200mmRnd")  == 0)
		|| (cfg__material_type.CompareNoCase("300mmRnd")  == 0))
		{
			doCH__WFR_SHAPE->Set__DATA("Round");
		}
		else if((cfg__material_type.CompareNoCase("4.5inSqr")  == 0)	
			 || (cfg__material_type.CompareNoCase("82.5mmRnd") == 0)
			 || (cfg__material_type.CompareNoCase("125mmSqr")  == 0)	
			 || (cfg__material_type.CompareNoCase("150mmSqr")  == 0)	
			 || (cfg__material_type.CompareNoCase("175mmSqr")  == 0))
		{
			doCH__WFR_SHAPE->Set__DATA("Square");
		}
	}

	// Wafer Size ...
	{
			 if(cfg__material_type.CompareNoCase("3inRnd")    == 0)		doCH__WFR_SIZE->Set__DATA("1"); 
		else if(cfg__material_type.CompareNoCase("82.5mmRnd") == 0)		doCH__WFR_SIZE->Set__DATA("2"); 
		else if(cfg__material_type.CompareNoCase("100mmRnd")  == 0)		doCH__WFR_SIZE->Set__DATA("3"); 
		else if(cfg__material_type.CompareNoCase("125mmRnd")  == 0)		doCH__WFR_SIZE->Set__DATA("4"); 
		else if(cfg__material_type.CompareNoCase("150mmRnd")  == 0)		doCH__WFR_SIZE->Set__DATA("5"); 
		else if(cfg__material_type.CompareNoCase("200mmRnd")  == 0)		doCH__WFR_SIZE->Set__DATA("6"); 
		else if(cfg__material_type.CompareNoCase("300mmRnd")  == 0)		doCH__WFR_SIZE->Set__DATA("7"); 
		else															doCH__WFR_SIZE->Set__DATA("6");
	}

	// ...
	CString cfg__fdcl;
	dEXT_CH__CFG_AL1_FDCL->Get__DATA(cfg__fdcl);

		 if(cfg__fdcl.CompareNoCase("None") == 0)		doCH__WFR_FDCL->Set__DATA("None"); 
	else if(cfg__fdcl.CompareNoCase("Flat") == 0)		doCH__WFR_FDCL->Set__DATA("Flat"); 
	else if(cfg__fdcl.CompareNoCase("Ntch") == 0)		doCH__WFR_FDCL->Set__DATA("Ntch");
	else												doCH__WFR_FDCL->Set__DATA("Flat"); 

	return 1;
}

// AL1 -----
int  CObj__AtmRobot_FUSION
::Fnc__AL1_AlMap(CII_OBJECT__VARIABLE* p_variable,
			     CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(dEXT_CH__CFG_AL1_EXIST_FLAG->Check__DATA("YES") > 0)
	{
		if(iCFG__SIM_MODE > 0)
		{
			if(dEXT_CH__AL1_SLOT01_STATUS->Check__DATA(STR__NONE) > 0)
			{
				diCH__AL_WFR->Set__DATA("NO");
			}
			else
			{
				diCH__AL_WFR->Set__DATA("YES");
			}
		}

		// ...
		CString str__al_wfr;
		diCH__AL_WFR->Get__DATA(str__al_wfr);
			 
			 if(str__al_wfr.CompareNoCase("?")   == 0)		dEXT_CH__AL1_SLOT01_STATUS->Set__DATA(STR__UNKNOWN);
		else if(str__al_wfr.CompareNoCase("NO")  == 0)		dEXT_CH__AL1_SLOT01_STATUS->Set__DATA(STR__NONE);
		else if(str__al_wfr.CompareNoCase("YES") == 0)		dEXT_CH__AL1_SLOT01_STATUS->Set__DATA(STR__EXIST);
		else												dEXT_CH__AL1_SLOT01_STATUS->Set__DATA(STR__UNKNOWN);

		// ...
		int status = Fnc__ONLINE_CHECK(p_alarm,0);
		
			 if(status == 0)		goto LOOP_RETRY;
		else if(status <  0)		return -1;			

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}
