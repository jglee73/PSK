#pragma once

#include "Interface_Code.h"

#include "CObj__PM_METAL__DEF.h"


union  JG_F4
{
	unsigned char uData[4];
	float fValue;
};

union  JG_UI2
{
	unsigned char  uData[2];
	unsigned short uiValue;
};


class CObj__PM_METAL : public __IOBJ__IO_TYPE
{
private:
	//-------------------------------------------------------------------------
	CString	sObject_Name;

	// ...
	SCX__SERIAL_JG mX_Serial;

	int iActive__SIM_MODE;
	//


	//-------------------------------------------------------------------------
	SCX__USER_LOG_CTRL xI__APP_LOG_CTRL;
	SCX__USER_LOG_CTRL xI__DRV_LOG_CTRL;

	bool bActive__COMM_ONLINE;
	int  iPara__Addr_ID;
	//

	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_MSG;

	// DRV_INFO ...
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_COM_PORT;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_PROTOCOL;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_MODBUS_ADDR;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_BAUD_RATE;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_COMM_PARITY;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_DATA_BIT;
	CX__VAR_STRING_CTRL  sCH__DRV_INFO_STOP_BIT;

	// NFO.BOTTLE.STATE ...
	CX__VAR_STRING_CTRL  sCH__INFO_BOTTLE_STATE_X[_CFG_SIZE__BOTTLE];
	CX__VAR_STRING_CTRL  sCH__INFO_BOTTLE_MSG_X[_CFG_SIZE__BOTTLE];

	// NFO.BOTTLE.VALVE ...
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV1_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV2_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV3_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV4_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV5_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_VS_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV6_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV7_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV8_X[_CFG_SIZE__BOTTLE];
	CX__VAR_DIGITAL_CTRL dCH__INFO_BOTTLE_AV9_X[_CFG_SIZE__BOTTLE];

	// NFO.ALARM.ACTIVE ...
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_PURGE;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_HEAVY;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_LIGHT;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_EMERGENCY_STOP;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_LEAK;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_FIRE;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_HIGH_TEMPERATURE;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_PT1_LOW_1;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_PT1_LOW_2;
	CX__VAR_DIGITAL_CTRL dCH__INFO_ALARM_ACTIVE_CDA_LOW;

	// ...
	CX__VAR_STRING_CTRL  sCH__INFO_BOTTLE_WEIGHT_PER;

	CX__VAR_STRING_CTRL  sCH__INFO_PT1_PSI;
	CX__VAR_STRING_CTRL  sCH__INFO_PT2_PSI;
	CX__VAR_STRING_CTRL  sCH__INFO_PT3_PSI;
	//

	// IO CHANNEL  -----------------------------------
	CX__VAR_STRING_CTRL  siCH__D2000_BOTTLE_CONDITION;
	CX__VAR_STRING_CTRL  siCH__D2005_BOTTLE_WEIGHT_PER;
	CX__VAR_STRING_CTRL  siCH__D2007_BOTTLE_PT1;
	CX__VAR_STRING_CTRL  siCH__D2008_BOTTLE_PT2;
	CX__VAR_STRING_CTRL  siCH__D2009_BOTTLE_PT3;
	CX__VAR_STRING_CTRL  siCH__D2020_BOTTLE_VALVE;
	CX__VAR_STRING_CTRL  siCH__D2029_ALARM_STATE;
	//


	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	unsigned int _Make__READ_PACKET(unsigned char* s_data, 
		                            const unsigned char addr_id,
	                                const unsigned char cmmd_id,
							        const unsigned int  start_addr,
									const unsigned char read_num);
	unsigned int _Recv__READ_PACKET(unsigned char* s_data, 
								    const int s_len);

	unsigned int _Make__WRITE_PACKET(unsigned char* s_data, 
									const unsigned char addr_id,
									const unsigned char cmmd_id,
									const unsigned int  start_addr,
									const unsigned char write_num,
									const unsigned short set_data,
									const float set_value);

	unsigned short _Get__CRC16(unsigned char* s_data, const int data_len);

	// ...
	void Mon__MONITOR(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	void _Update__BOTTLE_STATE(const unsigned int i_data);
	void _Update__BOTTLE_VALVE(const unsigned int i_data);
	void _Update__ALARM_ACTIVE(const unsigned int i_data);
	//


public:
	CObj__PM_METAL();
	~CObj__PM_METAL();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj, l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__VARIABLE_IO(p_io_variable);

	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	int __INITIALIZE__IO(p_io_para);

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm);
	int __CALL__MONITORING(id, p_variable, p_alarm);

	//-------------------------------------------------------------------------
	int __Read__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, double& read_data);
	int __Read__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, CString& read_data,int& item_index);
	int __Read__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, CString& read_data);

	int __Write__ANALOG(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const double set_data);
	int __Write__DIGITAL(const CString& var_name,const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data,const int item_index);
	int __Write__STRING(const CString& var_name, const CDS_IO__CHANNEL_INFO& io_info, const CString& set_data);
};

