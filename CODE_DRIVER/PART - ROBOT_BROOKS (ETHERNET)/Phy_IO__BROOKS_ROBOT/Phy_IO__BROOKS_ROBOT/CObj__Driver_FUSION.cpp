#include "StdAfx.h"
#include "CObj__Driver_FUSION.h"
#include "CObj__Driver_FUSION__DEF.h"
#include "CObj__Driver_FUSION__ALID.h"

#include "CCommon_DEF.h"


//--------------------------------------------------------------------------------
CObj__Driver_FUSION::CObj__Driver_FUSION()
{
	m_sErrorID  =   "0";
	m_sStationA =	"1";
	m_sStationB =	"1";
	m_sRPos     =	"RE"; 
	m_sZPos		=	"DN"; 
	m_sSlot		=	"1"; 

	m_nCommState = ONLINE;
}
CObj__Driver_FUSION::~CObj__Driver_FUSION()
{

}

//--------------------------------------------------------------------------------
int CObj__Driver_FUSION::__DEFINE__CONTROL_MODE(obj,l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT, "INIT");	

		ADD__CTRL_VAR(sMODE__ROBOT_CMMD, "ROBOT.CMMD");

		ADD__CTRL_VAR(sMODE__ALx_CMMD,   "ALx.CMMD");
		ADD__CTRL_VAR(sMODE__ALx_RESULT, "ALx.RESULT");

		ADD__CTRL_VAR(sMODE__CHECK_CMMD,     "CHECK.CMMD");
		ADD__CTRL_VAR(sMODE__CHECK_ERR_CODE, "CHECK.ERR_CODE");
	}
	return 1;
}
int CObj__Driver_FUSION::__DEFINE__VERSION_HISTORY(version)
{
	version = "JG.Lee \n";

	return 1;
}


// ...
#define  MON_ID__IO_MONITOR									1
#define  MON_ID__RECV_PROC									2
#define  MON_ID__RSPID_PROC									3
#define  MON_ID__HYPER_TERMINAL_SEND						4


// ...
#define APP_DSP__RB_TARGET_MOVE								\
"UNKNOWN HOME READY											\
PM1 PM2 PM3 PM4 PM5 PM6										\
LBA LBB														\
AL1 AL2														\
VIS1 VIS2													\
LP1 LP2 LP3 LP4 LP5											\
BUFF1 BUFF2"

#define APP_DSP__STN_NAME									\
"LP1 LP2 LP3 LP4 LP5										\
VIS1														\
LBA LBB														\
AL1 AL2														\
BUFF1 BUFF2 FULL_BUFF"

#define APP_DSP__ARM_TYPE									\
"A B"

#define APP_DSP__RET_EXT									\
"Retract Extend"

#define APP_DSP__DOWN_UP									\
"Down Up"

#define APP_DSP__ARM_STS_ANI								\
"UNKNOWN RETRACT EXTEND"

#define APP_DSP__LP_WFR_SLOT_STS							\
"UNKNOWN INVALID ABSENT PRESENT DOUBLE CROSSED"

#define APP_DSP__DSlot										\
"1  2  3  4  5  6  7  8  9  10								\
11 12 13 14 15 16 17 18 19 20								\
21 22 23 24 25 26 27 28 29 30"


// ...
#define APP_DSP__RB_Cmd_Set								    \
"PrepPick  PrepPlace                                        \
 Pick  Place             								    \
 Home  Reset  ShutDown                                      \
 MapStn"

#define APP_DSP__AL_Cmd_Set								    \
"InitAlgn  ALHome       								    \
 ALLoadPP  ALAlign  ALRotate  ALScan"

#define APP_DSP__AL_Cmd_Report							    \
"ALResult"


