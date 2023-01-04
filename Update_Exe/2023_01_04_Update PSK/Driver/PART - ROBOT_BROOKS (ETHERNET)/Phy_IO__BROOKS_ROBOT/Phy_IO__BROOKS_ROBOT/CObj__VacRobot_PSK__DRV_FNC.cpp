#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"
#include "CObj__VacRobot_PSK__DEF.h"

#include "Macro_Function.h"
#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int CObj__VacRobot_PSK
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__VacRobot_PSK
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;

	/*
	if((diCH__ARM_A_MAT_READ->Check__VARIABLE_NAME(var_name) > 0)
	|| (diCH__ARM_B_MAT_READ->Check__VARIABLE_NAME(var_name) > 0))
	{
		if(diCH__ARM_A_MAT_READ->Check__VARIABLE_NAME(var_name) > 0)
			str_cmmd = "RQ LOAD ARM A";
		else
			str_cmmd = "RQ LOAD ARM B";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(l_rsp.GetSize() > 1)
		{
			CString r_data = l_rsp[0];

			if(r_data.Find("ON") > 0)		read_data = "Present";
			else if(r_data.Find("OFF") > 0)		read_data = "Absent";
			else if(r_data.Find("?")  > 0)		read_data = "Unknown";
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

	if((diCH__ROBOT_STATE_READ__AUTO->Check__VARIABLE_NAME(var_name)   > 0)
	|| (diCH__ROBOT_STATE_READ__MANUAL->Check__VARIABLE_NAME(var_name) > 0))
	{
		str_cmmd = "TCL rqstate";     // BUSY, ERROR, ARM STATION, ARM Position, SERVO STATUS, ARM A STATUS
		
		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		
		if((r_flag >= 0)
		&& (l_rsp.GetSize() > 1))
		{
			CStringArray l_data;

			splitString(l_rsp[0], " ", l_data);
			
			if(l_data.GetSize() >= 7)
			{
				CString str_data;

				str_data = l_data[0];     // Busy
				if(str_data.CompareNoCase("N") == 0)		dCH__DRV_INFO_ACTIVE_BUSY->Set__DATA(STR__OFF);
				else										dCH__DRV_INFO_ACTIVE_BUSY->Set__DATA(STR__ON);

				str_data = l_data[1];     // Error
				sCH__DRV_INFO_ERROR_CODE->Set__DATA(str_data);

				//.. Can't Recive Not Working Arm Information Please
				// First Start Unknown
				{
					str_data = l_data[2];     // Arm A Station

					str_data = l_data[3];     // Arm A Position (RE:Retract , EX:Extend, HM:Home ,--:Not Target Arm, EO: Extend with offset, EV : Extend at VIA)

					str_data = l_data[4];     // Arm B Station 

					str_data = l_data[5];     // Arm B Position (RE:Retract , EX:Extend, HM:Home , --:Not Target Arm, EO: Extend with offset, EV : Extend at VIA)
				}

				str_data = l_data[6];     // Servo Status

				str_data = l_data[7];     // Arm_A Status
				if(str_data.CompareNoCase("ON") == 0)		dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Present");
				else										dCH__DRV_INFO_ARM_A_MAT_READ->Set__DATA("Absent");
				
				str_data = l_data[8];     // Arm_B Status
				if(str_data.CompareNoCase("ON") == 0)		dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Present");
				else										dCH__DRV_INFO_ARM_B_MAT_READ->Set__DATA("Absent");
			}

			read_data = STR__SUCCESS;
			return 1;
		}
		else
		{
			str_cmmd = "Load TCL scripts"; //When Fail Requset Satus, Reload TCL Scripts
			r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
			if(r_flag <0) {read_data = "FAIL";  return -1;}

			read_data = STR__FAIL;
			return -1;
		}
	}

	if(diCH__ROBOT_IO_STATE_READ->Check__VARIABLE_NAME(var_name) > 0) // For Check IO Sate When broke up issue
	{
		str_cmmd = "RQ IO STATE ALL";// AWC AVAILABLE SPEED 0.9
		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err);
		if(r_flag <0) {read_data = "FAIL"; return -1;}
		read_data = STR__SUCCESS;
		return 1;
	}

	if(diCH__COMM_STS->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(iActive__SIM_MODE > 0)
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

	if(diCH__ROBOT_INIT_CMD ->Check__VARIABLE_NAME(var_name) > 0)
	{
		
		str_cmmd = "SET OVERALLSPEED 0.9";// AWC AVAILABLE SPEED 0.9

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag <0) {read_data = "FAIL"; return -1;}

		str_cmmd = "Load TCL scripts";//For using "TCL rqstate"

		r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag <0) {read_data = "FAIL";  return -1;}

		/**
		str_cmmd = "SET SERVOS ON";// AWC AVAILABLE SPEED 0.9
		r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag <0) {read_data = "FAIL"; return -1;}
		**/
		read_data = STR__SUCCESS;
		return 1;
	}

	if(diCH__ROBOT_LOG_READ->Check__CHANNEL_NAME(var_name) > 0)
	{
		int r_flag = 0;
		str_cmmd = "RQ BIRTH";
		
		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ VERSION";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ DATE";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ TIME";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ HISTORY CMD ALL";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ HISTORY ERR ALL";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		str_cmmd = "RQ IO STATE ALL";

		if(r_flag <0) {read_data = "FAIL";  return -1;}

		read_data = "READ";
		return 1;
	}

	return -1;
}

