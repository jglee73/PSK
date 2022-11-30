#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CObj__Driver_FUSION__DEF.h"

#include "CMng__Error_Code.h"


class CObj__Driver_INFO
{
public:
	CObj__Driver_INFO()
	{
		iCmm_State = -1;
		bState_Run = TRUE;

		iMsg_ID = -1;
		sVar_Name = "";

		sList_RSP.RemoveAll();
		sList_ERR.RemoveAll();
	}

	// ...
	int  iCmm_State;
	bool bState_Run;

	int iMsg_ID;
	CString sVar_Name;

	CStringArray sList_RSP;
	CStringArray sList_ERR;
};
class CObj__Driver_MSG
{
private:
	CRITICAL_SECTION mCS_LOCK;

	CPtrArray pList__MSG_INFO;

public:
	CObj__Driver_MSG()
	{
		InitializeCriticalSection(&mCS_LOCK);
	}
	~CObj__Driver_MSG()
	{
		DeleteCriticalSection(&mCS_LOCK);
	}

	void Load__MSG_INFO(const int msg_id,const CString& var_name)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info = new CObj__Driver_INFO;
		pList__MSG_INFO.Add(p_info);

		// ...
		{
			p_info->iMsg_ID   = msg_id;
			p_info->sVar_Name = var_name;
		}

		if(pList__MSG_INFO.GetSize() > 10)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[0];
			delete p_info;

			pList__MSG_INFO.RemoveAt(0);
		}

		LeaveCriticalSection(&mCS_LOCK);
	}
	int  Set__MSG_INFO_OF_STATE(const int msg_id, const int ok_flag)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			if(p_info->iMsg_ID != msg_id)		continue;

			p_info->iCmm_State = ok_flag;

			r_flag = 1;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	int  Set__MSG_INFO_END(const int msg_id)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			if(p_info->iMsg_ID != msg_id)		continue;

			p_info->bState_Run = FALSE;

			r_flag = 1;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	int  Set__MSG_INFO_OF_RSP(const int msg_id, const CStringArray& l_rsp)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			if(p_info->iMsg_ID != msg_id)		continue;

			p_info->sList_RSP.Copy(l_rsp);

			r_flag = 1;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	int  Set__MSG_INFO_OF_ERR(const int msg_id, const CStringArray& l_err)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			if(p_info->iMsg_ID != msg_id)		continue;

			p_info->sList_ERR.Copy(l_err);

			r_flag = 1;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	int  Get__MSG_INFO_END(const int db_index, int& msg_id, CStringArray& l_rsp,CStringArray& l_err, CString& var_name,int& cmm_state)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=db_index; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			if(p_info->bState_Run)				continue; 

			msg_id = p_info->iMsg_ID;
				
			l_rsp.RemoveAll();
			l_rsp.Copy(p_info->sList_RSP);

			l_err.RemoveAll();
			l_err.Copy(p_info->sList_ERR);

			var_name  = p_info->sVar_Name;
			cmm_state = p_info->iCmm_State; 

			r_flag = i;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	int  Check__MSG_INFO(const int msg_id, CStringArray& l_rsp,CStringArray& l_err)
	{
		EnterCriticalSection(&mCS_LOCK);

		// ...
		{
			l_rsp.RemoveAll();
			l_err.RemoveAll();
		}

		CObj__Driver_INFO *p_info;
		int r_flag = -1;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];
			
			if(p_info->iMsg_ID != msg_id)
			{
				continue;
			}
			if(p_info->bState_Run)
			{
				break;
			}

			l_rsp.Copy(p_info->sList_RSP);
			l_err.Copy(p_info->sList_ERR);

			pList__MSG_INFO.RemoveAt(i);
			delete p_info;

			r_flag = 1;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
		return r_flag;
	}
	void Delete__MSG_INFO(const int msg_id)
	{
		EnterCriticalSection(&mCS_LOCK);

		CObj__Driver_INFO *p_info;

		int i_limit = pList__MSG_INFO.GetSize();
		int i;

		for(i=0; i<i_limit; i++)
		{
			p_info = (CObj__Driver_INFO*) pList__MSG_INFO[i];

			if(p_info->iMsg_ID != msg_id)
			{
				continue;
			}

			pList__MSG_INFO.RemoveAt(i);
			delete p_info;
			break;
		}

		LeaveCriticalSection(&mCS_LOCK);
	}

	int  Wait__MSG_INFO(const int msg_id,const double to_sec, CStringArray& l_rsp,CStringArray& l_err)
	{
		int r_flag = _Wait__MSG_INFO(msg_id,to_sec, l_rsp,l_err);

		Delete__MSG_INFO(msg_id);
		return r_flag;
	}
	int  _Wait__MSG_INFO(const int msg_id,const double to_sec, CStringArray& l_rsp,CStringArray& l_err)
	{
		int ref_tick = GetTickCount();
		
		while(1)
		{
			Sleep(10);

			int r_flag = Check__MSG_INFO(msg_id, l_rsp,l_err);
			if(r_flag > 0)			return  1;

			// ...
			int dif_tick = GetTickCount() - ref_tick;
			if(dif_tick < 0)
			{
				ref_tick = GetTickCount();
				continue;
			}

			double cur_sec = dif_tick / 1000.0;
			if(cur_sec >= to_sec)
			{
				return -11;
			}
		}
		return -1;
	}
};