int CObj__Driver_FUSION::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE

	CCommon_Error__DEF_VARIABLE m_err_def_variable;
	p_variable->Link__DEF_VARIABLE__ERROR_FEEDBACK(&m_err_def_variable);

	// ...
	CString str_name;
	int i;

	// Hyper Terminal ...
	{
		str_name = "sHYPER.TERMINAL.UPDATE.FLAG";
		STD__ADD_STRING_WITH_COMMENT(str_name, "");
		LINK__VAR_STRING_CTRL(xCH__UPDATE_FLAG, str_name);

		str_name = "dHYPER.TERMINAL.LOCK.FLAG";
		STD__ADD_DIGITAL_WITH_COMMENT(str_name, "YES NO", "");
		LINK__VAR_DIGITAL_CTRL(xCH__LOCK_FLAG, str_name);

		str_name = "dHYPER.TERMINAL.SEND.REQ";
		STD__ADD_DIGITAL(str_name, "NO YES");
		LINK__VAR_DIGITAL_CTRL(dCH__HYPER_TERMINAL_SEND_REQ,str_name);

		str_name = "sHYPER.TERMINAL.SEND.MSG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__HYPER_TERMINAL_SEND_MSG,str_name);

		str_name = "sHYPER.TERMINAL.RECV.MSG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__HYPER_TERMINAL_RECV_MSG,str_name);

		str_name = "aHYPER.TERMINAL.CMD.TIMEOUT";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 1, 60, "");
		LINK__VAR_ANALOG_CTRL(aCH__HYPER_TERMINAL_CMD_TIMEOUT,str_name);
	}

	// Robot : GetInfo ...
	{
		str_name = "Robot.sGetInfo.Update.Req";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__Robot_GetInfo_Update_Req, str_name);

		//
		str_name = "sGetInfo.Version";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_Version, str_name);

		//
		str_name = "sGetInfo.RB.GetApplicationID";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_RB_GetApplicationID, str_name);

		str_name = "sGetInfo.RB.GetLocationStates";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_RB_GetLocationStates, str_name);

		str_name = "sGetInfo.RB.GetSpeed";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_RB_GetSpeed, str_name);

		str_name = "sGetInfo.RB.GetVacuumSensorValue";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_RB_GetVacuumSensorValue, str_name);

		str_name = "sGetInfo.RB.IsServoed";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_RB_IsServoed, str_name);

		//
		str_name = "sGetInfo.SYS.GetStations";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_SYS_GetStations, str_name);

		str_name = "sGetInfo.SYS.Getdevices";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_SYS_Getdevices, str_name);

		str_name = "sGetInfo.SYS.GetSafetyEnabled";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_SYS_GetSafetyEnabled, str_name);

		str_name = "sGetInfo.SYS.GetSafetyState";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_SYS_GetSafetyState, str_name);
	}

	// Aligner : GetInfo ...
	{
		str_name = "AL.sGetInfo.Update.Req";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__AL_GetInfo_Update_Req, str_name);

		//
		str_name = "sGetInfo.AL.GetEccentricityAngle";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_AL_GetEccentricityAngle, str_name);
		
		str_name = "sGetInfo.AL.GetEccentricityMagnitude";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_AL_GetEccentricityMagnitude, str_name);
		
		str_name = "sGetInfo.AL.GetEccentricityTransform";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_AL_GetEccentricityTransform, str_name);
		
		str_name = "sGetInfo.AL.GetFiducialAngle";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__GetInfo_AL_GetFiducialAngle, str_name);
	}

	// Simulation ...
	{
		str_name = "SIM.CFG.REAL.TEST";
		STD__ADD_DIGITAL(str_name, "NO YES");
		LINK__VAR_DIGITAL_CTRL(dCH__SIM_CFG__REAL_TEST, str_name);

		str_name = "SIM.CFG.ALIGN.TIME";
		STD__ADD_STRING_WITH_X_OPTION(str_name, "");
		LINK__VAR_STRING_CTRL(sCH__SIM_CFG__ALIGN_TIME, str_name);
	}

	// ...
	{
		str_name = "INR.RB1.ACT.MSG";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__ACT_MSG, str_name);

		str_name = "OTR.OUT.MON.sCOMM.STS";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__OTR_OUT_MON__COMM_STS,str_name);

		str_name = "INR.sERROR.ID.DEC";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INR__ERROR_ID_DEC,str_name);

		str_name = "INR.sERROR.ID.HEXA";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INR__ERROR_ID_HEXA,str_name);

		str_name = "INR.sALGINER.ERROR.ID";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__INR__ALGINER_ERROR_ID,str_name);

		str_name = "INR.FLAG.dALGN.STS";
		STD__ADD_DIGITAL(str_name, "ALIGNING ALIGNED");
		LINK__VAR_DIGITAL_CTRL(dCH__INR_FLAG__ALGN_STS,str_name);
	}

	// PARA CHANNEL ...
	{
		// ROBOT ...
		str_name = "PARA.ROBOT.CMMD";
		STD__ADD_DIGITAL(str_name, APP_DSP__RB_Cmd_Set);
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_ROBOT_CMMD, str_name);

		str_name = "PARA.STN.NAME";
		STD__ADD_DIGITAL(str_name, APP_DSP__STN_NAME);
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_STN_NAME, str_name);

		str_name = "PARA.STN.SLOT";
		STD__ADD_DIGITAL(str_name, APP_DSP__DSlot);
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_STN_SLOT, str_name);

		str_name = "PARA.ALING.ANGLE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__PARA_ALING_ANGLE, str_name);

		str_name = "PARA.ARM.TYPE";
		STD__ADD_DIGITAL(str_name, APP_DSP__ARM_TYPE);
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_ARM_TYPE, str_name);

		// ALx ...
		str_name = "PARA.ALx.CMMD";
		STD__ADD_DIGITAL(str_name, APP_DSP__AL_Cmd_Set);
		LINK__VAR_DIGITAL_CTRL(dCH__PARA_ALx_CMMD, str_name);

		str_name = "PARA.ALx.CCD.POS";
		STD__ADD_ANALOG(str_name, "deg", 1, 0.0, 360.0);
		LINK__VAR_ANALOG_CTRL(aCH__PARA_ALx_CCD_POS, str_name);
	}

	// CONFIG CHANNEL ...
	{
		str_name = "CFG.ACTION.CONFIRM.FLAG";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name,"DISABLE ENABLE","");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_ACTION_CONFIRM_FLAG,str_name);
	}

	// ROBOT ...
	{
		str_name = "OTR.OUT.CFG.ROM.RATE";
		STD__ADD_STRING_WITH_X_OPTION(str_name, "");
		LINK__VAR_STRING_CTRL(sCH__OTR_OUT_CFG__ROM_DATE, str_name);

		str_name = "OTR.OUT.CFG.ROM.VERSION";
		STD__ADD_STRING_WITH_X_OPTION(str_name, "");
		LINK__VAR_STRING_CTRL(sCH__OTR_OUT_CFG__ROM_VERSION, str_name);
	}

	// ...
	{
		str_name = "ROM.VERSION";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__ROM_VER,str_name);

		str_name = "ROM.DATE";
		STD__ADD_STRING_WITH_COMMENT(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__ROM_DATE,str_name);
	}

	for(i=0;i<CFG_LPx__SLOT_SIZE;i++)
	{
		str_name.Format("OTR.OUT.MON.dSLOT%02d.MAP.RESULT", i+1);
		STD__ADD_DIGITAL_WITH_COMMENT(str_name,APP_DSP__LP_WFR_SLOT_STS,"");
		LINK__VAR_DIGITAL_CTRL(dCH__LPx_SLOT_STATUS[i],str_name);
	}

	// ATMAlignOCRTime
	str_name = "CFG.aALIGN.OCR.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0.5,100.0,"recommand:4 sec");

	// AtmDynamicAlignmentDirection
	str_name.Format("CFG.dDYNAMIC.ALIGN.DIRECTION");	// 자동으로 da 하지만, 명령어 끝에 option을 줘야한다.
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name,"RETRACT EXTEND","REC:RETRACT");
	LINK__VAR_DIGITAL_CTRL(dCFG__CH__DYNAMIC_ALIGN_DIRECTION,str_name);

	// ATMPadType
	str_name = "CFG.dPAD.TYPE";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "UNKNOWN", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_PAD_TYPE,str_name);

	// ATMPickTime
	str_name = "CFG.aPICK.TIMEOUT";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0.5,100.0,"recommand:4.2 sec");
	LINK__VAR_ANALOG_CTRL(aCH__CFG__PICK_TIMEOUT, str_name);

	// ATMPlaceTime
	str_name = "CFG.aPLACE.TIMEOUT";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0.5,100.0,"recommand:4.4 sec");
	LINK__VAR_ANALOG_CTRL(aCH__CFG__PLACE_TIMEOUT, str_name);

	// ATMPlaceToAlignerTime
	str_name = "CFG.aPLACE.AND.ALIGN.TIMEOUT";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0.5,100.0,"recommand:9 sec");
	LINK__VAR_ANALOG_CTRL(aCH__CFG__PLACE_AND_ALIGN_TIMEOUT, str_name);

	// CheckWaferSlideOut
	str_name = "CFG.dMAPPING.ACTION.SLIDEOUT.CHECK";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name,"NO YES","");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_MAPPING_ACTION_SLIDE_OUT_CHECK,str_name);

	// CoverWaferAlignmentBeforeReturnToPort
	str_name = "CFG.dBEFORE.PLACE.TO.LP.ALIGN";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name,"NO YES", "");

	// DAAlignerRadialHardTolerance
	str_name = "CFG.aDA.ALIGNER.R.HARD.TOLE";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"-",0,1000,8000,"recommand:4000");

	// DAAlignerRadialSoftTolerance
	str_name = "CFG.aDA.ALIGNER.R.SOFT.TOLE";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"-",0,500,4000,"recommand:2000");

	// DAAlignerRadialThetaHardTolerance
	str_name = "CFG.aDA.ALIGNER.T.HARD.TOLE";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"-",0,75,600,"recommand:300");

	// DAAlignerRadialThetaSoftTolerance
	str_name = "CFG.aDA.ALIGNER.T.SOFT.TOLE";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"-",0,37,300,"recommand:150");

	// DisableExtendedAlign : 103
	str_name = "CFG.dDISABLE.EXTEND.ALIGN";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name,"FALSE TRUE", "");

	//
	str_name = "CFG.aBEFORE.PLACE.TO.LP.ALIGN.ANGLE";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "angle", 0, 0, 360, "recommand:180");

	// ...
	str_name = "CFG.aPADDLE.DOWN.CHECK.TIMEOUT";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 0, 1, 12, "rec:2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_LP__PADDLE_CHECK_TIME,str_name);

	// ...
	str_name = "CFG.dMAPPING.DISABLE";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "FALSE TRUE", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_MAPPING_DISABLE,str_name);

	// ...
	str_name = "CFG.dPICK.PLACE.PRESSURE.CHECK";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "DISABLE ENABLE", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_PICK_PLACE_PRESS_CHECK,str_name);

	// ...
	str_name = "CFG.dALIGN.SKIP";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "FALSE TRUE", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_ALIGN_SKIP,str_name);

	// UseSlowPickPlaceFromAirLockToCool
	str_name = "CFG.dSLOW.PICK.PLACE.FROM.LLx.TO.COOL.STN";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "rec:NO");

	// WaferAlignmentBeforePostProcessedIMMMeasurement
	str_name = "CFG.dWFR.ALGN.BEFORE.IMM.MEASURE";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "FALSE TRUE", "rec:TRUE");

	// CHECK CMMD & ERR_CODE
	{
		str_name = "PARA.CHECK.CMMD";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__PARA_CHECK_CMMD, str_name);

		str_name = "PARA.CHECK.ERR_CODE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__PARA_CHECK_ERR_CODE, str_name);
	}

	// ...
	{
		str_name = "RBx.CMMD.STATE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__RBx_CMMD_STATE, str_name);

		str_name = "ALx.CMMD.STATE";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__ALx_CMMD_STATE, str_name);
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(3.0, MON_ID__IO_MONITOR);

		p_variable->Add__MONITORING_PROC(1.0, MON_ID__RECV_PROC);
		p_variable->Add__MONITORING_PROC(1.0, MON_ID__RSPID_PROC);

		p_variable->Add__MONITORING_PROC(3.0, MON_ID__HYPER_TERMINAL_SEND);
	}
	return 1;
}


