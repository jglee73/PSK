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
::Set__CPTR_SNS_OFF_ON(CII_OBJECT__VARIABLE* p_variable,
					   CII_OBJECT__ALARM* p_alarm,
		               const CString& arm_type,
		               const CString& stn_name)
{
	CString str_log;

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name);

			 if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
	}

	// 2. CPTR SET OFF
	{
		int state = -1;

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
	
		str_log.Format("1. Command Ret:%d", state);
		Fnc__APP_LOG(str_log);
	
		if(state <= 0)
		{
			return -1;		// Abort
		}
	}

	if(Is__OFFLINE(p_alarm) < 0)					return -1;
	if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)	return -1;
	if(p_variable->Check__CTRL_ABORT() > 0)			return -1;

	// 2. CPTR SET ON
	{
		int state = -1;

		if(arm_type.CompareNoCase(ARM_A) == 0)
		{
			Fnc__APP_LOG("ASet_Cptr_On...cmd Start..");
			state = doCH__COMMAND->Set__DATA("ASet_Cptr_On");
		}
		else if(arm_type.CompareNoCase(ARM_B) == 0)
		{
			Fnc__APP_LOG("BSet_Cptr_On...cmd Start..");
			state = doCH__COMMAND->Set__DATA("BSet_Cptr_On");
		}
	
		str_log.Format("2. Command Ret:%d", state);
		Fnc__APP_LOG(str_log);
	
		if(state <= 0)
		{
			return -1;		// Abort
		}
	}

	if(Is__OFFLINE(p_alarm) < 0)					return -1;
	if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)	return -1;
	if(p_variable->Check__CTRL_ABORT() > 0)			return -1;

	return 1;
}

int CObj__VacRobot_PSK
::Set__CPTR_SNS_OFF_N(CII_OBJECT__VARIABLE* p_variable,
				      CII_OBJECT__ALARM* p_alarm,
				      const CString& arm_type,
				      const CString& stn_name)
{	
	int state;
	int state2;
	CString str_log;

	Fnc__APP_LOG("[Set__CPTR_SNS_OFF_N] Start...");

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name);
	
		if(arm_type.CompareNoCase(ARM_A) == 0)			doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
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
				     const CString& stn_name)
{	
	CString str_log;

	Fnc__APP_LOG("[Set__CPTR_SNS_ON_N] Start...");

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name);
	
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

// ELO307 : �ݴ��� Arm�� Wafer ���� ��...
int CObj__VacRobot_PSK
::Get__CPTR_SNS(CII_OBJECT__VARIABLE* p_variable,
			    CII_OBJECT__ALARM* p_alarm,
		        const CString& arm_type,
		        const CString& stn_name,
			    const CString& act_type)
{
	CString str_sns_val;

	char *token;
	CString szTokenData;
	char szGetData[512];
	char seps[] = " ";
	int  i = 0;

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name);

			 if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
	}

	// 2. Get CPTR Val
	{
		int state = -1;

			 if(arm_type.CompareNoCase(ARM_A) == 0)		state = doCH__COMMAND->Set__DATA("AGet_Cptr");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		state = doCH__COMMAND->Set__DATA("BGet_Cptr");

		if(state <= 0)
		{
			return -1;		// Abort
		}

		if(Is__OFFLINE(p_alarm) < 0)					return -1;
		if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)	return -1;
		if(p_variable->Check__CTRL_ABORT() > 0)			return -1;
	}

	// 3. Value Parsing..
	{
		sCH__CPTR_SNS_FULL_VAL->Get__DATA(str_sns_val);
		Fnc__APP_LOG(str_sns_val);
	}

	// ...
	int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

	if(iCFG__SIM_FLAG > 0)
	{
		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			if(arm_type.CompareNoCase(ARM_B) == 0)
			{
				str_sns_val = "CPTR R 0587102 T 0330292 Z 0013842 H<cr>CPTR R 0587103 T 0330393 Z 0013843 L<cr>";
			}
			else
			{
				str_sns_val = "CPTR R 0777101 T 0330291 Z 0013841 H<cr>CPTR R 0777101 T 0330291 Z 0013841 L<cr>CPTR R 0587102 T 0330292 Z 0013842 H<cr>CPTR R 0587103 T 0330393 Z 0013843 L<cr>";
			}
		}
		else
		{
			str_sns_val = "CPTR R 0777101 T 0330291 Z 0013841 L<cr>CPTR R 0587102 T 0330292 Z 0013842 H<cr>CPTR R 0587103 T 0330393 Z 0013843 L<cr>";
		}		
	}
	
	if(str_sns_val.CompareNoCase("CPTR NOT TRIGGERED") == 0)
	{
		return 1;
	}

	strcpy(szGetData, str_sns_val);
	token = strtok(szGetData, seps);

	while(token != NULL)
	{	
		szTokenData = token;
		
		if(act_type.CompareNoCase("EXTEND") == 0)
		{
			if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
			{
				if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					if(i == 2) sCH__CPTR_ARM_B_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 4) sCH__CPTR_ARM_B_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 6) sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);

					if(i == 9)  sCH__CPTR_ARM_B_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 11) sCH__CPTR_ARM_B_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 13) sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
				else
				{
					if(i == 16) sCH__CPTR_ARM_A_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 18) sCH__CPTR_ARM_A_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 20) sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);

					if(i == 23) sCH__CPTR_ARM_A_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 25) sCH__CPTR_ARM_A_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 27) sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}				
			}
			else
			{
				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					if(i == 9)  sCH__CPTR_ARM_A_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 11) sCH__CPTR_ARM_A_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 13) sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);
					
					// RETRACT... LOW Sns
					if(i == 16) sCH__CPTR_ARM_A_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 18) sCH__CPTR_ARM_A_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 20) sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
				else	// ARM_B
				{
					if(i == 9)  sCH__CPTR_ARM_B_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 11) sCH__CPTR_ARM_B_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 13) sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);
					
					// RETRACT... LOW Sns
					if(i == 16) sCH__CPTR_ARM_B_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 18) sCH__CPTR_ARM_B_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 20) sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}				
			}
		}
		else
		{
			if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
			{
				if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					// ELO307 : ARM_A��  Wafer ���� ��...
					if(i == 2) sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 4) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 6) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);

					if(i == 9)  sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 11) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 13) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
				else
				{
					if(i == 16) sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 18) sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 20) sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);

					if(i == 23) sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 25) sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 27) sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
				}				
			}
			else
			{
				if( (arm_type.CompareNoCase(ARM_B) == 0) 
				&&  (dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Check__DATA("NONE") > 0) )
				{
					// PM2���� Arm B�� A arm�� Wafer�� ������, �ڸ����� Ʋ����..
					if(i == 2) sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 4) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
					if(i == 6) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);

					if(i == 9)  sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 11) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
					if(i == 13) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
					
				}
				else
				{
					if(arm_type.CompareNoCase(ARM_A) == 0)
					{
						// RETRACT... HIGH Sns
						if(i == 9)  sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
						if(i == 11) sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
						if(i == 13) sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);
						
						// RETRACT... LOW Sns
						if(i == 16) sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
						if(i == 18) sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
						if(i == 20) sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
					}
					else	// ARM_B
					{
						// RETRACT... HIGH Sns
						if(i == 9)  sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
						if(i == 11) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
						if(i == 13) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);
						
						// RETRACT... LOW Sns
						if(i == 16) sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
						if(i == 18) sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
						if(i == 20) sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
					}
					
				}
			}
		}
		i++;
		
		/* Get next token: */
		token = strtok( NULL, seps);	
	}

	return 1;
}


