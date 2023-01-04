#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "math.h"
#include "CCommon_DEF.h"

#include "Macro_Function.h"


//------------------------------------------------------------------------------------
void CObj__VacRobot_PSK
::Fnc__ACT_MSG(const CString& act_msg)
{
	sCH__ACT_MSG->Set__DATA(act_msg);
}

void CObj__VacRobot_PSK
::Fnc__APP_LOG(const CString& log_msg)
{
	if(iFlag__APP_LOG < 1)		return;

	xAPP_LOG_CTRL->WRITE__LOG(log_msg);
}

void CObj__VacRobot_PSK
::Fnc__DRV_LOG(const CString& log_msg)
{
	if(iFlag__DRV_LOG < 1)		return;

	xDRV_LOG_CTRL->WRITE__LOG(log_msg);
}

int CObj__VacRobot_PSK
::Set__CPTR_SNS_OFF_N(CII_OBJECT__VARIABLE* p_variable,
				      CII_OBJECT__ALARM* p_alarm,
				      const CString& arm_type,
				      const CString& stn_name,
					  const CString& slot_id)
{	
	int state;
	int state2;
	CString str_log;

	Fnc__APP_LOG("[Set__CPTR_SNS_OFF_N] Start...");

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name, slot_id);
	
		     if(arm_type.CompareNoCase(ARM_A) == 0)			doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)			doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
	}

	// 2. CPTR SET OFF
	if(arm_type.CompareNoCase(ARM_A) == 0)
	{
		Fnc__APP_LOG("ASet_Cptr_Off...cmd Start..");
		state = doCH__COMMAND->Set__DATA("ASet_Cptr_Off");
	}
	else if(arm_type.CompareNoCase(ARM_B) == 0)
	{
		Fnc__APP_LOG("BSet_Cptr_Off...cmd Start..");
		state = doCH__COMMAND->Set__DATA("BSet_Cptr_Off");
	}
	
	Fnc__APP_LOG("--> SET CPTR 21 OFF");
	state2 = doCH__COMMAND->Set__DATA("SET_CPTR_21_OFF");
	
	str_log.Format("1. Command Ret: (A or B sensor)%d, (21 sensor)%d", state, state2);
	Fnc__APP_LOG(str_log);
	if(state == 0 || state2 == 0)	return -1;		// Abort
	
	Fnc__APP_LOG("Checking Offline Status");
	if(Is__OFFLINE(p_alarm) < 0)	return -1;
	
	Fnc__APP_LOG("Checking Error Existence");
	if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)	return -1;
	
	Fnc__APP_LOG("Checking Ctrl Abort Status");
	if(p_variable->Check__CTRL_ABORT() > 0)			return -1;
	
	Fnc__APP_LOG("[Set__CPTR_SNS_OFF_N] End...");
	
	return 1;
}

int CObj__VacRobot_PSK
::Set__CPTR_SNS_ON_N(CII_OBJECT__VARIABLE* p_variable,
				     CII_OBJECT__ALARM* p_alarm,
				     const CString& arm_type,
				     const CString& stn_name,
					 const CString& slot_id)
{	
	CString str_log;

	Fnc__APP_LOG("[Set__CPTR_SNS_ON_N] Start...");

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name, slot_id);
	
		if(arm_type.CompareNoCase(ARM_A) == 0)			doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
	}
	
	// 2. CPTR SET ON
	{
		Fnc__APP_LOG("--> SET CPTR 21 ON");

		int state = doCH__COMMAND->Set__DATA("SET_CPTR_21_ON");
	
		str_log.Format("2. Command Ret:%d", state);
		Fnc__APP_LOG(str_log);
		
		if(state == 0)	return -1;		// Abort
	}

	if(Is__OFFLINE(p_alarm) < 0)						return -1;
	if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)		return -1;
	if(p_variable->Check__CTRL_ABORT() > 0)				return -1;
	
	Fnc__APP_LOG("[Set__CPTR_SNS_ON_N] End...");
	return 1;
}
