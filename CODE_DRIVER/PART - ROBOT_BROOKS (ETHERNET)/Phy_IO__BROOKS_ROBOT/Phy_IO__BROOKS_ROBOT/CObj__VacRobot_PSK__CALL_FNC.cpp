#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "Macro_Function.h"
#include "math.h"


//-------------------------------------------------------------------------	
// Init -----
int  CObj__VacRobot_PSK
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		sCH__DRV_INFO_ERROR_CODE->Set__DATA("0");
		sCH__INR_RB1_VERSION->Set__DATA("V.???");
	}

	siCH__VERSION__MANUAL->Get__STRING();

	if(Fnc__INIT(p_variable,p_alarm) < 0)
	{
		return -11;
	}

	if(Fnc__MAP(p_variable,p_alarm) < 0)
	{
		return -12;
	}
	return 1;
}

int  CObj__VacRobot_PSK
::Fnc__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// ...
	int state;
	Fnc__APP_LOG("[INIT] Mode --> ComInit Start...");

	if(Is__LOCAL(p_alarm) < 0)
	{
		return -1;
	}

	// after Robot Module doesn't Recieved data, IS__OFFLINE popup
	if(diCH__COMM_STS->Check__DATA(STR__OFFLINE) > 0)
	{
		int nCount =0;
		
		do
		{
			if(p_variable->Check__CTRL_ABORT() > 0)
			{
				return -1;
			}

			state = doCH__COMMAND->Set__DATA("ComInit");
			nCount++;

			if(nCount > 3)
			{
				break;
			}
		}
		while(state);
	}

	if(Is__OFFLINE(p_alarm) < 0)
	{
		return -1;
	}

	if(dCH__CFG_WFR_SNS_CHECK->Check__DATA("TRUE") > 0)
	{
		doCH__ARM_WFR_SNS->Set__DATA("Yes");

		state = doCH__COMMAND->Set__DATA("WfrSnsIntk");
	}
	else
	{
		doCH__ARM_WFR_SNS->Set__DATA("No");

		state = doCH__COMMAND->Set__DATA("WfrSnsIntk");
	}

	if(state == 0)    // Abort
	{
		return -1;
	}

	if(Is__OFFLINE(p_alarm) < 0)
	{
		return -1;
	}

	// ...
	{
		state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			if(state == OBJ_RETRY)			goto LOOP_RETRY;
			else							return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	/*
	// ...
	{
		state = doCH__COMMAND->Set__DATA("ComInit");

		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			if(state == OBJ_RETRY)			goto LOOP_RETRY;
			else							return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}
	*/

	Fnc__APP_LOG("[INIT] Mode --> HOME Start");
	if(Fnc__HOME(p_variable, p_alarm) < 0)
	{
		return -1;
	}

	return 1;
}

// Pick -----
int  CObj__VacRobot_PSK
::Call__PICK(CII_OBJECT__VARIABLE* p_variable,
		     CII_OBJECT__ALARM* p_alarm,
		     const CString& stn_name,
		     const CString& arm_type,
		     const CString& stn_slot)
{
	int is_act_handoff;

	if(stn_name.Find("PM") >= 0)	is_act_handoff = ACTIVE_HAND_OFF;
	else							is_act_handoff = NORMAL;
	
	int r_flag = Fnc__PICK(p_variable,p_alarm, stn_name,arm_type,stn_slot,is_act_handoff);
	if(r_flag > 0)
	{
		if(iActive__SIM_MODE > 0)
		{
			if(arm_type.CompareNoCase(ARM_A) == 0)     dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Present");
			if(arm_type.CompareNoCase(ARM_B) == 0)     dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Present");
		}
	}

	return r_flag;
}