int CObj__VacRobot_PSK
::Get__CPTR_SNS_N(CII_OBJECT__VARIABLE* p_variable,
			      CII_OBJECT__ALARM* p_alarm,
		          const CString& arm_type,
		          const CString& stn_name,
			      const CString& act_type)
{
	CString strMsg;
	
	int state;
	CString str__trg_cptr_num;
	CString str_sns_val;

	char *token;
	CString szTokenData;
	char szGetData[1024];
	char seps[] = " ";
	int  i = 0;

	// ...
	Fnc__APP_LOG("[Get__CPTR_SNS_N] Start...");

	// 1. Set Station cptr num...
	{
		CString str__trg_cptr_num = Get__CFG_STN_CPTR_NUM(stn_name);

			 if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__CPTR_STN_A->Set__DATA(str__trg_cptr_num);
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__CPTR_STN_B->Set__DATA(str__trg_cptr_num);
	}

	if(dCH__CFG_DA_SENSOR_TYPE->Check__DATA(STR__YES) > 0)
	{
		// 2. Get CPTR Val
		doCH__COMMAND->Set__DATA("GET_CPTR_21");
	}
	else
	{
		/*
			 if(arm_type.CompareNoCase(ARM_A) == 0)		doCH__COMMAND->Set__DATA("AGet.WAF_CEN");
		else if(arm_type.CompareNoCase(ARM_B) == 0)		doCH__COMMAND->Set__DATA("BGet.WAF_CEN");
		*/

		doCH__COMMAND->Set__DATA("WAF_CEN.DATA");
	}

	// ...
	{
		if(Is__OFFLINE(p_alarm) < 0)						return -1;
		if(Is__ERROR_EXIST(p_alarm) != OBJ_AVAILABLE)		return -1;
		if(p_variable->Check__CTRL_ABORT() > 0)				return -1;
	}

	// 3. Value Parsing..
	{
		sCH__CPTR_SNS_FULL_VAL->Get__DATA(str_sns_val);
		Fnc__APP_LOG(str_sns_val);
	}

	// ...
	int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

	if(iCFG__SIM_FLAG > 0)
	{
		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			if(arm_type.CompareNoCase(ARM_B) == 0 && act_type.CompareNoCase("RETRACT") == 0)
			{
				str_sns_val = "CPTR R 0585663 T 0330076 Z 0024097 H<cr>CPTR R 0547797 T 0330069 Z 0024097 L<cr>CPTR R 0378922 T 0330075 Z 0024098 H<cr>CPTR R 0340612 T 0330069 Z 0024098 L<cr>";
			}
			else if(arm_type.CompareNoCase(ARM_A) == 0 && act_type.CompareNoCase("RETRACT") == 0)
			{
				str_sns_val = "CPTR R 0768585 T 0330006 Z 0018673 H<cr>CPTR R 0768234 T 0330008 Z 0023672 L<cr>CPTR R 0586188 T 0330001 Z 0023673 H<cr>CPTR R 0548213 T 0330009 Z 0023674 L<cr>CPTR R 0379020 T 0330008 Z 0023675 H<cr>CPTR R 0341090 T 0330002 Z 0023676 L<cr>";
			}

			else if(arm_type.CompareNoCase(ARM_B) == 0 && act_type.CompareNoCase("EXTEND") == 0)
			{
				str_sns_val = "CPTR R 0340612 T 0330069 Z 0024098 L<cr>CPTR R 0378922 T 0330075 Z 0024098 H<cr>CPTR R 0547797 T 0330069 Z 0024097 L<cr>CPTR R 0585663 T 0330076 Z 0024097 H<cr>";
			}
			else if(arm_type.CompareNoCase(ARM_A) == 0 && act_type.CompareNoCase("EXTEND") == 0)
			{
				str_sns_val = "CPTR R 0341090 T 0330002 Z 0023676 L<cr>CPTR R 0379020 T 0330008 Z 0023675 H<cr>CPTR R 0548213 T 0330009 Z 0023674 L<cr>CPTR R 0586188 T 0330001 Z 0023673 H<cr>CPTR R 0768234 T 0330008 Z 0023672 L<cr>CPTR R 0768585 T 0330006 Z 0018673 H<cr>";
			}
		}
		else
		{
			str_sns_val = "CPTR R 0777101 T 0330291 Z 0013841 L<cr>CPTR R 0587102 T 0330292 Z 0013842 H<cr>CPTR R 0587103 T 0330393 Z 0013843 L<cr>"; // <-- old da data. should be replace as new da data
		}
	}
	
	if(str_sns_val.CompareNoCase("CPTR NOT TRIGGERED") == 0)
	{
		return 1;
	}

	// Find number of data as token
	char szTempData[1024];
	char *tempToken;

	strcpy(szTempData, str_sns_val);
	tempToken = strtok(szTempData, seps);

	int nItemNo = 0;

	while(tempToken != NULL)
	{
		szTokenData = tempToken;
		nItemNo++;
		tempToken = strtok(NULL, seps);
	}

	// Fine items
	strcpy(szGetData, str_sns_val);
	token = strtok(szGetData, seps);

	while(token != NULL)
	{	
		szTokenData = token;

		if(act_type.CompareNoCase("EXTEND") == 0)
		{
			// Align Sensor sensing firstly
			if(i == 9)
			{
				strMsg.Format("Align Sensor R H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
				
				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_R_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
			}								
			if(i == 11)	
			{
				strMsg.Format("Align Sensor T H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
				
				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_T_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
			}	
			if(i == 13)	
			{
				strMsg.Format("Align Sensor Z H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_LOW->Set__DATA(szTokenData);
				}
			}
			// Align Sensor sensing secondly
			if(i == 16)	
			{
				strMsg.Format("Align Sensor R L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_R_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}
			if(i == 18)	
			{
				strMsg.Format("Align Sensor T L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_T_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}	
			if(i == 20)	
			{
				strMsg.Format("Align Sensor Z L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}
			
			// Present Sensor sensing firstly
			if(i == 2)	
			{
				strMsg.Format("Present Sensor R L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == 4)	
			{
				strMsg.Format("Present Sensor T L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == 6)	
			{
				strMsg.Format("Present Sensor Z L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}			
			// Present Sensor sensing secondly
			if(i == 23)	
			{
				strMsg.Format("Present Sensor R H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == 25)	
			{
				strMsg.Format("Present Sensor T H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == 27)	
			{
				strMsg.Format("Present Sensor Z H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
		}
		else // RETRACT
		{
			// Align Sensor sensing firstly
			if(i == nItemNo-20)
			{
				strMsg.Format("Align Sensor R H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
				
				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}								
			if(i == nItemNo-18)	
			{
				strMsg.Format("Align Sensor T H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
				
				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}	
			if(i == nItemNo-16)	
			{
				strMsg.Format("Align Sensor Z H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Set__DATA(szTokenData);
				}
			}
			// Align Sensor sensing secondly
			if(i == nItemNo-13)	
			{
				strMsg.Format("Align Sensor R L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
			}
			if(i == nItemNo-11)	
			{
				strMsg.Format("Align Sensor T L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
			}	
			if(i == nItemNo-9)	
			{
				strMsg.Format("Align Sensor Z L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);

				if(arm_type.CompareNoCase(ARM_A) == 0)
				{
					sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
				else if(arm_type.CompareNoCase(ARM_B) == 0)
				{
					sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Set__DATA(szTokenData);
				}
			}
			
			// Present Sensor sensing firstly
			if(i == nItemNo-27)	
			{
				strMsg.Format("Present Sensor R H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == nItemNo-25)	
			{
				strMsg.Format("Present Sensor T H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == nItemNo-23)	
			{
				strMsg.Format("Present Sensor Z H:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			// Present Sensor sensing secondly
			if(i == nItemNo-6)	
			{
				strMsg.Format("Present Sensor R L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == nItemNo-4)	
			{
				strMsg.Format("Present Sensor T L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
			if(i == nItemNo-2)	
			{
				strMsg.Format("Present Sensor Z L:%s\n", szTokenData);
				Fnc__APP_LOG(strMsg);
			}	
		}
		i++;
		
		/* Get next token: */
		token = strtok( NULL, seps);	
	}

	Fnc__APP_LOG("[Get__CPTR_SNS_N] End...");
	return 1;
}

void CObj__VacRobot_PSK
::Calculation_Sns_Val(double caled_r_hi, double caled_t_hi, double caled_z_hi,
					  double caled_r_lo, double caled_t_lo, double caled_z_lo,
					  double r_hi, double t_hi, double z_hi,
					  double r_lo, double t_lo, double z_lo,
					  double &r_tune_val,
					  double &t_tune_val,
					  const CString& stn_name) 
{
	double circle_ban_jirum = 150;		// wafer 300mm ����..
	
	// Retract �� �������� �Ѵ�.
	/* RQ CPTR 2 : LL1
	*  CPTR R 0586754 T 0330299 Z 0013834 H
	*  CPTR R 0340957 T 0330299 Z 0013834 L
	*/

	// 1 micron = 10�� -3�� mm �̴�.
	// --------------------------------------------------------------------
	double ki_jun_r_high_val = caled_r_hi*0.001;	// ������ microns�̹Ƿ� .. ������ 1000�Ѵ�.
	double ki_jun_t_high_val = caled_t_hi*0.001;    // ���� ������ mm�� �ȴ�.
	double ki_jun_r_low_val  = caled_r_lo*0.001;    // t�� milidegree
	double ki_jun_t_low_val  = caled_t_lo*0.001;

	double r_sns_len = fabs(ki_jun_r_high_val - ki_jun_r_low_val);
	r_sns_len = r_sns_len*0.5;
	double x_val;
	
	x_val = pow(circle_ban_jirum, 2) - pow(r_sns_len, 2);
	x_val = sqrt(x_val);

	double ki_jun_result_t;
	double ki_jun_result_r;

	ki_jun_result_t = ki_jun_t_low_val+x_val;
	ki_jun_result_r = ki_jun_r_low_val+r_sns_len;

	CString str_result;
	str_result.Format("Station Name: %s 1. ���� ��ǥ.. R:%f,  T:%f",stn_name, ki_jun_result_r, ki_jun_result_t);
	Fnc__APP_LOG(str_result);

	// --------------------------------------------------------------------
	double real_r_high_val = r_hi*0.001;	// ���� : mm
	double real_t_high_val = t_hi*0.001;
	double real_r_low_val  = r_lo*0.001;
	double real_t_low_val  = t_lo*0.001;

	r_sns_len = fabs(real_r_high_val - real_r_low_val);
	r_sns_len = r_sns_len*0.5;
	double x_len;
	
	x_len = pow(circle_ban_jirum, 2) - pow(r_sns_len, 2);
	x_len = sqrt(x_len);

	double real_result_t;
	double real_result_r;

	real_result_t = real_t_low_val+x_len;
	real_result_r = real_r_low_val+r_sns_len;

	str_result.Format("Station Name: %s 2. ���� ��ǥ.. R:%f,  T:%f", stn_name, real_result_r, real_result_t);
	Fnc__APP_LOG(str_result);

	// --------------------------------------------------------------------
	double differ_r_val;
	double differ_t_val;

	differ_r_val = ki_jun_result_r - real_result_r;
	differ_t_val = ki_jun_result_t - real_result_t;

	str_result.Format("Station Name: %s 3. ���ش�� ���� ��.. R:%f mm,  T:%f mm", stn_name, differ_r_val, differ_t_val);
	Fnc__APP_LOG(str_result);

	// DA Chart �� Display !!
	CString str_r_val, str_t_val;
	
	str_r_val.Format("%f", differ_r_val*1000);
	str_t_val.Format("%f", differ_t_val*100);	// 1000�� ���ϴ°� �´°� ������. Lam ����� ����ϰ� DA Chart�� �ϴٺ���..

	CString data_log;
	char szPath[255];
	char data[255];
	
	CString path;
	CString file_time;
	
	SYSTEMTIME file_SystemTime;
	GetLocalTime(&file_SystemTime);
		
	file_time.Format("%04d_%02d_%02d",		
					 file_SystemTime.wYear,
					 file_SystemTime.wMonth,
					 file_SystemTime.wDay);

	// ...
	CString arm_type = dCH__OTR_IN_PARA__ARM_TYPE->Get__STRING();

	bool active__arm_a = false;
	bool active__arm_b = false;

		 if(arm_type.CompareNoCase(ARM_A)  == 0)			active__arm_a = true;
	else if(arm_type.CompareNoCase(ARM_B)  == 0)			active__arm_b = true;
	else if(arm_type.CompareNoCase(ARM_AB) == 0)
	{
		active__arm_a = true;
		active__arm_b = true;
	}

	// ...
	int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

	if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
	{
		int pm_id = pm_index + 1;

		if(active__arm_a)
		{
			sDA_PMC_CHART_ARM_A_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_ARM_A_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);
			dDA_PMC_CHART_ARM_A_UPDATE_FLAG_X[pm_index]->Set__DATA("ON");
	
			path = m_szRoot + "\\EQP_LOG\\DATALOG\\DA_Data\\" + file_time;
			CreateDirectory(path, NULL);

			data_log.Format("A/%s/%s ", str_r_val, str_t_val);
			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\PM%1d.TXT", m_szRoot, file_time, pm_id);

			FILE * fp = fopen(szPath, "a");
			if(fp != NULL)
			{
				sprintf(data, "%s\n",data_log);
				
				fprintf(fp, "%s\n", data);
				fclose(fp);
			}
		}
		if(active__arm_b)
		{
			sDA_PMC_CHART_ARM_B_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_ARM_B_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);
			dDA_PMC_CHART_ARM_B_UPDATE_FLAG_X[pm_index]->Set__DATA("ON");

			path = m_szRoot + "\\EQP_LOG\\DATALOG\\DA_Data\\" + file_time;
			CreateDirectory(path, NULL);
			
			data_log.Format("B/%s/%s ", str_r_val, str_t_val);
			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\PM%1d.TXT", m_szRoot, file_time, pm_id);

			FILE * fp = fopen(szPath, "a");			
			if(fp != NULL)
			{
				sprintf(data, "%s\n",data_log);
				
				fprintf(fp, "%s\n", data);
				fclose(fp);
			}
		}
	}

	// ...
	int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

	if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
	{	
		CString ll_name;

			 if(ll_index == 0)		ll_name = STR__LBA;
		else if(ll_index == 1)		ll_name = STR__LBB;
		else						ll_name.Format("LL%1d", ll_index+1);

		if(active__arm_a)
		{
			sDA_LL_CHART_ARM_A_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_ARM_A_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
			dDA_LL_CHART_ARM_A_UPDATE_FLAG_X[ll_index]->Set__DATA("ON");

			path = m_szRoot + "\\EQP_LOG\\DATALOG\\DA_Data\\" + file_time;			
			CreateDirectory(path, NULL);

			data_log.Format("A/%s/%s ", str_r_val, str_t_val);
			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\%s.TXT", m_szRoot, file_time, ll_name);

			FILE * fp = fopen(szPath, "a");
			if(fp != NULL)
			{
				sprintf(data, "%s\n",data_log);
				
				fprintf(fp, "%s\n", data);
				fclose(fp);
			}
		}
		if(active__arm_b)
		{
			sDA_LL_CHART_ARM_B_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_ARM_B_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
			dDA_LL_CHART_ARM_B_UPDATE_FLAG_X[ll_index]->Set__DATA("ON");
			
			path = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data\\"+file_time;
			CreateDirectory(path, NULL);
			
			data_log.Format("B/%s/%s ", str_r_val, str_t_val);
			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\%s.TXT", m_szRoot, file_time, ll_name);

			FILE * fp = fopen(szPath, "a");			
			if(fp != NULL)
			{
				sprintf(data, "%s\n",data_log);
				
				fprintf(fp, "%s\n", data);
				fclose(fp);
			}
		}
	}	

	// ...	
	differ_t_val = differ_t_val/775;		// 775�� Arm�� ����length�� ������ ...
	differ_t_val = differ_t_val/0.017452;	// sin1���� 0.017452 �̹Ƿ�...
	str_result.Format("Station Name: %s 4. �����ؾ��� ��.. R:%f mm,  T:%f degree", stn_name,-differ_r_val, differ_t_val);
	Fnc__APP_LOG(str_result);

	// For GUI Display !!
	CString str_data;
	str_data.Format("%f", -differ_r_val);
	sCH__Estimated_R_OFFSET->Set__DATA(str_data);

	str_data.Format("%f", differ_t_val);
	sCH__Estimated_T_OFFSET->Set__DATA(str_data);

	r_tune_val = -differ_r_val*1000;		// �տ��� 1000���� �������Ƿ�.. ���󺹱�..
	t_tune_val = differ_t_val*1000;
}

void CObj__VacRobot_PSK
::Calculation_Sns_Val_N(double caled_r_hi, double caled_t_hi, double caled_z_hi,
					    double caled_r_lo, double caled_t_lo, double caled_z_lo,
					    double r_hi, double t_hi, double z_hi,
					    double r_lo, double t_lo, double z_lo,
					    double &r_tune_val,
					    double &t_tune_val,
					    const CString& stn_name) 
{
	Fnc__APP_LOG("[Calculation_Sns_Val_N] Start...");

	CString strMsg;
	
	// Wafer Radius [micron]
	double dbl_wafer_radius = 150000.0; // [micron]
	
	// Get Reference Data
	double dbl_ref_r_h = caled_r_hi;
	double dbl_ref_t_h = caled_t_hi;
	double dbl_ref_z_h = caled_z_hi;
	double dbl_ref_r_l = caled_r_lo;
	double dbl_ref_t_l = caled_t_lo;
	double dbl_ref_z_l = caled_z_lo;
	
	// Get Current Data
	double dbl_cur_r_h = r_hi;
	double dbl_cur_t_h = t_hi;
	double dbl_cur_z_h = z_hi;
	double dbl_cur_r_l = r_lo;
	double dbl_cur_t_l = t_lo;
	double dbl_cur_z_l = z_lo;

	// Calculate Reference Variables
	double dbl_ref_A = (dbl_ref_r_h - dbl_ref_r_l) / 2.0;		// Half of sensing length [micron]
	double dbl_ref_Angle = acos(dbl_ref_A/dbl_wafer_radius);	// [radian]
	double dbl_ref_B = dbl_wafer_radius * sin(dbl_ref_Angle);	// distance from center to sensing point [micron]

	// Calculate Current Variables
	double dbl_cur_A = (dbl_cur_r_h - dbl_cur_r_l) / 2.0;		// Half of sensing length [micron]
	double dbl_cur_Angle = acos(dbl_cur_A/dbl_wafer_radius);	// [radian]
	double dbl_cur_B = dbl_wafer_radius * sin(dbl_cur_Angle);	// distance from center to sensing point [micron]
	
	double dbl_cur_temp_center_Y = (dbl_cur_r_h+dbl_cur_r_l)/2.0;
	double dbl_ref_temp_center_Y = (dbl_ref_r_h+dbl_ref_r_l)/2.0;

	if( (dbl_cur_temp_center_Y > dbl_ref_temp_center_Y) && (dbl_cur_A > dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on lowerY/rightX position\n");
	if( (dbl_cur_temp_center_Y > dbl_ref_temp_center_Y) && (dbl_cur_A < dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on lowerY/leftX position\n");
	if( (dbl_cur_temp_center_Y < dbl_ref_temp_center_Y) && (dbl_cur_A > dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on higherY/rightX position\n");
	if( (dbl_cur_temp_center_Y < dbl_ref_temp_center_Y) && (dbl_cur_A < dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on higherY/leftX position\n");
	
	if( (dbl_cur_temp_center_Y > dbl_ref_temp_center_Y) && (dbl_cur_A == dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on lowerY/centerX position\n");
	if( (dbl_cur_temp_center_Y < dbl_ref_temp_center_Y) && (dbl_cur_A == dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on higherY/centerX position\n");
	
	if( (dbl_cur_temp_center_Y == dbl_ref_temp_center_Y) && (dbl_cur_A > dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on centerY/rightX position\n");
	if( (dbl_cur_temp_center_Y == dbl_ref_temp_center_Y) && (dbl_cur_A < dbl_ref_A) ) Fnc__APP_LOG("current wafer exists on centerY/leftX position\n");

	// Calculate Offset X(horizontal), Y(Vertical)
	double dbl_offset_X = dbl_ref_B - dbl_cur_B;
	double dbl_offset_Y = (dbl_ref_r_h+dbl_ref_r_l)/2.0 - (dbl_cur_r_h+dbl_cur_r_l)/2.0;

	// Write log
	strMsg.Format("1. Ref. Data --> Distance from center to sensor X: (%f), Distance from center to sensor Y: (%f)", dbl_ref_B, dbl_ref_A);
	Fnc__APP_LOG(strMsg);
	strMsg.Format("2. Cur. Data --> Distance from center to sensor X: (%f), Distance from center to sensor Y: (%f)", dbl_cur_B, dbl_cur_A);
	Fnc__APP_LOG(strMsg);
	strMsg.Format("3. Offset from Reference --> X: (%f), Y:(%f)", dbl_offset_X, dbl_offset_Y);
	Fnc__APP_LOG(strMsg);

	// DA Chart �� Display !!
	CString str_r_val, str_t_val;
	str_r_val.Format("%.3f", dbl_offset_Y);
	str_t_val.Format("%.3f", dbl_offset_X);

	// For display
	aCH__RETRACT_R_OFFSET_VALUE->Set__DATA(str_r_val);
	aCH__RETRACT_T_OFFSET_VALUE->Set__DATA(str_t_val);

	// DA Offset ...
	sCH__DA_RESULT_R_OFFSET_DEG->Set__DATA(str_r_val);
	sCH__DA_RESULT_T_OFFSET_MM->Set__DATA(str_t_val);

	// ...
	CString data_log;
	char szPath[255];
	char data[255];
	
	CString file_time;
	
	SYSTEMTIME file_SystemTime;
	GetLocalTime(&file_SystemTime);
	
	file_time.Format("%04d_%02d_%02d",		
					 file_SystemTime.wYear,
					 file_SystemTime.wMonth,
					 file_SystemTime.wDay);
	
	CString path;
	CString str_val;

	CString strdirRoot[4];

	strdirRoot[0] = m_szRoot+"\\EQP_LOG\\";
	strdirRoot[1] = m_szRoot+"\\EQP_LOG\\DATALOG\\";
	strdirRoot[2] = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data";
	strdirRoot[3] = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data\\"+file_time;
	
	//// ���丮�� ������ ���丮�� ����
	for(int i =0; i < 4; i++)
	{
		Create_Directory(strdirRoot[i]);
	}

	SCX__FILE_CTRL x_file_ctrl;
	path = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data\\";
	
	x_file_ctrl->Delete__LOG_DIR(path,30);

	// ...
	CString arm_type = dCH__OTR_IN_PARA__ARM_TYPE->Get__STRING();

	bool active__arm_a = false;
	bool active__arm_b = false;

		 if(arm_type.CompareNoCase(ARM_A)  == 0)			active__arm_a = true;
	else if(arm_type.CompareNoCase(ARM_B)  == 0)			active__arm_a = true;
	else if(arm_type.CompareNoCase(ARM_AB) == 0)
	{
		active__arm_a = true;
		active__arm_b = true;
	}

	// ...
	int pm_index = Macro__CHECK_PMx_INDEX(stn_name);
	
	if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
	{
		int pm_id = pm_index + 1;

		if(active__arm_a)
		{
			sDA_PMC_CHART_ARM_A_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_ARM_A_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);	

			data_log.Format("A/%s/%s ", str_t_val,str_r_val);

			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\PM%1d.TXT", m_szRoot, file_time, pm_id);

			FILE * fp = fopen(szPath, "a");		
			if(fp != NULL)
			{
				sprintf(data, "%s",data_log);

				fprintf(fp, "%s", data);
				fclose(fp);
			}
		}
		if(active__arm_b)
		{
			sDA_PMC_CHART_ARM_B_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_ARM_B_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);

			data_log.Format("B/%s/%s ", str_t_val,str_r_val);	

			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\PM%1d.TXT", m_szRoot, file_time, pm_id);

			FILE * fp = fopen(szPath, "a");		
			if(fp != NULL)
			{
				sprintf(data, "%s",data_log);

				fprintf(fp, "%s", data);
				fclose(fp);
			}
		}

		if(dCH__CFG_PMx_DA_USE[0]->Check__DATA("YES") > 0)
		{
			sDA_PMC_CHART_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);
		}
		else
		{
			str_r_val = "0";
			str_t_val = "0";

			sDA_PMC_CHART_ROFFSET_DISPLAY_X[pm_index]->Set__DATA(str_r_val);
			sDA_PMC_CHART_TOFFSET_DISPLAY_X[pm_index]->Set__DATA(str_t_val);
		}
	}

	// ...
	int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

	if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
	{	
		CString ll_name;
		
			 if(ll_index == 0)			ll_name = "LBA";
		else if(ll_index == 1)			ll_name = "LBB";
		else							ll_name.Format("LL%1d", ll_index+1);

		if(active__arm_a)
		{
			sDA_LL_CHART_ARM_A_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_ARM_A_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
			dDA_LL_CHART_ARM_A_UPDATE_FLAG_X[ll_index]->Set__DATA("ON");
			
			data_log.Format("A/%s/%s ", str_t_val, str_r_val);

			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\%s.TXT", m_szRoot, file_time, ll_name);

			FILE * fp = fopen(szPath, "a");
			if(fp != NULL)
			{
				sprintf(data, "%s",data_log);

				fprintf(fp, "%s", data);
				fclose(fp);
			}
		}
		if(active__arm_b)
		{
			sDA_LL_CHART_ARM_B_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_ARM_B_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
			dDA_LL_CHART_ARM_B_UPDATE_FLAG_X[ll_index]->Set__DATA("ON");
			
			data_log.Format("B/%s/%s ", str_t_val, str_r_val);

			sprintf(szPath, "%s\\EQP_LOG\\DATALOG\\DA_Data\\%s\\%s.TXT", m_szRoot, file_time, ll_name);

			FILE * fp = fopen(szPath, "a");
			if(fp != NULL)
			{
				sprintf(data, "%s",data_log);

				fprintf(fp, "%s", data);
				fclose(fp);
			}
		}

		if (dCH__CFG_LLx_DA_USE[ll_index]->Check__DATA("YES") > 0)
		{
			sDA_LL_CHART_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
		}
		else
		{
			str_r_val = "0";
			str_t_val = "0";

			sDA_LL_CHART_ROFFSET_DISPLAY_X[ll_index]->Set__DATA(str_r_val);
			sDA_LL_CHART_TOFFSET_DISPLAY_X[ll_index]->Set__DATA(str_t_val);
		}
	}	

	r_tune_val = dbl_offset_Y;
	t_tune_val = dbl_offset_X;

	Fnc__APP_LOG("[Calculation_Sns_Val_N] End...");
}

int CObj__VacRobot_PSK
::Check_Offset_Range(const CString& stn_name, 
				     CII_OBJECT__VARIABLE* p_variable,
				     CII_OBJECT__ALARM* p_alarm,
				     const CPTR_TUNED_VAL set_cptr_tune_val)
{
	CString str_log;
	int alarm_id;
	CString r_act;
	CString alarm_msg;
	CString alarm_buf;

	CString str_r_range;
	CString str_t_range;

	CString str_r_soft;
	CString str_r_hard;

	CString str_t_soft;
	CString str_t_hard;

	double r_soft_max, r_soft_min;
	double r_hard_max, r_hard_min;

	double t_soft_max, t_soft_min;
	double t_hard_max, t_hard_min;

	Get__CFG_STN_OFFSET_RANGE_RET(stn_name, str_r_soft, str_r_hard, str_t_soft, str_t_hard);

	r_soft_max = atof(str_r_soft)*1000; r_soft_min = -atof(str_r_soft)*1000;   // mm�� microns�� ����..
	r_hard_max = atof(str_r_hard)*1000; r_hard_min = -atof(str_r_hard)*1000; 

	t_soft_max = atof(str_t_soft)*1000; t_soft_min = -atof(str_t_soft)*1000;   // mm�� microns�� ����..
	t_hard_max = atof(str_t_hard)*1000; t_hard_min = -atof(str_t_hard)*1000; 

	str_log.Format("Config R_SOFT_MAX:%f, R_SOFT_MIN:%f, T_SOFT_MAX:%f, T_SOFT_MIN:%f",
		            r_soft_max, r_soft_min, t_soft_max, t_soft_min);
	Fnc__APP_LOG(str_log);

	str_log.Format("Config R_HARD_MAX:%f, R_HARD_MIN:%f, T_HARD_MAX:%f, T_HARD_MIN:%f",
		            r_hard_max, r_hard_min, t_hard_max, t_hard_min);
	Fnc__APP_LOG(str_log);

	str_log.Format("Cptr Tune Val--> ro:%f, to:%f",
		            set_cptr_tune_val.ro_tuned_val, set_cptr_tune_val.to_tuned_val);
	Fnc__APP_LOG(str_log);

	// R Axis -- Warning !!
	if((set_cptr_tune_val.ro_tuned_val > r_hard_min) 
	&& (set_cptr_tune_val.ro_tuned_val < r_soft_min))
	{
		Fnc__APP_LOG("R Offset MIN Soft Alarm Occur..");

		// ...
		alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__SOFT_RANGE_ERROR;

		alarm_buf.Format("Config MIN_Range is HARD_MIN:%f < %f < SOFT_MIN:%f", 
						 r_hard_min, set_cptr_tune_val.ro_tuned_val, r_soft_min);
		alarm_msg += alarm_buf;
		
		p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alarm_msg);
	}
	else if((set_cptr_tune_val.ro_tuned_val < r_hard_max) 
		 && (set_cptr_tune_val.ro_tuned_val > r_soft_max))
	{
		Fnc__APP_LOG("R Offset MAX Soft Alarm Occur..");

		// ...
		alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__SOFT_RANGE_ERROR;
		
		alarm_buf.Format("Config MAX_Range is SOFT_MAX:%f < %f < HARD_MAX:%f", 
			             r_soft_max, set_cptr_tune_val.ro_tuned_val, r_hard_max);
		alarm_msg += alarm_buf;
		
		p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alarm_msg);
	}

	// ...
	{
		str_log.Format("Cptr Tune Val--> ro:%f, to:%f, r_hard_min:%f, r_hard_max:%f",
			            set_cptr_tune_val.ro_tuned_val, set_cptr_tune_val.to_tuned_val,
						r_hard_min, r_hard_max);
		Fnc__APP_LOG(str_log);
	}

	// R Axis -- Abort !!
	if( (set_cptr_tune_val.ro_tuned_val < r_hard_min) 
	||  (set_cptr_tune_val.ro_tuned_val > r_hard_max) )
	{
		Fnc__APP_LOG("R Offset Hard Alarm Occur..");

		// ...
		{
			alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__HARD_RANGE_ERROR;
		
			alarm_buf.Format("After Picking & Before Placing, Detects Wafer was misplaced in R Axis.\n\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("*** First of all, Must Check Wafer Position and Broken or not.\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("[ABORT]: Robot will be Down and Maint Mode..\n\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("[DIRECTION]\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("1. If Job Running, Must Be Calibrate Wafer Position.\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("2. You must Check Wafer Position and Broken or not\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("3. Push the Robot INIT Button in a TMC Operate Page\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("4. Then Job Will Resume.\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("5. Robot Will not Dynamic Align but just place in a fixed position.\n");
			alarm_msg += alarm_buf;
		
			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, alarm_msg, r_act);		
		}
		return OBJ_ABORT;
	}

	// ...
	{
		str_log.Format("Cptr Tune Val--> ro:%f, to:%f, t_hard_min:%f, t_hard_max:%f",
			            set_cptr_tune_val.ro_tuned_val, set_cptr_tune_val.to_tuned_val,
						t_hard_min, t_hard_max);

		Fnc__APP_LOG(str_log);
	}

	// T Axis -- Warning !!
	if((set_cptr_tune_val.to_tuned_val > t_hard_min) 
	&& (set_cptr_tune_val.to_tuned_val < t_soft_min))
	{
		Fnc__APP_LOG("T Offset Soft Alarm Occur..");

		// ...
		{
			alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__SOFT_RANGE_ERROR;
		
			alarm_buf.Format("Config MIN_Range is HARD_MIN:%f < %f < SOFT_MIN:%f", 
				             t_hard_min, set_cptr_tune_val.to_tuned_val, t_soft_min);
			alarm_msg += alarm_buf;
		
			p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alarm_msg);
		}
	}
	else if((set_cptr_tune_val.to_tuned_val < t_hard_max) 
		 && (set_cptr_tune_val.to_tuned_val > t_soft_max))
	{
		Fnc__APP_LOG("T Offset Soft Alarm Occur..");

		// ...
		{
			alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__SOFT_RANGE_ERROR;
		
			alarm_buf.Format("Config MAX_Range is SOFT_MAX:%f < %f < HARD_MAX:%f", 
							 t_soft_max, set_cptr_tune_val.to_tuned_val, t_hard_max);
			alarm_msg += alarm_buf;
		
			p_alarm->Post__ALARM_With_MESSAGE(alarm_id, alarm_msg);
		}
	}

	// T Axis -- Abort !!
	if( (set_cptr_tune_val.to_tuned_val < t_hard_min) 
	||  (set_cptr_tune_val.to_tuned_val > t_hard_max) )
	{
		Fnc__APP_LOG("T Offset Abort Alarm Occur..");

		// ...
		{
			alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__RANGE_ERROR;
			
			alarm_buf.Format("After Picking & Before Placing, Detects Wafer was misplaced in T Axis.\n\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("*** First of all, Must Check Wafer Position and Broken or not.\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("[ABORT]: Robot will be Down and Maint Mode..\n\n");
			alarm_msg += alarm_buf;

			alarm_buf.Format("[DIRECTION]\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("1. If Job Running, Must Be Calibrate Wafer Position.\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("2. You must Check Wafer Position and Broken or not\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("3. Push the Robot INIT Button in a TMC Operate Page\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("4. Then Job Will Resume.\n");
			alarm_msg += alarm_buf;
			alarm_buf.Format("5. Robot Will not Dynamic Align but just place in a fixed position.\n");
			alarm_msg += alarm_buf;

			p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, alarm_msg, r_act);
		}
		return OBJ_ABORT;
	}

	Fnc__APP_LOG("Offset Range Check.. Complete..");
	return OBJ_AVAILABLE;
}

void CObj__VacRobot_PSK
::Create_Directory(CString &dirPath)
{
	CFileFind cFileFinder;
	
	if(cFileFinder.FindFile(dirPath) == false)
	{
		CreateDirectory(dirPath, NULL);
	}
	else
	{
		if(cFileFinder.IsDirectory() == false)
		{
			CreateDirectory(dirPath, NULL);
		}
	}

	cFileFinder.Close();
}
