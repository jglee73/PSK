#include "StdAfx.h"
#include "CObj__CHM_FNC.h"
#include "CObj__CHM_FNC__DEF.h"
#include "CObj__CHM_FNC__ALID.h"

#include "Macro_Function.h"


// ...
int CObj__CHM_FNC::VAT__CALL_OBJECT(const CString& obj_mode)
{
	if(bActive__VAT_OBJ)
	{
		if(pOBJ_CTRL__VAT->Is__OBJ_BUSY() > 0)
		{
			pOBJ_CTRL__VAT->Abort__OBJECT();
		}

		int r_flag = pOBJ_CTRL__VAT->Call__OBJECT(obj_mode);
		if(r_flag < 0)
		{
			// Log ...

			return -1;
		}
	}

	return 1;
}

int CObj__CHM_FNC::VAT__RUN_OBJECT(const CString& obj_mode)
{
	if(bActive__VAT_OBJ)
	{
		if(pOBJ_CTRL__VAT->Is__OBJ_BUSY() > 0)
		{
			pOBJ_CTRL__VAT->Abort__OBJECT();
		}

		return pOBJ_CTRL__VAT->Run__OBJECT(obj_mode);
	}

	return 1;
}
