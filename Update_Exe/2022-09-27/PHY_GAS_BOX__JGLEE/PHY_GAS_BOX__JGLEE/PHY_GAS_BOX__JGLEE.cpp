// PHY_GAS_BOX__JGLEE.cpp : �ش� DLL�� �ʱ�ȭ ��ƾ�� �����մϴ�.
//

#include "stdafx.h"
#include "PHY_GAS_BOX__JGLEE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: �� DLL�� MFC DLL�� ���� �������� ��ũ�Ǿ� �ִ� ���
//		MFC�� ȣ��Ǵ� �� DLL���� ���������� ��� �Լ���
//		���� �κп� AFX_MANAGE_STATE ��ũ�ΰ�
//		��� �־�� �մϴ�.
//
//		��:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �Ϲ����� �Լ� ������ ���⿡ �ɴϴ�.
//		}
//
//		�� ��ũ�δ� MFC�� ȣ���ϱ� ����
//		�� �Լ��� �ݵ�� ��� �־�� �մϴ�.
//		��, ��ũ�δ� �Լ��� ù ��° ���̾�� �ϸ� 
//		��ü ������ �����ڰ� MFC DLL��
//		ȣ���� �� �����Ƿ� ��ü ������ ����Ǳ� ����
//		���;� �մϴ�.
//
//		�ڼ��� ������
//		MFC Technical Note 33 �� 58�� �����Ͻʽÿ�.
//

// CPHY_GAS_BOX__JGLEEApp

BEGIN_MESSAGE_MAP(CPHY_GAS_BOX__JGLEEApp, CWinApp)
END_MESSAGE_MAP()


// CPHY_GAS_BOX__JGLEEApp ����

CPHY_GAS_BOX__JGLEEApp::CPHY_GAS_BOX__JGLEEApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CPHY_GAS_BOX__JGLEEApp ��ü�Դϴ�.

CPHY_GAS_BOX__JGLEEApp theApp;


// CPHY_GAS_BOX__JGLEEApp �ʱ�ȭ

BOOL CPHY_GAS_BOX__JGLEEApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
