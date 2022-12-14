#include "StdAfx.h"
#include "CObj__VacRobot_WAVEII.h"
#include "CObj__VacRobot_WAVEII__DEF.h"

#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int CObj__VacRobot_WAVEII
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__VacRobot_WAVEII
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;

	/*
	if((diCH__ARM_A_READ->Check__VARIABLE_NAME(var_name) > 0)
	|| (diCH__ARM_B_READ->Check__VARIABLE_NAME(var_name) > 0))
	{
		if(diCH__ARM_A_READ->Check__VARIABLE_NAME(var_name) > 0)
			str_cmmd = "RQ POS STN ARM A";
		else
			str_cmmd = "RQ POS STN ARM B";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 4)
		{
			CString r_data = l_rsp[4];
		
			     if(r_data.CompareNoCase("EX") == 0)		read_data = "Extended";
			else if(r_data.CompareNoCase("RE") == 0)		read_data = "Retracted";
			else if(r_data.CompareNoCase("--") == 0)		read_data = "Unknown";
			else											read_data = "Unknown";
		}
		else
		{
			read_data = "Unknown";
		}

		if(l_err.GetSize() > 0)
		{

		}
		return 1;
	}
	*/

	if((diCH__ARM_A_MAT_READ->Check__VARIABLE_NAME(var_name) > 0)
	|| (diCH__ARM_B_MAT_READ->Check__VARIABLE_NAME(var_name) > 0))
	{
		if(diCH__ARM_A_MAT_READ->Check__VARIABLE_NAME(var_name) > 0)
			str_cmmd = "RQ LOAD ARM A";
		else
			str_cmmd = "RQ LOAD ARM B";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 3)
		{
			CString r_data = l_rsp[3];

			     if(r_data.CompareNoCase("ON") == 0)		read_data = "Present";
			else if(r_data.CompareNoCase("OF") == 0)		read_data = "Absent";
			else if(r_data.CompareNoCase("?")  == 0)		read_data = "Unknown";
			else											read_data = "Unknown";
		}
		else
		{
			read_data = "Unknown";
		}

		if(l_err.GetSize() > 0)
		{

		}
		return 1;
	}

	if(diCH__COMM_STS->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(iCFG__SIM_MODE > 0)
		{
			read_data = STR__ONLINE;
		}
		else
		{
			if(m_nCommState == OFFLINE)		read_data = STR__OFFLINE;
			else							read_data = STR__ONLINE;
		}
		return 1;
	}

	return -1;
}

int CObj__VacRobot_WAVEII
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;

	if(siCH__VERSION->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ VERSION";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, FALSE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 0)
		{
			read_data = "";

			int i_limit = l_rsp.GetSize();
			int i;

			for(i=0; i<i_limit; i++)
			{
				if(i > 0)		read_data += " ";
				
				read_data += l_rsp[i];
			}
		}
		else
		{
			read_data = "Unknown";
		}

		return 1;
	}

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__VacRobot_WAVEII
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{
	if(aoCH_RO_OFFSET->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sRO_OFFSET.Format("%.f", set_data);
		return 1;
	}
	if(aoCH_TO_OFFSET->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sTO_OFFSET.Format("%.f", set_data);
		return 1;
	}

	if(aoCH_STN_R_VAL->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sSTN_R_SET_VAL.Format("%.f", set_data);
		return 1;
	}
	if(aoCH_STN_T_VAL->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sSTN_T_SET_VAL.Format("%.f", set_data);
		return 1;
	}

	return -1;
}

