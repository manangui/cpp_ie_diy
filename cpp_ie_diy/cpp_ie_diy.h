
// cpp_ie_diy.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Ccpp_ie_diyApp: 
// 有关此类的实现，请参阅 cpp_ie_diy.cpp
//

class Ccpp_ie_diyApp : public CWinApp
{
public:
	Ccpp_ie_diyApp();

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Ccpp_ie_diyApp theApp;