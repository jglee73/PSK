#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"
#include "CObj__VacRobot_PSK__ALID.h"

#include "CCommon_DEF.h"


//--------------------------------------------------------------------------------
CObj__VacRobot_PSK::CObj__VacRobot_PSK()
{
	m_sErrorID  =   "0";
	m_sStationA =	"1";
	m_sStationB =	"1";
	m_sCptr_StationA = "1";
	m_sCptr_StationB = "1";
	m_sRPos     =	"RE"; 
	m_sZPos		=	"DN"; 
	m_sSlot		=	"1";

	m_sBefore_Stn_Retract_ArmA = "UNKNOWN";
	m_sBefore_Stn_Retract_ArmB = "UNKNOWN";

	iMsg_ID = 0;
}
CObj__VacRobot_PSK::~CObj__VacRobot_PSK()
{

}

//--------------------------------------------------------------------------------
int CObj__VacRobot_PSK::__DEFINE__CONTROL_MODE(obj,l_mode)
{
	sObject_Name = obj;

	// ...
	{
		ADD__CTRL_VAR(sMODE__INIT,		"INIT");

		ADD__CTRL_VAR(sMODE__PICK,		"PICK");
		ADD__CTRL_VAR(sMODE__PLACE,		"PLACE");
		ADD__CTRL_VAR(sMODE__ROTATE,	"ROTATE");
		ADD__CTRL_VAR(sMODE__HOME,		"HOME");
		ADD__CTRL_VAR(sMODE__MAP,		"MAP");

		ADD__CTRL_VAR(sMODE__EXTEND,	"EXTEND");
		ADD__CTRL_VAR(sMODE__RETRACT,	"RETRACT");
		ADD__CTRL_VAR(sMODE__GOUP,		"GOUP");
		ADD__CTRL_VAR(sMODE__GODOWN,	"GODOWN");
		ADD__CTRL_VAR(sMODE__RQ_STN,	"RQ_STN");

		ADD__CTRL_VAR(sMODE__TEACHED_CPTR_SAVE, "TEACHED_CPTR_SAVE");

		ADD__CTRL_VAR(sMODE__CHECK_CMMD,     "CHECK.CMMD");
		ADD__CTRL_VAR(sMODE__CHECK_ERR_CODE, "CHECK.ERR_CODE");
	}
	return 1;
}
int CObj__VacRobot_PSK::__DEFINE__VERSION_HISTORY(version)
{
	version = "JG.Lee \n";

	return 1;
}


// ...
#define  MON_ID__ANI_MONITOR			1
#define  MON_ID__IO_MONITOR				2
#define  MON_ID__HYPER_TERMINAL			3

// ...
#define  APP_DSP__STN_NAME				"PM1 PM2 PM3 PM4 PM5 PM6  LBA LBB"
#define  APP_DSP__SLOT_NUM				"1 2 3 4"
#define  APP_DSP__RB_ARM				"A  B  AB"
#define  APP_DSP__RET_EXT				"Retract  Extend"
#define  APP_DSP__DOWN_UP				"Down  Up"
#define  APP_DSP__ARM_STS_ANI			"UNKNOWN  RETRACT  EXTEND"


