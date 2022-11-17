#include "StdAfx.h"
#include "CObj__NAVII_SERIAL.h"


#define _DRV_CMMD__SET_ALL_CAPACITOR_INIT					125 // Init
#define _DRV_CMMD__SET_CAPACITOR_LIMIT						84
#define _DRV_CMMD__SET_INTERNAL_EXTERNAL_PRESET             97
#define _DRV_CMMD__SET_ACTIVE_PRESET						91
#define _DRV_CMMD__SET_AUXILIARY_CAP						95 // CAP, KMS:221026
#define _DRV_CMMD__SET_CONTROL_MODE							93 // Host/Manual
#define _DRV_CMMD__SET_LOAD_POS								112 // Shunt
#define _DRV_CMMD__SET_TUNE_POS								122 // Serise
#define _DRV_CMMD__SET_CAPACITOR_MOTOR_POS					124 // Shut&Serise Both
#define _DRV_CMMD__SET_CLAER_LATCHED_FAULTS					119 // KMS:221026


#define _DRV_CMMD__REPORT_CONTROL_MODE						163
#define _DRV_CMMD__REPORT_CAPACITOR_POS						180
#define _DRV_CMMD__REPORT_PROCESS_STATUS					162	// KMS:221026
#define _DRV_CMMD__REPORT_AUXILIARY_CAPACITOR_PARAM			165	// KMS:221026
#define _DRV_CMMD__REPORT_MEASURED_PARAMTER	 				248 // SUB: 201, 202 
#define _DRV_CMMD__REPORT_CONDENSED_MATCH_SNAPSHOT			219 // KMS

//------------------------------------------------------------------------------------
int CObj__NAVII_SERIAL
::__Read__ANALOG(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, double& read_data)
{

	return -1;
}

int CObj__NAVII_SERIAL
::__Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index)
{

	return -1;
}

