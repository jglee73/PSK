// PHY_RF_SYS__JGLEE.h : main header file for the PHY_RF_SYS__JGLEE DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPHY_RF_SYS__JGLEEApp
// See PHY_RF_SYS__JGLEE.cpp for the implementation of this class
//

class CPHY_RF_SYS__JGLEEApp : public CWinApp
{
public:
	CPHY_RF_SYS__JGLEEApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
