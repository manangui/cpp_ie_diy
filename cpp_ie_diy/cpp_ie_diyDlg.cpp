
// cpp_ie_diyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "cpp_ie_diy.h"
#include "cpp_ie_diyDlg.h"
#include "afxdialogex.h"

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
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccpp_ie_diyDlg �Ի���



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


// Ccpp_ie_diyDlg ��Ϣ�������

BOOL Ccpp_ie_diyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_Menu.LoadMenu(IDR_MENU1);  //  IDR_MENU1
	SetMenu(&m_Menu);
	m_MyIE.Navigate(TEXT("www.baidu.com"), NULL, NULL, NULL, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Ccpp_ie_diyDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Ccpp_ie_diyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ccpp_ie_diyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	

	//MessageBox(TEXT("find..."));
}


BOOL Ccpp_ie_diyDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_EDIT_URL)//���»س��������ǰ���������Լ������Ŀؼ���
		{
			// ���������£�������»س�ʱ����������Ҫ�Ŀؼ���
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_MyIE.Navigate(TEXT("http://www.hnhcyy.com/"), NULL, NULL, NULL, NULL);
}


void Ccpp_ie_diyDlg::OnClickedButtonBack()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_MyIE.GoBack();
}


void Ccpp_ie_diyDlg::OnClickedButtonForward()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_MyIE.GoForward();
}


void Ccpp_ie_diyDlg::OnClickedButtonReload()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_MyIE.Refresh();
}


void Ccpp_ie_diyDlg::OnClickedButtonStop()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_MyIE.Stop();
}
