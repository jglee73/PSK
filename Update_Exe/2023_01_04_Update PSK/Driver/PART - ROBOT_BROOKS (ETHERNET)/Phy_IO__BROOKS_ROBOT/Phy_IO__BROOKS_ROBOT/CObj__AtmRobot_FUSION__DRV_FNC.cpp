#include "StdAfx.h"
#include "CObj__AtmRobot_FUSION.h"
#include "CObj__AtmRobot_FUSION__DEF.h"

#include "CCommon_DEF.h"


//------------------------------------------------------------------------------------
int CObj__AtmRobot_FUSION
::__Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{
	if(aiCH__ANG_POS->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = dDRV__RB_ANGLE_POS;
		return 1;
	}
	if(aiCH__ANG_ECC->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = dDRV__RB_ANGLE_ECC;
		return 1;
	}
	if(aiCH__ECC_MAG->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = dDRV__RB_ECC_MAG;
		return 1;
	}
	if(aiCH__AVRG_RD->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = dDRV__RB_AVG_RD;
		return 1;
	}
	if(aiCH__ERROR_ID->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = (double) iDRV__ERROR_ID;			//
		return 1;
	}

	return -1;
}

int CObj__AtmRobot_FUSION
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{
	return -1;

	// ...
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;

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
	
	// eRB1.ArmAWfr   (Unknown Absent Present)
	if(diCH__ARM_A_WFR->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ LOAD A";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;

		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetAt(5) == '?')
			{
				read_data = "Unknown";
				return 1;
			}
			if((str__recv_data.GetAt(5) == 'O')&&(str__recv_data.GetAt(6) == 'F'))
			{
				read_data = "Absent";
				return 1;
			}
			*/
			
			read_data = "Present";
		}
		return 1;
	}
	// eRB1.VacSnsA   (ON OFF)
	if(diCH__VAC_SNS_A->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ VAC GRIP A";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;

		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetLength() > 11)  
			{
				char ch1;
				char ch2;

				ch1 = str__recv_data.GetAt(9);    // 'O'
				ch2 = str__recv_data.GetAt(10);   // 'N' or 'F'

				if((ch1 == 'O') && (ch2 == 'F'))
				{
					sDRV__RB_VAC_SNS_A = "OFF";
				}
				else
				{
					sDRV__RB_VAC_SNS_A = "ON";
				}

				read_data = sDRV__RB_VAC_SNS_A;
			}
			*/
		}
		return 1;
	}

	// eRB1.Rescan  (D/I) N/Y
	if(diCH__RESCAN->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ ALIGNER RSLT";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;

		if(l_rsp.GetSize() > 0)  
		{
			/*
			CString str1;
			CString str2;
			CString str3;
			CString str4;

			Fnc__IndexStrTo4Word(str__recv_data,' ',14,&str1,&str2,&str3,&str4);

			dDRV__RB_ANGLE_POS = atof(str1);
			dDRV__RB_ANGLE_ECC = atof(str2);
			dDRV__RB_ECC_MAG   = atof(str3);
			dDRV__RB_AVG_RD    = atof(str4);
			dDRV__RB_ECC_MAG /= 1000.0;
									
			Fnc__IndexStrTo1Word(str__recv_data, __CR, 36, &str1);
			
			if(str1.CompareNoCase("N") == 0)	sDRV__RESCAN = "N";
			else								sDRV__RESCAN = "Y";

			str__recv_data = str1;
			*/
		}
		return 1;
	}

	// eRB1.CurrStn (1 --- 25)
	if(diCH__CURR_STN->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ POS STN T";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;
		
		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetLength() > 7)		// OK
			{
				str__recv_data.SetAt(0,'0');  // 'P'
				str__recv_data.SetAt(1,'0');  // 'O'
				str__recv_data.SetAt(2,'0');  // 'S'
				str__recv_data.SetAt(3,'0');  // ' '
				str__recv_data.SetAt(4,'0');  // 'S'
				str__recv_data.SetAt(5,'0');  // 'T'
				str__recv_data.SetAt(6,'0');  // 'N'
				str__recv_data.SetAt(7,'0');  // ' '

				read_data.Format("%d", atoi(str__recv_data));
			}
			*/
		}
		return 1;		
	}
	
	// eRB1.VacStsA (ON OFF)
	if(diCH__VAC_STS_A->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ VAC GRIP A";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;
		
		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetLength() > 11)		// OK
			{
				char ch1;
				char ch2;

				ch1 = str__recv_data.GetAt(9);	  // 'O'
				ch2 = str__recv_data.GetAt(10);   // 'N' or 'F'

				if((ch1 == 'O')&&(ch2 == 'F'))     sDRV__RB_VAC_SNS_A = "OFF";
				else							   sDRV__RB_VAC_SNS_A = "ON";

				read_data = sDRV__RB_VAC_SNS_A;
			}
			*/
		}
		return 1;		
	}
	
	// eRB1.ALWfr ( ? No Yes )
	if(diCH__AL_WFR->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ ALIGNER RQWPRS";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;
		
		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetLength() > 14)  
			{
				CString str1;
				Fnc__IndexStrTo1Word(str__recv_data, __CR, 17, &str1);

				read_data = str1;
			}
			*/
		}
		return 1;
	}

	//
	if(diCH__ROBOT_CURR_POS->Check__VARIABLE_NAME(var_name) > 0)
	{
		str_cmmd = "RQ POS STN ALL";

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)			return -1;
		
		if(l_rsp.GetSize() > 0)
		{
			/*
			if(str__recv_data.GetLength() > 7)  
			{
				CString str1;
				CString str2;
				CString str3;
				CString str4;

				Fnc__IndexStrTo4Word(str__recv_data,' ',9,&str1,&str2,&str3,&str4);

				// (R)		
					 if(str1.Compare("RE") == 0)		sDRV__RB_AR_POS = "Retract";
				else if(str1.Compare("EX") == 0)		sDRV__RB_AR_POS = "Extend";
				else                            		sDRV__RB_AR_POS = "Unknown";

				// rotation (T)
				int b_str2 = atoi(str2);

				if((b_str2 >= 1)&&(b_str2 <= 25))
				{
					sDRV__RB_T_POS.Format("%1d",b_str2);
				}
				else
				{
					sDRV__RB_T_POS = "Unknown";
				}

				// (Z)		
					 if(str4.Compare("DN") == 0)		sDRV__RB_Z_POS = "Down";
				else if(str4.Compare("UP") == 0)		sDRV__RB_Z_POS = "Up";
				else                            		sDRV__RB_Z_POS = "Unknown";

				read_data = "On";
			}
			*/
		}
		return 1;
	}

	if(diCH__ROBOT_Z_POS->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = sDRV__RB_Z_POS;
		return 1;  
	}
	if(diCH__ROBOT_AR_POS->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = sDRV__RB_AR_POS;
		return 1;
	}
	if(diCH__ROBOT_T_POS->Check__VARIABLE_NAME(var_name) > 0)
	{
		read_data = sDRV__RB_T_POS;
		return 1;  
	}

	return -1;
}