int CObj__VacRobot_WAVEII
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;


	if(doCH__COMMAND->Check__VARIABLE_NAME(var_name) > 0)
	{
		CString str_action;
		CString para__stn_name;
		double  to_sec = 10;		// 10.0 sec

		// AGoto BGoto APick BPick APlace BPlace ASwap BSwap ComInit HomeAll HomeR Reset LoadA LoadB UnloadA UnloadB ChkLoad ChkLoadA ChkLoadB APickAL APlaceAL BPickAL BPlaceAL WfrSnsIntk

		// MX , GX Robot Commands -----
		sCH__ACTION_STS->Get__DATA(str_action);
		dCH__OTR_IN_PARA__STN_NAME->Get__DATA(para__stn_name);

		// ----- Get Action Timeout From config page...
		if(str_action.CompareNoCase(sMODE__ROTATE) == 0)
		{
			if(para__stn_name.CompareNoCase("PM1") == 0)
			{
				to_sec = aCH__CFG_PM1_ROTATE_TIME->Get__VALUE();
			}
			else if(para__stn_name.CompareNoCase("PM2") == 0)
			{
				to_sec = aCH__CFG_PM2_ROTATE_TIME->Get__VALUE();
			}
			else if(para__stn_name.CompareNoCase("PM3") == 0)
			{
				to_sec = aCH__CFG_PM3_ROTATE_TIME->Get__VALUE();
			}
			else if(para__stn_name.CompareNoCase("PM4") == 0)
			{
				to_sec = aCH__CFG_PM4_ROTATE_TIME->Get__VALUE();
			}
			else
			{
				to_sec = aCH__CFG_ACTION_TIMEOUT_ROTATE_TIME->Get__VALUE();
			}
		}
		/*
		else if(str_action.CompareNoCase(sMODE__GODOWN) == 0)
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_DOWN->Get__VALUE();
		}
		else if(str_action.CompareNoCase(sMODE__GOUP) == 0)
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_UP->Get__VALUE();
		}
		else if(str_action.CompareNoCase(sMODE__RETRACT) == 0)
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_RETRACT_TIME->Get__VALUE();
		}
		else if((str_action.CompareNoCase("EXTEND_DYNAMIC_ALIGN")  == 0) 
		     || (str_action.CompareNoCase("RETRACT_DYNAMIC_ALIGN") == 0))
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_GOTO_DA_TIME->Get__VALUE();
		}
		else if(str_action.CompareNoCase(sMODE__PICK) == 0)
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_PICK_TIME->Get__VALUE();
		}
		else if(str_action.CompareNoCase(sMODE__PLACE) == 0)
		{
			to_sec = aCH__CFG_ACTION_TIMEOUT_PLACE_TIME->Get__VALUE();
		}
		*/

		// --------- Command Format...
		if(set_data.CompareNoCase("AGoto") == 0)
		{
			// AGoto : GOTO Station RPosition ZPostion Slot Arm
			str_cmmd.Format("GOTO N %s R %s Z %s SLOT %s ARM A", m_sStationA, m_sRPos, m_sZPos, m_sSlot);
		}
		else if(set_data.CompareNoCase("AGoto_Offset") == 0)
		{
			// AGoto_Offset : GOTO Station RPosition ZPostion Slot Arm
			str_cmmd.Format("GOTO N %s R %s RO %s TO %s Z %s SLOT %s ARM A", m_sStationA, m_sRPos, m_sRO_OFFSET, m_sTO_OFFSET, m_sZPos, m_sSlot);
		}
		else if(set_data.CompareNoCase("BGoto") == 0)
		{
			// BGoto : GOTO Station RPosition ZPostion Slot Arm
			str_cmmd.Format("GOTO N %s R %s Z %s SLOT %s ARM B", m_sStationB, m_sRPos, m_sZPos, m_sSlot);
		}
		else if(set_data.CompareNoCase("BGoto_Offset") == 0)
		{
			// BGoto_Offset : GOTO Station RPosition ZPostion Slot Arm
			str_cmmd.Format("GOTO N %s R %s RO %s TO %s Z %s SLOT %s ARM B", m_sStationB, m_sRPos, m_sRO_OFFSET, m_sTO_OFFSET, m_sZPos, m_sSlot);
		}
		else if(set_data.CompareNoCase("APick") == 0)
		{
			// APick : PICK Station Slot Arm
			str_cmmd.Format("PICK %s SLOT %s ARM A", m_sStationA, m_sSlot);
		}
		else if(set_data.CompareNoCase("BPick") == 0)
		{
			// BPick : PICK Station Slot Arm
			str_cmmd.Format("PICK %s SLOT %s ARM B", m_sStationB, m_sSlot);
		}
		else if(set_data.CompareNoCase("APlace") == 0)
		{
			// APlace : PLACE Station Slot Arm
			str_cmmd.Format("PLACE %s SLOT %s ARM A", m_sStationA, m_sSlot);
		}
		else if(set_data.CompareNoCase("BPlace") == 0)
		{
			// BPlace : PLACE Station Slot Arm
			str_cmmd.Format("PLACE %s SLOT %s ARM B", m_sStationB, m_sSlot);
		}
		else if(set_data.CompareNoCase("APlace_Offset") == 0)
		{
			// APlace_Offset : PLACE Station with an offset
			str_cmmd.Format("PLACE %s SLOT %s ARM A RO %s TO %s", m_sStationA, m_sSlot, m_sRO_OFFSET, m_sTO_OFFSET);
		}
		else if(set_data.CompareNoCase("BPlace_Offset") == 0)
		{
			// BPlace_Offset : PLACE Station with an offset
			str_cmmd.Format("PLACE %s SLOT %s ARM B RO %s TO %s", m_sStationB, m_sSlot, m_sRO_OFFSET, m_sTO_OFFSET);
		}

		// Common Robot Commands -----
		else if(set_data.CompareNoCase("HomeAll") == 0)
		{
			str_cmmd.Format("HOME ALL");
		}
		else if(set_data.CompareNoCase("HomeR") == 0)
		{
			str_cmmd.Format("HOME R");
		}
		else if(set_data.CompareNoCase("Reset") == 0)
		{
			str_cmmd.Format("RESET");
		}
		else if(set_data.CompareNoCase("LoadA") == 0)
		{
			str_cmmd.Format("SET LOAD ARM A ON");
		}
		else if(set_data.CompareNoCase("LoadB") == 0)
		{
			str_cmmd.Format("SET LOAD ARM B ON");
		}
		else if(set_data.CompareNoCase("UnloadA") == 0)
		{
			str_cmmd.Format("SET LOAD ARM A OFF");
		}
		else if(set_data.CompareNoCase("UnloadB") == 0)
		{
			str_cmmd.Format("SET LOAD ARM B OFF");
		}
		else if(set_data.CompareNoCase("ChkLoad") == 0)
		{
			str_cmmd.Format("CHECK LOAD INTLCK ALL DIS");
		}
		else if(set_data.CompareNoCase("ChkLoadA") == 0)
		{
			str_cmmd.Format("CHECK LOAD A INTLCK ALL DIS");
		}
		else if(set_data.CompareNoCase("ChkLoadB") == 0)
		{
			str_cmmd.Format("CHECK LOAD B INTLCK ALL DIS");
		}

		// Pick & Place with Alginer -----
		else if(set_data.CompareNoCase("APickAL") == 0)
		{
			str_cmmd.Format("PICK %s ARM A STRT NR", m_sStationA);
		}
		else if(set_data.CompareNoCase("APlaceAL") == 0)
		{
			str_cmmd.Format("PLACE %s ARM A STRT NR", m_sStationA);
		}
		else if(set_data.CompareNoCase("BPickAL") == 0)
		{
			str_cmmd.Format("PICK %s ARM B STRT NR", m_sStationB);
		}
		else if(set_data.CompareNoCase("BPlaceAL") == 0)
		{
			str_cmmd.Format("PLACE %s ARM B STRT NR", m_sStationB);
		}
		else if(set_data.CompareNoCase("WfrSnsIntk") == 0)
		{
			str_cmmd.Format("SET INTLCK WAF_SEN %s", m_sWfrSnsIntlk);
		}
		else if(set_data.CompareNoCase("ASet_Cptr_On") == 0)
		{
			// SET_CPTR_ON : ?? Station???? ???? ?????? ON ??????.
			str_cmmd.Format("SET CPTR %s ON", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("ASet_Cptr_Off") == 0)
		{
			// SET_CPTR_ON : ?? Station???? ???? ?????? OFF ??????.
			str_cmmd.Format("SET CPTR %s OFF", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("BSet_Cptr_On") == 0)
		{
			// SET_CPTR_ON : ?? Station???? ???? ?????? ON ??????.
			str_cmmd.Format("SET CPTR %s ON", m_sCptr_StationB);
		}
		else if(set_data.CompareNoCase("BSet_Cptr_Off") == 0)
		{
			// SET_CPTR_ON : ?? Station???? ???? ?????? OFF ??????.
			str_cmmd.Format("SET CPTR %s OFF", m_sCptr_StationB);
		}
		else if(set_data.CompareNoCase("SET_CPTR_21_ON") == 0)
		{
			str_cmmd.Format("SET CPTR 21 ON");
		}
		else if(set_data.CompareNoCase("SET_CPTR_21_OFF") == 0)
		{
			str_cmmd.Format("SET CPTR 21 OFF");
		}
		else if(set_data.CompareNoCase("AGet_Cptr") == 0)
		{
			// RQ CPTR station : ?? Station???? ???? ???????? ????????.
			str_cmmd.Format("RQ CPTR %s", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("BGet_Cptr") == 0)
		{
			// RQ CPTR station : ?? Station???? ???? ???????? ????????.
			str_cmmd.Format("RQ CPTR %s", m_sCptr_StationB);
		}
		else if(set_data.CompareNoCase("GET_CPTR_21") == 0)
		{
			str_cmmd.Format("RQ CPTR 21");
		}
		else if(set_data.CompareNoCase("AGet_Current_Stn") == 0)
		{
			str_cmmd.Format("RQ STN %s A ALL", m_sStationA);
		}	
		else if(set_data.CompareNoCase("BGet_Current_Stn") == 0)
		{
			str_cmmd.Format("RQ STN %s B ALL", m_sStationB);
		}
		else if(set_data.CompareNoCase("AGet.WAF_CEN") == 0)
		{
			str_cmmd.Format("RQ STN %s A WAF_CEN ALL", m_sStationA);
		}	
		else if(set_data.CompareNoCase("BGet.WAF_CEN") == 0)
		{
			str_cmmd.Format("RQ STN %s B WAF_CEN ALL", m_sStationA);
		}	
		else if(set_data.CompareNoCase("WAF_CEN.DATA") == 0)
		{
			str_cmmd.Format("RQ WAF_CEN DATA");
		}	
		else if(set_data.CompareNoCase("ASet_Stn") == 0)
		{
			str_cmmd.Format("SET STN %s ARM A R %s T %s", m_sStationA, m_sSTN_R_SET_VAL, m_sSTN_T_SET_VAL);
		}
		else if(set_data.CompareNoCase("BSet_Stn") == 0)
		{
			str_cmmd.Format("SET STN %s ARM B R %s T %s", m_sStationB, m_sSTN_R_SET_VAL, m_sSTN_T_SET_VAL);
		}
		else
		{
			CString log_msg;

			log_msg.Format("[%s] Unknown DATA Error \n", var_name);
			Fnc__DRV_LOG(log_msg);
			return -1;
		}

		m_Out_Time = (int) to_sec;

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, to_sec, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 0)
		{
			m_sErrorID.Format("0");
			sCH__ERRID->Set__DATA(m_sErrorID);

			CString rsp_data = Get__STRING_OF_LIST(l_rsp);

			if((set_data.CompareNoCase("AGet_Cptr")   == 0) 
			|| (set_data.CompareNoCase("BGet_Cptr")   == 0) 
			|| (set_data.CompareNoCase("GET_CPTR_21") == 0))
			{
				// CPTR NOT TRIGGERED?? ?? ???? ????.
				sCH__CPTR_SNS_FULL_VAL->Set__DATA(rsp_data);
			}
			else if((set_data.CompareNoCase("AGet_Current_Stn") == 0) 
				 || (set_data.CompareNoCase("BGet_Current_Stn") == 0))
			{
				sCH__RQ_STN_FULL_VAL->Set__DATA(rsp_data);
			}
			else if(set_data.CompareNoCase("WAF_CEN.DATA") == 0)
			{
				bool active_offset = false;
				int count_offset = 0;

				CString str__off_r; 
				CString str__off_t; 

				int i_limit = l_rsp.GetSize();
				int i;

				for(i=0; i<i_limit; i++)
				{
					CString str_rsp = l_rsp[i];

					if(!active_offset)
					{
						if(str_rsp.CompareNoCase("OFFSET") == 0)
						{
							active_offset = true;
						}

						count_offset = 0;
						continue;
					}

					count_offset++;
					if(count_offset == 1)		str__off_r = str_rsp;
					if(count_offset == 2)		str__off_t = str_rsp;
				}

				if(active_offset)
				{
					CString str_value;
					
					double r_value = atof(str__off_r) / 1000.0;
					double t_value = atof(str__off_t) / 1000.0;

					str_value.Format("%.3f", r_value);
					sCH__RQSTN_SNS_R_VALUE->Set__DATA(str_value);
					
					str_value.Format("%.3f", t_value);
					sCH__RQSTN_SNS_T_VALUE->Set__DATA(str_value);

					sCH__RQSTN_SNS_Z_VALUE->Set__DATA("0.0");
				}
				else
				{
					sCH__RQSTN_SNS_R_VALUE->Set__DATA("0.0");
					sCH__RQSTN_SNS_T_VALUE->Set__DATA("0.0");
					sCH__RQSTN_SNS_Z_VALUE->Set__DATA("0.0");
				}
			}
		}

		if(l_err.GetSize() > 0)
		{
			CString str__err_id = l_err[0];

			m_sErrorID = str__err_id;
			sCH__ERRID->Set__DATA(m_sErrorID);
		}
		return 1;
	}

	// edo.RB1.StnA 
	if(doCH__STN_A->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sStationA = set_data;
		return 1;
	}
	// edo.RB1.StnB 
	if(doCH__STN_B->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sStationB = set_data;

		return 1;
	}

	// edo.RB1.CPTR.StnA
	if(doCH__CPTR_STN_A->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sCptr_StationA = set_data;
		return 1;
	}
	// edo.RB1.CPTR.StnB
	if(doCH__CPTR_STN_B->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sCptr_StationB = set_data;
		return 1;
	}

	// edo.RB1.RPos
	if(doCH__RPOS->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("Retract") == 0)		m_sRPos = "RE";
		else											m_sRPos = "EX";

		return 1;
	}

	// edo.RB1.ArmAMat
	// Unknown Absent Present;
	if(doCH__ARM_A_MAT->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("Absent") == 0)
		{
			str_cmmd.Format("SET LOAD A OFF");
		}
		else if(set_data.CompareNoCase("Present") == 0)
		{
			str_cmmd.Format("SET LOAD A ON");
		}
		else
		{
			str_cmmd.Format("SET LOAD A ?");
		}

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__ACT, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 0)
		{
			m_sErrorID.Format("0");
			sCH__ERRID->Set__DATA(m_sErrorID);

			CString rsp_data = Get__STRING_OF_LIST(l_rsp);

			// ...
			{

			}
		}

		if(l_err.GetSize() > 0)
		{
			CString str__err_id = l_err[0];

			m_sErrorID = str__err_id;
			sCH__ERRID->Set__DATA(m_sErrorID);
		}
		return 1;
	}

	// edo.RB1.ArmBMat
	// Unknown Absent Present;
	if(doCH__ARM_B_MAT->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("Absent") == 0)
		{
			str_cmmd.Format("SET LOAD B OFF");
		}
		else if(set_data.CompareNoCase("Present") == 0)
		{
			str_cmmd.Format("SET LOAD B ON");
		}
		else
		{
			str_cmmd.Format("SET LOAD B ?");
		}

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__ACT, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 0)
		{
			m_sErrorID.Format("0");
			sCH__ERRID->Set__DATA(m_sErrorID);

			CString rsp_data = Get__STRING_OF_LIST(l_rsp);

			// ...
			{

			}
		}

		if(l_err.GetSize() > 0)
		{
			CString str__err_id = l_err[0];

			m_sErrorID = str__err_id;
			sCH__ERRID->Set__DATA(m_sErrorID);
		}
		return 1;
	}

	// edo.RB1.ZPos
	if(doCH__ZPOS->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("Down") == 0)		m_sZPos = "DN";
		else										m_sZPos = "UP";

		return 1;
	}

	// edo.RB1.Slot
	if(doCH__SLOT->Check__VARIABLE_NAME(var_name) > 0)
	{
		m_sSlot = set_data;
		return 1;
	}

	// edo.RB1.WfrSns
	if(doCH__ARM_WFR_SNS->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("Yes") == 0)	m_sWfrSnsIntlk = "Y";
		else									m_sWfrSnsIntlk = "N";

		return 1;
	}

	return 1;
}

