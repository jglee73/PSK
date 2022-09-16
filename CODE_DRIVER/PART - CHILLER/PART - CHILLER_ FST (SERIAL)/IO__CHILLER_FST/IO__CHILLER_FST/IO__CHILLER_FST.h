// IO__CHILLER_FST.h : main header file for the IO__CHILLER_FST DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CIO__CHILLER_FSTApp
// See IO__CHILLER_FST.cpp for the implementation of this class
//

class CIO__CHILLER_FSTApp : public CWinApp
{
public:
	CIO__CHILLER_FSTApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
