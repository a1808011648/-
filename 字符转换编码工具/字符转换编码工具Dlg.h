
// �ַ�ת�����빤��Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "AutoChangeGui.h"

// C�ַ�ת�����빤��Dlg �Ի���
class C�ַ�ת�����빤��Dlg : public CDialog
{
// ����
public:
	C�ַ�ת�����빤��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	int Unicode��ѡ��;
//	int GBK��ѡ��;
	CString �ַ����༭��;
	CString ����༭��;
	CString ����༭��1;
	CString �ַ����༭��1;
	CButton ���ӿո�ѡ���;
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
	CButton С��ѡ���;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedButton2();

	AutoChangeGui MyChangeGui;
	CRect m_rect; 
	POINT old; 


	CStatic ��Ͽ�;
	CStatic ��Ͽ�1;
	void ResizeGui(CWnd* pWndSon);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
