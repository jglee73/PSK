#pragma once

#include "Interface_Code.h"
#include "CCommon_Error.h"
#include "CCommon_System.h"


class CObj_Phy__LPx_STD : public __IOBJ__STD_TYPE
{
private:
	//---------------------------------------------------------
	CString sObject_Name;
	int iPTN;

	CCommon_Error__DEF_VARIABLE mERROR__DEF_VAR;
	CCommon_Error__MODULE_OBJ   mERROR__MODULE_OBJ;

	//---------------------------------------------------------
	SCX__CTC__MODULE_OBJ xI_Module_Obj;
	SCX__CTC__SCH_MATERIAL_CTRL xI_SCH_MATERIAL_CTRL;

	SCX__LOT_LOG_CTRL xLOT_LOG_CTRL;
	SCX__USER_LOG_CTRL xLOG_CTRL;

	//---------------------------------------------------------
	//  INTERNAL PROPERTY

	int iSEQ__LOCK_FLAG;
	int iCALL_FLAG__FNC_UNLOAD;

	//  CONTROL
	CX__VAR_DIGITAL_CTRL xCH__OBJ_CTRL;
	CString dVAR__MODE;

	//  STATUS 
	CX__VAR_DIGITAL_CTRL xCH__VIRTUAL_OBJ_STATUS;
	CX__VAR_DIGITAL_CTRL xCH__OBJ_STATUS;
	CX__VAR_STRING_CTRL  xCH__SEQ_INFO_MSG;
	CX__VAR_DIGITAL_CTRL dCH__ACTIVE_FOUP_RELOAD;

	CII__VAR_DIGITAL_CTRL *dCH_CFG__LPx_USE;
	CX__VAR_DIGITAL_CTRL  dCH__CFG_PROCESS_TYPE;
	CX__VAR_DIGITAL_CTRL  dCH__CFG_SLOT_MAX;

	CII__VAR_DIGITAL_CTRL *dCH_CFG__LPx_TYPE;
	CII__VAR_DIGITAL_CTRL *dCH_CFG__LPx_MATERIAL_SIZE;	
	CII__VAR_STRING_CTRL  *sCH__LPx_PICK_COUNT;
	CII__VAR_STRING_CTRL  *sCH__LPx_LAMP_STATUS;
	CX__VAR_STRING_CTRL   xCH__LPx_JOB_STATUS_FLAG;

	CX__VAR_STRING_CTRL   xCH__LPx_END_REQ_FLAG;
	CX__VAR_STRING_CTRL   xCH__LPx_RETURN_REQ_FLAG;

	CII__VAR_DIGITAL_CTRL *dCH__CST_STATUS;
	CII__VAR_DIGITAL_CTRL *dCH__SHUTL_STS;
	CII__VAR_DIGITAL_CTRL *dCH__CLAMP_STS;

	CII__VAR_STRING_CTRL  *sCH__CID_STRING;
	CII__VAR_DIGITAL_CTRL *dCH__DOOR_STS;
	CII__VAR_STRING_CTRL  *sCH__PIO_TRANSFER;
	CII__VAR_STRING_CTRL  *sCH__PIO_ERROR_ACTIVE;

	CX__VAR_DIGITAL_CTRL  xCH__SLOT_STATUS[CFG_LP__SLOT_MAX];

	// START & END BUTTON ...
	CX__VAR_DIGITAL_CTRL  xCH__CFG_START_BUTTON_MODE;
	CX__VAR_STRING_CTRL   xCH__START_BUTTON_FLAG;

	CX__VAR_DIGITAL_CTRL  xCH__CFG_END_BUTTON_MODE;
	CX__VAR_STRING_CTRL   xCH__END_BUTTON_FLAG;

	// REQ ...
	CX__VAR_STRING_CTRL   xCH__LPx_HOQ_REQ;
	CX__VAR_STRING_CTRL   xCH__LPx_HOQ_LOCK;

	CX__VAR_STRING_CTRL   xCH__LPx_LOAD_REQ_BY_USER;

