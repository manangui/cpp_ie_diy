
// cpp_ie_diy.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ccpp_ie_diyApp: 
// �йش����ʵ�֣������ cpp_ie_diy.cpp
//

class Ccpp_ie_diyApp : public CWinApp
{
public:
	Ccpp_ie_diyApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ccpp_ie_diyApp theApp;