// ...
#define  ACT__RETRY_ABORT						\
l_act.RemoveAll();								\
l_act.Add("RETRY");								\
l_act.Add("ABORT");

#define  ACT__ABORT_ALARM						\
l_act.RemoveAll();								\
l_act.Add("ABORT");

#define  ACT__NO_YES_ALARM						\
l_act.RemoveAll();								\
l_act.Add("NO");								\
l_act.Add("YES");


int CObj__Driver_FUSION::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CString alarm_bff;
	CStringArray l_act;
	int alarm_id;
	int i;

	// ...
	{
		alarm_id = ALID__OFFLINE_ALARM;

		alarm_title  = title;
		alarm_title += "Offline.";

		alarm_msg  = "Controller is Offline.\n";
		alarm_msg += "Please, Check Communication Status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__ERROR_CODE_POPUP;

		alarm_title  = title;
		alarm_title += "Error Code !";

		alarm_msg = "Please, check HW status !\n";

		l_act.RemoveAll();
		l_act.Add(ACT__ABORT);
		l_act.Add(ACT__RETRY);
		l_act.Add(ACT__IGNORE);

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);	
	}
	// ...
	{
		alarm_id = ALID__ERROR_CODE_POST;

		alarm_title  = title;
		alarm_title += "Error Code !";

		alarm_msg = "Please, check HW status !\n";

		l_act.RemoveAll();
		l_act.Add(ACT__CHECK);

		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);	
	}

	// ...
	{
		alarm_id = ALID__ALGN_AND_PICK_TIMEOUT_ALARM;

		alarm_title  = title;
		alarm_title += "Align and Pick Action Timeout Occur.";

		alarm_msg  = "Align and Pick Action Timeout Occur.\n";
		alarm_msg += "Please, Check ATM Robot Status !\n";

		ACT__ABORT_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__MAPPING_DISABLE_CONFIG_ALARM;

		alarm_title  = title;
		alarm_title += "Config Option, Mapping Disable Alarm.";

		alarm_msg  = "Now, Mapping Disable Config Option Selected.\n";
		alarm_msg += "Would you like to continue ??\n";

		ACT__NO_YES_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBA__NOT_ATM_PRESSURE;

		alarm_title  = title;
		alarm_title += "LBA's Pressure is not ATM.";

		alarm_msg  = "Please, Check LBA's Pressure !\n";
		alarm_msg += "LBA's Pressure must be ATM.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBB__NOT_ATM_PRESSURE;

		alarm_title  = title;
		alarm_title += "LBB's pressure is not ATM.";

		alarm_msg  = "Please, check LBB's pressure !\n";
		alarm_msg += "LBB's pressure must be ATM.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	for(i=0; i<5; i++)
	{
		// DOOR NOT OPEN
		{
			alarm_id = ALID__LP1__NOT_DOOR_OPEN + i;

			alarm_title  = title;
			alarm_bff.Format("LP%1d's door status is not open.",i+1);
			alarm_title += alarm_bff;

			alarm_msg.Format("Please, check LP%1d's door status !\n",i+1);

			ACT__RETRY_ABORT;
			ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
		}

		// FOUP NOT EXIST
		{
			alarm_id = ALID__LP1__FOUP_NOT_EXIST + i;

			alarm_title  = title;
			alarm_bff.Format("LP%1d's foup does not exist.",i+1);
			alarm_title += alarm_bff;

			alarm_msg.Format("Please, check LP%1d's foup does not exist !\n",i+1);

			ACT__RETRY_ABORT;
			ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
		}

		// FOUP NOT CLAMP
		{
			alarm_id = ALID__LP1__FOUP_NOT_CLAMP + i;

			alarm_title  = title;
			alarm_bff.Format("LP%1d's foup does not clamp.",i+1);
			alarm_title += alarm_bff;

			alarm_msg.Format("Please, check LP%1d's foup does not clamp !\n",i+1);

			ACT__RETRY_ABORT;
			ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
		}

		// FOUP NOT LOAD
		{
			alarm_id = ALID__LP1__FOUP_NOT_LOAD + i;

			alarm_title  = title;
			alarm_bff.Format("LP%1d's foup position is not load.",i+1);
			alarm_title += alarm_bff;

			alarm_msg.Format("Please, check LP%1d's foup position is not load !\n",i+1);

			ACT__RETRY_ABORT;
			ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
		}

		// LP1, 2, 3, 4, 5... WAFER SLIDE OUT SNS
		{
			alarm_id = ALID__LP1_WFR_SLIDE_SNS_ALARM + i;

			alarm_title  = title;
			alarm_bff.Format("LP%1d's Wafer Slide Out Sns is On Status.",i+1);
			alarm_title += alarm_bff;

			alarm_msg.Format("Please, check LP%1d's Wafer Slide Status... !\n",i+1);

			ACT__RETRY_ABORT;
			ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
		}
	}

	// ...
	{
		alarm_id = ALID__LBA__NOT_DOOR_OPEN;

		alarm_title  = title;
		alarm_title += "LBA's door status is not open.";

		alarm_msg = "Please, check LBA's door status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBB__NOT_DOOR_OPEN;

		alarm_title  = title;
		alarm_title += "LBB's door status is not open.";

		alarm_msg = "Please, check LBB's door status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__INVALID__NOT_AL1_STATION;

		alarm_title  = title;
		alarm_title += "Invalid Target Station Eorror.";

		alarm_msg = "Please, check Target Station's Name !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);	
	}

	Register__ALARM_INF(p_alarm);
	return 1;
}