int CObj__AtmRobot_FUSION
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{

	return -1;
}


//------------------------------------------------------------------------------------
int CObj__AtmRobot_FUSION
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{
	iDRV__ERROR_ID = 0;
	sCH__INR__ERROR_ID_DEC->Set__DATA("0");
	sCH__INR__ERROR_ID_HEXA->Set__DATA("Ox0");
	
	iDRV__ALGNER_ERROR_ID = 0;
	sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");

	if(aoCH__ANGLE->Check__VARIABLE_NAME(var_name) > 0)
	{
		dDRV__RB_ANGLE_DEG = set_data;
	 	return 1;  
	}

	return 1;
}

int CObj__AtmRobot_FUSION
::__Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	CString str_cmmd;
	CStringArray l_rsp;
	CStringArray l_err;

	iDRV__ERROR_ID = 0;
	sCH__INR__ERROR_ID_DEC->Set__DATA("0");
	sCH__INR__ERROR_ID_HEXA->Set__DATA("Ox0");
	
	iDRV__ALGNER_ERROR_ID = 0;
	sCH__INR__ALGINER_ERROR_ID->Set__DATA("0");

	// eRB2.Command
	//   PrepPick  PrepPlace  Pick  Place  GetLocSte  Home  Reset  MapStn  GetMap  
	//   InitAlgn  ALAlign  ALHome  ALResult  ALLoadPP
	if(doCH__COMMAND->Check__VARIABLE_NAME(var_name) > 0)
	{
		double to_sec = _TO__ACT;

		if(set_data.CompareNoCase("PrepPick") == 0) 
		{
			str_cmmd.Format("rc PickPrepFrom atm1 1 %s %1d",
							sDRV__STN_NAME,
							iDRV__SLOT_NO);
		}
		else if(set_data.CompareNoCase("PrepPlace") == 0) 
		{
			str_cmmd.Format("rc PlacePrepTo atm1 1 %s %1d",
							sDRV__STN_NAME,
							iDRV__SLOT_NO);
		}
		else if(set_data.CompareNoCase("Pick") == 0) 
		{
			str_cmmd.Format("rc PickFrom atm1 1 %s %1d", 
				            sDRV__STN_NAME,
							iDRV__SLOT_NO);
		}
		else if(set_data.CompareNoCase("Place") == 0) 
		{
			str_cmmd.Format("rc PlaceTo atm1 1 %s %1d", 
							sDRV__STN_NAME,
							iDRV__SLOT_NO);
		}
		else if(set_data.CompareNoCase("Home") == 0) 
		{
			str_cmmd.Format("rc InitializeResources");
		}
		else if(set_data.CompareNoCase("Reset") == 0)
		{
			str_cmmd.Format("Restart");
		}
		else if(set_data.CompareNoCase("ShotDown") == 0)
		{
			str_cmmd.Format("ShutDown");
		}
		else if(set_data.CompareNoCase("MapStn") == 0)     // Mapping LPx ...
		{
			str_cmmd.Format("rc mapresource map1 %s", 
				        	sDRV__STN_NAME);
		}
		else if(set_data.CompareNoCase("GetMap") == 0)     // LPx의 Mapping 결과를 가져온다.
		{
			str_cmmd.Format("%s getlocationstates",
				            sDRV__STN_NAME);
		}
		else if(set_data.CompareNoCase("RB.GetMap") == 0) 
		{
			str_cmmd.Format("atm1 GetLocationStates");
		}
		else if(set_data.CompareNoCase("InitAlgn") == 0) 
		{
			str_cmmd.Format("algn1 InitializeResource");
		}
		else if(set_data.CompareNoCase("ALHome") == 0)
		{
			str_cmmd.Format("algn1 InitializeResource");
		}
		else if(set_data.CompareNoCase("ALResult") == 0) 
		{
			sCH__AL_GetInfo_Update_Req->Set__DATA(STR__YES);

			// ...
			CII__VAR_STRING_CTRL *pch_info;

			int i_limit = 10;
			int i;

			for(i=0; i<i_limit; i++)
			{
				if(i == 0)
				{
					str_cmmd = "algn1 GetEccentricityAngle";
					pch_info = sCH__GetInfo_AL_GetEccentricityAngle.Get__PTR();
				}
				else if(i == 1)
				{
					str_cmmd = "algn1 GetEccentricityMagnitude";
					pch_info = sCH__GetInfo_AL_GetEccentricityMagnitude.Get__PTR();
				}
				else if(i == 2)
				{
					str_cmmd = "algn1 GetEccentricityTransform";
					pch_info = sCH__GetInfo_AL_GetEccentricityTransform.Get__PTR();
				}
				else if(i == 3)
				{
					str_cmmd = "algn1 GetFiducialAngle";
					pch_info = sCH__GetInfo_AL_GetFiducialAngle.Get__PTR();
				}
				else
				{
					continue;
				}

				int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, to_sec, TRUE, l_rsp,l_err) ;
				if(r_flag < 0)
				{
					pch_info->Set__DATA("Error");
					continue;;
				}

				// ...
				{
					CString rsp_data;
					CString rsp_bff;

					int k_limit = l_rsp.GetSize();
					int k;

					for(k=0; k<k_limit; k++)
					{
						if(k > 0)		rsp_data += " ";
						
						rsp_bff.Format("%s", l_rsp[k]);
						rsp_data += rsp_bff;
					}
					pch_info->Set__DATA(rsp_data);
				}
			}

			sCH__AL_GetInfo_Update_Req->Set__DATA("");
			return 1;
		}
		else if(set_data.CompareNoCase("ALAlign") == 0)
		{
			str_cmmd.Format("algn1 align atm1 1 %1d", (int) dDRV__RB_ANGLE_DEG);
		}
		else if(set_data.CompareNoCase("ALRotate") == 0)
		{
			str_cmmd.Format("algn1 rotate %1d", (int) dDRV__RB_ANGLE_DEG);
		}
		else if(set_data.CompareNoCase("ALScan") == 0)
		{
			str_cmmd = "algn1 Scan atm1 1";
		}
		else if(set_data.CompareNoCase("ALLoadPP") == 0) 
		{
			str_cmmd.Format("algn1 align atm1 1 %d", (int) dDRV__RB_ANGLE_DEG);
		}

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, to_sec, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		if(set_data.CompareNoCase("RB.GetMap") == 0) 
		{
			CString wfr_sts = "Unknown";

			if(l_rsp.GetSize() > 0)
			{
				wfr_sts = l_rsp[0];
			}

			sCH__GetInfo_RB_GetLocationStates->Set__DATA(wfr_sts);
		}
		else if(set_data.CompareNoCase("GetMap") == 0)     // LPx의 Mapping Result Update ...
		{
			int i_limit = l_rsp.GetSize();
			int i;

			if(i_limit > CFG_LPx__SLOT_SIZE)		i_limit = CFG_LPx__SLOT_SIZE;

			for(i=0; i<i_limit; i++)
			{
				CString str_data = l_rsp[i];
				CString str_slot = "UNKNOWN";

				if(str_data.CompareNoCase("Unoccupied") == 0)		str_slot = "ABSENT";
				if(str_data.CompareNoCase("Occupied")   == 0)		str_slot = "PRESENT";

				dCH__LPx_SLOT_STATUS[i]->Set__DATA(str_slot);
			}					
		}
		return 1;   
	}
	
	// eRB1.Arm (A B)
	if(doCH__ARM->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("B") == 0)	sDRV__ARM_NO = "B";   
		else                                	sDRV__ARM_NO = "A";

		return 1;   
	}
	// eRB1.Slot (1 - 30)
	if(doCH__SLOT->Check__VARIABLE_NAME(var_name) > 0)
	{
		iDRV__SLOT_NO = atoi(set_data);
		return 1;  
	}

	// eRB1.WfrSize (1 2 3 4 5 6 7 20 21 22 23)
	if(doCH__WFR_SIZE->Check__VARIABLE_NAME(var_name) > 0)
	{
			 if(set_data.CompareNoCase("1")  == 0)		sDRV__RB_WFR_SIZE = "1";
		else if(set_data.CompareNoCase("2")  == 0)		sDRV__RB_WFR_SIZE = "2";
		else if(set_data.CompareNoCase("3")  == 0)		sDRV__RB_WFR_SIZE = "3";
		else if(set_data.CompareNoCase("4")  == 0)		sDRV__RB_WFR_SIZE = "4";
		else if(set_data.CompareNoCase("5")  == 0)		sDRV__RB_WFR_SIZE = "5";
		else if(set_data.CompareNoCase("6")  == 0)		sDRV__RB_WFR_SIZE = "6";
		else if(set_data.CompareNoCase("7")  == 0)		sDRV__RB_WFR_SIZE = "7";
		else if(set_data.CompareNoCase("20") == 0)		sDRV__RB_WFR_SIZE = "20";
		else if(set_data.CompareNoCase("21") == 0)		sDRV__RB_WFR_SIZE = "21";
		else if(set_data.CompareNoCase("22") == 0)		sDRV__RB_WFR_SIZE = "22";
		else                                			sDRV__RB_WFR_SIZE = "23";

		return 1;  
	}
	// eRB1.WfrFDCL (None  Flat  Ntch)
	if(doCH__WFR_FDCL->Check__VARIABLE_NAME(var_name) > 0)
	{
			 if(set_data.CompareNoCase("None") == 0)	sDRV__RB_WFR_FDCL = "NONE";
		else if(set_data.CompareNoCase("Flat") == 0)	sDRV__RB_WFR_FDCL = "FLAT";
		else                                			sDRV__RB_WFR_FDCL = "NTCH";

		return 1;  
	}
	// eRB1.WfrShape (Round Square)
	if(doCH__WFR_SHAPE->Check__VARIABLE_NAME(var_name) > 0)
	{
		     if(set_data.CompareNoCase("Round")  == 0)	sDRV__RB_WFR_SHAPE = "ROUND";
		else if(set_data.CompareNoCase("Square") == 0)	sDRV__RB_WFR_SHAPE = "SQUARE";
		else                                			sDRV__RB_WFR_SHAPE = "ROUND";

	 	return 1;  
	}
	// eATMRB1.WfrCCD
	if(doCH__WFR_CCD->Check__VARIABLE_NAME(var_name) > 0)
	{
			 if(set_data.CompareNoCase("1") == 0)		iDRV__RB_WFR_CCD = 1;
		else if(set_data.CompareNoCase("2") == 0)		iDRV__RB_WFR_CCD = 2;
		else                                			iDRV__RB_WFR_CCD = 3;

		return 1;  
	}

	// eRB1.Material (? 0 1 2 3 4 5 6 7 20 21 22 23 FP)
	/*
	3 = 100mm
	4 = 125mm
	5 = 150mm
	6 = 200mm
	7 = 300mm
	*/
	if(doCH__MATERIAL->Check__VARIABLE_NAME(var_name) > 0)
	{
			 if(set_data.CompareNoCase("0")  == 0)		sDRV__RB_MATERIAL = "0";
		else if(set_data.CompareNoCase("1")  == 0)		sDRV__RB_MATERIAL = "1";
		else if(set_data.CompareNoCase("2")  == 0)		sDRV__RB_MATERIAL = "2";
		else if(set_data.CompareNoCase("3")  == 0)		sDRV__RB_MATERIAL = "3";
		else if(set_data.CompareNoCase("4")  == 0)		sDRV__RB_MATERIAL = "4";
		else if(set_data.CompareNoCase("5")  == 0)		sDRV__RB_MATERIAL = "5";
		else if(set_data.CompareNoCase("6")  == 0)		sDRV__RB_MATERIAL = "6";
		else if(set_data.CompareNoCase("7")  == 0)		sDRV__RB_MATERIAL = "7";
		else if(set_data.CompareNoCase("20") == 0)		sDRV__RB_MATERIAL = "20";
		else if(set_data.CompareNoCase("21") == 0)		sDRV__RB_MATERIAL = "21";
		else if(set_data.CompareNoCase("22") == 0)		sDRV__RB_MATERIAL = "22";
		else if(set_data.CompareNoCase("23") == 0)		sDRV__RB_MATERIAL = "23";
		else if(set_data.CompareNoCase("FP") == 0)		sDRV__RB_MATERIAL = "FP";
		else                                			sDRV__RB_MATERIAL = "?";

		return 1;  
	}

	if(doCH__SYSTEM_TRACKING_MATERIAL->Check__VARIABLE_NAME(var_name) > 0)
	{
		if(set_data.CompareNoCase("False") == 0)			
		{
			str_cmmd = "System MaterialTracking false";
		}
		else if(set_data.CompareNoCase("True") == 0)
		{
			str_cmmd = "System MaterialTracking true";
		}
		else	
		{
			str_cmmd = "System MaterialTracking";			
		}

		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
		if(r_flag < 0)		return -1;

		return 1;
	}

	return -1;
}