int CObj__NAVII_SERIAL
::__Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data)
{
	unsigned char r_data[MAX_CHAR] = {0,};
	unsigned char s_data[MAX_CHAR] = {0,};
	CString ch_data;

	byte addr_id = (byte) aCH__CFG_PART_ADDRES_ID->Get__VALUE();

	#pragma region LOAD_TUNE_CAP
	if((siCH__CTRL_MODE_HEXA_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__CTRL_MODE_HEXA_CH2->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__CAPACITOR_POS_HEXA_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__CAPACITOR_POS_HEXA_CH2->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__REPORT_AUXILIARY_CAP_PARM->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = 0;
		byte s_data_len = 0;
		byte r_data_len = 0;
		byte sub_cmmd = 0;

		int para_id  = 0;

		if((siCH__CTRL_MODE_HEXA_CH1->Check__VARIABLE_NAME(var_name) > 0)
		|| (siCH__CTRL_MODE_HEXA_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__REPORT_CONTROL_MODE; // 163
			s_data_len = 2;
			r_data_len = 4;

				 if(siCH__CTRL_MODE_HEXA_CH1->Check__VARIABLE_NAME(var_name) > 0)			para_id = 1;
			else if(siCH__CTRL_MODE_HEXA_CH2->Check__VARIABLE_NAME(var_name) > 0)			para_id = 2;
			else																			return -1;

			s_data[0] = 0x0ff & para_id;
			s_data[1] = 0x00;
		}
		else if((siCH__CAPACITOR_POS_HEXA_CH1->Check__VARIABLE_NAME(var_name) > 0)
			 || (siCH__CAPACITOR_POS_HEXA_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__REPORT_CAPACITOR_POS; // 180
			s_data_len = 2;
			r_data_len = 6;

				 if(siCH__CAPACITOR_POS_HEXA_CH1 -> Check__VARIABLE_NAME(var_name) > 0)		para_id = 1;
			else if(siCH__CAPACITOR_POS_HEXA_CH2 -> Check__VARIABLE_NAME(var_name) > 0)		para_id = 2;
			else																			return -1;

			s_data[0] = 0x0ff & para_id;
			s_data[1] = 0x00;
		}

		else if(siCH__REPORT_PROCESS_STATUS -> Check__VARIABLE_NAME(var_name) > 0)
		{
			cmmd_id = _DRV_CMMD__REPORT_PROCESS_STATUS; // 162
			s_data_len = 0;
			r_data_len = 4;
			para_id = 1; // Only_Use:CH1

			s_data[0] = 0x0ff & para_id;
			s_data[1] = 0x00;
		}

		else if(siCH__REPORT_AUXILIARY_CAP_PARM -> Check__VARIABLE_NAME(var_name) > 0 )
		{
			cmmd_id = _DRV_CMMD__REPORT_AUXILIARY_CAPACITOR_PARAM; // 165
			s_data_len = 2;
			r_data_len = 3;
			
			int Param_select = 0; // Report Auxiliary Capacitor in "%" (Byte 0
			
			s_data[0] = 0x0ff & Param_select;
			s_data[1] = 0x00;
		}

		else
		{
			return -11;
		}

		//...
		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);	
		
		// Recive Data Parse...
		if(r_len >= r_data_len)
		{
			if(cmmd_id == _DRV_CMMD__REPORT_CONTROL_MODE)
			{
				// 0, 1 (Header, Command)
				byte byte_00 = 0x0ff & r_data[2]; 
				byte byte_01 = 0x0ff & r_data[3];
				byte byte_02 = 0x0ff & r_data[4];
				byte byte_03 = 0x0ff & r_data[5];

				//
				CString str_mode = "";

				switch(byte_02)
				{
					case 0:		str_mode = STR__USER;			break;
					case 1:		str_mode = STR__AUTO;			break;
					case 2:		str_mode = STR__HOST;			break;

					default:	str_mode = STR__UNKNOWN;		break;
				}

					 if(para_id == 1)		sCH__INFO_CTRL_MODE_CH1->Set__DATA(str_mode);
				else if(para_id == 2)		sCH__INFO_CTRL_MODE_CH2->Set__DATA(str_mode);

				//
				read_data.Format("%02X%02X %02X%02X", byte_00, byte_01, byte_02, byte_03);
			}
			else if(cmmd_id == _DRV_CMMD__REPORT_CAPACITOR_POS)
			{
				// 0, 1 (Header, Command)
				byte byte_00 = 0x0ff & r_data[2];
				byte byte_01 = 0x0ff & r_data[3];
				byte byte_02 = 0x0ff & r_data[4];
				byte byte_03 = 0x0ff & r_data[5];
				byte byte_04 = 0x0ff & r_data[6];
				byte byte_05 = 0x0ff & r_data[7];

				//
				CString str__pos_load;
				CString str__pos_tune;
				int val__pos_load = 0;
				int val__pos_tune = 0;

				val__pos_load  = 0x0ff & byte_03;
				val__pos_load  = val__pos_load << 8;
				val__pos_load += 0x0ff & byte_02;
				str__pos_load.Format("%.2f", (double) val__pos_load / 100.0);

				val__pos_tune  = 0x0ff & byte_05;
				val__pos_tune  = val__pos_tune << 8;
				val__pos_tune += 0x0ff & byte_04;
				str__pos_tune.Format("%.2f", (double) val__pos_tune / 100.0);

			    if(para_id == 1)
				{
					sCH__INFO_LOAD_POS_CH1->Set__DATA(str__pos_load);
					aCH__INFO_LOAD_POS_CH1->Set__VALUE((double) val__pos_load / 100.0);
					sCH__INFO_TUNE_POS_CH1->Set__DATA(str__pos_tune);
					aCH__INFO_TUNE_POS_CH1->Set__VALUE((double) val__pos_tune / 100.0);
				}
				else if(para_id == 2)
				{
					sCH__INFO_LOAD_POS_CH2->Set__DATA(str__pos_load);
					sCH__INFO_TUNE_POS_CH2->Set__DATA(str__pos_tune);
				}

				//
				read_data.Format("%02X%02X %02X%02X %02X%02X", byte_00,byte_01, byte_02,byte_03, byte_04,byte_05);
			}

			else if(cmmd_id == _DRV_CMMD__REPORT_AUXILIARY_CAPACITOR_PARAM)
			{
				byte byte_00 = 0x0ff & r_data[2];
				byte byte_01 = 0x0ff & r_data[3];
				byte byte_02 = 0x0ff & r_data[4];

				CString str__aux_cap;
				int val__cap_pose = 0;

				val__cap_pose  = 0x0ff & byte_02;
				val__cap_pose  = val__cap_pose << 8;
				val__cap_pose += 0x0ff & byte_01;
				str__aux_cap.Format("%.2f", (double) val__cap_pose / 100.0);
				sCH__INFO_CAP_POS_CH->Set__DATA(str__aux_cap);
				aCH__INFO_CAP_POS_CH->Set__VALUE((double) val__cap_pose / 100.0);
				read_data.Format("%02X, AUX_CAP_POSTION:%02X%02X", byte_00, byte_01, byte_02);
			}
		}
		else
		{
			read_data = "ERROR";
		}
		return 1;

	}
	#pragma endregion

	#pragma region Report_Measure_paramte_248

	if((siCH__REPORT_INPUT_SNS_DATA->Check__VARIABLE_NAME(var_name) >0)
	|| (siCH__REPORT_OUTPUT_SNS1_DATA->Check__VARIABLE_NAME(var_name) > 0)
	|| (siCH__REPORT_OUTPUT_SNS2_DATA->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = _DRV_CMMD__REPORT_MEASURED_PARAMTER;
		byte s_data_len = 0;
		byte r_data_len = 0;
		byte para01		= 0;
		byte sub_cmmd = 0;
		#pragma region Send_data
		if((siCH__REPORT_INPUT_SNS_DATA->Check__VARIABLE_NAME(var_name) > 0)
		|| (siCH__REPORT_OUTPUT_SNS1_DATA->Check__VARIABLE_NAME(var_name) > 0)
		|| (siCH__REPORT_OUTPUT_SNS2_DATA->Check__VARIABLE_NAME(var_name) > 0))
		{
			s_data_len = 4;
			r_data_len = 28;
			sub_cmmd = 201;

			if(siCH__REPORT_INPUT_SNS_DATA->Check__VARIABLE_NAME(var_name) > 0) para01 = 1;
			else if(siCH__REPORT_OUTPUT_SNS1_DATA->Check__VARIABLE_NAME(var_name) > 0) para01 = 7;
			else if(siCH__REPORT_OUTPUT_SNS2_DATA->Check__VARIABLE_NAME(var_name) > 0) para01 = 8;

			s_data[0] = 0x0ff & sub_cmmd;
			s_data[1] = 0x00;
			s_data[2] = 0x0ff & para01;
			s_data[3] = 0x00;
		}

		#pragma endregion
		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);	
		
		#pragma region RECV_DATA
		if(r_len >= r_data_len)
		{
			unsigned int return_data;
			CString sData;
			CString Log_buff = "";
			byte buffer_arry[28] = {0,};
			int buffer_len = sizeof(buffer_arry)/sizeof(buffer_arry[0]);
			int header_offset = (r_data_len>=7) ? 3:2;
			for(int i =0; i<buffer_len;i++)
			{
				buffer_arry[i] = 0x0ff & r_data[header_offset+i]; // Header, Command, Length
			}

			if(sub_cmmd == 201) //Report_Sensor_Input_OutPut
			{
				int start_byte = 0, end_byte = 0;
				//Input Sensor
				if(para01 == 1)
				{
					return_data = _Convert_ToInt(4,7,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_GAMMA_IN_SNS->Set__DATA(sData); // Gamma = Root(sData/1024)
					aCH__INFO_GAMMA_IN_SNS->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(12,15,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_REAL_IN_SNS->Set__DATA(sData); // (data*59)/1024
					aCH__INFO_REAL_IN_SNS->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(16,19,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_IMAGE_IN_SNS->Set__DATA(sData); // (data*59)/1024
					aCH__INFO_IMAGE_IN_SNS->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(20,23,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_VOLTAGE_IN_SNS->Set__DATA(sData);
					aCH__INFO_VOLTAGE_IN_SNS->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(24,27,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_CURRENT_IN_SNS->Set__DATA(sData);
					aCH__INFO_CURRENT_IN_SNS->Set__VALUE((double) return_data);

					read_data = "OK";
					return 1;
				}

				//Output Sensor1
				else if(para01 == 7)
				{
					return_data = _Convert_ToInt(4,7,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_PHASE_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_PHASE_OUT_SNS1->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(8,11,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_DELIVERY_POWER_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_DELIVERY_POWER_OUT_SNS1->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(12,15,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_REAL_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_REAL_OUT_SNS1->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(16,19,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_IMAGE_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_IMAGE_OUT_SNS1->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(20,23,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_VOLTAGE_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_VOLTAGE_OUT_SNS1->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(24,27,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_CURRENT_OUT_SNS1->Set__DATA(sData);
					aCH__INFO_CURRENT_OUT_SNS1->Set__VALUE((double) return_data);

					{	//DRV_LOG 작업 할 것
						
						read_data = "OK";
						return 1;
					}
					
				}
				//Output Sensor2
				else if(para01 == 8)
				{
					return_data = _Convert_ToInt(4,7,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_PHASE_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_PHASE_OUT_SNS2->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(8,11,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_DELIVERY_POWER_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_DELIVERY_POWER_OUT_SNS2->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(12,15,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_REAL_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_REAL_OUT_SNS2->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(16,19,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_IMAGE_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_IMAGE_OUT_SNS2->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(20,23,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_VOLTAGE_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_VOLTAGE_OUT_SNS2->Set__VALUE((double) return_data);

					return_data = _Convert_ToInt(24,27,buffer_arry);
					sData.Format("%.2f", (double) return_data / 100.0);
					sCH__INFO_CURRENT_OUT_SNS2->Set__DATA(sData);
					aCH__INFO_CURRENT_OUT_SNS2->Set__VALUE((double) return_data);

					read_data = "OK";
					return 1;
				}
			}

			else
			{
				read_data = "ERROR";
				return -1;
			}
			
		}
		else
		{
			read_data = "ERROR";
			return -1;
		}
		#pragma endregion
		

	}
	#pragma endregion

	#pragma region Report_Sanshot
	if(siCH__REPORT_CONDENSED_MATCH_SNAPSHOT -> Check__VARIABLE_NAME(var_name) > 0 )
	{
		int cmmd_id = _DRV_CMMD__REPORT_CONDENSED_MATCH_SNAPSHOT;
		int s_data_len = 0;
		int r_data_len = 88;
		// ..
		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);	
		
		
		if(r_len >= r_data_len)
		{
			unsigned int return_data;
			CString sData;
			byte buffer_arry[88] = {0,};
			int buffer_len = sizeof(buffer_arry)/sizeof(buffer_arry[0]); 
			for(int i =0; i<buffer_len;i++)
			{
				buffer_arry[i] = 0x0ff & r_data[3+i]; // Header, Command, Length
			}
			
			//status bytes...
			((buffer_arry[0] & 0x01) == 1) ? dCH__INFO_OUTPUT_ON->Set__DATA(STR__ON):dCH__INFO_OUTPUT_ON->Set__DATA(STR__OFF);
			((buffer_arry[0] & 0x02) == 1) ? dCH__INFO_OUTPUT_TUNED->Set__DATA(STR__ON):dCH__INFO_OUTPUT_TUNED->Set__DATA(STR__OFF);

			((buffer_arry[1] & 0x01) == 1) ? dCH__INFO_LOW_24V_SUPPLY->Set__DATA(STR__ON):dCH__INFO_LOW_24V_SUPPLY->Set__DATA(STR__OFF);
			((buffer_arry[1] & 0x02) == 1) ? dCH__INFO_OVERTEMP->Set__DATA(STR__ON):dCH__INFO_OVERTEMP->Set__DATA(STR__OFF);
			((buffer_arry[1] & 0x04) == 1) ? dCH__INFO_INTERLOCK_OPEN->Set__DATA(STR__ON):dCH__INFO_INTERLOCK_OPEN->Set__DATA(STR__OFF);
			((buffer_arry[1] & 0x08) == 1) ? dCH__INFO_FAN_FAULT->Set__DATA(STR__ON):dCH__INFO_FAN_FAULT->Set__DATA(STR__OFF);

			((buffer_arry[2] & 0x01) == 1) ? dCH__INFO_AUX_CAP_TUNED->Set__DATA(STR__ON):dCH__INFO_AUX_CAP_TUNED->Set__DATA(STR__OFF);

			((buffer_arry[3] & 0x01) == 1) ? dCH__INFO_LATCH_FAULT_EXIST->Set__DATA(STR__ON):dCH__INFO_LATCH_FAULT_EXIST->Set__DATA(STR__OFF);
			((buffer_arry[3] & 0x02) == 1) ? dCH__INFO_WARNING_EXIST->Set__DATA(STR__ON):dCH__INFO_WARNING_EXIST->Set__DATA(STR__OFF);
			((buffer_arry[3] & 0x04) == 1) ? dCH__INFO_MOTOR_FAIL_INIT->Set__DATA(STR__ON):dCH__INFO_MOTOR_FAIL_INIT->Set__DATA(STR__OFF);
			((buffer_arry[3] & 0x20) == 1) ? dCH__INFO_VOLTAGE_OVER_LIMIT->Set__DATA(STR__ON):dCH__INFO_VOLTAGE_OVER_LIMIT->Set__DATA(STR__OFF);
			
			//Match1 Load
			return_data = _Convert_ToInt(4,5,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_LOAD_POS_CH1->Set__DATA(sData);
			//Matcj1 Tune
			return_data = _Convert_ToInt(6,7,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_TUNE_POS_CH1->Set__DATA(sData);
			//Match1 R
			return_data = _Convert_ToInt(8,9,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_REAL_IN_SNS->Set__DATA(sData);
			//Match1 X
			return_data = _Convert_ToInt(10,11,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_IMAGE_IN_SNS->Set__DATA(sData);

			
			//...
			//Aux CAP Position
			return_data = _Convert_ToInt(28,29,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CAP_POS_CH->Set__DATA(sData);
			
			//Aux CAP Current (Primary_Sensor) 
			return_data = _Convert_ToInt(30,31,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CAP_CURRENT_CH1->Set__DATA(sData);

			//Aux CAP Current (Second_Sensor), For Source
			return_data = _Convert_ToInt(32,33,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CAP_CURRENT_CH2->Set__DATA(sData);

			//Aux CAP Voltage
			return_data = _Convert_ToInt(36,37,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CAP_VOLTAGE_CH1 ->Set__DATA(sData);

			//Aux CAP Voltage (Second_Sensor), For Source
			return_data = _Convert_ToInt(36,37,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CAP_VOLTAGE_CH2 ->Set__DATA(sData);
			
			//...
			//Frequency1 R
			return_data = _Convert_ToInt(40,43,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_REAL_OUT_SNS1->Set__DATA(sData);

			//Frequency1 X
			return_data = _Convert_ToInt(44,47,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_IMAGE_OUT_SNS1->Set__DATA(sData);

			//Frequency1 Voltage
			return_data = _Convert_ToInt(48,51,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_VOLTAGE_OUT_SNS1 ->Set__DATA(sData);
			//Frequency1 Current
			return_data = _Convert_ToInt(52,55,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_CURRENT_OUT_SNS1 ->Set__DATA(sData);
			//Frequency1 Phase
			return_data = _Convert_ToInt(56,59,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_PHASE_OUT_SNS1 ->Set__DATA(sData);
			//Frequency1 Power Delivery
			return_data = _Convert_ToInt(60,63,buffer_arry);
			sData.Format("%.2f", (double) return_data / 100.0);
			sCH__INFO_DELIVERY_POWER_OUT_SNS1 -> Set__DATA(sData);
			//... Sensor2가 Fequencey 2로 Out되는지 확인 필요한 구간
			
			//Frequency2 R
			if(dCH__PARA_SEL_CH ->Check__DATA(STR__SOURCE))
			{
				return_data = _Convert_ToInt(64,67,buffer_arry);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_REAL_OUT_SNS2 ->Set__DATA(sData);
				//Frequency2 X
				return_data = _Convert_ToInt(68,71,buffer_arry);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_IMAGE_OUT_SNS2 ->Set__DATA(sData);
				//Frequency2 Voltage
				return_data = _Convert_ToInt(72,75,buffer_arry);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_VOLTAGE_OUT_SNS2 ->Set__DATA(sData);
				//Frequency2 Current
				return_data = _Convert_ToInt(76,79,r_data);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_CURRENT_OUT_SNS2 ->Set__DATA(sData);
				//Frequency2 Phase
				return_data = _Convert_ToInt(80,83,buffer_arry);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_PHASE_OUT_SNS2 ->Set__DATA(sData);
				//Frequency2 Power Delivery
				return_data = _Convert_ToInt(84,87,buffer_arry);
				sData.Format("%.2f", (double) return_data / 100.0);
				sCH__INFO_DELIVERY_POWER_OUT_SNS2 -> Set__DATA(sData);
			}
			
			read_data = "OK";
			return 1;

		}
		else
		{
			read_data = "ERROR";
			return -1;
		}
		
	}
	#pragma endregion

	return -1;
}

//------------------------------------------------------------------------------------
int CObj__NAVII_SERIAL
::__Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data)
{

	return -1;
}

int CObj__NAVII_SERIAL
::__Write__DIGITAL(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index)
{
	unsigned char r_data[MAX_CHAR] = {0,};
	unsigned char s_data[MAX_CHAR] = {0,};
	CString ch_data;

	byte addr_id = (byte) aCH__CFG_PART_ADDRES_ID->Get__VALUE();

	
	if(doCH__ALL_CAPACITOR_INIT->Check__VARIABLE_NAME(var_name) > 0)
	{
		byte cmmd_id = _DRV_CMMD__SET_ALL_CAPACITOR_INIT; //125
		byte s_data_len = 0;
		byte r_data_len = 1;

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
		}
		return -1;
	}

	if((doCH__CAPACITOR_LIMIT_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__CAPACITOR_LIMIT_CH2->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = _DRV_CMMD__SET_CAPACITOR_LIMIT; // NU
		byte s_data_len = 10;
		byte r_data_len = 1;

		int para_id  = 0;
		int para_load_min = 0;
		int para_load_max = 0;
		int para_tune_min = 0;
		int para_tune_max = 0;

		if(doCH__CAPACITOR_LIMIT_CH1->Check__VARIABLE_NAME(var_name) > 0)
		{
			para_id = 1;
			para_load_min = (int) aCH__CFG_LOAD_MIN_CH1->Get__VALUE();
			para_load_max = (int) aCH__CFG_LOAD_MAX_CH1->Get__VALUE();
			para_tune_min = (int) aCH__CFG_TUNE_MIN_CH1->Get__VALUE();
			para_tune_max = (int) aCH__CFG_TUNE_MAX_CH1->Get__VALUE();
		}
		else if(doCH__CAPACITOR_LIMIT_CH2->Check__VARIABLE_NAME(var_name) > 0)
		{
			para_id = 2;
			para_load_min = (int) aCH__CFG_LOAD_MIN_CH2->Get__VALUE();
			para_load_max = (int) aCH__CFG_LOAD_MAX_CH2->Get__VALUE();
			para_tune_min = (int) aCH__CFG_TUNE_MIN_CH2->Get__VALUE();
			para_tune_max = (int) aCH__CFG_TUNE_MAX_CH2->Get__VALUE();
		}
		else
		{
			return -1;
		}

		s_data[0] = 0x0ff & para_id;
		s_data[1] = 0x00;
		
		s_data[2] = 0x0ff & para_load_min;
		s_data[3] = 0x0ff & (para_load_min >> 8);
		s_data[4] = 0x0ff & para_load_max;
		s_data[5] = 0x0ff & (para_load_max >> 8);

		s_data[6] = 0x0ff & para_tune_min;
		s_data[7] = 0x0ff & (para_tune_min >> 8);
		s_data[8] = 0x0ff & para_tune_max;
		s_data[9] = 0x0ff & (para_tune_max >> 8);

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
		}
		return -1;
	}

	if((doCH__CONTROL_MODE_CH1->Check__VARIABLE_NAME(var_name)  > 0)
	|| (doCH__CONTROL_MODE_CH2->Check__VARIABLE_NAME(var_name)  > 0)
	|| (doCH__ACTIVE_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__ACTIVE_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__INTERNAL_EXTERNAL_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__INTERNAL_EXTERNAL_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = 0;
		byte s_data_len = 4;
		byte r_data_len = 1;

		int para_id  = 0;
		int para_set = 0;

		if((doCH__CONTROL_MODE_CH1->Check__VARIABLE_NAME(var_name) > 0)
		|| (doCH__CONTROL_MODE_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__SET_CONTROL_MODE; //93

				 if(doCH__CONTROL_MODE_CH1->Check__VARIABLE_NAME(var_name) > 0)			para_id = 1;
			else if(doCH__CONTROL_MODE_CH2->Check__VARIABLE_NAME(var_name) > 0)			para_id = 2;

				 if(set_data.CompareNoCase(STR__USER) == 0)			para_set = 0; // Manual MOde Can Control User Mode(Can't Set)
			else if(set_data.CompareNoCase(STR__AUTO) == 0)			para_set = 1;	
			else if(set_data.CompareNoCase(STR__HOST) == 0)			para_set = 2;	
			else													return -11;
		}
		else if((doCH__ACTIVE_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)
			 || (doCH__ACTIVE_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__SET_ACTIVE_PRESET;  // NU

			if(doCH__ACTIVE_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)
			{
				para_id = 1;
				para_set = (int) aCH__PARA_ACTIVE_PRESET_CH1->Get__VALUE();
			}
			else if(doCH__ACTIVE_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0)
			{
				para_id = 2;
				para_set = (int) aCH__PARA_ACTIVE_PRESET_CH2->Get__VALUE();			
			}
		}
		else if((doCH__INTERNAL_EXTERNAL_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)
			 || (doCH__INTERNAL_EXTERNAL_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__SET_INTERNAL_EXTERNAL_PRESET; // NU

				 if(doCH__INTERNAL_EXTERNAL_PRESET_CH1->Check__VARIABLE_NAME(var_name) > 0)			para_id = 1;
			else if(doCH__INTERNAL_EXTERNAL_PRESET_CH2->Check__VARIABLE_NAME(var_name) > 0)			para_id = 2;

				 if(set_data.CompareNoCase(STR__INTERNAL) == 0)			para_set = 0;
			else if(set_data.CompareNoCase(STR__EXTERNAL) == 0)			para_set = 1;	
			else														return -11;
		}
		else
		{
			return -1;
		}

		s_data[0] = 0x0ff & para_id;
		s_data[1] = 0x00;
		s_data[2] = 0x0ff & para_set;
		s_data[3] = 0x0ff & (para_set >> 8);

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
		}
		return -1;
	}

	if((doCH__LOAD_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__LOAD_POS_CH2->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__TUNE_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__TUNE_POS_CH2->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = 0;
		byte s_data_len = 4;
		byte r_data_len = 1; // CSR ONLY

		int para_id = 0;
		int para_pos = 0;

		if((doCH__LOAD_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
		|| (doCH__LOAD_POS_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__SET_LOAD_POS;

			if(doCH__LOAD_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)		
			{
				para_id = 1;
				para_pos = (int) (100.0 * aCH__PARA_LOAD_POS_CH1->Get__VALUE());

				ch_data.Format("%1d", para_pos);
				sCH__CUR_LOAD_POS_CH1->Set__DATA(ch_data);
			}
			else if(doCH__LOAD_POS_CH2->Check__VARIABLE_NAME(var_name) > 0)
			{
				para_id = 2;
				para_pos = (int) (100.0 * aCH__PARA_LOAD_POS_CH2->Get__VALUE());

				ch_data.Format("%1d", para_pos);
				sCH__CUR_LOAD_POS_CH2->Set__DATA(ch_data);
			}

		}
		else if((doCH__TUNE_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
			 || (doCH__TUNE_POS_CH2->Check__VARIABLE_NAME(var_name) > 0))
		{
			cmmd_id = _DRV_CMMD__SET_TUNE_POS;

			if(doCH__TUNE_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)		
			{
				para_id = 1;
				para_pos = (int) (100.0 * aCH__PARA_TUNE_POS_CH1->Get__VALUE());

				ch_data.Format("%1d", para_pos);
				sCH__CUR_TUNE_POS_CH1->Set__DATA(ch_data);
			}
			else if(doCH__TUNE_POS_CH2->Check__VARIABLE_NAME(var_name) > 0)
			{
				para_id = 2;
				para_pos = (int) (100.0 * aCH__PARA_TUNE_POS_CH2->Get__VALUE());

				ch_data.Format("%1d", para_pos);
				sCH__CUR_TUNE_POS_CH2->Set__DATA(ch_data);
			}
		}
		else
		{
			return -1;
		}

		s_data[0] = 0x0ff & para_id; // 4 & 5bit Matcher Selection
		s_data[1] = 0x000 ;
		s_data[2] = 0x0ff & para_pos;
		s_data[3] = 0x0ff & (para_pos >> 8);

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
			return 1;
		}
		return -1;
	}

	if((doCH__CAPACITOR_MOTOR_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
	|| (doCH__CAPACITOR_MOTOR_POS_CH2->Check__VARIABLE_NAME(var_name) > 0))
	{
		byte cmmd_id = _DRV_CMMD__SET_CAPACITOR_MOTOR_POS;
		byte s_data_len = 6;
		byte r_data_len = 1;

		int para_id = 0;
		int para_load_pos = 0;
		int para_tune_pos = 0;

		if(doCH__CAPACITOR_MOTOR_POS_CH1->Check__VARIABLE_NAME(var_name) > 0)
		{
			para_id = 1;
			para_load_pos = (int) (100.0 * aCH__PARA_LOAD_POS_CH1->Get__VALUE());
			para_tune_pos = (int) (100.0 * aCH__PARA_TUNE_POS_CH1->Get__VALUE());

			ch_data.Format("%1d", para_load_pos);
			sCH__CUR_LOAD_POS_CH1->Set__DATA(ch_data);

			ch_data.Format("%1d", para_tune_pos);
			sCH__CUR_TUNE_POS_CH1->Set__DATA(ch_data);
		}
		else if(doCH__CAPACITOR_MOTOR_POS_CH2->Check__VARIABLE_NAME(var_name) > 0)
		{
			para_id = 2;
			para_load_pos = (int) (100.0 * aCH__PARA_LOAD_POS_CH2->Get__VALUE());
			para_tune_pos = (int) (100.0 * aCH__PARA_TUNE_POS_CH2->Get__VALUE());

			ch_data.Format("%1d", para_load_pos);
			sCH__CUR_LOAD_POS_CH2->Set__DATA(ch_data);

			ch_data.Format("%1d", para_tune_pos);
			sCH__CUR_TUNE_POS_CH2->Set__DATA(ch_data);
		}
		else
		{
			return -1;
		}

		s_data[0] = 0x0ff & para_id;
		s_data[1] = 0x00;
		s_data[2] = 0x0ff & para_load_pos;
		s_data[3] = 0x0ff & (para_load_pos >> 8);
		s_data[4] = 0x0ff & para_tune_pos;
		s_data[5] = 0x0ff & (para_tune_pos >> 8);

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
		}
		return -1;
	}
	
	if(doCH__AUXILIARY_CAP_POS -> Check__VARIABLE_NAME(var_name) > 0)
	{
		byte cmmd_id = _DRV_CMMD__SET_AUXILIARY_CAP;
		byte s_data_len = 3; // 1 , 2 Addtion
		byte r_data_len = 1;
		int para_cap_pos = 0;

		para_cap_pos = (int) (100.0 * aCH__PARA_CAP_POS_CH->Get__VALUE());
		ch_data.Format("%1d", para_cap_pos);
		sCH__CUR_CAP_POS_CH->Set__DATA(ch_data);
				
		s_data[0] = 0x00; // Aux Cap Paramter Selection ( Move Aux - 2 Addtiona; Bytes)
		s_data[1] = 0x0ff & para_cap_pos;
		s_data[2] = 0x0ff & (para_cap_pos >> 8);

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);		
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
			return -2;
		}
	}
	
	if(doCH__CLEAR_LATCH_FAULTS -> Check__VARIABLE_NAME(var_name) > 0)
	{
		byte cmmd_id = _DRV_CMMD__SET_CLAER_LATCHED_FAULTS; // 119
		byte s_data_len = 0; // 2_Additional_Data
		byte r_data_len = 1; // CSR ONLY

		int r_len = _Recv__Command(var_name, addr_id,cmmd_id,s_data_len,r_data_len, s_data,r_data);
		if(r_len >= r_data_len)
		{
			byte byte_00 = 0x0ff & r_data[0];
			if(byte_00 == 0)			return 1;

			ch_data.Format("%02X", byte_00);
			sCH__INFO_CSR_HEXA->Set__DATA(ch_data);

			ch_data = _Get__CSR_CODE(byte_00);
			sCH__INFO_CSR_MSG->Set__DATA(ch_data);
			return -2;
		}
	}

	return -1;
}

int CObj__NAVII_SERIAL
::__Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data)
{
	return -1;
}