int CObj__VacRobot_WAVEII
::__Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;


	if(soCH__CHECK_CMMD->Check__VARIABLE_NAME(var_name) > 0)
	{
		double to_sec = _TO__QUERY;

		if(set_data.Find("RQ") < 0)
		{
			to_sec = _TO__ACT;
		}

		if(Proc__CMMD_RSP(var_name, set_data, to_sec, TRUE, l_rsp,l_err) < 0)
		{
			return -1;
		}

		return 1;
	}
	
	if(soCH__HYPER_TERMINAL_CMD->Check__VARIABLE_NAME(var_name) > 0)
	{
		CString str_time;
		aCH__HYPER_TERMINAL_CMD_TIMEOUT->Get__DATA(str_time);
		
		double to_sec = atof(str_time);
		str_cmmd.Format("%s", set_data);
		
		sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__ACT, TRUE, l_rsp,l_err) ;

		if(r_flag < 0)
		{	
			CString log_msg;

			log_msg.Format("[%s] Timeout Error. \n\n", str_cmmd);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(log_msg);
			return -1;
		}

		// ...
		{
			CString str_rsp = Get__STRING_OF_LIST(l_rsp);
			CString str_err = Get__STRING_OF_LIST(l_err);
	
			CString str_line = "";

			if(str_rsp.GetLength() > 0)
			{
				str_line += str_rsp;
				str_line += "\n";
			}
			if(str_err.GetLength() > 0)
			{
				str_line += str_err;
				str_line += "\n";
			}

			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(str_line);
		}

		// ...
		{
			SCX__SEQ_INFO x_seq_info;
			CString str_data;
			CString ch_data;

			ch_data = xCH__UPDATE_FLAG->Get__STRING();
			str_data.Format("%1d", atoi(ch_data)+1);
			xCH__UPDATE_FLAG->Set__DATA(str_data);
			_sleep(500);

			CString str_time = x_seq_info->Get__DATE_TIME_STRING();
			str_data.Format("[%s] : <----- RECV -----> \n", str_time);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(str_data);

			ch_data = xCH__UPDATE_FLAG->Get__STRING();
			str_data.Format("%1d", atoi(ch_data)+1);
			xCH__UPDATE_FLAG->Set__DATA(str_data);
			_sleep(500);
		}
		return 1;
	}

	return -1;
}

