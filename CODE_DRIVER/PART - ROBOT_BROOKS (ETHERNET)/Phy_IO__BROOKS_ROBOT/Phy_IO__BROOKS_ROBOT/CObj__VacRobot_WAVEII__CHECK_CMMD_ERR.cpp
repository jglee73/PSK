#include "StdAfx.h"
#include "CObj__VacRobot_WAVEII.h"
#include "CObj__VacRobot_WAVEII__DEF.h"
#include "CObj__VacRobot_WAVEII__ALID.h"


//------------------------------------------------------------------------------------
int  CObj__VacRobot_WAVEII
::Call__CHECK_CMMD(CII_OBJECT__VARIABLE* p_variable,
				   CII_OBJECT__ALARM* p_alarm)
{
	printf("Call__CHECK_CMMD() : Started ... \n");

	CString str_cmmd = sCH__PARA_CHECK_CMMD->Get__STRING();
	int r_res = soCH__CHECK_CMMD->Set__DATA(str_cmmd);

	printf("Call__CHECK_CMMD() : End(%1d) ... \n", r_res);
	return 1;
}
int  CObj__VacRobot_WAVEII
::Call__CHECK_ERR_CODE(CII_OBJECT__VARIABLE* p_variable,
				       CII_OBJECT__ALARM* p_alarm)
{
	printf("Call__CHECK_ERR_CODE() : Started ... \n");

	CString ch_data = sCH__PARA_CHECK_ERR_CODE->Get__STRING();
	int i_err_code  = atoi(ch_data);
	
	CString err_msg = Get__Error_Msg_Of_Error_Code(i_err_code);

	printf(" * err_code [%1d] \n", i_err_code);
	printf(" * err_msg ... \n");
	printf("_______________________________________________\n");
	printf(err_msg);
	printf("_______________________________________________\n");

	printf("Call__CHECK_ERR_CODE() : End ... \n");
	return 1;
}