int  CObj__VacRobot_PSK
::Fnc__PICK(CII_OBJECT__VARIABLE* p_variable,
		    CII_OBJECT__ALARM* p_alarm,
		    const CString& stn_name,
		    const CString& arm_type,
		    const CString& stn_slot,
		    const int is_act_handoff)
{
	if(Is__LOCAL(p_alarm)   < 0)		return -11;
	if(Is__OFFLINE(p_alarm) < 0)		return -12;

	// ...
	{
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)			doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)			doCH__STN_B->Set__DATA(str__trg_stn_num);

		doCH__SLOT->Set__DATA(stn_slot);
	}

	// ...
	int state = -1;

	// Action : PICK ...
	{
		     if(arm_type.CompareNoCase(ARM_A) == 0)			state = doCH__COMMAND->Set__DATA("APick");
		else if(arm_type.CompareNoCase(ARM_B) == 0)			state = doCH__COMMAND->Set__DATA("BPick");

		if(state < 0)						return -21;
		if(Is__OFFLINE(p_alarm) < 0)		return -22;
	}

	// ...
	{
		state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}
	}

	_Update__WFR_CEN_DATA(p_variable);
	return 1;
}

// Place -----
int  CObj__VacRobot_PSK
::Call__PLACE(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& stn_name,
			  const CString& arm_type,
			  const CString& stn_slot)
{

	int r_flag = Fnc__PLACE(p_variable,p_alarm, stn_name,arm_type,stn_slot);
	if(r_flag > 0)
	{
		if(iActive__SIM_MODE > 0)
		{
			if(arm_type.CompareNoCase(ARM_A) == 0)		dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Absent");
			if(arm_type.CompareNoCase(ARM_B) == 0)		dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Absent");
		}
	}
	return r_flag;
}

int  CObj__VacRobot_PSK
::Fnc__PLACE(CII_OBJECT__VARIABLE* p_variable,
		     CII_OBJECT__ALARM* p_alarm,
		     const CString& stn_name,
		     const CString& arm_type,
		     const CString& stn_slot)
{
	Fnc__ACT_MSG("Place Start...");

	if(Is__LOCAL(p_alarm)   < 0)		return -1;
	if(Is__OFFLINE(p_alarm) < 0)		return -1;

	// Set Station
	{
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);
	}

	// Set Slot
	doCH__SLOT->Set__DATA(stn_slot);

	// ...
	{
		int state = -1;

			 if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("APlace");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BPlace");

		if(state == 0)    // Abort
		{
			return -1;
		}
	
		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	_Update__WFR_CEN_DATA(p_variable);
	return 1;
}


// Rotate -----
int  CObj__VacRobot_PSK
::Call__ROTATE(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& para__stn_name, 
			   const CString& para__arm_type,
			   const CString& para__stn_slot)
{
	if(iActive__SIM_MODE > 0)
	{
		return Fnc__SIM_ROTATE(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);
	}

	return Fnc__ROTATE(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);
}

int  CObj__VacRobot_PSK
::Fnc__SIM_ROTATE(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm,
				  const CString& stn_name, 
				  const CString& arm_type,
				  const CString& stn_slot)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	double  cfg__rotate_time = 1.0;
	CString var_data;

	aCH__SIM_CFG__ROTATE_TIME->Get__DATA(var_data);
	cfg__rotate_time = atof(var_data);

	if(x_timer_ctrl->WAIT(cfg__rotate_time) < 0)
	{
		return -1;
	}

	return 1;
}
int  CObj__VacRobot_PSK
::Fnc__ROTATE(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& stn_name, 
			  const CString& arm_type,
			  const CString& stn_slot)
{
	Fnc__ACT_MSG("Rotate Start...");

	if(Is__LOCAL(p_alarm)   < 0)		return -1;
	if(Is__OFFLINE(p_alarm) < 0)		return -1;

	// ...
	{
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

			 if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);

		doCH__SLOT->Set__DATA(stn_slot);
	}

	// ...
	{
		CString str__zpos = "Down";

		if(arm_type.CompareNoCase(ARM_A) == 0)
		{
			if(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA("NONE") > 0)		str__zpos = "Down";
			else																		str__zpos = "Up";
		}
		else if(arm_type.CompareNoCase(ARM_B) == 0)
		{
			if(dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Check__DATA("NONE") > 0)		str__zpos = "Down";
			else																		str__zpos = "Up";
		}

		doCH__ZPOS->Set__DATA(str__zpos);
		doCH__RPOS->Set__DATA("Retract");		// 반드시 넣을것...
	}

	// ...
	{
		int state = -1;

			if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGoto");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGoto");

		if(state == 0)    // Abort
		{
			return -1;
		}
		
		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}


