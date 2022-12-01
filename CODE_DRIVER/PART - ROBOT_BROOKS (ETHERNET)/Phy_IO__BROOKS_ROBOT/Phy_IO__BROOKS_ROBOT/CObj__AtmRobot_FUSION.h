#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CObj__AtmRobot_FUSION__DEF.h"

#include "CMng__Error_Code.h"


class CObj__AtmRobot_FUSION : public __IOBJ__IO_TYPE
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
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_NAME;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_SLOT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__ARM_TYPE;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_PARA__AL1_CCD_POS;

	// CONFIG CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__CFG_ACTION_CONFIRM_FLAG;

	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__AL1_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__AL2_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__VIS1_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__LBA_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__LBB_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__BUF1_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__BUF2_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__FULL_BUF_STN_NUM;

	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__LPx_STN_NUM[CFG_LPx__SIZE];

	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__PM1_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__PM2_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__PM3_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__PM4_STN_NUM;
	CX__VAR_ANALOG_CTRL  aCH__OTR_IN_CFG__PM5_STN_NUM;

	CX__VAR_STRING_CTRL  sCH__OTR_OUT_CFG__ROM_DATE;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_CFG__ROM_VERSION;

	// SIMULATION CHANNEL ...
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__ROTATE_TIME;

	// LPx
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LPx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LPx_PLACE_TIME;

	// ALx
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__ALx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__ALx_PLACE_TIME;

	// LBx
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LBx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__LBx_PLACE_TIME;

	// VISx
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__VISx_PICK_TIME;
	CX__VAR_ANALOG_CTRL  aCH__SIM_CFG__VISx_PLACE_TIME;

	// MATERIAL CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS;

	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_B_MATERIAL_TITLE;

	// ANIMATION CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ACT_ARM;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_A_ACT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_B_ACT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__TRG_MOVE;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__TRG_ROTATE;

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
	CX__VAR_ANALOG_CTRL aoCH__ANGLE;

	// AI  ----------
	CX__VAR_ANALOG_CTRL aiCH__ANG_POS;
	CX__VAR_ANALOG_CTRL aiCH__ANG_ECC;
	CX__VAR_ANALOG_CTRL aiCH__ECC_MAG;
	CX__VAR_ANALOG_CTRL aiCH__AVRG_RD;
	CX__VAR_ANALOG_CTRL aiCH__ERROR_ID;
	CX__VAR_ANALOG_CTRL aiCH__ALGN_ERROR_ID;

	// DO  ----------
	CX__VAR_DIGITAL_CTRL doCH__COMMAND;
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
	//
	
	// SI  ----------
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


	//-------------------------------------------------------------------------
	//  EXTERNAL PROPERTY

	// DB_CFG -----
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_SIM_MODE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_REF_ATM_PRESSURE;

	// AL1
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_EXIST_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_MATERIAL_TYPE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_FDCL;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_OCR_TYPE;

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_ALGN_POS;				// CFG.AL1.CCD.POS
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LL1_ALGN_POS;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LL2_ALGN_POS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_SLOT_MAX;
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_AL1_OCR_CCD_POS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_ALIGN_DEVICE;

	// AL1 -----
	CX__VAR_DIGITAL_CTRL dEXT_CH__AL1_SLOT01_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__AL1_SLOT02_STATUS;

	CX__VAR_STRING_CTRL  sEXT_CH__AL1_SLOT01_TITLE;
	CX__VAR_STRING_CTRL  sEXT_CH__AL1_SLOT02_TITLE;

	// VIS1 -----
	CX__VAR_DIGITAL_CTRL dEXT_CH__VIS1_SLOT01_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__VIS1_SLOT02_STATUS;

	CX__VAR_STRING_CTRL  sEXT_CH__VIS1_SLOT01_TITLE;
	CX__VAR_STRING_CTRL  sEXT_CH__VIS1_SLOT02_TITLE;

	// LBA -----
	CX__VAR_ANALOG_CTRL  aEXT_CH__LBA_PRESSURE_TORR;
	CX__VAR_DIGITAL_CTRL dEXT_CH__LBA_DOOR_VALVE_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__LBA_SLIT_VALVE_STATUS;

	CX__VAR_DIGITAL_CTRL dEXT_CH__LBA_SLOT_STATUS[CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__LBA_SLOT_TITLE[CFG_LBx__SLOT_SIZE];

	// LBB -----
	CX__VAR_ANALOG_CTRL  aEXT_CH__LBB_PRESSURE_TORR;
	CX__VAR_DIGITAL_CTRL dEXT_CH__LBB_DOOR_VALVE_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__LBB_SLIT_VALVE_STATUS;

	CX__VAR_DIGITAL_CTRL dEXT_CH__LBB_SLOT_STATUS[CFG_LBx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__LBB_SLOT_TITLE[CFG_LBx__SLOT_SIZE];

	// LPx -----
	int iLPx_SIZE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_DOOR_STATUS[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_EXIST_FLAG[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_CLAMP_STATUS[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_POS_STATUS[CFG_LPx__SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_SLOT_STATUS[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__LPx_SLOT_TITLE[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LP_SLOT_MAP_RESULT[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_IO_CH__ARM_RNE_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_IO_CH__ARM_LL1_RNE_SNS;
	CX__VAR_DIGITAL_CTRL dEXT_IO_CH__ARM_LL2_RNE_SNS;

	CX__VAR_DIGITAL_CTRL doEXT_IO_CH__LBA_LOAD_ENABLE;
	CX__VAR_DIGITAL_CTRL doEXT_IO_CH__LBB_LOAD_ENABLE;

	CX__VAR_DIGITAL_CTRL diEXT_CH__LPx__WFR_SLID_OUT_SNS[CFG_LPx__SIZE];	
	
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

	// Pick -----
	CString sMODE__PICK;
	int  Call__PICK(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	int  Fnc__SIM_PICK_TIME(CII_OBJECT__VARIABLE* p_variable,
						    CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);
	int  Fnc__PICK(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	// Place -----
	CString sMODE__PLACE;
	int  Call__PLACE(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	int  Fnc__SIM_PLACE_TIME(CII_OBJECT__VARIABLE* p_variable,
							 CII_OBJECT__ALARM* p_alarm,
							 const CString& arm_type,
							 const CString& stn_name,
							 const CString& stn_slot);
	int  Fnc__PLACE(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	// Rotate -----
	CString sMODE__ROTATE;
	int  Call__ROTATE(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	int  Fnc__SIM_ROTATE(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);
	int  Fnc__ROTATE(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	// AL Pick (delta Pick only)
	CString sMODE__AL_PICK;
	int  Call__AL_PICK(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// AL Align Pick (Align + delta Pick)
	CString sMODE__AL_ALIGN_PICK;
	int  Call__AL_ALIGN_PICK(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	// AL Align 
	CString sMODE__AL_ALIGN;
	int  Call__AL_ALIGN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// AL Align Init 
	CString sMODE__AL_ALIGN_INIT;
	int  Call__AL_ALIGN_INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// AL Align Result
	CString sMODE__AL_ALIGN_RESULT;
	int  Call__AL_ALIGN_RESULT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ALScan 
	CString sMODE__AL_SCAN;
	int  Call__AL_SCAN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ALHome 
	CString sMODE__AL_HOME;
	int  Call__AL_HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// Map
	CString sMODE__MAP;
	int  Call__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// Extend
	CString sMODE__EXTEND;
	int  Call__EXTEND(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	// Retract
	CString sMODE__RETRACT;
	int  Call__RETRACT(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	// GoUp
	CString sMODE__GOUP;
	int  Call__GOUP(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	// GoDown
	CString sMODE__GODOWN;
	int  Call__GODOWN(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	// Home
	CString sMODE__HOME;
	CString sMODE__VACOFF_HOME;
	int  Call__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm, const int req__vac_off);					   


	// ...
	void Mon__ANI_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Mon__IO_MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Mon__HYPER_TERMINAL_SEND(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// LoadPort Map
	CString sMODE__LP_MAP;
	int  Call__LP_MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const CString& stn_name);

	// ... 
	CString sMODE__CHECK_CMMD;
	int  Call__CHECK_CMMD(CII_OBJECT__VARIABLE* p_variable,
						  CII_OBJECT__ALARM* p_alarm);

	CString sMODE__CHECK_ERR_CODE;
	int  Call__CHECK_ERR_CODE(CII_OBJECT__VARIABLE* p_variable,
							  CII_OBJECT__ALARM* p_alarm);
	//

	// ...
	int  Interlock__CHECK_PRESSURE(CII_OBJECT__ALARM* p_alarm,const CString& stn_name,const CString& act_name);
	int  Interlock__CHECK_DOOR(CII_OBJECT__ALARM* p_alarm,const CString& stn_name,const CString& act_name);
	int  Interlock__CHECK_WAFER_LP_SLIDE(CII_OBJECT__ALARM* p_alarm,const CString& stn_name,const CString& act_name);
	int  Interlock__CHECK_MODULE(CII_OBJECT__ALARM* p_alarm,const CString& stn_name,const CString& act_name);

	// ...
	int  Is__LOCAL(CII_OBJECT__ALARM* p_alarm);
	int  Is__OFFLINE(CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Get__CFG_STN_NUM(const CString& stn_name,CString& stn_id);	

	// ROBOT -----
	int  Seq__ALIGN_PICK(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot,
							const CString& ccd_pos);

	int  Seq__ROBOT_PICK(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& act_cmmd,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Seq__ROBOT_PLACE(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Seq__ROBOT_ROTATE(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Seq__AL_HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Seq__AL_SCAN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int	 Seq__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int	 Seq__EXTEND(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	int	 Seq__RETRACT(CII_OBJECT__VARIABLE* p_variable,
						CII_OBJECT__ALARM* p_alarm,
						const CString& arm_type,
						const CString& stn_name,
						const CString& stn_slot);

	int	 Seq__GOUP(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	int	 Seq__GODOWN(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	int	 Seq__HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Seq__LP_MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const CString& stn_name);

	int	 Seq__ALALIGN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const CString& ccd_pos);
	int	 Seq__SIM_ALALIGN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const CString& ccd_pos);
	int  Seq__ALALIGN_RESULT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Set_IO__ARM_TYPE(const CString& arm_type,const CString& stn_name,const CString& stn_slot);
	int  Set_IO__ARM_TYPE(const CString& stn_name);

	// ...
	int  Fnc__IS_COMM_ONLINE();
	int  Fnc__ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm,const int alarm_check);

	int  Fnc__ALIGNER_ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm,const int alarm_check);

	int  Fnc__ROBOT_INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__ALIGNER_INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__ROBOT_MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__ROBOT_EXTEND(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Fnc__ROBOT_RETRACT(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Fnc__ROBOT_GOUP(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Fnc__ROBOT_GODOWN(CII_OBJECT__VARIABLE* p_variable,
							CII_OBJECT__ALARM* p_alarm,
							const CString& arm_type,
							const CString& stn_name,
							const CString& stn_slot);

	int  Fnc__ROBOT_HOME(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__LP_MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const CString& stn_name);

	int  Fnc__ROBOT_MAP_ONLINE_CHECK(CII_OBJECT__ALARM* p_alarm);
	int  Fnc__ROBOT_SET_WAFER(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	int  Fnc__ROBOT_ALARM_POST(CII_OBJECT__ALARM* p_alarm,const int alarm_id);

	int  Set__ROBOT_MATERIAL_SLOT(const CString& material_sts);
	int  Set__ROBOT_ANI(const CString& command,const CString& stn_name);

	// AL1 -----
	int  Fnc__AL1_AlMap(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Drv__CMD_COM_INIT(const CString& var_name);

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
	int  Proc__CMMD_RSP(const CString& var_name, 
						const CString& s_cmmd,
						const double to_sec,
						const BOOL active_prt,
						CStringArray& l_rsp,
						CStringArray& l_err);

	int  Check__MSG_KEY_WORD(const CString& str_data, 
							 const CString& key_word, 
							 int& msg_id,
							 CStringArray& l_para);

	CString Get__STRING_OF_LIST(const CStringArray& l_str);
	//

public:
	CObj__AtmRobot_FUSION();
	~CObj__AtmRobot_FUSION();

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