	// APP VARIABLE ...
	CII__VAR_DIGITAL_CTRL *dCH__PORT_CTRL;
	CII__VAR_STRING_CTRL  *sCH__PORT_STATUS;
	CII__VAR_STRING_CTRL  *sCH__RESERVE_ID;
	CII__VAR_STRING_CTRL  *sCH__PORT_EXCEPTION;
	CII__VAR_STRING_CTRL  *sCH__PORT_UNLOAD_REQ_FROM_TMC;

	CX__VAR_STRING_CTRL   xCH__APP_LOCK_FLAG;
	CX__VAR_STRING_CTRL   xCH__VIRTUAL_PORT_STATUS;

	//
	CII__VAR_STRING_CTRL  *sCH__PORT_LOTID;
	CII__VAR_STRING_CTRL  *sCH__PORT_PPID;

	CII__VAR_STRING_CTRL  *sCH__PORT_JOB_POPUP_TYPE;
	CII__VAR_STRING_CTRL  *sCH__PORT_JOB_POPUP_FILE;
	CII__VAR_STRING_CTRL  *sCH__PORT_JOB_NAME;
	CII__VAR_STRING_CTRL  *sCH__PORT_CJOBID;

	CII__VAR_ANALOG_CTRL  *aCH__PORT_CFG_JOB_END_SLOT;

	CX__VAR_ANALOG_CTRL   aCH__LAST_PICK_SLOT;
	CX__VAR_ANALOG_CTRL   aCH__LAST_RESERVE_SLOT;

	//
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_SERVICE_REQ;			 // NO  YES
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_ACCESS_REQ;			 // MANUAL  AUTO
	CX__VAR_STRING_CTRL   xCH__FA_LP_CURRENT_STATUS;		
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_ACCESS_STATUS;
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_BYPASS_READ_ID_FLAG;    // DISABLE  ENABLE
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_MANUAL_LOADING_FLAG;	 // DISABLE  ENABLE
	CX__VAR_STRING_CTRL   xCH__FA_LP_RESERVATION_STATUS;
	CX__VAR_STRING_CTRL   xCH__FA_LP_ASSOCIATION_STATUS;
	CX__VAR_STRING_CTRL   xCH__FA_LP_TRANSFER_STATUS;
	CX__VAR_STRING_CTRL   xCH__FA_CARRIERID_STATUS;
	CX__VAR_STRING_CTRL   xCH__FA_MAP_STATUS;
	CX__VAR_STRING_CTRL   xCH__FA_CARRIER_ACCESS_STATUS;
	CX__VAR_DIGITAL_CTRL  xCH__FA_LP_HOST_VERIFY_FLAG;

	//
	CX__VAR_STRING_CTRL   xCH__RF_PAGE_NUM;
	CX__VAR_STRING_CTRL   xCH__RF_DATA_LEN;
	CX__VAR_STRING_CTRL   xCH__RF_PAGE_DATA;

	//
	CString sWIN_CSTID__NAME;
	CX__VAR_STRING_CTRL   xCH__SCR__WIN_CSTID;

	//
	CX__VAR_STRING_CTRL   xCH__RELOAD_FLAG;
	CX__VAR_STRING_CTRL   xCH__RF_YES_NO_FLAG;
	CX__VAR_STRING_CTRL   xCH__SIDE_BUFFER_USE_FLAG;

	//
	CX__VAR_STRING_CTRL   xCH__DB_LOTID;
	CX__VAR_STRING_CTRL   xCH__DB_ROUTEID;

	CX__VAR_ANALOG_CTRL   xCH__DB_CYCLE_START_SLOT;
	CX__VAR_ANALOG_CTRL   xCH__DB_CYCLE_END_SLOT;
	CX__VAR_ANALOG_CTRL   xCH__DB_CYCLE_COUNT;
	CX__VAR_STRING_CTRL   xCH__CUR_CYCLE_COUNT;
	CX__VAR_STRING_CTRL   xCH__DB_CYCLE_MSG;