int CObj__VacRobot_PSK::__DEFINE__VARIABLE_STD(p_variable)
{
	DECLARE__STD_VARIABLE

	CCommon_Error__DEF_VARIABLE m_err_def_variable;
	p_variable->Link__DEF_VARIABLE__ERROR_FEEDBACK(&m_err_def_variable);

	// ...
	CString str_name;
	CString str_comment;
	CString def_name, def_data;
	int i;

	// Hyper Terminal ����... !!
	str_name = "sHYPER.TERMINAL.UPDATE.FLAG";
	STD__ADD_STRING_WITH_COMMENT(str_name, "");
	LINK__VAR_STRING_CTRL(xCH__UPDATE_FLAG, str_name);

	str_name = "dHYPER.TERMINAL.LOCK.FLAG";
	STD__ADD_DIGITAL_WITH_COMMENT(str_name, "YES NO","");
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


	// DA CHART...
	for(i=0; i<CFG_PMx__SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("dDA.PM%1d.CHART.ARM.A.UPDATE.FLAG", id);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_PMC_CHART_ARM_A_UPDATE_FLAG_X[i], str_name);

		str_name.Format("dDA.PM%1d.CHART.ARM.B.UPDATE.FLAG", id);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_PMC_CHART_ARM_B_UPDATE_FLAG_X[i], str_name);

		str_name.Format("dDA.PM%1d.CHART.DATA.CLEAR", id);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_PMC_CHART_DATA_CLEAR_X[i], str_name);
	}

	// PM : DA CHART ...
	for(i=0; i<CFG_PMx__SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("sDA.PM%1d.CHART.ARM.A.ROFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_ARM_A_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.PM%1d.CHART.ARM.A.TOFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_ARM_A_TOFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.PM%1d.CHART.ARM.B.ROFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_ARM_B_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.PM%1d.CHART.ARM.B.TOFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_ARM_B_TOFFSET_DISPLAY_X[i], str_name);
	}

	// LL : DA CHART ...
	for(i=0; i<CFG_LBx__SIZE; i++)
	{
		CString ll_name;

			 if(i == 0)			ll_name = "LBA";
		else if(i == 1)			ll_name = "LBB";
		else					continue;

		// A ARM
		str_name.Format("sDA.%s.CHART.ARM.A.ROFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_ARM_A_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.%s.CHART.ARM.A.TOFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_ARM_A_TOFFSET_DISPLAY_X[i], str_name);

		// B ARM 
		str_name.Format("sDA.%s.CHART.ARM.B.ROFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_ARM_B_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.%s.CHART.ARM.B.TOFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_ARM_B_TOFFSET_DISPLAY_X[i], str_name);

		//
		str_name.Format("dDA.%s.CHART.ARM.A.UPDATE.FLAG", ll_name);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_LL_CHART_ARM_A_UPDATE_FLAG_X[i], str_name);

		str_name.Format("dDA.%s.CHART.ARM.B.UPDATE.FLAG", ll_name);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_LL_CHART_ARM_B_UPDATE_FLAG_X[i], str_name);

		str_name.Format("dDA.%s.CHART.DATA.CLEAR", ll_name);
		STD__ADD_DIGITAL(str_name, "OFF ON");
		LINK__VAR_DIGITAL_CTRL(dDA_LL_CHART_DATA_CLEAR_X[i], str_name);

		//
		str_name.Format("sDA.%s.CHART.ROFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.%s.CHART.TOFFSET.DISPLAY", ll_name);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_LL_CHART_TOFFSET_DISPLAY_X[i], str_name);
	}

	// DA Offset ...
	{
		str_name = "DA.RESULT.R_OFFSET.DEG";	// deg
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DA_RESULT_R_OFFSET_DEG, str_name);

		str_name = "DA.RESULT.T_OFFSET.MM";		// mm
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__DA_RESULT_T_OFFSET_MM, str_name); 

		//
		str_name = "aCH.RETRACT.R.OFFSET.VALUE";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
		LINK__VAR_ANALOG_CTRL(aCH__RETRACT_R_OFFSET_VALUE,str_name);

		str_name = "aCH.RETRACT.T.OFFSET.VALUE";
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "milideg", 0, -9999999, 9999999, "");
		LINK__VAR_ANALOG_CTRL(aCH__RETRACT_T_OFFSET_VALUE,str_name);
	}

	//
	for(i=0; i<CFG_PMx__SIZE; i++)
	{
		int id = i + 1;

		str_name.Format("sDA.PM%1d.CHART.ROFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_ROFFSET_DISPLAY_X[i], str_name);

		str_name.Format("sDA.PM%1d.CHART.TOFFSET.DISPLAY", id);
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sDA_PMC_CHART_TOFFSET_DISPLAY_X[i], str_name);
	}

	// DA Retry Count
	str_name = "aDA.DA.RETRY.CHECK.COUNT";
	STD__ADD_ANALOG(str_name, "Num",0,1,5);
	LINK__VAR_ANALOG_CTRL(aDA_DA_RETRY_CHECK_COUNT,str_name);

	// Simulation ...
	str_name = "SIM.CFG.REAL.TEST";
	STD__ADD_DIGITAL(str_name, "NO YES");
	LINK__VAR_DIGITAL_CTRL(dCH__SIM_CFG__REAL_TEST, str_name);

	//
	str_name = "INR.RB1.ACT.MSG";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__ACT_MSG, str_name);

	str_name = "INR.RB1.ERRID";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__ERRID, str_name);

	str_name = "OTR.OUT.MON.sCOMM.STS";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__OTR_OUT_MON__COMM_STS,str_name);

	str_name = "CH.FILE.SZROOT.STS";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__szRoot,str_name);

	// PARA CHANNEL ...
	str_name = "OTR.IN.PARA.dSTN.NAME";
	STD__ADD_DIGITAL(str_name, APP_DSP__STN_NAME);
	LINK__VAR_DIGITAL_CTRL(dCH__OTR_IN_PARA__STN_NAME,str_name);

	str_name = "OTR.IN.PARA.dSTN.SLOT";
	STD__ADD_DIGITAL(str_name, APP_DSP__SLOT_NUM);
	LINK__VAR_DIGITAL_CTRL(dCH__OTR_IN_PARA__STN_SLOT,str_name);

	str_name = "OTR.IN.PARA.dARM.TYPE";
	STD__ADD_DIGITAL(str_name, APP_DSP__RB_ARM);
	LINK__VAR_DIGITAL_CTRL(dCH__OTR_IN_PARA__ARM_TYPE,str_name);

	str_name = "dACTION.STATUS";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__ACTION_STS, str_name);

	str_name.Format("OTR.IN.sARM_A.BEFORE.MODE.STS");
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__ARM_A_BEFORE_MODE_STS,str_name);

	str_name.Format("OTR.IN.sARM_B.BEFORE.MODE.STS");
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__ARM_B_BEFORE_MODE_STS,str_name);

	str_name.Format("OTR.IN.aSET.STN.R.VALUE");
	STD__ADD_ANALOG(str_name, "microns", 0, -9999999, 9999999);
	LINK__VAR_ANALOG_CTRL(aCH__SET_STN_R_VALUE,str_name);

	str_name.Format("OTR.IN.aSET.STN.T.VALUE");
	STD__ADD_ANALOG(str_name, "microns", 0, -9999999, 9999999);
	LINK__VAR_ANALOG_CTRL(aCH__SET_STN_T_VALUE,str_name);

	str_name.Format("OTR.IN.sGUI.DISPLAY.R.OFFSET");
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__Estimated_R_OFFSET,str_name);

	str_name.Format("OTR.IN.sGUI.DISPLAY.T.OFFSET");
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__Estimated_T_OFFSET,str_name);

	// LLx ...
	for(i=0; i<CFG_LBx__SIZE; i++)
	{
		CString ll_name;

			 if(i == 0)			ll_name = "LBA";
		else if(i == 1)			ll_name = "LBB";
		else					continue;

		int ll_id = i + 1;

		// Hard
		str_name.Format("OTR.IN.CFG.%s.R.OFFSET.HARD.TOLERANCE.RET", ll_name);
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mm", 1, 0, 4, "");
		LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__R_OFFSET_HARD_TOLERANCE_LL_RET_X[i], str_name);

		str_name.Format("OTR.IN.CFG.%s.T.OFFSET.HARD.TOLERANCE.RET", ll_name);
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "degree", 1, 0, 2, "");
		LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__T_OFFSET_HARD_TOLERANCE_LL_RET_X[i], str_name);

		// Soft
		str_name.Format("OTR.IN.CFG.%s.R.OFFSET.SOFT.TOLERANCE.RET", ll_name);
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mm", 1, 0, 4, "");
		LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__R_OFFSET_SOFT_TOLERANCE_LL_RET_X[i], str_name);

		str_name.Format("OTR.IN.CFG.%s.T.OFFSET.SOFT.TOLERANCE.RET", ll_name);
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "degree", 1, 0, 2, "");
		LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__T_OFFSET_SOFT_TOLERANCE_LL_RET_X[i], str_name);

		// STN.NUM
		str_name.Format("CFG.%s.STN.NUM", ll_name);
		STD__ADD_ANALOG_WITH_X_OPTION(str_name, "num", 0, 1, 16, "");
		LINK__VAR_ANALOG_CTRL(aCH__CFG_LLx_STN_NUM[i], str_name);

		// ARM_A ...
		{
			// HIGH ...
			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.R.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.T.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.Z.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[i], str_name);

			// LOW ...
			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.R.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_R_LOW_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.T.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_T_LOW_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_A.CPTR.Z.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[i], str_name);
		}
		// ARM_B ...
		{
			// HIGH ...
			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.R.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_HIGH_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.T.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_HIGH_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.Z.HIGH.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_HIGH_SNS_VAL_X[i], str_name);

			// LOW ...
			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.R.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_R_LOW_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.T.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_T_LOW_SNS_VAL_X[i], str_name);

			str_name.Format("OTR.IN.CALED.ARM_B.CPTR.Z.LOW.SNS.LL%1d.VALUE", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
			LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_LL_CPTR_Z_LOW_SNS_VAL_X[i], str_name);
		}

		// ... 
		{
			str_name.Format("CFG.CPTR.SNS.LL%1d.NUM", ll_id);
			STD__ADD_ANALOG_WITH_X_OPTION(str_name, "num", 0, 1, 10, "");
			LINK__VAR_ANALOG_CTRL(aCH__CFG_CPTR_SNS__LLx_NUM[i], str_name);
		}

		// CFG : DYNAMIC ...
		{
			str_name.Format("CFG.LL%1d.DA.USE", ll_id);
			STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
			LINK__VAR_DIGITAL_CTRL(dCH__CFG_LLx_DA_USE[i], str_name);
		}
	}

	// DA Sensor ...
	{
		str_name = "CFG.DA.SENSOR.TYPE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "YES REPORT", "");
		LINK__VAR_DIGITAL_CTRL(dCH__CFG_DA_SENSOR_TYPE, str_name);
	}

	// LL INFO ...
	{
		def_name = "LL_SIZE";
		p_variable->Get__DEF_CONST_DATA(def_name, def_data);

		iCFG__LL_SIZE = atoi(def_data);
		if(iCFG__LL_SIZE > CFG_LBx__SIZE)		iCFG__LL_SIZE = CFG_LBx__SIZE;	
	}

	// PM INFO ...
	{
		def_name = "PM_SIZE";
		p_variable->Get__DEF_CONST_DATA(def_name, def_data);

		iCFG__PM_SIZE = atoi(def_data);
		if(iCFG__PM_SIZE > CFG_PMx__SIZE)		iCFG__PM_SIZE = CFG_PMx__SIZE;

		for(i=0; i<iCFG__PM_SIZE; i++)
		{
			int id = i + 1;

			//
			{
				str_name.Format("CFG.PM%1d.STN.NUM", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "num", 0, 1, 16, "");
				LINK__VAR_ANALOG_CTRL(aCH__CFG_PMx_STN_NUM[i], str_name);
			}

			// VAC_RB CPTR Sensor Number
			{
				str_name.Format("CFG.CPTR.SNS.PM%1d.NUM", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "num", 0, 1, 10, "");
				LINK__VAR_ANALOG_CTRL(aCH__CFG_CPTR_SNS__PMx_NUM[i], str_name);
			}
			// CFG Range (R and T Offset)
			{

			}

			// Hard
			{
				str_name.Format("OTR.IN.CFG.PM%1d.R.OFFSET.HARD.TOLERANCE.RET", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mm", 1, 0, 4, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__R_OFFSET_HARD_TOLERANCE_RET[i], str_name);

				str_name.Format("OTR.IN.CFG.PM%1d.T.OFFSET.HARD.TOLERANCE.RET", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "degree", 1, 0, 2, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__T_OFFSET_HARD_TOLERANCE_RET[i], str_name);
			}
			// Soft
			{
				str_name.Format("OTR.IN.CFG.PM%1d.R.OFFSET.SOFT.TOLERANCE.RET", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "mm", 1, 0, 4, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__R_OFFSET_SOFT_TOLERANCE_RET[i], str_name);

				str_name.Format("OTR.IN.CFG.PM%1d.T.OFFSET.SOFT.TOLERANCE.RET", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "degree", 1, 0, 2, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_CFG__T_OFFSET_SOFT_TOLERANCE_RET[i], str_name);
			}

			// ARM_A ...
			{
				// R..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.R.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_HIGH_SNS_VAL[i], str_name);

				// T..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.T.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_HIGH_SNS_VAL[i], str_name);

				// Z..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.Z.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[i], str_name);

				// R..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.R.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_R_LOW_SNS_VAL[i], str_name);

				// T..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.T.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_T_LOW_SNS_VAL[i], str_name);

				// Z..
				str_name.Format("OTR.IN.CALED.ARM_A.CPTR.Z.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_A_CALED_PMx_CPTR_Z_LOW_SNS_VAL[i], str_name);
			}
			// ARM_B ...
			{
				// R..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.R.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_HIGH_SNS_VAL[i], str_name);

				// T..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.T.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_HIGH_SNS_VAL[i], str_name);

				// Z..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.Z.HIGH.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_HIGH_SNS_VAL[i], str_name);

				// R..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.R.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_R_LOW_SNS_VAL[i], str_name);

				// T..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.T.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_T_LOW_SNS_VAL[i], str_name);

				// Z..
				str_name.Format("OTR.IN.CALED.ARM_B.CPTR.Z.LOW.SNS.PM%1d.VALUE", id);
				STD__ADD_ANALOG_WITH_X_OPTION(str_name, "microns", 0, -9999999, 9999999, "");
				LINK__VAR_ANALOG_CTRL(aCH__OTR_IN_ARM_B_CALED_PMx_CPTR_Z_LOW_SNS_VAL[i], str_name);
			}

			// CFG : DYNAMIC ...
			{
				str_name.Format("CFG.PM%1d.DA.USE", id);
				STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "NO YES", "");
				LINK__VAR_DIGITAL_CTRL(dCH__CFG_PMx_DA_USE[i], str_name);
			}
		}
	}

	// MATERIAL CHANNEL -----
	{
		CString dsp_slot_sts;
		p_variable->Get__STD_DESCRIPTION("STD_SLOT_STATUS", dsp_slot_sts);

		// Material Status
		str_name = "OTR.OUT.MON.dARM_A.MATERIAL.STATUS";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, dsp_slot_sts, "");
		LINK__VAR_DIGITAL_CTRL(dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS,str_name);

		str_name = "OTR.OUT.MON.dARM_B.MATERIAL.STATUS";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, dsp_slot_sts,"");
		LINK__VAR_DIGITAL_CTRL(dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS,str_name);

		// Material Title
		str_name = "OTR.OUT.MON.sARM_A.MATERIAL.TITLE";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE,str_name);

		str_name = "OTR.OUT.MON.sARM_B.MATERIAL.TITLE";
		STD__ADD_STRING_WITH_X_OPTION(str_name,"");
		LINK__VAR_STRING_CTRL(sCH__OTR_OUT_MON__ARM_B_MATERIAL_TITLE,str_name);
	}

	// SIMULATION CHANNEL -----
	str_name = "SIM.CFG.aROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__ROTATE_TIME, str_name);

	// LBx
	str_name = "SIM.CFG.aLBx.PICK.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__LBx_PICK_TIME, str_name);

	str_name = "SIM.CFG.aLBx.PLACE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__LBx_PLACE_TIME, str_name);

	// PMx
	str_name = "SIM.CFG.aPMx.PICK.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__PMx_PICK_TIME, str_name);

	str_name = "SIM.CFG.aPMx.PLACE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__PMx_PLACE_TIME, str_name);

	//
	str_name = "SIM.CFG.aEXTEND.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__EXTEND_TIME, str_name);

	str_name = "SIM.CFG.aRETRACT.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name,"sec",1,0,9999,"");
	LINK__VAR_ANALOG_CTRL(aCH__SIM_CFG__RETRACT_TIME, str_name);

	// HIGH/LOW Full Value
	str_name = "GET.CPTR.SNS.FULL.VALUE";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_SNS_FULL_VAL, str_name);


	// ----------------- ARM A -------------------------
	// After EXTEND.. HIGH Sns
	str_name = "GET.CPTR.ARM_A.SNS.R.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_R_EX_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.T.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_T_EX_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.Z.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_HIGH, str_name);

	// After EXTEND.. LOW Sns
	str_name = "GET.CPTR.ARM_A.SNS.R.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_R_EX_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.T.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_T_EX_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.Z.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_Z_EX_VALUE_LOW, str_name);

	// After RETRACT.. HIGH Sns
	str_name = "GET.CPTR.ARM_A.SNS.R.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_R_RE_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.T.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_T_RE_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.Z.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_HIGH, str_name);

	// After RETRACT.. LOW Sns
	str_name = "GET.CPTR.ARM_A.SNS.R.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_R_RE_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.T.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_T_RE_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_A.SNS.Z.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_A_SNS_Z_RE_VALUE_LOW, str_name);


	// ----------------- ARM B -------------------------
	// After EXTEND.. HIGH Sns
	str_name = "GET.CPTR.ARM_B.SNS.R.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_R_EX_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.T.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_T_EX_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.Z.EX.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_HIGH, str_name);

	// After EXTEND.. LOW Sns
	str_name = "GET.CPTR.ARM_B.SNS.R.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_R_EX_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.T.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_T_EX_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.Z.EX.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_Z_EX_VALUE_LOW, str_name);

	// After RETRACT.. HIGH Sns
	str_name = "GET.CPTR.ARM_B.SNS.R.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_R_RE_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.T.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_T_RE_VALUE_HIGH, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.Z.RE.VALUE.H";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_HIGH, str_name);

	// After RETRACT.. LOW Sns
	str_name = "GET.CPTR.ARM_B.SNS.R.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_R_RE_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.T.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_T_RE_VALUE_LOW, str_name);

	str_name = "GET.CPTR.ARM_B.SNS.Z.RE.VALUE.L";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__CPTR_ARM_B_SNS_Z_RE_VALUE_LOW, str_name);


	// RQ STN FULL VALUE
	str_name = "GET.RQ.STN.FULL.VALUE";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__RQ_STN_FULL_VAL, str_name);

	// R, T, Z
	str_name = "GET.RQSTN.SNS.R.VALUE";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__RQSTN_SNS_R_VALUE, str_name);

	str_name = "GET.RQSTN.SNS.T.VALUE";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__RQSTN_SNS_T_VALUE, str_name);

	str_name = "GET.RQSTN.SNS.Z.VALUE";
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__RQSTN_SNS_Z_VALUE, str_name);

	str_name = "GET.RQSTN.SNS.X.VALUE"; // KMS : Transferom R,T -> X, Y
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL(sCH__RQSTN_SNS_X_VALUE, str_name);

	str_name = "GET.RQSTN.SNS.Y.VALUE"; // KMS : Transferom R,T -> X, Y
	STD__ADD_STRING(str_name);
	LINK__VAR_STRING_CTRL( sCH__RQSTN_SNS_Y_VALUE, str_name);


	// Config...
	str_name = "CFG.aACTION.TIMEOUT.DOWN";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:1.8");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_DOWN, str_name);

	str_name = "CFG.aACTION.TIMEOUT.UP";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:1.8");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_UP, str_name);

	str_name = "CFG.aACTION.TIMEOUT.EXTEND";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:2.2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_EXTEND, str_name);

	str_name = "CFG.aACTION.TIMEOUT.GOTO.DA.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:2.28");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_GOTO_DA_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.RETRACT.DA.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:1.73");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_RETRACT_DA_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.RETRACT.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:2.2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_RETRACT_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.ROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:2.3");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_ROTATE_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.PICK.DA.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:9");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_PICK_DA_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.PICK.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:4.3");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_PICK_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.PLACE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:3.9");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_PLACE_TIME, str_name);

	str_name = "CFG.aACTION.TIMEOUT.PLACE.ADJUST.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:3.25");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_ACTION_TIMEOUT_PLACE_ADJUST_TIME, str_name);

	str_name = "CFG.dPAD.TYPE";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "UNKNOWN", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_PAD_TYPE, str_name);

	str_name = "CFG.dWAFER.SIZE";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "300 200 OTHER", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_WAFER_SIZE, str_name);

	// Swap : Only Register...
	str_name = "CFG.aSWAP.LL.BVL.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:7.63");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_LL_BVL_TIME, str_name);

	str_name = "CFG.aSWAP.LL.DA.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:7.63");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_LL_DA_TIME, str_name);

	str_name = "CFG.aSWAP.LL.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:7.63");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_LL_TIME, str_name);

	str_name = "CFG.aSWAP.BVL.NO.Z.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:7.63");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_BVL_NO_Z_TIME, str_name);

	str_name = "CFG.aSWAP.BVL.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:7.59");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_BVL_TIME, str_name);

	str_name = "CFG.aSWAP.DA.NO.Z.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:5.1");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_DA_NO_Z_TIME, str_name);

	str_name = "CFG.aSWAP.DA.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:9.01");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_DA_TIME, str_name);

	str_name = "CFG.aSWAP.NO.Z.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:4.91");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_NO_Z_TIME, str_name);

	str_name = "CFG.aSWAP.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "recommand:8.91");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_SWAP_TIME, str_name);

	str_name = "CFG.aPM1.ROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "60deg..recommand:1.5");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_PM1_ROTATE_TIME, str_name);

	str_name = "CFG.aPM2.ROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "120deg..recommand:2.2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_PM2_ROTATE_TIME, str_name);

	str_name = "CFG.aPM3.ROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "180deg..recommand:2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_PM3_ROTATE_TIME, str_name);

	str_name = "CFG.aPM4.ROTATE.TIME";
	STD__ADD_ANALOG_WITH_X_OPTION(str_name, "sec", 1, 0.5, 100, "240deg..recommand:2");
	LINK__VAR_ANALOG_CTRL(aCH__CFG_PM4_ROTATE_TIME, str_name);

	str_name = "CFG.dWAFER.SENSOR.CHECK";
	STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "TRUE FALSE", "");
	LINK__VAR_DIGITAL_CTRL(dCH__CFG_WFR_SNS_CHECK, str_name);

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
		str_name = "Robot.sGetInfo.Update.Req";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__Robot_GetInfo_Update_Req, str_name);
	}

	// Arm - Material State ...
	{
		str_name = "Robot.Material.Req";
		STD__ADD_STRING(str_name);
		LINK__VAR_STRING_CTRL(sCH__Robot_Material_Req, str_name);

		str_name = "REQ.ARM_A.MATERIAL.STATE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ON OFF", "");
		LINK__VAR_DIGITAL_CTRL(dCH__REQ_ARM_A_MATERIAL_STATE, str_name);

		str_name = "REQ.ARM_B.MATERIAL.STATE";
		STD__ADD_DIGITAL_WITH_X_OPTION(str_name, "ON OFF", "");
		LINK__VAR_DIGITAL_CTRL(dCH__REQ_ARM_B_MATERIAL_STATE, str_name);
	}

	// ...
	{
		p_variable->Add__MONITORING_PROC(1.0, MON_ID__ANI_MONITOR);
		p_variable->Add__MONITORING_PROC(3.0, MON_ID__IO_MONITOR);
		p_variable->Add__MONITORING_PROC(3.0, MON_ID__HYPER_TERMINAL);
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

#define  ACT__CHECK_ALARM						\
l_act.RemoveAll();								\
l_act.Add("CHECK");

#define  ACT__DA_ABORT_ALARM					\
l_act.RemoveAll();								\
l_act.Add("RETRY");								\
l_act.Add("ABORT");


int CObj__VacRobot_PSK::__DEFINE__ALARM(p_alarm)
{
	DECLARE__ALARM;

	// ...
	CString title;
	title.Format("%s - ",sObject_Name);

	CString alarm_title;
	CString alarm_msg;
	CStringArray l_act;
	int alarm_id;

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
		alarm_id = ALID__ERROR_CODE;

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
		alarm_id = ALID__TM_CHM__NOT_ATM_PRESSURE;

		alarm_title  = title;
		alarm_title += "TMC_CHM's Pressure is not ATM.";

		alarm_msg  = "Please, Check TMC_CHM's Pressure !\n";
		alarm_msg += "TMC_CHM's Pressure must be ATM.\n";

		ACT__RETRY_ABORT;
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

	// ...
	{
		alarm_id = ALID__PMx__NOT_ATM_PRESSURE;

		alarm_title  = title;
		alarm_title += "PMC's pressure is not ATM.";

		alarm_msg  = "Please, check PMC's pressure !\n";
		alarm_msg += "PMC's pressure must be ATM.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__TM_CHM__NOT_VAC_PRESSURE;

		alarm_title  = title;
		alarm_title += "TMC_CHM's Pressure is not VAC.";

		alarm_msg  = "Please, Check TMC_CHM's Pressure !\n";
		alarm_msg += "TMC_CHM's Pressure must be VAC.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBA__NOT_VAC_PRESSURE;

		alarm_title  = title;
		alarm_title += "LBA's Pressure is not VAC.";

		alarm_msg  = "Please, Check LBA's Pressure !\n";
		alarm_msg += "LBA's Pressure must be VAC.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBB__NOT_VAC_PRESSURE;

		alarm_title  = title;
		alarm_title += "LBB's pressure is not VAC.";

		alarm_msg  = "Please, check LBB's pressure !\n";
		alarm_msg += "LBB's pressure must be VAC.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__PMx__NOT_VAC_PRESSURE;

		alarm_title  = title;
		alarm_title += "PMC's pressure is not VAC.";

		alarm_msg  = "Please, check PMC's pressure !\n";
		alarm_msg += "PMC's pressure must be VAC.\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBA__NOT_VALVE_OPEN;

		alarm_title  = title;
		alarm_title += "LBA's valve status is not open.";

		alarm_msg = "Please, check LBA's valve status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__LBB__NOT_VALVE_OPEN;

		alarm_title  = title;
		alarm_title += "LBB's valve status is not open.";

		alarm_msg = "Please, check LBB's valve status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__PMx__NOT_VALVE_OPEN;

		alarm_title  = title;
		alarm_title += "PMC's valve status is not open.";

		alarm_msg = "Please, check PMC's valve status !\n";

		ACT__RETRY_ABORT;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "R Offset Abort range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__ABORT_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "T Offset Abort range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__DA_ABORT_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__SOFT_RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "R Offset Soft range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__CHECK_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__SOFT_RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "T Offset Soft range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__CHECK_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_R_OFFSET__HARD_RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "R Offset Hard range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__DA_ABORT_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	// ...
	{
		alarm_id = ALID__AFTER_CALCULATION_T_OFFSET__HARD_RANGE_ERROR;

		alarm_title  = title;
		alarm_title += "T Offset Hard range error.";

		alarm_msg = "Please, check wafer position on the ARM !\n";

		ACT__DA_ABORT_ALARM;
		ADD__ALARM_EX(alarm_id,alarm_title,alarm_msg,l_act);
	}

	Register__ALARM_INF(p_alarm);
	return 1;
}


// ...
#define APP_DSP__COMM_STS							\
"OFFLINE  ONLINE"

#define APP_DSP__CMD_SET							\
"AGoto	AGoto_Offset								\
 HomeAll HomeR										\
 APick APlace										\
 APlace_Offset										\
 BPlace_Offset										\
 Reset												\
 BGoto	BGoto_Offset								\
 BPick BPlace										\
 APickAL APlaceAL									\
 BPickAL BPlaceAL									\
 LoadA LoadB UnloadA UnloadB						\
 ChkLoad ChkLoadA ChkLoadB							\
 WfrSnsIntk ComInit ASet_Cptr_On ASet_Cptr_Off		\
 BSet_Cptr_On BSet_Cptr_Off AGet_Cptr BGet_Cptr		\
 AGet_Current_Stn BGet_Current_Stn					\
 AGet.WAF_CEN     BGet.WAF_CEN						\
 WAF_CEN.DATA										\
 ASet_Stn BSet_Stn									\
 SET_CPTR_21_ON SET_CPTR_21_OFF GET_CPTR_21"

#define APP_DSP__STN_NUM				"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"
#define APP_DSP__CPTR_STN_NUM			"1 2 3 4 5 6 7 8 9 10"
#define APP_DSP__MATERIAL				"Unknown Absent Present"
#define APP_DSP__WAFER_SNS				"Yes No"
#define APP_DSP__ARM_STS				"Unknown Retracted Extended"


int CObj__VacRobot_PSK::__DEFINE__VARIABLE_IO(p_io_variable)
{
	DECLARE__IO_VARIABLE;

	CString str_name;
	CString fnc_name;

	// String
	{
		// SI  -----------------------------
		str_name = "esi.RB1.Version";
		IO__ADD_STRING_READ__MANUAL(str_name);
		LINK__IO_VAR_STRING_CTRL(siCH__VERSION, str_name);

		// SO  -----------------------------
		str_name = "so.Check.Cmmd";
		IO__ADD_STRING_WRITE(str_name);
		LINK__IO_VAR_STRING_CTRL(soCH__CHECK_CMMD, str_name);

		str_name = "eso.RB1.HyperTerminal.Command";
		IO__ADD_STRING_WRITE(str_name);
		LINK__IO_VAR_STRING_CTRL(soCH__HYPER_TERMINAL_CMD, str_name);
	}

	// Analog
	{
		// AI  -----------------------------
		str_name = "eai.RB1.ErrId";
		IO__ADD_ANALOG_READ(str_name, "num", 0, 0, 100000);
		LINK__IO_VAR_ANALOG_CTRL(aiCH__ERRID, str_name);

		// AO  -----------------------------
		str_name = "eao.RB1.RO.Offset";
		IO__ADD_ANALOG_WRITE(str_name, "", 0, -9999999, 9999999);
		LINK__IO_VAR_ANALOG_CTRL(aoCH_RO_OFFSET, str_name);

		str_name = "eao.RB1.TO.Offset";
		IO__ADD_ANALOG_WRITE(str_name, "", 0, -9999999, 9999999);
		LINK__IO_VAR_ANALOG_CTRL(aoCH_TO_OFFSET, str_name);

		str_name = "eao.RB1.STN.R.VAL";
		IO__ADD_ANALOG_WRITE(str_name, "", 0, -9999999, 9999999);
		LINK__IO_VAR_ANALOG_CTRL(aoCH_STN_R_VAL, str_name);

		str_name = "eao.RB1.STN.T.VAL";
		IO__ADD_ANALOG_WRITE(str_name, "", 0, -9999999, 9999999);
		LINK__IO_VAR_ANALOG_CTRL(aoCH_STN_T_VAL, str_name);
	}

	// Digital
	{
		// DO  -----------------------------
		str_name = "edo.RB1.Command";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__CMD_SET);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__COMMAND, str_name);

		str_name = "edo.RB1.StnA";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__STN_NUM);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__STN_A, str_name);

		str_name = "edo.RB1.StnB";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__STN_NUM);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__STN_B, str_name);

		str_name = "edo.RB1.CPTR.StnA";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__CPTR_STN_NUM);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__CPTR_STN_A, str_name);

		str_name = "edo.RB1.CPTR.StnB";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__CPTR_STN_NUM);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__CPTR_STN_B, str_name);

		str_name = "edo.RB1.Slot";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__SLOT_NUM);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__SLOT, str_name);

		str_name = "edo.RB1.ZPos";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__DOWN_UP);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__ZPOS, str_name);

		str_name = "edo.RB1.RPos";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__RET_EXT);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__RPOS, str_name);

		str_name = "edo.RB1.ArmAMat";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__MATERIAL);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__ARM_A_MAT, str_name);

		str_name = "edo.RB1.ArmBMat";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__MATERIAL);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__ARM_B_MAT, str_name);

		str_name = "edo.RB1.WfrSns";
		IO__ADD_DIGITAL_WRITE(str_name, APP_DSP__WAFER_SNS);
		LINK__IO_VAR_DIGITAL_CTRL(doCH__ARM_WFR_SNS, str_name);

		// DI  -----------------------------
		str_name = "edi.RB1.ComSts";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__COMM_STS);
		LINK__IO_VAR_DIGITAL_CTRL(diCH__COMM_STS, str_name);

		str_name = "edi.RB1.ArmARad";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__ARM_STS);
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ARM_A_READ, str_name);

		str_name = "edi.RB1.ArmBRad";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__ARM_STS);
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ARM_B_READ, str_name);

		str_name = "edi.RB1.ArmAMat.Read";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__MATERIAL);
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ARM_A_MAT_READ, str_name);

		str_name = "edi.RB1.ArmBMat.Read";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, APP_DSP__MATERIAL);
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ARM_B_MAT_READ, str_name);

		str_name = "edi.RB.Status.Read";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, "SUCCESS FAIL");
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_STATE_READ, str_name);

		str_name = "edi.RB.INIT.CMD";
		IO__ADD_DIGITAL_READ__MANUAL(str_name, "SUCCESS FAIL");
		LINK__IO_VAR_DIGITAL_CTRL(diCH__ROBOT_INIT_CMD, str_name);


	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__VacRobot_PSK::__INITIALIZE__OBJECT(p_variable,p_ext_obj_create)
{
	CString def_name;
	CString def_data;
	CString obj_name;
	CString str_name;
	int i;

	// DB_CFG
	{
		def_name = "OBJ__DB";
		p_variable->Get__DEF_CONST_DATA(def_name,def_data);

		iActive__SIM_MODE = -1;

		str_name = "CFG.SIM.MODE";
		LINK__EXT_VAR_DIGITAL_CTRL(dEXT_CH__CFG_SIM_MODE, def_data,str_name);
	}

	iFlag__APP_LOG = 1;

	// ...
	{
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

	iFlag__DRV_LOG = 1;

	// ...
	{
		CString file_name;
		CString log_msg;

		file_name.Format("%s_DRV.log", sObject_Name);

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
		iCFG__SIM_FLAG = -1;

		x_seq_info->Get__DIR_ROOT(m_szRoot);

		// 
		CString file_name;
		CString path;	

		//
		path = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data";	
		sCH__szRoot->Set__DATA(path);

		CreateDirectory(path, NULL);

		xAPP_LOG_CTRL->WRITE__LOG(path);

		//
		CString file_time;

		SYSTEMTIME file_SystemTime;
		GetLocalTime(&file_SystemTime);

		file_time.Format("%04d_%02d_%02d",		
						 file_SystemTime.wYear,
						 file_SystemTime.wMonth,
						 file_SystemTime.wDay);

		xAPP_LOG_CTRL->WRITE__LOG(file_time);
		path = m_szRoot+"\\EQP_LOG\\DATALOG\\DA_Data\\"+file_time;

		CreateDirectory(path, NULL);

		xAPP_LOG_CTRL->WRITE__LOG(path);
	}

	return 1;
}
int CObj__VacRobot_PSK::__INITIALIZE__IO(p_io_para)
{
	CString net_ip   = "127.0.0.1";
	CString net_port = "10001";

	m_nCommState = ONLINE;
	m_Rcv_Time = 5;
	m_Out_Time = 60;			// 60 sec

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

		// ...
		CString str_end = "";
		int end_len;

		str_end += (char) __CR;
		//str_end += (char) __LF;
		end_len = str_end.GetLength();

		mX_Net->SET__TERMINAL_InSTRING(str_end,  end_len);
		mX_Net->SET__TERMINAL_OutSTRING(str_end, end_len);
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
		log_msg.Format("Connecting to Serial ... \n");

		log_msg = "Connect to Ethernet ... \n";

		log_bff.Format("Net_IP : %s \n", net_ip);
		log_msg += log_bff;

		log_bff.Format("Net_Port : %s \n", net_port);
		log_msg += log_bff;

		log_bff.Format("m_Rcv_Time : %1d sec \n", m_Rcv_Time);
		log_msg += log_bff;

		log_bff.Format("m_Out_Time : %1d sec \n", m_Out_Time);
		log_msg += log_bff;

		log_bff.Format("End_InStr  : %s \n", sEnd_InStr);
		log_msg += log_bff;

		log_bff.Format("End_OutStr : %s \n", sEnd_OutStr);
		log_msg += log_bff;

		xAPP_LOG_CTRL->WRITE__LOG(log_msg);
		xDRV_LOG_CTRL->WRITE__LOG(log_msg);
	}

	// ...
	CString err_msg;
	printf("%s : Connecting (%s %s) ... \n", sObject_Name, net_ip,net_port);

	if(iActive__SIM_MODE > 0)
	{
		printf("VAC_RobotSimulation_Mode");
		return 1;
	}
	else
	{
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
	}

	return 1;
}