// ...
#define APP_DSP__Arm_ID				"A  B"
#define APP_DSP__Wfr    			"Unknown  Absent  Present"
#define APP_DSP__StrLoc 			"Normal  Retract2  NoRetract"
#define APP_DSP__Axises				"ALL  R  T  Z  W  S"

#define APP_DSP__Stn									\
"1  2  3  4  5  6  7  8  9  10							\
11 12 13 14 15 16 17 18 19 20							\
21 22 23 24 25 26 27 28 29 30"

#define APP_DSP__CurStn									\
"0														\
1  2  3  4  5  6  7  8  9  10							\
11 12 13 14 15 16 17 18 19 20							\
21 22 23 24 25 26 27 28 29 30"

#define APP_DSP__DDnUp				"DN  UP"
#define APP_DSP__OffOn              "OFF ON"
#define APP_DSP__RetExt             "RE  EX"
#define APP_DSP__ComSts             "Offline Online"
#define APP_DSP__YesNo              "Y   N"
#define APP_DSP__PrsAbs				"ON  OFF"
#define APP_DSP__ALWfr				"?  NO  YES"

#define APP_DSP__Material								\
"? 0 1 2 3 4 5 6 7 20 21 22 23 FP"

#define APP_DSP__Substrates								\
"1 2 3 4 5 6 7 20 21 22 23"

