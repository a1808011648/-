
// 字符转换编码工具Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "AutoChangeGui.h"

// C字符转换编码工具Dlg 对话框
class C字符转换编码工具Dlg : public CDialog
{
// 构造
public:
	C字符转换编码工具Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	int Unicode单选框;
//	int GBK单选框;
	CString 字符串编辑框;
	CString 编码编辑框;
	CString 编码编辑框1;
	CString 字符串编辑框1;
	CButton 增加空格选择框;
//	BOOL m_Unicode;
//	BOOL m_gbk;
	afx_msg void OnBnClickedButton1();
	
	void ChangeSize(CWnd* pWnd,int cx,int cy);
//	int m_unicode;
//	int m_gbk;
//	int m_unicode;
//	int m_gbk;
//	bool m_unicode;
//	bool m_gbk;
//	int m_unicode;
//	int m_gbk;
//	CButton m_unicode;
	CButton m_unicode;
	CButton m_gbk;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CButton 小端选择框;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedButton2();

	AutoChangeGui MyChangeGui;
	CRect m_rect; 
	POINT old; 


	CStatic 组合框;
	CStatic 组合框1;
	void ResizeGui(CWnd* pWndSon);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
