#pragma once


#define  ALID__OBJECT_MODE_UNKNOWN							11
#define  ALID__SYSTEM_IN_PROCESS							12
#define  ALID__SYSTEM_IN_MAINT_MODE							13

#define  ALID__JOB_START__ROUTE_RCP_TYPE_OLD				14
#define  ALID__JOB_START__ROUTE_RCP_DIFFRENT				15
#define  ALID__JOB_START__ROUTE_RCP_NO_SLOT_LIST            16

#define  ALID__JOB_START__MATERIAL_ERROR					21
#define  ALID__JOB_START__PM_ERROR							22
#define  ALID__JOB_START__MODULE_ERROR						23
#define  ALID__JOB_START__NO_SLOT_ERROR						24
#define  ALID__JOB_START__LBx_MODE_ERROR					25
#define  ALID__JOB_START__NO_SLOT_MAP_ERROR					26

#define  ALID__JOB_START__NEW_JOB_ERROR_IN_SYS_END			31  // ~ 35

#define  ALID__JOB_START__CID_NULL_ERROR					41
#define  ALID__JOB_START__CID_DUPLICATE_ERROR				42

#define  ALID__JOB_START__JOB_FILE_ERROR					51
#define  ALID__JOB_START__ROUTE_RECIPE_ERROR				52
#define  ALID__JOB_START__PM_RECIPE_ERROR					53

#define  ALID__JOB_START__DUMMY_PORT__NOT_EXIST				61
#define  ALID__JOB_START__DUMMY_MATERIAL__NOT_EXIST			62

#define  ALID__JOB_START__ERROR_AT_DUMMY_PORT				63
#define  ALID__ALL_JOB__END_BY_USER							64
#define  ALID__JOB_START__BUFFER_NOT_USE					65

#define  ALID__MANUAL_JOB_START__ERROR						66
#define  ALID__CYCLE_JOB_START__ERROR						67

#define  ALID__JOB_START__PM_NORMAL_TYPE__NOT_EXIST			71
#define  ALID__JOB_START__PM_TEST_TYPE__NOT_EXIST			72

#define  ALID__SYSTEM_DEADLOCK_ERROR						73

#define	 ALID__DUMMY_PORT_COUNT_WARNING						81

#define  ALID__RESYNC_EDIT_ENABLE							82
#define  ALID__RESYNC_EDIT_DISABLE							83
#define  ALID__RESYNC_EDIT_WAFER_DUPLICATE					84
#define  ALID__RESYNC_EDIT_WAFER_UI_SCH_DB_ERROR			85


// ...
#define  ACT__CHECK											"CHECK"
#define  ACT__ABORT											"ABORT"