int CObj__AtmRobot_FUSION
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
		CString str_data;
		CString ch_data;

		str_cmmd = set_data;	
		double to_sec = aCH__HYPER_TERMINAL_CMD_TIMEOUT->Get__VALUE();
			
		sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");

		// ...
		int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, to_sec, TRUE, l_rsp,l_err) ;

		if(r_flag < 0)
		{
			str_data.Format("[%s] Timeout Error. \n\n", str_cmmd);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(str_data);
			return -1;
		}

		// ...
		{
			str_data  = Get__STRING_OF_LIST(l_rsp);
			str_data += "\n";

			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(str_data);
		}

		// ...
		{
			SCX__SEQ_INFO x_seq_info;
			CString str_time;

			ch_data = xCH__UPDATE_FLAG->Get__STRING();
			str_data.Format("%1d", atoi(ch_data) + 1);
			xCH__UPDATE_FLAG->Set__DATA(str_data);
			_sleep(500);

			str_time = x_seq_info->Get__DATE_TIME_STRING();
			str_data.Format("[%s] : <----- RECV -----> \n", str_time);
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA("");
			sCH__HYPER_TERMINAL_RECV_MSG->Set__DATA(str_data);

			ch_data = xCH__UPDATE_FLAG->Get__STRING();
			str_data.Format("%1d", atoi(ch_data) + 1);
			xCH__UPDATE_FLAG->Set__DATA(str_data);
			_sleep(500);
		}
		return 1;
	}

	if(soCH__GET_INFO_CMD->Check__VARIABLE_NAME(var_name) > 0)
	{
		sCH__Robot_GetInfo_Update_Req->Set__DATA(STR__YES);

		// ...
		CII__VAR_STRING_CTRL *p_sch;
		CString ch_data;

		int i_limit = 20;
		int i;

		for(i=0; i<i_limit; i++)
		{
			if(i == 0)				// atm1 GetApplicationID
			{
				str_cmmd = "atm1 GetApplicationID";
				p_sch = sCH__GetInfo_RB_GetApplicationID.Get__PTR();
			}
			else if(i == 1)			// atm1 GetLocationStates
			{
				str_cmmd = "atm1 GetLocationStates";
				p_sch = sCH__GetInfo_RB_GetLocationStates.Get__PTR();
			}
			else if(i == 2)			// atm1 GetSpeed
			{
				str_cmmd = "atm1 GetSpeed";	
				p_sch = sCH__GetInfo_RB_GetSpeed.Get__PTR();
			}
			else if(i == 3)			// atm1 GetVacuumSensorValue 1
			{
				str_cmmd = "atm1 GetVacuumSensorValue 1";	
				p_sch = sCH__GetInfo_RB_GetVacuumSensorValue.Get__PTR();
			}
			else if(i == 4)			// atm1 IsServoed
			{
				str_cmmd = "atm1 IsServoed";
				p_sch = sCH__GetInfo_RB_IsServoed.Get__PTR();
			}
			else if(i == 5)			// system GetStations
			{
				str_cmmd = "system GetStations";
				p_sch = sCH__GetInfo_SYS_GetStations.Get__PTR();
			}
			else if(i == 6)			// system getdevices all
			{
				str_cmmd = "system getdevices all";		
				p_sch = sCH__GetInfo_SYS_Getdevices.Get__PTR();
			}
			else if(i == 7)			// system GetSafetyEnabled
			{
				str_cmmd = "system GetSafetyEnabled";		
				p_sch = sCH__GetInfo_SYS_GetSafetyEnabled.Get__PTR();
			}	
			else if(i == 8)			// system GetSafetyState
			{
				str_cmmd = "system GetSafetyState";		
				p_sch = sCH__GetInfo_SYS_GetSafetyState.Get__PTR();
			}
			else if(i == 9)			// Version
			{
				str_cmmd = "Version";
				p_sch = sCH__GetInfo_Version.Get__PTR();
			}
			else
			{
				continue;
			}
	
			int r_flag = Proc__CMMD_RSP(var_name, str_cmmd, _TO__QUERY, TRUE, l_rsp,l_err) ;
			if(r_flag < 0)		continue;

			// ...
			{
				ch_data = Get__STRING_OF_LIST(l_rsp);
				p_sch->Set__DATA(ch_data);
			}
		}

		sCH__Robot_GetInfo_Update_Req->Set__DATA("");
		return 1;
	}

	if(soCH__STN_NAME->Check__VARIABLE_NAME(var_name) > 0)
	{
		sDRV__STN_NAME = set_data;
		return 1;  
	}

	return -1;
}