// Home -----
int  CObj__VacRobot_PSK
::Call__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	if(iActive__SIM_MODE > 0)
	{
		return Fnc__SIM_HOME(p_variable,p_alarm);
	}

	return Fnc__HOME(p_variable,p_alarm);
}

int  CObj__VacRobot_PSK
::Fnc__SIM_HOME(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	Sleep(1500);

	return 1;
}
int  CObj__VacRobot_PSK
::Fnc__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	Fnc__ACT_MSG("Home Start...");

	if(Is__LOCAL(p_alarm)   < 0)		return -1;
	if(Is__OFFLINE(p_alarm) < 0)		return -1;

	// ...
	{
		int state = state = doCH__COMMAND->Set__DATA("HomeAll");

		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			if(state == OBJ_RETRY)		goto LOOP_RETRY;
			else						return -1;
		}
		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}


// Map -----
int  CObj__VacRobot_PSK
::Call__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	return Fnc__MAP(p_variable,p_alarm);
}


// Extend -----
int  CObj__VacRobot_PSK
::Call__EXTEND(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& stn_name, 
			   const CString& arm_type,
			   const CString& stn_slot,
			   const int is_active_handoff)
{

	return Fnc__EXTEND(p_variable,p_alarm, stn_name, arm_type, stn_slot, is_active_handoff);
}


// Retract -----
int  CObj__VacRobot_PSK
::Call__RETRACT(CII_OBJECT__VARIABLE* p_variable,
			    CII_OBJECT__ALARM* p_alarm,
			    const CString& stn_name, 
			    const CString& arm_type,
			    const CString& stn_slot,
			    const int is_active_handoff)
{
	int r_flag = Fnc__RETRACT(p_variable,p_alarm, stn_name,arm_type,stn_slot,is_active_handoff);

	if(r_flag > 0)
	{
		_Update__WFR_CEN_DATA(p_variable);
	}
	return r_flag;
}


// Goup -----
int  CObj__VacRobot_PSK
::Call__GOUP(CII_OBJECT__VARIABLE* p_variable,
		     CII_OBJECT__ALARM* p_alarm,
		     const CString& stn_name, 
		     const CString& arm_type,
		     const CString& stn_slot)
{
	return Fnc__GOUP(p_variable,p_alarm, stn_name, arm_type, stn_slot);
}

// GoDown -----
int  CObj__VacRobot_PSK
::Call__GODOWN(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
		  	   const CString& stn_name, 
			   const CString& arm_type,
			   const CString& stn_slot)
{
	return Fnc__GODOWN(p_variable,p_alarm, stn_name, arm_type, stn_slot);
}


