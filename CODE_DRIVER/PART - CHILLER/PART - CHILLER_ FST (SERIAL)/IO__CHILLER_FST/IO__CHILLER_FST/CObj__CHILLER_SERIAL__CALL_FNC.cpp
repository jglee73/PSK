#include "StdAfx.h"
#include "CObj__CHILLER_SERIAL.h"


// ..
int CObj__CHILLER_SERIAL
::Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		ch_data = aCH__CFG_INIT_TEMPERATURE_X[i]->Get__STRING();
		aCH__PARA_SET_TEMPERATURE_X[i]->Set__DATA(ch_data);

		ch_data = dCH__CFG_INIT_CONTROL_X[i]->Get__STRING();
		dCH__PARA_SET_CONTROL_X[i]->Set__DATA(ch_data);

		ch_data = dCH__CFG_INIT_CONNECT_X[i]->Get__STRING();
		dCH__PARA_SET_CONNECT_X[i]->Set__DATA(ch_data);

		//
		doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
	}
	return 1;
}

int CObj__CHILLER_SERIAL
::Call__LOCAL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		ch_data = STR__LOCAL;
		dCH__PARA_SET_CONNECT_X[i]->Set__DATA(ch_data);

		//
		doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
	}
	return 1;
}
int CObj__CHILLER_SERIAL
::Call__REMOTE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		ch_data = STR__REMOTE;
		dCH__PARA_SET_CONNECT_X[i]->Set__DATA(ch_data);

		//
		doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
	}
	return 1;
}

int CObj__CHILLER_SERIAL
::Call__RUN(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		ch_data = STR__RUN;
		dCH__PARA_SET_CONTROL_X[i]->Set__DATA(ch_data);

		//
		doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
	}
	return 1;
}
int CObj__CHILLER_SERIAL
::Call__STOP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm)
{
	CString ch_data;
	int i;

	for(i=0; i<_CFG__CH_SIZE; i++)
	{
		ch_data = STR__STOP;
		dCH__PARA_SET_CONTROL_X[i]->Set__DATA(ch_data);

		//
		doCH__CHANNEL_SET_X[i]->Set__DATA(_Cmmd_IO__Set);
	}
	return 1;
}
