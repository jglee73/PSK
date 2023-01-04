#include "StdAfx.h"
#include "CObj__Driver_FUSION.h"
#include "CObj__Driver_FUSION__DEF.h"
#include "CObj__Driver_FUSION__ALID.h"

#include "Macro_Function.h"


// ...
int  CObj__Driver_FUSION
::Set_IO__ARM_TYPE(const CString& arm_type,
				   const CString& para__stn_name,
				   const CString& para__stn_slot)
{
	CString drv__stn_name 
		= Get__Fusion_Resource_Name_Of_Module_Name(para__stn_name);

	if(drv__stn_name.GetLength() < 1)
	{
		return -1;
	}

	soCH__STN_NAME->Set__DATA(drv__stn_name);
	doCH__SLOT->Set__DATA(para__stn_slot);
	doCH__ARM->Set__DATA(arm_type);
	return 1;
}

int  CObj__Driver_FUSION
::Set_IO__ARM_TYPE(const CString& para__stn_name)
{
	CString drv__stn_name
		= Get__Fusion_Resource_Name_Of_Module_Name(para__stn_name);

	if(drv__stn_name.GetLength() < 1)
	{
		return -1;
	}

	soCH__STN_NAME->Set__DATA(drv__stn_name);
	return 1;
}
