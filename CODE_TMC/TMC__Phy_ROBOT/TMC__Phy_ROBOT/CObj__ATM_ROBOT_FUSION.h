#pragma once

#include "Interface_Code.h"

#include "CCommon_Error.h"
#include "CCommon_System.h"


class CObj__ATM_ROBOT_FUSION : public __IOBJ__STD_TYPE
{
private:
	CCommon_Error__USER_FNC mERROR__USER_FNC;

	//-------------------------------------------------------------------------
	CString	sObject_Name;

	SCX__USER_LOG_CTRL xAPP_LOG_CTRL;
	int iFlag__APP_LOG;

	int iActive__SIM_MODE;


	//-------------------------------------------------------------------------
	//  INTERNAL PROPERTY

	// OBJ ...
	CX__VAR_STRING_CTRL  sCH__OBJ_STATUS;

	// MON.ACTIVE ...
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_BUSY;

	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_INTERLOCK_BY_LPx[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_IWAIT_BY_LPx[CFG_LPx__SIZE];

	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_TO_LPx[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_TO_LLx[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_TO_AL1;
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_TO_ST1;
	CX__VAR_DIGITAL_CTRL dCH__MON_ACTIVE_ROBOT_ACTION_TO_ST2;

	// SIM ...
	CX__VAR_DIGITAL_CTRL dCH__SIM_PAUSE_ACTIVE;

	// CFG ...
	CX__VAR_DIGITAL_CTRL dCH__CFG_ACTION_CHECK;

	CX__VAR_DIGITAL_CTRL dCH__CFG_ARM_A_USE;
	CX__VAR_DIGITAL_CTRL dCH__CFG_ARM_B_USE;

	CX__VAR_DIGITAL_CTRL dCH__CFG_DUAL_ARM_USE_LPx;
	CX__VAR_DIGITAL_CTRL dCH__CFG_DUAL_ARM_USE_STx;
	CX__VAR_DIGITAL_CTRL dCH__CFG_DUAL_ARM_USE_LLx;

	// PARA CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_NAME;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__STN_SLOT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_IN_PARA__ARM_TYPE;

	// MATERIAL CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_A_MATERIAL_STATUS;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_B_MATERIAL_STATUS;

	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_A_MATERIAL_TITLE;
	CX__VAR_STRING_CTRL  sCH__OTR_OUT_MON__ARM_B_MATERIAL_TITLE;

	// ANIMATION CHANNEL
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ACT_ARM;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_A_ACT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__ARM_B_ACT;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__TRG_MOVE;
	CX__VAR_DIGITAL_CTRL dCH__OTR_OUT_MON__TRG_ROTATE;

	CX__VAR_DIGITAL_CTRL dCH__CFG__WAFER_PRESENT_CHECK;
	CX__VAR_DIGITAL_CTRL dCH__CFG__WAFER_CROSSED_CHECK_AFTER_MAPPING;

	// TAS Channel ...
	CX__VAR_STRING_CTRL  sCH__TAS_RESET_REQ;

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__RB[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__RB[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__RB[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__RB[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__RB[CFG_ACT__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__RB[CFG_ACT__SIZE];

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__LPx[CFG_ACT__SIZE][CFG_LPx__SIZE];

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__AL1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__AL1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__AL1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__AL1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__AL1[CFG_ACT__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__AL1[CFG_ACT__SIZE];

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__LLx_X[CFG_ACT__SIZE][CFG_LLx__SIZE];

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__LLx_SLOT[CFG_ACT__SIZE][CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];

	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_NOW__ST1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MIN__ST1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_MAX__ST1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG__ST1[CFG_ACT__SIZE];
	CX__VAR_STRING_CTRL  sCH__TAS_ACTION_TIME_AVG_F__ST1[CFG_ACT__SIZE];
	CX__VAR_ANALOG_CTRL  aCH__TAS_ACTION_TIME_CNT__ST1[CFG_ACT__SIZE];
	//

	//-------------------------------------------------------------------------
	//  EXTERNAL PROPERTY

	// OBJ DB ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LPx_EXIST_FLAG[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LPx_CLOSE_MOVE_AFTER_MAPPING[CFG_LPx__SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_ALIGN_DEVICE;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_EXIST_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_AL1_SLOT_MAX;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_SLOT_MAX[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_EXIST_FLAG[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_1_EXIST_FLAG[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_2_EXIST_FLAG[CFG_LLx__SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_VIS1_EIXST_FLAG;

	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_BUFF1_EXIST_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_BUFF2_EXIST_FLAG;
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_FULL_BUFF_EXIST_FLAG;

	//
	CX__VAR_DIGITAL_CTRL dEXT_CH__MAINT_TARGT_LLx_NAME;
	CX__VAR_DIGITAL_CTRL dEXT_CH__MAINT_TARGT_LLx_SLOT;

	CX__VAR_STRING_CTRL  sEXT_CH__MODULE_LINK_TARGT_LLx_NAME;
	CX__VAR_STRING_CTRL  sEXT_CH__MODULE_LINK_TARGT_LLx_SLOT;

	CX__VAR_STRING_CTRL  sEXT_CH__CUR_AL1_TARGET_LLx_NAME;
	CX__VAR_STRING_CTRL  sEXT_CH__CUR_AL1_TARGET_LLx_SLOT;
	CX__VAR_STRING_CTRL  sEXT_CH__CUR_AL1_CCD_POS;

	// LLx ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_SLOT_USE_X[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_ALIGN_ANGLE[CFG_LLx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_POST_POSITION_INCREMENT[CFG_LLx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_POST_POSITION_INCREMENT_RANGE[CFG_LLx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_POST_POSITION_INCREMENT_START_ANGLE[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_POST_POSITION_INCREMENT_APPLY[CFG_LLx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CUR_LLx_POST_POSITION_INCREMENT_ANGLE[CFG_LLx__SIZE];

	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_X_ALIGN_ANGLE[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_X_POST_POSITION_INCREMENT[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_X_POST_POSITION_INCREMENT_RANGE[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_LLx_X_POST_POSITION_INCREMENT_START_ANGLE[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_LLx_X_POST_POSITION_INCREMENT_APPLY[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CUR_LLx_X_POST_POSITION_INCREMENT_ANGLE[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];

	// PMx ...
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_PMx_ALIGN_ANGLE[CFG_PMx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_PMx_POST_POSITION_INCREMENT[CFG_PMx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_PMx_POST_POSITION_INCREMENT_RANGE[CFG_PMx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CFG_PMx_POST_POSITION_INCREMENT_START_ANGLE[CFG_PMx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__CFG_PMx_POST_POSITION_INCREMENT_APPLY[CFG_PMx__SIZE];
	CX__VAR_ANALOG_CTRL  aEXT_CH__CUR_PMx_POST_POSITION_INCREMENT_ANGLE[CFG_PMx__SIZE];

	// IO ...
	CX__VAR_DIGITAL_CTRL dEXT_CH__IO_EFEM_DOOR_STS;

	// ROBOT ...
	CII_EXT_OBJECT__CTRL *pROBOT__OBJ_CTRL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_ARM_A_MATERIAL_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_ARM_B_MATERIAL_STATUS;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_AL_MATERIAL_STATUS;
	CX__VAR_ANALOG_CTRL  aEXT_CH__ALIGNER_ANGLE_PARA;

	// AL1 ...
	int iDATA__ALIGN_TYPE;

	CII_EXT_OBJECT__CTRL *pAL1__OBJ_CTRL;

	CX__VAR_DIGITAL_CTRL dEXT_CH__AL1_SLOT01_STATUS;
	CX__VAR_DIGITAL_CTRL dEXT_CH__AL1_SLOT02_STATUS;

	CX__VAR_STRING_CTRL  sEXT_CH__AL1_SLOT01_TITLE;
	CX__VAR_STRING_CTRL  sEXT_CH__AL1_SLOT02_TITLE;

	// LLx ...
	int iSIZE_LLx;
	int iLLx_SLOT_SIZE;
	bool bActive__LLx_MULTI_DOOR_VALVE;
	bool bActive__LLx_MULTI_SLOT_VALVE;

	CX__VAR_DIGITAL_CTRL dEXT_CH__LLx_SLOT_STATUS[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__LLx_SLOT_TITLE[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LLx_DOOR_STATUS_A[CFG_LLx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LLx_DOOR_STATUS_XX[CFG_LLx__SIZE][CFG_LLx__SLOT_SIZE];

	// LPx ...
	int iLPx_SIZE;

	CII_EXT_OBJECT__CTRL *pLPx__OBJ_CTRL[CFG_LPx__SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_CFG_MAX_SLOT_COUNT[CFG_LPx__SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_SLOT_STATUS[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__LPx_SLOT_TITLE[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];

	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_DOOR_STATUS[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_EXIST_FLAG[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_CLAMP_STATUS[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_FOUP_POS_STATUS[CFG_LPx__SIZE];
	CX__VAR_DIGITAL_CTRL dEXT_CH__LPx_SLOT_MAP_STATUS[CFG_LPx__SIZE][CFG_LPx__SLOT_SIZE];

	CX__VAR_STRING_CTRL  sEXT_CH__LPx_MAP_SEQ_LOCK[CFG_LPx__SIZE];

	// SIDE STORAGE1 ...
	CX__VAR_ANALOG_CTRL  aEXT_CH__SIDE_STORAGE1_CFG_SLOT_MAX;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SIDE_STORAGE1_SLOT_STATUS[CFG_LPx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__SIDE_STORAGE1_SLOT_TITLE[CFG_LPx__SLOT_SIZE];

	// SIDE STORAGE2 ...
	CX__VAR_ANALOG_CTRL  aEXT_CH__SIDE_STORAGE2_CFG_SLOT_MAX;

	CX__VAR_DIGITAL_CTRL dEXT_CH__SIDE_STORAGE2_SLOT_STATUS[CFG_LPx__SLOT_SIZE];
	CX__VAR_STRING_CTRL  sEXT_CH__SIDE_STORAGE2_SLOT_TITLE[CFG_LPx__SLOT_SIZE];

	// ARM_RNE.SENSOR ...
	bool bActive__ROBOT_RNE_SNS__ARM_A;
	bool bActive__ROBOT_RNE_SNS__ARM_B;

	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_RNE_SNS__ARM_A;
	CX__VAR_DIGITAL_CTRL dEXT_CH__ROBOT_RNE_SNS__ARM_B;

	// ARM_RNE.STATE ...
	CString sDATA__RNE_ON;
	CString sDATA__RNE_OFF;
	//


	//-------------------------------------------------------------------------
	CString sMODE__INIT;
	int  Call__INIT(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm);

	CString sMODE__HOME;
	CString sMODE__VACOFF_HOME;
	int  Call__HOME(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const int req__vac_off);

	CString sMODE__ROTATE;
	int  Call__ROTATE(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__PICK;
	int  Call__PICK(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot,
					const bool active__align_pick);

	int  Fnc__ACTION(const CString& arm_type,
					 const CString& stn_name,
					 const CString& stn_slot,
					 const CString& cmmd_act);

	int  _Update__ACTION_MIN_MAX(CII__VAR_STRING_CTRL* p_ch_min,
								 CII__VAR_STRING_CTRL* p_ch_max,
								 CII__VAR_STRING_CTRL* p_ch_avg,
								 CII__VAR_STRING_CTRL* p_ch_avg_f,
								 CII__VAR_ANALOG_CTRL* p_ch_cnt,
								 const double cur_sec);

	CString sMODE__PLACE;
	int  Call__PLACE(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__MAP;
	int  Call__MAP(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm);

	CString sMODE__VACON;
	int  Call__VACON(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type);

	CString sMODE__VACOFF;
	int  Call__VACOFF(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type);

	CString sMODE__RETRACT;
	int  Call__RETRACT(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__EXTEND;
	int  Call__EXTEND(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__GOUP;
	int  Call__GOUP(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__GODOWN;
	int  Call__GODOWN(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm,
					const CString& arm_type,
					const CString& stn_name,
					const CString& stn_slot);

	CString sMODE__ALGN;
	int  Call__ALGN(CII_OBJECT__VARIABLE* p_variable,
					CII_OBJECT__ALARM* p_alarm);

	CString sMODE__LP_MAP;
	int  Call__LP_MAP(CII_OBJECT__VARIABLE* p_variable,
		              CII_OBJECT__ALARM* p_alarm);

	// TIME TEST ...
	CString sMODE__TIME_TEST;
	int  Call__TIME_TEST(CII_OBJECT__VARIABLE* p_variable,CII_OBJECT__ALARM* p_alarm);

	// ...
	int  Check__STN_EXIST(CII_OBJECT__ALARM* p_alarm, const CString& stn_name,const CString& stn_slot);
	//

	//-------------------------------------------------------------------------
	// ...
	int  Interlock__CHECK_MATERIAL(CII_OBJECT__ALARM* p_alarm,
								    const int place_flag,
								    const CString& arm_type,
								    const CString& stn_name,
								    const CString& stn_slot,
								    const CString& act_name);

	int  Interlock__CHECK_DOOR_OPEN(CII_OBJECT__ALARM* p_alarm,
									const CString& arm_type,
									const CString& stn_name,
									const CString& stn_slot,
									const CString& act_name);

	int  Fnc__CHANGE_MATERIAL_INFO(const int place_flag,
									const CString& arm_type,
									const CString& stn_name,
									const CString& stn_slot);

	// ...
	int  Interlock__AL1_SLOT_CHECK(CII_OBJECT__ALARM* p_alarm,
									const CString& arm_type,
									const CString& stn_name,
									const CString& para_slot,
									CString& trg_slot);

	int  Interlock__LLx_SLOT_CHECK(CII_OBJECT__ALARM* p_alarm,
									const CString& arm_type,
								    const CString& stn_name,
								    const CString& para_slot,
								    CString& trg_slot);

	// ...
	void Set_ANI__ROBOT_EXTEND(const CString& arm_type,const CString& stn_name,const CString& stn_slot);

	void Set_ANI__ROBOT_ALL_RETRACT();
	void Set_ANI__ROBOT_RETRACT(const CString& arm_type,const CString& stn_name,const CString& stn_slot);

	void Set_ANI__ROBOT_ROTATE(const CString& arm_type,	const CString& stn_name,const CString& stn_slot);
	void _Set_ANI__ROBOT_ROTATE(const CString& arm_type, const CString& stn_name,const CString& stn_slot);

	// ...
	void Fnc__APP_LOG(const CString& log_msg);

	int  Check__EFEM_DOORS(CII_OBJECT__ALARM* p_alarm,CII_OBJECT__VARIABLE* p_variable);

	// ...
	void Mon__STATE_MONITOR(CII_OBJECT__VARIABLE* p_variable, CII_OBJECT__ALARM *p_alarm);
	//


public:
	CObj__ATM_ROBOT_FUSION();
	~CObj__ATM_ROBOT_FUSION();

	//-------------------------------------------------------------------------
	int __DEFINE__CONTROL_MODE(obj, l_mode);
	int __DEFINE__VERSION_HISTORY(version);

	int __DEFINE__VARIABLE_STD(p_variable);
	int __DEFINE__ALARM(p_alarm);

	//-------------------------------------------------------------------------
	int __INITIALIZE__OBJECT(p_variable,p_ext_obj_create);	

	//-------------------------------------------------------------------------
	int __CALL__CONTROL_MODE(mode, p_debug, p_variable, p_alarm);
	int __CALL__MONITORING(id, p_variable, p_alarm);
};
