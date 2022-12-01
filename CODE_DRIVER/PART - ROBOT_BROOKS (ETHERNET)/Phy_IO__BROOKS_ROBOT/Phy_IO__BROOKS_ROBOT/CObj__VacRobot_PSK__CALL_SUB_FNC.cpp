#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "math.h"
#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_PSK
::Is__LOCAL(CII_OBJECT__ALARM* p_alarm)
{
	return 1;
}

int  CObj__VacRobot_PSK
::Is__OFFLINE(CII_OBJECT__ALARM* p_alarm)
{
LOOP_RETRY:

	if(iCFG__SIM_FLAG > 0)
	{
		diCH__COMM_STS->Set__DATA(STR__ONLINE);
	}

	if(diCH__COMM_STS->Check__DATA(STR__OFFLINE) > 0)
	{
		int alarm_id = ALID__OFFLINE_ALARM;
		CString r_act;

		p_alarm->Popup__ALARM(alarm_id,r_act);

		if(r_act.CompareNoCase("RETRY") == 0)		goto LOOP_RETRY;
		else										return -1;
	}

	return 1;
}

int CObj__VacRobot_PSK
::Fnc__calculation_CPTR_SNS_VAL(const CString& stn_name,
								const CString& arm_type,
								CPTR_TUNED_VAL& ro_to_tune_val)
{
	CString str_val;
	CString str_log;

	double caled_r_hi, caled_t_hi, caled_z_hi;
	double caled_r_lo, caled_t_lo, caled_z_lo;

	double r_hi, t_hi, z_hi;
	double r_lo, t_lo, z_lo;

	double r_tune_val, t_tune_val;

	// 1. PICK 할 때 읽어온 Data를 가져온다.
	{
		if(arm_type.CompareNoCase(ARM_A) == 0)
		{
			sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH->Get__DATA(str_val);	r_hi = atof(str_val);
			sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH->Get__DATA(str_val);	t_hi = atof(str_val);
			sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH->Get__DATA(str_val);	z_hi = atof(str_val);

			// RETRACT... LOW Sns
			sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW->Get__DATA(str_val);		r_lo = atof(str_val);
			sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW->Get__DATA(str_val);		t_lo = atof(str_val);
			sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW->Get__DATA(str_val);		z_lo = atof(str_val);
		}
		else
		{
			sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Get__DATA(str_val);	r_hi = atof(str_val);
			sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Get__DATA(str_val);	t_hi = atof(str_val);
			sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Get__DATA(str_val);	z_hi = atof(str_val);

			// RETRACT... LOW Sns
			sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Get__DATA(str_val);		r_lo = atof(str_val);
			sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Get__DATA(str_val);		t_lo = atof(str_val);
			sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Get__DATA(str_val);		z_lo = atof(str_val);
		}

		str_log.Format("After Picked, Result Data....   R_HI:%f, T_HI:%f, Z_HI:%f, R_LO:%f, T_LO:%f, Z_LO:%f", 
			r_hi, t_hi, z_hi, r_lo, t_lo, z_lo);

		Fnc__APP_LOG(str_log);
	}

	// 2. 해당 Station의 CALIBRATION 된 R, T, Z 값들을 가져온다.
	{
		Get__CALED_CPTR_SNS_VAL(stn_name,arm_type,
			caled_r_hi, caled_t_hi, caled_z_hi,
			caled_r_lo, caled_t_lo, caled_z_lo);

		str_log.Format("Teached, Cur Stn[%s], ARM [%s], R_HI:%f, T_HI:%f, Z_HI:%f, R_LO:%f, T_LO:%f, Z_LO:%f", 
			stn_name, arm_type, 
			caled_r_hi, caled_t_hi, caled_z_hi, 
			caled_r_lo, caled_t_lo, caled_z_lo);

		Fnc__APP_LOG(str_log);
	}

	// 3. PICK 후에 얻어온 R, T, Z 값과 CALIBRATION 된 R, T, Z 값들을 비교 계산한다.
	{
		Calculation_Sns_Val(caled_r_hi, caled_t_hi, caled_z_hi,
			caled_r_lo, caled_t_lo, caled_z_lo,
			r_hi, t_hi, z_hi,
			r_lo, t_lo, z_lo,
			r_tune_val, t_tune_val,
			stn_name);

		ro_to_tune_val.ro_tuned_val = r_tune_val;
		ro_to_tune_val.to_tuned_val = t_tune_val;
	}

	return 1;
}