// -----
int  CObj__VacRobot_PSK
::Fnc__SIM_MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	diCH__COMM_STS->Set__DATA(STR__ONLINE);
	return 1;
}
int  CObj__VacRobot_PSK
::Fnc__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	// ...
	{
		Fnc__ACT_MSG("Map Start...");

		if(Is__LOCAL(p_alarm)   < 0)		return -1;
		if(Is__OFFLINE(p_alarm) < 0)		return -1;
	}

	// ...
	{
		doCH__COMMAND->Set__DATA("ChkLoad.All");
	}

	/*
	// ...
	{
		int state = doCH__COMMAND->Set__DATA("ChkLoadA");
	
		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			if(state == OBJ_RETRY)		goto LOOP_RETRY;
			else						return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = doCH__COMMAND->Set__DATA("ChkLoadB");
		
		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			if(state == OBJ_RETRY)		goto LOOP_RETRY;
			else						return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}
	*/

	// INF Update -----
	CString str__wfr_sts;
	CString var_data;

	// if(iActive__SIM_MODE > 0)
	{
		if(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)
			dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Absent");
		else
			dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Present");

		if(dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Check__DATA(STR__NONE) > 0)
			dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Absent");
		else
			dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Present");
	}

	/*
	// A ARM ----- 
	{
		dCH__DRV_INFO_ARM_A_MAT_READ->Get__DATA(var_data);

			 if(var_data.CompareNoCase("Present") == 0)		str__wfr_sts = "EXIST";
		else if(var_data.CompareNoCase("Absent")  == 0)		str__wfr_sts = "NONE";
		else												str__wfr_sts = "UNKNOWN";

		dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Get__DATA(var_data);

		if(((str__wfr_sts.CompareNoCase("EXIST") == 0) && (var_data.CompareNoCase("NONE") == 0))	  
		|| ((str__wfr_sts.CompareNoCase("NONE")  == 0) && (var_data.CompareNoCase("NONE") != 0)))
		{
			int alarm_id = ALID__VACRB1_MATERIAL_DIFFERENT_INFO;

			CString r_act;
			CString s_msg;

			s_msg.Format("ARM_A Mapping Result Is ==>  \nSensor Status [%s], Material Status [%s]\n", str__wfr_sts, var_data);
			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, s_msg, r_act);

			if(r_act.CompareNoCase("ABORT") == 0)
			{
				return OBJ_ABORT;
			}

			// Option : Abort, Yes 를 누르면 H/W 센서정보로 Update !!
			dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(str__wfr_sts);
		}
	}

	// B ARM ----- 
	{
		dCH__DRV_INFO_ARM_B_MAT_READ->Get__DATA(var_data);

		     if(var_data.CompareNoCase("Present") == 0)		str__wfr_sts = "EXIST";
		else if(var_data.CompareNoCase("Absent")  == 0)		str__wfr_sts = "NONE";
		else												str__wfr_sts = "UNKNOWN";

		dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Get__DATA(var_data);

		if(((str__wfr_sts.CompareNoCase("EXIST") == 0) && (var_data.CompareNoCase("NONE") == 0))
		|| ((str__wfr_sts.CompareNoCase("NONE")  == 0) && (var_data.CompareNoCase("NONE") != 0)))
		{
			int alarm_id = ALID__VACRB1_MATERIAL_DIFFERENT_INFO;

			CString r_act;
			CString s_msg;

			s_msg.Format("ARM_B Mapping Result Is ==> Sensor Status [%s], Material Status [%s]\n", str__wfr_sts, var_data);
			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, s_msg, r_act);

			if(r_act.CompareNoCase("ABORT") == 0)
			{
				return OBJ_ABORT;
			}

			// Option : Abort, Yes 를 누르면 H/W 센서정보로 Update !!
			dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Set__DATA(str__wfr_sts);
		}
	}
	*/

	return 1;
}

