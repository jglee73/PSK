// Phy_IO__BROOKS_ROBOT.h : main header file for the Phy_IO__BROOKS_ROBOT DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPhy_IO__BROOKS_ROBOTApp
// See Phy_IO__BROOKS_ROBOT.cpp for the implementation of this class
//

class CPhy_IO__BROOKS_ROBOTApp : public CWinApp
{
public:
	CPhy_IO__BROOKS_ROBOTApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