class CObj__Driver_FUSION : public __IOBJ__IO_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	CCommon_Error__USER_FNC mERROR__USER_FNC;

	// ..
	SCX__USER_LOG_CTRL xAPP_LOG_CTRL;
	SCX__USER_LOG_CTRL xDRV_LOG_CTRL;

	//
	int iActive__SIM_MODE;
	int iCFG__SIM_MODE;

	//
	CII__EXT_FNC_MODE_CTRL *pII__EXT_MODE_CTRL;
	CII__EXT_FNC_VAR_CTRL  *pII__EXT_VAR_CTRL;
	CII__EXT_USER_FNC_CTRL *pII__EXT_FNC_CTRL;

	//
	CObj__Driver_MSG mDrv_Msg;

	SCX__ETHERNET_JGLEE mX_Net;
	CString sEnd_InStr;
	CString sEnd_OutStr;

	int	 m_nCommState;
	int	 m_Rcv_Time;
	int	 m_Out_Time;

	//
	int  iFlag__APP_LOG;
	int  iFlag__DRV_LOG;

	// ...
	CString  m_sErrorID;
	CString  m_sStationA;
	CString  m_sStationB;
	CString  m_sRPos;
	CString  m_sZPos;
	CString  m_sSlot;
	CString  m_sWfrSnsIntlk;

	// ...
	CMng__Error_Code mMNG__ERR_CODE;
	//


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// ...
	CX__VAR_DIGITAL_CTRL dCH__SIM_CFG__REAL_TEST;
	CX__VAR_STRING_CTRL  sCH__SIM_CFG__ALIGN_TIME;

	CX__VAR_STRING_CTRL  sCH__ACT_MSG;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__COMM_STS;

	CX__VAR_STRING_CTRL  sCH__INR__ERROR_ID_DEC;
	CX__VAR_STRING_CTRL  sCH__INR__ERROR_ID_HEXA;

	CX__VAR_STRING_CTRL  sCH__INR__ALGINER_ERROR_ID;
	CX__VAR_DIGITAL_CTRL dCH__INR_FLAG__ALGN_STS;

	// PARA CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__PARA_ROBOT_CMMD;
	CX__VAR_DIGITAL_CTRL dCH__PARA_STN_NAME;
	CX__VAR_DIGITAL_CTRL dCH__PARA_STN_SLOT;
	CX__VAR_STRING_CTRL  sCH__PARA_ALING_ANGLE;
	CX__VAR_DIGITAL_CTRL dCH__PARA_ARM_TYPE;

	CX__VAR_DIGITAL_CTRL dCH__PARA_ALx_CMMD;
	CX__VAR_ANALOG_CTRL  aCH__PARA_ALx_CCD_POS;

	// CONFIG CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__CFG_ACTION_CONFIRM_FLAG;

	CX__VAR_STRING_CTRL  sCH__OTR_OUT_CFG__ROM_DATE;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_CFG__ROM_VERSION;

	// ...
	CX__VAR_STRING_CTRL  sCH__ROM_VER;
	CX__VAR_STRING_CTRL  sCH__ROM_DATE;

	CX__VAR_DIGITAL_CTRL dCH__LPx_SLOT_STATUS[CFG_LPx__SLOT_SIZE];

	CX__VAR_ANALOG_CTRL  aCH__CFG__PLACE_AND_ALIGN_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG__PICK_TIMEOUT;
	CX__VAR_ANALOG_CTRL  aCH__CFG__PLACE_TIMEOUT;
	CX__VAR_DIGITAL_CTRL dCH__CFG_MAPPING_ACTION_SLIDE_OUT_CHECK;
	CX__VAR_ANALOG_CTRL  aCH__CFG_LP__PADDLE_CHECK_TIME;

	CX__VAR_DIGITAL_CTRL dCFG__CH__DYNAMIC_ALIGN_DIRECTION;

	CX__VAR_DIGITAL_CTRL dCH__CFG_MAPPING_DISABLE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_ALIGN_SKIP;
	CX__VAR_DIGITAL_CTRL dCH__CFG_PAD_TYPE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_PICK_PLACE_PRESS_CHECK;

	// CHECK CMMD & ERR_CODE
	CX__VAR_STRING_CTRL  sCH__PARA_CHECK_CMMD;
	CX__VAR_STRING_CTRL  sCH__PARA_CHECK_ERR_CODE;
	//


	// IO CHANNEL  -----------------------------------
	// AO  ----------
	CX__VAR_ANALOG_CTRL aoCH__ALIGN_SLOT;
	CX__VAR_ANALOG_CTRL aoCH__ANGLE;

	// AI  ----------
	CX__VAR_ANALOG_CTRL aiCH__ANG_POS;
	CX__VAR_ANALOG_CTRL aiCH__ANG_ECC;
	CX__VAR_ANALOG_CTRL aiCH__ECC_MAG;
	CX__VAR_ANALOG_CTRL aiCH__AVRG_RD;
	CX__VAR_ANALOG_CTRL aiCH__ERROR_ID;
	CX__VAR_ANALOG_CTRL aiCH__ALGN_ERROR_ID;

	// DO  ----------
	CX__VAR_DIGITAL_CTRL doCH__RBx_CMMD;
	CX__VAR_STRING_CTRL  sCH__RBx_CMMD_STATE;

	CX__VAR_DIGITAL_CTRL doCH__ALx_CMMD;
	CX__VAR_DIGITAL_CTRL doCH__ALx_REPORT;
	CX__VAR_STRING_CTRL  sCH__ALx_CMMD_STATE;

	CX__VAR_STRING_CTRL  soCH__STN_NAME;
	CX__VAR_DIGITAL_CTRL doCH__ARM;
	CX__VAR_DIGITAL_CTRL doCH__SLOT;

	CX__VAR_DIGITAL_CTRL doCH__WFR_SIZE;
	CX__VAR_DIGITAL_CTRL doCH__WFR_FDCL;
	CX__VAR_DIGITAL_CTRL doCH__WFR_SHAPE;

	CX__VAR_DIGITAL_CTRL doCH__WFR_CCD;
	CX__VAR_DIGITAL_CTRL doCH__MATERIAL;

	CX__VAR_DIGITAL_CTRL doCH__SYSTEM_TRACKING_MATERIAL;

	// DI  ----------
	CX__VAR_DIGITAL_CTRL diCH__COMM_STS;

	CX__VAR_DIGITAL_CTRL diCH__ARM_A_WFR;
	CX__VAR_DIGITAL_CTRL diCH__ARM_B_WFR;
	CX__VAR_DIGITAL_CTRL diCH__VAC_SNS_A;
	CX__VAR_DIGITAL_CTRL diCH__VAC_SNS_B;

	CX__VAR_DIGITAL_CTRL diCH__RESCAN;
	CX__VAR_DIGITAL_CTRL diCH__CURR_STN;
	CX__VAR_DIGITAL_CTRL diCH__VAC_STS_A;
	CX__VAR_DIGITAL_CTRL diCH__VAC_STS_B;
	CX__VAR_DIGITAL_CTRL diCH__AL_WFR;
	
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_CURR_POS;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_Z_POS;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_AR_POS;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_T_POS;
	

	// SO  ----------
	CX__VAR_STRING_CTRL  soCH__HYPER_TERMINAL_CMD;

	// Hyper_Terminal - Virtual
	CX__VAR_STRING_CTRL  xCH__UPDATE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOCK_FLAG;
	CX__VAR_STRING_CTRL  sCH__HYPER_TERMINAL_RECV_MSG;
	CX__VAR_ANALOG_CTRL  aCH__HYPER_TERMINAL_CMD_TIMEOUT;
	CX__VAR_STRING_CTRL  sCH__HYPER_TERMINAL_SEND_MSG;
	CX__VAR_DIGITAL_CTRL dCH__HYPER_TERMINAL_SEND_REQ;

	// SO ...
	CX__VAR_STRING_CTRL  soCH__CHECK_CMMD;
	CX__VAR_STRING_CTRL  soCH__GET_INFO_CMD;

	// SI ...
	CX__VAR_STRING_CTRL  siCH__RBx_GetMap;
	CX__VAR_STRING_CTRL  siCH__LPx_GetMap;

	CX__VAR_STRING_CTRL  siCH__ALx_RESULT;

	// Robot : GetInfo ... 
	CX__VAR_STRING_CTRL  sCH__Robot_GetInfo_Update_Req;

	CX__VAR_STRING_CTRL  sCH__GetInfo_Version;

	CX__VAR_STRING_CTRL  sCH__GetInfo_RB_GetApplicationID;
	CX__VAR_STRING_CTRL  sCH__GetInfo_RB_GetLocationStates;
	CX__VAR_STRING_CTRL  sCH__GetInfo_RB_GetSpeed;
	CX__VAR_STRING_CTRL  sCH__GetInfo_RB_GetVacuumSensorValue;
	CX__VAR_STRING_CTRL  sCH__GetInfo_RB_IsServoed;

	CX__VAR_STRING_CTRL  sCH__GetInfo_SYS_GetStations;
	CX__VAR_STRING_CTRL  sCH__GetInfo_SYS_Getdevices;
	CX__VAR_STRING_CTRL  sCH__GetInfo_SYS_GetSafetyEnabled;
	CX__VAR_STRING_CTRL  sCH__GetInfo_SYS_GetSafetyState;

	// Aligner : GetInfo ...
	CX__VAR_STRING_CTRL  sCH__AL_GetInfo_Update_Req;

	CX__VAR_STRING_CTRL  sCH__GetInfo_AL_GetEccentricityAngle;
	CX__VAR_STRING_CTRL  sCH__GetInfo_AL_GetEccentricityMagnitude;
	CX__VAR_STRING_CTRL  sCH__GetInfo_AL_GetEccentricityTransform;
	CX__VAR_STRING_CTRL  sCH__GetInfo_AL_GetFiducialAngle;
	
	// ...
	int	     iDRV__ALGNER_ERROR_ID;
	int	     iDRV__ERROR_ID;
	CString  sDRV__STN_NAME;
	CString  sDRV__ARM_NO;
	int      iDRV__SLOT_NO;
	CString  sDRV__RB_VAC_SNS_A;
	CString  sDRV__RB_VAC_SNS_B;
	double   dDRV__RB_FIND_BIAS_SET;
	CString  sDRV__RB_MATERIAL;
	CString  sDRV__RB_WFR_SHAPE;
	CString  sDRV__RB_WFR_SIZE;
	CString  sDRV__RB_WFR_FDCL;
	int      iDRV__ANGLE_SLOT;
	double   dDRV__RB_ANGLE_DEG;
	double	 dDRV__RB_ANGLE_POS;
	double	 dDRV__RB_ANGLE_ECC;
	double	 dDRV__RB_ECC_MAG;
	double	 dDRV__RB_AVG_RD;
	int      iDRV__RB_WFR_CCD;	
	CString  sDRV__RB_Z_POS;
	CString  sDRV__RB_AR_POS;
	CString  sDRV__RB_BR_POS;
	CString  sDRV__RB_T_POS;
	CString  sDRV__RB_S_POS;
	int      iDRV__ECC_MAG;
	int      iDRV__ANGLE_POS;
	int      iDRV__ANGLE_ECC;
	int      iDRV__AVG_RD;
	double   dDRV__DELTA_R;
	double   dDRV__DELTA_T;
	CString  sDRV__RESCAN;
	//

	// ...
	int iMsg_ID;

	int Get__Msg_ID()
	{
		iMsg_ID++;

		if(iMsg_ID < 0)		iMsg_ID = 1;
		if(iMsg_ID > 999)	iMsg_ID = 1;

		return iMsg_ID;
	}


	//-------------------------------------------------------------------------
	// Init -----
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__SIM_INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ... 
	CString sMODE__ROBOT_CMMD;
	int  Call__ROBOT_CMMD(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	CString sMODE__ALx_CMMD;
	int  Call__ALx_CMMD(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm);

	CString sMODE__ALx_RESULT;
	int  Call__ALx_RESULT(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	// ... 
	CString sMODE__CHECK_CMMD;
	int  Call__CHECK_CMMD(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CHECK_ERR_CODE;
	int  Call__CHECK_ERR_CODE(CII_OBJECT__VARIABLE* p_variable,
							  CII_OBJECT__ALARM* p_alarm);

	// ...
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Mon__RECV_PROC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	void Mon__RSPID_PROC(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	void Mon__HYPER_TERMINAL_SEND(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Fnc__StrTo2Word(const CString& data,
							const char section,
							CString *p_str1,
							CString *p_str2);

	int  Fnc__StrTo7Word(const CString& data,
							const char section,
							CString *p_str1,
							CString *p_str2,
							CString *p_str3,
							CString *p_str4,
							CString *p_str5,
							CString *p_str6,
							CString *p_str7);

	int  Fnc__IndexStrTo1Word(const CString& data,
							const char section,
							int index,
							CString *p_str1);
	int  Fnc__IndexStrTo4Word(const CString& data,
							const char section,
							int index,
							CString *p_str1,
							CString *p_str2,
							CString *p_str3,
							CString *p_str4);
	int  Fnc__IndexStrTo5Word(const CString& data,
							const char section,
							int index,
							CString *p_str1,
							CString *p_str2,
							CString *p_str3,
							CString *p_str4,
							CString *p_str5);

	int  Fnc__HexToDec(const CString& str_dec);
	int  Fnc__DecToBin(int dec,CString *p_str);

	// ...
	void Fnc__APP_LOG(const CString& log_msg);
	void Fnc__DRV_LOG(const CString& log_msg);
	void Fnc__DRV_LOG_FORMAT(const char *fmt, ...);
	void Fnc__ACT_MSG(const CString& act_msg);

	// ...
	int m_nRetryCount;
	int m_nTimeout;
	
	// ...
	void Register__ALARM_INF(CII_DEFINE__ALARM* p_alarm);
	int  Fnc__ROBOT_ALARM_POST(CII_OBJECT__ALARM* p_alarm,const int alarm_id);

	CString Get__Fusion_Error_Msg_Of_Error_Code(const int err_code);
	CString Get__Motion_Secondary_Error_Msg_Of_Error_Code(const int err_code);

	CString Get__Fusion_Resource_Name_Of_Module_Name(const CString& module_name)
	{
		if(module_name.CompareNoCase(ARM_A) == 0)			return "atm1 1";
		if(module_name.CompareNoCase(ARM_B) == 0)			return "atm1 2";
		
		if(module_name.CompareNoCase(STR__LP1) == 0)		return "lpm1";
		if(module_name.CompareNoCase(STR__LP2) == 0)		return "lpm2";
		if(module_name.CompareNoCase(STR__LP3) == 0)		return "lpm3";
		if(module_name.CompareNoCase(STR__LP4) == 0)		return "lpm4";
		if(module_name.CompareNoCase(STR__LP5) == 0)		return "lpm5";

		if(module_name.CompareNoCase(STR__AL1) == 0)		return "algn1";
		if(module_name.CompareNoCase(STR__AL2) == 0)		return "algn2";

		if(module_name.CompareNoCase(STR__LBA) == 0)		return "lla";
		if(module_name.CompareNoCase(STR__LBB) == 0)		return "llb";

		if(module_name.CompareNoCase(STR__BUFF1) == 0)		return "buf1";
		if(module_name.CompareNoCase(STR__BUFF2) == 0)		return "buf2";

		return "";
	}

	// ...
	int  Drv__SEND_CMMD(const CString& var_name, 
						const CString& s_cmmd,
						const BOOL active_prt);
	int  Drv__SEND_RECV(const CString& var_name, 
						const CString& s_cmmd,
						const double to_sec,
						const BOOL active_prt,
						CStringArray& l_rsp,
						CStringArray& l_err);

	int  Proc__RECV_RSP(CII_OBJECT__ALARM* p_alarm, const BOOL active_prt);

	int  Check__MSG_KEY_WORD(const CString& str_data, 
							 const CString& key_word, 
							 int& msg_id,
							 CStringArray& l_para);

	CString Get__STRING_OF_LIST(const CStringArray& l_str);

	int  Fnc__ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm, const int alarm_check);

	// ...
	int  Set_IO__ARM_TYPE(const CString& arm_type,const CString& stn_name,const CString& stn_slot);
	int  Set_IO__ARM_TYPE(const CString& stn_name);
	//

public:
	CObj__Driver_FUSION();
	~CObj__Driver_FUSION();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__VARIABLE_IO(p_io_variable);

	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);	
	int __INITIALIZE__IO(p_io_para);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);

	//-------------------------------------------------------------------------
	int __Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data);
	int __Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index);
	int __Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data);

	int __Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data);
	int __Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index);
	int __Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data);
};