int  CObj__VacRobot_PSK
::Fnc__EXTEND(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& stn_name,
			  const CString& arm_type,
			  const CString& stn_slot,
			  const int is_active_handoff)
{
	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	double  cfg__sim_time = 1.0;
	CString var_data;
	CString str_log;

	// ...
	{
		Fnc__ACT_MSG("EXTEND Start...");

		if(Is__LOCAL(p_alarm)   < 0)		return -1;
		if(Is__OFFLINE(p_alarm) < 0)		return -1;
	}

	// ...
	{
		// Set Station 
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);

		// Set Slot
		doCH__SLOT->Set__DATA(stn_slot);

		// Extend
		doCH__RPOS->Set__DATA("Extend");
	}

	// ...
	{
		CString str__zpos = "Down";

		if(arm_type.CompareNoCase(ARM_A) == 0)
		{
			if(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA("NONE") > 0)
				str__zpos = "Down";
			else
				str__zpos = "Up";
		}
		else if(arm_type.CompareNoCase(ARM_B) == 0)
		{
			if(dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Check__DATA("NONE") > 0)
				str__zpos = "Down";
			else
				str__zpos = "Up";
		}

		if(stn_name.Find("PM") >= 0)
		{
			if(is_active_handoff == ACTIVE_HAND_OFF)
			{
				doCH__ZPOS->Set__DATA("Down");
			}
		}
		else
		{
			doCH__ZPOS->Set__DATA(str__zpos);
		}
	}

	if(iActive__SIM_MODE > 0)
	{
		aCH__SIM_CFG__EXTEND_TIME->Get__DATA(var_data);
		cfg__sim_time = atof(var_data);
		
		if(x_timer_ctrl->WAIT(cfg__sim_time) < 0)
		{
			return -1;
		}
		return 1;
	}

	// ...
	{
		int state = -1;

		// Action : [AGoto, BGoto]	
		     if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGoto");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGoto");

		str_log.Format("Extend.. Command Ret : %d", state);	
		Fnc__ACT_MSG(str_log);
		
		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		str_log.Format("Extend..Error Exist Check Ret : %d", state);	
		Fnc__ACT_MSG(str_log);
		
		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}

int  CObj__VacRobot_PSK
::Fnc__RETRACT(CII_OBJECT__VARIABLE* p_variable,
			   CII_OBJECT__ALARM* p_alarm,
			   const CString& para__stn_name, 
			   const CString& para__arm_type,
			   const CString& para__stn_slot,
			   const int is_active_handoff)
{
	CString set_ro_offset;
	CString set_to_offset;
	CString str_log;

	if(dCH__CFG_DA_SENSOR_TYPE->Check__DATA(STR__YES) > 0)
	{
		// 1. SET CPTR OFF
		{
			Fnc__APP_LOG("Start Sensor Off");

			int nRet = Set__CPTR_SNS_OFF_N(p_variable, p_alarm, para__arm_type, para__stn_name, para__stn_slot);

			str_log.Format("End Sensor Off (Result %d)", nRet);
			Fnc__APP_LOG(str_log);

			if(nRet <= 0)		return OBJ_ABORT;
		}

		// 2. SET CPTR ON
		{
			Fnc__APP_LOG("Start Sensor On ");

			int nRet = Set__CPTR_SNS_ON_N(p_variable, p_alarm, para__arm_type, para__stn_name, para__stn_slot);

			str_log.Format("End Sensor On (Result %d)", nRet);
			Fnc__APP_LOG(str_log);

			if(nRet <= 0)		return OBJ_ABORT;
		}
	}

	// 3. RETRACT
	{
		int nRet = _Fnc__RETRACT(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot,is_active_handoff);

		if(nRet <= 0)		return OBJ_ABORT;
	}

	if(dCH__CFG_DA_SENSOR_TYPE->Check__DATA(STR__YES) > 0)
	{
		// 4. SET CPTR OFF
		{
			Fnc__APP_LOG("Start Sensor Off");

			int nRet = Set__CPTR_SNS_OFF_N(p_variable, p_alarm, para__arm_type, para__stn_name, para__stn_slot);

			str_log.Format("End Sensor Off (Result:%d)", nRet);
			Fnc__APP_LOG(str_log);

			if(nRet <= 0)		return OBJ_ABORT;
		}
	}

	return OBJ_AVAILABLE;
}