#define APP_DSP__FDCLs				"None  Flat  Ntch"
#define APP_DSP__WfrShapes			"Round  Square"
#define APP_DSP__CCDPos				"1  2  3"
#define APP_DSP__DOffOn				"Off  On"
#define APP_DSP__DZPos				"Unknown  Up  Down"
#define APP_DSP__DRPos				"Unknown  Retract  Extend"

#define APP_DSP__DTPos									\
"Unknown												\
1  2  3  4  5  6  7  8  9  10							\
11 12 13 14 15 16 17 18 19 20							\
21 22 23 24 25 26 27 28 29 30"

#define APP_DSP__DSPos									\
"Unknown												\
1  2  3  4  5  6  7  8  9  10							\
11 12 13 14 15 16 17 18 19 20							\
21 22 23 24 25 26 27 28 29 30"


int CObj__Driver_FUSION::__DEFINE__VARIABLE_IO(p_io_variable)
{
	DECLARE__IO_VARIABLE;

	CString str_name;

	// Analog ...
	{
		// AO  -----------------------------
		{
			str_name = "ao.Align.Slot";
			IO__ADD_ANALOG_WRITE(str_name, "slot", 0,1.0,2.0);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ALIGN_SLOT, str_name);

			str_name = "ao.Angle";
			IO__ADD_ANALOG_WRITE(str_name, "deg", 1,0.0,360.0);
			LINK__IO_VAR_ANALOG_CTRL(aoCH__ANGLE, str_name);
		}

		// AI  -----------------------------
		{
			str_name = "ai.AngPos";
			IO__ADD_ANALOG_READ__MANUAL(str_name, "deg", 1,-360.0,360.0);
			LINK__IO_VAR_ANALOG_CTRL(aiCH__ANG_POS, str_name);

			str_name = "ai.AngEcc";
			IO__ADD_ANALOG_READ__MANUAL(str_name, "deg", 1,-360.0,360.0);
			LINK__IO_VAR_ANALOG_CTRL(aiCH__ANG_ECC, str_name);

			str_name = "ai.EccMag";
			IO__ADD_ANALOG_READ__MANUAL(str_name, "mils",1,0.0,300.0);
			LINK__IO_VAR_ANALOG_CTRL(aiCH__ECC_MAG, str_name);

			str_name = "ai.AvrgRd";
			IO__ADD_ANALOG_READ__MANUAL(str_name, "deg",1,-360.0,360.0);
			LINK__IO_VAR_ANALOG_CTRL(aiCH__AVRG_RD, str_name);

			str_name = "ai.ErrorId";
			IO__ADD_ANALOG_READ__MANUAL(str_name, "num",0,0,99999);
			LINK__IO_VAR_ANALOG_CTRL(aiCH__ERROR_ID, str_name);
		}
	}

	// Digital ...
	{
		// DO  -----------------------------
		{
			str_name = "do.RBx.Command";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__RB_Cmd_Set);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__RBx_CMMD, str_name);

			str_name = "do.ALx.Command";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__AL_Cmd_Set);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ALx_CMMD, str_name);

			str_name = "do.ALx.Report";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__AL_Cmd_Report);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ALx_REPORT, str_name);

			//
			str_name = "do.Stn_Name";
			IO__ADD_STRING_WRITE(str_name);
			LINK__IO_VAR_STRING_CTRL(soCH__STN_NAME, str_name);

			str_name = "do.Arm";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__Arm_ID);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__ARM, str_name);

			str_name = "do.Slot";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__DSlot);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__SLOT, str_name);

			str_name = "do.WfrSize";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__Substrates);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__WFR_SIZE, str_name);

			str_name = "do.WfrFDCL";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__FDCLs);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__WFR_FDCL, str_name);

			str_name = "do.WfrShape";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__WfrShapes);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__WFR_SHAPE, str_name);

			str_name = "do.WfrCCD";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__CCDPos);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__WFR_CCD, str_name);

			str_name = "do.Material";
			IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__Material);
			LINK__IO_VAR_DIGITAL_CTRL(doCH__MATERIAL, str_name);

			//
			str_name = "do.System.TrackingMaterial";
			IO__ADD_DIGITAL_WRITE(str_name, "False True Data");
			LINK__IO_VAR_DIGITAL_CTRL(doCH__SYSTEM_TRACKING_MATERIAL, str_name);
		}

		// DI  -----------------------------
		{
			str_name = "di.ComSts";
			IO__ADD_DIGITAL_READ(str_name, APP_DSP__ComSts);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__COMM_STS, str_name);

			str_name = "di.ArmAWfr";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__Wfr);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__ARM_A_WFR, str_name);

			str_name = "di.VacSnsA";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__PrsAbs);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__VAC_SNS_A, str_name);

			str_name = "di.Rescan";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__YesNo);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__RESCAN, str_name);

			str_name = "di.CurrStn";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__CurStn);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__CURR_STN, str_name);

			str_name = "di.VacStsA";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__OffOn);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__VAC_STS_A, str_name);

			str_name = "di.ALWfr";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__ALWfr);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__AL_WFR, str_name);

			// ...
			str_name = "di.Robot.CurrPos";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__DOffOn);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_CURR_POS, str_name);

			//
			str_name = "di.Robot.Z.Pos";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__DZPos);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_Z_POS, str_name);

			str_name = "di.Robot.AR.Pos";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__DRPos);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_AR_POS, str_name);

			str_name = "di.Robot.T.Pos";
			IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__DTPos);
			LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_T_POS, str_name);
		}
	}

	// String ...
	{
		// SO  -----------------------------
		{
			str_name = "eso.RB1.HyperTerminal.Command";
			IO__ADD_STRING_WRITE(str_name);
			LINK__IO_VAR_STRING_CTRL(soCH__HYPER_TERMINAL_CMD, str_name);

			str_name = "eso.RB1.GetInfo.Command";
			IO__ADD_STRING_WRITE(str_name);
			LINK__IO_VAR_STRING_CTRL(soCH__GET_INFO_CMD, str_name);

			//
			str_name = "so.Check.Cmmd";
			IO__ADD_STRING_WRITE(str_name);
			LINK__IO_VAR_STRING_CTRL(soCH__CHECK_CMMD, str_name);
		}

		// SI  -----------------------------
		{
			str_name = "si.RBx.GetMap";
			IO__ADD_STRING_READ__MANUAL(str_name);
			LINK__IO_VAR_STRING_CTRL(siCH__RBx_GetMap, str_name);

			str_name = "si.LPx.GetMap";
			IO__ADD_STRING_READ__MANUAL(str_name);
			LINK__IO_VAR_STRING_CTRL(siCH__LPx_GetMap, str_name);

			str_name = "si.ALx.RESULT";
			IO__ADD_STRING_READ__MANUAL(str_name);
			LINK__IO_VAR_STRING_CTRL(siCH__ALx_RESULT, str_name);
		}
	}

	return 1;
}