	CX__VAR_STRING_CTRL   xCH__MANUAL_CTRL_FLAG;
	CX__VAR_STRING_CTRL   xCH__CYCLE_CTRL_FLAG;

	CX__VAR_STRING_CTRL   xCH__MANUAL_CTRL_RUNNING_FLAG;
	CX__VAR_STRING_CTRL   xCH__CYCLE_CTRL_RUNNING_FLAG;

	//
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_VALID;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_CS_0;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_CS_1;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_TR_REQ;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_BUSY;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_COMPT;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_IN_CONT;

	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_OUT_L_REQ;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_OUT_U_REQ;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_OUT_READY;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_OUT_HO_AVBL;
	CX__VAR_STRING_CTRL   sCH__LINK_AMHS_IO_OUT_ES;

	// SIM CFG ...
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_INIT_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_MAP_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_PREPLOAD_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_CID_READ_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_LOAD_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RLSUNLOAD_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_UNLOAD_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RELOAD_SEC;

	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RF_CID_READ_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RF_PAGE_READ_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RF_CID_WRITE_SEC;
	CX__VAR_ANALOG_CTRL   aCH__SCH_TEST_CFG_RF_PAGE_WRITE_SEC;
	//

	//---------------------------------------------------------
	//  EXTERNAL PROPERTY

	CString sPORT_NAME;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SCH_TEST_CFG_TMC_DUMMY_BY_CTC;

	CX__VAR_STRING_CTRL  xEXT_CH__CFG_LPx_JOB_START_FLAG;
	CX__VAR_DIGITAL_CTRL xEXT_CH__MELODY_BUZZER;
	CX__VAR_DIGITAL_CTRL xEXT_CH__MELODY_CTRL;

	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_LPx_MANUAL_TO_AUTO_ALWAYS_APPLY;
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_LPx_PIO_READY_CHECK_MODE;
	CX__VAR_DIGITAL_CTRL xEXT_CH__CFG_LPx_CID_FORMAT;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SCH_MAP_DEVICE;
	CX__VAR_STRING_CTRL  sEXT_CH__LPx_MAP_REQ;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LPx_ACCESS_MODE_AUTO_CTRL_FLAG;