int CObj__VacRobot_PSK
::Fnc__calculation_CPTR_SNS_VAL_N(const CString& stn_name,
								  const CString& arm_type,
								  CPTR_TUNED_VAL& ro_to_tune_val)
{
	CString str_val;
	CString str_log;
	double caled_r_hi, caled_t_hi, caled_z_hi;
	double caled_r_lo, caled_t_lo, caled_z_lo;

	double r_hi, t_hi, z_hi;
	double r_lo, t_lo, z_lo;

	double r_tune_val, t_tune_val;

	// 1. PICK 할 때 읽어온 Data를 가져온다.
	{
		if(arm_type.CompareNoCase(ARM_A) == 0)
		{
			sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH->Get__DATA(str_val);	r_hi = atof(str_val);
			sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH->Get__DATA(str_val);	t_hi = atof(str_val);
			sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH->Get__DATA(str_val);	z_hi = atof(str_val);

			// RETRACT... LOW Sns
			sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW->Get__DATA(str_val);		r_lo = atof(str_val);
			sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW->Get__DATA(str_val);		t_lo = atof(str_val);
			sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW->Get__DATA(str_val);		z_lo = atof(str_val);
		}
		else
		{
			sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH->Get__DATA(str_val);	r_hi = atof(str_val);
			sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH->Get__DATA(str_val);	t_hi = atof(str_val);
			sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH->Get__DATA(str_val);	z_hi = atof(str_val);

			// RETRACT... LOW Sns
			sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW->Get__DATA(str_val);		r_lo = atof(str_val);
			sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW->Get__DATA(str_val);		t_lo = atof(str_val);
			sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW->Get__DATA(str_val);		z_lo = atof(str_val);
		}

		str_log.Format("After Picked, Result Data....   R_HI:%f, T_HI:%f, Z_HI:%f, R_LO:%f, T_LO:%f, Z_LO:%f", 
			r_hi, t_hi, z_hi, r_lo, t_lo, z_lo);

		Fnc__APP_LOG(str_log);
	}

	// 2. 해당 Station의 CALIBRATION 된 R, T, Z 값들을 가져온다.
	{
		Get__CALED_CPTR_SNS_VAL(stn_name,arm_type,
			caled_r_hi, caled_t_hi, caled_z_hi,
			caled_r_lo, caled_t_lo, caled_z_lo);

		str_log.Format("Teached, Cur Stn[%s], ARM [%s], R_HI:%f, T_HI:%f, Z_HI:%f, R_LO:%f, T_LO:%f, Z_LO:%f", 
			stn_name, arm_type, 
			caled_r_hi, caled_t_hi, caled_z_hi, 
			caled_r_lo, caled_t_lo, caled_z_lo);

		Fnc__APP_LOG(str_log);
	}

	// 3. PICK 후에 얻어온 R, T, Z 값과 CALIBRATION 된 R, T, Z 값들을 비교 계산한다.
	{
		Calculation_Sns_Val_N(caled_r_hi, caled_t_hi, caled_z_hi,
			caled_r_lo, caled_t_lo, caled_z_lo,
			r_hi, t_hi, z_hi,
			r_lo, t_lo, z_lo,
			r_tune_val, t_tune_val,
			stn_name);

		// Below values mean X & Y Offset, don't mean Theta Offset
		ro_to_tune_val.ro_tuned_val = r_tune_val;
		ro_to_tune_val.to_tuned_val = t_tune_val;
	}

	return OBJ_AVAILABLE;
}

