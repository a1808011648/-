
// �ַ�ת�����빤��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ַ�ת�����빤��App:
// �йش����ʵ�֣������ �ַ�ת�����빤��.cpp
//

class C�ַ�ת�����빤��App : public CWinApp
{
public:
	C�ַ�ת�����빤��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ַ�ת�����빤��App theApp;