//--------------------------------------------------------------------------------
int CObj__VacRobot_PSK::__CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm)
{
LOOP_RETRY:

	// ...
	mMNG__ERR_CODE.Clear__Error_Code();

	// ...
	xCH__LOCK_FLAG->Set__DATA("YES");	// Lock�� �Ǵ�.

	// ...
	int flag = -1;

	CString para__arm_type;
	CString para__stn_name;
	CString para__stn_slot;

	CString szUpperObj;
	CString log_msg;

	// Driver���� timeout���� ����ȴ�.
	sCH__ACTION_STS->Set__DATA(mode);

	// ...
	CStringArray l_para;
	p_variable->Get__FNC_PARAMETER(l_para);

	if(l_para.GetSize() > 0)
	{
		int limit = l_para.GetSize();
		int i;

		for(i=0;i<limit;i++)
		{
			CString para_data = l_para[i];

			switch(i)
			{
				case 0:		
					dCH__OTR_IN_PARA__ARM_TYPE->Set__DATA(para_data);
					break;

				case 1:
					dCH__OTR_IN_PARA__STN_NAME->Set__DATA(para_data);
					break;

				case 2:
					dCH__OTR_IN_PARA__STN_SLOT->Set__DATA(para_data);
					break;
			}	
		}
	}

	dCH__OTR_IN_PARA__ARM_TYPE->Get__DATA(para__arm_type);
	dCH__OTR_IN_PARA__STN_NAME->Get__DATA(para__stn_name);
	dCH__OTR_IN_PARA__STN_SLOT->Get__DATA(para__stn_slot);

	// ...
	{
		log_msg.Format("--------> Start ... :  [%s] (%s,%s,%s)",
			mode,
			para__arm_type,
			para__stn_name,
			para__stn_slot);

		Fnc__APP_LOG(log_msg);
	}

	pII__EXT_MODE_CTRL = p_variable->Get__EXT_FNC_MODE_CTRL();
	pII__EXT_VAR_CTRL  = p_variable->Get__EXT_FNC_VAR_CTRL();
	pII__EXT_FNC_CTRL  = p_variable->Get__EXT_USER_FNC_CTRL();

	// ...
	szUpperObj = pII__EXT_MODE_CTRL->Get__UPPER_OBJECT_NAME();	

	log_msg.Format("Object Call: [%s] ==> [%s]",  szUpperObj, sObject_Name);
	Fnc__APP_LOG(log_msg);

	//	Clear !! 
	m_sErrorID  =   "0";
	sCH__ERRID->Set__DATA(m_sErrorID);

	// ...
	{
		IF__CTRL_MODE(sMODE__INIT)
		{
			flag = Call__INIT(p_variable,p_alarm);
		}
		ELSE_IF__CTRL_MODE(sMODE__PICK)
		{
			flag = Call__PICK(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);

			// Save Before Info...
			if(para__arm_type.CompareNoCase(ARM_A) == 0)	m_sBefore_Stn_Retract_ArmA = para__stn_name;
			else											m_sBefore_Stn_Retract_ArmB = para__stn_name;
		}
		ELSE_IF__CTRL_MODE(sMODE__PLACE)		flag = Call__PLACE(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);
		ELSE_IF__CTRL_MODE(sMODE__ROTATE)		flag = Call__ROTATE(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);

		ELSE_IF__CTRL_MODE(sMODE__HOME)			flag = Call__HOME(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__MAP)			flag = Call__MAP(p_variable,p_alarm);

		ELSE_IF__CTRL_MODE(sMODE__EXTEND)		flag = Call__EXTEND(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot,ACTIVE_HAND_OFF);
		ELSE_IF__CTRL_MODE(sMODE__RETRACT)
		{
			flag = Call__RETRACT(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot,ACTIVE_HAND_OFF);

			// Save Before Info...
			if(para__arm_type.CompareNoCase(ARM_A) == 0)	m_sBefore_Stn_Retract_ArmA = para__stn_name;
			else											m_sBefore_Stn_Retract_ArmB = para__stn_name;
		}

		ELSE_IF__CTRL_MODE(sMODE__GOUP)			flag = Call__GOUP(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);
		ELSE_IF__CTRL_MODE(sMODE__GODOWN)		flag = Call__GODOWN(p_variable,p_alarm, para__stn_name,para__arm_type,para__stn_slot);

		ELSE_IF__CTRL_MODE(sMODE__RQ_STN)		flag = Call__RQ_STN(p_variable,p_alarm, para__stn_name,para__arm_type);
		ELSE_IF__CTRL_MODE(sMODE__SET_STN)		flag = Call__SET_STN(p_variable,p_alarm, para__stn_name,para__arm_type);

		ELSE_IF__CTRL_MODE(sMODE__TEACHED_CPTR_SAVE)	flag = Call__TEACHED_CPTR_SAVE(p_variable,p_alarm, para__stn_name,para__arm_type);

		ELSE_IF__CTRL_MODE(sMODE__CHECK_CMMD)			flag = Call__CHECK_CMMD(p_variable,p_alarm);
		ELSE_IF__CTRL_MODE(sMODE__CHECK_ERR_CODE)		flag = Call__CHECK_ERR_CODE(p_variable,p_alarm);
	}

	// ERR_CHECK ...
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
			int alm_id = ALID__ERROR_CODE;
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

	// KMS, Material Check
	{
		CString var_data;
		//diCH__ARM_A_MAT_READ->Get__DATA(var_data);
		diCH__ROBOT_STATE_READ->Get__DATA(var_data);
		if(diCH__ARM_A_MAT_READ->Check__DATA("Present") > 0) dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__EXIST);
		else if(diCH__ARM_A_MAT_READ->Check__DATA("Absent") > 0) dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__NONE);
		else dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS->Set__DATA(STR__UNKNOWN);

		//diCH__ARM_B_MAT_READ->Get__DATA(var_data);
		if(diCH__ARM_B_MAT_READ->Check__DATA("Present") > 0) dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Set__DATA(STR__EXIST);
		else if(diCH__ARM_B_MAT_READ->Check__DATA("Absent") > 0) dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Set__DATA(STR__NONE);
		else dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS->Set__DATA(STR__UNKNOWN);
	}


	if((flag < 0)||(p_variable->Check__CTRL_ABORT() > 0))
	{
		CString log_msg;
		log_msg.Format("<-- Aborted ... :  [%s]",mode);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);

		log_msg.Format("%s_Failed",mode);

		if(para__arm_type.CompareNoCase(ARM_A) == 0)		sCH__ARM_A_BEFORE_MODE_STS->Set__DATA(log_msg);
		else												sCH__ARM_B_BEFORE_MODE_STS->Set__DATA(log_msg);
	}
	else
	{
		CString log_msg;
		log_msg.Format("<-- Completed ... :  [%s]",mode);

		Fnc__APP_LOG(log_msg);
		Fnc__ACT_MSG(log_msg);

		if(mode.CompareNoCase(sMODE__ROTATE) != 0)			// PICK �Ŀ� ROTATE �ϹǷ�.. Update ����..
		{
			log_msg.Format("%s_Success",mode);

			if(para__arm_type.CompareNoCase(ARM_A) == 0)	sCH__ARM_A_BEFORE_MODE_STS->Set__DATA(log_msg);
			else											sCH__ARM_B_BEFORE_MODE_STS->Set__DATA(log_msg);
		}
	}

	return flag;
}

int CObj__VacRobot_PSK::__CALL__MONITORING(id, p_variable, p_alarm)
{
	switch(id)
	{
		case MON_ID__ANI_MONITOR:
			Mon__ANI_MONITOR(p_variable,p_alarm);
			break;

		case MON_ID__IO_MONITOR:
			Mon__IO_MONITOR(p_variable,p_alarm);
			break;

		case MON_ID__HYPER_TERMINAL:
			Mon__HYPER_TERMINAL_SEND(p_variable,p_alarm);
			break;
	}

	return 1;
}
