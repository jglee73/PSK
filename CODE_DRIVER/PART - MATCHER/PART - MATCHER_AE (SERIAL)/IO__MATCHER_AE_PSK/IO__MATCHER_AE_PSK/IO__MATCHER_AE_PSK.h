// IO__MATCHER_AE_PSK.h : main header file for the IO__MATCHER_AE_PSK DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIO__MATCHER_AE_PSKApp
// See IO__MATCHER_AE_PSK.cpp for the implementation of this class
//

class CIO__MATCHER_AE_PSKApp : public CWinApp
{
public:
	CIO__MATCHER_AE_PSKApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
