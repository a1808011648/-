
// �ַ�ת�����빤��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ַ�ת�����빤��.h"
#include "�ַ�ת�����빤��Dlg.h"
#include "afxdialogex.h"
#include<stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include"StrToHex_HexToStr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ַ�ת�����빤��Dlg �Ի���




C�ַ�ת�����빤��Dlg::C�ַ�ת�����빤��Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C�ַ�ת�����빤��Dlg::IDD, pParent)
	, �ַ����༭��(_T(""))
	, ����༭��(_T(""))
	, ����༭��1(_T(""))
	, �ַ����༭��1(_T(""))

{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ַ�ת�����빤��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, �ַ����༭��);
	DDX_Text(pDX, IDC_EDIT2, ����༭��);
	DDX_Text(pDX, IDC_EDIT4, ����༭��1);
	DDX_Text(pDX, IDC_EDIT3, �ַ����༭��1);
	DDX_Control(pDX, IDC_CHECK2, ���ӿո�ѡ���);
	//  DDX_Control(pDX, IDC_BUTTON1, m_unicode);
	DDX_Control(pDX, IDC_RADIO1, m_unicode);
	DDX_Control(pDX, IDC_RADIO2, m_gbk);
	DDX_Control(pDX, IDC_CHECK3, С��ѡ���);
	DDX_Control(pDX, IDC_STATIC0, ��Ͽ�);
	DDX_Control(pDX, IDC_STATIC1, ��Ͽ�1);
}

BEGIN_MESSAGE_MAP(C�ַ�ת�����빤��Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ַ�ת�����빤��Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &C�ַ�ת�����빤��Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C�ַ�ת�����빤��Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK3, &C�ַ�ת�����빤��Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON2, &C�ַ�ת�����빤��Dlg::OnBnClickedButton2)
	ON_WM_SIZE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// C�ַ�ת�����빤��Dlg ��Ϣ�������

BOOL C�ַ�ת�����빤��Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_unicode.SetCheck(TRUE);
	m_gbk.SetCheck(FALSE);
	���ӿո�ѡ���.SetCheck(TRUE);
	SetWindowText(_T("Unicode--GBK--����ת�����汾1.0.1��"));
	MyChangeGui.SetMainRect(this);
	// ��ȡ�Ի����ʼ��С    
	GetClientRect(&m_rect);  //��ȡ�Ի���Ĵ�С
	

	
	
	return TRUE;
}

void C�ַ�ת�����빤��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ַ�ת�����빤��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ַ�ת�����빤��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

using namespace std;






//�ַ���ת��Ϊ16����

//------�ַ�ת���밴ť������---------------//
void C�ַ�ת�����빤��Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	BOOL AddSpaces = FALSE;
	BOOL flags = FALSE;
	//�жϱ༭���Ƿ�Ϊ��
	if(�ַ����༭��.IsEmpty()){ 
		MessageBox(L"������Ҫת�������ݣ�");
		return;
	}
	//�ж��Ƿ���Ҫ���ӿո�
	if(���ӿո�ѡ���.GetCheck()){
		AddSpaces = TRUE;
	}
	if(С��ѡ���.GetCheck()){
		flags = TRUE;
	}

	//�жϵ�ǰѡ��״̬�Ƿ���Unicode
	if(m_unicode.GetCheck()){

		MessageBox(L"��ǰѡ��ΪUnicode");

		
		char *c= (char*)�ַ����༭��.GetBuffer();
		int length = �ַ����༭��.GetLength() * 2;
		char *buf = new char[length + 2];

		//��Unicode�ַ�����ʮ������ʽ�洢��buf��
		for(int i = 0;i<length;i++){
			buf[i] = *(c+i);

		}
	
		//��ʮ����ת��Ϊʮ������Unicode������ʽ���洢��string��
		string temp = StrToHex(buf,length,AddSpaces,flags);
		delete buf; //�ͷ�������ڴ�

		//���������
		����༭�� = temp.c_str();
		
	}

	//�жϵ�ǰѡ��״̬�Ƿ���GBK
	if(m_gbk.GetCheck()){
		MessageBox(L"��ǰѡ��ΪGbk");
		//��Unicode�ַ���ת��ΪGBK�ַ����������char*buf��
		char * buf = UnicodeToAsni(�ַ����༭��.GetBuffer());
		int lenth = strlen(buf);

		//���ַ���ת��Ϊ���룬��������༭����
		string temp = StrToHex(buf,lenth,AddSpaces,flags);
		����༭�� = temp.c_str();

		//�ͷ�UnicodeToAsni��������ڴ�;
		delete buf; //
	}

	UpdateData(FALSE);
	return;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ַ�ת�����빤��Dlg::OnBnClickedRadio1()
{
	m_gbk.SetCheck(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ַ�ת�����빤��Dlg::OnBnClickedRadio2()
{
	m_unicode.SetCheck(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//������С�˴洢
void C�ַ�ת�����빤��Dlg::OnBnClickedCheck3()
{
	GetDlgItem(IDC_EDIT1)->GetClientRect(&m_rect);
	TRACE("%d----%d---",m_rect.right,m_rect.bottom);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

//---------����ת�ַ�����ť����---------------//
void C�ַ�ת�����빤��Dlg::OnBnClickedButton2()
{
	UpdateData(TRUE); //�����ݸ��½�����
	BOOL flages = FALSE;
	if(����༭��1.IsEmpty()){ //�жϱ��������Ƿ�Ϊ��
		MessageBox(L"������Ҫת�������ݣ�");
		return;
	}
	//�ж��Ǵ�˻���С��
	if(С��ѡ���.GetCheck()){
		flages = TRUE;

	}
	//�ж��Ƿ�ΪGBK����
	if(m_gbk.GetCheck()){

		//��GBK����ת��Ϊ�ַ�����������༭����
		char*c=HexToStr(����༭��1.GetBuffer(),flages);
		�ַ����༭��1 = c;
		UpdateData(FALSE);
		delete c;
		return;
	}
	
	//��Unicode����ת��Ϊ�ַ�����������༭����
	wchar_t *wc = (wchar_t *)HexToStr(����༭��1.GetBuffer(),flages);
	�ַ����༭��1 = wc;
	UpdateData(FALSE);
	delete wc;
	
	
	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ַ�ת�����빤��Dlg::ChangeSize(CWnd* pWnd,int cx,int cy){
	if(pWnd) //�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����  
	{ 
		CRect rect;  //��ȡ�ؼ��仯ǰ�Ĵ�С  
		pWnd->GetWindowRect(&rect); 
		ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е��������� 

		//  cx/m_rect.Width()Ϊ�Ի����ں���ı仯���� 
		rect.left=rect.left*cx/m_rect.Width();//�����ؼ���С 
		rect.right=rect.right*cx/m_rect.Width(); 
		rect.top=rect.top*cy/m_rect.Height(); 
		rect.bottom=rect.bottom*cy/m_rect.Height(); 
		pWnd->MoveWindow(rect);//���ÿؼ���С 
	} 
}
void C�ַ�ת�����빤��Dlg::ResizeGui(CWnd* pWndSon){

	MyChangeGui.SetNewMainRect(this);
	MyChangeGui.SetSonRect(pWndSon);
	MyChangeGui.SetSonWide(pWndSon);
	MyChangeGui.SetSonHigh(pWndSon);
	MyChangeGui.ChangeGuiSize(0,0,MyChangeGui.GetSonWide(pWndSon),MyChangeGui.GetSonHigh(pWndSon),pWndSon);
	//��ǰ�ؼ����2--��--444--��--28
	//��ǰ�ؼ����3--��--425--��--124
}

void C�ַ�ת�����빤��Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if(nType == SIZE_RESTORED){

		
		CWnd* pWndSon = NULL;
		pWndSon = GetDlgItem(IDC_STATIC0);
		ResizeGui(pWndSon);
		
		pWndSon = GetDlgItem(IDC_STATIC1);
		ResizeGui(pWndSon);

		pWndSon = GetDlgItem(IDC_EDIT1);
		ResizeGui(pWndSon);

		pWndSon = GetDlgItem(IDC_EDIT2);
		ResizeGui(pWndSon);

		pWndSon = GetDlgItem(IDC_EDIT3);
		ResizeGui(pWndSon);

		pWndSon = GetDlgItem(IDC_EDIT4);
		ResizeGui(pWndSon);
		
	
		//��ǰ�ؼ����2--��--444--��--28
		//��ǰ�ؼ����3--��--425--��--124


		
	

		
	}
}
