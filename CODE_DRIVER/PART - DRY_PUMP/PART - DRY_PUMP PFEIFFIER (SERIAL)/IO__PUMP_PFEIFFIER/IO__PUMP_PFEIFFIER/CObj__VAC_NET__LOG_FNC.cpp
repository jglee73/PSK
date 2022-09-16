#include "StdAfx.h"
#include "CObj__VAC_NET.h"
#include "CObj__VAC_NET__DEF.h"


//------------------------------------------------------------------------------------
void CObj__VAC_NET::WRITE__APP_LOG_MSG(const CString& log_msg)
{	
	xAPP__LOG_CTRL->WRITE__LOG(log_msg);
}

void CObj__VAC_NET::WRITE__DRV_LOG_MSG(const CString& log_msg)
{	
	xDRV__LOG_CTRL->WRITE__LOG(log_msg);
}
