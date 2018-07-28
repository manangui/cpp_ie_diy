
// cpp_ie_diyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "cpp_ie_diy.h"
#include "cpp_ie_diyDlg.h"
#include "afxdialogex.h"

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
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccpp_ie_diyDlg 对话框



Ccpp_ie_diyDlg::Ccpp_ie_diyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccpp_ie_diyDlg::IDD, pParent)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccpp_ie_diyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_MyIE);
	DDX_Control(pDX, IDC_BUTTON_BACK, m_Back);
	DDX_Control(pDX, IDC_BUTTON_FORWARD, m_Forward);
	DDX_Control(pDX, IDC_BUTTON_RELOAD, m_Reload);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_Stop);
	DDX_Control(pDX, IDC_EDIT_URL, m_Url);
}

BEGIN_MESSAGE_MAP(Ccpp_ie_diyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_COMMAND(ID_HELP_ABOUT, OnAbout)
	ON_COMMAND(ID_FILE_FIND, OnFind)
	ON_COMMAND(ID_FILE_EXIT, OnExit)
	ON_EN_CHANGE(IDC_EDIT_URL, &Ccpp_ie_diyDlg::OnChangeEditUrl)
	ON_BN_CLICKED(IDC_BUTTON_HCYY, &Ccpp_ie_diyDlg::OnClickedButtonHcyy)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &Ccpp_ie_diyDlg::OnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_FORWARD, &Ccpp_ie_diyDlg::OnClickedButtonForward)
	ON_BN_CLICKED(IDC_BUTTON_RELOAD, &Ccpp_ie_diyDlg::OnClickedButtonReload)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &Ccpp_ie_diyDlg::OnClickedButtonStop)
END_MESSAGE_MAP()


// Ccpp_ie_diyDlg 消息处理程序

BOOL Ccpp_ie_diyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO:  在此添加额外的初始化代码
	m_Menu.LoadMenu(IDR_MENU1);  //  IDR_MENU1
	SetMenu(&m_Menu);
	m_MyIE.Navigate(TEXT("www.baidu.com"), NULL, NULL, NULL, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ccpp_ie_diyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ccpp_ie_diyDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ccpp_ie_diyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccpp_ie_diyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	if (nType != 0)
	{
		CRect rect;
		GetWindowRect(rect);
		m_MyIE.put_Width(rect.Width());
		m_MyIE.put_Height(rect.Height());
		m_Url.SetWindowPos(NULL, 0, 0, rect.Width()-460, 25, SWP_NOMOVE);
	}	
}

void Ccpp_ie_diyDlg::OnAbout()
{
	MessageBox(TEXT("about..."));
	

}
void Ccpp_ie_diyDlg::OnFind()
{
	MessageBox(TEXT("find..."));


}
void Ccpp_ie_diyDlg::OnExit()
{
	//MessageBox(TEXT("exit"));
	exit(0);
}

void Ccpp_ie_diyDlg::OnChangeEditUrl()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	

	//MessageBox(TEXT("find..."));
}


BOOL Ccpp_ie_diyDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_EDIT_URL)//按下回车，如果当前焦点是在自己期望的控件上
		{
			// 你想做的事，如果按下回车时焦点在你想要的控件上
			CString str;
			m_Url.GetWindowTextW(str);
			m_MyIE.Navigate(str, NULL, NULL, NULL, NULL);
		}
		return TRUE;
	}
	//if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	//	return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}


void Ccpp_ie_diyDlg::OnClickedButtonHcyy()
{
	// TODO:  在此添加控件通知处理程序代码
	m_MyIE.Navigate(TEXT("http://www.hnhcyy.com/"), NULL, NULL, NULL, NULL);
}


void Ccpp_ie_diyDlg::OnClickedButtonBack()
{
	// TODO:  在此添加控件通知处理程序代码
	m_MyIE.GoBack();
}


void Ccpp_ie_diyDlg::OnClickedButtonForward()
{
	// TODO:  在此添加控件通知处理程序代码
	m_MyIE.GoForward();
}


void Ccpp_ie_diyDlg::OnClickedButtonReload()
{
	// TODO:  在此添加控件通知处理程序代码
	m_MyIE.Refresh();
}


void Ccpp_ie_diyDlg::OnClickedButtonStop()
{
	// TODO:  在此添加控件通知处理程序代码
	m_MyIE.Stop();
}