int  CObj__VacRobot_PSK
::_Fnc__RETRACT(CII_OBJECT__VARIABLE* p_variable,
			    CII_OBJECT__ALARM* p_alarm,
			    const CString& stn_name,
			    const CString& arm_type,
			    const CString& stn_slot,
			    const int is_active_handoff)
{	
	double  cfg__sim_time = 1.0;
	CString var_data;
	CString str_log;

	SCX__TIMER_CTRL x_timer_ctrl;
	x_timer_ctrl->REGISTER__ABORT_OBJECT(sObject_Name);

	// ...
	{
		Fnc__ACT_MSG("RETRACT Start...");

		if(Is__LOCAL(p_alarm)   < 0)		return -1;
		if(Is__OFFLINE(p_alarm) < 0)		return -1;
	}

	// ...
	{
		// Set Station
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);

		// Set Slot
		doCH__SLOT->Set__DATA(stn_slot);

		// Retract
		doCH__RPOS->Set__DATA("Retract");

		if(stn_name.Find("PM") >= 0)
		{
			if(is_active_handoff == ACTIVE_HAND_OFF)
			{
				doCH__ZPOS->Set__DATA("Down");
			}
		}

		if(iActive__SIM_MODE > 0)
		{
			aCH__SIM_CFG__RETRACT_TIME->Get__DATA(var_data);
			cfg__sim_time = atof(var_data);

			if(x_timer_ctrl->WAIT(cfg__sim_time) < 0)
			{
				return -1;
			}
			return 1;
		}
	}

	// ...
	{
		int state = -1;

		// Action : [AGoto, BGoto]	
			 if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGoto");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGoto");

		str_log.Format("Retract.. Command Ret : %d", state);
		Fnc__ACT_MSG(str_log);
		
		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		str_log.Format("Retract..Error Exist Check Ret : %d", state);	
		Fnc__ACT_MSG(str_log);
		
		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	return 1;
}

int  CObj__VacRobot_PSK
::Fnc__GOUP(CII_OBJECT__VARIABLE* p_variable,
		    CII_OBJECT__ALARM* p_alarm,
		    const CString& stn_name,
		    const CString& arm_type,
		    const CString& stn_slot)
{
	Fnc__ACT_MSG("GOUP Start...");
	Fnc__APP_LOG("GOUP Start...");

	if(Is__LOCAL(p_alarm)   < 0)		return -1;
	if(Is__OFFLINE(p_alarm) < 0)		return -1;

	// ...
	{
		// Set Station
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);

		// Set Slot
		doCH__SLOT->Set__DATA(stn_slot);

		doCH__ZPOS->Set__DATA("Up");
	}

	// ...
	{
		int state = -1;

		// Action : [AGoto, BGoto]	
			 if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGoto");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGoto");

		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	Fnc__APP_LOG("GOUP Complete...");
	return 1;
}

int  CObj__VacRobot_PSK
::Fnc__GODOWN(CII_OBJECT__VARIABLE* p_variable,
			  CII_OBJECT__ALARM* p_alarm,
			  const CString& stn_name,
			  const CString& arm_type,
			  const CString& stn_slot)
{
	Fnc__ACT_MSG("GODOWN Start...");
	Fnc__APP_LOG("GODOWN Start...");

	if(Is__LOCAL(p_alarm)   < 0)		return -1;
	if(Is__OFFLINE(p_alarm) < 0)		return -1;

	// ...
	{
		// Set Station
		CString str__trg_stn_num = Get__CFG_STN_NUM(stn_name, stn_slot);

		     if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__STN_A->Set__DATA(str__trg_stn_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__STN_B->Set__DATA(str__trg_stn_num);

		// Set Slot
		doCH__SLOT->Set__DATA(stn_slot);

		// 
		doCH__ZPOS->Set__DATA("Down");
	}

	// ...
	{
		int state = -1;

		// Action : [AGoto, BGoto]	
		     if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGoto");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGoto");

		if(state == 0)    // Abort
		{
			return -1;
		}

		if(Is__OFFLINE(p_alarm) < 0)
		{
			return -1;
		}
	}

	// ...
	{
		int state = Is__ERROR_EXIST(p_alarm);

		if(state != OBJ_AVAILABLE)
		{
			return -1;
		}

		if(p_variable->Check__CTRL_ABORT() > 0)
		{
			return -1;
		}
	}

	Fnc__APP_LOG("GODOWN Complete...");
	return 1;
}


// ...
int  CObj__VacRobot_PSK
::Call__TEST_DA_REPORT(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	_Update__WFR_CEN_DATA(p_variable);
	return 1;
}