//--------------------------------------------------------------------------------
int CObj__Driver_FUSION::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{
	// APP LOG ...
	{
		iFlag__APP_LOG = 1;

		// ...
		CString file_name;
		CString log_msg;

		file_name.Format("%s_App.log", sObject_Name);

		log_msg  = "\n\n";
		log_msg += "//------------------------------------------------------------------------";

		xAPP_LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
		xAPP_LOG_CTRL->SET__PROPERTY(file_name,24*5,60);

		xAPP_LOG_CTRL->DISABLE__TIME_LOG();
		xAPP_LOG_CTRL->WRITE__LOG(log_msg);

		xAPP_LOG_CTRL->ENABLE__TIME_LOG();
		xAPP_LOG_CTRL->WRITE__LOG("   START   \n");
	}

	// DRV LOG ...
	{
		iFlag__DRV_LOG = 1;

		// ...
		CString file_name;
		CString log_msg;

		file_name.Format("%s_Drv.log", sObject_Name);

		log_msg  = "\n\n";
		log_msg += "//------------------------------------------------------------------------";

		xDRV_LOG_CTRL->CREATE__SUB_DIRECTORY(sObject_Name);
		xDRV_LOG_CTRL->SET__PROPERTY(file_name,24*5,60);

		xDRV_LOG_CTRL->DISABLE__TIME_LOG();
		xDRV_LOG_CTRL->WRITE__LOG(log_msg);

		xDRV_LOG_CTRL->ENABLE__TIME_LOG();
		xDRV_LOG_CTRL->WRITE__LOG("   START   \n");
	}

	// ...
	{
		SCX__SEQ_INFO x_seq_info;

		iActive__SIM_MODE = x_seq_info->Is__SIMULATION_MODE();
		iCFG__SIM_MODE = -1;
	}
	return 1;
}
int CObj__Driver_FUSION::__INITIALIZE__IO(p_io_para)
{
	//-------------------------------------------------------
	// Set Driver Parameter
	//------------------------------------------------------

	CString net_ip   = "127.0.0.1";
	CString net_port = "10001";

	// ...
	{
		CString para_cmmd;
		CString para_data;

		// 1. IP
		{
			para_cmmd = "IP";

			if(p_io_para->Get__PARAMETER_DATA(para_cmmd, para_data) > 0)
			{
				net_ip = para_data;
			}
		}
		// 2. Port
		{
			para_cmmd = "PORT";

			if(p_io_para->Get__PARAMETER_DATA(para_cmmd, para_data) > 0)
			{
				net_port = para_data;
			}
		}
	}
	
	// ...
	{
		CString end_str = "";
		
		end_str  = (char) __CR;
		end_str += (char) __LF;

		int end_len = end_str.GetLength();

		mX_Net->SET__TERMINAL_InSTRING( end_str, end_len);
		mX_Net->SET__TERMINAL_OutSTRING(end_str, end_len);
	}

	// ...
	{
		iDRV__ALGNER_ERROR_ID = 0;
		iDRV__ERROR_ID = 0;
		sDRV__STN_NAME = "";
		sDRV__ARM_NO   = "A";

		iDRV__SLOT_NO = 1;
		sDRV__RB_VAC_SNS_A = "OFF";
		sDRV__RB_VAC_SNS_B = "OFF";
		dDRV__RB_FIND_BIAS_SET = 0.0;
		sDRV__RB_MATERIAL  = "7";       // 6: 200mm  7: 300mm
		sDRV__RB_WFR_SHAPE = "ROUND";
		sDRV__RB_WFR_SIZE  = "7";
		sDRV__RB_WFR_FDCL  = "Ntch";
		
		iDRV__ANGLE_SLOT   = 1;
		dDRV__RB_ANGLE_DEG = 0.0;
		dDRV__RB_ANGLE_POS = 0.0;
		dDRV__RB_ANGLE_ECC = 0.0;
		dDRV__RB_ECC_MAG   = 0.0;
		dDRV__RB_AVG_RD    = 0.0;

		iDRV__RB_WFR_CCD = 2;			// 2: 300mm

		sDRV__RB_Z_POS  = "Unknown";
		sDRV__RB_AR_POS = "Unknown";
		sDRV__RB_BR_POS = "Unknown";
		sDRV__RB_T_POS  = "Unknown";
		sDRV__RB_S_POS  = "Unknown";

		iDRV__ECC_MAG   = 0;
		iDRV__ANGLE_POS = 0;
		iDRV__ANGLE_ECC = 0;
		iDRV__AVG_RD    = 0;

		dDRV__DELTA_R = 0.0;
		dDRV__DELTA_T = 0.0; 

		sDRV__RESCAN = "N";
	}

	// ...
	CString log_msg;
	CString log_bff;

	CString str_data;

	// ...
	{
		sEnd_InStr  = mX_Net->GET__TERMINAL_InSTRING();	
		sEnd_OutStr = mX_Net->GET__TERMINAL_OutSTRING();
	}

	// ...
	{
		log_msg.Format("Connecting to Ethernet ... \n");

		log_bff.Format("Net_IP : %s \n", net_ip);
		log_msg += log_bff;

		log_bff.Format("Net_Port : %s \n", net_port);
		log_msg += log_bff;

		//
		m_nRetryCount = 2;

		log_bff.Format(" * Retry Count: %1d \n", m_nRetryCount);
		log_msg += log_bff;

		//
		m_nTimeout = 1;			// 1 sec
		m_Rcv_Time = m_nTimeout;

		log_bff.Format(" * Recv_Timeout: %1d sec \n", m_nTimeout);
		log_msg += log_bff;

		//
		m_Out_Time = 10;		// 10 sec

		log_bff.Format("Action_Timeout: %1d sec \n", m_Out_Time);
		log_msg += log_bff;

		//
		log_bff.Format("End_InStr  : %s \n", sEnd_InStr);
		log_msg += log_bff;

		log_bff.Format("End_OutStr : %s \n", sEnd_OutStr);
		log_msg += log_bff;

		//
		xAPP_LOG_CTRL->WRITE__LOG(log_msg);
		xDRV_LOG_CTRL->WRITE__LOG(log_msg);
	}

	// ...
	CString err_msg;
	printf("%s : Connecting (%s %s) ... \n", sObject_Name, net_ip,net_port);

	mX_Net->INIT__PROPERTY(net_ip, atoi(net_port));
	if(mX_Net->CONNECT(&err_msg) < 0)
	{
		log_msg = "Connection Result ... \n";
		log_bff.Format("Fail to do INIT__ETHERNET: %s(%s), ret(-1) \n", net_ip,net_port);
		log_msg += log_bff;
		log_bff.Format(" * Error Message <- \"%s\" \n", err_msg);
		log_msg += log_bff;

		printf("%s : %s", sObject_Name, log_msg);
		xDRV_LOG_CTRL->WRITE__LOG(log_msg);

		diCH__COMM_STS->Set__DATA(STR__OFFLINE);
	}
	else
	{
		log_msg = "Connection Result ... \n";
		log_msg += "Init-Ethernet Completed ... \n";

		printf("%s : %s", sObject_Name, log_msg);
		xDRV_LOG_CTRL->WRITE__LOG(log_msg);

		diCH__COMM_STS->Set__DATA(STR__ONLINE);
	}
	return 1;
}