int CObj__VacRobot_PSK
::Get__CALED_CPTR_SNS_VAL(const CString& stn_name,
						  const CString& arm_type,
						  double& r_hi, double& t_hi, double& z_hi,
						  double& r_lo, double& t_lo, double& z_lo)
{
	CString cfg_cptr_sns_val;

	// ...
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
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				r_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				t_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				z_hi = atof(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				r_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				t_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				z_lo = atof(cfg_cptr_sns_val);
			}
			if(active__arm_b)
			{
				// HIGH
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				r_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				t_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				z_hi = atof(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				r_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				t_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Get__DATA(cfg_cptr_sns_val);	
				z_lo = atof(cfg_cptr_sns_val);
			}
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				r_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				t_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				z_hi = atof(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				r_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				t_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				z_lo = atof(cfg_cptr_sns_val);
			}

			if(active__arm_b)
			{
				// HIGH
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				r_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				t_hi = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				z_hi = atof(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				r_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				t_lo = atof(cfg_cptr_sns_val);
				
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Get__DATA(cfg_cptr_sns_val);	
				z_lo = atof(cfg_cptr_sns_val);
			}
		}
	}

	return 1;
}

int CObj__VacRobot_PSK
::Init__CALED_CPTR_SNS_VAL_CH(const CString& stn_name, const CString& arm_type)
{
	CString cfg_cptr_sns_val = "";

	// ...
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
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);	
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
			}

			if(active__arm_b)
			{
				// HIGH
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
			}
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
			}

			if(active__arm_b)
			{
				// HIGH
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
			}
		}
	}

	return 1;
}

int CObj__VacRobot_PSK
::Save__CALED_CPTR_SNS_VAL(const CString& stn_name,
						   const CString& arm_type,
						   double& r_hi, double& t_hi, double& z_hi,
						   double& r_lo, double& t_lo, double& z_lo)
{
	CString cfg_cptr_sns_val;

	// ...
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
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				cfg_cptr_sns_val.Format("%.f", r_hi); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);	
				
				cfg_cptr_sns_val.Format("%.f", t_hi); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_hi); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				cfg_cptr_sns_val.Format("%.f", r_lo); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_lo); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_lo); 
				aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
			}

			if(active__arm_b)
			{
				// HIGH
				cfg_cptr_sns_val.Format("%.f", r_hi); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_hi); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_hi); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				cfg_cptr_sns_val.Format("%.f", r_lo); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_lo); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_lo); 
				aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[ll_index]->Set__DATA(cfg_cptr_sns_val);
			}
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			if(active__arm_a)
			{
				// HIGH
				cfg_cptr_sns_val.Format("%.f", r_hi); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_hi); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_hi); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				cfg_cptr_sns_val.Format("%.f", r_lo); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_lo); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_lo); 
				aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
			}

			if(active__arm_b)
			{
				// HIGH
				cfg_cptr_sns_val.Format("%.f", r_hi); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_hi); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_hi); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);

				// LOW
				cfg_cptr_sns_val.Format("%.f", r_lo); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", t_lo); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
				
				cfg_cptr_sns_val.Format("%.f", z_lo); 
				aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_LOW_SNS_VAL[pm_index]->Set__DATA(cfg_cptr_sns_val);
			}
		}
	}

	return 1;
}

CString  CObj__VacRobot_PSK
::Get__CFG_STN_NUM(const CString& stn_name)
{
	CString cfg_stn_num = "?";

	// ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			aCH__CFG_LLx_STN_NUM[ll_index]->Get__DATA(cfg_stn_num);
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			aCH__CFG_PMx_STN_NUM[pm_index]->Get__DATA(cfg_stn_num);
		}
	}

	return cfg_stn_num;
}

