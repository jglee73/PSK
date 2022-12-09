// IO__GAS_CABINET_PSK.h : main header file for the IO__GAS_CABINET_PSK DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIO__GAS_CABINET_PSKApp
// See IO__GAS_CABINET_PSK.cpp for the implementation of this class
//

class CIO__GAS_CABINET_PSKApp : public CWinApp
{
public:
	CIO__GAS_CABINET_PSKApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
