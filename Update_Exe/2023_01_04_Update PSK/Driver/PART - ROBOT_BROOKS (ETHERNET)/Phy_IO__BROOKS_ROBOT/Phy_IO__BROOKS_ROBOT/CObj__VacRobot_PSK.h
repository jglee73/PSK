#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_SYSTEM.h"

#include "CMng__Error_Code.h"


class CObj__VacRobot_PSK : public __IOBJ__IO_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	int iCFG__PM_SIZE;
	int iCFG__LL_SIZE;

	int m_nSTN_NUM_MAX;

	bool bCMD_INIT_FLAG;

	// ...
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	SCX__USER_LOG_CTRL xAPP_LOG_CTRL;
	SCX__USER_LOG_CTRL xDRV_LOG_CTRL;
	SCX__USER_LOG_CTRL xRB_LOG_CTRL;

	int iActive__SIM_MODE;

	//
	CII__EXT_FNC_MODE_CTRL *pII__EXT_MODE_CTRL;
	CII__EXT_FNC_VAR_CTRL  *pII__EXT_VAR_CTRL;
	CII__EXT_USER_FNC_CTRL *pII__EXT_FNC_CTRL;

	CString m_szRoot;

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
	CString  m_sCptr_StationA;
	CString  m_sCptr_StationB;
	CString  m_sRPos;
	CString  m_sZPos;
	CString  m_sSlot;
	CString  m_sWfrSnsIntlk;

	CString  m_sRO_OFFSET;
	CString  m_sTO_OFFSET;

	CString  m_sSTN_R_SET_VAL;
	CString  m_sSTN_T_SET_VAL;

	// ...
	int iMsg_ID;

	int Get__Msg_ID()
	{
		iMsg_ID++;
		if(iMsg_ID < 0)		iMsg_ID = 1;
		if(iMsg_ID > 99)	iMsg_ID = 1;
		return iMsg_ID;
	}

	// ...
	CMng__Error_Code mMNG__ERR_CODE;
	//


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// ...
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__COMM_STS;

	CX__VAR_STRING_CTRL	 sCH__ACT_MSG;
	CX__VAR_STRING_CTRL	 sCH__ERRID;
	CX__VAR_STRING_CTRL	 sCH__szRoot;

	// PARA ...
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_NAME;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_SLOT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__ARM_TYPE;

	CX__VAR_STRING_CTRL  sCH__ACTION_STS;

	//
	CX__VAR_STRING_CTRL sCH__ARM_A_BEFORE_MODE_STS;
	CX__VAR_STRING_CTRL sCH__ARM_B_BEFORE_MODE_STS;

	CX__VAR_ANALOG_CTRL  aCH__SET_STN_R_VALUE;
	CX__VAR_ANALOG_CTRL  aCH__SET_STN_T_VALUE;

	CX__VAR_STRING_CTRL  sCH__Estimated_R_OFFSET;
	CX__VAR_STRING_CTRL  sCH__Estimated_T_OFFSET;

	// CFG ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_LLx_STN_NUM_X[CFG_LBx__SIZE][CFG_LBx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_CPTR_SNS__LLx_NUM_X[CFG_LBx__SIZE][CFG_LBx__SLOT_SIZE];;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PMx_STN_NUM[CFG_PMx__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__CFG_CPTR_SNS__PMx_NUM[CFG_PMx__SIZE];

	CX__VAR_DIGITAL_CTRL dCH__CFG_DA_SENSOR_TYPE;

	// MON ...
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS;
	
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_B_MATERIAL_TITLE;

	// SIM ...
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__ROTATE_TIME;

	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LBx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LBx_PLACE_TIME;

	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__PMx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__PMx_PLACE_TIME;
	
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__EXTEND_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__RETRACT_TIME;

	// DA.RESULT ...
	CX__VAR_STRING_CTRL  sCH__CPTR_SNS_FULL_VAL;
	CX__VAR_STRING_CTRL  sCH__DA_RESULT_FULL_VAL;

	CX__VAR_STRING_CTRL  sCH__DA_RESULT_R_OFFSET_MM;
	CX__VAR_STRING_CTRL  sCH__DA_RESULT_T_OFFSET_DEG;	
	CX__VAR_STRING_CTRL  sCH__DA_RESULT_X_OFFSET_MM;
	CX__VAR_STRING_CTRL  sCH__DA_RESULT_Y_OFFSET_MM;

	// CFG.TIMEOUT ...
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_DOWN;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_UP;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_EXTEND;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_GOTO_DA_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_RETRACT_DA_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_RETRACT_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_ROTATE_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_PICK_DA_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_PLACE_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT_PLACE_ADJUST_TIME;

	CX__VAR_ANALOG_CTRL  aCH__CFG_ACTION_TIMEOUT;

	CX__VAR_DIGITAL_CTRL dCH__CFG_PAD_TYPE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_WAFER_SIZE;

	CX__VAR_ANALOG_CTRL  aCH__CFG_PM1_ROTATE_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PM2_ROTATE_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PM3_ROTATE_TIME;
	CX__VAR_ANALOG_CTRL  aCH__CFG_PM4_ROTATE_TIME;

	CX__VAR_DIGITAL_CTRL dCH__CFG_WFR_SNS_CHECK;

	// CHECK CMMD & ERR_CODE
	CX__VAR_STRING_CTRL  sCH__PARA_CHECK_CMMD;
	CX__VAR_STRING_CTRL  sCH__PARA_CHECK_ERR_CODE;

	// DRV_INFO ...
	CX__VAR_DIGITAL_CTRL dCH__DRV_INFO_ACTIVE_BUSY;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_ERROR_CODE;

	CX__VAR_STRING_CTRL  sCH__INR_RB1_VERSION;

	CX__VAR_DIGITAL_CTRL dCH__CFG_CHECKLOAD_BASE_MAP;
	CX__VAR_DIGITAL_CTRL dCH__DRV_INFO_ARM_A_MAT_READ;
	CX__VAR_DIGITAL_CTRL dCH__DRV_INFO_ARM_B_MAT_READ;
	//

	
	// IO CHANNEL  -----------------------------------
	// SI
	CX__VAR_STRING_CTRL  siCH__VERSION__MANUAL;

	// SO
	CX__VAR_STRING_CTRL  soCH__CHECK_CMMD;

	CX__VAR_STRING_CTRL  xCH__UPDATE_FLAG;
	CX__VAR_DIGITAL_CTRL xCH__LOCK_FLAG;
	CX__VAR_STRING_CTRL  soCH__HYPER_TERMINAL_CMD;
	CX__VAR_STRING_CTRL  sCH__HYPER_TERMINAL_RECV_MSG;
	CX__VAR_ANALOG_CTRL  aCH__HYPER_TERMINAL_CMD_TIMEOUT;
	CX__VAR_STRING_CTRL  sCH__HYPER_TERMINAL_SEND_MSG;
	CX__VAR_DIGITAL_CTRL dCH__HYPER_TERMINAL_SEND_REQ;

	// DO
	CX__VAR_DIGITAL_CTRL doCH__COMMAND;
	CX__VAR_DIGITAL_CTRL doCH__STN_A;
	CX__VAR_DIGITAL_CTRL doCH__STN_B;
	CX__VAR_DIGITAL_CTRL doCH__CPTR_STN_A;
	CX__VAR_DIGITAL_CTRL doCH__CPTR_STN_B;
	CX__VAR_DIGITAL_CTRL doCH__SLOT;
	CX__VAR_DIGITAL_CTRL doCH__ZPOS;
	CX__VAR_DIGITAL_CTRL doCH__RPOS;
	CX__VAR_DIGITAL_CTRL doCH__ARM_A_MAT;
	CX__VAR_DIGITAL_CTRL doCH__ARM_B_MAT;
	CX__VAR_DIGITAL_CTRL doCH__ARM_WFR_SNS;
	
	// DI
	CX__VAR_DIGITAL_CTRL diCH__COMM_STS;
	CX__VAR_DIGITAL_CTRL diCH__ARM_A_READ;
	CX__VAR_DIGITAL_CTRL diCH__ARM_B_READ;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_INIT_CMD;

	CX__VAR_DIGITAL_CTRL diCH__ROBOT_STATE_READ__AUTO;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_STATE_READ__MANUAL;

	CX__VAR_DIGITAL_CTRL diCH__ROBOT_IO_STATE_READ;
	CX__VAR_DIGITAL_CTRL diCH__ROBOT_LOG_READ;

	// AO
	CX__VAR_ANALOG_CTRL aoCH_RO_OFFSET;
	CX__VAR_ANALOG_CTRL aoCH_TO_OFFSET;
	CX__VAR_ANALOG_CTRL aoCH_STN_R_VAL;
	CX__VAR_ANALOG_CTRL aoCH_STN_T_VAL;
	//


	//-------------------------------------------------------------------------
	// Init -----
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm);

	int  Fnc__INIT(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm);

	// Pick -----
	CString sMODE__PICK;
	int  Call__PICK(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& para__stn_name,
					const CString& para__arm_type,
					const CString& para__stn_slot);

	int  Fnc__PICK(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm,
				   const CString& stn_name,
				   const CString& arm_type,
				   const CString& stn_slot,
				   const int is_act_handoff);

	// Place -----
	CString sMODE__PLACE;
	int  Call__PLACE(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name,
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	int  Fnc__PLACE(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& para__stn_name,
					const CString& para__arm_type,
					const CString& para__stn_slot);

	// Rotate ...
	CString sMODE__ROTATE;
	int  Call__ROTATE(CII_OBJECT__VARIABLE* p_variable,
					  CII_OBJECT__ALARM* p_alarm,
					  const CString& para__stn_name, 
					  const CString& para__arm_type,
					  const CString& para__stn_slot);

	int  Fnc__SIM_ROTATE(CII_OBJECT__VARIABLE* p_variable,
						 CII_OBJECT__ALARM* p_alarm,
						 const CString& para__stn_name, 
						 const CString& para__arm_type,
						 const CString& para__stn_slot);

	int  Fnc__ROTATE(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	// Home ...
	CString sMODE__HOME;
	int  Call__HOME(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm);

	int  Fnc__SIM_HOME(CII_OBJECT__VARIABLE* p_variable,
					   CII_OBJECT__ALARM* p_alarm);
	int  Fnc__HOME(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm);

	// Map -----
	CString sMODE__MAP;
	int  Call__MAP(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm);

	int  Fnc__SIM_MAP(CII_OBJECT__VARIABLE* p_variable,
				      CII_OBJECT__ALARM* p_alarm);
	int  Fnc__MAP(CII_OBJECT__VARIABLE* p_variable,
				  CII_OBJECT__ALARM* p_alarm);

	// Extend -----
	CString sMODE__EXTEND;
	int  Call__EXTEND(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot,
					 const int is_active_handoff);

	int  Fnc__EXTEND(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot,
					 const int is_active_handoff);

	// Retract -----
	CString sMODE__RETRACT;
	int  Call__RETRACT(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot,
					 const int is_active_handoff);

	int  Fnc__RETRACT(CII_OBJECT__VARIABLE* p_variable,
				      CII_OBJECT__ALARM* p_alarm,
					  const CString& para__stn_name, 
					  const CString& para__arm_type,
					  const CString& para__stn_slot,
					  const int is_active_handoff);

	int  _Fnc__RETRACT(CII_OBJECT__VARIABLE* p_variable,
					   CII_OBJECT__ALARM* p_alarm,
					   const CString& para__stn_name, 
					   const CString& para__arm_type,
					   const CString& para__stn_slot,
					   const int is_active_handoff);

	// Goup -----
	CString sMODE__GOUP;
	int  Call__GOUP(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	int  Fnc__GOUP(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	// GoDown -----
	CString sMODE__GODOWN;
	int  Call__GODOWN(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	int  Fnc__GODOWN(CII_OBJECT__VARIABLE* p_variable,
					 CII_OBJECT__ALARM* p_alarm,
					 const CString& para__stn_name, 
					 const CString& para__arm_type,
					 const CString& para__stn_slot);

	// ... 
	CString sMODE__TEST_DA_REPORT;
	int  Call__TEST_DA_REPORT(CII_OBJECT__VARIABLE* p_variable,	
							  CII_OBJECT__ALARM* p_alarm);

	// ... 
	CString sMODE__CHECK_CMMD;
	int  Call__CHECK_CMMD(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CHECK_ERR_CODE;
	int  Call__CHECK_ERR_CODE(CII_OBJECT__VARIABLE* p_variable,
						      CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CHECK_IO_STATE_ALL;
	int  Call__CHECK_IO_STATE_ALL(CII_OBJECT__VARIABLE* p_variable,
								  CII_OBJECT__ALARM* p_alarm);

	CString sMODE__SAVE_ROBOT_LOG;
	int  Call__SAVE_ROBOT_LOG(CII_OBJECT__VARIABLE* p_variable,
								  CII_OBJECT__ALARM* p_alarm);


	// ...
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Mon__HYPER_TERMINAL_SEND(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Is__LOCAL(CII_OBJECT__ALARM* p_alarm);
	int  Is__OFFLINE(CII_OBJECT__ALARM* p_alarm);
	int  Is__ERROR_EXIST(CII_OBJECT__ALARM* p_alarm);
	
	CString	Get__CFG_STN_NUM(const CString& stn_name, const CString& str_slot_id);	
	CString Get__CFG_STN_CPTR_NUM(const CString& stn_name, const CString& str_slot_id);

	// ...
	int Set__CPTR_SNS_OFF_N(CII_OBJECT__VARIABLE* p_variable,
						    CII_OBJECT__ALARM* p_alarm,
						    const CString& arm_type,
		                    const CString& stn_name,
						    const CString& slot_id);

	int Set__CPTR_SNS_ON_N(CII_OBJECT__VARIABLE* p_variable,
						   CII_OBJECT__ALARM* p_alarm,
						   const CString& arm_type,
		                   const CString& stn_name,
						   const CString& slot_id);

	// ...
	void Fnc__APP_LOG(const CString& log_msg);
	void Fnc__DRV_LOG(const CString& log_msg);
	void Fnc__ACT_MSG(const CString& act_msg);		// sCH__ACT_MSG

	// ...
	void Register__ALARM_INF(CII_DEFINE__ALARM* p_alarm);

	CString Get__Error_Msg_Of_Error_Code(const int err_code);

	// ...
	int  Proc__CMMD_RSP(const CString& var_name, 
						const CString& s_cmmd,
						const double to_sec,
						const BOOL active_prt,
						CStringArray& l_rsp,
						CStringArray& l_err);


	int RB_LOG_EXTRACT(const CString& var_name,  
					   const CString& s_cmmd,
					   const double to_sec, 
					   const BOOL active_prt, 
					   CStringArray& l_rsp, 
					   CStringArray& l_err);

	int  Check__MSG_KEY_WORD(const CString& str_data, 
							 const CString& key_word, 
							 CStringArray& l_para);

	CString Get__STRING_OF_LIST(const CStringArray& l_str);

	// ...
	int  splitString(CString strData,CString Seperator, CStringArray& arr);
	
	int  _Update__WFR_CEN_DATA(CII_OBJECT__VARIABLE* p_variable);
	//


public:
	CObj__VacRobot_PSK();
	~CObj__VacRobot_PSK();

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