CString  CObj__VacRobot_PSK
::Get__CFG_DYNAMIC_ALGN_USE(const CString& stn_name)
{
	CString cfg_val = "?";

	// ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			 dCH__CFG_LLx_DA_USE[ll_index]->Get__DATA(cfg_val);
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			dCH__CFG_PMx_DA_USE[pm_index]->Get__DATA(cfg_val);
		}
	}

	return cfg_val;
}

CString  CObj__VacRobot_PSK
::Get__CFG_STN_CPTR_NUM(const CString& stn_name)
{
	CString cfg_val;

	// ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			aCH__CFG_CPTR_SNS__LLx_NUM[ll_index]->Get__DATA(cfg_val);
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			aCH__CFG_CPTR_SNS__PMx_NUM[pm_index]->Get__DATA(cfg_val);
		}
	}

	return cfg_val;
}

int  CObj__VacRobot_PSK
::Get__CFG_STN_OFFSET_RANGE_RET(const CString& stn_name, 
								CString& str_r_soft_tol, CString& str_r_hard_tol,
								CString& str_t_soft_tol, CString& str_t_hard_tol)
{
	// ...
	{
		int ll_index = Macro__CHECK_LLx_INDEX(stn_name);

		if((ll_index >= 0) && (ll_index < iCFG__LL_SIZE))
		{
			aCH__OTR_IN_CFG__R_OFFSET_SOFT_TOLERANCE_LL_RET_X[ll_index]->Get__DATA(str_r_soft_tol);
			aCH__OTR_IN_CFG__R_OFFSET_HARD_TOLERANCE_LL_RET_X[ll_index]->Get__DATA(str_r_hard_tol);

			aCH__OTR_IN_CFG__T_OFFSET_SOFT_TOLERANCE_LL_RET_X[ll_index]->Get__DATA(str_t_soft_tol);
			aCH__OTR_IN_CFG__T_OFFSET_HARD_TOLERANCE_LL_RET_X[ll_index]->Get__DATA(str_t_hard_tol);
		}
	}

	// ...
	{
		int pm_index = Macro__CHECK_PMx_INDEX(stn_name);

		if((pm_index >= 0) && (pm_index < iCFG__PM_SIZE))
		{
			aCH__OTR_IN_CFG__R_OFFSET_SOFT_TOLERANCE_RET[pm_index]->Get__DATA(str_r_soft_tol);
			aCH__OTR_IN_CFG__R_OFFSET_HARD_TOLERANCE_RET[pm_index]->Get__DATA(str_r_hard_tol);

			aCH__OTR_IN_CFG__T_OFFSET_SOFT_TOLERANCE_RET[pm_index]->Get__DATA(str_t_soft_tol);
			aCH__OTR_IN_CFG__T_OFFSET_HARD_TOLERANCE_RET[pm_index]->Get__DATA(str_t_hard_tol);
		}
	}

	return 1;
}

int  CObj__VacRobot_PSK
::Is__ERROR_EXIST(CII_OBJECT__ALARM* p_alarm)
{
	int err_code;

	// Read ErrorID
	{
		CString ch_data = sCH__ERRID->Get__STRING();
		err_code = atoi(ch_data);

		CString log_msg;
		log_msg.Format("APP_GET_ERR_ID : [%d]", err_code);
		Fnc__APP_LOG(log_msg);
	}

	// Simulation
	if(dEXT_CH__CFG_SIM_MODE->Check__DATA(STR__ENABLE) > 0)
	{
		err_code = 0;
	}

	if(err_code == 0)
	{
		return 1;
	}

	// ...
	int	alarm_id = ALID__CONTROLLER_ERROR_CODE;
	CString r_act;

	CString err_msg = Get__Error_Msg_Of_Error_Code(err_code);
	p_alarm->Popup__ALARM_With_MESSAGE(alarm_id, err_msg, r_act);

	if(r_act.CompareNoCase("RETRY") == 0)
	{
		return OBJ_RETRY;
	}
	return OBJ_ABORT;
}
