
// 字符转换编码工具Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "字符转换编码工具.h"
#include "字符转换编码工具Dlg.h"
#include "afxdialogex.h"
#include<stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include"StrToHex_HexToStr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C字符转换编码工具Dlg 对话框




C字符转换编码工具Dlg::C字符转换编码工具Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C字符转换编码工具Dlg::IDD, pParent)
	, 字符串编辑框(_T(""))
	, 编码编辑框(_T(""))
	, 编码编辑框1(_T(""))
	, 字符串编辑框1(_T(""))

{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C字符转换编码工具Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, 字符串编辑框);
	DDX_Text(pDX, IDC_EDIT2, 编码编辑框);
	DDX_Text(pDX, IDC_EDIT4, 编码编辑框1);
	DDX_Text(pDX, IDC_EDIT3, 字符串编辑框1);
	DDX_Control(pDX, IDC_CHECK2, 增加空格选择框);
	//  DDX_Control(pDX, IDC_BUTTON1, m_unicode);
	DDX_Control(pDX, IDC_RADIO1, m_unicode);
	DDX_Control(pDX, IDC_RADIO2, m_gbk);
	DDX_Control(pDX, IDC_CHECK3, 小端选择框);
	DDX_Control(pDX, IDC_STATIC0, 组合框);
	DDX_Control(pDX, IDC_STATIC1, 组合框1);
}

BEGIN_MESSAGE_MAP(C字符转换编码工具Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C字符转换编码工具Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &C字符转换编码工具Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &C字符转换编码工具Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK3, &C字符转换编码工具Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON2, &C字符转换编码工具Dlg::OnBnClickedButton2)
	ON_WM_SIZE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// C字符转换编码工具Dlg 消息处理程序

BOOL C字符转换编码工具Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码
	m_unicode.SetCheck(TRUE);
	m_gbk.SetCheck(FALSE);
	增加空格选择框.SetCheck(TRUE);
	SetWindowText(_T("Unicode--GBK--编码转换（版本1.0.1）"));
	MyChangeGui.SetMainRect(this);
	// 获取对话框初始大小    
	GetClientRect(&m_rect);  //获取对话框的大小
	

	
	
	return TRUE;
}

void C字符转换编码工具Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C字符转换编码工具Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C字符转换编码工具Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

using namespace std;






//字符串转换为16进制

//------字符转编码按钮被单机---------------//
void C字符转换编码工具Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	BOOL AddSpaces = FALSE;
	BOOL flags = FALSE;
	//判断编辑框是否为空
	if(字符串编辑框.IsEmpty()){ 
		MessageBox(L"请输入要转换的内容！");
		return;
	}
	//判断是否需要增加空格
	if(增加空格选择框.GetCheck()){
		AddSpaces = TRUE;
	}
	if(小端选择框.GetCheck()){
		flags = TRUE;
	}

	//判断当前选中状态是否是Unicode
	if(m_unicode.GetCheck()){

		MessageBox(L"当前选中为Unicode");

		
		char *c= (char*)字符串编辑框.GetBuffer();
		int length = 字符串编辑框.GetLength() * 2;
		char *buf = new char[length + 2];

		//将Unicode字符串以十进制形式存储到buf中
		for(int i = 0;i<length;i++){
			buf[i] = *(c+i);

		}
	
		//将十进制转变为十六进制Unicode编码形式，存储到string中
		string temp = StrToHex(buf,length,AddSpaces,flags);
		delete buf; //释放申请的内存

		//将编码输出
		编码编辑框 = temp.c_str();
		
	}

	//判断当前选中状态是否是GBK
	if(m_gbk.GetCheck()){
		MessageBox(L"当前选中为Gbk");
		//将Unicode字符串转换为GBK字符串，输出到char*buf中
		char * buf = UnicodeToAsni(字符串编辑框.GetBuffer());
		int lenth = strlen(buf);

		//将字符串转变为编码，并输出到编辑框内
		string temp = StrToHex(buf,lenth,AddSpaces,flags);
		编码编辑框 = temp.c_str();

		//释放UnicodeToAsni中申请的内存;
		delete buf; //
	}

	UpdateData(FALSE);
	return;
	// TODO: 在此添加控件通知处理程序代码
}


void C字符转换编码工具Dlg::OnBnClickedRadio1()
{
	m_gbk.SetCheck(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void C字符转换编码工具Dlg::OnBnClickedRadio2()
{
	m_unicode.SetCheck(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


//单机了小端存储
void C字符转换编码工具Dlg::OnBnClickedCheck3()
{
	GetDlgItem(IDC_EDIT1)->GetClientRect(&m_rect);
	TRACE("%d----%d---",m_rect.right,m_rect.bottom);

	// TODO: 在此添加控件通知处理程序代码
}

//---------编码转字符串按钮单机---------------//
void C字符转换编码工具Dlg::OnBnClickedButton2()
{
	UpdateData(TRUE); //将数据更新进变量
	BOOL flages = FALSE;
	if(编码编辑框1.IsEmpty()){ //判断编码内容是否为空
		MessageBox(L"请输入要转换的内容！");
		return;
	}
	//判断是大端还是小端
	if(小端选择框.GetCheck()){
		flages = TRUE;

	}
	//判断是否为GBK编码
	if(m_gbk.GetCheck()){

		//将GBK编码转换为字符串并输出到编辑框内
		char*c=HexToStr(编码编辑框1.GetBuffer(),flages);
		字符串编辑框1 = c;
		UpdateData(FALSE);
		delete c;
		return;
	}
	
	//将Unicode编码转换为字符串并输出到编辑框内
	wchar_t *wc = (wchar_t *)HexToStr(编码编辑框1.GetBuffer(),flages);
	字符串编辑框1 = wc;
	UpdateData(FALSE);
	delete wc;
	
	
	
	
	// TODO: 在此添加控件通知处理程序代码
}


void C字符转换编码工具Dlg::ChangeSize(CWnd* pWnd,int cx,int cy){
	if(pWnd) //判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建  
	{ 
		CRect rect;  //获取控件变化前的大小  
		pWnd->GetWindowRect(&rect); 
		ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标 

		//  cx/m_rect.Width()为对话框在横向的变化比例 
		rect.left=rect.left*cx/m_rect.Width();//调整控件大小 
		rect.right=rect.right*cx/m_rect.Width(); 
		rect.top=rect.top*cy/m_rect.Height(); 
		rect.bottom=rect.bottom*cy/m_rect.Height(); 
		pWnd->MoveWindow(rect);//设置控件大小 
	} 
}
void C字符转换编码工具Dlg::ResizeGui(CWnd* pWndSon){

	MyChangeGui.SetNewMainRect(this);
	MyChangeGui.SetSonRect(pWndSon);
	MyChangeGui.SetSonWide(pWndSon);
	MyChangeGui.SetSonHigh(pWndSon);
	MyChangeGui.ChangeGuiSize(0,0,MyChangeGui.GetSonWide(pWndSon),MyChangeGui.GetSonHigh(pWndSon),pWndSon);
	//当前控件编号2--宽--444--长--28
	//当前控件编号3--宽--425--长--124
}

void C字符转换编码工具Dlg::OnSize(UINT nType, int cx, int cy)
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
		
	
		//当前控件编号2--宽--444--长--28
		//当前控件编号3--宽--425--长--124


		
	

		
	}
}