	int iFLAG__LPx_AUTO_LOAD;
	//

	
	//---------------------------------------------------------
	CString sMODE__INIT;
	int Call__INIT(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__MAP;
	int Call__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__PREPLOAD;
	int Call__PREPLOAD(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__CID_READ;
	int Call__CID_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__LOAD;
	int Call__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__RLSUNLOAD;
	int Call__RLSUNLOAD(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__UNLOAD;
	int Call__UNLOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	CString sMODE__RELOAD;
	int Call__RELOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	//
	CString sMODE__RF_CID_READ;
	int Call__RF_CID_READ(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__RF_PAGE_READ;
	int Call__RF_PAGE_READ(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__RF_CID_WRITE;
	int Call__RF_CID_WRITE(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__RF_PAGE_WRITE;
	int Call__RF_PAGE_WRITE(CII_OBJECT__VARIABLE* p_variable);

	//
	CString sMODE__SCH_MAP;
	int Call__SCH_MAP(CII_OBJECT__VARIABLE* p_variable);

	CString sMODE__CHECK_SLOT;
	int Call__CHECK_SLOT(CII_OBJECT__VARIABLE* p_variable);
	//

	//---------------------------------------------------------
	void Mon__ALL_STATE(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Mon__PORT_CTRL(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void Mon__PORT_EXCEPTION(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	void _Fnc__PORT_EXCEPTION(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	void Mon__FA_REPORT(CII_OBJECT__VARIABLE* p_variable);
	void Mon__FA_ACCESS_And_TRANSFER(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  LP__Is_Available();

	// ...
	int  FA_Seq__STATUS_CHANGE();

	int  FA_Seq__TRANSFER_BLOCKED();

	int  FA_Seq__LOAD_REQ();
	int  FA_Seq__UNLOAD_REQ();

	int  FA_Seq__CID_READ_START();
	int  FA_Seq__CID_READ_END();

	int  FA_Seq__MAP_START();
	int  FA_Seq__MAP_END();

	//
	int  FA_Seq__CAMCEL();
	int  FA_Seq__PAUSE();
	int  FA_Seq__RESUME();
	int  FA_Seq__ABORT();

	int  FA_Seq__COMPLETE();

	// ...
	int  Fnc__WAIT_SEC(CII_OBJECT__VARIABLE* p_variable,CII__VAR_ANALOG_CTRL* pch_analog_cfg);

	// ...
	int  Fnc__INIT(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__MAP(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  Fnc__PREPLOAD(CII_OBJECT__VARIABLE* p_variable);

	int  Fnc__CID_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const int seq_flag = -1);
	int  _Fnc__CID_READ(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm,const int seq_flag = -1);
	
	int  Fnc__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	int  _Fnc__LOAD(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);
	
	int  Check__CST_ERROR(CII_OBJECT__ALARM* p_alarm,const int load_seq_flag);

	int  _Fnc__DEVICE_MAP(CII_OBJECT__ALARM* p_alarm);

	int  Check__PORT_STATUS__JOB_READY();

	int  Fnc__RLSUNLOAD(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__UNLOAD(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm, const int complete_flag = -1);
	int  _Fnc__UNLOAD(CII_OBJECT__VARIABLE* p_variable, const int complete_flag = -1);
	
	int  Fnc__RELOAD(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm);
	int  Fnc__RELOAD(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM* p_alarm,const int seq_flag);

	int  Fnc__RF_CID_READ(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__RF_PAGE_READ(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__RF_CID_WRITE(CII_OBJECT__VARIABLE* p_variable);
	int  Fnc__RF_PAGE_WRITE(CII_OBJECT__VARIABLE* p_variable);

	// ...
	SCI__THREAD_SYNC_CTRL xI_Sync_Ctrl;

	int  iFLAG__MODULE_OBJ;

	int  Fnc__MODULE_OBJ(CII_OBJECT__VARIABLE* p_variable, const CString obj_mode);
	int  Sim__MODULE_OBJ(CII_OBJECT__VARIABLE* p_variable, const CString obj_mode);

	// ...
	int  Cancel__PORT();
	int  Pause__PORT(CII_OBJECT__ALARM* p_alarm);
	int  Resume__PORT(CII_OBJECT__ALARM* p_alarm);
	int  Abort__PORT(CII_OBJECT__ALARM* p_alarm);
	int  Return__PORT(CII_OBJECT__ALARM* p_alarm);
	int  Reload__PORT(CII_OBJECT__ALARM* p_alarm, const int call_flag = -1);

	// ...
	int  Verify__CID(CII_OBJECT__ALARM* p_alarm);
	int  Verify__MAP(CII_OBJECT__ALARM* p_alarm);

	int  Fnc__Verify_SlotMap(CII_OBJECT__ALARM* p_alarm,const int ptn);
	int  Fnc__Verify_CarrierID(CII_OBJECT__ALARM* p_alarm,const int ptn,const int carrier_reader_available);

	// ...
	int  Is__DUMMY_PORT();
	int  Set__DUMMY_PORT();

	int  Set__LOT_END();
	int  Clear__PORT_DATA();

	int  Is__MANUAL_MODE();

	// ...
	void Get__PORT_SLOT_STS(CUIntArray& l_slot_Sts);
	void Get__PORT_SLOT_STS(CStringArray& l_slot_Sts);
	void Set__PORT_SLOT_STS_TO_NEW_STS(const CString& new_sts);

	int  Check__PORT_STS__Standby_Or_CtcInUse();

	int  Popup__WIN_CSTID();
	//


public:
	CObj_Phy__LPx_STD();
	~CObj_Phy__LPx_STD();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj,l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);

	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);
	
	int __START__OBJECT();

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode,p_debug,p_variable,p_alarm);
	int __CALL__MONITORING(id,p_variable,p_alarm);
};
