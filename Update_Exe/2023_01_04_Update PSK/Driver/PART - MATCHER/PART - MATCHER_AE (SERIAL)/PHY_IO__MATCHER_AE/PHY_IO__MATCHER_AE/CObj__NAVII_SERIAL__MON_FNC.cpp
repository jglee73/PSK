#include "StdAfx.h"
#include "CObj__NAVII_SERIAL.h"


// ...
int CObj__NAVII_SERIAL
::Mon__MONITOR(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm)
{
	// ...
	{
		CString ch_data;
		sCH__INFO_CTRL_MODE_CH -> Set__DATA(STR__HOST);
		
		aCH__INFO_LOAD_POS_CH -> Set__VALUE(0.0);
		aCH__INFO_TUNE_POS_CH -> Set__VALUE(0.0);
		aCH__INFO_CAP_POS_CH -> Set__VALUE(0.0);
		aCH__INFO_REAL_IN_SNS -> Set__VALUE(0.0);
		aCH__INFO_IMAGE_IN_SNS -> Set__VALUE(0.0);
		
		//
		ch_data = "0.0";
		sCH__CUR_LOAD_POS_CH -> Set__DATA(ch_data);
		sCH__CUR_TUNE_POS_CH -> Set__DATA(ch_data);
		sCH__CUR_CAP_POS_CH -> Set__DATA(ch_data);
		
	}
	
	
	int loop_count = 0;
	bActive__COMM_ONLINE = true;
	
	while(1)
	{
		
		p_variable->Wait__SINGLE_OBJECT(0.1);


		loop_count++;
		if(loop_count > 10)			loop_count = 1;

		if((loop_count == 1) || (loop_count == 6))
		{
			siCH__REPORT_AUXILIARY_CAP_PARM->Get__STRING();
		}

		else if(loop_count == 2)
		{
			siCH__REPORT_INPUT_SNS_DATA -> Get__STRING();
		}
		else if(loop_count == 3)
		{
			siCH__REPORT_OUTPUT_SNS1_DATA -> Get__STRING();
		}
		else if(loop_count == 4)
		{
			if(dCH__MAT_TYPE ->Check__DATA(STR__SOURCE)) siCH__REPORT_OUTPUT_SNS2_DATA -> Get__STRING(); // KMS : Only use SNS2 Data For Source, Bais only have SNS1 Data. 
		}
		else if(loop_count == 5)
		{
			//siCH__REPORT_CONDENSED_MATCH_SNAPSHOT -> Get__STRING();
		}

		if(loop_count == 1)
		{
			if(bActive__COMM_ONLINE)			dCH__MON_COMM_STS->Set__DATA(STR__ONLINE);
			else								dCH__MON_COMM_STS->Set__DATA(STR__OFFLINE);
		}

		if(dCH__MON_COMM_STS->Check__DATA(STR__OFFLINE) > 0)
		{
			int alarm_id = ALID__OFFLINE_ALARM;
			CString alm_msg;
			CString	r_act;

			alm_msg = sPROTOCOL_INFO;
			p_alarm->Check__ALARM(alarm_id,r_act);
			p_alarm->Post__ALARM_With_MESSAGE(alarm_id,alm_msg);
		}
		else
		{
			siCH__REPORT_PROCESS_STATUS->Get__STRING();
		}
		
		if(iActive_SIM > 0)
		{
			// Sync Set Data & Sns Data
			CString ch_data;
			// LOAD.POS ...
			{
				aCH__INFO_LOAD_POS_CH->Get__DATA(ch_data);
				sCH__CUR_LOAD_POS_CH->Set__DATA(ch_data);
				
			}
			// TUNE.POS ...
			{
				aCH__INFO_TUNE_POS_CH->Get__DATA(ch_data);
				sCH__CUR_TUNE_POS_CH->Set__DATA(ch_data);
				
			}
			// CAP.POS ...
			{
				aCH__INFO_CAP_POS_CH->Get__DATA(ch_data);
				sCH__CUR_CAP_POS_CH->Set__DATA(ch_data);
			}
		}
		
	}
	
	
	return 1;
}
