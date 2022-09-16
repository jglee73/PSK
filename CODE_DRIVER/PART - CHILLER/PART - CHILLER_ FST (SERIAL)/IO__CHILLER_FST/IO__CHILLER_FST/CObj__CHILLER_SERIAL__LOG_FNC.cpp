#include "StdAfx.h"
#include "CObj__CHILLER_SERIAL.h"
#include "CObj__CHILLER_SERIAL__DEF.h"


//------------------------------------------------------------------------------------
void CObj__CHILLER_SERIAL::WRITE__APP_LOG_MSG(const CString& log_msg)
{	
	xAPP__LOG_CTRL->WRITE__LOG(log_msg);
}

void CObj__CHILLER_SERIAL::WRITE__DRV_LOG_MSG(const CString& log_msg)
{	
	xDRV__LOG_CTRL->WRITE__LOG(log_msg);
}