int CObj__VacRobot_PSK
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;


	if(siCH__VERSION__MANUAL->Check__VARIABLE_NAME(var_name) > 0)
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

			sCH__INR_RB1_VERSION->Set__DATA(read_data);
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
int CObj__VacRobot_PSK
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

int CObj__VacRobot_PSK
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;


	if(doCH__COMMAND->Check__VARIABLE_NAME(var_name) > 0)
	{
		CString str_action;
		CString para__stn_name;
		double  to_sec = aCH__CFG_ACTION_TIMEOUT->Get__VALUE();		// KMS Over 10.0 sec

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
		else if(set_data.CompareNoCase("ChkLoad.All") == 0)
		{
			str_cmmd.Format("CHECK LOAD");
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
			// SET_CPTR_ON : 각 Station앞에 있는 센서를 ON 시킨다.
			str_cmmd.Format("SET CPTR %s ON", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("ASet_Cptr_Off") == 0)
		{
			// SET_CPTR_ON : 각 Station앞에 있는 센서를 OFF 시킨다.
			str_cmmd.Format("SET CPTR %s OFF", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("BSet_Cptr_On") == 0)
		{
			// SET_CPTR_ON : 각 Station앞에 있는 센서를 ON 시킨다.
			str_cmmd.Format("SET CPTR %s ON", m_sCptr_StationB);
		}
		else if(set_data.CompareNoCase("BSet_Cptr_Off") == 0)
		{
			// SET_CPTR_ON : 각 Station앞에 있는 센서를 OFF 시킨다.
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
			// RQ CPTR station : 각 Station앞에 있는 센서값을 가져온다.
			str_cmmd.Format("RQ CPTR %s", m_sCptr_StationA);
		}
		else if(set_data.CompareNoCase("BGet_Cptr") == 0)
		{
			// RQ CPTR station : 각 Station앞에 있는 센서값을 가져온다.
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
		else if(set_data.CompareNoCase("Servos.ON") == 0)
		{
			str_cmmd.Format("SET SERVOS ON");
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
				sCH__CPTR_SNS_FULL_VAL->Set__DATA(rsp_data);
			}
			else if((set_data.CompareNoCase("AGet_Current_Stn") == 0) 
				 || (set_data.CompareNoCase("BGet_Current_Stn") == 0))
			{
				sCH__DA_RESULT_FULL_VAL->Set__DATA(rsp_data);
			}
			else if(set_data.CompareNoCase("WAF_CEN.DATA") == 0)
			{
				sCH__DA_RESULT_FULL_VAL->Set__DATA(rsp_data);

				// ...
				bool active_offset = false;
				int count_offset = 0;
				
				CStringArray l_data_array;
				CString AWC_Data = l_rsp[0];
				CString str__off_r; 
				CString str__off_t; 

				
				if(l_rsp.GetSize() >= 2)
				{
					splitString(AWC_Data," ",l_data_array);
					if(l_data_array.GetSize() >= 15)
					{
						str__off_r = l_data_array[13]; // microns
						str__off_t = l_data_array[14]; //millidegrees
						
						active_offset = true;
					}
				}

				/*(*
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
				**/

				if(active_offset)
				{
					CString str_value;
					
					double r_value = atof(str__off_r) / 1000.0;
					double t_value = atof(str__off_t) / 1000.0;

					str_value.Format("%.3f", r_value);
					sCH__DA_RESULT_R_OFFSET_MM->Set__DATA(str_value);
					
					str_value.Format("%.3f", t_value);
					sCH__DA_RESULT_T_OFFSET_DEG->Set__DATA(str_value);

					//
					str_value.Format("%.3f", r_value * cos(t_value));
					sCH__DA_RESULT_X_OFFSET_MM->Set__DATA(str_value);
					
					str_value.Format("%.3f", r_value * sin(t_value));
					sCH__DA_RESULT_Y_OFFSET_MM->Set__DATA(str_value);

				}
				else
				{
					sCH__DA_RESULT_R_OFFSET_MM->Set__DATA("0.0");
					sCH__DA_RESULT_T_OFFSET_DEG->Set__DATA("0.0");
					
					sCH__DA_RESULT_X_OFFSET_MM->Set__DATA("0.0");
					sCH__DA_RESULT_Y_OFFSET_MM->Set__DATA("0.0");
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
		// m_sSlot = set_data;
		m_sSlot = "1";
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

int CObj__VacRobot_PSK
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

int CObj__VacRobot_PSK
::splitString(CString strData, CString Seperator, CStringArray& arr)
{
	CString data = strData;
	int Position = 0;
	CString Token;

	Token = data.Tokenize(Seperator, Position);

	if (Token != L"") 
		arr.Add(Token);

	while (!Token.IsEmpty())
	{
		// Get next token.
		Token = data.Tokenize(Seperator, Position);

		if (Token != L"")
		{
			arr.Add(Token);
		}
	}

	data.Empty();
	Token.Empty();
	return 1;
}