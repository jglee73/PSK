// PHY_GAS_BOX__JGLEE.h : PHY_GAS_BOX__JGLEE DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPHY_GAS_BOX__JGLEEApp
// �� Ŭ������ ������ ������ PHY_GAS_BOX__JGLEE.cpp�� �����Ͻʽÿ�.
//

class CPHY_GAS_BOX__JGLEEApp : public CWinApp
{
public:
	CPHY_GAS_BOX__JGLEEApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