//--------------------------------------------------------------------------------
int CObj__Driver_FUSION::__CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm)
{
LOOP_RETRY:
	
	// ...
	mMNG__ERR_CODE.Clear__Error_Code();

	// For Hyper Terminal Interlock !!
	xCH__LOCK_FLAG->Set__DATA("YES");		//	Lock을 건다.

	// ...
	int flag = -1;

	CString para__arm_type;
	CString para__stn_name;
	CString para__stn_slot;
	CString para__align_angle;

	CString szUpperObj;

	CStringArray l_para;
	p_variable->Get__FNC_PARAMETER(l_para);

	if(mode.CompareNoCase(sMODE__ROBOT_CMMD) == 0)
	{
		if(l_para.GetSize() > 0)
		{
			CString para_data;

			int limit = l_para.GetSize();
			int i;

			for(i=0;i<limit;i++)
			{
				para_data = l_para[i];

				switch(i)
				{
					case 0:		
						dCH__PARA_ARM_TYPE->Set__DATA(para_data);
						break;

					case 1:
						dCH__PARA_STN_NAME->Set__DATA(para_data);
						break;

					case 2:
						dCH__PARA_STN_SLOT->Set__DATA(para_data);
						break;
				}	
			}
		} 

		dCH__PARA_ARM_TYPE->Get__DATA(para__arm_type);
		dCH__PARA_STN_NAME->Get__DATA(para__stn_name);
		dCH__PARA_STN_SLOT->Get__DATA(para__stn_slot);

		// ...
		{
			CString log_msg;

			log_msg.Format("Start ... :  [%s] (%s,%s,%s)",
							mode,
							para__arm_type,
							para__stn_name,
							para__stn_slot);

			Fnc__APP_LOG(log_msg);
			Fnc__ACT_MSG(log_msg);
		}
	}
	else if(mode.CompareNoCase(sMODE__ALx_CMMD) == 0)
	{
		if(l_para.GetSize() > 0)
		{
			dCH__PARA_STN_NAME->Set__DATA("AL1");

			int i_limit = l_para.GetSize();
			int i;

			for(i=0; i<i_limit; i++)
			{
				CString para_data = l_para[i];

					 if(i == 0)		dCH__PARA_STN_SLOT->Set__DATA(para_data);
				else if(i == 1)		sCH__PARA_ALING_ANGLE->Set__DATA(para_data);
			}
		} 

		dCH__PARA_STN_NAME->Get__DATA(para__stn_name);
		dCH__PARA_STN_SLOT->Get__DATA(para__stn_slot);
		sCH__PARA_ALING_ANGLE->Get__DATA(para__align_angle);

		// ...
		CString log_msg;

		log_msg.Format("Start ... :  [%s] (%s,%s) (%s deg)",
						mode,
						para__stn_name,
						para__stn_slot,
						para__align_angle);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);
	}
	else
	{
		CString log_msg;

		log_msg.Format("Start ... :  [%s]", mode);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);
	}

	// ...
	int seq_flag = 1;

	if(dCH__CFG_ACTION_CONFIRM_FLAG->Check__DATA(STR__ENABLE) > 0)
	{
		CString log_msg;

		CString str_title;
		CString str_msg;
		CString str_bff;
		CStringArray l_act;
		CString r_act;

		str_title.Format("%s - Action Confirm Flag", sObject_Name);

		str_bff.Format("Object Mode : [%s] \n", mode);
		str_msg += str_bff;
		str_bff.Format("Arm Type : [%s] \n", para__arm_type);
		str_msg += str_bff;
		str_bff.Format("Station Name : [%s] \n", para__stn_name);
		str_msg += str_bff;
		str_bff.Format("Station Slot : [%s] \n", para__stn_slot);
		str_msg += str_bff;

		l_act.RemoveAll();
		l_act.Add(STR__YES);
		l_act.Add(STR__NO);

		p_alarm->Popup__MESSAGE_BOX(str_title,str_msg,l_act,r_act);

		if(r_act.CompareNoCase(STR__NO) == 0)
		{
			seq_flag = -1;

			CString log_msg = "Confirm : Action No Clicked !";

			Fnc__APP_LOG(log_msg);
			Fnc__ACT_MSG(log_msg);
		}
	}

	if(seq_flag > 0)
	{
		pII__EXT_MODE_CTRL = p_variable->Get__EXT_FNC_MODE_CTRL();
		pII__EXT_VAR_CTRL  = p_variable->Get__EXT_FNC_VAR_CTRL();
		pII__EXT_FNC_CTRL  = p_variable->Get__EXT_USER_FNC_CTRL();

		// ...
		{
			CString log_msg;

			szUpperObj = pII__EXT_MODE_CTRL->Get__UPPER_OBJECT_NAME();	
		
			log_msg.Format("Object Call: [%s] ==> [%s]",  szUpperObj,sObject_Name);
			Fnc__APP_LOG(log_msg);
		}

			 IF__CTRL_MODE(sMODE__INIT)					flag = Call__INIT(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ROBOT_CMMD)			flag = Call__ROBOT_CMMD(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ALx_CMMD)				flag = Call__ALx_CMMD(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__ALx_RESULT)			flag = Call__ALx_RESULT(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__CHECK_CMMD)			flag = Call__CHECK_CMMD(p_variable, p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__CHECK_ERR_CODE)		flag = Call__CHECK_ERR_CODE(p_variable, p_alarm);
	}
	else
	{
		flag = -1;
	}

	// ...
	{
		CString err_code;
		CString err_msg;

		while(mMNG__ERR_CODE.Get__Error_Code(err_code,err_msg) > 0)
		{
			int i_error = atoi(err_code);
			if(i_error == 0)		continue;
			
			// ...
			{
				CString log_msg;
				CString log_bff;

				log_msg = "Error_Code Occurred !!!";

				log_bff.Format("Error_Code : [%s] \n", err_code);
				log_msg += log_bff;
				log_bff.Format("Error_Msg  : [%s] \n", err_msg);
				log_msg += log_bff;

				Fnc__APP_LOG(log_msg);
			}

			// ...
			int alm_id = ALID__ERROR_CODE_POPUP;
			CString alm_msg;
			CString alm_bff;
			CString r_act;

			alm_msg.Format("Control_Mode : %s \n", mode);

			alm_bff.Format("Error_Code : %s \n", err_code);
			alm_msg += alm_bff;
			alm_bff.Format("Error_Message \n");
			alm_msg += alm_bff;
			alm_msg += "  * ";
			alm_msg += err_msg;

			// ...
			{
				CString log_msg;

				log_msg.Format("Alarm Post : %1d \n", alm_id);
				log_msg += alm_msg;

				Fnc__APP_LOG(log_msg);
			}

			p_alarm->Popup__ALARM_With_MESSAGE(alm_id,alm_msg,r_act);			

			if(r_act.CompareNoCase(ACT__RETRY) == 0)
			{
				// ...
				{
					CString log_msg = "Alarm Selection <- Retry";
					Fnc__APP_LOG(log_msg);
				}

				goto LOOP_RETRY;
			}
			if(r_act.CompareNoCase(ACT__ABORT) == 0)
			{
				// ...
				{
					CString log_msg = "Alarm Selection <- Abort";
					Fnc__APP_LOG(log_msg);
				}

				flag = -1;
			}

			if(r_act.CompareNoCase(ACT__IGNORE) == 0)
			{
				// ...
			}
		}
	}

	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		CString log_msg;	
		log_msg.Format("Aborted ... :  [%s]\n", mode);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);
	}
	else
	{
		CString log_msg;
		log_msg.Format("Completed ... :  [%s]\n", mode);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);
	}

	return flag;
}

int CObj__Driver_FUSION::__CALL__MONITORING(id, p_variable, p_alarm)
{
	switch(id)
	{
		case MON_ID__IO_MONITOR:
			Mon__IO_MONITOR(p_variable,p_alarm);
			break;

		case MON_ID__RECV_PROC:
			Mon__RECV_PROC(p_variable, p_alarm);
			break;

		case MON_ID__RSPID_PROC:
			Mon__RSPID_PROC(p_variable, p_alarm);
			break;

		case MON_ID__HYPER_TERMINAL_SEND:
			Mon__HYPER_TERMINAL_SEND(p_variable, p_alarm);
			break;
	}

	return 1;
}
