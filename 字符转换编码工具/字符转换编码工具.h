
// 字符转换编码工具.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C字符转换编码工具App:
// 有关此类的实现，请参阅 字符转换编码工具.cpp
//

class C字符转换编码工具App : public CWinApp
{
public:
	C字符转换编码工具App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C字符转换编码工具App theApp;